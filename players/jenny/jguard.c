inherit "obj/monster.c";
#include "/players/jareel/define.h"
reset(arg)  {
object gold,helmet,shield,armor,sword;
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_alias("elite");
set_alt_name("guard");
set_short("A "+BOLD+YEL+"Yelmalian "+NORM+BOLD+"[ "+BLU+"Elite "+NORM+BOLD+"] "+NORM+"Guard");
set_long(
        "The imposing figure standing before you bearing the mark of\n"+
        "the Yelmalian Elite Guard.  Legend has it the Guard are some\n"+
        "of the most impressive fighters in the realm.  Holding his hand\n"+
        "on the hilt of a glowing yellow sword the guard eyes you.\n" );
 if(!random(2)) set_gender("male"); else set_gender("female");
 set_al((1000-random(2000)));
set_race("human");
set_level(20);
set_hp(500);
MOCO("/players/jareel/weapons/yelmalian_elite_sword.c"),this_object());
init_command("wield sword");
MOCO("/players/jareel/armor/yelmalian_elite_armor.c"),this_object());
init_command("wear armor");
MOCO("/players/jareel/armor/yelmalian_elite_shield.c"),this_object());
init_command("wear shield");
MOCO("/players/jareel/armor/yelmalian_elite_helm.c"),this_object());
init_command("wear helm");
set_wc(30);
set_ac(17);
set_aggressive(0);
add_money(1000);
set_dead_ob(this_object());
set_chance(40);
set_spell_dam(50);
set_spell_mess1(
  "The guard shoots forth a bolt of raw energy into its attacker.\n");
set_spell_mess2(
  "The guard flashes a bolt of......\n"+
  "\n"+
  ""+BOLD+YEL+"                    P   O   W   E   R !  !  !  !  !\n"+
  "\n"+
  ""+NORM+"                                                                burning you with solar energy.\n" );
}

heart_beat(){
object ob;
object att;
object next;
heart_beat() {
if(!environment()) return;
if(ob = present("guard", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
::heart_beat();
}
}
