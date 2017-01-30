inherit "/room/room";

reset(arg) {
  if(arg) return;
  if(!present("name_of_monster", this_object()))
    move_object(clone_object("/open/verte/morgoth/monster"), this_object());
  dest_dir = ({ "/players/morgoth/workroom", "north" });
}

move(str) {
  if(present("name_of_monster", this_object()))
    write("The golem blocks your path.\n");
  else ::move(str);
  return 1;
}
