#include <iostream>
#include <vector>

using namespace std;

struct HashTable {
    int size = 0;
    
    vector<vector<int>> table;
    HashTable(int s){
        this->size = s;
        table.resize(s);
    }
    
    void insert(int v){
        int hashed = hash(v);
        cout << "hash value for " << v << " is " << hashed << "\n";
        table[hashed].push_back(v);
    }
    
    int hash(int v){
        return v % size;
    }
    
    bool find(int v){
        int hashed = hash(v);
        
        for(auto val : table[hashed]){
            if(val == v){
                return true;
            }
        }
        return false;
    }
    
    void remove(int v){
        int hashed = hash(v);
        
        for(int i=0; i<table[hashed].size(); i++){
            if(table[hashed][i] == v){
                table[hashed].erase(table[hashed].begin()+i);
                break;
            }
        }
    }
    
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    HashTable *hashTable = new HashTable(10);
    
    hashTable->insert(3);
    hashTable->insert(7);
    hashTable->insert(17);
    hashTable->insert(20);
    hashTable->insert(31);
    hashTable->insert(52);
    hashTable->insert(76);
    
    cout << hashTable->find(7) << "\n";
    cout << hashTable->find(17) << "\n";
    cout << hashTable->find(32) << "\n";
    
    cout << hashTable->find(76) << "\n";
    hashTable->remove(76);
    cout << hashTable->find(76) << "\n";
    
    
    return 0;
    
}

