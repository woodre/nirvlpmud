#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2;
int a;  a = random(2);
 ob = clone_object("obj/money");
  ob->set_money(random(100) + 15);
  move_object(ob, this_object());
if(a == 0){ ob2 = clone_object(ROOT+"wep/flameblade.c"); }
if(a == 1){ ob2 = clone_object(ROOT+"wep/flamedag.c"); }
  move_object(ob2, this_object());

set_name("Fire Mephit");
set_alias("fire");
set_alt_name("lavamon");
set_race("mephit");
set_gender("creature");

set_short(HIR+"Fire Mephit"+NORM);
set_long("A creature born from the edge of the elemental planes of both air and\n"+
         "fire, the Fire Mephit feels right at home here close to the lava\n"+
         "pits in Gundar. The mephit itself looks vaguely humanoid, with a large\n"+
         "set of wings that protrude from its tiny form. Standing barely over\n"+
         "4 feet tall, the Mephit cannot be that much of a challenge...\n");

set_level(15);
set_ac(9);
set_wc(22 + random(5));
/* Mephit is mostly fire and brimstone, reflecting poor AC, yet damaging WC */
set_hp(220 + random(50));
set_al(-1000);
set_aggressive(0);

init_command("wield blade");
init_command("wield dagger");

set_chance(15);
set_spell_dam(25);
set_spell_mess2("\n"+HIR+"Fire Mephit "+NORM+"rears up before you and breathes a\n"+
     "\n            "+HIR+"Gout of Flame"+NORM+"\n"+
     "\ninto your face, buring your eyes and searing your lungs...\n\n");
set_spell_mess1(HIR+"Fire Mephit"+NORM+" breathes a cone of flame, burning the area.\n");

set_a_chat_chance(10);
load_a_chat(HIR+"Fire Mephit "+NORM+"slashes at you with its tiny blade.\n");
load_a_chat(HIR+"Fire Mephit "+NORM+"stabs you with its tiny blade.\n");

   }
}
