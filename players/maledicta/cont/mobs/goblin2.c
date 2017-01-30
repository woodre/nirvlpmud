#define WAR "/players/maledicta/cont/war/war"
#include "/players/maledicta/ansi.h"
inherit "players/vertebraker/closed/std/monster.c";

object gold;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("goblin");
set_alt_name("cont_goblin");
set_race("goblin");
set_short(YEL+"Goblin "+NORM+HIW+"Wolf"+BOLD+"rider"+NORM);
set_long(
"  This is a small green skinned goblin on the back\n"+
"of a large dire wolf. He is carrying a long spear\n"+
"and is covered in a light leather armor. His yellow\n"+
"eyes are narrowed and staring at you. The wolf is\n"+
"covered in a thick black fur with cold blue eyes\n"+
"glaring at you hungrily.\n");
set_level(15);
set_al(-500);
set_dead_ob(this_object());
set_chance(5);
set_spell_dam(10);
set_spell_mess1(
  "Goblin wolfrider tears into his opponent!\n");
set_spell_mess2(
  "You are bit and struck by the wolfrider and his mount!\n");
gold = clone_object("obj/money");
gold->set_money(800 + random(400));
move_object(gold,this_object());
}

init(){
  add_action("do_block_dest","dest");
  add_action("do_block_dest","destruct");
  }

do_block_dest(){  
  if(this_player()){
  if(this_player()->query_level() < 20) return 0;
  write_file("/players/maledicta/log/DONT",
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
tell_room(environment(),
"The rider and mount fall to the ground and die.\n");
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
move_object(clone_object("/players/maledicta/cont/mobs/goblin6.c"), environment(this_object()));
break;
case 93..99:
move_object(clone_object("/players/maledicta/cont/mobs/goblin3.c"), environment(this_object()));
break;
case 90..92:
move_object(clone_object("/players/maledicta/cont/mobs/ogre_merc.c"), environment(this_object()));
break;
case 76..89:
move_object(clone_object("/players/maledicta/cont/mobs/goblin2.c"), environment(this_object()));
break;
case 1..75:
move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), environment(this_object()));
break;
}

}
