#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n=0){ init(n); }
    void init(int n){
        p.resize(n);
        r.assign(n,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

struct Edge {
    int u, v;
    int w;
    bool operator<(Edge const& other) const { return w < other.w; }
};

static inline int manhattan(const vector<vector<int>>& pts, int i, int j){
    return abs(pts[i][0]-pts[j][0]) + abs(pts[i][1]-pts[j][1]);
}

// Fenwick tree for MAX query on prefix [1..idx]
struct FenwickMax {
    int n;
    vector<pair<long long,int>> bit; // (value, index)
    FenwickMax(int n=0){ init(n); }
    void init(int n_){
        n=n_;
        bit.assign(n+1, {LLONG_MIN, -1});
    }
    void update(int i, pair<long long,int> val){
        for(; i<=n; i+=i&-i) bit[i] = max(bit[i], val);
    }
    pair<long long,int> query(int i){
        pair<long long,int> res = {LLONG_MIN, -1};
        for(; i>0; i-=i&-i) res = max(res, bit[i]);
        return res;
    }
};

int minCostConnectPoints_ManhattanMST(vector<vector<int>>& points) {
    int n = (int)points.size();
    vector<Edge> edges;
    edges.reserve(8*n);

    // store original coords
    vector<long long> ox(n), oy(n);
    for(int i=0;i<n;i++){
        ox[i]=points[i][0];
        oy[i]=points[i][1];
    }

    // Each transform: x' = sx*x, y' = sy*y, optional swap
    // 8 transforms cover all quadrants and swap cases
    for(int swapXY=0; swapXY<2; swapXY++){
        for(int sx : {-1, 1}){
            for(int sy : {-1, 1}){
                // Build transformed points
                struct P { long long x,y; int id; };
                vector<P> a(n);
                for(int i=0;i<n;i++){
                    long long x = ox[i], y = oy[i];
                    if(swapXY) swap(x,y);
                    x *= sx;
                    y *= sy;
                    a[i] = {x,y,i};
                }

                // Sort by x then y (process increasing x ensures previous points have <=x)
                sort(a.begin(), a.end(), [](const P& A, const P& B){
                    if(A.x != B.x) return A.x < B.x;
                    return A.y < B.y;
                });

                // coordinate compress y
                vector<long long> ys;
                ys.reserve(n);
                for(auto &p: a) ys.push_back(p.y);
                sort(ys.begin(), ys.end());
                ys.erase(unique(ys.begin(), ys.end()), ys.end());

                FenwickMax fw((int)ys.size());

                // For each point p, query best previous with y_prev <= y_p
                for(auto &p: a){
                    int yi = (int)(lower_bound(ys.begin(), ys.end(), p.y) - ys.begin()) + 1;

                    auto best = fw.query(yi);
                    if(best.second != -1){
                        int u = p.id;
                        int v = best.second;
                        int w = manhattan(points, u, v);
                        edges.push_back({u, v, w});
                    }

                    // Update with value = x+y (maximize this)
                    fw.update(yi, {p.x + p.y, p.id});
                }
            }
        }
    }

    // Kruskal on candidate edges
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long ans = 0;
    int used = 0;
    for(auto &e: edges){
        if(dsu.unite(e.u, e.v)){
            ans += e.w;
            used++;
            if(used == n-1) break;
        }
    }

    return (int)ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> points[i][0] >> points[i][1];
    }

    cout << "Minimum Cost: " << minCostConnectPoints_ManhattanMST(points) << "\n";
    return 0;
}
