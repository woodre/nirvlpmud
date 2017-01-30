/*  This is a weapon testing mob.  It gives damage per round.  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
int apple;
object room;
init(){
   ::init();
   add_action("Pbag","pbag");
}
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("bag");
   set_race("testmob");
   set_alias("punching bag");
set_short(BOLD+"Punching bag"+NORM);
   set_long("This is a punching bag to test your weapons on.\n"+
      "Type 'pbag off' to turn it off.\n"+
      "Type 'pbag damage' to turn it on.\n");
   set_level(1);
   set_hp(1000);
   set_al(0);
   set_wc(0);
   set_ac(0);
   enable_commands();
   set_heart_beat(1);
}
Pbag(arg){
   apple = 0;
   if(!arg){write("Type 'pbag damage' to turn me on.\n");
      write("Type 'pbag off' to turn me off.\n");
      return 1;}
   if(arg == "off"){apple = 0; return 1;}
   if(arg != "damage"){write("Type 'pbag damage' to turn me on.\n");
      write("Type 'pbag off' to turn me off.\n");
      return 1;}
   apple=1;
   return 1;
}
heart_beat(){
   int hps;
   ::heart_beat();
   hps=this_object()->query_hp();
   room=environment(this_object());
   if(apple == 1)
      say("You just did "+(1000 - hps)+" points of damage.\n");
   this_object()->heal_self(1000);
}
