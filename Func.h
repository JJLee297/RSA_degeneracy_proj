#include <iostream>

using namespace std;

class Key {
public:
	void setKey(int mod, int ex, int degs) {
		m = mod;
		e = ex;
		deg = degs;
	}
	void output() {
		if (e >= 100)
			cout << e << "; " << deg << endl;
		else if (e >= 10)
			cout << "0" << e << "; " << deg << endl;
		else
			cout << "00" << e << "; " << deg << endl;
	}
	bool operator < (const Key& str) const {
		return (deg < str.deg);
	}
private:
	int m;
	int e;
	int deg;
};

void show(vector<ll> ex) {
	for (int i = 0; i < ex.size(); ++i) {
		cout << ex[i] << " ";
	}
	cout << "\n";
}

int solve(int x, int y, int p) {
	int res = 1;
	x = x % p;
	if (x == 0) return 0;
	while (y > 0) {
		if (y & 1)
			res = (res*x) % p;
		y = y >> 1;
		x = (x*x) % p;
	}
	return res;
}

vector<ll> cop(int phi) {
	vector<ll> ret;
	vector<ll> factors;
	int b = phi;
	factors.push_back(2);
	while (phi % 2 == 0) {
		phi /= 2;
	}
	for (int i = 3; i <= phi; i += 2) {
		if (phi % i == 0) {
			factors.push_back(i);
			while (phi % i == 0)
				phi = phi / i;
		}
	}
	int k = factors.size();
	for (int i = 1; i < b; ++i) {
		bool check = false;
		for (int j = 0; j < k; ++j) {
			if (i % factors[j] == 0) {
				check = true;
				break;
			}
		}
		if (check == false) {
			ret.push_back(i);
		}
	}
	return ret;
}

ll countDegen2(int e, int m, vector<ll> v) {
	vector<ll> bruh = v;
	ll ret = 0;
	for (int i = 0; i < m; ++i) {
		if (solve(i, e, m) == i) {
			++ret;
		}
	}
	return ret;
}

ll countDegen(int e, int m, vector<ll> v) {
	vector<ll> bruh = v;
	ll ret = 0;
	for (int i = 0; i < bruh.size(); ++i) {
		int test = solve(bruh[i], e, m);
		if (test > bruh[i]) {
			bruh.erase(std::remove(bruh.begin(), bruh.end(), test), bruh.end());
		}
		else if (test == bruh[i]) {
			++ret;
		}
	}
	return ret;
}

ll countTotDegen(int m, vector<ll> evals) {
	vector<ll> v(m);
	iota(begin(v), end(v), 0);
	ll ret = 0;
	for (int i = 0; i < evals.size(); ++i) {
		ret += countDegen(evals[i], m, v);
	}
	return ret;
}

void assign(ll M, ll evalSize, ll totDegen) {
	int ind = 0;
	while (1) {
		if (M <= mRange[ind])
			break;
		else
			ind++;
	}
	totMes[ind] += (M * evalSize);
	degMes[ind] += totDegen;
	keyCount[ind] += evalSize;
}

void write(int firstp, int secondp) {
	ofstream textfile;
	textfile.open("poggers.txt", ofstream::out | ofstream::trunc);
	if (textfile.is_open())
	{
		textfile << firstp << "\n" << secondp << "\n";
		for (int i = 0; i < 34; ++i) {
			textfile << degMes[i] << " ";
		}
		textfile << endl;
		for (int i = 0; i < 34; ++i) {
			textfile << totMes[i] << " ";
		}
		textfile << endl;
		for (int i = 0; i < 34; ++i) {
			textfile << keyCount[i] << " ";
		}
	}
	textfile.close();
}

vector<ll> read(string in) {
	vector<ll> reader;
	for (int i = 0; i < 34; ++i) {
		reader.push_back(0);
	}
	int a = 0;
	int k = 0;
	for (int i = 0; i < in.length(); ++i) {
		if (in[i] != ' ') {
			a *= 10;
			a += (in[i] - '0');
		}
		else {
			reader[k] = a;
			++k;
			a = 0;
		}
	}
	return reader;
}

