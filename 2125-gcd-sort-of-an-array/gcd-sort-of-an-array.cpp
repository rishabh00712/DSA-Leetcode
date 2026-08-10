class Solution {
public:
    struct DSU {
        vector<int> parent, size_;
        int components;
        
        DSU(int n) : parent(n), size_(n, 1), components(n) {
            iota(parent.begin(), parent.end(), 0);  // parent[i] = i initially
        }
        
        int find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];  // path compression (halving)
                x = parent[x];
            }
            return x;
        }
        
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (size_[a] < size_[b]) swap(a, b);
            parent[b] = a;
            size_[a] += size_[b];
            components--;
            return true;
        }
        
        bool same(int a, int b) {
            return find(a) == find(b);
        }
        
        int size(int x) {
            return size_[find(x)];
        }
    };

    vector<vector<int>> get_prime_divs(int N) {
        vector<vector<int>> divs(N+1);

        for (int i = 2; i <= N; i++) {
            if (divs[i].size() != 0) continue;
            for (int j = i; j <= N; j += i) {
                divs[j].push_back(i);
            }
        }

        return divs;
    }

    bool gcdSort(vector<int>& nums) {
        int N = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        DSU dsu(N+1);
        vector<vector<int>> divs = get_prime_divs(N);

        for (int i = 0; i < n; i++) {
            for (auto& div : divs[nums[i]]) {
                dsu.unite(nums[i], div);
            }
        }

        vector<int> b(nums.begin(), nums.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            if (!dsu.same(b[i], nums[i])) return false;
        }

        return true;
    }
};