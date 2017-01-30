inherit "room/room";
object monster;
init() {
  add_action("search","search");
  ::init();
}

reset(arg) {
    if (arg) return;
    monster();
    set_light(1);
    short_desc = "Black Walled Room";
    no_castle_flag = 0;
    long_desc = 
"You have entered a very dark room.  The walls have been darkened by many\n"+
"ages worth of conflict and battle.  Above you you can see an opening to the\n"+
"and below you you get a feeling of extreme evil.\n"+
"";
dest_dir = ({
             "players/grimm/rooms/haphaz_k12", "up",
           });
}

monster() {
  if (!present("junior")) {
    monster = clone_object("players/grimm/monster/junior");
    move_object(monster, this_object());
   }
  return 1;
}

search() {
  if (present("junior")) {
write("You search around and find a passage leading down,\nbut Junior bars your way.\n");
  } else {
write("You search around, find a passage leading down, and decide to take it.\n");
    move_object(this_player(), "players/grimm/rooms/haphaz_k12d2");
    }
  return 1;
}
