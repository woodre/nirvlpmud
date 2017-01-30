/*
File: lynx.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/2/01
Description:
  A statuette that acts as a battery for energy.
  I don't have a monster for it yet, but it'll probably be in my
Caladon area eventually.
*/
#include "defs.h"

inherit "/obj/treasure.c";

int charged;

int id(string str) {
  return ::id(str) || str=="jade lynx" || str=="jade lynx statue";
}

string short() {
  if(charged)
    return "A "+HIG+"jade"+NORM+" lynx";
  else
    return "A "+GRN+"jade"+NORM+" lynx";
}

void reset(int arg) {
  if(arg) return;
  set_id("lynx");
  set_alias("statue");
  set_short("A "+HIG+"jade"+NORM+" lynx");
  set_long(
"This is a small palm-sized statue of a lynx carved from a piece of\n"+
"jade.  You may 'charge' and 'tap' it.\n"
  );
  set_weight(1);
  set_value(3500);
}

void init() {
  object other;
  if(!environment()) return;
  other = present("jade lynx statue 2",environment());
  if(other) {
    write(RED+"The two jade lynxes explode due to their proximity!\n"+NORM);
    say("The two jade lynxes explode due to their proximity!\n");
    this_player()->hit_player(100);
    if(environment()->is_player()) environment()->add_weight(-2);
    destruct(other);
    destruct(this_object());
    return;
  }
  if(this_player()==environment()) {
    add_action("cmd_cache", "charge");
    add_action("cmd_cache", "cache");
    add_action("cmd_tap", "tap");
  }
}

int cmd_cache(string str) {
  int cost;
  if(!id(str)) {
    notify_fail("Charge what?\n");
    return 0;
  }
  if(charged) {
    write("It has already been charged.\n");
    return 1;
  }
  cost=50+random(11);
  if((int)this_player()->query_sp() < cost) {  
    write(HIR+"Something is wrong!  You lack the power to control the jade lynx\n"+
              "and it discharges your energy into the air!\n"+NORM);
    this_player()->add_spell_point(-random(100));
    if((int)this_player()->query_sp() < 100) {
      write(RED+"Lacking any other source of energy, the jade lynx drains your physical health!\n"+NORM);
      TP->hit_player(120);
    }
    return 1;
  }

  this_player()->add_spell_point(-cost);
  if(random((int)this_player()->query_attrib("mag") +
            (int)this_player()->query_attrib("int") +
            (int)this_player()->query_level()) < 15) {
    write("You fail to charge the "+HIG+"jade"+NORM+" lynx properly.\n"+
          "You feel drained.\n");
    return 1;
  }
  write("You charge the "+HIG+"jade"+NORM+" lynx.\n");
  say(TPN+" charges the jade lynx.\n");
  charged=1;
  return 1;
}

int cmd_tap(string str) {
  if(!id(str)) {
    notify_fail("Tap what?\n");
    return 0;
  }
  if(!charged) {
     write("Nothing happened.\n");
     return 1;
  }
  if((int)this_player()->query_level() < 15) {
    write("You aren't high enough level to use this item.\n");
    return 1;
  }
  write(HIM+"You tap the statuette's power.  Energy fills you!\n"+NORM);
  say(TPN+" taps a jade statuette's power.\n");
  this_player()->add_spell_point(25+random(26));
  charged=0;
  if((int)this_player()->query_attrib("wil") > random(100)) {
    write(RED+"You draw too deeply upon the "+HIG+"jade"+NORM+" lynx's power!\n"+
              "You scream in pain.\n"+NORM);
    say(TPN+" screams and falls to the ground.\n");
    this_player()->add_hit_point(-random(50));
    if((int)this_player()->query_hp() < 0) TP->hit_player(1);
  }
  return 1;
}

locker_arg() {
  return charged+"";
}

locker_init(arg) {
  sscanf(arg,"%d",charged);
}
    
generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}
