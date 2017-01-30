#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"

inherit "obj/monster.c";
#define SEVER "\nTyric invokes.....\n        "+HIK+"D E A T H"+NORM+"...\n"
#define SEVERP "              Your heart stops as you writhe in pain\n"
#define NAME "Tyric - "+HIK+"Rune Sword"+NORM+" of Humakt."+NORM
#define SEVER2 "\nTyric casts.....\n        "+HIK+"D E A T H"+NORM+"...\n"
#define TRUESWORD HIY+"Rune magic flows"+NORM+" over Tyric's sword...\n"
#define TRUESWORD2 "            Tyric's sword strikes true into you"+NORM
#define TRUESWORD3 "Tyric's sword stikes True into #TN#"         
#define CRIT "Tyric strikes a "+HIR+BLINK+"C R I T I C A L"+NORM+" low gashing flesh."
#define CRIT2 "Tyric strikes a "+HIR+BLINK+"C R I T I C A L"+NORM+" blow gashing #TN#."


int stuff;
int sword;

reset(arg)  {

  string str;
  object gold;
  stuff = random(2);
    ::reset(arg);
  if(arg) return;

  set_name("tyric");
  set_alias("runesword");
  set_alt_name("sword");
  set_race("human");
  set_short(NAME);
  set_long(
    "An imposing looking man.  His gaze is unyielding.  His stance is firm.\n"+
    "The ancient armor he wears looks molding to his form moving with his\n"+
    "every movement.  A dark silver truth rune hangs on a necklace around his\n"+
    "thick neck. You wonder if this is a fight worth fighting.\n");  
  set_level(22);
  set_hp(800);
  set_al(0);
  set_wc(42);
  set_ac(32);
  set_heal(10+(random(10)),1);
  set_aggressive(0);
  set_heart_beat(1);
  set_chat_chance(5);
    load_chat("Tyric peers at you from under this helmet.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(6000) + 4000);
  move_object(gold,this_object());

  if(stuff == 0) { /* Necklace */ 
    MOCO("/players/jareel/general_stuff/tyrics_bag.c"),this_object());
    MOCO("/players/jareel/armor/humakt/humakt_necklace.c"),this_object());
      init_command("wear necklace");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword"); 
    set_wc(42);    
  }

  if(stuff == 1) { /* Necklace */ 
    MOCO("/players/jareel/general_stuff/tyrics_bag.c"),this_object());
    MOCO("/players/jareel/weapons/chaos/woods2/humakt_sword.c"),this_object());
      init_command("wield sword");
    set_wc(42);    
  }


  add_spell(
    "severspirit",""+SEVER+SEVERP+"\n",
                  ""+SEVER2+"\n",
  2,250,"other|magical");

  add_spell(
    "truesword",""+TRUESWORD+TRUESWORD2+"\n",
          ""+TRUESWORD3+"\n",
  10,50,"other|good");
 
  add_spell(
    "spirit","\n"+BOLD+"        An enraged Spirit slashes at you!\n"+NORM+"\n",
             "\n"+BOLD+"        An enraged Spirit slashes at #TN#.\n"+NORM+"\n",
  10,200,"other|spirit");

  add_spell(
    "crit",""+CRIT+"\n",
           ""+CRIT2+"\n",
  40,50,"other|Jareel");


  set_dead_ob(this_object());
}

