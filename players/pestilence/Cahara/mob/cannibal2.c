/*     Basic code framework for the soldier switch      */
/*     borrowed from the following:                             */
/*            /open/maledicta/dusan/guard.c                     */

#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define attacker attacker_ob
int dif_sold;

reset(arg){
  ::reset(arg);
  if(arg) return;
set_race("army ant");

switch(random(7)){
case 0:
    soldier9();
    break;
case 1:
    soldier9();
    break;
case 2:
    soldier10();
    break;
case 3:
    soldier10();
    break;
case 4:
    soldier9();
    break;
case 5:
    soldier10();
    break;
case 6:
    soldier9();
    break;
default:
    soldier10();

    break;
  }
}       

/* individual soldier varibles */                            
soldier9(){
dif_sold=1;
set_short("A small cannibal child");
set_long(
           "Thi is a small child, maybe around the age of 10.  It's hard to tell\n"+
           "if the child is a boy or girl.  The 10 or so years appear to been hard\n"+
           "on this child.\n");
set_name(""+YEL+"Cannibal child"+NORM+"");
set_alt_name("cannibal child");
set_alias("child");
set_level(10);
set_hp(100+random(50));
set_aggressive(1);
set_heal(1,1);
set_ac(8);
set_gender("male");
set_wc(10+random(5));
set_wc_bonus(1);
set_al(-550);
set_dead_ob(this_object());
set_chat_chance(1);
  load_chat("The child says: mmm dad would put you into a nice soup.\n");
  load_chat("The child drools.\n");
set_a_chat_chance(4);
  load_a_chat("The child says: I can see your flesh tastes nice.\n");
set_chance(10);
set_spell_dam(5+random(20));
set_spell_mess1(
  "The child kicks his attacker in the leg..");
set_spell_mess2(
  "The child kicks you in the leg.");

}

soldier10(){
dif_sold=2;
set_short(""+YEL+"A Cannibal woman"+NORM+"");
set_long(
           "This is a cannibal woman.  She is a well built woman, very muscular.\n"+
           "She stands just short of 6 feet tall, and looks well versed in the arts of\n"+
           "combat.  There are several scars on her arms, obviously coming from\n"+
           "previous meals, before they became meals.\n");
set_name(""+YEL+"Cannibal woman"+NORM+"");
set_alt_name("cannibal woman");
set_alias("woman");
set_level(17);
set_hp(400+random(200));
set_ac(14);
set_gender("female");
set_wc(22+random(6));
set_wc_bonus(1);
set_heal(6, 8);
set_al(-250);
set_dead_ob(this_object());
set_chat_chance(1);
  load_chat("The woman says: Kidema will show you!!.\n");
  load_chat("The woman says: Kidema can't be killed!!.\n");
set_a_chat_chance(2);
  load_a_chat("The woman tries to bite you.\n");
  load_a_chat("The woman takes a bite out of your leg.\n");
set_multi_cast(1);
set_chance(15);
set_spell_dam(30+random(20));
set_spell_mess1(
  ""+YEL+"The cannibal woman"+NORM+" lunges for it's attackers throat, just leaving a large "+HIR+"bite"+NORM+".");
set_spell_mess2(
  ""+YEL+"The cannibal woman"+NORM+" lunges for your throat, leaving a large "+HIR+"bloody bite"+NORM+".");
add_spell("bone tear",
  "#MN# bites your arm very hard.\n",
  "#MN# bites #TN#'s arm very hard.\n",
   20,35,"physical");
add_spell("bone tear",
  "#MN# smashes your head with her fist.\n",
  "#MN# smashes #TN#'s head with her fist.\n",
   15,35,"physical",1);

}

