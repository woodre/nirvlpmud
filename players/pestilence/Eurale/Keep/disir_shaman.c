/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
object cape,gold;
  ::reset(arg);
  if(arg) return;

set_name(HIR+"Disir Shaman"+NORM);
set_alias("shaman");
set_alt_name("disir");
set_race("creature");
set_short(HIR+"Disir Shaman"+NORM);
set_long(
	"This is the feared Disir Shaman.  His powers of the occult are\n"+
	"well known among his race.  He has an aura of misery and death\n"+
	"surrounding him.  His boney, long talons look scorched and\n"+
	"there is a sickening odor in the air.\n");

set_level(23);
set_hp(900);
set_hp_bonus(240);
set_al(-400);
set_wc(48);
set_wc_bonus(17);
move_object(clone_object("players/eurale/Keep/OBJ/velvet_cape"),TO); 
init_command("wear cape");
move_object(clone_object("players/eurale/Keep/OBJ/dragon_ring"),TO);  
init_command("wear ring");
set_ac(22);
set_heal(random(15),3);
set_aggressive(random(2));
add_money(3500);

set_chat_chance(8);
  load_chat("The Shaman mumbles an incantation.....\n");
  load_chat("The Fire licks out at the Shaman's feet.....\n");
  load_chat("The Shaman points at you......\n");
  load_chat("The Shaman shouts: WHO LET YOU ENTER?\n");
set_a_chat_chance(9);
  load_a_chat("\nThe Shaman pulls the cape over his face and disappears\n"+
              "into the darkness....\n\n");
  load_a_chat("\nThe Shaman screams: GUARDS, GUARDS!\n");
  load_a_chat("\nThe Shaman SLAMS you to the ground....\n");
  load_a_chat("\nThe Shaman gouges you with a vicious kick..\n");

/*
set_chance(15);
set_spell_dam(55);

set_spell_mess1(
  "\nThe Shaman "+HIR+"SUMMONS"+NORM+" the river of fire to attack...\n\n");
set_spell_mess2(
  "\nThe Disir Shaman steps back.......\n"+
  "      points at the river and then at you.....\n"+
  "            and the flames jump out and "+HIR+"S I N G E"+NORM+" you..\n\n");
*/

add_spell("river",
  "\nThe Disir Shaman steps back.......\n"+
  "      points at the river and then at you.....\n"+
  "            and the flames jump out and "+HIR+"S I N G E"+NORM+" you..\n\n",
  "\nThe Shaman "+HIR+"SUMMONS"+NORM+" the river of fire to attack...\n\n",
10,40,"other|fire",0);

/*
gold = clone_object("obj/money");
gold->set_money(1250);
move_object(gold,this_object());
*/

add_spell("heal",
    "#MN# utters some words in a chant.\n",
    "#MN# utters some words in a chant.\n",
    10,"30-50",0,0, "Shaman_heal" );

add_spell("burn",
    "$HR$    F$N$\n$HR$      L$N$\n        $HR$A$N$\n         $HR$ M$N$\n            $HR$E$N$\n\n      burns you with intense pain!\n",
    "$HR$    F$N$\n$HR$      L$N$\n        $HR$A$N$\n         $HR$ M$N$\n            $HR$E$N$\n\n      burns #TN# with intense pain!\n",
    20,50-80,"other|fire",0);

}

Shaman_heal( object target, object room, int damage ) {
int amt;
amt = 100 + random(40);
if(this_object()->query_hp() < 150) {
tell_room(environment(),
  "The shaman cackles and his wounds seem to heal before your very eyes...\n"+
  NORM);
  heal_self(amt);
return 1; }
}

id(str) { return (::id(str) || str == "disir shaman"); }
/*
heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  if(this_object()->query_hp() < 150) Shaman_heal();
}

Shaman_heal() {
int amt;
amt = 10 + random(5);
tell_room(environment(),
  "The shaman cackles and his wounds seem to heal before your very eyes...\n"+
  NORM);
  heal_self(amt);
}
*/
