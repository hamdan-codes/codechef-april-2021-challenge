/*
 * Author Chaudhary Hamdan
 * C++ Template for Competitive Programming
 * Github link : https://github.com/hamdan-codes
 */

/*
 * Template available at my Github
 * Repository Link :-
 * https://github.com/hamdan-codes/templates-for-CP/
 */




#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define si              set<int>
#define gi              greater<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define all(x)          x.begin(),x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define pi              3.14159265358979323846264338327950288419716939937510
#define inf             LONG_LONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define endl            '\n'
#define mk(arr,n,type)  type *arr=new type[n]
#define w(x)            int x; cin >> x; while(x--)
#define f(i,x,y)        for(int i = x; i < y; i++)
#define rf(i,x,y)       for(int i = x; i >= y; i--)



using namespace std;

using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_p()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\KIIT\\input", "r", stdin);
    freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif
}
/* ********************* Your Functions Below ********************** */
















/* ********************* Your Functions Above ********************** */

main()
{
    c_p_p();

    /* *************** Your main function Code Below ****************** */





    w(t)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vi g(n + 1);

        f(i, 1, n + 1)
        {
            cin >> g[i];
        }


        vector<vector<pii>> arr(n + 1);
        f(i, 0, m)
        {
            int u, v, d;
            cin >> u >> v >> d;
            arr[u].pb(mp(i, d));
            arr[v].pb(mp(i, d));
        }

        vector<vector<pii>> dp(n + 1);
        dp[0].pb(mp(0, 0));

        f(i, 1, n + 1)
        {
            vector<pii> vec_data;
            vec_data.insert(vec_data.end(), all(dp[i - 1]));

            int current = 0, current_mask = 0;
            si dist;
            rf(j, i, 1)
            {
                current += g[j];
                current_mask ^= (1LL << j);

                for (auto & [idx, w] : arr[j]) {
                    if (dist.count(idx)) {
                        current += w;
                    }
                    else {
                        dist.insert(idx);
                    }
                }

                if (j > 1)
                {
                    for (auto & [val, old_mask] : dp[j - 2])
                    {
                        vec_data.pb(mp(val + current, current_mask ^ old_mask));
                    }
                }
                else
                {
                    vec_data.pb(mp(current, current_mask));
                }
            }

            sort(all(vec_data));
            reverse(all(vec_data));
            si sel;
            int filled = 0;

            f(j, 0, vec_data.size() && filled < k)
            {
                if (sel.count(vec_data[j].ss))
                    continue;

                dp[i].pb(vec_data[j]);
                filled++;
                sel.insert(vec_data[j].ss);
            }
        }

        f(i, 0, k)
        {
            cout << dp[n][i].ff << " ";
        }
        cout << endl;
    }




    /* **************** Your main function Code Above ****************** */

    return 0;
}
