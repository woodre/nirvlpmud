int cmd_form(string str) {
  if(!str || str!="party") {
    notify_fail("Form what?\n");
    return 0;
  }
  if(present("party_object",this_player())) {
    notify_fail("You already have a party object.\n");
    return 0;
  }
  move_object(clone_object("/obj/partyob"),this_player());
  return 1;
}
