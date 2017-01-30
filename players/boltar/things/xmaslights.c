#include "/players/boltar/things/esc.h"
#include "/obj/clean.c"


 int lightstate;
short()
{
   if(lightstate == 0) 
     return "Christmas lights";
    if(lightstate == 1)
   return esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mChristmas lights (lit)"+esc+"[0m";
}

query_value()
{
        return 75;
}

  query_weight() {   return 2; }
long()
{
   write("A string of Christmas lights, the big old fashioned kind.\n");
}

init() {
     add_action("light","light");
     add_action("extinguish","extinguish");
}

id(str) {
    return str == "lights" || str == "christmas lights";
}

light(str) {
    if (!str || !id(str))
        return 0;
   if(lightstate != 0) {
   write("The lights are already lit.\n");
return 1;
}
 write("You turn on the Christmas lights.\n");
 write("Its a very pretty sight.  You feel more relaxed.\n");
if (this_player()) {
say(call_other(this_player(), "query_name") +
  " turns on the Christmas lights. \n"+
   "They light up in all different colors.\n");
  }
   set_light( 1);
   lightstate = 1;
    return 1;
}

get() {
  write("You get an electric shock as you pick up the lights.\n");
    return 1;
}
extinguish(str) {
    if (!str || !id(str))
      return "extinguish what?";
    if(lightstate != 1) {
    write("The lights are not lit.\n");
return 1;
}
    write("You extinguish the Christmas lights.\n");
    say(call_other(this_player(), "query_name") +
   " turns off the Christmas lights.\n");
   set_light(-1);
   lightstate = 0;
   return 1;
}
