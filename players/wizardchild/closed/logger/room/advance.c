/* advance.c: guild advancement room */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  object master,bank;
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild advancement room";
  long_desc  = "This small room is where a Lumberjack comes to prove his or her ability.\n"
              +"In here, there lies the Master Logger. Only he can tell whether you are\n"
              +"ready for advancement.\n";
  dest_dir =
  ({
  ROOM_DIR+"g_hall.c", "east"
  });
  master = clone_object(ROOM_DIR+"masterlg.c");
  move_object(master, this_object());
  bank = clone_object("/players/wizardchild/closed/logger/gpbank");
  move_object(bank, this_object());
}
init() {
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file(ROOM_DIR+"ILLEGAL_ENTRY", "<"+ctime(time())+"> "+this_player()->query_real_name()+" advance\n");
    move_object(this_player(), "room/plane12");
  }
  ::init();
}
