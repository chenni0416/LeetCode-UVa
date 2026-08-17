#include <bits/stdc++.h>
using namespace std;
/*
1. l < 0 or l > M: not use
2. 0 0 stop
3. final ouput cannot print /n

*/

struct seg {
    int l;
    int r;
    bool operator<(const seg& other) const {
        // return (l < other.l) ? (l < other.l) : (r > other.r);
        if (l != other.l) return l < other.l;
        return (r > other.r);
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        int l, r;
        vector<seg> segs;
        // guarantee r >= l
        while (cin >> l >> r && (l || r)) {
            seg s{l, r};
            if (l > m || r <= 0) continue;
            segs.push_back(s);
        }
        sort(segs.begin(), segs.end());
        
        int idx = 0;
        // int best_idx = 0
        int curR = 0;
        // int maxR
        // int curL = 0;
        // int ans = 0;
        // bool possible = false;
        vector<seg> ans_segs;
        int n = segs.size();

        while (curR < m) {
            int maxR = curR;
            int best_idx = -1;
            while (idx < n && segs[idx].l <= maxR) {
                if (segs[idx].r > curR) {
                    curR = segs[idx].r;
                    best_idx = idx;
                }
                idx++;
            }
            if (best_idx == -1) break;
            ans_segs.push_back(segs[best_idx]);
        }

        //print ans
        if (curR < m) {
            cout << 0 << "\n";
        }
        else {
            cout << ans_segs.size() << "\n";
            for (auto& s : ans_segs) cout << s.l << " " << s.r << "\n";
            // for (int i = 0; i <= idx; i++) {
            //     cout << segs[i].l << " " << segs[i].r << "\n";
            // }
        }
        if (t != 0) cout << "\n";


        // while (idx < n && maxR < m) {
        //     while (idx < n && segs[idx].l <= curL) {
        //         if (segs[idx].r > maxR) {
        //             best_idx = idx;
        //             maxR = segs[idx].r;
        //         }
        //         idx++;
        //     }
        //     ans_segs.push_back(segs[best_idx]);
        //     curL = maxR;
        // }


        // for (auto s : segs) {
        //     cout << "check after sort"<< s.l << " "<< s.r << "\n";
        // }
        // if ()
        // testcase: if r < l or 
        // 0 1 1 2, 0 2 1 3, 
        // sep: 0 1 2 3
        // 0 
        // int idx = -1;
        // for (int i = 0; i < segs.size(); i++) {
        //     if (segs[i].l >= 0) break;
        //     if (segs[i].r > maxR) {
        //         maxR = segs[i].r;
        //         idx = i;
        //     }
        // }
        // if (idx != -1) ans_segs.push_back(segs[idx]);
        
        // for (int i = 0; i < segs.size(); i++) {
        //     if (segs[i].l > maxR) {
        //         // line break
        //         // possible = false;
        //         break;
        //     }
        //     // 
        //     if (segs[i].r > maxR) {
        //         idx = i;
        //         maxR = segs[i].r;
        //         ans_segs.push_back(segs[i]);
        //     }

        //     // maxR = segs[i].r;
        //     // if (segs[i].r > maxR && ) {
        //     //     maxR = segs[i].r;
        //     //     ans_segs.push_back(segs[i]);
        //     //     // ans ++;
        //     // }
        //     // has ans;
        //     if (maxR >= m) {
        //         // idx = i;
        //         possible = true;
        //         break;
        //     }
            
        // }

        // //print ans
        // if (!possible) {
        //     cout << 0 << "\n";
        // }
        // else {
        //     cout << ans_segs.size() << "\n";
        //     for (auto& s : ans_segs) cout << s.l << " " << s.r << "\n";
        //     // for (int i = 0; i <= idx; i++) {
        //     //     cout << segs[i].l << " " << segs[i].r << "\n";
        //     // }
        // }
        // if (t != 0) cout << "\n";
        // cout << "\n";



    }


}