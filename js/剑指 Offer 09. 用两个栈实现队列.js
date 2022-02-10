/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */

/*
  var CQueue = function () {
  this.stack1 = [];
  this.stack2 = [];
};

CQueue.prototype.appendTail = function (value) {
  this.stack1.push(value);
};

CQueue.prototype.deleteHead = function () {
  if (!this.stack2.length) {
    while (this.stack1.length) {
      this.stack2.push(this.stack1.pop());
    }
  }
  return this.stack2.pop() || -1;
};

*/

var CQueue = function () {
  this.stack1 = [];
  this.stack2 = [];
};

/**
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function (value) {
  this.stack1.push(value);
  if (!this.stack2.length) {
    while (this.stack1.length) {
      this.stack2.push(this.stack1.pop());
    }
  }
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function () {
  console.log("deleting", this.stack1, this.stack2);
  return this.stack2.pop() || -1;
};

const q = new CQueue();
console.log(q.deleteHead());
q.appendTail(1);
q.appendTail(2);
console.log(q.deleteHead());
console.log(q.deleteHead());
q.appendTail(3);
