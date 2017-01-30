#define WAR "/players/maledicta/cont/war/war"
#include "/players/maledicta/ansi.h"
inherit "players/vertebraker/closed/std/monster.c";

object gold;
int sps;
reset(arg)  {

  ::reset(arg);
  if(arg) return;
sps = 500;
set_name("goblin");
set_alt_name("cont_goblin");
set_race("goblin");
set_alias("shaman");
set_short(HIG+"Goblin "+NORM+GRN+"Shaman"+NORM);
set_long(
"  Dressed in long dirty robes and decorated with the bones\n"+
"of humans and small animals, this goblin has a dangerous\n"+
"look in his yellow bulbous eyes. He carries a long staff\n"+
"which is covered in scribbled markings and bright feathers.\n"+
"He is constantly chanting and humming.\n");
set_level(20);
set_wc(42);
set_ac(6);
set_al(-1000);
message_hit=({
""+HIR+"Envelopes"+NORM+""," in a deadly fire cloud of magic",
""+HIG+"Blasts"+NORM+""," with an unholy bolt of energy",
""+HIY+"hit"+NORM+""," with a charged staff strike",
"hit"," with a staff slam",
"hit","",
"grazed"," with an arching staff swing",
"bruised"," with the butt of his staff"
});
gold = clone_object("obj/money");
gold->set_money(4000 + random(2000));
move_object(gold,this_object());
set_dead_ob(this_object());
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
 if(sps < 495) sps += 5;
 if(!attacker_ob) environment()->doitanyway();
 
 if(sps >= 50 && hit_point < 250 && random(100) < 30){
    hit_point += 40;
    sps -= 50;
    tell_room(environment(),
    HIW+"The "+HIG+"Goblin Shaman"+NORM+HIW+" raises his hands to the sky and chants!"+NORM+"\n"+
    HIG+"His wounds begin to seal!"+NORM+"\n");
    }
 else if(attacker_ob && sps >= 100 && random(100) < 20){
    sps -= 100;
    tell_room(environment(),
    HIW+"The "+HIG+"Goblin Shaman"+NORM+HIW+" raises his staff and slams it into the ground...\n"+
    "The earth begins to quake and split!"+NORM+"\n");
    attacker_ob->hit_player(random(30) + 30);
    tell_room(environment(),
    HIR+attacker_ob->query_name()+" is thrown brutally to the ground!"+NORM+"\n");
    }
 }
