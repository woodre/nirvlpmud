#include "/players/traff/closed/ansi.h"
int check;

id(str) {
   return str == "flag";
}

reset(arg) {
   if(arg) return;
   check = 0;
}

get() {return 1;}

long() {
   write("A "+RED+"flag"+NORM+".\n");
   write("You can <flag> <player>, to get their attention.\n");
    write("The flag may be used "+(10-check)+" more times.\n");
}

short() {
   return "A small flag";
}

init() {
   add_action("flag","flag");
}
flag (str)
{
   string who;
   object me;
   who = lower_case(str);
   if(!str) {
      write("Flag who?\n");
      return 1; }
   me = find_player(who);
   if(!me || me->query_invis()) {
      write(who+" is not here....\n");
      return 1; }
    if(me->query_level() > 20 &&
           me->query_real_name() != "traff") {
      write("Not a good idea!\n");
      return 1;
   }
tell_object(find_player(who),"O\n|"+BRED+"          "+NORM+
   "\n|"+BRED+" Hey You! "+NORM+
   "\n|"+BRED+"          "+NORM+
   "\n|\n|\n"+
   NORM+capitalize(this_player()->query_real_name())+" wants your attention\n");
write("You wave your flag at "+who+"\n");
check = check + 1;
if(check > 10) { destruct(this_object()); }
return 1; 
}
