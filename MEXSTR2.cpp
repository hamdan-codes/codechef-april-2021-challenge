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
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
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

constexpr int MAXN = (int)1e6;
int dp[MAXN + 2], dp1[MAXN + 2];
int other1[MAXN], other2[MAXN];


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif
}
/* ********************* Your Functions Below ********************** */



main()
{
	c_p_p();

	/* *************** Your main function Code Below ****************** */


	w(t)
	{
		string arr;
		cin >> arr;
		int n = arr.length();

		int top = -1;
		f(i, 0, n)
		{
			if (arr[i] == '0')
			{
				f(j, top + 1, i + 1)
				{
					other1[j] = i;
				}
				top = i;
			}
		}

		f(i, top + 1, n)
		{
			other1[i] = n;
		}

		if (other1[0] == n)
		{
			cout << 0 << endl;
			continue;
		}

		top = -1;
		f(i, 0, n)
		{
			if (arr[i] == '1')
			{
				f(j, top + 1, i + 1)
				{
					other2[j] = i;
				}
				top = i;
			}
		}

		f(i, top + 1, n)
		{
			other2[i] = n;
		}

		dp[n] = dp[n + 1] = 0;
		dp1[n] = dp1[n + 1] = 0;

		rf(i, n - 1, 0)
		{
			dp[i] = dp[i + 1];

			if (arr[i] == '0' && other2[i] < n)
				dp[i] = max(dp[i], dp[other2[i] + 1] + 1);

			if (arr[i] == '1' && other1[i] < n)
				dp[i] = max(dp[i], dp[other1[i] + 1] + 1);

			dp1[i] = dp1[i + 1];

			if (other2[i] < n)
				dp1[i] = max(dp1[i], dp[other2[i] + 1] + 1);
		}

		int l = dp1[0] + 1;
		int cur_idx = other2[0] + 1;
		string ans = "1";

		f(i, 1, l)
		{
			if (cur_idx >= n)
			{
				ans.pb('0');
				continue;
			}
			if (other1[cur_idx] >= n)
			{
				ans.pb('0');
				cur_idx = other1[cur_idx] + 1;
				continue;
			}

			if (dp[other1[cur_idx] + 1] < l - i - 1)
			{
				ans.pb('0');
				cur_idx = other1[cur_idx] + 1;
			}
			else
			{
				ans.pb('1');
				cur_idx = other2[cur_idx] + 1;
			}
		}

		cout << ans << endl;
	}


	/* **************** Your main function Code Above ****************** */

	return 0;
}
