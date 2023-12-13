cmake_minimum_required(VERSION 3.26)
project(adventofcode23 C)

set(CMAKE_C_STANDARD 11)

add_executable(D1P1 day1/part1.c)
add_executable(D1P2 day1/part2.c)

add_executable(D2P1 day2/part1.c)
add_executable(D2P2 day2/part2.c)

add_executable(D3P1 day3/part1.c)
add_executable(D3P2 day3/part2.c)

add_executable(D6P1 day6/part1.c)
add_executable(D6P2 day6/part2.c)

add_executable(D10P1 day10/part1.c)
#add_executable(D10P2 day10/part2.c)