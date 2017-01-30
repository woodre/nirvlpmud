

#include "/players/jaraxle/ansi.h"



inherit "players/jaraxle/weapon/weapon.c";

#define USER environment()

#define TP this_player()

#define POS query_possessive()

#define OBJ query_objective()

#define PRO query_pronoun()



reset(arg){

  ::reset(arg);

  if (arg) return;

set_name("rapier");

set_alt_name("elven rapier");

set_alias("found_elven_rapier");

set_short(GRN+"Elven "+HIG+"Rapier"+NORM);

set_hit_func(this_object());

set_type("sword");  

set_class(17);

set_weight(2);

set_value(10000);

set_no_break(1);

}



long(){ write(

"  This is a thin bladed rapier.  It is made of purest mithril\n"+

"steel, and is unbreakable by normal means. The hilt is protected\n"+

"by a golden guard with symbols of the forest decorating it. The\n"+

"pommel is tipped by a large diamond that glitters as the light\n"+

"strikes it.\n"+

"This weapon cannot be broken.\n");

return 1;

}



weapon_hit(attacker){

  if(random(100) < 30){

  tell_object(USER,

  HIG+"       The Elven Rapier pulses with life"+HIY+"..."+NORM+"\n\n"+

  YEL+"      /  /  /  /\\/\\/\\/\\///   "+HIY+"S L I C E"+NORM+YEL+"   \\\\\\/\\/\\/\\/\\ \\  \\  \\"+NORM+"\n\n"+

  HIG+"                        "+attacker->query_name()+" falls back in pain!"+NORM+"\n");

  tell_room(environment(USER),

  USER->query_name()+"'s "+HIG+"Elven Rapier"+NORM+" leaps forward...\n"+

  attacker->query_name()+" is impaled!\n", ({ USER }));

  return 5;

  }

  if(random(100) < 15){

  tell_object(USER,

  HIG+"The "+HIW+"Elven Rapier"+HIG+" jumps in your hand!"+NORM+"\n"+

  HIY+"    ..."+HIG+attacker->query_name()+" is sliced open!"+NORM+"\n\n");

  return 2;

  }   

  return 0;

}   

