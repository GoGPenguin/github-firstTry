    #include <bits/stdc++.h>
    using namespace std;
    
    #define pb push_back
    #define ull unsigned long long
    #define lcm(a, b)  (a*b) / __gcd(a, b)
    #define mod 1000000007
    #define int long long

//void Sert(int a[], int n){
//	for (int i = 0; i < n- 1; i++){
//		int min = i;
//		for (int j = i + 1; j < n; j++){
//			if (a[j] < a[min]) min = j;
//		}
//		swap(a[i], a[min]);
//	}
//}

void Sert(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		int Min = i;
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[i]) Min = j;
		}
		swap(a[i], a[Min]);
	}
}

//void BubSort(int a[], int n){
//	for (int i = 0; i < n - 1; i++){
//		for (int j = 0; j < n - i - 1; j++){
//			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
//		}
//	}
//}

void BubSort(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}

//void Insort(int a[], int n){
//	for (int i = 1; i < n; i++){
//		int key = a[i];
//		int j = i - 1;
//		while (j >= 0 && a[j] > key){
//			a[j + 1] = a[j];
//			j--;
//		}
//		a[j + 1] = key;
//	}
//}

void Insort(int a[], int n){
	for (int i = 1; i < n; i++){
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
}

//int Partition(int a[], int l, int r){
//	int p = a[r];
//	int i = l - 1; 
//	for (int j = l; j < r; j++){
//		if (a[j] < p) {
//			++i;
//			swap(a[j], a[i]);
//		}
//	}
//	++i;
//	swap(a[i], a[r]);
//	return i;
//}

int Partition(int a[], int l, int r){
	int p = a[r];
	int i = l - 1;
	
	for (int j = l; j < r; j++){
		if (a[j] < p){
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void QSortLomuto(int a[], int l, int r){
	if (l >= r) return;
	else {
		int p = Partition(a, l, r);
		QSortLomuto(a, l, p - 1);
		QSortLomuto(a, p + 1, r);
	} 
}
//
//int partition2(int a[], int l, int r){
//	int p = a[l];
//	int i = l - 1, j = r + 1;
//	
//	while (1){
//		do{
//			++i;
//		} while (a[i] < p);
//		
//		do{
//			--j;
//		} while (a[j] > p);
//		if (i < j) {
//			swap(a[i], a[j]);
//		}
//		else return j;
//	}
//	
//}

int partition2(int a[], int l, int r){
	int p = a[l];
	int i = l - 1, j = r + 1;
	
	while (1){
		do {
			++i;
		} while (a[i] < p);
		
		do {
			--j;
		} while (a[j] > p);
		
		if (i < j) swap(a[i], a[j]);
		else return j;
	}
}

//void QSortHoare(int a[], int l, int r){
//	if (l >= r) return;
//	int p = partition2(a, l , r);
//	QSortHoare(a, l , p);
//	QSortHoare(a, p + 1, r);
//}

void QSortHoare(int a[], int l, int r){
	if (l >= r) return;
	int p = partition2(a, l, r);
	QSortHoare(a, l, p);
	QSortHoare(a, p + 1, r);
}


signed main()
{	
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
//	Sert(a, n);
//	BubSort(a, n);
//	Insort(a, n);
//	QSortLomuto(a, 0, n - 1);
	QSortHoare(a, 0, n -1);
	for (int i = 0; i < n; i++) cout << a[i];
}
