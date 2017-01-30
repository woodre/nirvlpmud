inherit "/room/room";

reset(arg) {
  if(arg) return;
  if(!present("name_of_monster", this_object()))
    move_object(clone_object("/open/verte/morgoth/monster"), this_object());
  dest_dir = ({ "/players/morgoth/workroom", "north",
           "/players/vertebraker/workroom", "south" });
}

move(str) {
  if(query_verb() == "north")
  if(present("name_of_monster", this_object()))
  {
    write("The golem blocks your path.\n");
    return 1;
  }
  ::move(str);
  return 1;
}
