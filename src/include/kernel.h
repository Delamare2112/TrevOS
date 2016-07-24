#pragma once

#if defined(__linux__)
#error "Why you no cross-compile?! You want to hurt?!"
#endif

#if !defined(__i386__)
#error "you might want to try a i386-elf compiler"
#endif

#include <stdbool.h> // booleve it or not C doesn't have bools by deafult!
#include <stddef.h>
#include <stdint.h>

#include "config.h"
#include "Terminal.h"
// #include "Memory.h"
// #include "InterruptHandler.h"
// #include "GDT.h"

void Panic();

extern "C"
void StartKernel();
