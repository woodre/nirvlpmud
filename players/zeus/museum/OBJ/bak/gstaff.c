/*  every spell has a 1:6 chance of doing almost no damage 
    lowered wc from 18 to 16 (thematic), storable, saves charges.
    raised weight from 2 to 4
*/

inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define M tell_object(environment(),
#define T tell_room(environment(environment()),
#define N capitalize((string)environment()->query_real_name())
#define P environment()->query_possessive()
#define X target->query_name()
#define XP target->query_possessive() /* his */
int charge, damage, x, z, a;
string *ms, *fs;
object target;

reset(arg) {
   ::reset(arg);
   if (arg) return;

   a = 0;
   charge = 55 + random(26);
   set_name("staff");
   set_short("The Staff of Granite");
   set_alias("staff");
   set_long(
"This is the legendary staff of granite.  The handle is crafted from a\n"+
"very dark wood that spirals all along it.  At the top a strangely curved\n"+
"piece of granite is wrapped in the dark wood.  A black gem is embedded\n"+
"in the front of the piece of granite.  There is an engraving on the top\n"+
"of the staff.\n");
   set_class(16);
   set_type("staff");
   set_weight(4);
   set_value(7000);
   set_read(
	   "There is a 'pillar' of granite engraved on the top of the staff.\n");
   set_hit_func(this_object());
}

void init(){
  ::init();
  add_action("special", "pillar");
}

status special(string str){
  string str1,str2,str3;
  if(TP->query_ghost()) return 0;
  if(!present(this_object(), this_player())) return 0;
  if(!charge)
  { 
    write("The staff is out of charges.\n"); 
    return 1; 
  }
  if(TP->query_spell_dam()) return 1;
  if(!str && TP->query_attack())
    target = (object)TP->query_attack();
  else if(str)
    target = present(str, environment(TP));
  else if(!str && !TP->query_attack()) return 0;
  if(!target)
  { 
    tell_object(TP, "There is no "+str+" here.\n");
    return 1;
  }
  if(!target->is_npc()){
    tell_object(TP, "You cannot attack "+str+"!\n");
    return 1;
  }
  damage = random(30) + 15;
  if(damage < 20)
  {
	  str1 = "\tYou point the staff at "+X+"...\n"+
		  "\tThe ground shakes beneath your feet.\n";
	  str2 = "\tThe ground shakes beneath your feet.\n";
	  str3 = "\tThe ground shakes beneath your feet.\n";
	  damage = random(5);
  }
  else if(damage < 30)
  {
    str1 = "\tYou point the staff at "+X+"...\n"+
      "\tA pillar of granite rips from the ground beneath "+X+".\n\t"+
      X+" is knocked off "+XP+" feet.\n";
    str2 = "A pillar of granite rips from the ground benearth you.\n\t"+
      "\tYou are knocked off your feet.\n";
    str3 = "\tA pillar of granite rips from the ground beneath "+X+".\n\t"+
      X+" is knocked off "+XP+" feet.\n";
  }
  else 
  {
    str1 = "\tYou point the staff at "+X+"...\n"+
      "\tA pillar of granite explodes around "+X+".\n\t"+
      X+" is impaled by the pillar of granite!\n";
    str2 = "\tA pillar of granite explodes around you.\n"+
      "\tYou are impaled by the pillar of granite!\n";
    str3 = "\tA pillar of granite explodes around "+X+".\n\t"+
      X+" is impaled by the pillar of granite!\n";
  }
  TP->spell_object(target, "rock", damage, 0, str1, str2, str3);
  if(TP->query_level() < 6)
  {
    write(RED+"The staff burns your hand!\n"+NORM);
    TO->drop();
    TP->heal_self(-random(200));
    TP->hit_player(5);
  }
  charge -= 1;
  return 1;
}

def(object y){
   ms =({ "in an arc", "in a circular motion", "up and down",
          "back and forth", "quickly downwards", "in a star shape", 
          "in a spiral", "in a zig zag" });
   fs =({ BOLD+BLK+"The ground trembles beneath "+y->QN+"'s feet!"+NORM,
          RED+"A massive crack opens beneath "+y->QN+"!"+NORM,
          HIR+"A fissure breaths fire upon "+y->QN+"!"+NORM,
          HIW+"A mountain of rock knocks "+y->QN+" over!"+NORM,
          BOLD+BLK+"A hail of stones pelt "+y->QN+"!"+NORM,
          RED+"A hail storm of stones nail "+y->QN+"!"+NORM,
          HIW+y->QN+" is driven back by a hail of stones!"+NORM,
          HIR+y->QN+" is suddenly crushed by a boulder!"+NORM
   });
}

int weapon_hit(object y){
  if(!a){ def(y); a = 1; }
  x = random(16);
  z = random(sizeof(ms));
  target = y;
  if(x < 4){
    M "You wave your staff "+ms[z]+"...\n\n\t\t"+fs[z]+"\n\n");
    T N+" waves "+P+" staff "+ms[z]+"...\n\n\t\t"+fs[z]+"\n\n", ({ ENV }));
    return 6;
  }
  if(x >= 8 && random(2)){
    switch(x){
    case 8:
      M "As you grasp your staff you feel the ground tremble.\n");
      T "You feel the ground tremble.\n", ({ ENV }));
      break;
    case 9:
      M BOLD+BLK+"Your staffs glows with an aura of power.\n"+NORM);
      T BOLD+BLK+N+"'s staff glows with an aura of power.\n"+NORM, ({ ENV }));
      break;
    case 10:
      M "You smack "+y->QN+" with your staff.\n");
      T N+" smacks "+y->QN+" with "+P+" staff.\n", ({ ENV }));
      break;
    case 11:
      M "You clunk "+y->QN+" on the head with your staff.\n");
      T N+" clunks "+y->QN+" on the head with "+P+" staff.\n", ({ ENV }));
      break;
    case 12:
      M "You swing your staff into "+y->QN+".\n");
      T N+" swings "+P+" staff into "+y->QN+".\n", ({ ENV }));
        break;
    case 13:
      M "You rub your staff causing it to grow slightly warmer.\n");
      T N+" rubs "+P+" staff causing it to grow slightly warmer.\n",
        ({ ENV }));
      break;
    case 14:
      M "You wave your staff about menacingly.\n");
      T N+" waves "+P+" staff about menacingly.\n", ({ ENV }));
      break;
    case 15:
      M "You tap your staff on the ground hoping for something to happen.\n");
      T N+" taps "+P+" staff on the ground hoping for something "+
        "to happen.\n", ({ ENV }));
      break;
      return 1;
    }
  }
}

generic_object(){    return 1; }
restore_thing(str){  restore_object(str); return 1; }
save_thing(str){     save_object(str);    return 1; }
locker_arg(){        return ""+charge; } 
locker_init(arg){    charge = atoi(arg); }
