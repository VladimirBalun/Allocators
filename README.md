# Allocators

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/5a1b7ace732d409ea84d34316e721935)](https://www.codacy.com/manual/VladimirBalun/Allocators?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=VladimirBalun/Allocators&amp;utm_campaign=Badge_Grade)
[![Build status](https://ci.appveyor.com/api/projects/status/ovh0o2eioj04f610?svg=true)](https://ci.appveyor.com/project/VladimirBalun/allocators)

When applications need more memory this can be allocated in the heap (rather than in the stack) in runtime. 
This memory is called 'dynamic memory' because it can't be known at compile time and its need changes 
during the execution. Our programs can ask for dynamic memory using 'malloc'. Malloc returns an address to 
a position in memory where we can store our data. Once we're done with that data, we can call 'free' to 
free the memory and let others processes use it.

For this project I've implemented different ways to manage by ourselves dynamic memory in C++.This means 
that instead of using native calls like 'malloc' or 'free' we're going to use a custom memory allocator
that will do this for us but in a more efficient way.

## How to build project

You can build a project manually using the following commands:

    mkdir build
    cd build
    cmake ..
    