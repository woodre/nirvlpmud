id(str) { return str=="scavenger list dispenser" || str=="dispenser" || str == "list dispenser"; }

short() { return "A Scavenger List Dispenser"; }

long() {
  write("Type \"scavenge\" to begin your hunt.\n");
}

init() {
  add_action("cmd_scavenge","scavenge");
}

cmd_scavenge(){
  if(present("scavenger list", this_player())) {
    write("You already have a list!\n");
    return 1;
  }
  else {
    object ob;
    ob = clone_object("/players/vertebraker/obj/scavenger");
    ob->load_data();
    move_object(ob, this_player());
   write("You take your list.\n");
  write("Happy hunting!\n");
    return 1;
  }
}
