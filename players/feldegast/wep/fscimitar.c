/*
This scimitar is wielded by The Wanderer in the Jal-Hab.  It ignites
in battle if it is daylight, and gets snuffed out at night.  Wc18, and 
decent specials, but nothing extraordinary.
*/
#include "defs.h"
#define HOUR (time() % 86400 / 3600 - 4)

inherit "/obj/weapon.c";

int lit;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("scimitar");
  set_short(HIY+"The Scimitar of the Sun"+NORM);
  set_long(
    "The Scimitar of the Sun is a long curving sword with a heavily\n"+
    "waited tip.  Running along the blade are etched curling tongues\n"+
    "of flame.  The pommelstone of the scimitar is a circular glowing\n"+
    "yellow rock of indeterminate origins.\n"
  );
  set_type("sword");
  set_class(18);
  set_weight(7);
  set_value(2500);

  message_hit=({
    YEL+"toasted"+NORM," with "+short_desc,
    HIR+"seared"+NORM,"",
    RED+"burned"+NORM," with a crackling sound",
    "chopped"," hard",
    "hit","",
    "grazed","",
    "nicked","'s stomach"
  });
}

string short() {
  string s;
  s=short_desc;
  if(lit)
    s+=" ("+HIR+"Blazing"+NORM+")";
  if(broke)
    s+=" [broken]";    
  if(wielded)
    s+=" (wielded)";
  if ((int)call_other(this_player(), "query_level", 0) > 20)
    s+="  < wc " + class_of_weapon + ","+eff_wc + " >";
  return s;
}

int weapon_hit() {
  int x;
  if(!lit && HOUR > 6 || HOUR < 18) {
    write(short_desc+HIY+" lights up with fire!\n"+NORM);
    lit=1;
    set_light(1);
  }
  if(lit && HOUR < 6 || HOUR > 18) {
    write(short_desc+"'s flames die as night falls.\n"); 
    lit=0;
    set_light(-1);
  }
  if(lit) {
    x=random( (int)TP->query_attrib("wil") + (int)TP->query_attrib("pie") );
    if(x > 27 && random(3)) {
      write(RED+"Your scimitar blazes.\n"+NORM);
      say(RED+TPN+"'s scimitar blazes.\n"+NORM);
    }
    if(x > 30 && x < 35) {
      write(HIR+" You sear your opponent with your blazing scimitar.\n"+NORM);
      say(HIR+TPN+" sears "+(string)TP->query_possessive()+" opponent with "+
          (string)TP->query_possessive()+" blazing scimitar!\n"+NORM);
      return 4;
    }
    if(x >= 35) { /* 13% or less */
      write(HIY+"Your scimitar glows bright as the sun.\n"+NORM);
      say(HIY+TPN+"'s scimitar glows bright as the sun.\n"+NORM);
      return 7;
    }
  }
  return 0;
}