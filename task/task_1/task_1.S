.section .data   // section with initialized variables 
  buffer:
   .fill 256, 1, 0
  

.section .text
  .global _start

  _start:
    ldr x0, =buffer     // store the buffer start 
    mov x1, #256     // load len of buffer
    
    mov x8, #17   // write system call getcwd number 
    svc #0        // perform getcwd call and store in buffer

    mov x0, #1     // file descriptor for standard output is 1
    ldr x1, =buffer  // load address of the variable with data to x1
    mov x2, #256    // bytes count to write
    mov x8, #64   // write system call number is 64
    svc #0        // perform a system call

    mov x0, #1    // return status 0
    mov x8, #93   // exit system call is 93
    svc #0        // perform a system call