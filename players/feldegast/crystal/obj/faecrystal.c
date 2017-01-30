/*
File: faecrystal.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 5/5/01
Description:
  A spell point battery for the crystal mage guild.  Adapted from my jade lynx.
*/
#include "../defs.h"

inherit "/obj/treasure.c";

int charged;

string short() {
  if(charged)
    return "A "+HIM+"faecrystal"+NORM;
  else
    return "A "+MAG+"faecrystal"+NORM;
}

void reset(int arg) {
  if(arg) return;
  set_id("faecrystal");
  set_alias("crystal");
  set_short("A "+HIM+"faecrystal"+NORM);
  set_long(
"This is a palm-sized faceted crystal with a purple glow.  You may "+BOLD+"charge"+NORM+" energy\n"+
"in it and then "+BOLD+"tap"+NORM+" it later.  You can also "+BOLD+"dismiss"+NORM+" it.\n"
  );
  set_weight(1);
  set_value(0);
}

int drop() { return 1; }

void init() {
  if(this_player()==environment()) {
    add_action("cmd_cache", "charge");
    add_action("cmd_tap", "tap");
    add_action("cmd_dismiss", "dismiss");
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
    write(HIR+"Something is wrong!  You lack the power to control the faecrystal\n"+
              "and it discharges your energy into the air!\n"+NORM);
    this_player()->add_spell_point(-random(100));
    if((int)this_player()->query_sp() < 100) {
      write(RED+"Lacking any other source of energy, the faecrystal drains your physical health!\n"+NORM);
      TP->hit_player(120);
    }
    return 1;
  }

  this_player()->add_spell_point(-cost);
  if(random((int)this_player()->query_attrib("mag") +
            (int)this_player()->query_attrib("int") +
            (int)this_player()->query_level()) < 15) {
    write("You fail to charge the "+HIM+"faecrystal"+NORM+" properly.\n"+
          "You feel drained.\n");
    return 1;
  }
  write("You charge the "+HIM+"faecrystal"+NORM+".\n");
  say(TPN+" charges the faecrystal.\n");
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

  if((int)this_player()->query_attrib("wil") < random(24)) {
    write(RED+"You draw too deeply upon the "+HIM+"faecrystal"+NORM+"'s power!\n"+
              "You scream in pain.\n"+NORM);
    say(TPN+" screams and falls to the ground.\n");
    this_player()->add_hit_point(-random(50));
    if((int)this_player()->query_hp() < 0) TP->hit_player(1);
  }

  return 1;
}

int cmd_dismiss(string str)
{
  if(str=="faecrystal")
  {
    write("With a wave of your hand, you dismiss the faecrystal.\n");
    TP->add_weight(-1);
    destruct(this_object());
    return 1;
  }
}

int query_save_flag() { return 1; }