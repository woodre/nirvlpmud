#include "/players/saber/closed/esc.h"
#include <ansi.h>
/******************************************************************************
 * Posted this For Approval Purpose!!
 * Program: hamato.c
 * Path: /players/wicket/ninja_turtles/weapons
 * Type: weapom
 * Created: Sat Oct  4 07:01:51 2014 CST by Wicket
 *
 *  Tested on testmob.c for damage out put.
 *  Comparison of /players/wicket/ninja_turtles/weapons/hamato.c to 
 *                /players/jenny/wings/items/gstick.c
 *   Gordie Stick damage over 100 Rounds!
 *    physical   : 1672 | 16
 *    Tot Damage : 1672
 *    Rounds     : 100
 *    Avg Damage : 16
 *    Max Damage : 58
 *
 *  Hamato Ninjutsu damge over 100 Rounds!
 *    physical   : 1677 | 16
 *    Tot Damage : 1677
 *    Rounds     : 102
 *    Avg Damage : 16
 *    Max Damage : 42
 ******************************************************************************/
#define ATT capitalize(attacker->query_name())
#define tp this_player()->query_name()
int a, w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("hamato");
set_alias("ninjutsu");
set_type("exotic");
set_alt_name("ninjutsu");
set_short(BOLD+"Hamato Ninjutsu"+NORM);
set_long("The Ancient art of ninjutsu that Master Splinter had learned\n"+
         "from his master Hamato Yoshi while he was still a normal rat.\n"+
         "His master practiced this art every day faithfully, in doing\n"+
         "so Splinter followed his moves and thus learned the ancient\n"+
         "art of Hamato Ninjutsu.\n");
set_class(17);
set_weight(2);
set_value(25000);
set_hit_func(this_object());
}

