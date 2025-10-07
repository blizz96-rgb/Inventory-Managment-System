# Inventory-Managment-System
Inventory Manager is a basic application that handles inventory records and saves data in readable .txt files for later use.
Inventory Manager is a basic application that handles inventory records and saves data in 
readable .txt files for later use. When setting up the program make sure inventory.h, 
file_io.h, main.c, inventory.c, file_io.c, and Makefile exist within the same 
directory. Compile the program by executing make in your terminal. After building the 
program launch ./inventory_manager to begin inventory management. 
Compilation creates object files (.o) which are intermediate files that require no manual 
opening. The .txt file generated during program operation remains accessible and contains 
the preserved inventory records. Executing make clean when required will delete compiled 
files yet keep the inventory data intact. Users will find the program straightforward to use as 
it needs no extra configuration yet operates correctly immediately. 
The program development process revealed a core dump error while attempting to save 
inventory data. The program experienced initial save errors which persisted even after 
correction. I thoroughly reviewed my code and executed multiple rewrites yet considered 
starting anew but chose to continue due to the substantial eAort made. Through the use of 
gdb in debugger mode I managed to find the error-causing line which allowed me to correct 
the issue and create a fully operational program. The successful functioning of the program 
post-debugging provided immense satisfaction. 
