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

[C001] - Document source code using **[Doxygen] (https://www.doxygen.nl/index.html)** syntax

~~[C002] - Create a folder for each library~~

[C003] - `main` branch is ONLY for TESTED libraries. All the rest goes to `Debug` branch


-

# Coding Convention `[CCxxx]`

For writing of this library we choosen to use the **[Hungarian Notation] (https://en.wikipedia.org/wiki/Hungarian_notation)**.

> Hungarian Notation: This notation describes the variable type or purpose at the start of the variable name, followed by a descriptor that indicates the variable’s function. The Camelcase notation is used to delimit words.
> 
> For examples:
arrDistrubuteGroup  //Array called “Distribute Group”
sUserName           //String called “User Name”
iRandomSeed         //Integer called “Random Seed”



[CC001] - Naming Convention

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
| string | s | 
| String() |
| unsigned char |
| unsigned int |
| unsigned long |
| void |
| word |