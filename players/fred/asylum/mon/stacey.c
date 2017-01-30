inherit "/obj/monster.c";
#include <ansi.h>
#include "/players/fred/defines.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("stacey");
  set_race("spirit");
  set_short("Stacey");
  set_long(
    "  Stacey has long blonde hair down to the middle of her back.\n"+
    "She appears to be a younger woman wearing the same clothes that\n"+
    "she wore many years ago. Her face shows many years of pain and\n"+
    "and suffering\n");
  
  set_level(20);
  set_al(-(random(800)));
  set_ac(17);
  set_wc(30);
  set_hp(400+(random(200)));
  set_gender("female");
  set_dead_ob(this_object());
  set_aggressive(1);
  set_chat_chance(5);
   load_chat("Stacey cries, why can't you leave us alone...\n");
   load_chat("Stacey sobs into her sleeve...\n");
  }
  
  monster_died(){
   object corpse;
   corpse = present("corpse", environment());
   tell_object(HOSER,
     "\n  As Stacey "+YEL+"vanishes"+NORM+" in a blast of light...\n"+
     "      She says, please take good care of my belongings.\n"+
     "          They are all I have.\n\n");
   if(corpse)
    destruct(corpse);
    return 1;  
   }
