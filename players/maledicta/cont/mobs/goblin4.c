#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object gold;
reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("goblin");
set_alt_name("cont_goblin");
set_race("goblin");
set_short("A Goblin Cavalier");
set_long(
"  This is a semi-intelligent goblin which is covered in\n"+
"rusty but decent armor. He has a large sword in his right\n"+
"hand, with a shield in the left. He almost seems competent\n"+
"compared to the other goblins.\n");
set_level(12);
set_hp(160);
set_al(-500);
set_wc(17);
set_ac(10);
set_dead_ob(this_object());
set_chance(5);
set_spell_dam(15);
set_spell_mess1(
  "The goblin cavalier strikes at his opponent with deadly precision!\n");
set_spell_mess2(
  "The goblin cavalier strikes you with a solid blow!\n");
gold = clone_object("obj/money");
gold->set_money(550 + random(60));
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
move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), environment(this_object()));
break;
case 7..11:
move_object(clone_object("/players/maledicta/cont/mobs/goblin2.c"), environment(this_object()));
break;
case 6:
move_object(clone_object("/players/maledicta/cont/mobs/goblin3.c"), environment(this_object()));
break;
case 4..5:
move_object(clone_object("/players/maledicta/cont/mobs/goblin4.c"), environment(this_object()));
break;
case 3:
move_object(clone_object("/players/maledicta/cont/mobs/goblin5.c"), environment(this_object()));
break;
case 2:
move_object(clone_object("/players/maledicta/cont/mobs/goblin6.c"), environment(this_object()));
break;
case 0..1:
move_object(clone_object("/players/maledicta/cont/mobs/goblin7.c"), environment(this_object()));
break;
default:
move_object(clone_object("/players/maledicta/cont/mobs/goblin1.c"), environment(this_object()));
break;
}

}
