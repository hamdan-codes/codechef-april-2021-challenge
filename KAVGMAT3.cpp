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
using namespace std;

typedef long long int ll;


void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif
}
/* ********************* Your Functions Below ********************** */









ll min(ll x, ll y) {
	if (x < y) {
		return x;
	}
	return y;
}

int main() {

	c_p_p();

	ll t;
	cin >> t;
	while (t--) {
		ll n, m, k;
		cin >> n >> m >> k;
		double mat[n + 1][m + 1];
		for (ll i = 0; i <= n; i++) {
			for (ll j = 0; j <= m; j++) {
				if (i == 0 || j == 0) {
					mat[i][j] = 0;
				}
				else {
					cin >> mat[i][j];
				}
			}
		}
		for (ll i = 0; i <= n; i++) {
			double pre = 0;
			for (ll j = 0; j <= m; j++) {
				mat[i][j] += pre;
				pre = mat[i][j];
			}
		}
		for (ll j = 0; j <= m; j++) {
			double pre = 0;
			for (ll i = 0; i <= n; i++) {
				mat[i][j] += pre;
				pre = mat[i][j];
			}
		}
		ll zz = min(n, m);
		ll ans = 0;
		for (ll len = 1; len <= zz; len++) {
			for (ll i = len; i <= n; i++) {
				for (ll j = len; j <= m; j++) {
					if ((mat[i][j] + mat[i - len][j - len] - mat[i][j - len] - mat[i - len][j]) / (len * len) >= k) {
						ans++;
					}
				}
			}

		}
		cout << ans << endl;
	}




	/* **************** Your main function Code Above ****************** */

	return 0;
}
