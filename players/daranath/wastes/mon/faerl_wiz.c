#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";
object MSG, ob, ob2, ob3;
int A, DAM;

reset(arg) {
   ::reset(arg);
   if (!arg) {

A = random(5);
if(A == 0){DAM = 20; MSG = (HIG+"Acid Breath"+NORM); }
if(A == 1){DAM = 25; MSG = (HIM+"Mystic Lash"+NORM); }
if(A == 2){DAM = 30; MSG = (BLK+BOLD+"Shadow Arrow"+NORM); }
if(A == 3){DAM = 30; MSG = (HIY+"Lightning Rage"+NORM); }
if(A == 4){DAM = 40; MSG = (HIM+"Mystic Strike"+NORM); }

 ob = clone_object("obj/money");
  ob->set_money(random(4000) + 1000);
/* average coins of 3300, 200 below monster guide */
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/leathers.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/bladestaff.c");
  move_object(ob3, this_object());

set_name("Faerl Wizard");
set_alias("platmon");
set_alt_name("wizard");
set_race("faerl");
set_gender("male");

set_short(WHT+"faerl "+HIM+"wizard"+NORM);
set_long("The Faerl Wizard stands with a grace the others do not have. His wings\n"+
         "are pulled back, acting as a shadow for his body. His light, \n"+
         "leather armor is in perfect shape, as if he doesn't need to\n"+
         "resort to hand-to-hand combat to take care of business.\n");

set_level(18);
set_ac(15);
set_wc(24 + random(4));
set_hp(370 + random(60));
set_al(-1000);
set_aggressive(0);

set_chance(20);
set_spell_dam(DAM);
set_spell_mess1("Faerl Wizard casts a spell during the fight.\n");
set_spell_mess2("\nFaerl Wizard prepares and casts a spell:\n\n"+
     "                 "+MSG+"        \n"+
     "\nFaerl Wizard smirks as you feel the effects of the damaging spell.\n");

init_command("wield staff");
init_command("wear leather");

   }
}
