# Garbage Collector - README

## Overview
This project provides a simple garbage collection system in C using a linked list to manage dynamically allocated memory. The system ensures that all allocated memory is tracked and freed, preventing memory leaks. Additionally, a cleanup function (`main_cleanup`) is provided to free all memory and reset the garbage collector when the program terminates.

## Features
- **Linked List-Based Garbage Collection:**
  Memory blocks are tracked in a linked list, enabling efficient memory management.

- **Automatic Memory Management:**
  Custom memory allocation function (`ft_malloc`) automatically registers memory blocks with the garbage collector.

- **Batch Memory Deallocation:**
  All memory blocks tracked by the garbage collector are freed at once using `gc_free_all()`.

- **Program Cleanup:**
  The `main_cleanup()` function frees all allocated memory, resets the garbage collector, and exits the program.

## Files
- **gb_garbage_collector.c**: Implements the core garbage collection system, including adding memory blocks to the collection list, creating nodes, and freeing all memory.
- **gb_utils.c**: Provides utility functions for memory allocation, linked list operations, and printing the state of the garbage collector.
- **main_cleanup()**: A cleanup function that frees all memory, resets the garbage collector, and terminates the program.

## Usage

### Garbage Collector Operations

1. **Initialize Garbage Collector**
   Sets up an empty garbage collector to track dynamically allocated memory.

   ```c
   t_garbage_collector *gc_init_garbage_collector(void);
