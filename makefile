###############################################################
# Program:
#     Assignment 05, Order Tracking
#     Brother Alvey, CS165
# Author:
#     Bryan Yeske
# Summary:
#     This is now a clerks program for recites invintory and
#     more.
###############################################################


# We will learn fancier compilation steps later, but this is
# good enough for now...
a.out : cipher.h cipher01.h cipher02.h cipher03.h cipher04.h cipher05.h example.h ui.cpp
	g++ ui.cpp
