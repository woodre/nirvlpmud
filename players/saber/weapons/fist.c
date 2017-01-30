/* added in a check in each return to check for if(rnd(3)==0)
  - mythos <9-22-96> */

#include "/players/saber/closed/ansi.h"
#define ATT capitalize(attacker->query_name())
#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("martial art");
     set_alias("fist");
    set_type("exotic");         /* set type added by Pavlik */
     set_alt_name("kung fu");
     set_short("Howling Fist Style Kung Fu");
     set_long("The knowledge and mastery of the legendary Howling Fist\n"+
        "Style Kung Fu.  It is a deadly weapon when correctly used.\n");
    set_class(15);
    set_weight(1);
    set_value(2500);
    set_hit_func(this_object());
}
weapon_hit(attacker){
string style, attack, attackm;
string here;
string color, backstr;
string gender,gender2,ogender,ogender2;
   w=random(22);
ogender2 = attacker->query_objective();
ogender = attacker->query_possessive();
gender = this_player()->query_possessive();
here = environment(this_player());

if(w == 0) {
tell_room(here,
  tp+" launches a series of rapid fire "+HIR+"Leapord's Paw"+NORM+" strikes\n"+
  "into "+ATT+"'s face.\n");
  if(random(3) > 0) return 0;
return 2;  }
if(w == 1) {
tell_room(here,
  tp+" rakes "+ATT+" across the face with a vicious "+HIR+"Tiger Claw"+NORM+".\n");
if(random(3) > 0) return 0;
return 2;   }
if(w == 2) {
tell_room(here,
  tp+" rips "+ATT+"'s throat with a devastating "+HIR+"Eagle Claw"+NORM+" fist.\n");
if(random(3) > 0) return 0;
return 5;  }
if(w == 3) {
tell_room(here,
  tp+" jams a "+HIR+"Poison Thumb"+NORM+" into "+ATT+"'s eye.\n");
if(random(3) > 0) return 0;
return 6;  }
if(w == 4) {
tell_room(here,
  tp+" launches "+ATT+" back into the air with a devastating "+HIR+"Broken Crane's Wing"+NORM+".\n"+
    ATT+" staggers back a step.\n");
if(random(3) > 0) return 0;
return 5;   }
if(w == 5) {
tell_room(here,
  tp+" hammers "+ATT+" to the throat with an "+HIR+"Opposing Crane's Wing"+NORM+" thrust.\n"+
    ATT+" makes a sickening choking noise and gasps for air.\n");
if(random(3) > 0) return 0;
return 7;   }
if(w == 6) {
tell_room(here,
  tp+" feints and than slaps "+ATT+" upside the head with a "+HIR+"Monkey Palm"+NORM+".\n");
if(random(3) > 0) return 0;
return 3;   }
if(w == 7) {
tell_room(here,
  tp+" kia's loudly as "+gender+" delivers a bloody "+HIR+"Dragon's Rake"+NORM+"\n"+
     "across "+ATT+"'s face.\n"+
    ATT+" wipes the blood from "+ogender+" eyes.\n");
if(random(3) > 0) return 0;
return 6;   }
if(w == 8) {
tell_room(here,
  tp+" hits "+ATT+" with a "+HIR+"Thrusting Leopard Kick"+NORM+" to the solar plexus.\n");
if(random(3) > 0) return 0;
return 5;   }
if(w == 9)  {
tell_room(here,
  tp+" jumps towards "+ATT+".\n"+
    tp+" completes a "+HIR+"Leaping Tiger Kick"+NORM+", leaving a bloody trail\n"+
    "across "+ATT+"'s abdomen.\n");
 if(random(3) > 0) return 0;
  return 5;   }
if(w == 10)  {
tell_room(here,
  tp+" spins and whips "+gender+" foot across "+ATT+"'s neck in a\n"+
    "sliding "+HIR+"Reverse Snake Kick"+NORM+".\n");
if(random(3) > 0) return 0;
return 6;  }
if(w == 11)  {
tell_room(here,
  tp+" slides-floats sideways by "+ATT+".\n"+
    tp+" completes "+gender+" circle and administers a deadly\n"+
    HIR+"Whipping Dragon's Tail"+NORM+" to "+ATT+"'s spine.\n");
  if(random(3) > 0) return 0;
  return 9;  }
if(w == 12)  {
tell_room(here,
  tp+" catches "+ATT+"'s attack and mutilates the outstreached appendage\n"+
    "with a "+HIR+"Crushing Wing Trap"+NORM+".\n"+
    "You hear a sickening crunch.\n");
  if(random(3) > 0) return 0;
  return 5;  }
if(w == 13)  {
tell_room(here,
  tp+" leaps across "+ATT+", climbing "+ogender2+" like a tree.\n"+
    tp+" reaches "+ATT+"'s neck and executes the "+HIR+"Climbing Monkey"+NORM+" neck snap.\n"+
    ATT+"'s head lolls forward.\n");
  if(random(3) > 0) return 0;
  return 8;  }
if(w == 14)  {
tell_room(here,
  tp+" slams "+ATT+" down against the ground with a "+HIR+"Dragging Leapard"+NORM+" lock.\n");
  if(random(3) > 0) return 0;
  return 4;  }
if(w == 15)  {
tell_room(here,
  tp+" grasps "+ATT+" and holds "+ogender2+" in the infamous "+HIR+"Tiger Embrace"+NORM+".\n"+
    tp+" snakes "+gender+" hand around "+ATT+"'s head, pulling it back\n"+
    "to expose the throat.\n"+
    tp+" leans down and bites "+ATT+"'s exposed throat.\n");
  if(random(3) > 0) return 0;
  return 8;  }
if(w == 16)  {
tell_room(here,
  tp+" coils "+gender+" arms around "+ATT+"'s legs.\n"+
    ATT+" is dragged to the ground by the "+HIR+"Crushing Snake Lock"+NORM+".\n");
  if(random(3) > 0) return 0;
  return 5;  }
if(w == 17)  {
tell_room(here,
  tp+" drops "+ATT+" to the floor with a spinning "+HIR+"Leapard's Tail"+NORM+" leg sweep.\n"+
    ATT+" falls.\n");
  if(random(3) > 0) return 0;
  return 4;  }
if(w == 18)  {
tell_room(here,
  tp+" slides "+gender+" feet around "+ATT+"'s leg and kicks.\n"+
    ATT+" is slammed to the ground by the deadly "+HIR+"Coiled Serpent"+NORM+" strike.\n");
  if(random(3) > 0) return 0;
  return 3;  }
if(w == 19)  {
tell_room(here,
  tp+" sends "+ATT+" flying through the air with a "+HIR+"Reverse Crane Throw"+NORM+".\n");
  if(random(3) > 0) return 0;
  return 5;  }
if(w == 20)  {
tell_room(here,
  tp+" howls loudly as "+gender+" grasps "+ATT+".\n"+
    ATT+" flies through the air, a victim of the deadly\n"+
    "  "+HIR+"SCREAMING TIGER TOSS"+NORM+".\n");
  if(random(3) > 0) return 0;
  return 10;  }
if(w == 21)  {
tell_room(here,
  tp+" spins with an outstreatched leg.\n"+
    ATT+" falls, "+ogender+" leg smashed in by the "+HIR+"Floating Dragon"+NORM+".\n");
  if(random(3) > 0) return 0;
  return 3;  }
/*
if(w == 22)  {
tell_room(here,
  tp+" catches "+ATT+" in "+gender+" vortex.\n"+
  tp+" rocks "+ATT+" with a "+HIR+"Mega-Spiral"+NORM+" of quicksilver punches.\n");
tell_room(here,
  tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n");
  return 7;  }
if(w == 23)  {
tell_room(here,
  tp+" jumps high into the air.\n"+
  tp+" descends like an eagle upon "+ATT+" with\n"+
    "the fierce claws of the "+HIR+"Red Sand Palm"+NORM+".\n");
  return 5;  }
if(w == 24)  {
tell_room(here,
  tp+" hits "+ATT+" in the groin with the "+HIR+"Peach Pitcher"+NORM+" claw.\n");
  return 2;  }
if(w == 25)  {
tell_room(here,
  tp+" rages into "+ATT+" with a series of quick "+HIM+"Wind Cutter"+NORM+" kicks.\n");
  return 4;  }
if(w == 26)  {
tell_room(here,
  tp+" dances around "+ATT+", spinning with "+gender+" palms\n"+
  "extended in the "+HIM+"Whirling Dancer"+NORM+"'s devastating spiral.\n");
tell_room(here,
  ATT+" is hit.\n"+ATT+" is hit.\n");
  return 6;  }
*/


return 0;
        }
