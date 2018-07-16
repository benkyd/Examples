class Node {
    constructor(value, parent) {
        this.Value = value;
        this.Parent = parent;
        this.Left = null;
        this.Right = null;
    }

    addNode(n) {
        if(n.Value < this.Value) {
            if (this.Left == null) {
                this.Left = n;
            } else {
                this.Left.addNode(n);
            }
        } else if (n.Value > this.Value) {
            if (this.Right == null) {
                this.Right = n;
            } else {
                this.Right.addNode(n);
            }
        }
    }
}

class Tree {
    constructor(values) {
        this.Values = values;
        this.Root = null;

        for (let value of this.Values) {
            this.addVal(value);
        }
    }

    addVal(val) {
        let n = new Node(val);
        if (this.Root == null) {
            this.Root = n;
        } else {
            this.Root.addNode(n);
        }
    }
}

let tree = new Tree([4,2,5,3,8,1]);
console.log(JSON.stringify(tree, 4, 2));