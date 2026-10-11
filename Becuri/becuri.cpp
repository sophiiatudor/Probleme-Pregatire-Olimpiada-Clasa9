#include <fstream>

using namespace std;

ifstream cin("becuri.in");
ofstream cout("becuri.out");

const int N = 500;

int a[N + 1][N + 1];
bool lin[N + 1];
bool col[N + 1];

bool solve(int n, int m) {
	for (int j = 1; j <= m; j++) {
		if ((a[1][j] ^ lin[1]) == 1) {
			col[j] = true;
		}
	}
	for (int i = 2; i <= n; i++) {
		if ((a[i][1] ^ col[1]) == 1) {
			lin[i] = true;
		}
		for (int j = 2; j <= m; j++) {
			if ((a[i][j] ^ lin[i] ^ col[j]) != 0) {
				return false;
			}
		}
	}
	return true;
}

int count(int n, bool v[]) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += v[i];
	}
	return cnt;
}

void print(int ans, bool val, int n, int m) {
	cout << ans << "\n";

	for (int i = 1, j = 1; i <= n || j <= m; ) {
		if (i <= n && lin[i] != val) {
			i++;
		} else if (j <= m && col[j] != val) {
			j++;
		} else if (i <= n && j <= m) {
			cout << i << " " << j << "\n";
			i++; j++;
		} else if (i <= n) {
			cout << i << " 1\n";
			i++;
		} else {
			cout << "1 " << j << "\n";
			j++;
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	if (solve(n, m) == false) {
		cout << "-1\n";
		return 0;
	}
	
	int cnt_lin = count(n, lin);
	int cnt_col = count(m, col);

	int opt1 = -1;
	if (cnt_lin % 2 == cnt_col % 2) {
		opt1 = max(cnt_lin, cnt_col);
	}

	int opt2 = -1;
	if ((n - cnt_lin) % 2 == (m - cnt_lin) % 2) {
		opt2 = max(n - cnt_lin, m - cnt_col);
	}

	if (opt1 == -1 && opt2 == -1) {
		cout << "-1\n";
	} else if (opt2 == -1 || opt1 < opt2) {
		print(opt1, true, n, m);
	} else {
		print(opt2, false, n, m);
	}

	return 0;
}