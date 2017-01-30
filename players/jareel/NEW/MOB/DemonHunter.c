inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()
#define STAB BOLD+"Morgus's form blurs in a "+RED+"fury"+NORM+BOLD+" of blinding attacks"+NORM
#define THRUST BOLD+"Morgus thrusts his sword piercing flesh"+NORM

  int V;
  int sword;
  int necklace;
  int spear;
  int armor;

  reset(arg)  {
    ::reset(arg);
  if (arg) return;
  set_name("Morgus - "+RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"] "+BOLD+HIK+"Demon Hunter"+NORM+"  (Black Knight) ");
  set_alias("morgus");
  set_alt_name("hunter");
  set_race("human");
  set_al(-1000);
  set_level(25);
  set_aggressive(0);
  set_hp(3000);
  set_ac(19);
  set_heal(25,1);
 /*MOCO("/players/jareel/NEW/WEAPON/BladeOfLight.c"),this_object());
  init_command("wield sword");*/
  set_wc(50);
  /*
  WC BONUS
  WC = 50 Extra Attack
  Add Damage Spell 1 100 damage 25 of the time = 25 Average 
  Add Damage Spell 2 140 damage 50% of the time = 70 Average
  Spell 3 32 damage 25% of the time = 8
  Spell 4 108 Damage 25% of the time = 27
  */
  set_wc_bonus(182); 
  set_gender("male");
  add_money(2000+random(1000));
  set_dead_ob(this_object());
  set_short("Morgus - "+RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"] "+BOLD+HIK+"Demon Hunter"+NORM+"  (Black Knight) ");
  set_long(
      "Morgus is an old silver-haired, wrinkled, weathered warrior.  His battered armour has\n"+
      "has been slashed and gouged by what appears to be some huge claws.  Evil glowing eerie\n"+
      "haunting death rid-in soulless eyes pierce through your soul as his gaze catches you \n"+
      "looking at him.  Engaging this mere mortal may not be the wisest move one has ever made.\n");
  add_spell(
    "spear stab",STAB+"\n"+THRUST+"\n"+STAB+"\n",
    "\n",
  25,100,"other|physical");

  add_spell(
    "spear thrust",STAB+"\n"+STAB+"\n"+STAB+"\n"+THRUST+"\n"+STAB+"\n",
    "\n",
  50,140,"other|physical");
  set_chat_chance(2);
      load_chat("Morgus says:  I shall find the real '"+HIK+"Cacodeamon"+NORM+"' on the '"+HIR+"HeroPlane"+NORM+"' and Vanquish him for Ultimate Power!\n");
      load_chat("Morgus says:  We will vanquish all demons from this realm of Darkness with my "+HIY+"Blade"+NORM+" of "+HIY+"Light"+NORM+"!\n");
  }
  heart_beat(){
    object ob;
    object att;
    object next;
    if(!environment()) return;
      if(ob = present("guard", environment())) { if(ob->query_attack()) 
    attack_object(ob->query_attack()); } ;
      ::heart_beat();
    if(attacker_ob) {
      already_fight=0; /* Extra Attack x2 All Spells and Weapon Hits  Weapon has a special that triggers extra attack may be really bad*/
      V = random(3);
        if(attacker_ob){
        if(V == 1) V_stab();
      else if(V == 2) V_bladesharp();
    }
  }
}

  V_stab()  {
    tell_room(environment(TO),
      "Morgus slashes you with his sword.\n");
    call_other(attacker_ob,"hit_player",random(25)+12);
  return;
  }
  V_bladesharp() {
    tell_room(environment(TO),
      "Morgus unleashes solar energy....\n"+
      STAB+"\n"+STAB+"\n"+THRUST+"\n"+STAB+"\n");
     call_other(attacker_ob,"hit_player",random(86)+65);
  return;
  }