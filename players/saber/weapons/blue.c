/*  Added cosmetic changes 8/16/02 - Eurale  */

#include "/open/ansi.h"
/*
#include "/players/saber/closed/esc.h"
*/
#define ATT capitalize(attacker->query_name())
/* real_name returns 0 on some things, changed to name, -Bp */
#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
      ::reset(arg);
    if (arg) return;
    set_name("martial art");
    set_alias("dragon");
    set_alt_name("kung fu");
    set_short(BLU+"Blue Dragon Style Kung Fu"+NORM);
    set_long("The knowledge and mastery of the legendary Blue Dragon\n"+
       "Style Kung Fu.  It is a deadly weapon in the right hands.\n");
    set_class(16);
    set_weight(4);
    set_value(3500);
    set_hit_func(this_object());
}

weapon_hit(attacker){
string style, attack, attackm;
string here;
string color, backstr;
string gender,gender2,ogender,ogender2;
   w=random(26);
style = esc+"[1m";
attackm = esc+"[0m"+style+attack+esc+"[0m";
ogender2 = attacker->query_objective();
ogender = attacker->query_possessive();
gender = this_player()->query_possessive();
here = environment(this_player());

/* Steal an opponents 'Chi' with this */
if(attacker && attacker->query_hp() > 25)
attacker->heal_self(-random(3));

if(w == 0) {
tell_room(here,
  tp+" slices "+ATT+" with a "+esc+"[0m"+style+"Knife Edge Hand"+esc+"[0m"+".\n");
return 2;  }
if(w == 1) {
tell_room(here,
  tp+" hammers "+ATT+" with an "+esc+"[0m"+style+"Awakening Dragon"+esc+"[0m"+" kick to the face.\n"+
  tp+" hammers "+ATT+" with an "+esc+"[0m"+style+"Awakening Dragon"+esc+"[0m"+" kick to the chest.\n"+
  tp+" hammers "+ATT+" with an "+esc+"[0m"+style+"Awakening Dragon"+esc+"[0m"+" kick to the face.\n");
return 5;   }
if(w == 2) {
tell_room(here,
  tp+" trips "+ATT+" with an "+esc+"[0m"+style+"Leg Brush"+esc+"[0m"+", dumping "+ogender2+" on "+ogender+" back.\n");
return 1;   }
if(w == 3) {
tell_room(here,
  tp+" grabs "+ATT+"'s leg and delivers a "+esc+"[0m"+style+"Knee Bender"+esc+"[0m"+" lock.\n");
return 1;  }
if(w == 4) {
tell_room(here,
  tp+" smites "+ATT+" with a "+esc+"[0m"+style+"Heart Stealer"+esc+"[0m"+" kick.\n");
return 3;  }
if(w == 5) {
tell_room(here,
  tp+" performs a "+esc+"[0m"+style+"Disappearing Act"+esc+"[0m"+" and appears behind "+ATT+".\n"+
  tp+" slams "+ATT+" with a "+esc+"[0m"+style+"Heart Stealing"+esc+"[0m"+" kick to the back of the neck.\n");
return 3;   }
if(w == 6) {
tell_room(here,
  tp+" grabs "+ATT+"'s arm and inflicts an "+esc+"[0m"+style+"Elbow Crusher"+esc+"[0m"+".\n");
return 1;   }
if(w == 7) {
tell_room(here,
  tp+" crushes "+ATT+"'s wrist with a two finger style of the "+esc+"[0m"+style+"Bone Cracking Claw"+esc+"[0m"+".\n");
return 2;   }
if(w == 8) {
tell_room(here,
  tp+" hammers "+ATT+" with an "+esc+"[0m"+style+"Awakening Dragon"+esc+"[0m"+" kick to the face.\n");
return 3;  }
if(w == 9) {
tell_room(here,
  tp+" follows "+ATT+"'s movements with the "+esc+"[0m"+style+"Hunting Shadow"+esc+"[0m"+".\n"+
  tp+" rocks "+ATT+" with a "+esc+"[0m"+style+"Heart Stealer"+esc+"[0m"+" kick to the neck.\n");
return 3;   }
if(w == 10) {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" hammers "+ATT+" with an "+esc+"[0m"+style+"Awakening Dragon"+esc+"[0m"+" kick to the face.\n");
return 7;  }
if(w == 11) {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" is surrounded by a dragon like aura.\n"+
  tp+" hammers "+ATT+" with a "+esc+"[0m"+style+"Dragon in Nine Heaven's"+esc+"[0m"+" kick to the temple.\n");
