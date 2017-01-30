/* add to baspuzzle.c:
   #define ANTWOORD "6840512379"
*/

description()
{ write("\t ****** Numbers Quest ******\n"+
  "Here are 4 rows with the numbers 0-9, ordered in a specific way:\n"+
  "\n\t2 6 3 0 4 8 5 1 7 9\n\t4 6 9 1 2 8 5 7 3 0\n"+
  "\t6 0 4 9 5 8 2 3 7 1\n\t4 6 9 1 5 8 2 3 7 0\n\n"+
  "The question is: what is the correct order of the ten numbers,\n"+
  "given that in the first row three numbers are on their original\n"+
  "place, in the second row none of them is correct situated, the\n"+
  "third row has six numbers in the right position and in the last\n"+
  "row six numbers are wrong positioned?\n"+
  "Give your answer by typing: 'answer <numbers, without spaces>'.\n"+);
  return 1;
}
