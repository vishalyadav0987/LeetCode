class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {

        // Actual ON bulbs
        unordered_set<long long> bulbs;

        // count the number illumation happens with bulb

        // horizontal
        unordered_map<int, int> rowCnt;

        // vertically
        unordered_map<int, int> colCnt;

        // left diagnal
        unordered_map<int, int> leftDiaCnt; // r-c

        // right diagonal
        unordered_map<int, int> rightDiaCnt; // r+c

        // Convert (r,c) into one unique number
        auto key = [&](int r, int c) { return 1LL * r * n + c; };

        // Add all bulbs in set
        for (auto lamp : lamps) {
            int r = lamp[0];
            int c = lamp[1];

            long long check = key(r, c);

            // Duplicate bulb
            if (bulbs.count(check)) {
                continue;
            }

            // new bulb
            bulbs.insert(check);
            rowCnt[r]++;
            colCnt[c]++;
            leftDiaCnt[r - c]++;
            rightDiaCnt[r + c]++;
        }

        vector<int> answer;

        // -----------------------------
        // 2. Process every query
        // -----------------------------
        for (auto query : queries) {
            int r = query[0];
            int c = query[1];

            // Check whether query cell is illuminated
            if (rowCnt[r] > 0 || colCnt[c] > 0 || leftDiaCnt[r - c] > 0 ||
                rightDiaCnt[r + c] > 0) {
                answer.push_back(1);
            } else {
                answer.push_back(0);
            }

            // we know the blubs position, ersae bulbs from bulbs and decrese
            // the count where it illuminates
            //     0.  1.  2
            // 0.  x.  x.  x
            // 1.  x.  B.  x
            // 2.  x.  x.  x

            // we run loop from
            // r-1 to r+1

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    // move row and col
                    int mr = r + dr;
                    int mc = c + dc;

                    // Outside grid
                    if (mr < 0 || mr >= n || mc < 0 || mc >= n) {
                        continue;
                    }

                    // here check in these 9 cell bulb exist or not
                    long long check = key(mr, mc);


                    // No ON bulb at this cell
                    if (!bulbs.count(check)) {
                        continue;
                    }

                    // Turn OFF this bulb
                    bulbs.erase(check);

                    rowCnt[mr]--;
                    colCnt[mc]--;
                    leftDiaCnt[mr - mc]--;
                    rightDiaCnt[mr + mc]--;
                }
            }
        }

        return answer;
    }
};