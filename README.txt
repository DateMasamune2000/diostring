                                                               
 mmmm   mmmmm   mmmm   mmmm mmmmmmm mmmmm  mmmmm  mm   m   mmm 
 #   "m   #    m"  "m #"   "   #    #   "#   #    #"m  # m"   "
 #    #   #    #    # "#mmm    #    #mmmm"   #    # #m # #   mm
 #    #   #    #    #     "#   #    #   "m   #    #  # # #    #
 #mmm"  mm#mm   #mm#  "mmm#"   #    #    " mm#mm  #   ##  "mmm"
                                                               
==================================================================

Diostring was born out of my dissatisfaction with the way strings are handled
in the C standard library. Its approach to strings is to store the string
length and buffer size with the buffer itself. This is mostly to eliminate
string length calculations wherever possible, and hopefully make efficient
string manipulation easier in C.

Key features include:
* No built-in bounds checking: buffer sizes are expected to be checked by
users, but helper routines are planned. All functions do exactly as they say
on the tin
* Portability: String routines are not tied to the C standard library, and
tasks like allocation and de-allocation are the responsibility of a programmer.
The hope is that this can allow it to be used with custom allocators.

In the interest of modularity, a lot of functionality has intentionally been
excluded from the library. There are however a few features that have been
planned for the library:

- Inline functions and macros that can be used for bounds checking
