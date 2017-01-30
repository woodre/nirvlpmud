/*  This weapon has a built in dest for the strange random
bug that occasionally makes it stick on a player.  */
/* I have set it up so that the return damage only occurs 1/3
   otherwise it returns 0  - mythos <9-22-96> */

#include "/players/saber/closed/ansi.h"
#define ATT capitalize(attacker->query_name())
#define tp this_player()->query_name()
int w, DAMAGE;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("martial art");
     set_alias("dance");
    set_type("exotic");         /* set type added by Pavlik */
     set_alt_name("kung fu");
     set_short("Dancing Lady Style Kung Fu");
     set_long("The knowledge and mastery of the legendary Dancing Lady\n"+
        "Style Kung Fu.  It is a deadly weapon in the right hands.\n"+
        "You can destroy the kung fu by typing <kung fu gone>\n");
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
   w=random(27);
ogender2 = attacker->query_objective();
ogender = attacker->query_possessive();
gender = this_player()->query_possessive();
here = environment(this_player());

if(w == 0) {
tell_room(here,
  tp+" slices "+ATT+" with a "+HIM+"Knife Edge Hand"+NORM+".\n");
DAMAGE = 2;  }
if(w == 1) {
tell_room(here,
  tp+" trips "+ATT+" with a "+HIM+"Leg Brush"+NORM+", dumping "+ogender2+" on "+ogender+" back.\n");
DAMAGE = 1;   }
if(w == 2) {
tell_room(here,
  tp+" grabs "+ATT+"'s leg and delivers a "+HIM+"Knee Bender"+NORM+" lock.\n");
DAMAGE = 1;  }
if(w == 3) {
tell_room(here,
  tp+" smites "+ATT+" with a "+HIM+"Heart Stealer"+NORM+" kick.\n");
DAMAGE = 3;  }
if(w == 4) {
tell_room(here,
  tp+" performs a "+HIM+"Disappearing Act"+NORM+" and appears behind "+ATT+".\n"+
  tp+" slams "+ATT+" with a "+HIM+"Heart Stealing"+NORM+" kick to the back of the neck.\n");
DAMAGE = 3;   }
if(w == 5) {
tell_room(here,
  tp+" grabs "+ATT+"'s arm and inflicts an "+HIM+"Elbow Crusher"+NORM+".\n");
DAMAGE = 1;   }
if(w == 6) {
tell_room(here,
  tp+" crushes "+ATT+"'s wrist with a two finger style of the "+HIM+"Bone Cracking Claw"+NORM+".\n");
DAMAGE = 2;   }
if(w == 7) {
tell_room(here,
  tp+" follows "+ATT+"'s movements with the "+HIM+"Haunting Shadow"+NORM+".\n"+
  tp+" rocks "+ATT+" with a "+HIM+"Heart Stealer"+NORM+" kick to the neck.\n");
DAMAGE = 3;   }
if(w == 8) {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" slams "+ATT+" with the single extended foot of a "+HIM+"Hell Dragon's Stroke"+NORM+".\n");
DAMAGE = 7;   }
if(w == 9)  {
tell_room(here,
  tp+" uses "+HIM+"Riding on a Cloud"+NORM+" to jump high into the air.\n"+
  tp+" performs the whirlwind motion of the "+HIM+"Mini Tornado Kick"+NORM+".\n"+
  "");
  write("You hit "+ATT+" with a bone crunching sound.\n");
  say(tp+" hits "+ATT+" with a bone crunching sound.\n");
  DAMAGE = 5;   }
if(w == 10)  {
tell_room(here,
  tp+" smashes "+ATT+" with a "+HIM+"Northern Eagle Punch"+NORM+".\n");
DAMAGE = 3;  }
if(w == 11)  {
tell_room(here,
  tp+" uses the "+HIM+"Lightfoot"+NORM+" to jump high into the air.\n"+
  tp+" devastates "+ATT+" with a "+HIM+"Rock Shattering Kick"+NORM+" to the chest.\n");
  DAMAGE = 6;  }
if(w == 12)  {
tell_room(here,
  tp+" performs a "+HIM+"Disappearing Act"+NORM+" and appears behind "+ATT+".\n"+
  tp+" sinks "+gender+" claws into "+ATT+"'s collar bone and\n"+
  "performs the devastating "+HIM+"Shoulder Separator"+NORM+" manuver.\n");
  DAMAGE = 4;  }
if(w == 13)  {
tell_room(here,
  tp+" slams "+ATT+" with a spinning "+HIM+"Tiger Tail Kick"+NORM+".\n");
  DAMAGE = 3;  }
