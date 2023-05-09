pub enum  Node{
    Val(i32, Box<Node>),
    Null
}

pub struct LinkedList {
    first: Node,
    last: Node,
}

impl LinkedList {
    // pub fn addAtEnd
}

use Node::{Val, Null};

pub fn makeLinkedList() {
    let list = Val(1, Box::new(Val(2, Box::new(Null))));
}

