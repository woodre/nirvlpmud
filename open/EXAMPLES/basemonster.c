inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("phoenix");
  set_race("");
  set_alias("");
set_short("A Fiery Phoenix");
set_long(A huge Phoenix, engulfed in mystical flame.\n");
set_level(50);
set_hp(0)
set_al(0);
set_wc(1);
set_ac(1);
  set_chat_chance(2);
  load_chat("\n");
  load_chat("\n");
  gold=clone_object("obj/money");
  gold->set_money(random(###)+###);
  move_object(gold,this_object());
  weapon=clone_object("");
  move_object(weapon,this_object());
  armor=clone_object("");
  move_object(armor,this_object());
}
