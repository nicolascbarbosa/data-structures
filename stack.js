class Stack {

  constructor() {
    this.stack = [];
    this.stack_min = [];
    this.value_minimum = 0;
  }

  push(value) {
    let len = this.stack.length;

    if(value >= this.value_minimum) {
      if(len == 0) {
        this.value_minimum = value;
      }     
    } else {          
      this.value_minimum = value;
    }
       
    this.stack[len] = value;
    this.stack_min[len] = this.value_minimum;
  }

  pop() {
    let len = this.stack.length - 1;

    delete this.stack.splice(len, 1); //or .pop
    delete this.stack_min.splice(len, 1); //or .pop
  }

  get Minimum() {
    return this.stack_min[0];
  }

}

const stack = new Stack;

stack.push(10);
stack.push(40);
stack.push(50);
stack.push(60);
stack.push(70);
stack.push(80);
stack.push(90);

stack.pop();

console.log(stack);