inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("kelly bundy");
    set_alt_name("kelly");
MOCO("/players/jenny/bundy/items/kellywep.c"),this_object());
init_command("wield equipment");
set_alias("bundy");
    set_race("human");
    set_level(19);
    set_hp(850);
set_wc(15);
set_frog(1);
    set_aggressive(1);
    set_ac(21);
    set_al(510);
    set_gender("female");
    set_short(""+YEL+"Kelly Bundy"+NORM+"");
    set_long(
      "Kelly is the Bundy's promiscuous daughter.  She is very attractive,\n"+
      "but not too bright.  She dreams about one day becoming an actress.\n"+
     "Maybe she wouldn't mind if you gave her a kiss.\n");
     
set_chat_chance(16);
load_chat(""+MAG+"Kelly smiles at you and winks."+NORM+"\n");
set_dead_ob(this_object());
}
monster_died() { 
move_object(clone_object("/players/jenny/bundy/mobs/buck.c"),this_object());
return 0;
}
