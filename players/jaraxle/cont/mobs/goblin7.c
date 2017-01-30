#define WAR "/players/jaraxle/cont/daemon"

#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";

object gold;

reset(arg)  {



  ::reset(arg);

  if(arg) return;



set_name("goblin");

set_alt_name("cont_goblin");

set_race("goblin");

set_alias("priest");

set_short("Goblin Sergeant");

set_long(

"  This is an officer in the goblin army. He is\n"+

"decently armored and carries a longsword in his\n"+

"green hand. He is larger than most goblins.\n");

set_level(9);

set_hp(135);

set_al(-1000);

set_wc(15);

set_ac(4);

set_chance(5);

set_spell_dam(15);

set_spell_mess1(

  "Goblin sergeant slashes at his opponent!\n");

set_spell_mess2(

  "You feel a stabbing pain as the Sergeant slices into you!\n");

set_dead_ob(this_object());

gold = clone_object("obj/money");

gold->set_money(350);

move_object(gold,this_object());

}



monster_died() {

if(WAR->query_mobs_left()){

WAR->sub_mob();

tell_room(environment(),

"Goblin reinforcements arrive.\n");

get_goblin();

}

return 0; }





get_goblin(){



switch(random(21)){

case 12..1000:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin1.c"), environment(this_object()));

break;

case 7..11:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin2.c"), environment(this_object()));

break;

case 6:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin3.c"), environment(this_object()));

break;

case 4..5:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin4.c"), environment(this_object()));

break;

case 3:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin5.c"), environment(this_object()));

break;

case 2:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin6.c"), environment(this_object()));

break;

case 0..1:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin7.c"), environment(this_object()));

break;

default:

move_object(clone_object("/players/jaraxle/cont/mobs/goblin1.c"), environment(this_object()));

break;

}



}