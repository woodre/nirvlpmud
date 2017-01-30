inherit "/obj/weapon.c";
#include <ansi.h>

reset (arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("reaver");
  set_short(BOLD+HIW+"Fate"+HIR+" Reaver"+NORM);
  set_long(
 HIM+"  The mystical blade of the knight "+HIB+"Beowulf"+HIM+".  The blade is enveloped\n"+
 "in a magical aura.  Runes of great power are etched into the blade.\n"+
 BOLD+"The razor sharp blade scintilates under the noon sun blinding its foe"+NORM+HIM+".\n"+
 "The blade seems to be made of some material that is of another world, almost\n"+
 CYN+"etherial"+HIM+" in nature.  In the hands of the correct person, the "+HIW+"Fate "+HIR+"\n"+
 "Reaver"+HIM+" is something to be feared.\n"+NORM);
  set_type("axe");
  set_class(18);
  set_weight(3);
  set_value(5000);
  set_hit_func(this_object()); 
}

mixed
weapon_hit(object attacker) 
{
    if(random(20) > 15)
    {
     write("\n\n    You work yourself into a frenzy scoring hit after hit on your foe.\n");
     write(RED+"                         B   L   O   O   D\n");
     write("                          B   L   O   O   D\n");
     write("                           B   L   O   O   D\n");
     write(HIR+"                      Flows from the many wounds.\n\n"+NORM);
     say("\n\n    You work yourself into a frenzy scoring hit after hit on your foe.\n");
     say(RED+"                         B   L   O   O   D\n");
     say("                          B   L   O   O   D\n");
     say("                           B   L   O   O   D\n");
     say(HIR+"                      Flows from the many wounds.\n\n"+NORM);
     return 5;
    }
    if(random(50) >= 25)
    {
     write("\n\n    You grab "+HIW+"Fate "+HIR+"Reaver"+NORM+" in both hands and \n");
     write("     evoke the Sur rune and the enemy is blinded in"+WHT+" Holy Light"+NORM+".\n\n");
     say("\n\n    You grab "+HIW+"Fate "+HIR+"Reaver"+NORM+" in both hands and \n");
     say("     evoke the Sur rune and the enemy is blinded in"+WHT+" Holy Light"+NORM+".\n\n");
     return 4;
     }
}


  
