inherit "obj/monster";

reset(arg){
  object gold,obj;
  ::reset(arg);
  if(arg) return;
  set_name("lord");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Lord Dwarven Lord");
  set_long("One of only two Lords of the Dwarven Lords.\n");
  set_level(21);
  set_hp(525);
  set_ac(32);
  set_wc(18);
  set_al(-500);
  gold=clone_object("obj/money");
  gold->set_money(8000);
  move_object(gold,this_object());
  obj=clone_object("/players/rumplemintz/obj/dquestobj");
  move_object(obj,this_object());
  call_out("dwarf_talk",10);
}
dwarf_talk() {
  say("Lord says: You shall pay for your insolence!\n");
  call_out("dwarf_fight2",2);
  return 1;
}
dwarf_fight2() {
  say("Lord says: No one shall take my treasure!\n");
  call_out("dwarf_fight3",2);
  return 1;
}
dwarf_fight3() {
  say("Lord says: You've killed all my men!\n");
  call_out("dwarf_fight4",2);
  return 1;
}
dwarf_fight4() {
  say("Lord says: You shall die now.\n");
  call_out("dwarf_talk",20);
  return 1;
}