void tester() {
	cout << "Enter f[0-383]: ";
	int f, s;
	cin >> f;
	cout << "\nEnter s[0-383]:";
	cin >> s;
	ll m = primes[f] * primes[s];
	vector<ll> evals = cop((primes[f] - 1) * (primes[s] - 1));
	vector<ll> v(m);
	iota(begin(v), end(v), 0);
	for (int i = 0; i < evals.size(); ++i) {
		cout << "Key: (" << m << ", " << evals[i] << ")\n";
		cout << countDegen(evals[i], m, v) << endl;
	}
	system("pause");
}

void tester2() {
	for (int i = 0; i < 989; ++i) {
		if (solve(i, 43, 989) == i) {
			cout << i << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < 989; ++i) {
		if (solve(i, 85, 989) == i) {
			cout << i << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < 989; ++i) {
		if (solve(i, 127, 989) == i) {
			cout << i << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < 989; ++i) {
		if (solve(i, 169, 989) == i) {
			cout << i << " ";
		}
	}
	system("pause");
}


void tester3() {
	for (int i = 0; i < 20; ++i) {
		int ret = 0;
		for (int x = 0; x < 989; ++x) {
			if (solve(x, 43 + (43 - 1) * i, 989) == x) {
				++ret;
			}
		}
		cout << "Key: (989, " << 43 + 42 * i << "): " << ret << endl;
	}
	system("pause");
}



void tester4() {
	int ret = 0;
	for (int m = 0; m < 77; ++m) {
		if (solve(m, 11, 77) == m) {
			cout << m << "\n";
		}
	}
	system("pause");
}


// used for outputting all valid RSA keys
void tester5() {
	ll m = primes[0] * primes[1];
	vector<ll> evals = cop((primes[0] - 1) * (primes[1] - 1));
	vector<ll> v(m);
	vector<Key> keep;
	iota(begin(v), end(v), 0);
	for (int i = 0; i < evals.size(); ++i) {
		Key newt;
		int e = countDegen(evals[i], m, v);
		newt.setKey(m, evals[i], e);
		keep.push_back(newt);
	}
	sort(keep.begin(), keep.end());
	for (int i = 0; i < keep.size(); ++i) {
		keep[i].output();
	}
	system("pause");
}


// used for outputing all keys
// will take significantly more time due to duplicate outputs 
void tester6() {
	ll m = primes[10] * primes[12];
	vector<ll> evals((primes[10] - 1) * (primes[12] - 1) - 1);
	iota(begin(evals), end(evals), 1);
	vector<ll> v(m);
	vector<Key> keep;
	iota(begin(v), end(v), 0);
	for (int i = 0; i < evals.size(); ++i) {
		Key newt;
		int e = countDegen2(evals[i], m, v);
		newt.setKey(m, evals[i], e);
		keep.push_back(newt);
	}
	sort(keep.begin(), keep.end());
	for (int i = 0; i < keep.size(); ++i) {
		keep[i].output();
	}
	system("pause");
}



void tester7() {
	for (int m = 0; m < 15; ++m) {
		if (solve(m, 3, 15) == m) {
			cout << m << "\n";
		}
	}
	system("pause");
}

void tester8() {
	int a = 0;
	int b = 0;
	for (int m = 0; m < 221; ++m) {
		//cout << m << " " << solve(m, 5, 221);
		if (solve(m, 5, 221) == m) {
			cout << m << endl;
		}
		//cout << endl;
	}
	for (int m = 0; m < 221; ++m) {
		//cout << m << " " << solve(m, 29, 221) << endl;
	}
	for (int m = 0; m < 221; ++m) {
		//cout << m << " " << solve(m, 53, 221) << endl;
	}
	system("pause");
}
