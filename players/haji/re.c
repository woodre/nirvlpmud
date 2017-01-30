reset(arg) {
   object ob1;

    if (arg)
	return;
    move_object(this_object(), DEST);
   if (!present("grail", find_object("room/quest_room"))) {
      ob1 = clone_object("obj/quest_obj");
      call_other(ob1, "set_name", "grail");
      call_other(ob1, "set_hint", "Search out and find the holy grail.\n");
      move_object(ob1, find_object("room/quest_room"));
   }
}
