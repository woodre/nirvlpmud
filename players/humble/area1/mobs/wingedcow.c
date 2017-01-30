/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=5000+random(5000);
    set_name(HIY+"Moo Cow"+NORM);
    set_alt_name("moo cow");
    set_alias("moo cow");
    set_short(HIC+"W "+HIR+"  i"+HIC+" n"+HIR+" g"+HIC+" e"+HIR+" d"+HIY+"  M O O  C O W"+RED+" ( B e l l i g e r e n t ) "+NORM); 
    set_race("cow");
    set_long(
   HIW+"This is a giant winged moo cow. It looks like a voilent cow, perhaps\n"+NORM+
    HIW+"it had a rough childhood.  It's feasting upon the dairy backstock, boy\n"+NORM+
    HIW+" Debbie would be pissed! It's wings are a sparkling white and blue.\n"+NORM+
    HIW+"The cow's eyes are bloodshot, what a filthy beast.\n"+NORM);
    set_gender("male");
    set_level(28);
    set_ac(28+random(8));
    set_wc(45+random(5));
    set_hp(1800+random(300));
    set_al(350);
    set_multi_cast(1);
    add_spell("headbutt",
    RED+"The Winged MOO COW lowers it's head and charges you.....\n"+NORM+
     RED+"----------------->     B  A  M     <--------------------\n"+NORM+
    RED+"You fall backwards onto a box of milk covering yourself in smelly dairy.\n",
    "#MP#"+HIW+" lowers it's head and charges #TP#.\n"+NORM,
    20,20,"physical");

    add_spell("flutter",
    "#MN#"+HIW+" spreads it's wings...\n"+NORM+
    HIC+"                       @ @ @ @ @@ @ @ @ @\n"+NORM+
    HIC+"                             @ @ @ @ @ @ @ @\n"+NORM+
    HIC+"                                   @ @ @ @ @ @\n"+NORM+
    HIC+"                                         @ @ @ @\n"+NORM+
    HIC+"                                               @ @\n"+NORM+
    HIC+"                                                  @\n"+NORM,
    HIC+"The Winged Moo Cow begins to flutter it's wings....\n"+NORM+
    HIC+"A strong gust freezes you in your place.\n"+NORM,
    10,80,"other|wind");
    }
}
