# sim800l_light

Customized library to manage SIMCom SIM800L module by serial AT commands using only the subset we really need (only GSM for send/receive sms, NO GPRS, NO UMTS, or other internet function, NO voice call function)


-
For syntax reference of this `.md` file, see **[Markdown Guide] (https://www.markdownguide.org/)**

-

# ToDo `[TDxxx]` 

...
...

-

# Convention `[Cxxx]`

[C001] - Document source code using **[Doxygen] (https://www.doxygen.nl/index.html)** syntax see **[\[CC002\] - Doxygen text block](#[CC002]---doxygen-text-block)**

~~[C002] - Create a folder for each library~~

[C003] - `main` branch is for libraries developing.

[C004] - When a release is made you `MUST` use `TAGS` on GitHub.

[C005] - If you need to test a feature or develop a new ones, then `BRANCH` from `main` and, only at the end of all the develop, `MERGE` back to main to release feature.


-

# Coding Convention `[CCxxx]`

For writing of this library we choosen to use the **[Hungarian Notation] (https://en.wikipedia.org/wiki/Hungarian_notation)**.

> Hungarian Notation: This notation describes the variable type or purpose at the start of the variable name, followed by a descriptor that indicates the variable’s function. The Camelcase notation is used to delimit words.
> 
> For examples:
arrDistrubuteGroup  //Array called “Distribute Group”
sUserName           //String called “User Name”
iRandomSeed         //Integer called “Random Seed”

-

###[CC001] - Naming Convention

| Variable Type | Name starts with... | Variable mem usage | Variable range |
|:--------------|:-------------------:|:------------------:|:--------------:|
| array | arr | Depends on variable type | - |
| bool | b | 1 byte | true / false |
| byte | by | 1 byte | 0 - 255 |
| char | c | 1 byte | see [ASCII chart] (https://www.arduino.cc/en/Reference/ASCIIchart) |
| double | d | 4 byte on Uno (and other ATMEGA based bord) <br> 8 byte (64-bit precision) on the Arduino Due board | ? |
| float | f | 4 byte (32-bit) | from -3.4028235E+38 to 3.4028235E+38 |
| int | i | 2 byte (16-bit) on Uno (and other ATMEGA based bord) <br> 4 byte (32-bit) on the Arduino Due and SAMD based board| 2-byte: from -32768 to 32767 <br>4-byte: from -2,147,483,648 to 2,147,483,647 |
| long | l | 4 byte | from -2,147,483,648 to 2,147,483,647 |
| short | sh | 2 byte | from -32768 to 32767 |
| size_t | sz | byte as the object | byte as the object | see object |
| string | s | 1 byte x char + terminator | - |
| String() | s | 1 byte x char + terminator | - |
| unsigned char | uc | 1 byte | 0 - 255 |
| unsigned int | ui | 2 byte (16-bit) on Uno (and other ATMEGA based bord) <br> 4 byte (32-bit) on the Arduino Due and SAMD based board| 2-byte: from 0 to 65535<br>4-byte: from 0 to 4,294,967,295 |
| unsigned long | ul | 4 byte | from 0 to 4,294,967,295 |
| word | w | 2 byte | from 0 to 65535 |

-

###[CC002] - Doxygen text block

####Comment Block
`/*!`
&nbsp;&nbsp;` * ... text ...`
&nbsp;&nbsp;` * ... text ...`
&nbsp;&nbsp;` * ... text ...`
&nbsp;&nbsp;` */`
<br>

####Brief Description
`/*! \brief Brief description.`
&nbsp;&nbsp;` *         Brief description continued.`
&nbsp;&nbsp;` *`
&nbsp;&nbsp;` *  Detailed description starts here.`
&nbsp;&nbsp;` */`

This command ends at the end of a paragraph, so the detailed description follows after an _empty_ line.
<br>

####Putting documentation after members
If you want to document the members of a file, struct, union, class, or enum, it is sometimes desired to place the documentation block after the member instead of before.
For this purpose you have to put an additional `<` marker in the comment block. Note that this also works for the parameters of a function.

Here are some examples:

`int var; /*!< Detailed description after the member */`

<br>

####Commenting funtions or subs

`//! A normal member taking two arguments and returning an integer value.`
`/*!`
&nbsp;&nbsp;`  \param a an integer argument.`
&nbsp;&nbsp;`  \param s a constant character pointer.`
&nbsp;&nbsp;`  \return The test results`
&nbsp;&nbsp;`  \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()`
`*/`
`int testMe(int a,const char *s);`


####Documentation at other places
In the examples in the previous section the comment blocks were always located *in front* of the declaration or definition of a file, class or namespace or *in front* or *after* one of its members. Although this is often comfortable, there may sometimes be reasons to put the documentation somewhere else. For documenting a file this is even required since there is no such thing as "in front of a file".

Doxygen allows you to put your documentation blocks practically anywhere (the exception is inside the body of a function or inside a normal C style comment block).

The price you pay for not putting the documentation block directly before (or after) an item is the need to put a structural command inside the documentation block, which leads to some duplication of information. So in practice you should avoid the use of structural commands unless other requirements force you to do so.

Structural commands (like all other commands) start with a backslash (\), or an at-sign (@) if you prefer Javadoc style, followed by a command name and one or more parameters. For instance, if you want to document the class Test in the example above, you could have also put the following documentation block somewhere in the input that is read by doxygen:

`/*! \class Test`
`    \brief A test class.`
` `
`    A more detailed class description.`
`*/`

Here the special command `\class` is used to indicate that the comment block contains documentation for the class Test. Other structural commands are:

`\struct` to document a C-struct.
`\union` to document a union.
`\enum` to document an enumeration type.
`\fn` to document a function.
`\var` to document a variable or typedef or enum value.
`\def` to document a #define.
`\typedef` to document a type definition.
`\file` to document a file.
`\namespace` to document a namespace.
`\package` to document a Java package.
`\interface` to document an IDL interface.