
// Author: Nguyen Quoc Phu Dep Trai    

#include<bits/stdc++.h>
using namespace std; 

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define int long long
#define db long double
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll> 
#define ve vector 
#define uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin())
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define pt pop_front
#define pf push_front
#define LB lower_bound
#define UB upper_bound 
#define sz(x) (int)((x).size())
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define btctz(a) __builtin_ctz(a) // bit 1 MIN
#define btclz(a) __builtin_clz(a)  // bit 1 MAX
#define            tct  template<typename T>
#define BIT(x,i) ((x>>i)&1)
#define MASK(x) (1<<(x))
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
ll rd(ll l,ll r){return l+1ll*rand()*rand()%(r-l+1);}

tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}
#define print(a) for(auto  _v : a )cout<<_v<<" ";cout<<'\n';

const int N = 1e6+5 , maxN=20, CH = 26 ;
const ll sm = 1e9+7 , base=311, inf = (int)1e9 , llinf = (ll)1e18 + 7LL , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
void add(ll &a,ll b){a+=b; if(a>=sm)a-=sm;}
void del(ll &a,ll b){a-=b; if(a<0)a+=sm;}
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};



vector<char>board;
char PLAYER_X = 'X';
char PLAYER_O = 'O';
char EMPTY = '.';

void display_board(){
    f(i,1,3) cout<<board[i]<<"  ";
    cout<<el;
    f(i,4,6) cout<<board[i]<<"  ";
    cout<<el;
    f(i,7,9) cout<<board[i]<<"  ";
    cout<<el;
}

int WhoWin(){
    f(x,0,2){
        if(board[1+3*x]==board[2+3*x]&&board[2+3*x]==board[3+3*x]&&board[3+3*x]!=EMPTY){
            if(board[1+3*x]==PLAYER_X) return 1;
            return -1;
        }
    }
    f(x,1,3){
        if(board[x]==board[x+3]&&board[x+3]==board[x+6]&&board[x]!=EMPTY){
            if(board[x]==PLAYER_X) return 1;
            return -1;
        }
    }
    if(board[1]==board[5]&&board[5]==board[9]&&board[1]!=EMPTY){
        if(board[1]==PLAYER_X) return 1;
        return -1;
    }
    if(board[3]==board[5]&&board[5]==board[7]&&board[7]!=EMPTY){
        if(board[3]==PLAYER_X) return 1;
        return -1;
    }
    f(i,1,9) if(board[i]==EMPTY) return 0;
    return 2;
}
vector<int> MOVE(){
    vll SAVE;
    f(i,1,9)if(board[i]==EMPTY)SAVE.pb(i);
    return SAVE;
}
int Point(vector<int>&move, int depth,int player){
    int result = WhoWin();
    if(result!=0){
        if(result==2) return 0;
        if(result==1) return 10-depth;
        return -1*(depth+1);
    }
    int cost;
    if(player){
        int MIN=0;
        for(auto step:move){
            board[step]=PLAYER_X;
            vll newmove=MOVE();
            maxi(MIN,Point(newmove,depth+1,player^1));
            board[step]=EMPTY;
        }
        cost=MIN;
    }

    else {
        int MAX=inf;
        for(auto step:move){
            board[step]=PLAYER_O;
            vll newmove=MOVE();
            mini(MAX,Point(newmove,depth+1,player^1));
            board[step]=EMPTY;
        }
        cost=MAX;
    }
    return cost;
}
signed main(){
    board.resize(10,EMPTY);
    display_board();
    while(!WhoWin()){
        cout<<"Please enter the number from 1 to 9: ";
        int number; cin>>number;
        if(board[number]!=EMPTY){
            cout<<"Your step error! Please try again.";
            continue;
        }
        board[number]=PLAYER_X;
        vll move=MOVE();
        int bestmove=-1;
        int cost=inf;
        for(auto step:move){
            board[step]=PLAYER_O;
            vll newmove=MOVE();
            if(mini(cost,Point(newmove,0,1))){
                bestmove=step;
            }
            board[step]=EMPTY;
        }
        board[bestmove]=PLAYER_O;
        display_board();
    }
    if(WhoWin()==1){
        cout<<"Congratulation you won!"<<el;
    }
    else if(WhoWin()==-1){
        cout<<"Sorry you lose!"<<el;
    }
    else cout<<"Draw!"<<el;
    return 0;
}