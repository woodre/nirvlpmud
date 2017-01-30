inherit "/obj/monster.c";

#include "../defs.h"
reset(arg) {
   ::reset(arg);
   if(arg) return;
    move_object(clone_object("/players/humble/newbarea/items/elvendagger.c"));
     init_command("wield dagger");
    set_name(GRN+"An Elf"+NORM);
    set_short(GRN+"An Elf"+NORM);
    set_alias("elf");
    set_alt_name("elf");
   set_long(
    "An Elf of normal proportion.  He is a slender young elf with healthy long\n"+
    "hair.  He looks very innocent and at home in this world, you cannot\n"+
    "figure out what type of weapons he has sheathed but I'm sure he's\n"+
    "a skilled young warrior from some tribe.\n");
   set_gender("male");
    set_race("elf");
    set_level(10);
    set_hp(150+random(25));
    set_wc(14);
    set_ac(8);
    add_money(175+random(100));
    set_chat_chance(5);
    set_a_chat_chance(4);
    load_chat(GRN+"An Elf playfully kicks rocks in your direction.\n"+NORM);
    load_a_chat(GRN+"An Elf screams:"+NORM+" You big bully, I'll show you.\n");
  }
