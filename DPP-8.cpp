//AUTHOR: HIMANSHU TIWARI
#include <bits/stdc++.h>
 
using namespace std;
 
#define nln '\n'
#define fr(i, l, h, s) for (long long i = l; i < h; i += s)
#define frr(i, h, l, s) for(long long i=h; i>=l; i-=s)
#define inp(arr) for(auto& x:arr) cin >> x
#define inpvp(arr) for(auto& x:arr) cin >> x.first >> x.second;
#define out(arr) for(auto x: arr) cout << x << ' '; cout << nln 
#define mout(m)   for(auto it: m){cout<<it.first<<" "<<it.second<<endl;}
#define outvp(vp) for(auto x: vp) cout << '(' << x.first << ", " << x.second << "), "; cout << nln;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define alr(arr, n) (arr), (arr) + (n)
#define sz(x) (ll)((x).size())
#define vi vector<int>
#define vf vector<float>
#define vll vector<ll>
#define vc vector<char>
#define vstr vector<string>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvc vector<vector<char>>
#define pb push_back
#define pob pop_back
#define xx first
#define yy second
#define yes cout<<"YES"<<endl
#define no  cout<<"NO"<<endl
 
const ll M = 1e9+7;
 
bool sorter(pll p1, pll p2)
{
    return true;
}
 
