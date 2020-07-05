/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (30.13%)
 * Likes:    5789
 * Dislikes: 259
 * Total Accepted:    552.4K
 * Total Submissions: 1.7M
 * Testcase Example:
'["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 *
 * LRUCache cache = new LRUCache( 2  capacity  );
**cache.put(1, 1);
*cache.put(2, 2);
*cache.get(1);     // returns 1
*cache.put(3, 3);  // evicts key 2
*cache.get(2);     // returns -1 (not found)
*cache.put(4, 4);  // evicts key 1
*cache.get(1);     // returns -1 (not found)
*cache.get(3);     // returns 3
*cache.get(4);     // returns 4
*****/
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class LRUCache {
 private:
  struct KVPair {
    int k, v;
    KVPair(int k, int v) : k(k), v(v) {}
  };
  unordered_map<int, list<KVPair>::iterator> m;
  list<KVPair> l;
  int cap;

 public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (m.count(key)) {
      int val = m[key]->v;
      l.erase(m[key]);
      KVPair kv = KVPair(key, val);  // OR kv = *m[key];
      l.push_front(kv);              // emplace_front(k,v)
      m[key] = l.begin();
      return val;
    } else
      return -1;
  }

  void put(int key, int value) {
    if (m.count(key)) {
      l.erase(m[key]);
      KVPair kv = KVPair(key, value);
      l.push_front(kv);
      m[key] = l.begin();
    } else {
      KVPair kv = KVPair(key, value);
      l.push_front(kv);
      m[key] = l.begin();
    }

    if (m.size() > cap) {
      KVPair p = l.back();
      l.pop_back();
      m.erase(p.k);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
