inherit "obj/monster";

reset(arg)
{
object gold, weapon;
  ::reset(arg);
  if(arg) return;
set_name("skull");
set_alias("skull");
set_short("Skull");
set_long("Skull is Bulk's stupid sidekick.\n"+
"He has no clue what's going on.\n");
set_level(5);
set_hp(100);
set_wc(10);
set_ac(5);
set_aggressive(0);
set_chat_chance(3);
load_chat("Skull asks: Uhhh...What is a Power Ranger?\n");
gold=clone_object("obj/money");
gold->set_money(200);
move_object(gold, this_object());
}
