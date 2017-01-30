inherit "obj/monster";

reset(arg){
  object armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Dwarven Fighter");
  set_race("dwarf");
  set_alias("fighter");
  set_short("A Dwarven Fighter");
  set_long("A nimble fighter produced by the Dwarf Lords.\n");
  set_level(9);
  set_hp(135);
  set_ac(7);
  set_wc(13);
  set_al(-500);
  weapon=clone_object("/players/rumplemintz/weapon/baxe");
  move_object(weapon,this_object());
  armor=clone_object("/players/rumplemintz/armor/dcloak");
  move_object(armor,this_object());
  call_out("dwarf_talk",10);
}
dwarf_talk() {
  say("Fighter says: Ot dock harplink dim wesuul!\n");
  call_out("dwarf_fight2",2);
  return 1;
}
dwarf_fight2() {
  say("Fighter says: Gousard atu ow idsn trewsur!\n");
  call_out("dwarf_fight3",2);
  return 1;
}
dwarf_fight3() {
  say("Fighter says: Welcome to the Land of the Dwarven Lords.\n");
  call_out("dwarf_fight4",2);
  return 1;
}
dwarf_fight4() {
  say("Fighter says: The Lord Dwarven Lord is the ruler of this area.\n");
  call_out("dwarf_talk",20);
  return 1;
}
