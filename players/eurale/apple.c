/*This is a weapon testing monster made by Sweetness*/
/*It will give you the damage that you do in a round*/
/*and will not die. Just look at apple to see the  */
/*commands to use with him. If you like it let me know*/

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
int apple;
object room;
init(){
   ::init();
   add_action("apple","apple");
}
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("road apple");
   set_race("fruit");
   set_alias("apple");
set_short(BOLD+"A road apple"+NORM);
   set_long("This is a road apple to test your weapons on.\n"+
      "Type 'apple off' to turn it off.\n"+
      "Type 'apple damage' to turn it on.\n");
   set_level(1);
   set_hp(1000);
   set_al(0);
   set_wc(0);
   set_ac(0);
   enable_commands();
   set_heart_beat(1);
}
apple(arg){
   apple = 0;
   if(!arg){write("Type 'apple damage' to turn me on.\n");
      write("Type 'apple off' to turn me off.\n");
      return 1;}
   if(arg == "off"){apple = 0; return 1;}
   if(arg != "damage"){write("Type 'apple damage' to turn me on.\n");
      write("Type 'apple off' to turn me off.\n");
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
