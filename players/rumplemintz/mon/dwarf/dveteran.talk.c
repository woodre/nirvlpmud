inherit "obj/monster";

reset(arg){
  object money;
  ::reset(arg);
  if(arg) return;
  set_name("Dwarven Veteran");
  set_race("dwarf");
  set_alias("veteran");
  set_short("A Dwarven Veteran");
  set_long("An intelligent veteran of the Dwarven Clan.\n");
  set_level(10);
  set_hp(150);
  set_ac(8);
  set_wc(14);
  set_al(-500);
  money=clone_object("obj/money");
  money->set_money(450);
  move_object(money,this_object());
  call_out("dwarf_talk",10);
}
dwarf_talk() {
  say("Veteran says: Ot dock harplink dim wesuul!\n");
  call_out("dwarf_fight2",2);
  return 1;
}
dwarf_fight2() {
  say("Veteran says: Gousard atu ow idsn trewsur!\n");
  call_out("dwarf_fight3",2);
  return 1;
}
dwarf_fight3() {
  say("Veteran says: Welcome to the first level of the Dwarf castle.\n");
  call_out("dwarf_fight4",2);
  return 1;
}
dwarf_fight4() {
  say("Veteran says: You must pass all of us to get to the Lord.\n");
  call_out("dwarf_talk",20);
  return 1;
}
