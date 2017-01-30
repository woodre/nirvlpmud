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
set_short(HIW+"A "+HIR+"Crazed"+NORM+HIW+" Goblin Warrior"+NORM);
set_long(
"  This is a wild goblin warrior. He is covered in red\n"+
"paint and has only a ragged loin cloth to cover his\n"+
"form. His yellow eyes are wide in madness and stare at\n"+
"you with a crazed passion to slay. He carries only a\n"+
"rusty longsword.\n");
set_level(16);
set_al(-1000);
set_wc(35);
set_ac(1);
set_dead_ob(this_object());
set_chance(5);
set_spell_dam(20);
set_spell_mess1(
  "The goblin berserker tears into his opponent with a mad rage!\n");
set_spell_mess2(
  "You are struck repeatedly by a crazed goblin warrior!\n");

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
