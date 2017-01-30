#include "/players/jaraxle/ansi.h"

#define OPP attacker_ob->query_name()

#define WAR "/players/jaraxle/cont/war/war.c"

inherit "obj/monster.c";



object enemy;



reset(arg)  {

 ::reset(arg);

  if(arg) return;

set_name("king");

set_alt_name("garshlog");

set_race("goblin");

set_short(BOLD+"Garshlog, the "+NORM+GRN+"Goblin King"+NORM);

set_long(

" This is the huge Goblin King, Garshlog. His body is\n"+

"very fat, from his many plunderings, and his face is\n"+

"large and round with many folds of rough green skin\n"+

"hanging from it. The goblins hands are large, and\n"+

"hold a large cleaver at the ready. His body is covered\n"+

"with tight fitting armor, mostly scavenged, that protects\n"+

"him against most attacks. He seems ready for combat.\n");

set_level(24);

set_hp(2400);

set_al(-1000);

set_heal(8,2);

set_wc(50);

set_ac(22);

set_wc_bonus(50);

set_heart_beat(1);

set_chance(30);

set_dead_ob(this_object());

set_spell_dam(60);

set_spell_mess1(

"The "+HIG+"Goblin King "+HIR+"Cleaves"+NORM+" into his opponent!\n");

set_spell_mess2(

"You feel the sharp edge of the King's cleaver bite deep into your skin!\n");

}







init(){

 ::init();

 add_action("nogo", "out");

 }



nogo(){ 

  write("The Goblin King laughs, grabbing you roughly and slinging you from the door!\n");

  this_player()->hit_player(30);

  return 1;

  }







heart_beat(){

object oldopp;



::heart_beat();



if(random(100) < 60){

  if(attacker_ob && !attacker_ob->query_ghost()){

tell_room(environment(),

"                    "+HIR+"- --- "+HIW+"!!!The Goblin King Goes into a BERSERK rage!!!"+HIR+" --- -"+NORM+"\n");

  already_fight=0;

  attack();

  }

 }

if(attacker_ob && alt_attacker_ob != attacker_ob){

 if(!alt_attacker_ob->query_ghost()){

 if(random(100) < 50){

   oldopp = attacker_ob;

   attacker_ob = alt_attacker_ob;

tell_room(environment(),

"\n"+GRN+"<"+HIG+"<<>>"+NORM+GRN+"> "+HIG+"THE GOBLIN KING CHARGES "+attacker_ob->query_name()+"!!!"+NORM+"\n\n");

   already_fight = 0;

   attack();

   attacker_ob = oldopp;

   }

  }

 }



enemy = attacker_ob;



 if(enemy && !attacker_ob){

  if(environment() == environment(enemy)){

    tell_room(environment(),

    "The Goblin King gives out a loud battle cry and charges!!!\n\n\n"); 

    attack_object(enemy);

   }

 }

}



monster_died(){

int amount;

amount = random(500000) + 1800000;

tell_room(environment(),

"As the Goblin King falls to the ground dead he cries out,\n"+

"a swelling of blood frothing up from his lips.\n\n"+

"He dies.\n");

tell_room(environment(),

"\n\nIn a nearby chest you find the Goblins Treasure...\n"+

"You add "+amount+" to the Templar donation!\n"+

"There is also something else...and it glimmers..\n\n");

move_object(clone_object("/players/jaraxle/cont/war/excalibur.c"), environment());

write_file("/players/jaraxle/cont/war/WON!",

"King defeated on "+ctime(time())+" :: "+amount+".\n");

WAR->kill_king();

return 1;

}