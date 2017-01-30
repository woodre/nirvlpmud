/* answer: atafaf */

description()
{ write("\t ****** ?? True or False ?? ******\n\n"+
  "Last week we were discussing puzzles, walking through the streets of Nirvana.\n"+
  "In a pub we met six people who told us they belonged to a completely new guild.\n"+
  "This guild was spliced into three parts. People in the first part are 'truthers',\n"+
  "those in the second part are 'falsers' and those from the last part the 'alterna-\n"+
  "tivers'. The truthers always tell the truth, the falsers always lie, as you may\n"+
  "suspect. The alternativers tell the truth and the false alternatively. We were\n"+
  "curious and asked each of the six persons in the group the following questions:\n"+
  "\t1) Are you a truther?\n"+
  "\t2) How many thruthers are present in this group of six?\n"+
  "\t3) How many alternativers are present in this group of six?\n"+
  "They answered:  person * 1st * 2nd * 3rd\n"+
  "                  1       Y     1     2\n"+
  "                  2       Y     1     3\n"+
  "                  3       Y     1     2\n"+
  "                  4       Y     2     2\n"+
  "                  5       Y     1     1\n"+
  "                  6       Y     2     1\n"+
  "At first we thought that this didn't give us much information, but then\n"+
  "we concluded that it was enough to determine the guild part of each person.\n"+
  "This results in this weeks question:\n"+
  "    ==> To what part of this new guild each speaker belongs to?\n\n"+
  "Answer by 'answer <first guild letter (t,f,a) of 6 persons without spaces>'.\n");
  return 1;
}
