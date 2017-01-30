inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("jesse duke");
    set_alt_name("jesse");
    set_race("human");
    set_alias("duke");
set_gender("male");
    set_al(250+random(100));
    set_level(12);
    set_hp(160+random(40));
    set_wc(12+random(5));
    set_ac(9+random(3));
    set_short(BOLD+""+WHT+"Jesse Duke"+NORM);
    set_long(
      "Uncle Jesse is a grey haired gentleman in his 60's.  He is a\n"+
      "heavyset man with a long beard, and wearing blue coveralls.\n"+
     "He is the unquestioned head of the Duke clan.  Everybody in\n"+
      "Hazzard knows and respects him, even Rosco and Boss Hogg.\n"+
      "He used to run moonshine with Boss Hogg in the good ole days,\n"+
      "but when caught, made a deal with the government never to\n"+
      "make shine again.\n");
MOCO("/players/jenny/dukes/items/shine.c"),this_object());  }
