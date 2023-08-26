# More on matrices

# Determinant

![oyd354bm.bmp](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/oyd354bm.bmp)

![dnp7d4gx.bmp](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/dnp7d4gx.bmp)

# Minors and cofactors

take a row and a column from a matrix and you get the minor.

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%201.png)

# Determinants for n x n

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%202.png)

Properties

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%203.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%204.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%205.png)

# Inverse of a Matrix

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%206.png)

if it has an inverse it is called *invertible* or *nonsingular, else noninvertible* or *singular*

the rows and columns of an inverse matrix is linearly independent.

# **The Classical Adjoint (to compute matrix inverse)**

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%207.png)

# Matrix Inverse

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%208.png)

properties:

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%209.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2010.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2011.png)

# Orthogonal Matrices

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2012.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2013.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2014.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2015.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2016.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2017.png)

# Orthogonalizing a matrix

make the rows perpendicular. This is biased to r1

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2018.png)

Trick for 3D (does not work in higher dimensions)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2019.png)

This is not biased:

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2020.png)

# 4D Homogeneous matrices

last row is the w, homogeneous coordinate

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2021.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2022.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2023.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2024.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2025.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2026.png)

why can’t drop the last column in stric algebra linear things

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2027.png)

In code you can drop to 4x3, assume the last column to be 0, 0 ,0, 1

# General Affine Transformations:

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2028.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2029.png)

T= Translation matrix

R=Linear Transformation Matrix

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2030.png)

# 4 x 4 Matrices and Perspective Projection

![x81dtsxd.bmp](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/x81dtsxd.bmp)

![9c36akmd.bmp](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/9c36akmd.bmp)

![c1mzf46b.bmp](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/c1mzf46b.bmp)

d = distance from the pinhole to the projection place

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2031.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2032.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2033.png)

![2q6jo0rm.bmp](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/2q6jo0rm.bmp)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2034.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2035.png)

4D will look like

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2036.png)

![Untitled](More%20on%20matrices%20e7f31fa603c441e4b623f11c60cc923b/Untitled%2037.png)