# PURPOSE OF THE PROJECT

The following project encrypts or decrypts a message based on the user decision. Likewise, the user decides when to stop the project (when
they are done either encrypting or decrypting messages).

# FUNCTIONALITY

The program accepts Command Line Arguments which consists of a "key length" and "key". The "key length" has to match the length of the provided
"key" and the "key" must include all positive integers, in any order, until matching the last element. For example, a **valid** use of CLAs would be:

<center>./railcipher 4 1 3 2 4</center>

an **invalid** use would be:

<center>./railcipher 4 1 0 3 4</center>

If a corrrectly "key length" and "key" is provided, then the program will start running and will provide to the user three possible commands:

*encrypt {MESSAGE}
*decrypt {MESSAGE}
*quit

If a wrong command is used, the program will ask the user to try again.

If encrypt is chosen, the program will encrypt the MESSAGE by using the "key" and "key length".

If decrypt is chosen, the program will decrypt the MESSAGE by using the "key" and "key length".

# SKILLS

*Get used to manipulating CLAs in C.
*Hands on building encrypting and decrypting algorithms.
*Use of stderr by implementing macros