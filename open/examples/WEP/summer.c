#include "defs.h"

inherit "/obj/weapon.c";

int lit;

reset(arg) {
   ::reset(arg);
  if(arg) return;
  set_name("summersword");
  set_alias("summer");
  set_short(HIY+"Summersword"+NORM);
  set_type("sword");
  set_class(18);
  set_weight(4);
  set_long(
    "The Sword of Summer is a finely crafted longsword with a\n"+
    "gleaming blade and a sapphire pommelstone.  The silver\n"+
    "crosspiece is shaped like a stylized sun.  You can make\n"+
    "out cryptic runes just beneath the surface of the blade.\n"
  );
  set_hit_func(this_object());
  set_read("On the first side:\n"+
           BOLD+"  This Blade Was Forged by the Master Weaponsmith, Mertucio.\n"+NORM+
           "On the other side:\n"+
           HIY+"  In Luminus Vethi\n"+NORM);
}

void init() {
  ::init();
  add_action("cmd_intone","intone");
  add_action("cmd_intone","say");
}

cmd_intone(str) {
  if(lower_case(str)!="in luminus vethi")
    return 0;
  if(lit) {
    write("Nothing happens.\n");
    return 1;
  }
  if(this_player()->query_sp() < 30) {
    write("You do not have enough magical energy.\nNothing happens.\n");
    return 1;
  }
  write("You exert your will as you intone the words:\n\t"+BOLD+"In Luminus Vethi\n"+NORM);
  this_player()->add_spell_point(-30);
  if(this_player()->query_attrib("wil") < 16) {
    write("Your will was not strong enough.  Nothing happens.\n");
    return 1;
  }
  write(HIY+"Your sword begins to give off a cheerful glow.\n"+NORM);
  say(TPN+"'s sword begins to glow.\n");
  lit = 1;
  set_light(1);
  call_out("lights_out",200*this_player()->query_level());
  return 1;
}

void lights_out() {
  set_light(-1);
  lit=0;
  if(environment()->is_player())
    tell_object(environment(),"The Summersword dims.\n");
}

weapon_hit(attacker) {
  int w;

  w=random(3);

  if(set_light(0) <= 0) {
    if(!w)
      write(BOLD+BLK+"The Summersword lies dormant in your hands.\n"+NORM);
    return 0;
  }

  if(!w) {
    switch(random(4)) {
      case 0: write("The Summersword's blade burns "+BBLK+HIW+"white hot"+NORM+"!\n");
              say("The Summersword's blade burns "+BBLK+HIW+"white hot"+NORM+"!\n");
              break;
      case 1: write("The Summersword cuts through the air in an elegant sweep!\n");
              say("The Summersword cuts through the air in an elegant sweep!\n");
              break;
      case 2: write(HIY+"\nThe Summersword glows like the sun on a warm summer day.\n\n"+NORM);
              say(HIY+"\nThe Summersword glows like the sun on a warm summer day.\n\n"+NORM);
              break;
      case 3: write("The Summersword dances in your hands as you smite "+attacker->query_name()+"!\n");
              say(TPN+" smites "+attacker->query_name()+" with the Summersword!\n");
              break;
      return 3;
    }
  }
}

short() {
  if(lit)
    return ::short()+" ("+HIC+"*"+NORM+")";
  return ::short();
}

count_misses(w) {
  return 1;
}

count_hit_made(w) {
  return 1;
}