soldier12(){
dif_sold=3;
set_short(""+RED+"A Lieutenant Army Ant"+NORM+"");
set_long(
           "This a lieutenant army ant.  He has been an army ant a long time to\n"+
           "be an officer.  He has to be one of the leaders in the invasion of\n"+
           "the village of Amity.  This ant is eleven feet tall, with six strong\n"+
           "legs with three joints on each leg.  It has a long jaw with several\n"+
           "very sharp teeth.  This ant has a small mark on its thorax, as if it\n"+
           "was showing its rank.  This would symbolize that the ants have a form\n"+
           "of intelligence.\n");
set_name(""+HIR+"Lieutenant army ant"+NORM+"");
set_alt_name("lieutenant army ant");
set_alias("ant");
set_level(19);
set_hp(550+random(200));
set_ac(16);
set_gender("male");
set_wc(22+random(15));
set_wc_bonus(9);
set_aggressive(0);
set_heal(5, 10);
set_al(-500);
set_dead_ob(this_object());
set_chat_chance(20);
 load_chat("The ant throws you to the ground.\n");
  load_chat("The ant circles around you with disgust.\n");
set_a_chat_chance(25);
  load_a_chat("The ant grapples you to the ground .\n");
  load_a_chat("The ant attacks you with four of its legs.\n");
set_chance(25);
set_spell_dam(35+random(25));
set_spell_mess1(
  ""+HIB+"The ant tears into it's attacker torso, "+HIR+"eviscerating"+NORM+" them.");
set_spell_mess2(
  ""+HIB+"The ant tears into your torso, "+HIR+"eviscerating"+NORM+" you.");

}
soldier13(){
dif_sold=4;
set_short(""+HIK+"A Sergeant Army Ant"+NORM+"");
set_long(
           "This is a sergeant army ant.  There are many scars on his body.  You\n"+
           "can tell he has been in many battles, and this is how he achieved his\n"+
           "rank of sergeant.  The ant is ten feet tall, with six, three jointed legs\n"+
           "making him very mobile.  A long jaw with very sharp teeth makes him a very\n"+
           "tough opponent to fight.\n");
set_name(""+HIK+"Sergeant army ant"+NORM+"");
set_alt_name("sergeant army ant");
set_alt_name("army ant");
set_alias("ant");
set_level(18);
set_hp(450+random(200));
set_ac(15);
set_gender("male");
set_wc(22+random(10));
set_wc_bonus(9);
set_al(-500);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The ant pokes at you with its antennae.\n");
  load_chat("The ant lifts you and shakes you, then puts you back down.\n");
set_a_chat_chance(25);
  load_a_chat(""+RED+"The ant spits acid at you"+NORM+".\n");
load_a_chat(""+BLU+"The ant spins around and tries to sting you"+NORM+".\n");
set_chance(25);
set_spell_dam(30+random(25));
set_spell_mess1(
  "The ant slashes its attacker's legs with its sharp teeth.");
set_spell_mess2(
  "The ant slashes your legs with its sharp teeth.");

}


id(str) { return (::id(str) || str == "cannibal"); }
heart_beat(){
int z;
  if(!this_object()) return;
::heart_beat();

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
   tell_room(environment(this_object()), 
  "The ant lashes out, tearing "+HIR+"flesh"+NORM+" from it's foe.\n");
  tell_object(attacker_ob,
  "The ant lashes out, ripping into your skin causing alot of pain"+NORM+".\n");
    attacker->hit_player(30 +random(30));
     }
}
}


monster_died() {
if(dif_sold == 1) {  tell_room(environment(this_object()),
        "As the ant dies, the antennae breaks off from his head.\n"),
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 2) {  tell_room(environment(this_object()),
        "As the ant dies, the antennae breaks off from his head.\n"),
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 3) {  tell_room(environment(this_object()),
"As the ant dies, the thorax breaks off from his body.\n"),
  move_object(clone_object("/players/pestilence/amity/obj/thorax.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 4) {  tell_room(environment(this_object()),
        "As the ant dies, the metasoma breaks off from his rear.\n"),
  move_object(clone_object("/players/pestilence/amity/obj/metasoma.c"),
      environment(this_object()));
return 1;
}
}
