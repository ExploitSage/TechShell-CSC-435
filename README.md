# TechShell
CSC435 Operating Systems Tech Shell

Gustave Abel Michel III  

Non functional  
	True Piping  
Functional  
	Pseudo Pipe (using temp files)  
	Execution of Commands  
	Multiple Commands (seprated by semicolon)  
	Redirection  
		In, out, and both simulationious  
	built in commands  
	Strings  
	Variable replacement using $  
a)  
%> ls; echo "awesome"  
Command.c  Command.o  Parser.c	Parser.o  techShell    techShell.o  Variable.h  
Command.h  Makefile   Parser.h	Readme	  techShell.c  Variable.c   Variable.o  
awesome  
  
b) Not truely Functional (uses temp files, which are deleted after)  
%> ls | wc  
 15  15 155  
  
c)  
%> ls > out; wc < out  
 15  15 144  
  
d)  
%> set A "WOW DUDE"  
%> set B "COOL"  
%> list  
A:WOW DUDE  
B:COOL  
%> set B  
%> list  
A:WOW DUDE  
%> echo $A  
WOW DUDE  
  
e)  
%> asdf  
TSH: No such file or directory  
%> set  
TSH: Error, no Variable name given  