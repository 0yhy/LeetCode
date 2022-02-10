/*
 * @lc app=leetcode.cn id=146 lang=typescript
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class DbLinkedList {
  key: number;
  val: number;
  prev: DbLinkedList | null;
  next: DbLinkedList | null;
  constructor(
    key: number,
    val?: number,
    prev?: DbLinkedList | null,
    next?: DbLinkedList | null
  ) {
    this.key = key;
    this.val = val === undefined ? 0 : val;
    this.prev = prev === undefined ? null : prev;
    this.next = next === undefined ? null : next;
  }
}
class LRUCache {
  capacity: number;
  cnt: number;
  head: DbLinkedList;
  tail: DbLinkedList;
  map: object;
  constructor(capacity: number) {
    this.capacity = capacity;
    this.head = new DbLinkedList(-1, -1);
    this.tail = new DbLinkedList(-1, -1, this.head, null);
    this.head.next = this.tail;
    this.cnt = 0;
    this.map = {};
  }
  /**
   * 将某一结点插入头部
   * @param cur 待插入节点
   */
  private insert(cur: DbLinkedList) {
    let tmp = this.head.next;
    cur.prev = this.head;
    cur.next = tmp;
    tmp.prev = cur;
    this.head.next = cur;
  }
  private delete(cur: DbLinkedList) {
    cur.prev.next = cur.next;
    cur.next.prev = cur.prev;
  }
  get(key: number): number {
    const cur: DbLinkedList = this.map[key];
    if (cur) {
      this.delete(cur);
      this.insert(cur);
      return cur.val;
    }
    return -1;
  }
  put(key: number, value: number): void {
    const p = new DbLinkedList(key, value);
    // 该key不存在
    if (!this.map[key]) {
      this.insert(p);
      if (this.cnt < this.capacity) ++this.cnt;
      else {
        // 淘汰尾部元素
        let prev = this.tail.prev;
        delete this.map[prev.key];
        prev.next = null;
        this.tail = prev;
      }
    }
    // 该key已经存在
    else {
      const cur = this.map[key];
      this.delete(cur);
      this.insert(p);
    }
    this.map[key] = p;
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
// @lc code=end
