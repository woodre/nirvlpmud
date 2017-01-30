inherit "obj/monster";

reset(arg)
{
object gold, weapon;
  ::reset(arg);
  if(arg) return;
set_name("bulk");
set_alias("bulk");
set_short("Bulk");
set_long("Bulk is looking for the Power Rangers\n");
set_level(7);
set_hp(150);
set_wc(11);
set_ac(6);
set_al(1);
set_aggressive(0);
set_chat_chance(10);
load_chat("Bulk says: I gotta know who the Power Rangers are.\n");
load_chat("Bulk says: I'm gonna be famous when I show the world who\n"+
"the Power Rangers really are!\n");
gold=clone_object("obj/money");
gold->set_money(300);
move_object(gold, this_object());
}
