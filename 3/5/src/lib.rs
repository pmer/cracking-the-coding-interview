// Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can
// use an additional temporary stack, but you may not copy the elements into any other data
// structure (such as an array). The stack supports the following operations: push, pop, peek, and
// isEmpty.

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct Stack {
    items: Vec<i32>,
}

impl Stack {
    pub fn new() -> Self {
        Stack{
            items: vec![],
        }
    }

    pub fn push(&mut self, x: i32) {
        self.items.push(x);
    }

    pub fn pop(&mut self) -> i32 {
        self.items.pop().unwrap()
    }

    pub fn peek(&self) -> i32 {
        self.items[self.items.len() - 1]
    }

    pub fn is_empty(&self) -> bool {
        self.items.len() == 0
    }
}

// An insertion sort.
pub fn sort(mut unsorted: Stack) -> Stack {
    let mut sorted = Stack::new();

    while !unsorted.is_empty() {
        let to_insert = unsorted.pop();

        let mut num_moved = 0;
        while !sorted.is_empty() && to_insert < sorted.peek() {
            unsorted.push(sorted.pop());
            num_moved += 1;
        }

        sorted.push(to_insert);

        while num_moved > 0 {
            sorted.push(unsorted.pop());
            num_moved -= 1;
        }
    }

    sorted
}

#[test]
fn test_empty() {
    test_with(vec![]);
}

#[test]
fn test_single() {
    test_with(vec![0]);
}

#[test]
fn test_two_one_unique() {
    test_with(vec![0, 0]);
}

#[test]
fn test_two_two_unique() {
    test_with(vec![0, 1]);
    test_with(vec![1, 0]);
}

#[test]
fn test_three_two_unique() {
    test_with(vec![0, 0, 1]);
    test_with(vec![0, 1, 0]);
    test_with(vec![1, 0, 0]);
}

#[test]
fn test_three_three_unique() {
    test_with(vec![0, 1, 2]);
    test_with(vec![0, 2, 1]);
    test_with(vec![1, 0, 2]);
    test_with(vec![1, 2, 0]);
    test_with(vec![2, 0, 1]);
    test_with(vec![2, 1, 0]);
}

#[allow(dead_code)]
fn test_with(xs: Vec<i32>) {
    let my_sorted = sort(Stack{items: xs.clone()});

    let mut true_sorted = xs.clone();
    true_sorted.sort();
    let true_sorted = Stack{items: true_sorted};

    assert_eq!((&xs, my_sorted), (&xs, true_sorted));
}
