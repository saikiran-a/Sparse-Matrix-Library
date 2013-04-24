Sparse-Matrix-Library
======================
Sparse matrices are indispensable components of most scientiﬁc applications. The systems can grow very large in dimension — millions
and even billions of unknowns are not rare — but the number of terms per equation is limited. That is the matrices used in these linear 
systems are sparse. Despite the importance of sparse matrices in a large variety of applications the software support in a general-purpose
manner is insuﬃcient.

This Project is implemented to store these type of matrices.

Here input is taken in 2 different ways...

1 - Entire matrix.
      eg: for a 5 * 5 unit matrix the imput will be....

                  1 0 0 0 0
                  0 1 0 0 0
                  0 0 1 0 0
                  0 0 0 1 0
                  0 0 0 0 1

2 - Triplet.
      eg: for a 5 * 5 unit matrix the input will be as a set of triplets...

                  0 0 1
                  1 1 1
                  2 2 1
                  3 3 1
                  4 4 1

      i.e., row number, column number and a value at that position.


Hence the Data structure stores only non-zero values present in the matrix.


project consists of 5 files...

      1 - matrix.h -> contains the structure and the functions for the user.
      2 - client.c -> example client interface
      3 - implementation.cpp -> impementaion of the above functions.
      4 - matrix.txt -> input type 1
      5 - triplet -> input type 2




How to run the project:

in linux:

      gcc client.c implementation.c -o output


      ./output
