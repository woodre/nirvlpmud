#include "/players/llew/closed/ansi.h"

lt (str) {
   string what, who;
   if(sscanf(str, "%s %s", who, what) != 2) {
      write("Sing what?\n");
      return 1;
   }
   if(!find_player(who)) {
       write(capitalize(who)+" is not here....\n");
       return 1;
   }
   if(in_editor(find_player(who))) {
      write(who+" is in edit.\n");
   }
   if(interactive(find_player(who))) {
      string mess;
      mess=" ";
      if(query_verb() == "lt") mess+="tells you: ";
      tell_object(find_player(who),capitalize(this_player()->query_real_name())+format(mess+what,70));
      write("You lt to "+capitalize(who)+": "+what+"\n");
      return 1; 
   }
   else { 
      write(capitalize(who)+" is link dead.\n"); 
      return 1;
   }
}
