#pragma once
#include <iostream>
#include <vector>
#include <string>

void double_data(int* int_ptr);
void swap_12(int* a, int* b);
void display(const std::vector<std::string>* const v);
void display(const int* array, const int sentinel);
int* largest_int(int* int_ptr1, int* int_ptr2);
int* create_array(size_t size, int init_value);
int square(int& n);
void print_array_12(const int* array, const size_t size);
int* apply_all(const int* array1, const size_t size1, const int* array2, const size_t size2);