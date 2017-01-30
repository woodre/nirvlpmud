#include "define.h"
#include <ansi.h>


inherit "/obj/weapon.c";

int lit;

reset(arg) {
   ::reset(arg);
  if(arg) return;
  set_name("moongleam");
  set_alias("moon");
  set_short(HIC+"Moongleam"+NORM);
  set_type("sword");
  set_class(20);
  set_weight(4);
  set_long(
    "The Sword of the moon is a finely crafted longsword with a\n"+
    "coal black blade and a sapphire pommelstone.  The silver\n"+
    "crosspiece is shaped like a stylized full moon. You can make\n"+
    "out cryptic runes just beneath the surface of the blade.\n"
  );
  set_value(1200);
  set_params("other|evil",7,"evil_hit");
  set_read("On the first side:\n"+
           BOLD+"  This Blade Was Forged by the Master Weaponsmith, Mertucio.\n"
+NORM+
           "On the other side:\n"+
           HIY+"  Summon Darkness\n"+NORM);
}

void init() {
  ::init();
  add_action("cmd_intone","intone");
  add_action("cmd_intone","say");
}

cmd_intone(str) {
  if(!str || (lower_case(str) != "summon darkness"))
    return 0;
  if(lit) {
    write("Nothing happens.\n");
    return 1;
  }
  if(this_player()->query_sp() < 30) {
    write("You do not have enough magical energy.\nNothing happens.\n");
    return 1;
  }
  write("You exert your will as you intone the words:\n\t"+BOLD+"Summon Darkness\n"+NORM);
  this_player()->add_spell_point(-30);
  if(this_player()->query_attrib("wil") < 20) {
    write("Your will was not strong enough.  Nothing happens.\n");
    return 1;
  }
  write(HIY+"Your sword emits a errie wave of darkness.\n"+NORM);
  say(TPN+"'s sword begins to pulse with evil.\n");
  lit = 1;
  set_light(-2);
  call_out("lights_out",200*this_player()->query_level());
  return 1;
}

void lights_out() {
  set_light(2);
  lit=0;
  if(environment()->is_player())
    tell_object(environment(),"Moongleams thirst has been quench. The darkness subsides\n");
}

fire_hit(attacker) {
  int w;

  w=random(12);

  if(set_light(0) <= 0) {
    if(!w)
      write(BOLD+BLK+"Moongleam lays dormant in your hands.\n"+NORM);
    return 0;
  }

  if(!w) {
    switch(random(4)) {
      case 0: write("Moongleam's blade pulses with "+BBLK+HIW+"EVIL"+NORM+"!\n");
              say("Moongleam's blade burns "+BBLK+HIW+"white hot"+NORM+"!\n");
              break;
      case 1: write("Moongleam cuts through the air in an elegant sweep!\n");
              say("Moongleam cuts through the air in an elegant sweep!\n")
;
              break;
      case 2: write(HIK+"\nMoongleam vibrates violently as it looks for"+NORM+""+BBLK+HIW+"blood"+NORM+""+HIK+" to feed on.\n\n"+NORM);
              say(HIK+"\nMoongleam vibrates violently as it looks for"+NORM+""+BBLK+HIW+"blood"+NORM+""+HIK+" to feed on.\n\n"+NORM);
              break;
      case 3: write("Moongleam dances in your hands as you smite "+attacker->query_name()+"!\n");
              say(TPN+" smites "+attacker->query_name()+" with Moongleam!\n");
              break;
    }
    return 9;
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