#include "/players/boltar/things/esc.h"


 int lightstate;
short()
{
   if(lightstate == 0) 
     return "A Christmas tree";
    if(lightstate == 1)
   return esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[31m"+esc+"[40m A Christmas tree (lit)"+esc+"[0m";
}

query_value()
{
        return 0;
}

  query_weight() {   return 10000; }
long()
{
   write("A decorated pine tree. It has lights and other strange objects hanging on it.\n");
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
     add_action("light"); add_verb("light");
     add_action("extinguish"); add_verb("extinguish");
#else
  add_action("light", "light");
  add_action("extinguish", "extinguish");
#endif
}

id(str) {
    return str == "tree" || str == "christmas tree";
}

light(str) {
    if (str && !id(str))
        return 0;
   if(lightstate != 0) {
   write("The tree is already lit.\n");
    return 1;
}
 write("You turn on the Christmas tree's lights.\n");
 write("Its a very pretty sight.  You feel more relaxed.\n");
if (this_player()) {
say(call_other(this_player(), "query_name") +
  " lights the Christmas tree. \n"+
  "It glows and sparkles with all the colors of the rainbow. \n");
  }
   set_light( 1);
   lightstate = 1;
    return 1;
}

get() {
   write("You get pricked with several pine needles as you pick up the tree.\n");
    return 1;
}
extinguish(str) {
    if (str && !id(str))
      return "extinguish what?";
    if(lightstate != 1) {
    write("The tree is not lit.\n");
   return 1;
}
    write("You extinguish the Christmas tree's lights.\n");
    say(call_other(this_player(), "query_name") +
   " turns off the Christmas tree lights.\n");
   set_light(-1);
   lightstate = 0;
   return 1;
}
