/* I built this Kung fu style for my wife, with Saber's full permission.
   WC 17, Average return of 5.6, weight 2 Kung Fu    -Dar  */

#include "/players/saber/closed/esc.h"
#include <ansi.h>
#define ATT capitalize(attacker->query_name())
#define tp this_player()->query_name()
int a, w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Pouncing Kitten Kung Fu");
set_alias("kitten");
set_type("exotic");
set_alt_name("kung fu");
set_short("Pouncing Kitten Style Kung Fu");
set_long("The knowledge and mastery of the Master Monk Kaya. She\n"+
         "developed this fighting style called the Pouncing Kitten.\n"+
         "You can destroy the kung fu by typing <kung fu gone>\n");
set_class(17);
set_weight(2);
set_value(3500);
set_hit_func(this_object());
}

weapon_hit(attacker){
string style, attack, attackm;
string here;
string color, backstr;
string gender,gender2,ogender,ogender2;
   w=random(25);
   a=random(4);
ogender2 = attacker->query_objective();
ogender = attacker->query_possessive();
gender = this_player()->query_possessive();
here = environment(this_player());

if(w == 0) {
tell_room(here,
  tp+" races across the room with a "+HIM+"Charging Cheetah"+NORM+" maneuver.\n"+
  tp+" launches a series of rapid fire "+HIM+"Kitty's Paw"+NORM+" strikes\n"+
  "into "+ATT+"'s face.\n");
if(call_other(this_player(),"query_attrib","wil") > random(50))  {
return 4; }
}
if(w == 1) {
tell_room(here,
  tp+" rakes "+ATT+" across the face with a vicious "+HIM+"Kitten Claw"+NORM+".\n"); 
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 2; }
}
if(w == 2) {
tell_room(here,
  tp+" rips "+ATT+"'s throat with a devastating "+HIM+"Dancing Kitty"+NORM+" strike.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 5; }
}
if(w == 3) {
tell_room(here,
  tp+" rolls into a ball and strikes "+ATT+" with the deadly\n"+
  "                "+HIM+"Hidden Kitten Claw"+NORM+"\n"+
  ATT+" rolls forward and falls in pain from the blow.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 5; }
}
if(w == 4) {
tell_room(here,
  tp+" performs a "+HIM+"Disappearing Act"+NORM+" and appears behind "+ATT+".\n"+
  tp+" slams "+ATT+" with a "+HIM+"Vicious Kitty"+NORM+" kick to the back of the neck.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 3; }
}
if(w == 5) {
tell_room(here,
  tp+" grabs "+ATT+"'s arm and inflicts an "+HIM+"Lion's Claw Trap"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 3; }
}
if(w == 6) {
tell_room(here,
  tp+" crushes "+ATT+"'s wrist with a two finger style of the "+HIM+"Venemous Lion Stare"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 2; }
}
if(w == 7) {
tell_room(here,
  tp+" follows "+ATT+"'s movements with the "+HIM+"Stalking Kitten"+NORM+".\n"+
  tp+" rocks "+ATT+" with a "+HIM+"Vicious Kitty"+NORM+" kick to the neck.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 9; }
}
if(w == 8) {
tell_room(here,
  tp+" jumps into the air, nothing but a brief shadow against the moon.\n"+
  tp+" slams "+ATT+" with the single extended foot of a "+HIM+"Hell Kitten's Stroke"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 7; }
}
if(w == 9)  {
tell_room(here,
  tp+" uses a "+HIM+"Flying Kitten Leap"+NORM+" to jump high into the air.\n"+
  tp+" performs the whirlwind motion of the "+HIM+"Furious Kitty Kick"+NORM+".\n"+
  "");
if(a == 0){ write("You hit "+ATT+" with a bone crunching sound.\n");
say(tp+" hits "+ATT+" with a bone crunching sound.\n"); }
if(a == 1){ write("You hit "+ATT+" hard.\nYou hit "+ATT+" very hard.\n");
say(tp+" hits "+ATT+" with a bone crunching sound.\n"); }
if(a == 2){ write("You hit "+ATT+" very hard.\nYou hit "+ATT+" very hard.\n");
write("You hit "+ATT+" with a bone crunching sound.\n");
say(tp+" hits "+ATT+" with a bone crunching sound.\n"); }
if(a == 3){ write("You hit "+ATT+" very hard.\nYou hit "+ATT+" hard.\n");
write("You hit "+ATT+" with a bone crunching sound.\n");
write("You hit "+ATT+" with a bone crunching sound.\n");
say(tp+" hits "+ATT+" with a bone crunching sound.\n"); }
if(call_other(this_player(),"query_attrib","wil") > random(50)) {
if(a == 0) {return 5; }
if(a == 1) {return 8; }
if(a == 2) {return 12; }
if(a == 3) {return 17; }
   }
}
if(w == 10)  {
tell_room(here,
  tp+" smashes "+ATT+" with a "+HIM+"Jaguar's Strength Punch"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 3; }
}
if(w == 11)  {
tell_room(here,
  tp+" uses the "+HIM+"Flying Kitten Leap"+NORM+" to jump high into the air.\n"+
  tp+" devastates "+ATT+" with a "+HIM+"Thrusting Leopard Kick"+NORM+" to\n"+
  "the chest. "+ATT+" falls down to the ground, writhing in pain.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 6; }
}
if(w == 12)  {
tell_room(here,
  tp+" performs a "+HIM+"Disappearing Act"+NORM+" and appears behind "+ATT+".\n"+
  tp+" sinks "+gender+" "+HIM+"Kitten Claws"+NORM+" into "+ATT+"'s collar bone and\n"+
  "performs the devastating "+HIM+"Shoulder Separator"+NORM+" manuever.\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 4; }
}
if(w == 13)  {
tell_room(here,
  tp+" slams "+ATT+" with a spinning "+HIM+"Tiger Tail Kick"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 3; }
}
if(w == 14)  {
tell_room(here,
  tp+" "+HIM+"Meows"+NORM+" loudly as "+gender+" delivers a bloody "+HIM+"Kitten's Kiss"+NORM+" to "+ATT+"'s face.\n");
if(call_other(this_player(),"query_attrib","wil") > random(50)) {
return 8; }
}
if(w == 15)  {
tell_room(here,
  tp+" surprises "+ATT+" with a spinning jump kick called the "+HIM+"Tiger Tail Kick"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 3; }
}
if(w == 16)  {
tell_room(here,
  tp+" starts to growl, the descends into a "+HIM+"Feline Frenzy"+NORM+".\n"+
  tp+" catches "+ATT+" within "+gender+" chaotic frenzy.\n"+
  tp+" rocks "+ATT+" with a flurry of "+HIM+"Kitten Claw"+NORM+" strikes.\n");
tell_room(here,
  tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 7; }
}
if(w == 17)  {
tell_room(here,
  tp+" starts to growl, then descends into a "+HIM+"Feline Frenzy"+NORM+".\n"+
  tp+" catches "+ATT+" within "+gender+" chaotic frenzy.\n"+
  tp+" rocks "+ATT+" with a flurry of "+HIM+"Kitten Claw"+NORM+" strikes.\n");
  write("You hit "+ATT+" hard.\nYou hit "+ATT+" hard.\nYou hit "+ATT+" hard.\nYou hit "+ATT+" hard.\n");
  say(tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 10; }
}
if(w == 18)  {
tell_room(here,
  tp+" jabs "+ATT+" in the eye with a "+HIM+"Kitten Tail Strike"+NORM+".\n"+
  ATT+" grabs its eye and falls over in pain.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 3; }
}
if(w == 19)  {
tell_room(here,
  tp+" jumps torwards "+ATT+" in a surprise maneuver.\n"+
  tp+" completes a "+HIM+"Leaping Tiger Kick"+NORM+", leaving a bloody\n"+
  "trail across "+ATT+"'s abdomen.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 4; }
}
if(w == 20)  {
tell_room(here,
  tp+" reverses "+gender+" direction suddenly, appearing behind "+ATT+".\n"+
  tp+" rakes "+ATT+" across the back with paired "+HIM+"Kitten Claws"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 5; }
}
if(w == 21)  {
tell_room(here,
  tp+" leaps behind "+ATT+" with a burst of "+HIM+"Pure Puma Power"+NORM+".\n"+
  tp+" flips "+ATT+" through the air with a "+HIM+"Reverse Puma's Head Throw"+NORM+".\n"+
  ATT+" hits the ground with a painful sounding 'THUD'.\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
return 5; }
}
if(w == 22)  {
tell_room(here,
  tp+" starts to growl, then descends into a "+HIM+"Feline Frenzy"+NORM+".\n"+
  tp+" catches "+ATT+" within "+gender+" chaotic display.\n"+
  tp+" staggers "+ATT+" with a slash from "+gender+" "+HIM+"Kitten Claws"+NORM+".\n");
tell_room(here,
  tp+" slashes "+ATT+" again with the deadly "+HIM+"Kitten Claw"+NORM+" strike.\n"+
  ATT+" falls back from the savage display, but "+tp+" is unrelenting\n");
tell_room(here,
  tp+" slashes "+ATT+" again with the deadly "+HIM+"Kitten Claw"+NORM+" strike.\n"+
  tp+" slashes "+ATT+" again with the deadly "+HIM+"Kitten Claw"+NORM+" strike.\n"+
  ATT+" falls to the ground in pain.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 9; }
}
if(w == 23)  {
tell_room(here,
  tp+" uses the "+HIM+"Flying Kitten Leap"+NORM+" to jump high in the air.\n"+
  tp+" descends upon "+ATT+" with the fierce strikes of the "+HIM+"Twisting Kitten"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 5; }
}
if(w == 24)  {
tell_room(here,
  tp+" dodges a deadly blow with the "+HIM+"Springing Kitty"+NORM+" maneuver.\n"+
  tp+" springs back and slashes "+ATT+" with "+gender+" "+HIM+"Kitten Claws"+NORM+" again.\n");
if(call_other(this_player(),"query_attrib","ste") > random(50)) {
return 3; }
}
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
