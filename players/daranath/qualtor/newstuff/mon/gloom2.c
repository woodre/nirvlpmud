#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "players/mythos/amon/forest/monster1";
object ob;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

 ob = clone_object("obj/money.c");
  ob->set_money(2000+random(2000));
  move_object(ob, this_object());

set_name("Gloom");
set_alias("gloom");
set_alt_name("ghostmon");
set_race("spirit");
set_short(HIW+"A glowing spirit"+NORM);
set_long("A rare form of undead that takes over the body of a living creature\n"+
         "this particular Gloom has not yet found a host. The spirit wanders\n"+
         "around constantly, inflicting its own form of maddness on those\n"+
         "who would stop it from taking thier body.\n");

set_hp(350+random(100));
set_level(18);
set_al(-(250+random(350)));
set_wc(24+random(6));
set_ac(14+random(3));
set_heal(3,7);
set_aggressive(1);

set_chance(25);
set_spell_dam(20+random(40));
set_spell_mess1("The form of a glowing spirit materializes and slashes at its foe.\n");
set_spell_mess2("The Gloom materializes before you and screams loudly, attempting to take your soul.\n");

}

