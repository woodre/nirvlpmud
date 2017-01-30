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

set_name("Gloom Drifter");
set_alias("gloom");
set_alt_name("drifter");
set_race("spirit");
set_short("A spirit hunts about the area");
set_long("A rare form of undead that takes over the body of a living creature\n"+
         "this particular Gloom has mergered with the spirit of a Drifter.\n"+
         "Together they stalk the night, two enities completly seperate\n"+
         "in thought, in hunger, yet one in body.\n");

set_level(19);

set_hp(400+random(100));
set_al(-(250+random(350)));
set_wc(25+random(7));
set_ac(15+random(3));
set_heal(4,8);
set_aggressive(1);

set_chance(25);
set_spell_dam(25+random(45));
set_spell_mess1("The form of a glowing spirit materializes and slashes at its foe.\n");
set_spell_mess2("The Gloom materializes before you and screams loudly, attempting to take your soul.\n");

}

