class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meeting) {

        // endTime , {meetingCount , roomIndex}
        vector<pair<long long, pair<int,int>>> hardik;
        for (int i = 0; i < n; i++) {
            hardik.push_back({0, {0, i}});
        }

        sort(meeting.begin(), meeting.end());

        for (int i = 0; i < meeting.size(); i++) {
            long long start = meeting[i][0];
            long long duration = meeting[i][1] - meeting[i][0];

            bool flag = false;
            sort(hardik.begin(),hardik.end(),[](auto a , auto b){
                    return a.second.second < b.second.second;
                }
                );

            // try to find a free room
            for (auto &h : hardik) {
                
                if (h.first <= start) {
                    h.first = start + duration;
                    h.second.first++;
                    flag = true;
                    break;
                }
            }

            // delay case
            if (!flag) {
                sort(hardik.begin(), hardik.end(),
                     [](auto &a, auto &b) {
                         if (a.first == b.first)
                             return a.second.second < b.second.second;
                         return a.first < b.first;
                     });

                hardik[0].first += duration;
                hardik[0].second.first++;
            }
        }

        int ans = 0;
        int mx = 0;

        for (auto &h : hardik) {
            if (h.second.first > mx) {
                mx = h.second.first;
                ans = h.second.second;
            }
            else if (h.second.first == mx) {
                ans = min(ans, h.second.second);
            }
        }

        return ans;
    }
};
