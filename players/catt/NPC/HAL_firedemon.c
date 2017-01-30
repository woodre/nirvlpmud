inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
object spell;
reset(arg) {
   object money;
::reset(arg);
if(arg) return;
set_name("fire demon");
set_alias("demon");
set_short("Fire Demon");
set_long("A fire demon conjured from the plain of fire. It is a deep red\n" +
         "and seems to burn with a hellish glow.\n");
set_level(7);
set_race("demon");
set_hp(105);
set_al(-100);
set_wc(11);
set_ac(6);
add_spell("Fire Spit",
   "#MN# spits fire at you.\n",
   "#MN# spits fire at #TN#.\n",
   30,5,"other|fire");
set_aggressive(1);
money = clone_object("obj/money");
money->set_money(random(100));
move_object(money, this_object());
if(random(100) > 95) {
   spell = clone_object(MAGICAL+"flamestrike");
if(spell) {
  move_object(spell, this_object());
          }
}
}
