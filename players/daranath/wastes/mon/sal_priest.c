#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";
object MSG, ob, ob2, ob3, ob4;
int A, DAM;

reset(arg) {
   ::reset(arg);
   if (!arg) {

A = random(5);
if(A == 0){DAM = 20; MSG = (BLK+BOLD+"Inflict Minor Wounds"+NORM); }
if(A == 1){DAM = 25; MSG = (BLK+BOLD+"Inflict Moderate Wounds"+NORM); }
if(A == 2){DAM = 30; MSG = (BLK+BOLD+"Inflict Major Wounds"+NORM); }
if(A == 3){DAM = 30; MSG = (BLK+BOLD+"Salamander Blacklash"+NORM); }
if(A == 4){DAM = 40; MSG = (BLK+BOLD+"Inflict Critical Wounds"+NORM); }

 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/coal_amulet.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"obj/coal_ring.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT +"wep/heat_mace.c");
  move_object(ob4, this_object());

set_name("Salamander Priest");
set_alias("lavamon");
set_alt_name("priest");
set_race("salamander");
set_gender("creature");

set_short(RED+"salamander "+WHT+"priest"+NORM);
set_long("The red scales of the salamander priest shimmer with magical energy\n"+
         "as he stands before you. The salamander's black orbs glimmer with\n"+
         "anticipation of a skirmish.\n");

set_level(18);
set_ac(15);
set_wc(24 + random(4));
set_hp(370 + random(60));
set_al(-1000);
set_aggressive(0);

set_chance(20);
set_spell_dam(DAM);
set_spell_mess1("Salamander Priest prays for a spell during the fight.\n");
set_spell_mess2("\nSalamander Priest prays for and casts a spell:\n\n"+
     "                 "+MSG+"        \n"+
     "\nThe salamander smirks as you feel the effects of the damaging spell.\n");

init_command("wield mace");
init_command("wear ring");
init_command("wear amulet");

   }
}
