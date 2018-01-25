# C Programming Assignment 2 (IN PROGRESS)

_red-black trees in C_

* * * 

_note: cmocka has to be built separately and dynamically linked to the project_

_note: the CMakeLists.txt has a hardcoded library name and location assuming an Ubuntu installation_

* * *

## Goals

1. Practice development in the C programming language.
2. Imiplement a self-balancing red-black tree with O(n) space requirement and O(log n) search, instert, and delete operations.
3. Learn to program against an API requirement.
4. Learn to work with a test suite.
5. Prepare for [C3](https://github.com/ivogeorg/msl-clang-003).
6. Develop good coding style.

## Synopsis

This assignment is a continuation of [C PA 1](https://github.com/ivogeorg/msl-clang-001), and adds the extra requirement for _logarithmic_ search, insert, and delete operations. While a simple binary tree can perform these operations in _O(n)_ time, a _red-black tree_ can perform them in _O(log n)_. The RB tree is a self-balancing tree and is guaranteed to be approximately balanced such that _no simple path between a root and a leaf is more than twice as long as any other_. As in the previous assignment, you need to read in a file with English words and output a file where the words are counted and sorted. In this assignment, the files will contain 1000s of words, so an unbalanced tree will be unfeasible.

## Submission

You need to fork this repository and `git clone` it to your development environment. When you are done and your code works, `git commit` all your changes and `git push` to your forked (aka **remote**) repository. Work in the **master** branch. This assignment will have a test suite, for which you will need an installation of the [cmocka](https://cmocka.org/) testing framework for C. Your will need to pass the tests in the test suite.

### Github
Submissions are **one** per team. Submit with your team account. _**Reminder:** The team account name should look like **ucd-[course]-[team-color]-s18**. For example, **ucd-os-orange-s18**._ 

### Canvas
Both team members have to make an assignment submission on [Canvas](https://canvas.instructure.com/courses/1270192) before the deadline. You only need to enter the _clone URL_ of your project repository (e.g. https://github.com/ivogeorg/msl-clang-002.git).

## Grading

Each team mate gets the number of points the team submission scored.

### Points
Maximum: 100

### Details
The fraction of tests you pass will be multiplied by the maximum number.

### Bonus
Maximum: 100 additional points, to be applied to your overall score before final grade calculation

Order the tree according to the dynamic count of words in the file rather than in alphabetical order. Print the words in descending order of incidence. _Warning: This might take a long time._

## Due date

The assignment is due on **Thu, Feb 1, at 23:59 Mountain time**. The last commit to your repository before the deadline will be evaluated.

## Honor code

Free Github repositories are public so you can look at each other's code. Please, don't do that. You can discuss any programming topics and the assignments in general but sharing of solutions diminishes the individual learning experience of many people. Assignments might be randomly checked for plagiarism and a plagiarism claim may be raised against you. You definitely don't want that.

**Note:** There are many implementations of red-black trees _online_. (See [Resources](#resources).) Do not copy-paste. You can look at other implementations, but you have to _type your own code_. The first quiz _after_ the assignment will contain questions on red-black trees, so you need to understand them.

## Resources

1. RB trees [explained](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree) on Wikipedia.
2. RB trees [implemented](http://adtinfo.org/libavl.html/Red_002dBlack-Trees.html) in Ben Pfaff's [GNU libavl](http://adtinfo.org/index.html). _Note: Ben Pfaff is the author of [Pintos](http://pintos-os.org/)._
3. RB trees [visualized](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html) at University of San Francisco's [Data Structure Visualizations](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html). 

## Use of libraries

For this assignment, no external libraries should be used, except for the ANSI C Standard Library. The implementation of the data structures should be your own. We will use library implementations of data structures and programming primitives in the Pintos assignments.

## Coding style

Familiarize yourself with and start the following [coding style guide](http://courses.cms.caltech.edu/cs11/material/c/mike/misc/c_style_guide.html). While you are not expected to follow every point of it, you should try to follow it enought to get a feel for what is good style and bad style. C code can quickly become [unreadable](http://www.ioccc.org/) and difficult to maintain.

## References

The [C Reference](http://en.cppreference.com/w/c), which you should get confortable consulting.

The [ISO C Standards](http://www.iso-9899.info/wiki/The_Standard) defines the language. A freely available draft [C11 Standard](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf), if you want to dig deep.

This [C98 Library Reference](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/) seems to be the standard reference. You should not expect many changes, though it's always good to work off a latest copy of your library reference, which should be available through the vendor/implementor.

Two guides for implementation of `malloc()`: [here](http://danluu.com/malloc-tutorial/) and [here](http://www.inf.udec.cl/~leo/Malloc_tutorial.pdf).

## Detailed Instructions

### Input

The input will be a file containing English words, one word per line. **The words are not guaranteed to be lower-case for this assignment, but your counts need to be case-INsensitive.** You need to read it in to sort them. The test file(s) will be in the same directory as your executable and will appear as the first argument when your program is run.

### Output

For each input file `input01.txt`, generate an output file in the same directory, called `myoutput01.txt`. **No ground-truth file will be provided for this assignment.** The output should be an alphabetized list of unique lower-case words and their counts in the file, as follows:

```
one: 4
three: 5
years: 23
```

### Data structures

You should use a **red-black** binary tree to keep the running count for words and keep them in alphabetical order. This means that if you have four words, say *one, two, three, go, one*, that come in this order, you will end up with a tree that looks like:

```
    one(2)
  /     \
 go(1)  two(1)
        /
     three(1)
```

Think what traversal you need to print the words in the tree in alphabetical order.

#### Red-black trees

The tree has to be a *self-referential* C `struct`, containing a dynamically allocated `word`, its integer `count`, and pointers to the `left` and `right` subtrees. In other words, a tree is equivalent to a single node of the tree.

### Functionality

For this assignment, you will have an API in a header file that you need to implement against. The test suite will use this API to test your implementation.

#### Overview 
1. Read words from the file. Don't read in the whole file and then process it. Read it in chunks using a buffer.
2. Tree lookup for the next word in the input. 
3. If a word is in the tree, increment the count; if it isn't, dynamically allocate a new node; position and link it properly, and initialize the count to 1. _**Note:** The red-black properties need to hold between operations!_
4. When you are done with the input, you should have a complete approximately-balanced tree. Use it to print out the output file.
5. Destroy the tree, making sure you `free()` dynamic structures in the proper order.
6. Your tree functions should be *recursive*.

#### Functions

1. `RBInsert`
2. `RBDelete`
3. `RBFind`

### README

Overwrite the **README.md** file and describe your project (approach, data structures, algorithms, etc.). Use this opportunity to get to know [*markdown*](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet). It's a useful skill.

