/* **********************************************************************
* Party of the Troll race, Parnish is a very powerfull Shaman.
* As a Shaman he has not developed his combat skills to any
* real extent, but his spiritual power is not to be taken
* lightly.
*
* Parnish Summons a Large Monster (His Fetch) this Monster
* Is a very large Monster That will be immune to Physical
* Damage (Or Nearly Immune) It will Also cause a huge amount
* of Spirit(Type) damage.  This is like wizard damage but
* there will be wards in this area that will help protect 
* players from being unprotected from this damage type.
********************************************************************** */

#include "/players/jareel/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

  int a;
  int b;
     
  reset(arg)  {

  a = 3600;
  b = 3600;

    ::reset(arg);
  if(arg) return;

  set_name("Parnish");
  set_alias("darn");
  set_race("troll");
  set_alt_name("keeper");
  set_short("Parnish Darn");
  set_long(
    "Parnish Darn is a large troll.  The spiritual aura of a\n"+
    "very powerfull Shaman looms around him.  His eyes are like\n"+
    "narrow slits, looking at past a helmet face guard.\n");
  set_level(10);
  set_hp(450);
  set_al(0);
  set_wc(14);
  set_ac(8);
  set_heal(15,1);
  set_dead_ob(this_object());
  add_money(400);
  set_chat_chance(2);
    load_chat("Parnish Darn says: 'You want to buy some '"+HIR+"reds"+NORM+"'?' \n");
    load_chat("Parnish Darn says: 'You want to buy some '"+HIB+"blues"+NORM+"'?'\n");
  }

  heart_beat(){
    ::heart_beat();
  if(attacker_ob) 
  set_assist("/players/jareel/monsters/chaos/caves/fetch", 1, 1, 1);  
  }

  init() { 
    ::init(); 
  add_action("heals","buy");
  }


heals(arg) {
  if(!arg) { return 0; }
  if(arg == "1" || arg == "reds") {
  if(!this_player()->add_weight(1)) {
    write("You are unable to carry this, lighten your load.\n");
    return 1; }
  if(this_player()->query_money() < a) {
    write("Your need more money.\n");
    return 1; }
    TP->add_money(-a);
    write("Parnish Darn hands you a focused form of energy.\n");
    say(TPN+" buys energy from Parnish Darn.\n");
    MOCO("/players/jareel/heals/redspiritstore.c"),TP);
    return 1; }
       
  if(arg == "2" || arg == "blues") {
  if(!this_player()->add_weight(1)) {
    write("You are unable to carry this, lighten your load.\n");
    return 1; }
  if(this_player()->query_money() < b) {
    write("Your need more money.\n");
    return 1; }
    TP->add_money(-b);
    write("Parnish Darn hands you a swirling ball of energy.\n");
    say(TPN+" buys energy from Parnish Darn.\n");
    MOCO("/players/jareel/heals/bluespiritstore.c"),TP);
    return 1; }
}
