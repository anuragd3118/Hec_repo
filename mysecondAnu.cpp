Skip to content
DEV Community 👩‍💻👨‍💻
Search...

Log in
Create account

5
Like
0
Jump to Comments
1
Save

Cover image for 103. Binary Tree Zigzag Level Order Traversal 🚀
Samuel Hinchliffe 🚀
Samuel Hinchliffe 🚀
Posted on May 6

103. Binary Tree Zigzag Level Order Traversal 🚀
#
javascript
#
programming
#
tutorial
#
leetcode
Solution Developed In:
JavaScript

The Question
For this article we will be covering Leetcode's '103. Binary Tree Zigzag Level Order Traversal' question.

Question:

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate > between).

Example:

Example
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
Explaining The Question
This Question is rated Medium. Which I believe is accurate. In many ways this question is the successor to '102. Binary Tree Level Order Traversal'. If you are familiar with the question, you will be able to understand this question.

What we're being asked to do is the same as 102. Binary Tree Level Order Traversal. Although with a twist, we need to do it in a zigzag fashion. Meaning we need to alternate between left and right. Normally we would just go left -> right. As if we was reading a book. Although in this questions we need to go left -> right and then right -> left. A literal zig zag.

Now this may seem difficult because we're going to have to create a unusual traversal but it's actually not that difficult. We both know that level order traversal requires a queue to store the row nodes. All we need to do is to alternate the queue between being a queue and a stack.

So whenever we add to the row of the we also ask? Do i add this value to the start or the end of the array? That's it. 😁

Recommended Knowledge
Binary Tree
Depth First Search
Level order traversal
102. Binary Tree Level Order Traversal (Able to do this with ease)
Stack
What do we know?
We have a binary tree (Most times, it could be empty)
We need to store all the rows within the Binary Tree within a array that will represent the level order traversal
We need to perform level order traversal on the Binary Tree but in a zigzag fashion.
How we're going to do it:
We're going to be implementing a similar solution to the 102. Binary Tree Level Order Traversal question. Which is to use a queue to store the row nodes. Ensuring we have always cleared all the nodes in the queue moving onto the next row.

The key difference here is we have a flag set called zigzag to alternate between true and false values. True indicates we need to go right -> left and false indicates we need to go left -> right. We do this using the unshift and push methods.

Whenever we need to add a node to the row we ask? Do i add this value to the start or the end of the array?. So if the zigzag flag is true we add the node to the start of the array using the unshift operation like we would if this was a queue. If the zigzag flag is false we add the node to the end of the array as if it was a stack.

So what we achieve in the end isn't zigzag traversal but something that mimics it. Technically speaking, we are traversing the Binary Tree in a level order fashion. But the way we add the nodes to the row is in a zigzag fashion.

Big O Notation:
Time Complexity: O(n) | Where n is the number of nodes in our Binary Tree | As we're going to traverse all of the nodes within the tree.

Space Complexity: O(n) | Where n is the number of nodes in our Binary Tree | As we're going to add all of our nodes to a level_order array.

Leetcode Results:
See Submission Link:

Runtime: 69 ms, faster than 76.64% of JavaScript online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 43.5 MB, less than 95.97% of JavaScript online submissions for Binary Tree Zigzag Level Order Traversal.
LeetCode

