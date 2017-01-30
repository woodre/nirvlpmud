/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=6500+random(2000);
    move_object(clone_object("/players/humble/area1/objs/boxcutter.c"));
    init_command("wield boxcutter");
     set_name(MAG+"Toddles"+NORM);
    set_alt_name("toddles");
    set_alias("toddles");
    set_short(MAG+"Toddles"+NORM);
    set_race("human");
    set_long(
    "Toddles is a skinny man who towers over you.  He must be at least 6'3. He dons\n"+
    "glasses and a short hair-cut.  He doesn't say much but his crooked smile\n"+
    "begins to scare you. He is in charge of the grocery store's night crew.\n");
    set_gender("male");
    set_level(23);
    set_ac(25);
    set_wc(30+random(10));
    set_hp(950+random(550));
    set_al(350);
    set_multi_cast(0);
    add_spell("pallet stomp",
    HIY+"Toddles pulls a pallet jack out of nowhere and runs you over!\n"+NORM+
    YEL+"  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @\n"+NORM+
    YEL+"          @ @ @ @ @ @   !!!!!   @ @ @ @ @ \n"+NORM+
    YEL+"          @ @ @ @ @ @   !!!!!   @ @ @ @ @ \n"+NORM+
    YEL+"  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @\n"+NORM,
    HIW+"Toddles flies out of nowhere atop a pallet jack and rides over #TN#!\n"+NORM,
   15,80,"physical");

    add_spell("aisle stomp",
    MAG+"Toddles throws you down in the middle of the aisle and quickly shuffles\n"+NORM+
    MAG+"his feet about your head, yuck your biting the bottom of an aisle...ooohhh\n"+NORM+
    HIR+"    B L O O D    G U S H E S   O U T   Y O U R   E A R S !\n"+NORM+
    MAG+"as Toddles curb stomps your ass in the middle of the aisle.\n"+NORM,
    HIW+"Toddles drops his opponent to the ground and stomps #TN# head in!\n"+NORM,
    10,80,"physical");
    }
}
