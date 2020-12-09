Grep with Marketing
===================

Sometimes the reason you don't write unit tests is because it's really difficult to isolate a testable unit. 
You can use this code to practice some relevant techniques for that situation.

The overall idea is you'd like to test the `grep` function defined in `main.c`. 
Instructions for one way to do this that demonstrates some useful techniques:

1. Isolate the unit under test by moving it into the 'surgery'. The original code should still compile, 
   and the code in the surgery should soon compile but not link.
    - [ ] Make sure you can compile and run both main.c in the main project and main.cpp in the surgery, and know how to switch between them.
    - [ ] Create a h and c file pair in the surgery with the same name as the function you want to isolate and test, copy the function into the c file.
    - [ ] Add the c file to the CMakeLists in the surgery.
    - [ ] Compile and run both main and surgery - everything should still work.
    - [ ] Replace the original function with a #include pointing at the c file in the surgery
    - [ ] Run the original compilation - it should still be successful
    - [ ] Add an include to `main.cpp` for the new c file
    - [ ] Run the surgery compilation - it should fail. Fix all the compiler errors but stop when you get linker errors. 
            Hint: In the c file, add a #include for the h file, hidden using an #ifdef SURGERY 
          - [ ] Add relevant standard library includes in the h file in the surgery.
          - [ ] Add function prototypes in `stubs.h` for any other functions that the unit under test uses.
    - [ ] Double check the original code compiles and runs exactly as before.  

2. Make the code in the surgery also link by generating [exploding fakes](https://github.com/jwgrenning/gen-xfakes)
    - [ ] Copy your linker error messages into a file, for example `linker-errors.txt`
    - [ ] Use the gen-xfakes.sh script to generate exploding fakes.
    - [ ] Put the exploding fakes in the `x-stubs-cpp.cpp` file so they will be included in the build.
    - [ ] Compile and link the code in the surgery, it should succeed.
   
3. Write a first unit test.
    - [ ] Add a call to the function under test in `main.cpp`. Run it and find the first explosion.
    - [ ] Replace exploding stubs with read stubs one by one
   
4. Write more unit tests
5. Refactor the unit to be more testable
6. Re-insert the unit into the main code and integrate the tests so they are run as part of the normal build.
