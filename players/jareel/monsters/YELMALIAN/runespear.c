inherit "obj/monster.c";
#include "/players/jareel/define.h"

reset(arg)  {
object gold,helmet,armor,spear;
  ::reset(arg);
  if(arg) return;

  set_name("Whelm - "+HIY+"Y"+NORM+BOLD+"elmalian "+HIY+"R"+NORM+BOLD+"unespear"+NORM);
  set_alias("runespear");
  set_alt_name("whelm");
  set_short("Whelm - "+HIY+"Y"+NORM+BOLD+"elmalian "+HIY+"R"+NORM+BOLD+"unespear"+NORM);
  set_long(
    "The imposing figure standing before you bears the mark of the\n"+
    "Yelmalian Runespear.  Legend has it the Runeshields are some\n"+
    "of the most impressive fighters in the realm.  With a hand on\n"+
    "the shaft of a glowing yellow spear the guard eyes you.\n" );
  if(!random(2)) set_gender("male"); else set_gender("female");

  set_al((500-random(1000)));
  set_race("human");
  set_level(20);
  set_hp(500);

  MOCO("/players/jareel/weapons/yelmalian_elite_spear.c"),this_object());
    init_command("wield spear");
  MOCO("/players/jareel/armor/yelmalian/runeshield.c"),this_object());
    init_command("wear shield");
  set_wc(50);
  set_ac(27);
  set_aggressive(0);
  add_money(1500);
  set_dead_ob(this_object());
  set_chance(40);
    set_spell_dam(50);
      set_spell_mess1(
        "The guard shoots forth a bolt of raw energy into its attacker.\n");
      set_spell_mess2(
        "The guard flashes a bolt of......\n"+
        "\n"+
        ""+BOLD+YEL+"  P   O   W   E   R !  !  !  !  !\n"+
        "\n"+
        ""+NORM+"              burning you with solar energy.\n" );
  }

  heart_beat(){
    object ob;
    object att;
    object next;
      if(!environment()) return;
      if(ob = present("guard", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
    ::heart_beat();
  }
