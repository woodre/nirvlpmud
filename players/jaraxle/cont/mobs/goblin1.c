#define WAR "/players/jaraxle/cont/war/war"

#include "/players/jaraxle/ansi.h"

inherit "players/vertebraker/closed/std/monster.c";



object gold;

object hate;



reset(arg)  {



  ::reset(arg);

  if(arg) return;



set_name("goblin");

set_alt_name("cont_goblin");

set_race("goblin");

set_short(HIG+"Goblin "+NORM+GRN+"Soldier"+NORM);

set_long(

"  This is a short but stout goblin soldier. He has greenish\n"+

"tinted skin and yellow sickly eyes. He is covered in a crude\n"+

"mismatched armor that is torn and battered in numerous places\n"+

"along his wiry body. A short weapon is in his right hand. He\n"+

"seems pretty terrified at this moment.\n");



set_level(5 + random(6));

set_al(-500);

set_dead_ob(this_object());

set_chance(5);

set_spell_dam(10);

set_heart_beat(1);

set_spell_mess1(

  "Goblin soldier runs forward and cuts his opponent!\n");

set_spell_mess2(

  "You are cut by the goblin soldiers weapon!\n");



gold = clone_object("obj/money");

gold->set_money(200 + ((level - 5) * 50));

move_object(gold,this_object());

}

init(){

  add_action("do_block_dest","dest");

  add_action("do_block_dest","destruct");

  }



do_block_dest(){  

  if(this_player()){

  if(this_player()->query_level() < 20) return 0;

  write_file("/players/jaraxle/log/DONT",

  this_player()->query_real_name()+" attempted on "+ctime(time())+"\n");

  }

  write("\n\n\n\n\n\n\n\n\n\n\n           "+HIR+"DON'T DO THAT!"+NORM+"\n\n\n\n\n\n\n\n\n");

  return 1;

  }

heart_beat(){ 

 ::heart_beat();

 if(!attacker_ob) environment()->doitanyway();

 }



monster_died() {

if(WAR->query_mobs_left(environment()->query_room_num()) > 0){

WAR->sub_mob(environment()->query_room_num());

tell_room(environment(),

"Goblin reinforcements arrive.\n");

get_goblin();

}

return 0; }



query_goblin(){ return "x24mx2x"; }



get_goblin(){

switch(random(100)+1){

case 100: 

move_object(clone_object("/players/jaraxle/cont/mobs/goblin6.c"), environment(this_object()));

break;

case 93..99:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin3.c"), environment(this_object()));

break;

case 90..92:

move_object(clone_object("/players/jaraxle/cont/mobs/ogre_merc.c"), environment(this_object()));

break;

case 76..89:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin2.c"), environment(this_object()));

break;

case 1..75:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin1.c"), environment(this_object()));

break;

}



}

