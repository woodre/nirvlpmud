#include "/players/catwoman/closed/color.h"
inherit "/obj/monster.c";

reset(arg){
    ::reset(arg);
    if(arg) return;
move_object(clone_object("/players/catwoman/weapon/jguitar.c"),this_object());
    set_name("jimi");
    set_short(LIGHT_BLUE+"The one and only "+OFF+"Jimi "+PURPLE+"Hendrix"+OFF);
    set_race("musician");
    set_alias("hendrix");
set_long("Jimi looks pretty strong for a dead guy\n"+
"must be all that heroin he took.  There is a purple haze about his head.\n");
set_level(25);
set_hp(999);
set_wc(19);
set_ac(15);
set_aggressive(1);
set_chance(40);
set_spell_dam(20);
set_spell_mess1(LIGHT_BLUE+"Jimi strikes a chord through your soul."+OFF);
set_spell_mess2("Jimi says: excuse me while I kiss the sky.\n"+REV_PURPLE+"Jimi's guitar SCREEECHES!!!.\n"+OFF);
}
