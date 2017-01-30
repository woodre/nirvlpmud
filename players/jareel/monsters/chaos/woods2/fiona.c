#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"

inherit "obj/monster.c";
#define THUNDER "\nFiona calls for the power of the "+HIB+"S"+HIW+"*"+HIB+"T"+HIW+"*"+HIB+"O"+HIW+"*"+HIB+"R"+HIW+"*"+HIB+"M"+NORM+"...\n"
#define CLAP1 "              "+HIY+"T"+HIB+"*"+HIY+"H"+HIB+"*"+HIY+"U"+HIB+"*"+HIY+"N"+HIB+"*"+HIY+"D"+HIB+"*"+HIY+"E"+HIB+"*"+HIY+"R "+NORM+"rumbles over head!!!\n"
#define CLAP2 "                                A Sonic blast erupts into you!!!!!!\n"
#define CLAP3 "                                A Sonic blast erupts into #TN#!!!!!!\n"
#define NAME "Fiona - "+HIB+"Rune Lord Priest"+NORM+" of Orlanth Thunderous."+NORM
#define LIGHTNING HIB+"              L"+HIY+"*"+HIB+"I"+HIY+"*"+HIB+"G"+HIY+"*"+HIB+"H"+HIY+"*"+HIB+"T"+HIY+"*"+HIB+"N"+HIY+"*"+HIB+"I"+HIY+"*"+HIB+"N"+HIY+"*"+HIB+"G "+NORM+"leaps from Fiona's bracers!!!\n"
#define CLAP4 "                                The bolt leaps into you!!!!!!!!!!!!\n"
#define CLAP5 "                                The bolt of lightning leaps into #TN#!!!!!!!!!!!!\n"
#define THLI HIY+"                              T"+HIB+"*"+HIY+"H"+HIB+"*"+HIY+"U"+HIB+"*"+HIY+"N"+HIB+"*"+HIY+"D"+HIB+"*"+HIY+"E"+HIB+"*"+HIY+"R"+NORM+" and\n" 
#define THLI1 HIB+"                                  L"+HIY+"*"+HIB+"I"+HIY+"*"+HIB+"G"+HIY+"*"+HIB+"H"+HIY+"*"+HIB+"T"+HIY+"*"+HIB+"N"+HIY+"*"+HIB+"I"+HIY+"*"+HIB+"N"+HIY+"*"+HIB+"G\n"
#define MAR"                                      "+NORM+"Crash down into you in a marriage of pain!!!!!!!!!!!!"

int stuff;
int sword;

reset(arg)  {

  string str;
  object gold;
  stuff = random(8);
    ::reset(arg);
  if(arg) return;

  set_name("fiona");
  set_alias("priestess");
  set_alt_name("lord");
  set_race("human");
  set_short(NAME);
  set_long(
    "The perfect visage of a warrior and a woman.  Fiona's form has no flaw\n"+
    "the curve of her form and grace of her stance show her a master of her art.\n"+
    "Fiona's armor seems to have a protective air swirling over it, granting\n"+
    "her great protection against attacks.  You feel she is a great warrior\n"+
    "feeling caution is the best course of action.\n");  
  set_level(22);
  set_hp(800);
  set_al(300);
  set_wc(50);
  set_ac(52);
  set_heal(10+(random(10)),1);
  set_aggressive(0);
  set_heart_beat(1);
  set_chat_chance(5);
    load_chat("Fiona holds her blade.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(3000) + 4000);
  move_object(gold,this_object());

  if(stuff == 0) { /* Amulet */ 
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_amulet.c"),this_object());
      init_command("wear amulet");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword"); 
    set_wc(50);    
  }

  if(stuff == 1){ /* Bracelet */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_bracelet.c"),this_object());
      init_command("wear bracelet");
    MOCO("/players/jareel/weapons/mondar_death_sword.c"),this_object());
      init_command("wield sword");
    set_wc(52+random(10));
  }

  if(stuff == 2){ /* Bracers */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_bracers.c"),this_object());
      init_command("wear bracelet");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");    
    set_wc(52);
  } 

  if(stuff == 3){ /* Earring */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_earring.c"),this_object());
      init_command("wear earring");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(52);
  }

  if(stuff == 4){ /* Plate */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_plate.c"),this_object());
      init_command("wear armor");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(52);
  }

  if(stuff == 5){ /* Shield */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_shield.c"),this_object());
      init_command("wear shield");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(52);
  }

  if(stuff == 6){ /* Vambraces (Pants) */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_vambraces.c"),this_object());
      init_command("wear vambraces");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(52);
  }

  if(stuff == 7){ /* Misc */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_wind.c"),this_object());
      init_command("wear wind");
    MOCO("/players/jareel/weapons/orlanth/fiona_sword.c"),this_object());
      init_command("wield sword");    
    set_wc(82+random(40));
  }

  add_spell(
    "thunderclap",""+THUNDER+CLAP1+CLAP2+"\n",
                  ""+THUNDER+CLAP3+"\n",
    20,90,"other|physical");

  add_spell(
    "lightningstrike",""+THUNDER+LIGHTNING+CLAP4+"\n",
          ""+THUNDER+CLAP5+"\n",
    20,90,"other|electricity");
 
 add_spell(
    "spirit","\n"+BOLD+"        An enraged Spirit slashes at you!\n"+NORM+"\n",
             "\n"+BOLD+"        An enraged Spirit slashes at #TN#.\n"+NORM+"\n",
    5,200,"other|spirit");

  add_spell(
    "thunderlightning",""+THUNDER+THLI+THLI1+MAR+"\n",
           ""+THUNDER+"\n",
    20,180,"other|electricity");

  set_dead_ob(this_object());
}

