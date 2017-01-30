/* **********************************************************************
*
********************************************************************** */

inherit "/obj/monster";
#include "/players/jareel/define.h"

    reset(arg) {
      ::reset(arg);
        if (arg) return;
    set_race("troll");
    set_al(-10);
    set_ac(5);
    set_wc(9);
    set_hp(75);
    set_level(5);
    add_money(180+random(20));
    set_name("troll");
    set_short("Trollkin");
    set_long(
      "A hunching humanoid figure stamds in front of you.\n"+
      "Frail and cowardly the creature is very fragile\n"+
      "when seen next to his larger relatives.\n");
    set_spell_mess1("Trollkin tosses a rock\n");
    set_spell_mess2("Trollkin tosses a rock");
    set_chance(5);
    set_spell_dam(3);

}
