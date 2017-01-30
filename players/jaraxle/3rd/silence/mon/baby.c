#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("fairy child");
   set_alias("child");
   set_race("fairy");
   set_short("Fairy Child");
   set_long("An extremely young fairy.  The wings flutter franticly, trying to\n"+
      "it floating in the air.  The eyes are slightly closed shut.\n");
   
   set_level(1);
   set_hp(60+random(20));
   set_al(0);
   set_wc(3);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The Fairy Child floats around quickly.\n");
   load_chat("The Fairy Child smiles at you.\n");
   load_chat("A light gust of wind pushes the Fairy Child across the room.\n");
   set_dead_ob(this_object());
   
}

monster_died() {
   tell_room(environment(this_object()),
      "The child flops to the floor, dead.\n");
   MOCO("/players/jaraxle/3rd/silence/items/dust.c"),environment());

return 0; }
