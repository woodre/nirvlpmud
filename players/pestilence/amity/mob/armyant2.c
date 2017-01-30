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
    soldier12();
    break;
case 4:
    soldier13();
    break;
case 5:
    soldier10();
    break;
case 6:
    soldier9();
    break;
default:
    soldier9();

    break;
  }
}       

/* individual soldier varibles */                            
soldier9(){
dif_sold=1;
set_short("A "+HIB+"Private Army Ant"+NORM+"");
set_long(
           "This a giant ant.  He is part of the ant army.  He has six legs and\n"+
           "a jaw with very sharp teeth.  The ant has the strength to carry things\n"+
           "over twenty times his own weight.\n");
set_name(""+HIB+"Private army ant"+NORM+"");
set_alt_name("private army ant");
set_alias("ant");
set_level(16);
set_hp(300+random(200));
set_aggressive(1);
set_heal(4,2);
set_ac(13);
set_gender("male");
set_wc(21+random(5));
set_wc_bonus(9);
set_al(-550);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The Private ant lashes at you.\n");
  load_chat("The Private ant circles around you.\n");
set_a_chat_chance(25);
  load_a_chat(""+HIK+"The ant strikes out"+NORM+".\n");
  load_a_chat(""+HIB+"The ant strikes you with his hind legs"+NORM+".\n");
set_chance(25);
set_spell_dam(25+random(20));
set_spell_mess1(
  "The ant lashes out with it's jaws, striking it's attacker leaving a deep "+RED+"gouge"+NORM+".");
set_spell_mess2(
  "The ant lashes out at you, leaving a deep "+RED+"gouge"+NORM+".");
add_spell("private tear",
"#MN# lashes out, tearing $HR$flesh$N$ from you.\n",
"#MN# lashes out, tearing $HR$flesh$N$ from #TN#.\n",
 20,45,"physical",6);
}

soldier10(){
dif_sold=2;
set_short(""+BLU+"A Corporal Army Ant"+NORM+"");
set_long(
           "This is a corporal army ant.  He is an ant with slightly more power\n"+
           "than that of the private.  He the same size, being ten feet tall.\n"+
           "The ant is long and black, with six legs with three joints on each leg,\n"+
          "and has two large attennae protruding from it's head.  It also has a long\n"+
           "jaw with very sharp teeth.  They are sharp enough to remove a human's head\n"+
           "with one bite.\n");
set_name(""+BLU+"Corporal army ant"+NORM+"");
set_alt_name("corporal army ant");
set_alias("ant");
set_level(17);
set_hp(400+random(200));
set_ac(14);
set_gender("male");
set_wc(22+random(6));
set_wc_bonus(9);
set_heal(6, 8);
set_al(-250);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The ant pushes you to the ground.\n");
  load_chat("The ant taunts you into fighting it.\n");
set_a_chat_chance(25);
  load_a_chat("The ant kicks you with its hind legs.\n");
  load_a_chat("The ant bites at your throat.\n");
set_chance(25);
set_spell_dam(30+random(20));
set_spell_mess1(
  ""+BLU+"The ant lunges for it's attackers throat, just leaving a large "+HIR+"gash"+NORM+".");
set_spell_mess2(
  ""+BLU+"The ant lunges for your throat, leaving a large "+HIR+"bloody gash"+NORM+".");
add_spell("Corporal tear",
"#MN# lashes out, tearing $HR$flesh$N$ from you.\n",
"#MN# lashes out, tearing $HR$flesh$N$ from #TN#.\n",
 20,55,"physical",6);

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
add_spell("lieutenant tear",
"#MN# lashes out, tearing $HR$flesh$N$ from you.\n",
"#MN# lashes out, tearing $HR$flesh$N$ from #TN#.\n",
 25,55,"physical",6);

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
add_spell("sargeant tear",
"#MN# lashes out, tearing $HR$flesh$N$ from you.\n",
"#MN# lashes out, tearing $HR$flesh$N$ from #TN#.\n",
 25,50,"physical",6);

}


id(str) { return (::id(str) || str == "insect"); }
heart_beat(){
int z;
  if(!this_object()) return;
::heart_beat();

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>9){
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
  move_object(clone_object("/players/pestilence/amity/obj/antennae.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 2) {  tell_room(environment(this_object()),
        "As the ant dies, the antennae breaks off from his head.\n"),
  move_object(clone_object("/players/pestilence/amity/obj/antennae.c"),
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
