class Solution {
public:
    void applyMessageEvent(vector<string> event , vector<int>& MentionCount , vector<int>& OfflineTime) {
        int timestamp = stoi(event[1]);

        vector<string> ids;
        stringstream ss(event[2]);

        string token;
        while (ss >> token) {
            ids.push_back(token);
        }

        for (string id : ids) {
            if (id == "ALL") {
                for (int i=0 ; i<MentionCount.size() ; i++) 
                    MentionCount[i]++;
            }
            else if (id == "HERE") {
                for (int i=0 ; i<MentionCount.size() ; i++) {
                    if (OfflineTime[i] == 0 || OfflineTime[i] + 60 <= timestamp)
                        MentionCount[i]++;
                }
            }
            else 
                MentionCount[stoi(id.substr(2))]++;
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> MentionCount(numberOfUsers);
        vector<int> OfflineTime(numberOfUsers);

        auto lambda = [](vector<string>& v1 , vector<string>& v2) {
            int t1 = stoi(v1[1]);
            int t2 = stoi(v2[1]);

            if (t1 == t2)
                return v1[0][1] > v2[0][1];
            
            return t1 < t2;
        };

        sort(events.begin() , events.end() , lambda);

        for (vector<string>event : events) {
            if (event[0] == "MESSAGE") {
                applyMessageEvent(event , MentionCount , OfflineTime);
            }
            else if (event[0] == "OFFLINE") {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);

                OfflineTime[id] = timestamp;
            }
        }

        return MentionCount;
    }
};