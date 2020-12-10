Grep with Marketing
===================

Sometimes the reason you don't write unit tests is because it's really difficult to isolate a testable unit. 
You can use this code to practice some relevant techniques for that situation.

The overall idea is you'd like to test the `grep` function defined in `main.c`. 
Instructions for one way to do this that demonstrates some useful techniques:

1. Isolate the unit under test by moving it into the 'surgery'. The original code should still compile between each step.
    - [x] Make sure you can compile and run both main.c in the main project and main.cpp in the surgery, and know how to switch between them.
    - [x] Copy the 'grep' function into the surgery. Hint - create a new c and h file, copy the code into the c file.
    - [x] Replace the original function with a #include of the relevant file in the surgery
    - [x] Run the original compilation - it should still be successful
    
2. Get the 'grep' function to compile in its new home. Note you are done with this when you get linker errors. 
    - [x] Modify the unit test in the surgery to #include the grep.c file. Note - do not add it to CMakelists
    - [x] In the c file, add a #include for the h file, hidden using an #ifdef SURGERY
    - [x] Double check the original code compiles and runs exactly as before.
    - [x] Add relevant standard library includes in the h file in the surgery.
    - [x] Add function prototypes in `stubs.h` for any other functions that the unit under test uses.
    - [x] Double check the original code compiles and runs exactly as before.  

3. Make the code in the surgery also link by writing stubs
     - [ ] in 'stubs.c' write simple implementations of all the prototypes listed in 'stubs.c'
   
4. Write unit tests
    - [ ] Write a unit test in the surgery that calls the 'grep' function. 
    - [ ] Write more unit tests to cover relevant code branches
   
5. Refactor the unit to be more testable
6. Re-insert the unit into the main code and integrate the tests so they are run as part of the normal build.
