/* Made for Fastkill for bugs..

Fred

*/

inherit "obj/weapon";
#include <ansi.h>
#define PI TP->query_attrib("pie")
#define QA query_alignment()
#define QN query_name()
#define TP this_player()
#define POS query_possessive()
 

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("elucidator");
    set_alias("sword");
    set_short(BOLD+BLK+"The Legendary Elucidator"+NORM);
    set_type("sword");
    set_long(
      "Elucidator is a pitch black sword, evenly balanced and\n"+
      "quite powerful.  It has a black handle connected to a hand\n"+
      "guard that is longer on the right side.  Attached to this\n"+
      "elongated area of the hand-guard is part of Elucidator's\n"+
      "obsidian blade.\n");
    set_class(18);
    set_weight(2);
    set_value(1200);
    set_hit_func(this_object());
}
 
weapon_hit(object ob) 
{
  if(check_race(ob) && PI > random(50) ) 
  {
    write("\nElucidator shines with an "+MAG+"eerie"+NORM+" Glow.\n\n"+
          "     "+HIY+"Light"+NORM+BOLD+" energy"+NORM+" fires from Elucidator into "+MAG+ob->QN+NORM+"\n\n");
    say("\n"+TP->QN+"'s "+BOLD+"sword"+NORM+" fires "+HIY+"Light"+NORM+BOLD+" energy"+NORM+" into "+ob->QN+"\n\n");
    ob->heal_self(-(4 + random(PI/2)));
    TP->add_hit_point(random(PI/5));
    return 5;
  }
  if(!random(5) && ob->QA < 0)  
  {
    write("\nElucidator slices through the air\n\n"+
             ""+RED+"      D E S T R O Y I N G "+NORM+"\n\n"+
             "            "+MAG+ob->QN+NORM+"\n\n");
    say("\n"+TP->QN+RED+" destroys "+NORM+ob->QN+" with Elucidator!\n\n");
    ob->heal_self(-(4 + random(4)));      

    return 4;
  }
  if(!random(5) && TP->QA > 0)
  {
    write("\nYou "+BOLD+"lunge"+NORM+" forward hacking deeply into "+ob->QN+"!\n\n");
    say(TP->QN+BOLD+" lunges"+NORM+" forward with "+TP->POS+" sword, hacking into "+ob->QN+"!\n");
    ob->heal_self(-(2 + random(3)));
    return 3;
  } 
  return;
}
 
check_race(object ob) {
  if(
    call_other(ob,"id","shadowcreature") ||
    call_other(ob,"id","demon") ||
    call_other(ob,"id","devil") ||
    call_other(ob,"id","daemon") ||
    call_other(ob,"id","shadow") ||
    call_other(ob,"id","spirit") ||
    call_other(ob,"id","undead") ||
    call_other(ob,"id","ghost") ) return 1;
  else return 0;
}
