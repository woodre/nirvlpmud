#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"

inherit "obj/monster.c";
#define SEVER "\nKrista casts.....\n        "+HIK+"S=E=V=E=R  S=P=I=R=I=T"+NORM+"...\n"
#define SEVERP "              Your heart stops as you writhe in pain\n"
#define NAME "Krista - "+HIK+"Rune Sword"+NORM+" of Humakt."+NORM
#define SEVER2 "\nKrista casts.....\n        "+HIK+"S=E=V=E=R  S=P=I=R=I=T"+NORM+"...\n"
#define TRUESWORD HIY+"Rune magic flows"+NORM+" over Krista's sword...\n"
#define TRUESWORD2 "            Krista's sword strikes true into you"+NORM
#define TRUESWORD3 "Fiona's sword stikes True into #TN#"         
#define CRIT "Krista strikes a "+HIR+BLINK+"C R I T I C A L"+NORM+" hit on you."
#define CRIT2 "Krista strikes a "+HIR+BLINK+"C R I T I C A L"+NORM+" hit on #TN#."




int stuff;
int sword;

reset(arg)  {

  string str;
  object gold;
  stuff = random(8);
    ::reset(arg);
  if(arg) return;

  set_name("krista");
  set_alias("sword");
  set_alt_name("rune");
  set_race("human");
  set_short(NAME);
  set_long(
    "The perfect visage of a warrior and a woman.  Fiona's form has no flaw\n"+
    "the curve of her form and grace of her stance show her master of her art.\n"+
    "Fiona armor seems to have a protective air swirling over it granting\n"+
    "it user great protection against all forms of attack.  You feel this is a\n"+
    "great warrior and should approach her with caution.\n");  
  set_level(23);
  set_hp(1000);
  set_al(300);
  set_wc(70);
  set_ac(52);
  set_heal(10+(random(25)),1);
  set_aggressive(0);
  set_heart_beat(1);
  set_chat_chance(5);
    load_chat("Krista prays to her god.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(5000) + 5000);
  move_object(gold,this_object());

  if(stuff == 0) { /* Amulet */ 
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_amulet.c"),this_object());
      init_command("wear amulet");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword"); 
    set_wc(70);    
  }

  if(stuff == 1){ /* Bracelet */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_bracelet.c"),this_object());
      init_command("wear bracelet");
    MOCO("/players/jareel/weapons/mondar_death_sword.c"),this_object());
      init_command("wield sword");
    set_wc(70+random(10));
  }

  if(stuff == 2){ /* Bracers */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_bracers.c"),this_object());
      init_command("wear bracelet");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");    
    set_wc(70);
  } 

  if(stuff == 3){ /* Earring */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_earring.c"),this_object());
      init_command("wear earring");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(70);
  }

  if(stuff == 4){ /* Plate */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_plate.c"),this_object());
      init_command("wear armor");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(70);
  }

  if(stuff == 5){ /* Shield */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_shield.c"),this_object());
      init_command("wear shield");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(70);
  }

  if(stuff == 6){ /* Vambraces (Pants) */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/chaos/woods2/orlanth_vambraces.c"),this_object());
      init_command("wear vambraces");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
    set_wc(70);
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
    "severspirit",""+SEVER+SEVERP+"\n",
                  ""+SEVER2+"\n",
  6,350,"other|magical");

  add_spell(
    "truesword",""+TRUESWORD+TRUESWORD2+"\n",
          ""+TRUESWORD3+"\n",
  25,100,"other|good");
 
  add_spell(
    "spirit","\n"+BOLD+"        An enraged Spirit slashes at you!\n"+NORM+"\n",
             "\n"+BOLD+"        An enraged Spirit slashes at #TN#.\n"+NORM+"\n",
  20,200,"other|spirit");

  add_spell(
    "crit",""+CRIT+"\n",
           ""+CRIT2+"\n",
  25,180,"other|Jareel");

  set_dead_ob(this_object());
}

