#ifndef MODELS_H
#define MODELS_H

#include "main.h"

GLfloat KartVerts [155][3] = {
	{0.149409, 0.149409, -0.289131},
	{0.000000, 0.211296, -0.289131},
	{-0.149409, 0.149409, -0.289131},
	{-0.211296, -0.000000, -0.289131},
	{-0.149409, -0.149409, -0.289131},
	{0.000000, -0.211296, -0.289131},
	{0.149409, -0.149409, -0.289131},
	{0.211296, -0.000000, -0.289131},
	{0.149409, 0.149409, 0.289131},
	{0.000000, 0.211296, 0.289131},
	{-0.149409, 0.149409, 0.289131},
	{-0.211296, 0.000000, 0.289131},
	{-0.149409, -0.149409, 0.289131},
	{0.000000, -0.211296, 0.289131},
	{0.149409, -0.149409, 0.289131},
	{0.211296, 0.000000, 0.289131},
	{0.000000, -0.000000, -0.289131},
	{0.000000, 0.000000, 0.289131},
	{0.129482, -0.137734, -0.293856},
	{-0.002784, -0.192520, -0.294142},
	{-0.135050, -0.137734, -0.293856},
	{-0.189837, -0.005469, -0.293167},
	{-0.135050, 0.126795, -0.292479},
	{-0.002784, 0.181581, -0.292193},
	{0.129482, 0.126795, -0.292479},
	{0.184269, -0.005469, -0.293167},
	{-0.002784, -0.002901, -0.786294},
	{0.163565, -0.257140, 0.153262},
	{0.163951, -0.235354, 0.100658},
	{0.164885, -0.182757, 0.078868},
	{0.165818, -0.130161, 0.100658},
	{0.166204, -0.108375, 0.153262},
	{0.165818, -0.130161, 0.205867},
	{0.164885, -0.182757, 0.227657},
	{0.163951, -0.235354, 0.205867},
	{0.238549, -0.258471, 0.153262},
	{0.238936, -0.236684, 0.100658},
	{0.239869, -0.184088, 0.078868},
	{0.240802, -0.131491, 0.100658},
	{0.241189, -0.109705, 0.153262},
	{0.240802, -0.131491, 0.205867},
	{0.239869, -0.184088, 0.227657},
	{0.238936, -0.236684, 0.205867},
	{0.237819, -0.299616, 0.153262},
	{0.238420, -0.265779, 0.071559},
	{0.239869, -0.184088, 0.037716},
	{0.241319, -0.102397, 0.071559},
	{0.241919, -0.068560, 0.153262},
	{0.241319, -0.102397, 0.234966},
	{0.239869, -0.184088, 0.268809},
	{0.238420, -0.265779, 0.234966},
	{0.162834, -0.298286, 0.153262},
	{0.163435, -0.264448, 0.071559},
	{0.164885, -0.182757, 0.037716},
	{0.166334, -0.101066, 0.071559},
	{0.166935, -0.067229, 0.153262},
	{0.166334, -0.101066, 0.234966},
	{0.164885, -0.182757, 0.268809},
	{0.163435, -0.264448, 0.234966},
	{0.163565, -0.257140, -0.162199},
	{0.163951, -0.235354, -0.214804},
	{0.164885, -0.182757, -0.236594},
	{0.165818, -0.130161, -0.214804},
	{0.166204, -0.108375, -0.162199},
	{0.165818, -0.130161, -0.109595},
	{0.164885, -0.182757, -0.087805},
	{0.163951, -0.235354, -0.109595},
	{0.238549, -0.258471, -0.162199},
	{0.238936, -0.236684, -0.214804},
	{0.239869, -0.184088, -0.236594},
	{0.240802, -0.131491, -0.214804},
	{0.241189, -0.109705, -0.162199},
	{0.240802, -0.131491, -0.109595},
	{0.239869, -0.184088, -0.087805},
	{0.238936, -0.236684, -0.109595},
	{0.237819, -0.299616, -0.162199},
	{0.238420, -0.265779, -0.243903},
	{0.239869, -0.184088, -0.277746},
	{0.241319, -0.102397, -0.243903},
	{0.241919, -0.068560, -0.162199},
	{0.241319, -0.102397, -0.080496},
	{0.239869, -0.184088, -0.046653},
	{0.238420, -0.265779, -0.080496},
	{0.162834, -0.298286, -0.162199},
	{0.163435, -0.264448, -0.243903},
	{0.164885, -0.182757, -0.277746},
	{0.166334, -0.101066, -0.243903},
	{0.166935, -0.067229, -0.162199},
	{0.166334, -0.101066, -0.080496},
	{0.164885, -0.182757, -0.046653},
	{0.163435, -0.264448, -0.080496},
	{-0.240292, -0.257140, -0.162199},
	{-0.239905, -0.235354, -0.214804},
	{-0.238972, -0.182757, -0.236594},
	{-0.238038, -0.130161, -0.214804},
	{-0.237652, -0.108375, -0.162199},
	{-0.238038, -0.130161, -0.109595},
	{-0.238972, -0.182757, -0.087805},
	{-0.239905, -0.235354, -0.109595},
	{-0.165307, -0.258471, -0.162199},
	{-0.164920, -0.236684, -0.214804},
	{-0.163987, -0.184088, -0.236594},
	{-0.163054, -0.131491, -0.214804},
	{-0.162667, -0.109705, -0.162199},
	{-0.163054, -0.131491, -0.109595},
	{-0.163987, -0.184088, -0.087805},
	{-0.164920, -0.236684, -0.109595},
	{-0.166037, -0.299616, -0.162199},
	{-0.165437, -0.265779, -0.243903},
	{-0.163987, -0.184088, -0.277746},
	{-0.162537, -0.102397, -0.243903},
	{-0.161937, -0.068560, -0.162199},
	{-0.162537, -0.102397, -0.080496},
	{-0.163987, -0.184088, -0.046653},
	{-0.165437, -0.265779, -0.080496},
	{-0.241022, -0.298286, -0.162199},
	{-0.240421, -0.264448, -0.243903},
	{-0.238972, -0.182757, -0.277746},
	{-0.237522, -0.101066, -0.243903},
	{-0.236922, -0.067229, -0.162199},
	{-0.237522, -0.101066, -0.080496},
	{-0.238972, -0.182757, -0.046653},
	{-0.240421, -0.264448, -0.080496},
	{-0.240292, -0.257140, 0.136654},
	{-0.239905, -0.235354, 0.084050},
	{-0.238972, -0.182757, 0.062260},
	{-0.238038, -0.130161, 0.084050},
	{-0.237652, -0.108375, 0.136654},
	{-0.238038, -0.130161, 0.189259},
	{-0.238972, -0.182757, 0.211049},
	{-0.239905, -0.235354, 0.189259},
	{-0.165307, -0.258471, 0.136654},
	{-0.164920, -0.236684, 0.084050},
	{-0.163987, -0.184088, 0.062260},
	{-0.163054, -0.131491, 0.084050},
	{-0.162667, -0.109705, 0.136654},
	{-0.163054, -0.131491, 0.189259},
	{-0.163987, -0.184088, 0.211049},
	{-0.164920, -0.236684, 0.189259},
	{-0.166037, -0.299616, 0.136654},
	{-0.165437, -0.265779, 0.054950},
	{-0.163987, -0.184088, 0.021108},
	{-0.162537, -0.102397, 0.054950},
	{-0.161937, -0.068560, 0.136654},
	{-0.162537, -0.102397, 0.218358},
	{-0.163987, -0.184088, 0.252201},
	{-0.165437, -0.265779, 0.218358},
	{-0.241022, -0.298286, 0.136654},
	{-0.240421, -0.264448, 0.054950},
	{-0.238972, -0.182757, 0.021108},
	{-0.237522, -0.101066, 0.054950},
	{-0.236922, -0.067229, 0.136654},
	{-0.237522, -0.101066, 0.218358},
	{-0.238972, -0.182757, 0.252201},
	{-0.240421, -0.264448, 0.218358},
};

