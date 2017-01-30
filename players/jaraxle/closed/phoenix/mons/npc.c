/*  10/08/06 - Rumplemintz
      Moved inherit above #include and removed trailing ; from #include
      Copied mishtar's random.h to local random.c and inherit it here
      instead of using inherit on a .h file
     Changed include of mishtar/ansi.h to /obj/ansi.h (mishtar's does not exist)
*/

inherit "/obj/monster.c";
inherit "/players/jaraxle/closed/phoenix/mons/random.c";
#include "/obj/ansi.h"


reset(arg) {
    get_random();
    set_alias("guard");
    set_name("guard");
    set_race("elf");
    set_gender((gen));
    set_short(HIK+"Erethorian Gate Keeper"+NORM);
    set_short(HIK+"Erethorian Gate Keeper"+NORM);
    set_long("\n"+
      "A long mane of "+hair+" hair flows freely in the soft breeze as \n"+
      "this grizzled elven warrior silently stands guard at "+genp+" post.\n"+
      capitalize(to_string(genp))+" silver platemail glistens in the dim light as "+gen3+" tightens \n"+
      genp+" grip on "+genp+" sword and hefts "+genp+" shield with a sigh.\n");

    set_level(20);
    set_hp(800);
    set_al(800);
    set_wc(40+random(5));
    set_ac(15+random(5));
}
