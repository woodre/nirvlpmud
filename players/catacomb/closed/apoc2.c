inherit "/obj/weapon.c";
#include <ansi.h>
#define tpn this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("sword");
  set_alias("apocalypse");
  set_short(HIM+"Apocalypse"+NORM);
  set_long(
 HIR+"  The sword of Ragnarok, the end of time.  Forged deep\n"+
 "within the underdark by the four horsemen, the sword lies\n"+
 "in wait for the time when it will be needed.  The serrated\n"+
 "blade is roughly five feet in length stained a "+NORM+BOLD+RED+"blood red"+NORM+".\n"+
 HIR+"Halfway down the blade two large barbs extend out from the\n"+
 "blade.  The hilt is made from the polished bone of the elders\n"+
 "of each race.  At the end of the hilt is a large skull with\n"+
 "rubies for eyes.\n"+NORM);
  set_type("sword");
  set_class(18);
  set_weight(2);
  set_value(0);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (10) < 7) 
    {
     write(HIB+"\nYou call forth the power of the sword.\n"+NORM);
     write(RED+"      FIRE\n");
     write(    "             and\n");
     write(    "                   BRIMSTONE\n"+NORM);
     write(HIB+"         fall from the heavens.\n\n"+NORM);
     say(RED+"\n~~~~~~~~~~~~FIRE and BRIMSTONE~~~~~~~~~~~~~~~~\n");
     say(      "          errupt from the heavens\n\n"+NORM);
     return 5;
    }
    if (random(20) >= 13)
    {
     write(HIW+"\n\n        You stab "+HIM+"Apocalypse"+HIW+" into the ground....\n"+NORM);
     write(HIR+    "            Demons emerge from the ground\n"+NORM);
     write(HIW+    "        You watch in sadistic glee as the demons\n"+NORM);
     write(HIR+    "                 DEVOUR your foe\n"+NORM);
     say(HIM+"\n     Apocalypse"+BLU+" is thrust into the ground\n");
     say(       "        Demons emerge from under the monster\n");
     say(RED+   "             DEVOURING the monster\n"+NORM);
     return 5;
    }
    if (random(10) >= 5)
    {
     write(HIR+"\n    6666      6666      6666 \n");
     write("    6         6         6    \n");
     write("    6666      6666      6666 \n");
     write("    6  6      6  6      6  6 \n");
     write("    6666      6666      6666 \n\n");
     write("  The beast leaps from the sword\n");
     write(NORM+RED+"       UTTERLY DESTROYING\n"+NORM);
     write(HIR+"            your foe!\n\n"+NORM);
     say(HIB+"\n   The hell beast leaps from the blade\n"+NORM);
     say(YEL+    "            DESTROYING\n"+NORM);
     say(HIB+  "              its foe!\n\n"+NORM);
     return 6;
    }
  }

  
