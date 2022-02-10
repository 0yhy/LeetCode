/*
 * @lc app=leetcode.cn id=208 lang=typescript
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class TrieNode {
  isEnd: boolean;
  children: Map<string, TrieNode>;
  constructor() {
    this.children = new Map();
    this.isEnd = false;
  }
}

class Trie {
  root: TrieNode;

  constructor() {
    this.root = new TrieNode();
  }

  insert(word: string): void {
    let cur: TrieNode = this.root;
    for (let i = 0; i < word.length; cur = cur.children.get(word[i]), ++i) {
      if (!cur.children.has(word[i])) {
        cur.children.set(word[i], new TrieNode());
      }
    }
    cur.isEnd = true;
  }

  search(word: string): boolean {
    let cur: TrieNode = this.root;
    for (let i = 0; i < word.length; cur = cur.children.get(word[i]), ++i) {
      if (!cur.children.has(word[i])) return false;
    }
    return cur.isEnd;
  }

  startsWith(prefix: string): boolean {
    let cur: TrieNode = this.root;
    for (let i = 0; i < prefix.length; cur = cur.children.get(prefix[i]), ++i) {
      if (!cur.children.has(prefix[i])) return false;
    }
    return true;
  }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
// @lc code=end