if(w == 14)  {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" rages into "+ATT+" with a "+HIM+"Sheet Lightning"+NORM+" jump kick.\n");
  DAMAGE = 4;  }
if(w == 15)  {
tell_room(here,
  tp+" devastates "+ATT+" with a spinning jump kick called the "+HIM+"Wing Cutter"+NORM+".\n");
  DAMAGE = 3;  }
if(w == 16)  {
tell_room(here,
  tp+" successfully executes a "+HIM+"BIRTH OF A DEMON"+NORM+" sequence.\n"+
  tp+" becomes a fury of motion as "+gender+" rocks "+ATT+" with a fury of\n"+
"lightning quick attacks.\n"+
  "");
  say(tp+" hits "+ATT+" with a crushing blow.\n"+tp+" hits "+ATT+" with a crushing blow.\n");
  write("You hit "+ATT+" with a crushing blow.\nYou hit "+ATT+" with a crushing blow.\n");
  DAMAGE = 10;  }
if(w == 17)  {
tell_room(here,
  tp+" thrashes "+ATT+" with a "+HIM+"Consecutive Bombardment"+NORM+" of lightning quick punches.\n"+
  "");
  write("You hit "+ATT+" hard.\nYou hit "+ATT+" hard.\nYou hit "+ATT+" hard.\nYou hit "+ATT+" hard.\n");
  say(tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n");
  DAMAGE = 7;  }
if(w == 18)  {
tell_room(here,
  tp+" jumps high into the air.\n"+
  tp+" executes the fast, double claw flying attack of\n"+
  HIM+"the Eagle Hunts the Hare"+NORM+" upon "+ATT+".\n");
  DAMAGE = 3;  }
if(w == 19)  {
tell_room(here,
  tp+" performs a "+HIM+"Finger Storm Sandstorm"+NORM+".\n"+
  tp+" assaults "+ATT+" with a flurry of whirling two finger strikes.\n");
  write("You hit "+ATT+".\nYou hit "+ATT+".\nYou hit "+ATT+".\n");
  say(tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n");
  DAMAGE = 7;  }
if(w == 20)  {
tell_room(here,
  tp+" reverses "+gender+" direction suddenly, appearing behind "+ATT+".\n"+
  tp+" claws "+ATT+" across the back with a "+HIM+"Dancing Touch"+NORM+" strike.\n");
  DAMAGE = 5;  }
if(w == 21)  {
tell_room(here,
  tp+" performs the "+HIM+"Haunting Demon"+NORM+", flipping over "+ATT+" and raking\n"+
  gender+" finger claws down "+ATT+"'s back.\n");
  DAMAGE = 3;  }
if(w == 22)  {
tell_room(here,
  tp+" catches "+ATT+" in "+gender+" vortex.\n"+
  tp+" rocks "+ATT+" with a "+HIM+"Mega-Spiral"+NORM+" of quicksilver punches.\n");
  write("You hit "+ATT+".\nYou hit "+ATT+".\nYou hit "+ATT+".\nYou hit "+ATT+".\nYou hit "+ATT+".\n");
  say(tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n");
  DAMAGE = 7;  }
if(w == 23)  {
tell_room(here,
  tp+" jumps high into the air.\n"+
  tp+" descends like an eagle upon "+ATT+" with\n"+
    "the fierce claws of the "+HIM+"Red Sand Palm"+NORM+".\n");
  DAMAGE = 5;  }
if(w == 24)  {
tell_room(here,
  tp+" hits "+ATT+" in the groin with the "+HIM+"Peach Pitcher"+NORM+" claw.\n");
  DAMAGE = 2;  }
if(w == 25)  {
tell_room(here,
  tp+" rages into "+ATT+" with a series of quick "+HIM+"Wind Cutter"+NORM+" kicks.\n");
  DAMAGE = 4;  }
if(w == 26)  {
tell_room(here,
  tp+" dances around "+ATT+", spinning with "+gender+" palms\n"+
  "extended in the "+HIM+"Whirling Dancer"+NORM+"'s devastating spiral.\n");
  write("You hit "+ATT+".\nYou hit "+ATT+".\n");
  say(tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n");
  DAMAGE = 6;  }
  if(random(3) > 0) return 0;  /* my addition - mythos */
return DAMAGE;
        }

init()  {
  ::init();
  add_action("kung","kung");
        }

kung(str)  {
  if(str == "fu gone")  {
  write("You dispose of the kung fu.\n");
  command("drop kung fu", environment(this_object()));
  destruct(this_object());
  return 1;
        }
        }
