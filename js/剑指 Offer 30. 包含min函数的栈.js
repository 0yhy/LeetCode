/**
 * initialize your data structure here.
 */
var MinStack = function () {
  this.s = [];
  this.m = [];
};

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {
  this.s.push(x);
  if (!this.m.length || x <= this.m[this.m.length - 1]) {
    this.m.push(x);
  }
  console.log(this.s, this.m);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
  if (this.s.pop() == this.m[this.m.length - 1]) {
    this.m.pop();
  }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
  return this.s[this.s.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.min = function () {
  return this.m[this.m.length - 1];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.min()
 */
var stack = new MinStack();
stack.push(-2);
stack.push(0);
stack.push(1);
console.log(stack.min());
console.log(stack.top());
stack.pop();
console.log(stack.min());
