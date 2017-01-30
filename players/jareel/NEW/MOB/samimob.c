inherit "/obj/monster.c";
#include "/players/fred/ansi.h";

#define tpn this_player()->query_name()  /* tpn is usualy all caps for Defs */
#define ATT USER->query_attack()


reset(arg) {
  ::reset(arg);
  if(arg) return;
        
  set_name("emperor");
  set_race("imortal");
  set_short(""+HIB+"E"+HIR+"mperor"+NORM+" of "+HIB+"C"+HIR+"haos"+NORM);
  set_long(
    "  Long"+HIB+" black"+NORM+" hair drapes down to this mans waist. A\n"+
    "long scar runs down the side of his face directly below his eye.\n"+
    "There is a Ensignia of the royal house of Madness upon his chest.\n");
  add_money(8000+random(6000));
  set_level(29);
  set_hp(2000+random(150));
  set_hp_bonus(2000);
  set_al(-800);
  set_heal(5,10); /* This heals 5 every 10 Rounds */
  set_ac(28+random(4));
  set_wc(55);
  set_aggressive(0);
  set_multi_cast(1);
  
  add_spell("flames_of_eternity",
    ""+HIB+"Blue flames"+NORM+" Erupt and engulf you in a whirlind of FURY!\n",
    "#MN# raises his staff high and summons blue flames from the pillar!\n",
  50,({35,35}),({"other|fire","other|evil"}),1);
  
  add_spell("Fatal_darkness",
    ""+HIB+"D A R K N E S S"+NORM+" appears to pour out of every pour into the room.\n",
    "#MN# raises his staff high and summons concentrated"+HIY+"C H A O S"+NORM+". \n",
  50,({35,35}),({"other|energy","other|evil"}),2);
  
  add_spell("Heal_spell",
    ""+HIB+"E"+HIR+"mperor"+NORM+" takes a Potion of "+HIR+"Healing"+NORM+" out of the "+HIK+"V O I D"+NORM+".\n\
    "+HIB+"E"+HIR+"mperor"+NORM+" Drinks the "+HIR+"Potion"+NORM+".\n\
    "+HIB+"E"+HIR+"mperor"+NORM+" Drinks the "+HIR+"Potion"+NORM+".\n\
    "+HIB+"E"+HIR+"mperor"+NORM+" Drinks the "+HIR+"Potion"+NORM+".\n",
    ""+HIB+"E"+HIR+"mperor"+NORM+" takes a Potion of "+HIR+"Healing"+NORM+" out of the "+HIK+"V O I D"+NORM+".\n\
    "+HIB+"E"+HIR+"mperor"+NORM+" Drinks the "+HIR+"Potion"+NORM+".\n\
    "+HIB+"E"+HIR+"mperor"+NORM+" Drinks the "+HIR+"Potion"+NORM+"\n\
    "+HIB+"E"+HIR+"mperor"+NORM+" Drinks the "+HIR+"Potion"+NORM+"\n",
  30,"20-30",0,3,"heal_me");
 }

     heart_beat() {
  object       ob;
  ::heart_beat();

  if(!attacker_ob) {
    return;
  }}

heal_me( object target, object room, int damage ) {
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
heal_self(25+random(26));
}
 