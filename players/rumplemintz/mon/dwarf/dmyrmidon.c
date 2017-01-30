inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("myrmidon");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Myrmidon");
   set_long("A strong myrmidon from the Dwarven lands.\n");
  set_level(15);
  set_hp(225);
  set_al(-500);
  set_wc(20);
  set_ac(12);
    gold=clone_object("obj/money");
   gold->set_money(875);
   move_object(gold,this_object());
}
