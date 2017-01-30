#include <ansi.h>
inherit "obj/weapon.c";
inherit "/players/sparrow/closed/bwtProject/bwtPowers.c";
int bwtLevel, bwtExperience, bwtPower;

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("thorns");
set_alias("thorns of the black willow");
set_short(HIK+"T"+NORM+MAG+"horns of the "+HIK+"B"+NORM+MAG+"lack "+HIK+"W"+NORM+MAG+"illow"+NORM);
set_long("Thorns of the Black Willow. Beta weapon of Sparrow.\n");
set_hit_func(this_object());
set_type("exotic");  
set_class(20);
set_weight(1);
set_value(2000);
set_two_handed_wep(1);
set_no_break(1);
add_special_fun("/players/sparrow/closed/powers/speed.c");
add_special_fun("/players/sparrow/closed/powers/life.c");
add_special_fun("/players/sparrow/closed/powers/cleansing.c");
add_special_fun("/players/sparrow/closed/powers/disease.c");
add_special_fun("/players/sparrow/closed/powers/mana.c");
add_special_fun("/players/sparrow/closed/powers/evil.c");
 
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
  if(lev < 10) {
    return 0;
  }
  
  if(random(100) > 30){
    switch(random(10) + 1){
      case 10:   
        loc = "head";  
        dam1 = random(10) + 5;  
        break; 
      case 6..9: 
        loc = "chest"; 
        dam1 = random(7) + 4;   
        break; 
      case 3..5: 
        loc = "arm";   
        dam1 = random(5) + 3;   
        break; 
      case 1..2: 
        loc = "leg";   
        dam1 = random(3) + 3;   
        break; 
      default:   
        loc = "head";  
        dam1 = random(10) + 5;   
    }
    switch(random(10)) {
      case 9:
        severity = HBRED+"SLAUGHTERS"+NORM;
        dam1 = dam1 + 4;
        break;
      case 5..8:
        severity = HIR+"MAIMS"+NORM;
        dam1 = dam1 + 2;
        break;
      case 2..4:
        severity = RED+"destroys"+NORM;
        dam1 = dam1 + 1;
        break;
      default:
        severity = "punishes";
    }
    switch(random(7)) {
      case 0:
        action = "with a viscious stab to the";
        break;
      case 1:
        action = "with a clean slash to the";
        break;
      case 2:
        action = "with a deadly strike to the";
        break;
      case 3:
        action = "with a suprise strike to the";
        break;
      case 4:
        action = "with a brutal combination to the";
        break;
      case 5:
        action = "with a series of slashes to the";
        break;
      default:
        action = "with a focused attack to the";
    }
    
    tell_room(environment(USER),
    capitalize(USER->query_name())+" "+severity+" "+att->query_name()+" "+action+" "+loc+"!\n");
    return dam1;
  }
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
  return bwtExperience;
}

int
query_bwtLevel() {
  return bwtLevel;
}

int
query_bwtPower() {
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
get(){ 
if(this_player())
if(this_player()->query_real_name() != "wulfgar" && TP->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}

