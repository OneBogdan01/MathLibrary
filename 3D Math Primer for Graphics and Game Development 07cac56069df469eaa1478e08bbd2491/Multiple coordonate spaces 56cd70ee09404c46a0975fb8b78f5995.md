# Multiple coordonate spaces

<aside>
💡 Mainly we need those to express relative objects from different coordonate spaces. Local to global and global to local

</aside>

![object_inertial_world_translate_rotate.png](Multiple%20coordonate%20spaces%2056cd70ee09404c46a0975fb8b78f5995/object_inertial_world_translate_rotate.png)

<aside>
💡 The concept of converting from one coord. space to another is called coordinate space transformation.

</aside>

<aside>
💡 The active and passive transformation creates a lot of confusion. The first id about making the world fix, and move the things around, the second moves the world to the objects.

</aside>

<aside>
💡 Conversion from local space to world space:

</aside>

$$
w=O+bx*p+by*q
,pq:basis
$$

<aside>
💡 A good basis is orthonormal. If not it could be dependent linearly can't represent all the dimensions, the dot product needs to be divided unless they are of unit length. They are linearly independent.

</aside>

$$
p(x)q=r
$$

that is the cross product.

<aside>
💡 Hierarchies of objects make the motions easier to understand, matrices and vectors are needed to represent this in world space. Nested space coordinates…

</aside>

<aside>
💡 Be careful about the difference between representing points and vectors, the latter should not be translated or used to convert from local space to world space.

</aside>

This is how to get object space if the basis are orthonormal and u being upright space.

![Screenshot_20230425_113822_Firefox.jpg](Multiple%20coordonate%20spaces%2056cd70ee09404c46a0975fb8b78f5995/Screenshot_20230425_113822_Firefox.jpg)