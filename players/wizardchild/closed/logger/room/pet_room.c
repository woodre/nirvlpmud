/* pet_room.c: where pets go */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild pet room";
  long_desc  = "As you enter this room, you feel at one with nature. From the look of it, this\n"
              +"is where the animals of Nirvana come to assist Logger's in their tasks. If you\n"
              +"have a pet in this room, he will follow you only if you tell him so.\n";
  dest_dir =
  ({ 
  "/players/wizardchild/closed/logger/room/g_hall.c", "south"
  });
}
init() {
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file("players/wizardchild/closed/logger/room/ILLEGAL_ENTRY", "<"+ctime(time())+"> "+this_player()->query_real_name()+" pet_room\n");
    move_object(this_player(), "room/plane12");
  }
  ::init();
}
