Grep with Marketing
===================

Sometimes the reason you don't write unit tests is because it's really difficult to isolate a testable unit. 
You can use this code to practice some relevant techniques for that situation.

4 steps

0. initial state - main
1. get patient into surgery, everything compiles - with_surgery
2. ready to start writing unit tests - stubs provided for convenience - with_stubs_no_tests
2. write unit tests and stubs for patient - with_coverage
3. refactor to have abstractions so we can insert stubs without needing surgery - with_abstractions
4. put the patient back into teh real build and test via abstractions - sample_solution


The overall idea is you'd like to test the `grep` function defined in `main.c`. 
Instructions for one way to do this that demonstrates some useful techniques:

1. Isolate the unit under test by moving it into the 'surgery'. The original code should still compile between each step.
    - [x] Make sure you can compile and run both main.c in the main project and unit_test.cpp in the surgery, and know how to switch between them.
    - [x] Copy the 'grep' function into 'patient.c' in the surgery.
    - [x] Replace the original function with #include surgery/patient.c
    - [x] Run the original compilation - it should still be successful
    
2. Get the unit tests in the surgery to compile when they include the patient.
    - [x] Add relevant standard library includes in the h file in the surgery.
    - [x] Add function prototypes in `stubs.h` for any other functions that the unit under test uses.
    - [x] Double check the original code compiles and runs exactly as before.  

3. Make the code in the surgery also link by writing stubs
    - [x] in 'stubs.c' write simple implementations of all the prototypes listed in 'stubs.h'
   
4. Write unit tests
    - [x] Write a unit test in the surgery that calls the 'grep' function. 
    - [x] Write more unit tests to cover relevant code branches
   
5. Refactor the unit to be more testable
6. Re-insert the unit into the main code and integrate the tests so they are run as part of the normal build.
