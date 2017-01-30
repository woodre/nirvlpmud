inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("marker");
  set_short("A Marker");
  set_long("A \"kill\" marker. Type \"guard <monster>\" to activate.\n");
  set_weight(1);
  set_value(500);
}

init() {
  add_action("guard","guard");
}

guard(str) {
  object ob;
  if(!str) {
    write("What do you want to guard?\n");
    return 1;
  }
  if(!present(str,environment(this_player()))) {
    write("That is not here.\n");
    return 1;
  }
  if(present("bruno",environment(this_player()))) {
    write("There is already a guard here.\n");
    return 1;
  }
  ob = clone_object("/players/grimm/monster/protect");
  ob->set_item(str);
  ob->set_owner(this_player()->query_real_name());
  move_object(ob,environment(this_player()));
  write("Done.\n");
  return 1;
}
