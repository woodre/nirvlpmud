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
set_race("human");

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
    soldier12();
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

/* individual soldier variables */                            
soldier9(){
dif_sold=1;
set_short("A Sickly patient"+NORM+"");
set_long(  "This is a frail old man, who is very sick.  It looks like he \n"+
           "has come to the hospital to die.\n");
set_name("Sickly patient");
set_alt_name("patient");
set_alias("sickly patient");
set_level(16);
set_hp(400+random(200));
set_aggressive(0);
set_heal(4,2);
set_ac(20);
set_gender("male");
set_wc(21+random(5));
set_al(250);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("Patient says: I think I soiled myself.\n");
add_spell("barrage",
"#MN# wipes his sickness on you!#RET#You hope he doesn't have Ebola.\n",
"#MN# wipes his sickness on #TN#!#RET##TN# hopes its not Ebola.\n",
 25,"20-35","other|poison",1);

}

soldier10(){
dif_sold=2;
set_short("A Patient"+NORM+"");
set_long(
           "This is a female patient.  She appears to have some sort of unknown\n"+
           "sickness.  She is very irritated and wants to get out of this place.\n");
set_name("A Patient"+NORM+"");
set_alt_name("patient");
set_alias("a patient");
set_level(17);
set_hp(500+random(200));
set_ac(24);
set_gender("female");
set_wc(26+random(6));
set_heal(6, 8);
set_al(250);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("Patient says: Where is the nurse!\n");
add_spell("charm",
"#MN# shoves you to the ground!\n",
"#MN# shoves #TN# to the ground!\n",
25,"25-40",0,0);
}

soldier12(){
dif_sold=3;
set_short("A child patient"+NORM+"");
set_long(
           "This is a sick child.  He seems to be in an almost zombie state.\n"+
           "He moves around very slowly, but appears to have abnormally high\n"+
           "strength.\n");
set_name("A child patient"+NORM+"");
set_alt_name("child patient");
set_alias("patient");
set_level(19);
set_hp(650+random(200));
set_ac(26);
set_gender("child");
set_wc(22+random(15));
set_aggressive(0);
set_heal(5, 10);
set_al(500);
set_dead_ob(this_object());
set_chat_chance(10);
 load_chat("Child says: I need brains do you have brains?\n");
add_spell("barrage",
"#MN# leaps up and "+HIW+"bites"+NORM+" you on the neck!\n"+HIR+"Blood"+NORM+" flows from your neck!\n",
"#MN# leaps up and "+HIW+"bites"+NORM+" #TN# on the neck!\n"+HIR+"Blood"+NORM+" flows from #TN#'s neck\n",
 25,"25-55","other|magic",0);
}
soldier13(){
dif_sold=4;
set_short(""+HIW+"A Nurse"+NORM+"");
set_long(
           "This is a female nurse.  She is heavier set and has been around\n"+
           "long enough to see almost anything.  She wear comfortable white shoes\n"+
           "with matching pants and a collared white shirt.\n");
set_name(""+HIW+"A Nurse"+NORM+"");
set_alt_name("nurse");
set_alias("a nurse");
set_level(18);
set_hp(550+random(200));
set_ac(25);
set_gender("female");
set_wc(22+random(10));
set_al(500);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("Nurse says: watch out, I'm the only who knows what they are doing here!\n");
 add_spell("barrage",
"#MN# smashes you over the head with a bedpan!#RET#Urine drips down your face.\n",
"#MN# smashes #TN# over the head with a bedpan!#RET#Urine drips down #TN#'s face.\n",
 25,"20-55","other|magic",1);


}


id(str) { return (::id(str) || str == "sick person"); }
heart_beat(){
int z;
  if(!this_object()) return;
::heart_beat();

}

/*
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
*/
self_attack( object target, object room, int damage ) {
  int wep;
  int dam_amt;
  string pname;
  string *amess;

  if( !target || !environment() )
    return;

  wep = target->query_name_of_weapon();
  pname = target->query_name();
  dam_amt = 15 + random (20);
  if( !wep ) {
  tell_room(environment(),
    pname+" massacres "+pname+" into tiny fragments.\n");
  return 1;
  }
  else {
   amess =  wep->query_message_hit( dam_amt );
   tell_room(environment(), pname+" "+amess[1]+" "+pname+amess[0]+".\n");
  return 1;
  }
}