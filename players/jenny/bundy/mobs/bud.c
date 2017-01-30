inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("bud bundy");
    set_alt_name("bud");
set_alias("bundy");
set_race("human");
    set_level(15);
    set_wc(18+random(5));
MOCO("/players/jenny/bundy/items/bhat.c"),this_object());
init_command("wear hat");
    set_ac(10+random(3));
    set_hp(200+random(50));
    set_al(101);
    set_gender("male");
    set_short(""+GRN+"Bud Bundy"+NORM+"");
    set_long(
      "Bud is the Bundy's hormone driven son.  He is short, ugly, and\n"+
      "and poor.  This does not help him with the ladys.  He is smart\n"+
     "though.  Bud once was awarded a scholarship, but Al and Peg\n"+
     "blew his scholarship money on themselves.\n");
set_chat_chance(25);
    load_chat(""+RED+"Bud says: "+NORM+" You can just call me Grandmaster B"+NORM+"\n");

}