weapon_hit(attacker){
string style, attack, attackm;
string here;
string color, backstr;
string gender,gender2,ogender,ogender2;

  /** Gnar **/
  if( !attacker )
    return 0;

   w=random(25);
   a=random(4);
ogender2 = attacker->query_objective();
ogender = attacker->query_possessive();
gender = this_player()->query_possessive();
here = environment(this_player());

if(w == 0) {
tell_room(here,
  tp+" races across the room with a "+BOLD+"Kikaku"+NORM+"-"+BOLD+"Ken"+NORM+" maneuver.\n"+
  tp+" attacks with the strength of "+RED+"Demon Horns Fist"+NORM+" and strikes\n"+
  "into "+ATT+"'s head.\n");
if(call_other(this_player(),"query_attrib","wil") > random(30))  {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 1) {
tell_room(here,
  tp+" rakes "+ATT+" across the face with a "+RED+"vicious "+BOLD+"Shitan"+NORM+"-"+BOLD+"Ken"+NORM+".\n"); 
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 2) {
tell_room(here,
  tp+" crushes "+ATT+"'s throat with a devastating "+BOLD+"Tai"+NORM+"-"+BOLD+"Ken"+NORM+" strike.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 3) {
tell_room(here,
  tp+" rolls forward and strikes "+ATT+" with the deadly\n"+
  "                "+BOLD+"Zenpo Kaiten"+NORM+"\n"+
  ATT+" rolls backwards and falls in pain from the blow.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 4) {
tell_room(here,
  tp+" performs a "+HIK+"Disappearing Act"+NORM+" and appears behind "+ATT+".\n"+
  tp+" doing a "+BOLD+"Omote Gyaku Grab"+NORM+" on "+ATT+" snapping their wrist\n"+
     " and throwing them to the ground.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 5) {
tell_room(here,
  tp+" grabs "+ATT+"'s arm and inflicts an "+BOLD+"Ura Kote Gyaku"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
		
if(w == 6) {
tell_room(here,
  tp+" crushes "+ATT+"'s wrist with a extended knuckle style of the "+BOLD+"Shikan"+NORM+"-"+BOLD+"ken"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 7) {
tell_room(here,
  tp+" follows "+ATT+"'s movements with silent moves of "+BOLD+"Shinobi Aruki"+NORM+".\n"+
  tp+" blasts "+ATT+" with a "+BOLD+"Fudo"+NORM+"-"+BOLD+"Ken"+NORM+" punch to the neck.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 8) {
tell_room(here,
  tp+" jumps into the air, nothing but a brief shadow against the moon.\n"+
  tp+" slams "+ATT+" with the single extended foot of a "+BOLD+"Sokuyaku"+NORM+"-"+BOLD+"ken"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

if(w == 9)  {
tell_room(here,
  tp+" uses the "+BOLD+"Happo"+NORM+"-"+BOLD+"geri technique"+NORM+" to jump high into the air.\n"+
  tp+" performs the "+CYN+"whirlwind motion"+NORM+" of the "+BOLD+"Happo"+NORM+"-"+BOLD+"geri"+NORM+".\n"+
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
if(call_other(this_player(),"query_attrib","wil") > random(30)) {
if(a == 0) {        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		 }
if(a == 1) {        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		 }
if(a == 2) {        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		 }
if(a == 3) {        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		 }
   }
}
if(w == 10)  {
tell_room(here,
  tp+" smashes "+ATT+" with a "+GRN+"Mantis "+RED+"Crab "+BOLD+"Fist"+NORM+".\n");
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 11)  {
tell_room(here,
  tp+" uses the "+BOLD+"Musha Dori"+NORM+" to jump high into the air.\n"+
  tp+" devastates "+ATT+" with a "+YEL+"Ude Jime Ashi Ori Gata Elbow"+NORM+" to\n"+
  "the chest. "+ATT+" falls down to the ground, writhing in pain.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 12)  {
tell_room(here,
  tp+" performs a "+MAG+"Ku No Kata"+NORM+" and appears behind "+ATT+".\n"+
  tp+" sinks "+gender+" "+HIR+"finger tips"+NORM+" into "+ATT+"'s collar bone and\n"+
  "performs the devastating "+BOLD+"Hane"+NORM+"-"+BOLD+"Koshi Nage"+NORM+" manuever.\n");
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 13)  {
tell_room(here,
  tp+" slams "+ATT+" with a spinning "+BOLD+"Keri"+NORM+"-"+BOLD+"kudaki Kick"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 14)  {
tell_room(here,
  tp+" "+HIR+"SCREAMS"+NORM+" loudly as "+gender+" delivers a deadly "+HIR+"Ka No Kata Kiss"+NORM+" to "+ATT+"'s face.\n");
if(call_other(this_player(),"query_attrib","wil") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(5), "physical");
		}
}
if(w == 15)  {
tell_room(here,
  tp+" surprises "+ATT+" with a spinning jump sweep called the "+BOLD+"Hari goshi"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 16)  {
tell_room(here,
  tp+" starts to growl, the descends into a "+BOLD+"Jumonji No Kamae"+NORM+".\n"+
  tp+" catches "+ATT+" within "+gender+" chaotic frenzy.\n"+
  tp+" rocks "+ATT+" with a flurry of "+HIC+"Shiho Tenchi Tobi "+NORM+"kicks.\n");
tell_room(here,
  tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n"+tp+" hits "+ATT+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 17)  {
tell_room(here,
  tp+" starts to growl, then descends into a "+BOLD+"Ichimonji No Kamae"+NORM+".\n"+
  tp+" catches "+ATT+" within "+gender+RED+" chaotic frenzy"+NORM+".\n"+
  tp+" rocks "+ATT+" with a flurry of "+HIB+"Hokenn Juroppo Fist"+NORM+" strikes.\n");
  write("You hit "+ATT+" hard.\nYou hit "+ATT+" hard.\nYou hit "+ATT+" hard.\nYou hit "+ATT+" hard.\n");
  say(tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n"+tp+" hits "+ATT+" hard.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 18)  {
tell_room(here,
  tp+" jabs "+ATT+" in the eye with a "+BOLD+"Shishin"+NORM+"-"+BOLD+"Ken Jab"+NORM+".\n"+
  ATT+" grabs its eye and falls over in pain.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 19)  {
tell_room(here,
  tp+" jumps torwards "+ATT+" in a surprise maneuver.\n"+
  tp+" completes a "+BOLD+"Sokki"+NORM+"-"+BOLD+"ken Knee"+NORM+", leaving a "+HIR+"bloody\n"+
  "trail "+NORM+"across "+ATT+"'s face.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 20)  {
tell_room(here,
  tp+" reverses "+gender+" direction suddenly, appearing behind "+ATT+".\n"+
  tp+" rakes "+ATT+" across the back with paired "+BOLD+"Shito"+NORM+"-"+BOLD+"ken"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 21)  {
tell_room(here,
  tp+" leaps behind "+ATT+" with a burst of "+BOLD+"Oogyaku"+NORM+".\n"+
  tp+" flips "+ATT+" through the air with a "+HIY+"Tomoe"+NORM+"-"+HIY+"nage Throw"+NORM+".\n"+
  ATT+" hits the ground with a painful sounding 'THUD'.\n");
if(call_other(this_player(),"query_attrib","str") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 22)  {
tell_room(here,
  tp+" starts to growl, then descends into a "+BOLD+"Hicho No Kamae"+NORM+".\n"+
  tp+" catches "+ATT+" within "+gender+" chaotic display.\n"+
  tp+" staggers "+ATT+" with a slash from "+gender+" "+HIR+"Ki"+NORM+"-"+HIR+"ken"+NORM+".\n");
tell_room(here,
  tp+" slashes "+ATT+" again with the deadly "+HIR+"Ki"+NORM+"-"+HIR+"ken"+NORM+" strike.\n"+
  ATT+" falls back from the savage display, but "+tp+" is unrelenting\n");
tell_room(here,
  tp+" slashes "+ATT+" again with the deadly "+HIR+"Ki"+NORM+"-"+HIR+"ken"+NORM+" strike.\n"+
  tp+" slashes "+ATT+" again with the deadly "+HIR+"Ki"+NORM+"-"+HIR+"ken"+NORM+" strike.\n"+
  ATT+" falls to the ground in pain.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 23)  {
tell_room(here,
  tp+" uses the "+BOLD+"Sokugyaku technique"+NORM+" to jump high in the air.\n"+
  tp+" descends upon "+ATT+" with the fierce kicks of the "+BOLD+"Sokugyaku"+NORM+".\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}
if(w == 24)  {
tell_room(here,
  tp+" dodges a deadly blow with the "+BOLD+"Ura Oni-kudaki"+NORM+" maneuver.\n"+
  tp+" springs back and slashes "+ATT+" with "+gender+" "+HIG+"Ken"+NORM+"-"+HIG+"Kudaki"+NORM+" again.\n");
if(call_other(this_player(),"query_attrib","ste") > random(30)) {
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
		}
}

}
