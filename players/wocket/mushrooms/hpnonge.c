#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg){
object gold;
    ::reset(arg);
  if(arg) return;
    set_name("nonge");
    set_alt_name("hpnonge");
    set_alias("priest");
    set_short("A "+CYN+"high priest"+NORM+" nonge");
    set_long("\
His fur is well trimmed and his white markings give him an air\n\
of authority.  His dress is of fine gold robes that flow well beyond\n\
his ankles.  From not having to do much physical work his\n\
build isnt that of a great warrior but he is in well enough\n\
shape to suit his needs.\n");
    set_gender("male");
    set_race("seussian");
    set_al(1000);
    set_level(21);
    set_hp(800);
    set_wc(33);
    set_ac(20);

    set_chance(8);
    set_spell_dam(30);
    set_spell_mess1("\nThe "+CYN+"high priest"+NORM+" nonge recites some ancient words.\n\t"+HIR+"FLAMES BEGIN TO ERRUPT EVERYWHERE !!!!\n\n"+NORM);
    set_spell_mess2("\nThe "+CYN+"high priest"+NORM+" nonge recites some ancient words.\n\t"+HIR+"FLAMES BEGIN TO ERRUPT EVERYWHERE !!!!\n\n"+NORM+"You feel great pain as the heat burns you.");

move_object(clone_object("/players/wocket/mushrooms/lance.c"),this_object());
add_money(1000);
}

