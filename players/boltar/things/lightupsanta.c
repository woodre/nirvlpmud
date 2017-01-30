#include "/players/boltar/things/esc.h"


 int lightstate;
 int stoptalk;
short()
{
    if (this_player()->query_real_name() == "geoff") return "A light up Santa";
   if(lightstate == 0) 
     return "A light up plastic Santa";
    if(lightstate == 1)
   return esc+"[0m"+esc+"[1m"+esc+"[1m"+esc+"[37m"+esc+"[40m A light up plastic Santa (lit)"+esc+"[0m";
}

query_value()
{
        return 150;
}

  query_weight() {   return 10000; }
long()
{
  write("A light up plastic Santa Claus. It almost looks real.\n");
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
    return str == "santa" || str == "plastic santa";
}

light(str) {
    if (str && !id(str))
        return 0;
   if(lightstate != 0) {
   write("The santa is already lit.\n");
    return 1;
}
     write("You turn on the Santa, and it glows brightly.\n");
if (this_player()) {
say(call_other(this_player(), "query_name") +
  " turns on the Santa Claus. \n"
   );
}
   set_light( 1);
   lightstate = 1;
   stoptalk = 0;
   call_out("talk", 5);
    return 1;
}

get() {
   write("Ok.\n");
    return 1;
}
extinguish(str) {
    if (str && !id(str))
      return "extinguish what?";
    if(lightstate != 1) {
    write("The santa is not lit.\n");
   return 1;
}
    write("You extinguish the Santa.\n");
    say(call_other(this_player(), "query_name") +
   " turns off the Santa.\n");
   set_light(-1);
   lightstate = 0;
   stoptalk = 1;
   return 1;
}
talk() {
if(random(100) < 50) {
    say("\n");
    say("The plastic Santa says: Ho Ho Ho.       ");
    say("Merry Christmas.\n");
/* Rumplemintz */
    if (present("trixie", environment(this_object()))) {
      say("Trixie glares at the plastic Santa.\n");
      say("Trixie asks: Who yo callin 'Ho', Jolly man?\n");
      say("Trixie snaps her fingers in a 'Z' formation.\n");
    }
}else if (random(100) < 50) {
     say("\nThe plastic Santa says: I know if you have been bad or good.\n");
} else {
     say("\nThe plastic Santa says: I know when you are sleeping, I know when you're awake.\n");
}
    if(!stoptalk)
     call_out("talk", 30);
    }
remove_object(ob) { log_file("XMAS",file_name(ob)+"\n"); }
