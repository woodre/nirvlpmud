inherit "obj/clean";
#include "/players/snakespear/closed/ansi.h"
id(str) {
   return str == "sign";
}

short() { 
   return HIY+"A "+HIR+"BIG "+HIW+"WARNING "+HIG+"SIGN"+NORM;
   }

long()  {
 write(
 "  This is a huge sign with big, bright colors.  There is nothing\n"+
 "around it or obstructing it from view.  The sign is made of a\n"+
 "strange glowing material that must possess some strong magical\n"+
 "power, because it looks very new and clean.  It seems to tug at\n"+
 "your soul.  There is something written on it.\n");
}

get()  { return 0;  }
query_weight()  { return 1; }
query_value()  { return 1;  }
init()  {
add_action("read_sign", "read");
}

read_sign(str) {
 write(
 "  Those that have aquired the powers of the flame and knowledge to cast\n"+
 "fireballs, should be very leary of venturing further into this dark\n"+
 "castle.  The castle was cursed by a higher power.  Only the young may\n"+
 "pass into the realms and battle the creatures that lurk inside.\n\n"+
 "  This -IS- your only warning.  If you can use fireball and procede\n"+
 "further into Zultayne, your fate is in your own hands.  You have been\n"+
 "warned.  One must make their choice wisely now.\n\n\n"+
 HIR+"*"+NORM+"  The author is unknown.  "+HIR+"*\n"+NORM);
 return 1;
 }