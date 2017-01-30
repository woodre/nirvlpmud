inherit "/obj/monster.c";

#include "../defs.h"
reset(arg) {
   ::reset(arg);
   if(arg) return;
    move_object(clone_object("/players/humble/newbarea/items/dwarfchainmail.c"));
    move_object(clone_object("/players/humble/newbarea/items/dwarfhelm.c"));
    init_command("wear chainmail");
    init_command("wear helm");
    set_short(HIW+"Dwarven Guard"+NORM);
    set_name(HIW+"Dwarven Guard"+NORM);
    set_alias("dwarf");
    set_alt_name("guard");
   set_long(
    "A brutish and rather large looking Dwarf with a nasty red beard that\n"+
    "hangs down to his crotch. He wield a rather scary looking hammer.\n"+
    "and is covered from head to toe in blood-splattered chainmail.\n"+
    "You have to wonder what a beast like this is doing in such a serene\n"+
    "place as such.\n");
   set_gender("male");
    set_race("dwarf");
    set_level(14);
    set_hp(180+random(45));
    set_wc(18);
    set_ac(11);
    add_money(200+random(100));
    set_chat_chance(5);
    set_a_chat_chance(4);
    load_a_chat(HIW+"Dwarven Guard gets a grin on his face as he takes your blows.\n"+NORM);
    load_chat(HIW+"Dwarven Guard looks at you and laughs.\n"+NORM);
  }
    stop() {
    if(this_player()->query_level() >0) {
    write(HIK+"Dwarven Guard shoves you back.\n"+NORM+
    HIK+"Dwarven Guard says:"+NORM+" You're not to go in there.\n");
    return 1;
    }

    return 0;
}
init() {
    ::init();
      add_action("stop", "enter");
  }
