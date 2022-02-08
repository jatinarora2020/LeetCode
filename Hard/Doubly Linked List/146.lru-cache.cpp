using namespace std;
#include "iostream"
#include "unordered_map"
struct DLL
{
    int key = -1;
    int value = -1;
    DLL* next  = NULL;
    DLL* prev = NULL;
};
// @lc code=start
class LRUCache {
    int lMaxCap;
    int lCurSize;
    DLL* lLastNode;
    DLL* lHeadNode;
    unordered_map<int,DLL*> lDllHash;
public:
    LRUCache(int capacity) {
        lMaxCap = capacity;
        lCurSize = 0;
        lLastNode = NULL;
        lHeadNode = NULL;
    }

    int get(int key);
    void put(int key, int value);
    DLL* Create_DLL_Node(int key, int value)
    {
        DLL* lRetVal = new DLL();
        lRetVal->key = key;
        lRetVal->value = value;
        lRetVal->next = NULL;
        lRetVal->prev = NULL;
        return lRetVal;
    }    
};

int LRUCache :: get (int key)
{
    DLL* lCurNode = NULL;
    int lRetVal = -1;
    unordered_map<int,DLL*>:: iterator itr;
    itr = lDllHash.find(key);
    if(itr == lDllHash.end())
        lRetVal = -1;
    else
    {
        lCurNode = itr->second;
        lRetVal = lCurNode->value;
        if(lCurNode != lHeadNode)
        {
        lCurNode->prev->next = lCurNode->next;
        if(lCurNode == lLastNode)
            lLastNode = lCurNode->prev;
        else
            lCurNode->next->prev = lCurNode->prev;
        lCurNode->next = lHeadNode;
        lHeadNode->prev = lCurNode;
        lHeadNode = lCurNode;
        lHeadNode->prev = NULL;
        }
    }
    return lRetVal;
}

void LRUCache :: put(int key, int value)
{
    DLL* lCurNode = NULL;
    unordered_map<int,DLL*>:: iterator itr;

    itr = lDllHash.find(key);
    if(itr == lDllHash.end())
    {
         if(lCurSize == lMaxCap ) //Perform Deletion in the list as Per LRU
         {
             if(lLastNode != lHeadNode)
             {
               lCurNode = lLastNode->prev;
               lCurNode->next = NULL;
             }
            lDllHash.erase(lLastNode->key);
            delete(lLastNode);
            if(lCurNode != NULL)
               lLastNode = lCurNode;
            lCurSize--;   
        }
        lCurNode = Create_DLL_Node(key,value);
        if(lCurSize == 0)
        {
            lCurSize++;
            lHeadNode = lCurNode;
            lLastNode = lCurNode;
            lDllHash.insert({key,lCurNode});
            return;
        }
        lCurSize++;
        lDllHash.insert({key,lCurNode});
        lCurNode->next = lHeadNode;
        lHeadNode->prev = lCurNode;
        lHeadNode = lCurNode;
        lHeadNode->prev = NULL;
    }
    else
    {
        lCurNode = itr->second;
        lCurNode->value = value;
        if(lCurNode != lHeadNode)
        {
        lCurNode->prev->next = lCurNode->next;
        if(lCurNode == lLastNode)
            lLastNode = lCurNode->prev;
        else
            lCurNode->next->prev = lCurNode->prev;
        lCurNode->next = lHeadNode;
        lHeadNode->prev = lCurNode;
        lHeadNode = lCurNode;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
  /* 
  ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

   LRUCache lObj(2);
    lObj.put(1,1);
    lObj.put(2,2);
    cout <<endl<< lObj.get(1);
    lObj.put(3,3);
    cout<<endl << lObj.get(2);
    lObj.put(4,4);
    cout<<endl<<lObj.get(1);
    cout<<endl<<lObj.get(3);
    cout<<endl<<lObj.get(4);*/

  /*  ["LRUCache","put","get","put","get","get"]
[[1],[2,1],[2],[3,2],[2],[3]]

    LRUCache lObj(1);
    lObj.put(2,1);
    cout <<endl<< lObj.get(2);
    lObj.put(3,2);
    cout<<endl << lObj.get(2);
    cout<<endl<<lObj.get(3); */

  /*  ["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
[[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]] */

    LRUCache lObj(3);
    lObj.put(1,1);
    lObj.put(2,2);
    lObj.put(3,3);
    lObj.put(4,4);
    cout<<endl<<lObj.get(4);
    cout<<endl<<lObj.get(3);
    cout<<endl<<lObj.get(2);
    cout<<endl<<lObj.get(1);
    lObj.put(5,5);
    cout<<endl<<lObj.get(1);
    cout<<endl<<lObj.get(2);
    cout<<endl<<lObj.get(3);
    cout<<endl<<lObj.get(4);
    cout<<endl<<lObj.get(5);
    return 0;
    
}