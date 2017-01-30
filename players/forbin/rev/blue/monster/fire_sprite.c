#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/monster.c";

int Winked;

id(string str) { 
  if(Winked) 
    return (str == "FireSprite_gopoofy"); 
  else
    return (::id(str)); 
}

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Fire Sprite");
  set_alt_name("fire sprite");
  set_race("sprite");
  set_short("Fire Sprite");
  set_long(
    "This sprite is a thin creature with slender arms and legs.  It is\n"+
    "ringed in a bright fire and peers at you mischievously from dark\n"+
    "slitted eyes.  Only standing a few feet tall, the sprite hovers\n"+
    "several feet above the ground as flames dance about its feet.\n");
  set_level(5);
  set_hp(75);
  set_al(-200);
  set_wc(11);
  set_ac(5);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Fire Sprite flutters about...\n");
    load_chat("You feel warm as the Fire Sprite flies near you...\n");    
  set_a_chat_chance(20);
    load_a_chat("The Fire Sprite burns you...\n");
    load_a_chat("The Fire Sprite cries, \"Why are you hurting me?\"\n");    
    load_a_chat("The Fire Sprite yells, \"Leave me alone you big meanie!\"\n");    
  add_money(180+random(41));
  Winked = 0;  
}

short() {
  if(Winked)
    return 0;
  else
    return (random(2) ? HIY+"F"+HIR+"ire "+HIY+"S"+HIR+"prite"+NORM : HIR+"F"+HIY+"ire "+HIR+"S"+HIY+"prite"+NORM); 
}

void wink_out() {
  tell_room(environment(this_object()),
    "\n\n\t\t"+HIY+"POOF!"+NORM+"\n"+
    "There is a bright flash as the sprite disappears.\n"+
    "You hear a giggle echo through the room.\n");
  Winked = 1;
  call_out("wink_in", 480);
}

void wink_in() {
  tell_room(environment(this_object()),
    "A sprite giggles as it slowly fades into view.\n");
  Winked = 0;
}
  
heart_beat() {
  ::heart_beat();
  if(!environment())  return;
  if(!attacker_ob) return;
  if(query_too_big()) { call_out("wink_out", 1); }
}


query_too_big() {
  int x;
  object *atts;
  atts = all_inventory(environment());
  atts = filter_array(atts, "is_attacker", this_object());
  for(x = 0; x < sizeof(atts); x++) {
    if(atts[x]->query_level() > 10) 
      return 1;       
  }
  return 0;
}  

is_attacker(object ob) {
  if(ob->is_player()) {
    return (ob->query_attack() == this_object());
  }
}