The Solution
var zigzagLevelOrder = function (root) {

    // What we do here is perform the normal
    // level order traversal in rows.
    // But we instead use a stack / queue depending
    // on if we're to zig zag or not.

    // Base case, we have no root.
    if (!root) {
        return [];
    }

    // So we're going to need a queue for the level order traversal.
    // We're also going to need a level_order array to store all the rows 
    // of the binary tree
    // as well as a flag to invert the order of the rows or not
    // (zig zag). Meaning, if we're going to zig zag, we'll get the first node in the queue
    // if we're not zig zag, we'll get the last node in the queue. (Unshift / pop)
    let queue       = [root];
    let level_order = [];
    let zigzag      = true;

    // So we perform a normal iterative level order traversal.
    while (queue.length) {

        // This will be our row, it will store all the nodes for the row in the tree
        let row       = [];
        let queue_len = queue.length;

        // So we're always going to invert the order of the rows.
        // We do this to create our zig zag effect.
        // Back, forward, back, forward, etc.
        zigzag = !zigzag;

        // We're going to get everything in the queue.
        // at this particular moment and nothing more.
        for (let counter = 0; counter < queue_len; counter++) {

            // Grab the current node by removing it off the end of the queue
            let node = queue.pop();

            // So, if the invert flag is set, we're going to push the current node
            // to the START of the row. Which means, we will produce a zig zag effect.
            // Without having to change the order in which we visit our nodes.
            // If the invert flag is not set, we're going to push the current node
            // to the end of the row stack like we normally would in level order traversal.
            if (zigzag) {
                row.unshift(node.val);
            } else {
                row.push(node.val);
            }

            // Add to the queue. 
            node.left  ? queue.unshift(node.left) : null;
            node.right ? queue.unshift(node.right): null;
        }

        // Push to the level_order array.
        level_order.push(row);
    }

    // Return the level_order array.
    return level_order;
};

Top comments (0)

Subscribe
pic
Add to the discussion
Code of Conduct • Report abuse
🌚 Friends don't let friends browse without dark mode.
Sorry, it's true.

Read next
rakeshkr2 profile image
In One Minute : log4j2
Rakesh KR - Oct 7

omerr profile image
Git Internals: Rewriting History and Overcoming Gitsasters
Omer Rosenbaum - Oct 11

vcctm profile image
What is a closure? And why this matters ? - Javascript
Victor Miranda - Oct 11

shahednasser profile image
Medusa 1.5.0: PriceList Import, Medusa Hackathon, and more!
Shahed Nasser - Oct 11


Samuel Hinchliffe 🚀
Follow
418 I'm a teapot
LOCATION
United Kingdom
WORK
Software Engineer
JOINED
Apr 24, 2022
More from Samuel Hinchliffe 🚀
287. Find the Duplicate Number 🚀
#javascript #leetcode #tutorial #beginners
76. Minimum Window Substring 🚀
#javascript #tutorial #leetcode #programming
55. Jump Game 🚀
#java #cpp #python #leetcode
var zigzagLevelOrder = function (root) {

    // What we do here is perform the normal
    // level order traversal in rows.
    // But we instead use a stack / queue depending
    // on if we're to zig zag or not.

    // Base case, we have no root.
    if (!root) {
        return [];
    }

    // So we're going to need a queue for the level order traversal.
    // We're also going to need a level_order array to store all the rows 
    // of the binary tree
    // as well as a flag to invert the order of the rows or not
    // (zig zag). Meaning, if we're going to zig zag, we'll get the first node in the queue
    // if we're not zig zag, we'll get the last node in the queue. (Unshift / pop)
    let queue       = [root];
    let level_order = [];
    let zigzag      = true;

    // So we perform a normal iterative level order traversal.
    while (queue.length) {

        // This will be our row, it will store all the nodes for the row in the tree
        let row       = [];
        let queue_len = queue.length;

        // So we're always going to invert the order of the rows.
        // We do this to create our zig zag effect.
        // Back, forward, back, forward, etc.
        zigzag = !zigzag;

        // We're going to get everything in the queue.
        // at this particular moment and nothing more.
        for (let counter = 0; counter < queue_len; counter++) {

            // Grab the current node by removing it off the end of the queue
            let node = queue.pop();

            // So, if the invert flag is set, we're going to push the current node
            // to the START of the row. Which means, we will produce a zig zag effect.
            // Without having to change the order in which we visit our nodes.
            // If the invert flag is not set, we're going to push the current node
            // to the end of the row stack like we normally would in level order traversal.
            if (zigzag) {
                row.unshift(node.val);
            } else {
                row.push(node.val);
            }

            // Add to the queue. 
            node.left  ? queue.unshift(node.left) : null;
            node.right ? queue.unshift(node.right): null;
        }

        // Push to the level_order array.
        level_order.push(row);
    }

    // Return the level_order array.
    return level_order;
};
