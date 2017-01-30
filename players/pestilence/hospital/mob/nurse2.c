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

/* individual soldier variables */                            
soldier9(){
dif_sold=1;
set_short(""+WHT+"An orderly"+NORM+"");
set_long(
           "This is a lowly orderly, who takes orders from the nurses.  He is here\n"+
           "to clean any messes, change bedpans and deal with anything else the\n"+
           "nurses don't feel like doing.\n");
set_name(""+WHT+"An orderly"+NORM+"");
set_alt_name("orderly");
set_alias("an orderly");
set_level(16);
set_hp(400+random(200));
set_aggressive(1);
set_heal(4,2);
set_ac(20);
set_gender("male");
set_wc(21+random(5));
set_al(50);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("An Orderly says: do this, do that. I'm sick of this shit!\n");
add_spell("barrage",
"#MN# smashes you over the head with a bedpan!#RET#Urine drips down your face.\n",
"#MN# smashes #TN# over the head with a bedpan!#RET#Urine drips down #TN#'s face.\n",
 25,"20-55","other|magic",1);

}

soldier10(){
dif_sold=2;
set_short(""+HIW+"A voluptuous Nurse"+NORM+"");
set_long(
           "This is a very shapely blonde nurse.  Her uniform is very tight\n"+
           "and reveals a large amount of cleavage.  The skirt part of the uniform\n"+
           "ends just below the butt cheeks.  This is where you see a nice garter belt\n"+
          "holding up a pair of fishnet stockings.  It's obvious she was hired for her\n"+
           "looks and not her skill set.\n");
set_name(""+HIW+"A voluptuous Nurse"+NORM+"");
set_alt_name("voluptuous nurse");
set_alias("nurse");
set_level(17);
set_hp(500+random(200));
set_ac(24);
set_gender("female");
set_wc(26+random(6));
set_heal(6, 8);
set_al(250);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("Voluptuous nurse says: Orderly!! Orderly clean up this shit!\n");
add_spell("charm",
"#MN# distracts you with her breasts!\nYou swing wildly.\n",
"#MN# distracts #TN# with her breasts!\n#TN# swings wildly.\n",
25,"5-40",0,0,"self_attack");
}

soldier12(){
dif_sold=3;
set_short(""+HIW+"A Male Nurse"+NORM+"");
set_long(
           "This is one of those male nurses.  He is very fit and appears to be\n"+
           "able to handle anything that comes up in the hospital.  He wears long\n"+
           "white pants, and a short sleeve collared shirt.\n");
set_name(""+HIW+"A Male Nurse"+NORM+"");
set_alt_name("male nurse");
set_alias("nurse");
set_level(19);
set_hp(650+random(200));
set_ac(26);
set_gender("male");
set_wc(22+random(15));
set_aggressive(0);
set_heal(5, 10);
set_al(500);
set_dead_ob(this_object());
set_chat_chance(10);
 load_chat("Nurse says: watch out I have work to do.\n");
add_spell("barrage",
"#MN# stabs you with a needle.\n"+HIR+"Blood"+NORM+" flows from your arm!\n",
"#MN# stabs #TN# with a needle.\n"+HIR+"Blood"+NORM+" flows from #TN#'s arm!\n",
 25,"20-55","other|magic",1);
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


id(str) { return (::id(str) || str == "hospital_help"); }
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