inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("jim jupiter");
MOCO("/players/jenny/bundy/items/tot.c"),this_object());
MOCO("/players/jenny/bundy/items/bon.c"),this_object());
    set_alt_name("jim");
    set_alias("jupiter");
    set_race("human");
    set_al(60);
    set_level(20);
    set_hp(525);
    set_wc(31);
    set_ac(18);
    set_gender("male");
    set_short(""+RED+"Jim Jupiter"+NORM+"");
    set_long(
      "Jim Jupiter, aka 'the healthiest man in Chicago', spent a week\n"+
      "in the Bundy home to try and get Peg into shape.  Instead, she\n"+
     "turned him into a couch potato who watches Oprah and eats bonbons\n");

set_chat_chance(19);
    load_chat(""+RED+"Jim says: "+NORM+" Hi!  I'm Jim Jupiter.  The healthiest man in Chicago."+NORM+"\n");
}
