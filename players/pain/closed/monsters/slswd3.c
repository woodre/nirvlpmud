inherit "obj/monster";

reset(arg)
{
   object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("sellsword");
   set_race("human");
  set_alias("sellsword");
  set_short("A grizzled old Sellsword");
   set_long("This veteren of many wars is truly one to be reckoned with... use caution\n"+
   "He seems to be jeering you into a fight....\n"+
   "What do you think your chances are?\n");
  set_level(15);
  set_hp(300);
  set_al(0);
  set_wc(20);
  set_ac(10);
   weapon=clone_object("/players/pain/closed/weapons/slswdweap");
  move_object(weapon,this_object());
}
