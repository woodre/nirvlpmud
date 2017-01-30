#define WAR "/players/maledicta/cont/war/war"
#include "/players/maledicta/ansi.h"
inherit "players/vertebraker/closed/std/monster.c";

object gold;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("ogre");
set_alt_name("cont_goblin");
set_race("ogre");
set_alias("mercenary");
set_short(YEL+"Ogre "+NORM+BOLD+"Mercenary"+NORM);
set_long(
"  This is a massive ogre mercenary.  He was hired by the goblin\n"+
"army to fill in the ranks and terrorize their enemies. He is\n"+
"dressed in stench-ridden furs and carries a huge club. His\n"+
"mouth is turned up in an evil smile, his yellow and broken\n"+
"teeth jutting out in awkward angles.\n");
set_level(20);
set_al(-1000);
set_chance(25);
set_spell_dam(40);
set_spell_mess1(
  "The Ogre Mercenary lunges forward and "+HIW+"- "+HIR+"SLAMS"+HIW+" -"+NORM+" his opponent!\n");
set_spell_mess2(
  HIW+"You fall back stunned as the Ogre Mercenary "+HIR+"SLAMS"+HIW+" you with his Club!"+NORM+"\n");
set_dead_ob(this_object());
gold = clone_object("obj/money");
gold->set_money(3000 + random(4000));
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
if(WAR->query_mobs_left(environment()->query_room_num()) > 0){
WAR->sub_mob(environment()->query_room_num());
tell_room(environment(),
HIG+"Goblin reinforcements arrive."+NORM+"\n");
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