GLfloat KartNorms [466][3] = {
	{0.382683, 0.923880, 0.000000},
	{0.382683, 0.923880, 0.000000},
	{0.382683, 0.923880, 0.000000},
	{0.382683, 0.923880, 0.000000},
	{-0.382683, 0.923880, 0.000000},
	{-0.382683, 0.923880, 0.000000},
	{-0.382683, 0.923880, 0.000000},
	{-0.382683, 0.923880, 0.000000},
	{-0.923880, 0.382683, 0.000000},
	{-0.923880, 0.382683, 0.000000},
	{-0.923880, 0.382683, 0.000000},
	{-0.923880, 0.382683, 0.000000},
	{-0.923880, -0.382683, 0.000000},
	{-0.923880, -0.382683, 0.000000},
	{-0.923880, -0.382683, 0.000000},
	{-0.923880, -0.382683, 0.000000},
	{-0.382683, -0.923880, 0.000000},
	{-0.382683, -0.923880, 0.000000},
	{-0.382683, -0.923880, 0.000000},
	{-0.382683, -0.923880, 0.000000},
	{0.382683, -0.923880, 0.000000},
	{0.382683, -0.923880, 0.000000},
	{0.382683, -0.923880, 0.000000},
	{0.382683, -0.923880, 0.000000},
	{0.923880, -0.382683, 0.000000},
	{0.923880, -0.382683, 0.000000},
	{0.923880, -0.382683, 0.000000},
	{0.923880, -0.382683, 0.000000},
	{0.923879, 0.382684, 0.000000},
	{0.923879, 0.382684, 0.000000},
	{0.923879, 0.382684, 0.000000},
	{0.923879, 0.382684, 0.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{-0.000000, -0.005208, 0.999986},
	{-0.000000, -0.005209, 0.999986},
	{-0.000000, -0.005209, 0.999986},
	{-0.000000, -0.005209, 0.999986},
	{0.000000, -0.005209, 0.999986},
	{-0.000000, -0.005209, 0.999986},
	{0.000000, -0.005209, 0.999986},
	{0.000000, -0.005208, 0.999986},
	{0.361149, -0.870157, -0.335259},
	{0.361149, -0.870157, -0.335259},
	{0.361149, -0.870157, -0.335259},
	{-0.361149, -0.870157, -0.335259},
	{-0.361149, -0.870157, -0.335259},
	{-0.361149, -0.870157, -0.335259},
	{-0.871891, -0.359422, -0.332598},
	{-0.871891, -0.359422, -0.332598},
	{-0.871891, -0.359422, -0.332598},
	{-0.871891, 0.362867, -0.328836},
	{-0.871891, 0.362867, -0.328836},
	{-0.871891, 0.362867, -0.328836},
	{-0.361149, 0.873602, -0.326176},
	{-0.361149, 0.873602, -0.326176},
	{-0.361149, 0.873602, -0.326176},
	{0.361149, 0.873602, -0.326176},
	{0.361149, 0.873602, -0.326176},
	{0.361149, 0.873602, -0.326176},
	{0.871891, 0.362867, -0.328836},
	{0.871891, 0.362867, -0.328836},
	{0.871891, 0.362867, -0.328836},
	{0.871891, -0.359422, -0.332598},
	{0.871891, -0.359422, -0.332598},
	{0.871891, -0.359422, -0.332598},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382684},
	{-0.006789, -0.382623, -0.923879},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923879},
	{0.006789, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017742, -0.000000},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382684},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006789, -0.382623, 0.923880},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{0.006789, 0.382624, 0.923879},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923879},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382684},
	{-0.016392, -0.923734, -0.382684},
	{-0.016392, -0.923734, -0.382684},
	{-0.006790, -0.382623, -0.923879},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017742, -0.000000},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006789, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923879},
	{0.006789, 0.382623, -0.923879},
	{0.006789, 0.382623, -0.923879},
	{0.006789, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382684},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{0.016392, 0.923734, 0.382684},
	{0.016392, 0.923734, 0.382684},
	{0.016392, 0.923734, 0.382684},
	{0.016392, 0.923734, 0.382684},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{0.006789, 0.382623, 0.923879},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923879},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382684},
	{-0.006790, -0.382623, -0.923879},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{0.006790, 0.382624, -0.923879},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923879},
	{0.006790, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, -0.382684},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382684},
	{-0.016392, -0.923734, -0.382684},
	{-0.016392, -0.923734, -0.382684},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006789, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006789, 0.382623, -0.923879},
	{0.006789, 0.382623, -0.923879},
	{0.006789, 0.382623, -0.923879},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382684},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923880},
	{0.006790, 0.382623, 0.923879},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, 0.382683},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017743, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{0.016392, 0.923734, 0.382684},
	{0.016392, 0.923734, 0.382684},
	{0.016392, 0.923734, 0.382684},
	{0.016392, 0.923734, 0.382684},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{0.006790, 0.382623, 0.923879},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923880},
	{-0.006790, -0.382623, 0.923879},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.006789, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006789, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, -0.382684},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017743, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017743, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, 0.000000},
	{0.999843, -0.017742, -0.000000},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382683},
	{-0.016392, -0.923734, -0.382684},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{-0.006790, -0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.006790, 0.382623, -0.923880},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382683},
	{0.016392, 0.923734, -0.382684},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.016392, 0.923734, 0.382683},
	{0.006789, 0.382623, 0.923880},
	{0.006789, 0.382623, 0.923880},
	{0.006789, 0.382623, 0.923880},
	{0.006789, 0.382623, 0.923879},
	{-0.006790, -0.382623, 0.923880},
	{-0.006789, -0.382623, 0.923880},
	{-0.006789, -0.382623, 0.923880},
	{-0.006789, -0.382623, 0.923880},
	{-0.016392, -0.923734, 0.382684},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.016392, -0.923734, 0.382683},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017742, -0.000000},
	{-0.999843, 0.017742, 0.000000},
	{-0.999843, 0.017743, -0.000000},
	{-0.999843, 0.017743, -0.000000},
};

