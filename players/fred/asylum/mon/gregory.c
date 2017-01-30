inherit "/obj/monster.c";
#include <ansi.h>
#include "/players/fred/defines.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("gregory");
  set_alias("greg");
  set_race("spirit");
  set_short("Gregory");
  set_long(
    "  A grossly disfigured ghost of one of the many guards\n"+
    "that used to patrol the halls of the asylum. Most were\n"+
    "killed by patients in cruel inhumane ways. Some of the \n"+
    "luckier ones were burned alive or stabbed to death.\n");
  
  set_level(20);
  set_al(0);
  set_ac(17);
  set_wc(27+(random(10)));
  set_hp(500+(TO->query_wc()*2));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(5);
   load_chat("Gregory glares at you with "+BOLD+RED+"RAGE"+NORM+" filled eyes...\n");
   load_chat("Gregory eyes you suspiciously...\n");
  set_chance(15);
  set_spell_dam(random(50));
  set_spell_mess1(
    "\n\tGregory grabs "+MAG+HOSER+NORM+" by the throat and...\n"+
    "\t  slowly tightens his grip.\n\n");
  set_spell_mess2(
    "\n\tGregory grabs you by the throat and slowly "+MAG+"tightens"+NORM+" his grip.\n\n");  
  }
  
  monster_died(){
   object corpse;
   corpse = present("corpse", environment());
   tell_object(HOSER,
     "\n  Gregory screams in anguish as you deliver the final blow.\n\n");
     move_object(clone_object("/players/fred/asylum/obj/bracelet.c"),
     environment(this_object())); 
     move_object(clone_object("/players/fred/asylum/obj/bboots.c"),
     environment(this_object())); 
   if(corpse)
      destruct(corpse);
      return 1;  
   }
