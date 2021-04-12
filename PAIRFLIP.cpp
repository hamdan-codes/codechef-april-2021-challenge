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
#define vs              vector<string>
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
#define mk(type,arr,n)  type *arr=new type[n]
#define w(x)            int x; cin >> x; while(x--)
#define f(i,x,y)        for(int i = x; i < y; i++)
#define rf(i,x,y)       for(int i = x; i >= y; i--)
#define test(x)           int ttt; cin >> ttt; for(int x=1;x<=ttt;x++)



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
		int n, m, e, ones = 0;
		cin >> n >> m >> e;

		vs A(n);
		string s;

		f(i, 0, n)
		{
			cin >> s;
			A[i] = s;

			ones += count(all(s), '1');
		}

		f(i, 0, n)
		{
			cin >> s;
		}

		if (ones % 2)
		{
			cout << -1 << endl;
		}
		else if (n == 2 && m == 2)
		{
			cout << -1 << endl;
		}
		else if (e == 0)
		{
			cout << (ones / 2) << endl;
		}
		else
		{
			cout << (ones / 2) << endl;

			f(i, 0, n)
			{
				f(j, 0, m - 2)
				{
					if (A[i][j] == '1' && A[i][j + 2] == '1')
					{
						cout << 'R' << " " << (i + 1) << " " << (j + 1) << " " << (j + 3) << endl;
						A[i][j] = '0';
						A[i][j + 2] = '0';
					}
				}
			}

			f(i, 0, m)
			{
				f(j, 0, n - 2)
				{
					if (A[j][i] == '1' && A[j + 2][i] == '1')
					{
						cout << 'C' << " " << (i + 1) << " " << (j + 1) << " " << (j + 3) << endl;
						A[j][i] = '0';
						A[j + 2][i] = '0';
					}
				}
			}
		}
	}





	/* **************** Your main function Code Above ****************** */

	return 0;
}
