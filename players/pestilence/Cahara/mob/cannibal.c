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
    soldier12();
    break;
case 5:
    soldier13();
    break;
case 6:
    soldier12();
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
add_spell("fist smash",
  "#MN# smashes your head with her fist.\n",
  "#MN# smashes #TN#'s head with her fist.\n",
   15,35,"physical",1);

}

soldier12(){
dif_sold=3;
set_short(""+YEL+"A Cannibal hunter"+NORM+"");
set_long(
           "This is a male cannibal hunter.  He mainly searches the island\n"+
           "for animals and other kinds of meat, when humans can't be found.\n"+
           "Just because he hunts animals, doesn't make a formidable opponent\n"+
           "for adventurers.\n");
set_name(""+YEL+"Cannibal Hunter"+NORM+"");
set_alt_name("cannibal hunter");
set_alias("hunter");
set_level(19);
set_hp(550+random(200));
set_ac(16);
set_gender("male");
set_wc(22+random(15));
set_wc_bonus(1);
set_aggressive(0);
set_heal(5, 10);
set_al(-500);
set_dead_ob(this_object());
set_chat_chance(1);
  load_chat("The cannibal hunter says: Have you seen some meat?\n");
  load_chat("The cannibal hunter says: Hey wait your meat!!\n");
set_a_chat_chance(2);
  load_a_chat("The cannibal hunter tackles you to the ground.\n");
set_multi_cast(1);
set_chance(20);
set_spell_dam(35+random(25));
set_spell_mess1(
  "The hunter spears his attacker.");
set_spell_mess2(
  "The hunter spears you deeply, causing you to feel immense pain.");
add_spell("bone crush",
  "#MN# hits your with a fierce blow, smashing your bones.\n",
  "#MN# smashes #TN#'s bones with a fierce blow.\n",
   20,35,"physical");
add_spell("bone expose",
  "#MN# tears your flesh open, exposing bone.\n",
  "#MN# tears #TN#'s flesh open, exposing bone.\n",
   15,35,"physical",1);

}
soldier13(){
dif_sold=4;
set_short(""+YEL+"A Cannibal Fighter"+NORM+"");
set_long(
           "This is a large cannibal fighter.  They train solely to kill and fight off\n"+
           "opposing tribes.  One can see that he has been in many fights, and\n"+
           "has been successful, for a cannibal fight is always to the death, and\n"+
           "they fight for their lives and to not be dinner for their attackers family.\n");
set_name(""+YEL+"Cannibal Fighter"+NORM+"");
set_alt_name("cannibal fighter");
set_alt_name("fighter");
set_alias("ant");
set_level(20);
set_hp(600+random(200));
set_ac(20);
set_gender("male");
set_wc(32+random(10));
set_wc_bonus(1);
set_al(-500);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The cannibal fighter says: You will die by my hands.\n");
set_a_chat_chance(25);
  load_a_chat(""+YEL+"The fighter jumps at you"+NORM+".\n");
set_multi_cast(1);
set_chance(25);
set_spell_dam(30+random(25));
set_spell_mess1(
  "The Cannibal fighter knocks his attacker to the ground.");
set_spell_mess2(
  "The Cannibal fighter knocks you to the ground.");
add_spell("bone crush",
  "#MN# hits your with a fierce blow, smashing your bones.\n",
  "#MN# smashes #TN#'s bones with a fierce blow.\n",
   20,45,"physical");
add_spell("bone expose",
  "#MN# tears your flesh open, exposing bone.\n",
  "#MN# tears #TN#'s flesh open, exposing bone.\n",
   15,45,"physical",1);


}


id(str) { return (::id(str) || str == "cannibal"); }


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
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 4) {  tell_room(environment(this_object()),
        "As the ant dies, the metasoma breaks off from his rear.\n"),
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
      environment(this_object()));
return 1;
}
}