//===================================================================//
ll intfromstring(const string &s){int n=s.length();ll num=0;fr(i,0,n,1) num=num*10+(s[i]-'0');return num;}
string stringFromInt64(ll n){string s;if(n<10) {s.pb('0'+n); return s;}s=stringFromInt64(n/10);s.pb('0'+n%10);return s;}
ll factn(ll n){ll prod=1;if(n==0) return 1;fr(i,1,n+1,1)prod=((prod%M)*(i%M))%M;return prod%M;}
ll factlogn(ll lo, ll hi){if(hi-lo==1) return hi*lo;if(hi-lo==2) return hi*(hi-1)*(lo);int mid=(hi+lo)/2;return factlogn(lo,mid) * factlogn(mid+1,hi);}
ll maxl(long long int a, long long int b){if (a > b)return a;return b;}
ll minl(long long int a, long long int b){if (a < b) return a;return b;}
ll absl(long long int a){if(a<0) return -a; return a;}
ll powb(ll base, ll po){base%=M;if(base==1 || po==0) return 1;if(po==1) return base%M;if (po&1){ll x=powb(base, po/2)%M;return (((x*x)%M)*base)%M;}ll x = powb(base, po / 2)%M;return (x*x)%M;}
ll powbwomom(ll base, ll po){if (base == 1 || po == 0)return 1;if (po == 1)return base;if (po & 1){ll x = powbwomom(base, po / 2);return (((x * x)) * base);}ll x = powbwomom(base, po / 2);return (x * x);}
string Binary(ll n){if(!n) return "0"; stack<char> bin;while (n){if (n & 1)bin.push('1');else bin.push('0');n = n >> 1;}string str = "";while (bin.size()){str.push_back(bin.top());bin.pop();}return str;}
ll intFromBinary(string binary){reverse(all(binary));ll fact=1;ll ret=0;fr(i,0,sz(binary),1){ll mul=fact<<i;ret+=(binary[i]-'0')*mul;}return ret;}
void printbin(int n){if(n==0) return;printbin(n>>1);cout << (n&1);}
ll msb(ll n){ if(n==0) return 0; ll res=1; while(n/2!=0){ n/=2; res++;} return res;}
ll setBits(ll n){ll ref=1;ll ans=0;while(ref<=n){if((n&ref))ans++;ref<<=1;}return ans;}
void precision(int _n){cout << fixed << setprecision(_n);}
void google(int a) {cout << "Case #" << a << ": "; return;}
ll lcm(ll a, ll b){return (a * b) / __gcd(a, b);}
//====================================================================/
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
bool isPalin(string st,ll length)  
{  
    int flag=0;
  //ll length = strlen(st);
    
    for( ll k=0;k < length ;k++){
        if(st[k] != st[length-k-1]){
            flag = 1;
            break;
           }
        }
if(flag==0)    
return true;  
else    
return false;  
   
}  
bool binarySearch(vector<ll>&arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return true;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return false;
}
bool isvowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='U'||ch=='O')
        return true;
    else
        return false;
}
class disjoint_set
{
    private:
    vll par, rank;
    public:
    map<ll, ll> sze;
    void make(ll n)
    {
        fr(i,1,n+1,1)
        {
            par[i]=i;
            rank[i]=0;
        }
        return;
    }
    disjoint_set(ll n)
    {
        par.assign(n+1,0);
        rank.assign(n+1,0);
        make(n);
    }
    ll findParent(ll v)
    {
        if(par[v]==v) return v;
        return par[v]=findParent(par[v]);
    }
    void unionSet(ll a, ll b)
    {
        a=findParent(a);
        b=findParent(b);
        if(a==b) return;
        if(rank[a]<rank[b])
        {
            par[b]=a;
        }
        else if(rank[b]<rank[a])
        {
            par[a]=b;
        }
        else 
        {
            par[a]=b;
            ++rank[a];
        }
        return;
    }
};
int primeFactors(int n)//returning number of prime factor excluding 1 and number itself
   {
       int ans = 0;
       int num =n;
       for(int i=2; i<=num/2; i++)
       {
           while(n%i == 0)
           {
               ans++;
               n/= i;
           }
                      
       }   
       return ans;
   }
   int index(string newstring, char ch)
   {
       for(ll i=0;i<newstring.length();i++)
       {
           if(newstring[i]==ch)
           {
               return i;
           }
       }
       return -1;
   }
   int binarySearchString(vector<string>arr, string x) {
   int lower = 0;
   int upper = arr.size() - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res;
      if (x == (arr[mid]))
         res = 0;
      if (res == 0)
         return mid;
      if (x > (arr[mid]))
         lower = mid + 1;
      else
         upper = mid - 1;
   }
   return -1;
}
ll numberof2factor(ll num)
{
    ll c=0;
    while(num%2==0)
    {
       c++;
        num/=2;
    }
    return c;
}
   void rev(vector<ll>&v , int l , int h)
    {
        while ( l < h)
        {
            swap(v[l],v[h]);
            l++ ;
            h-- ;
        }
    }
    void dfs_traversal(vector<ll>&vis,ll node,vector<ll>adj[],vector<ll>&ls,ll n)
    {
     vis[node]=1;
     ls.push_back(node);
     for(auto it: adj[node])
     {
        if(!vis[it])
        {
           dfs_traversal(vis,it,adj,ls,n); 
        }
     }
    }
    int coonectivitycheck=0;
    void dfs(ll n,vector<ll>adj[])
    {
        vll vis(n,0);
        ll start=0;
        vll ls;
        dfs_traversal(vis,start,adj,ls,n);
        if(coonectivitycheck==1)
        {
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    cout<<"NOT CONNECTED"<<endl;
                    return;
                }
            }
            cout<<"CONNECTED"<<endl;
            return;
        }
        for(auto it: ls)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    void bfs(ll n,vector<ll>adj[])
    {
        vector<ll>vis(n,0);
        queue<ll>q;
        q.push(0);
        vector<ll>ls;
        //vis[0]=1;
        while(!q.empty())
        {
            ll node=q.front();
            vis[node]=1;
            ls.pb(node);
            q.pop();
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                q.push(it);
                }
            }
        }
        for(auto it: ls)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
     bool dfs_bip(ll node,ll c,vector<ll>&col,vector<ll>adj[])
    {
        col[node]=c;
        for(auto it: adj[node])
        {
            if(col[it]==-1)
            {
                if(!dfs_bip(it,1-c,col,adj))
                {
                    return false;
                }
            }
            else
            {
                if(col[node]==col[it])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isbipartite(ll n, vector<ll>adj[])
    {
        vll col(n,-1);
        for(ll i=0;i<n;i++)
        {
            ll c=0;
            if(col[i]==-1)
            {
             if(!dfs_bip(i,c,col,adj))
             {
                return false;
             }
            }
        }
        return true;
    }
    //bfs based
   void cyclicgraph(ll n,vector<ll>adj[])
   {
    vll vis(n,0);
    vis[0]=1;
    queue<pair<ll,ll>>q;//storing current node and previous node
    q.push({0,-1});
    while(!q.empty())
    {
        ll node=q.front().first;
        ll prev=q.front().second;
        q.pop();
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                vis[it]=1;
                q.push({it,node});
            }
            else
            {
                if(prev!=it)
                {
                    cout<<"has cycle"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"does not have a cycle"<<endl;
   }
   void toposort(ll n,vector<ll>adj[])
   {
    vector<ll>indegree(n,0);//number of incoming nodes
    for(ll i=0;i<n;i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }
  //  out(indegree);
    queue<ll>q;
    for(ll i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vll toposorted;
    while(!q.empty())
    {
      ll node=q.front();
      q.pop();
      toposorted.pb(node);
      for(auto it: adj[node])
      {
        indegree[it]--;
        if(indegree[it]==0)
        {
            q.push(it);
        }
      }
    }
    for(auto it: toposorted)
    {
        cout<<it<<" ";
    }
    cout<<endl;
   }
/*-------------------------------------------*/
  
void solve() {
ll n,E;
cin>>n>>E;
vector<ll>adj[n];
for(ll i=0;i<E;i++)
{
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);//for toposort we need to comment out this one
}
for(int i=0;i<n;i++)
{
    cout<<i<<" ";
    for(auto it: adj[i])
        cout<<it<<" ";
    cout<<endl;
}

//------------------------DFS----------------------------------------------------
dfs(n,adj);

//------------------------BFS---------------------------------------------------
bfs(n,adj);

//---------------------checking whether it is connected graph or not----------------

//simply idea is that we will go for dfs and if there exists any node which is not visted in that one dfs call
//then we can say that it is connected graph
coonectivitycheck=1;
dfs(n,adj);


//---------------------Bipartite graph------------------------------------------
bool ans=isbipartite(n,adj);
if(ans==1)
{
    cout<<"bipartite graph"<<endl;
}
else
{
    cout<<"NOT a bipartite graph"<<endl;
}

//----------------------CONTAINS CYCLE OR NOT-------------------------------

cyclicgraph(n,adj);//for undirected graph 
// for directed graph , we can go for topo sort as we know that topo sort exists only
//for directed acyclic graph

//-------------------------TOPO SORT------------------------------------

//USING BFS
 toposort(n,adj);
 return;
}



/*if without else waali error ko remove krne k liye ye check kro ki kahi if or else if k sattement k beech mein kopi varaible wagera toh nhi h 
RE:---kahi empty cheez ko toh nhi use kr rhe ho
kisi array mein increment or decrement kr rhe hoi toh ek baar uss array ko fir se use krne k liye kahiu copy kr lena 
-->
char ch=(9-('7'-'0'))+'0';
ch=2
kabhi bhi kisi question mein kuch element delete krne k baad usko correct order mein print krna ho toh 
sabse phele uss mein deletion peform kr lo then map mein store kr lo 
fir loop laga kr harr k element print kara do jo bhi uss map ka part ho
-----kabhi bhi error aaye toh ek baar check kr lo acche se
----->rotation in 2d matrix<--------
after rotating by 90 deg
a[i][j]->a[j][n-i-1]
after rotating by 180 deg
a[i][j]=a[n-i-1][n-j-1]
after rotating by 270 deg
a[i][j]=a[n-1-j][i]
*/ 






 

int main()
{

   //fast;
ll tx;
cin>>tx;
while(tx--)
{
  solve();
 
}
return 0;
}