int numKartFaces = 302;

GLint KartFaces[302][6] = {
	{1, 1, 2, 2, 9, 3},
	{9, 3, 2, 2, 10, 4},
	{2, 5, 3, 6, 10, 7},
	{10, 7, 3, 6, 11, 8},
	{3, 9, 4, 10, 11, 11},
	{11, 11, 4, 10, 12, 12},
	{4, 13, 5, 14, 12, 15},
	{12, 15, 5, 14, 13, 16},
	{5, 17, 6, 18, 13, 19},
	{13, 19, 6, 18, 14, 20},
	{6, 21, 7, 22, 14, 23},
	{14, 23, 7, 22, 15, 24},
	{7, 25, 8, 26, 15, 27},
	{15, 27, 8, 26, 16, 28},
	{8, 29, 1, 30, 16, 31},
	{16, 31, 1, 30, 9, 32},
	{2, 33, 1, 34, 17, 35},
	{3, 36, 2, 33, 17, 35},
	{4, 37, 3, 36, 17, 35},
	{5, 38, 4, 37, 17, 35},
	{6, 39, 5, 38, 17, 35},
	{7, 40, 6, 39, 17, 35},
	{8, 41, 7, 40, 17, 35},
	{1, 34, 8, 41, 17, 35},
	{9, 42, 10, 43, 18, 44},
	{10, 43, 11, 45, 18, 44},
	{11, 45, 12, 46, 18, 44},
	{12, 46, 13, 47, 18, 44},
	{13, 47, 14, 48, 18, 44},
	{14, 48, 15, 49, 18, 44},
	{15, 49, 16, 50, 18, 44},
	{16, 50, 9, 42, 18, 44},
	{19, 51, 26, 52, 20, 53},
	{26, 52, 25, 54, 20, 53},
	{25, 54, 24, 55, 20, 53},
	{24, 55, 23, 56, 20, 53},
	{23, 56, 22, 57, 20, 53},
	{22, 57, 21, 58, 20, 53},
	{19, 59, 20, 60, 27, 61},
	{20, 62, 21, 63, 27, 64},
	{21, 65, 22, 66, 27, 67},
	{22, 68, 23, 69, 27, 70},
	{23, 71, 24, 72, 27, 73},
	{24, 74, 25, 75, 27, 76},
	{25, 77, 26, 78, 27, 79},
	{26, 80, 19, 81, 27, 82},
	{29, 83, 28, 84, 37, 85},
	{37, 85, 28, 84, 36, 86},
	{30, 87, 29, 88, 38, 89},
	{38, 89, 29, 88, 37, 90},
	{31, 91, 30, 92, 39, 93},
	{39, 93, 30, 92, 38, 94},
	{32, 95, 31, 96, 40, 97},
	{40, 97, 31, 96, 39, 98},
	{33, 99, 32, 100, 41, 101},
	{41, 101, 32, 100, 40, 102},
	{34, 103, 33, 104, 42, 105},
	{42, 105, 33, 104, 41, 106},
	{35, 107, 34, 108, 43, 109},
	{43, 109, 34, 108, 42, 110},
	{28, 111, 35, 112, 36, 113},
	{36, 113, 35, 112, 43, 114},
	{37, 115, 36, 116, 45, 117},
	{45, 117, 36, 116, 44, 118},
	{38, 119, 37, 115, 46, 120},
	{46, 120, 37, 115, 45, 117},
	{39, 121, 38, 119, 47, 122},
	{47, 122, 38, 119, 46, 120},
	{40, 123, 39, 121, 48, 124},
	{48, 124, 39, 121, 47, 122},
	{41, 125, 40, 123, 49, 126},
	{49, 126, 40, 123, 48, 124},
	{42, 127, 41, 125, 50, 128},
	{50, 128, 41, 125, 49, 126},
	{43, 129, 42, 127, 51, 130},
	{51, 130, 42, 127, 50, 128},
	{36, 116, 43, 129, 44, 118},
	{44, 118, 43, 129, 51, 130},
	{45, 131, 44, 132, 53, 133},
	{53, 133, 44, 132, 52, 134},
	{46, 135, 45, 136, 54, 137},
	{54, 137, 45, 136, 53, 138},
	{47, 139, 46, 140, 55, 141},
	{55, 141, 46, 140, 54, 142},
	{48, 143, 47, 144, 56, 145},
	{56, 145, 47, 144, 55, 146},
	{49, 147, 48, 148, 57, 149},
	{57, 149, 48, 148, 56, 150},
	{50, 151, 49, 152, 58, 153},
	{58, 153, 49, 152, 57, 154},
	{51, 155, 50, 156, 59, 157},
	{59, 157, 50, 156, 58, 158},
	{44, 159, 51, 160, 52, 161},
	{52, 161, 51, 160, 59, 162},
	{53, 163, 52, 164, 29, 165},
	{29, 165, 52, 164, 28, 166},
	{54, 167, 53, 163, 30, 168},
	{30, 168, 53, 163, 29, 165},
	{55, 169, 54, 167, 31, 170},
	{31, 170, 54, 167, 30, 168},
	{56, 171, 55, 169, 32, 172},
	{32, 172, 55, 169, 31, 170},
	{57, 173, 56, 171, 33, 174},
	{33, 174, 56, 171, 32, 172},
	{58, 175, 57, 173, 34, 176},
	{34, 176, 57, 173, 33, 174},
	{59, 177, 58, 175, 35, 178},
	{35, 178, 58, 175, 34, 176},
	{52, 164, 59, 177, 28, 166},
	{28, 166, 59, 177, 35, 178},
	{61, 179, 60, 180, 69, 181},
	{69, 181, 60, 180, 68, 182},
	{62, 183, 61, 184, 70, 185},
	{70, 185, 61, 184, 69, 186},
	{63, 187, 62, 188, 71, 189},
	{71, 189, 62, 188, 70, 190},
	{64, 191, 63, 192, 72, 193},
	{72, 193, 63, 192, 71, 194},
	{65, 195, 64, 196, 73, 197},
	{73, 197, 64, 196, 72, 198},
	{66, 199, 65, 200, 74, 201},
	{74, 201, 65, 200, 73, 202},
	{67, 203, 66, 204, 75, 205},
	{75, 205, 66, 204, 74, 206},
	{60, 207, 67, 208, 68, 209},
	{68, 209, 67, 208, 75, 210},
	{69, 211, 68, 212, 77, 213},
	{77, 213, 68, 212, 76, 214},
	{70, 215, 69, 211, 78, 216},
	{78, 216, 69, 211, 77, 213},
	{71, 217, 70, 215, 79, 218},
	{79, 218, 70, 215, 78, 216},
	{72, 219, 71, 217, 80, 220},
	{80, 220, 71, 217, 79, 218},
	{73, 221, 72, 219, 81, 222},
	{81, 222, 72, 219, 80, 220},
	{74, 223, 73, 221, 82, 224},
	{82, 224, 73, 221, 81, 222},
	{75, 225, 74, 223, 83, 226},
	{83, 226, 74, 223, 82, 224},
	{68, 212, 75, 225, 76, 214},
	{76, 214, 75, 225, 83, 226},
	{77, 227, 76, 228, 85, 229},
	{85, 229, 76, 228, 84, 230},
	{78, 231, 77, 232, 86, 233},
	{86, 233, 77, 232, 85, 234},
	{79, 235, 78, 236, 87, 237},
	{87, 237, 78, 236, 86, 238},
	{80, 239, 79, 240, 88, 241},
	{88, 241, 79, 240, 87, 242},
	{81, 243, 80, 244, 89, 245},
	{89, 245, 80, 244, 88, 246},
	{82, 247, 81, 248, 90, 249},
	{90, 249, 81, 248, 89, 250},
	{83, 251, 82, 252, 91, 253},
	{91, 253, 82, 252, 90, 254},
	{76, 255, 83, 256, 84, 257},
	{84, 257, 83, 256, 91, 258},
	{85, 259, 84, 260, 61, 261},
	{61, 261, 84, 260, 60, 262},
	{86, 263, 85, 259, 62, 264},
	{62, 264, 85, 259, 61, 261},
	{87, 265, 86, 263, 63, 266},
	{63, 266, 86, 263, 62, 264},
	{88, 267, 87, 265, 64, 268},
	{64, 268, 87, 265, 63, 266},
	{89, 269, 88, 267, 65, 270},
	{65, 270, 88, 267, 64, 268},
	{90, 271, 89, 269, 66, 272},
	{66, 272, 89, 269, 65, 270},
	{91, 273, 90, 271, 67, 274},
	{67, 274, 90, 271, 66, 272},
	{84, 260, 91, 273, 60, 262},
	{60, 262, 91, 273, 67, 274},
	{93, 275, 92, 276, 101, 277},
	{101, 277, 92, 276, 100, 278},
	{94, 279, 93, 280, 102, 281},
	{102, 281, 93, 280, 101, 282},
	{95, 283, 94, 284, 103, 285},
	{103, 285, 94, 284, 102, 286},
	{96, 287, 95, 288, 104, 289},
	{104, 289, 95, 288, 103, 290},
	{97, 291, 96, 292, 105, 293},
	{105, 293, 96, 292, 104, 294},
	{98, 295, 97, 296, 106, 297},
	{106, 297, 97, 296, 105, 298},
	{99, 299, 98, 300, 107, 301},
	{107, 301, 98, 300, 106, 302},
	{92, 303, 99, 304, 100, 305},
	{100, 305, 99, 304, 107, 306},
	{101, 307, 100, 308, 109, 309},
	{109, 309, 100, 308, 108, 310},
	{102, 311, 101, 307, 110, 312},
	{110, 312, 101, 307, 109, 309},
	{103, 313, 102, 311, 111, 314},
	{111, 314, 102, 311, 110, 312},
	{104, 315, 103, 313, 112, 316},
	{112, 316, 103, 313, 111, 314},
	{105, 317, 104, 315, 113, 318},
	{113, 318, 104, 315, 112, 316},
	{106, 319, 105, 317, 114, 320},
	{114, 320, 105, 317, 113, 318},
	{107, 321, 106, 319, 115, 322},
	{115, 322, 106, 319, 114, 320},
	{100, 308, 107, 321, 108, 310},
	{108, 310, 107, 321, 115, 322},
	{109, 323, 108, 324, 117, 325},
	{117, 325, 108, 324, 116, 326},
	{110, 327, 109, 328, 118, 329},
	{118, 329, 109, 328, 117, 330},
	{111, 331, 110, 332, 119, 333},
	{119, 333, 110, 332, 118, 334},
	{112, 335, 111, 336, 120, 337},
	{120, 337, 111, 336, 119, 338},
	{113, 339, 112, 340, 121, 341},
	{121, 341, 112, 340, 120, 342},
	{114, 343, 113, 344, 122, 345},
	{122, 345, 113, 344, 121, 346},
	{115, 347, 114, 348, 123, 349},
	{123, 349, 114, 348, 122, 350},
	{108, 351, 115, 352, 116, 353},
	{116, 353, 115, 352, 123, 354},
	{117, 355, 116, 356, 93, 357},
	{93, 357, 116, 356, 92, 358},
	{118, 359, 117, 355, 94, 360},
	{94, 360, 117, 355, 93, 357},
	{119, 361, 118, 359, 95, 362},
	{95, 362, 118, 359, 94, 360},
	{120, 363, 119, 361, 96, 364},
	{96, 364, 119, 361, 95, 362},
	{121, 365, 120, 363, 97, 366},
	{97, 366, 120, 363, 96, 364},
	{122, 367, 121, 365, 98, 368},
	{98, 368, 121, 365, 97, 366},
	{123, 369, 122, 367, 99, 370},
	{99, 370, 122, 367, 98, 368},
	{116, 356, 123, 369, 92, 358},
	{92, 358, 123, 369, 99, 370},
	{125, 371, 124, 372, 133, 373},
	{133, 373, 124, 372, 132, 374},
	{126, 375, 125, 376, 134, 377},
	{134, 377, 125, 376, 133, 378},
	{127, 379, 126, 380, 135, 381},
	{135, 381, 126, 380, 134, 382},
	{128, 383, 127, 384, 136, 385},
	{136, 385, 127, 384, 135, 386},
	{129, 387, 128, 388, 137, 389},
	{137, 389, 128, 388, 136, 390},
	{130, 391, 129, 392, 138, 393},
	{138, 393, 129, 392, 137, 394},
	{131, 395, 130, 396, 139, 397},
	{139, 397, 130, 396, 138, 398},
	{124, 399, 131, 400, 132, 401},
	{132, 401, 131, 400, 139, 402},
	{133, 403, 132, 404, 141, 405},
	{141, 405, 132, 404, 140, 406},
	{134, 407, 133, 403, 142, 408},
	{142, 408, 133, 403, 141, 405},
	{135, 409, 134, 407, 143, 410},
	{143, 410, 134, 407, 142, 408},
	{136, 411, 135, 409, 144, 412},
	{144, 412, 135, 409, 143, 410},
	{137, 413, 136, 411, 145, 414},
	{145, 414, 136, 411, 144, 412},
	{138, 415, 137, 413, 146, 416},
	{146, 416, 137, 413, 145, 414},
	{139, 417, 138, 415, 147, 418},
	{147, 418, 138, 415, 146, 416},
	{132, 404, 139, 417, 140, 406},
	{140, 406, 139, 417, 147, 418},
	{141, 419, 140, 420, 149, 421},
	{149, 421, 140, 420, 148, 422},
	{142, 423, 141, 424, 150, 425},
	{150, 425, 141, 424, 149, 426},
	{143, 427, 142, 428, 151, 429},
	{151, 429, 142, 428, 150, 430},
	{144, 431, 143, 432, 152, 433},
	{152, 433, 143, 432, 151, 434},
	{145, 435, 144, 436, 153, 437},
	{153, 437, 144, 436, 152, 438},
	{146, 439, 145, 440, 154, 441},
	{154, 441, 145, 440, 153, 442},
	{147, 443, 146, 444, 155, 445},
	{155, 445, 146, 444, 154, 446},
	{140, 447, 147, 448, 148, 449},
	{148, 449, 147, 448, 155, 450},
	{149, 451, 148, 452, 125, 453},
	{125, 453, 148, 452, 124, 454},
	{150, 455, 149, 451, 126, 456},
	{126, 456, 149, 451, 125, 453},
	{151, 457, 150, 455, 127, 458},
	{127, 458, 150, 455, 126, 456},
	{152, 459, 151, 457, 128, 460},
	{128, 460, 151, 457, 127, 458},
	{153, 461, 152, 459, 129, 462},
	{129, 462, 152, 459, 128, 460},
	{154, 463, 153, 461, 130, 464},
	{130, 464, 153, 461, 129, 462},
	{155, 465, 154, 463, 131, 466},
	{131, 466, 154, 463, 130, 464},
	{148, 452, 155, 465, 124, 454},
	{124, 454, 155, 465, 131, 466},
};

#endif