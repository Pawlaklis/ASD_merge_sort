#include <ctime>
#include <algorithm>
#include <iostream>

void generate_random(int arr[], int n, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (b - a) + a;
    }
}

void merge(int arr[], int p, int q, int r) {
    int l_array[q - p + 1];
    int r_array[r - q];

    for (int i = 0; i < q - p + 1; ++i) {
        l_array[i] = arr[i + p];
    }
    for (int i = 0; i < r - q; ++i) {
        r_array[i] = arr[i + q + 1];
    }
    int L = 0, R = 0;
    int i = p;
    while(L < q - p + 1&& R < r - q){
        if(l_array[L] < r_array[R]){
            arr[i] = l_array[L];
            L++;
        }
        else{
            arr[i] = r_array[R];
            R++;
        }
        i++;
    }
    while(L < q - p + 1){
        arr[i] = l_array[L];
        L++;
        i++;
    }
    while(R < r - q){
        arr[i] = r_array[R];
        R++;
        i++;
    }
}

void merge_sort(int arr[], int p, int r){
    if(p < r) {
        int q = p + (r - p) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}



int main() {
    int n;
    std::cin >> n;
    int arr[n];

    generate_random(arr, n, -1000, 1000);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

    merge_sort(arr, 0, n);


    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
