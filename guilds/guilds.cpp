// C++ implementation of disjoint set
 
#include <bits/stdc++.h>
using namespace std;
 
#define UNITING 1
 
class DisjSet {
    int *rank, *parent, n, rafael_guild, *points;
 
public:
   
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n, vector<int> players_points)
    {
        rank = new int[n];
        parent = new int[n];
        points = new int[n];
        this->n = n;
        rafael_guild = 0;
        makeSet(players_points);
    }
    
    int get_rafael_guild(){
        return rafael_guild;
    }
    
    // Creates n single item sets
    void makeSet(vector<int> players_points)
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            points[i] = players_points[i];
        }
    }
 
    // Finds set of given item x
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
 
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);
 
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
 
        return parent[x];
    }
    
    // Finds set of given item x
    int get_points(int x)
    {
        return points[x];
    }
    
    void print_points()
    {
        for(int i = 0; i<n; i++)
            cout<<points[i]<<" ";
        cout<<endl;
    }
    
    void print_parent()
    {
        for(int i = 0; i<n; i++)
            cout<<parent[i]<<" ";
        cout<<endl;
    }
 
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
 
        // If they are already in same set
        if (xset == yset)
            return;
 
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            if(xset == rafael_guild){
                rafael_guild = yset;
            }
            parent[xset] = yset;
            points[yset] += points[xset];
        }
        else if (rank[xset] > rank[yset]) {
            if(yset == rafael_guild){
                rafael_guild = xset;
            }
            parent[yset] = xset;
            points[xset] += points[yset];
        }
 
        // If ranks are same, then increment
        // rank.
        else {
            if(yset == rafael_guild){
                rafael_guild = xset;
            }
            parent[yset] = xset;
            points[xset] += points[yset];
            rank[xset] = rank[xset] + 1;
        }
    }
};
 
// Driver Code
int main()
{
    
    int number_of_players, number_of_actions;
    
    cin>>number_of_players>>number_of_actions;
    
    while(number_of_players != 0 && number_of_actions != 0){
        int player;
        vector<int> players_points;
        int action, player_a, player_b, player_a_father, player_b_father;
        int rafael_win = 0;
        
        for (int i = 0; i < number_of_players; ++i){
            cin >> player;
            players_points.push_back(player);
        }
        
        DisjSet ds(number_of_players, players_points);
        
        for (int i = 0; i < number_of_actions; ++i){
            cin>>action>>player_a>>player_b;
            
            player_a -= 1;
            player_b -= 1;
            
            //ds.print_points();
            //ds.print_parent();
            //cout << "rafael guild "<< ds.get_rafael_guild() << endl;
            
            if(action == UNITING){
                ds.Union(player_a, player_b);
            } else {
                player_a_father = ds.find(player_a);
                player_b_father = ds.find(player_b);
                
                if(player_a_father == ds.get_rafael_guild()){
                    if(ds.get_points(player_a_father) > ds.get_points(player_b_father))
                        rafael_win += 1;
                } else if (player_b_father == ds.get_rafael_guild()) {
                    if(ds.get_points(player_b_father) > ds.get_points(player_a_father))
                        rafael_win += 1;
                }
            }
        }
        
        cout << rafael_win << endl;
            
        cin>>number_of_players>>number_of_actions;
        
    }
 
    return 0;
}