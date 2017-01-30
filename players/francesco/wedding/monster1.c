#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";

reset(arg){
  object kale;
  ::reset();
  if(arg) return;
   set_name("peasant");
   set_race("human");
   set_alias("peasant");
   set_gender("male");
     set_short(HIR+"A peasant"+NORM+"");
     set_long("The peasant is wearing a well ironed suit.  His tie, though, seems\n"+
              "a bit out of fashion.  Also, he doesnt feel much comfortable in\n"+
              "this environment.\n");
   set_level(5);
   set_hp(100);
   set_wc(7);
   set_ac(12);
   set_chat_chance(1);
   load_chat("The peasant proudly (!) shows around his multicolored tie.\n");
   load_chat("The peasant whispers to his companion:  Yes, they did come at us, about one year ago.\n");
   kale = clone_object("/players/francesco/wedding/invite.c");
   move_object(kale,this_object());
}

id(str) {return str=="peasant" ;}

