#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";
object MSG, ob, ob2, ob3;
int A, DAM;

reset(arg) {
   ::reset(arg);
   if (!arg) {

A = random(5);
if(A == 0){DAM = 15; MSG = (HIW+"Magic Missile"+NORM); }
if(A == 1){DAM = 20; MSG = (HIY+"Shocking Strike"+NORM); }
if(A == 2){DAM = 25; MSG = (HIB+"Lightning Blast"+NORM); }
if(A == 3){DAM = 25; MSG = (HIR+"Fire Ball"+NORM); }
if(A == 4){DAM = 30; MSG = (HIW+"Eye of "+HIR+"Cormax"+NORM); }

 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/gob_robes.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/shamanstaff.c");
  move_object(ob3, this_object());

set_name("goblin shaman");
set_alias("cavemon");
set_alt_name("shaman");
set_race("goblin");
set_gender("male");

set_short(GRN+"goblin "+HIR+"shaman"+NORM);
set_long("The Shaman of the goblin tribes, this one has a number of beads running\n"+
         "along the length of his robes, each one representing a battle he\n"+
         "has fought in, and survived. Each goblin Shaman seems to know a\n"+
         "single spell, probably all thier limited intellect can handle.\n");

set_level(13);
set_ac(10);
set_wc(15 + random(4));
set_hp(170 + random(60));
set_al(-800);
set_aggressive(0);

set_chance(10);
set_spell_dam(DAM);
set_spell_mess1("Goblin Shaman casts a spell during the fight.\n");
set_spell_mess2("\nGoblin Shaman prepares and casts a spell:\n\n"+
     "                 "+MSG+"        \n"+
     "\nGoblin Shaman smirks as you feel the effects of the damaging spell.\n");

init_command("wield staff");
init_command("wear robes");

   }
}
