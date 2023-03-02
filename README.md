C-LANG
======

C ANSI
------
auto
break
case
char
const
continue
default
do
double
else
enum
extern
float
for
goto
if
int
long
register
return
short
signed
sizeof
static
struct
switch
typedef
union
unsigned
void
volatile
while

Flow
----

Source -> Preprocessor -> Compiler -> Linker -> Program


Basic Types
-----------
char
int
float
double
void

Type Modifiers
--------------
signed
unsigned
long
short

Access Modifiers
----------------
const
volatile

Storage Modifiers
-----------------
extern
static
register
auto

Operators
---------
= += -= *= /=
- + * / % -- ++
> >= < <= == !=
&& || !
& | ^ ~ >> <<
?:

Pointer
-------
&
*
(*)

Access
------
. -> [] ()

Special
-------
sizeof()

Control
-------
if/else
switch/case/default
for
while
do/while
break
continue
return
goto

Memory
------
malloc()
free()

Function
--------
type name(args){body}
int main(){}
char func(...){}

Struct
------
struct name {fields};

Union
-----

Enum
----

Typedef
-------

Console
-------
stdin  = 0
stdout = 1
stderr = 2
printf()
scanf()

Files
-----
FILE *
fopen()
fwrite()
fread()
fseek()
fclose()

Unix files
----------
open()
write()
read()
close()

Preprocessor
------------
#include
#define
#ifdef
#undef
#error


Sockets
-------
connect()
listen()
accept()


Env
---
envp

Fork
----

Threads
-------

Signals
-------

Args
----

Non-blocking
------------
epoll()
poll()
select()
