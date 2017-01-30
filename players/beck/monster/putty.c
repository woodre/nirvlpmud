inherit "obj/monster";

reset(arg)
{
object gold, weapon;
gold=clone_object("obj/money");
gold->set_money(random(100) + 100);
move_object(gold, this_object());
  ::reset(arg);
  if(arg) return;
set_name("putty");
set_alias("patroller");
set_short("A Putty Patroller");
set_long("The Putty Patroller is the backbone of Lord Zed's forces.\n"+
"It is made of clay, and has a large Z on the center of it's chest.\n");
set_level(5);
set_hp(75);
set_wc(7 + random(2));
set_ac(3 + random(2));
set_al(-100);
set_aggressive(1);
}
