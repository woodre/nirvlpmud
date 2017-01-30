
inherit "obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"

reset(str) {
  if(str) return;
     set_name("elendil");
     set_alias("king");
     set_short("Elendil, King of Elves");
     set_long("He is a rather large elf clad in the best armaments of elves.\n");
     set_level(19);
     set_hp(800);
    set_ac(15);
    set_wc(30);
     set_al(645);
     ::reset(0);
  move_object(clone_object("/players/dragnar/MKScar/scar"), this_object());
}

