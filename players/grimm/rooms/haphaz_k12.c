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
    short_desc = "A Guarded Room";
    no_castle_flag = 0;
    long_desc = 
"This room is a post for a local guard.  He looks rather burly and is not\n"+
"to let anybody pass him.  To the south is an opening and below you you\n"+
"you have a strange sensation that you really do not want to go down there.\n"+
"";
dest_dir = ({
             "players/grimm/rooms/haphaz_k13", "south",
           });
}

monster() {
  if (!present("guard")) {
    monster = clone_object("players/grimm/monster/guard2");
    move_object(monster, this_object());
    }
  return 1;
}

search() {
  if (present("guard")) {
write("You search around and find a passage below you,\nbut the guard bars your way.\n");
    } else {
    write("You find a passage leading down and decide to take it.\n");
    move_object(this_player(), "players/grimm/rooms/haphaz_k12d1");
    }
  return 1;
}
