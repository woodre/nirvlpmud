/* complain.c: room for player whining board */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  object table;
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild complaint room";
  long_desc  = "This is the basement of the Logger's Guild hall. Running around here\n"
              +"are rats and many other lovely creatures. In the corner of the room,\n"
              +"you see the rotting corpse of an adventurer who had too big a mouth.\n"
              +"This room is evidentally for complaining. Guild ideas belong in the\n"
              +"Guild hall, while this room is reserved for bitching about management.\n";
  dest_dir =
  ({
  ROOM_DIR+"g_hall.c", "up"
  });
  table = clone_object(ROOM_DIR+"whinebb.c");
  move_object(table, this_object());
}
init() {
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file(ROOM_DIR+"ILLEGAL_ENTRY", "<"+ctime(time())+"> "+this_player()->query_real_name()+" gc hall\n");
    move_object(this_player(), "room/plane12");
  }
  ::init();
}
