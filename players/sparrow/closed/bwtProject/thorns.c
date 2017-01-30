#include <ansi.h>
inherit "obj/weapon.c";
inherit "/players/sparrow/closed/bwtProject/bwtPowers.c";
int bwtLevel, bwtExperience, bwtPower bwtTrainableExp, bwtCombatXpStart, bwtCombatXpStop, bwtBaseWc;

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("thorns");
set_alias("thorns of the black willow");
set_short(HIK+"T"+NORM+MAG+"horns of the "+HIK+"B"+NORM+MAG+"lack "+HIK+"W"+NORM+MAG+"illow"+NORM);
set_long("Thorns of the Black Willow. Beta weapon of Sparrow.\n");
set_hit_func(this_object());
set_type("whip");  
set_class(20);
set_weight(1);
set_value(2000);
set_two_handed_wep(1);
set_no_break(1);
message_hit = ({
  HIR+"hacked"+NORM," into a bloody, squirming mess on the floor",
  RED+"sliced"+NORM, " with a critical strike",
  RED+"diced"+NORM, " into tiny, pathetic little pieces",
  HIW+"pierced"+NORM, " deeply, causing great pain",
  HIW+"chopped"+NORM, " with a mad surgeon's grace",
  "slapped", " viciously with the flat of the blade",
  "cut", " lightly across the chest"
  });
  }


weapon_hit(ob){
int lev, xlev, hp, sp, mhp, msp, num, dam1;
  string loc, severity, action;
  object me, att, ATT;
  me = USER;
  lev = me->query_level();
  xlev = me->query_extra_level();
  att = ob;
  if(!bwtCombatXpStart) {
    bwtCombatXpStart = environment(this_object())->query_exp();
  }
  bwtCombatXpStop = environment(this_object())->query_exp();
  bwtTrainableExp += (bwtCombatXpStop - bwtCombatXpStart);
  return 0;  
}   
     
void
set_bwtExperience(int x) {
  bwtExperience = x;
}

void
set_bwtLevel(int x) {
  bwtLevel = x;
}

void
set_bwtPower(int x) {
  bwtPower = x;
}

int
query_bwtExperience() {
  if(!bwtExperience) {
    set_bwtExperience(0);
  }
  return bwtExperience;
}

int
query_bwtLevel() {
  if(!bwtLevel) {
    set_bwtLevel(1);
  }
  return bwtLevel;
}

int
query_bwtPower() {
  if(!bwtPower) {
    set_bwtPower(0);
  }
  return bwtPower;
}

int
add_bwtExperience(int x) {
  bwtExperience += x;
  return bwtExperience;
}

int
add_bwtLevel(int x) {
  bwtLevel += x;
  return bwtLevel;
}

int
add_bwtPower(int x) {
  bwtPower += x;
  if(bwtPower > (query_bwtLevel* 55)) {
    bwtPower = query_bwtLevel * 55;
  }
  return bwtPower;
}

int
query_bwtNextLevel() {
  int currentLevel;
  int *levelTable;
  levelTable = ({0,125000, 300000, 550000, 900000, 1400000, 2100000,
    3000000,4000000,5000000,6000000,7000000,8000000,9000000,10000000,
    12000000,14000000,16000000,18000000,20000000
  })
  currentLevel = this_object()->query_bwtLevel();
  return levelTable[currentLevel];  
}

int
wield(str) {
  ::wield(str);
  bwtCombatXpStart = environment(this_object())->query_exp();
  return 1;
}

int
stopwield() {
  ::stopwield();
  if(!bwtCombatXpStart) {
    return 1;
  }
  bwtCombatXpStop = environment(this_object())->query_exp();
  bwtTrainableExp += (bwtCombatXpStop - bwtCombatXpStart);
  return 1;
}

int
un_wield() {
  ::un_wield();
  if(!bwtCombatXpStart) {
    return 1;
  }
  bwtCombatXpStop = environment(this_object())->query_exp();
  bwtTrainableExp += (bwtCombatXpStop - bwtCombatXpStart);
  return 1;
}

get() { 
  if(this_player())
  if(this_player()->query_real_name() != "wulfgar" && TP->query_level() < 20) {
    write("You are unable to grasp such a powerful artifact!\n");
    return 0;
  }
  return 1;
}

