/* personal say command */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

status main(string str) {
  string verb;
  if(!str) {
    FAIL("Say what?\n");
      return 0; 
  }
  if(strlen(str) > 1) {
         if(str[strlen(str)-3..strlen(str)-1] == "!!!") verb = "scream";
    else if(str[strlen(str)-3..strlen(str)-1] == "???") verb = "ponder";
    else if(str[strlen(str)-2..strlen(str)-1] == ":)")  verb = "smile";
    else if(str[strlen(str)-2..strlen(str)-1] == ":(")  verb = "frown";
    else if(str[strlen(str)-2..strlen(str)-1] == ";)")  verb = "wink";
    else if(str[strlen(str)-2..strlen(str)-1] == ";(")  verb = "sadly wink";
    else if(str[strlen(str)-2..strlen(str)-1] == "!!")  verb = "yell";
    else if(str[strlen(str)-2..strlen(str)-1] == "??")  verb = "wonder";
    else if(str[strlen(str)-1] == '?')                  verb = "ask";
    else if(str[strlen(str)-1] == '!')                  verb = "exclaim";
    else                                                verb = "speak";
  }
  else verb = "speak";
  tell_object(this_player(),WTC+"You "+verb+": "+NORM+str+"\n");
  tell_room(environment(this_player()),WTC+this_player()->query_name()+" "+verb+"s: "+NORM+str+"\n", ({ this_player() }));
    return 1; 
}
