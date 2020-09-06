class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n), aux(n);
        vector<int> counter(n);
        for (int i = 0; i < n; i ++)
            v[i] = make_pair(nums[i], i);
        mergeSort(v, 0, n - 1, aux, counter);
        return counter;
    }
    void mergeSort(vector<pair<int, int>>& v, int l, int r, vector<pair<int, int>>& aux, vector<int>& counter){
        if (l >= r) return;
        int mid = l + ((r - l) >> 1);
        mergeSort(v, l, mid, aux, counter);
        mergeSort(v, mid + 1, r, aux, counter);
        merge(v, l, mid, r, aux, counter);
    }
    void merge(vector<pair<int, int>>& v, int l, int mid, int r, vector<pair<int, int>>& aux, vector<int>& counter
        ) {
        int i = l, j = mid + 1, k = l;
        while (i <= mid || j <= r){
            if (i > mid) aux[k ++] = v[j ++];
            else if (j > r) aux[k ++] = v[i ++];
            else if (v[i].first <= v[j].first) aux[k ++] = v[j ++];
            else {
                counter[v[i].second] += r - j + 1;
                aux[k ++] = v[i ++];
            }
        }
        for (k = l; k <= r; k ++) v[k] = aux[k];
    }
};