return 8;   }
if(w == 12) {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" hammers "+ATT+" with an "+esc+"[0m"+style+"Eighteen Dragon Slaying Kick"+esc+"[0m"+".\n");
return 8;  }  /* return 12 is a wee bit much for this weapon- changed to 8 */
if(w == 13) {
tell_room(here,
  tp+" does a leg sweep, knocking "+ATT+" upon "+ogender+" stomach.\n"+
  tp+" performs the "+esc+"[0m"+style+"God and Ghost Exchange"+esc+"[0m"+".\n"+
  tp+" jumps high into the air, a brief shadow against the moon.\n");
tell_room(here,
  tp+" lands with a double foot jump kick upon the prone "+ATT+".\n"+
  "You think you hear "+ATT+"'s spine crack.\n");
return 8;  } /* return 12 is a wee bit much for this weapon- changed to 8 */
if(w == 14) {
tell_room(here,
  tp+" places both hands together and crushes "+ATT+" with the thrusting\n"+
  "strike of the "+esc+"[0m"+style+"Heart Demolishing Shovel"+esc+"[0m"+".\n");
return 6;  }
if(w == 15) {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" slams "+ATT+" with the single extended foot of a "+esc+"[0m"+style+"Hell Dragon's Stroke"+esc+"[0m"+".\n");
return 7;   }
if(w == 16) {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" rocks "+ATT+" with the spinning single foot of the "+esc+"[0m"+style+"Mini Hell-Dragon's"+esc+"[0m"+" strokes.\n");
return 6;   }
if(w == 17)  {
tell_room(here,
  tp+" uses "+esc+"[0m"+style+"Riding on a Cloud"+esc+"[0m"+" to jump high into the air.\n"+
  tp+" performs the whirlwind motion of the "+esc+"[0m"+style+"Mini Tornado Kick"+esc+"[0m"+".\n"+
  tp+" hits "+ATT+" with a bone crunching sound.\n");
  return 5;   }
if(w == 18)  {
tell_room(here,
  tp+" smashes "+ATT+" with a "+esc+"[0m"+style+"Northern Eagle Punch"+esc+"[0m"+".\n");
return 3;  }
if(w == 19)  {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" bombards "+ATT+" with the "+esc+"[0m"+style+"Raging Dragons"+esc+"[0m"+" kick.\n"+
  tp+" hits "+ATT+" with a crushing blow.\n");
  return 5;   }
if(w == 20)  {
tell_room(here,
  tp+" uses the "+esc+"[0m"+style+"Lightfoot"+esc+"[0m"+" to jump high into the air.\n"+
  tp+" annihilates "+ATT+" with the "+esc+"[0m"+style+"Right and Left Mighty Dragon"+esc+"[0m"+" jump kick.\n"+
  tp+" hits "+ATT+" with a bone crushing sound.\n");
  return 6;  }
if(w == 21)  {
tell_room(here,
  tp+" uses the "+esc+"[0m"+style+"Lightfoot"+esc+"[0m"+" to jump high into the air.\n"+
tp+" devastates "+ATT+" with a "+esc+"[0m"+style+"Rock Shattering Kick"+esc+"[0m"+" to the chest.\n");
  return 6;  }
if(w == 22)  {
tell_room(here,
  tp+" performs a "+esc+"[0m"+style+"Disappearing Act"+esc+"[0m"+" and appears behind "+ATT+".\n"+
  tp+" sinks "+gender+" claws into "+ATT+"'s collar bone and\n"+
  "performs the devastating "+esc+"[0m"+style+"Shoulder Separator"+esc+"[0m"+" manuver.\n");
  return 4;  }
if(w == 23)  {
tell_room(here,
  tp+" slams "+ATT+" with a spinning "+esc+"[0m"+style+"Tiger Tail Kick"+esc+"[0m"+".\n");
  return 3;  }
if(w == 24)  {
tell_room(here,
  tp+" jumps high into the air, a brief shadow against the moon.\n"+
  tp+" rages into "+ATT+" with a "+esc+"[0m"+style+"Sheet Lightning"+esc+"[0m"+" jump kick.\n");
  return 4;  }
if(w == 25)  {
tell_room(here,
  tp+" devastates "+ATT+" with a spinning jump kick called the "+esc+"[0m"+style+"Wing Cutter"+esc+"[0m"+".\n");
  return 3;  }


/* steal an attackers Chi */
if(attacker && attacker->query_hp() > 25)
attacker->heal_self(-random(2));

return 0;
        }
