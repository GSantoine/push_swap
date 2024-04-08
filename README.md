# Push_swap - a number sorting program in C

## 6th project in my 42 cursus
The whole point of this project is efficiency and optimization. We must create a program that takes a set of int values as input and use only 2 stacks and a limited set of instructions to manipulate the stacks. The ouput is the exact suite of instructions needed to sort the input values. The goal is not to have the quickest sorting time, but the fewest instructions needed to do so. This greatly affects the approach we are going to take.
I chose to go with the radix sorting algorithm for its simplicity eventhough there are more efficient algorithms possible.
Notions explored : sorting algorithms, stack data structures, list data structures (for the easy implementation of stacks in C), dynamic memory allocation.

---

| Project Name | push_swap |
| :-: | :-: |
| Technos | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| Utilities used | read(), write(), malloc(), free(), exit() |

## Usage
```
git clone https://github.com/GSantoine/push_swap.git
cd push_swap
make
./push_swap "1 3 2"
```
