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
set_short("Goblin Devastater");
set_long(
"  This is a heavily armored goblin warrior which carries\n"+
"a huge axe and a large iron shield. He has a heavy helm\n"+
"adorning his head with a large horse hair tassle hanging\n"+
"from the back. Large spikes jut from all over his armor.\n"+
"You feel almost intimidated by this oversized creature.\n");
set_level(14);
set_hp(230);
set_al(-800);
set_wc(18);
set_ac(14);
set_dead_ob(this_object());
set_chance(5);
set_spell_dam(15);
set_spell_mess1(
  "The Devastater runs at his opponent, striking with wild abandon!\n");
set_spell_mess2(
  "The Devastator strikes you with his large axe!\n");
gold = clone_object("obj/money");
gold->set_money(750 + random(160));
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
