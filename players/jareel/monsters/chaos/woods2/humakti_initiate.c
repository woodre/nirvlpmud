inherit "obj/monster.c";
#include "/players/jareel/define.h"
reset(arg)  {
object gold,helmet,armor,spear;
  ::reset(arg);
  if(arg) return;

set_name("initiate");
set_alias("humakti");
set_alt_name("guard");
set_short("An Initiate of "+HIK+"Humakt"+NORM);
set_long(
        "The imposing figure standing before you bears the mark of\n"+
       "an initiate of Humakt .  Humakti are some of the most impressive\n"+
        "fighters in the realm.  With a hand on shaft of his sword the\n"+
        "initiate eyes you.\n" );
 if(!random(2)) set_gender("male"); else set_gender("female");
set_al(0);
set_race("human");
set_level(18);
set_hp(500);
MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
init_command("wield spear");
set_wc(30);
set_ac(17);
set_aggressive(0);
add_money(3500);
set_dead_ob(this_object());
set_chance(40);
set_spell_dam(50);
set_spell_mess1(
  "The initiate shoots forth a bolt of raw energy into its attacker.\n");
set_spell_mess2(
  "The initiate strikes you with the power of Truth and Death.\n" );
}

init() {
  ::init();
    add_action("nogo","west");
}

heart_beat(){
object ob;
object att;
object next;
if(!environment()) return;
if(ob = present("guard", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
::heart_beat();
}

nogo() {
    write("The initiate blocks your path.\n");
  return 1;
}