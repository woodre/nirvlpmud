/*
 *      File:                   emotes.c
 *      Function:               lists emotes by starting letter(s)
 *      Author(s):              Illarion@Nirvana
 *      Created:                10 Nov 2004
 *      Notes:                  
 *
 *      Change History:
 */

#include "/players/illarion/dfns.h"

/* 
 * Function name: cmd_emotes
 * Description: writes the emotions starting with the letter(s)
                specified in the argument
 * Arguments: string
 * Returns: int
 */
 
cmd_emotes(string str) {
  string *emotions;
  string output;
  int s,x;
  if(!str) {
    cat("/doc/helpdir/emotions");
    return 1;
  }
  
  emotions=get_dir("/bin/soul/_"+str+"*");
  s=sizeof(emotions);
  if(!s) {
    write("No emotes starting with \""+str+"\" found.\n");
    return 1;
  }
  output="";
  for(x=0;x<s;x++)
    output+=emotions[x][1..-3]+" ";
  write("\n      [ :::Emotions Starting with "+str+"::: ]\n\n");

  write(format(output));
  return 1;
}