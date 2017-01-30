/*
 *  A general emote.
 */

emotee(str)  {
  if(!str)  {
  write("What would you like to emote?\n");
  return 1;
        }
  say(tp+" "+str+" \n");
  write(tp+" "+str+" \n");
  return 1;
        }
