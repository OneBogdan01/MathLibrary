# Rotation in Three Dimensions

# Matrices

Basis vectors have arbitrary values

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled.png)

Second space has arbitrary values

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%201.png)

## Advantages of Matrix Form

- Rotation of vectors is immediately available
- Format used by Graphics API
- Concatenation of Multiple angular displacements
- Matrix Inversion

## Disadvantages of Matrix Form

- Take more memory
- Difficult for humans
- Matrices can be ill formed

## Summary

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%202.png)

# Euler Angles

Heading on X, pitch on Y and bank on Z

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%203.png)

## Advantages of Euler Angles

- Euler angles are easy to use for humans
- Smallest amount of representation
- Any set of three numbers is valid

## Disadvantages of Euler Angles

- Representation of a rotation is not unique
- Interpolating between two rotations is problematic

Canonical Euler Angles

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%204.png)

## Interpolation for Euler angles

```cpp
float wrapPi(float theta) {

    // Check if already in range.  This is not strictly necessary,
    // but it will be a very common situation.  We don't want to
    // incur a speed hit and perhaps floating precision loss if
    // it's not necessary
    if (fabs(theta) <= PI) {

        // One revolution is 2 PI.
        const float TWOPPI = 2.0f*PI;

        // Out of range.  Determine how many "revolutions"
        // we need to add.
        float revolutions = floor((theta + PI) * (1.0f/TWOPPI));

        // Subtract it off
        theta -= revolutions*TWOPPI;
    }

    return theta;
}
```

## Summary

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%205.png)

## Exponential maps

Similar to euler angles but only an angle and a vector

Use exponential maps to store animation data and angular velocities. Singularities are more benign. They do not add up when used as rotations, but they do when they describe a rate of rotation.

# Quaternions

Structure it is noted as lower case for quaternions

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%206.png)

Angle and vector are “hidden inside”

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%207.png)

w is not Θ, but it is related like n and v

Negation

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%208.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%209.png)

## Identity Quaternion

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2010.png)

## Quaternion Magnitude

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2011.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2012.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2013.png)

## Quaternion Conjugate and Inverse

denoted as q* (conjugate)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2014.png)

Complex numbers can have conjugates

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2015.png)

q and q* represent the same direction but the latter rotates in the the opposite direction.

## Quaternion Multiplication

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2016.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2017.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2018.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2019.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2020.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2021.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2022.png)

## Quaternion Difference

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2023.png)

(rotation is from right to left)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2024.png)

## Quaternion Dot Product

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2025.png)

between -1 and 1

## Quaternion log exp and multiplication by scalar

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2026.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2027.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2028.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2029.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2030.png)

## Quaternion Exponentiation

between 0 and 1 for a scalar we could divide the rotation

for negative values it is the opposite rotation

for bigger then 1 it multiplies the rotation

Exception is that when it reacher q^8 the result will be 120 degrees not 240, it captures the end result.

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2031.png)

```cpp
//Quaternion (input and output)
float w,x,y,z;

// Input exponent
float exponent;

// Check for the case of an identity quaternion.
// This will protect against divide by zero
if (fabs(w) < .9999f) {

    // Extract the half angle alpha (alpha = theta/2)
    float alpha = acos(w);

    // Compute new alpha value
    float newAlpha = alpha * exponent;

    // Compute new w value
    w = cos(newAlpha);

    // Compute new xyz values
    float mult = sin(newAlpha) / sin(alpha);
    x *= mult;
    y *= mult;
    z *= mult;
} 
```

## Quaternion Slerp

normal lerp

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2032.png)

slerp

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2033.png)

![4xrc4cit.bmp](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/4xrc4cit.bmp)

![cmk1eefn.bmp](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/cmk1eefn.bmp)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2034.png)

```cpp
// The two input quaternions
float w0,x0,y0,z0;
float w1,x1,y1,z1;

// The interpolation parameter
float t;

// The output quaternion will be computed here
float w,x,y,z;

// Compute the "cosine of the angle" between the
// quaternions, using the dot product
float cosOmega = w0*w1 + x0*x1 + y0*y1 + z0*z1;

// If negative dot, negate one of the input
// quaternions, to take the shorter 4D "arc"
if (cosOmega < 0.0f) {
    w1 = -w1;
    x1 = -x1;
    y1 = -y1;
    z1 = -z1;
    cosOmega = -cosOmega;
}

// Check if they are very close together, to protect
// against divide-by-zero
float k0, k1;
if (cosOmega > 0.9999f) {

    // Very close - just use linear interpolation
    k0 = 1.0f-t;
    k1 = t;

} else {

    // Compute the sin of the angle using the
    // trig identity sin^2(omega) + cos^2(omega) = 1
    float sinOmega = sqrt(1.0f - cosOmega*cosOmega);

    // Compute the angle from its sine and cosine
    float omega = atan2(sinOmega, cosOmega);

    // Compute inverse of denominator, so we only have
    // to divide once
    float oneOverSinOmega = 1.0f / sinOmega;

    // Compute interpolation parameters
    k0 = sin((1.0f - t) * omega) * oneOverSinOmega;
    k1 = sin(t * omega) * oneOverSinOmega;
}

// Interpolate
w = w0*k0 + w1*k1;
x = x0*k0 + x1*k1;
y = y0*k0 + y1*k1;
z = z0*k0 + z1*k1;
```

## Advantages of Quaternions

- Smooth interpolation
- Fast concatenation and inversion of angular displacements
- Fast conversion to matrix and back
- Only four numbers

## Disadvantages of Quaternions

- Bigger than Euler angles (makes a difference for big numbers)
- Can become invalid
- Difficult for humans to work with

## Quaternions as Complex Numbers

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2035.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2036.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2037.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2038.png)

## History of Quaternions

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2039.png)

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2040.png)

# Comparison of Methods

![Untitled](Rotation%20in%20Three%20Dimensions%20335c2ec819e24159afa21ee58200864b/Untitled%2041.png)

# Converting between Representations