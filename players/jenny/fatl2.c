inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("fat lady");
    set_alt_name("lady");
    set_alias("woman");
    set_race("human");
    set_al(-300);
    set_level(15);
    set_hp(330+random(50));
    set_ac(13);
    set_wc(17);
    set_gender("female");
   set_armor_params("other|electric",2000,0,0);
    set_short(""+WHT+"A fat lady"+NORM+"");
    set_long(
      "This is one of the many fat ladies who seem to exist for the\n"+
      "sole purpose of making Al's life a living hell.  She is very\n"+
      "large, unattractive, and is wearing an ugly flowered dress.\n");
MOCO("/players/jenny/bundy/items/purse.c"),this_object());
set_chat_chance(12);
    load_chat(""+YEL+"The fat lady says: "+NORM+" I'm telling you!  I wear a size 6"+NORM+"\n");
}
init() {
  ::init();
add_action("stop","east");
}
stop() {
if(TP->query_exp() > 295000 && TP->query_level() < 20) {
write(""+BOLD+""+RED+"The fat lady is blocking your path."+NORM+"\n");
return 1; }
}
