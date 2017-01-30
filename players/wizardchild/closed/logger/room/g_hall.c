/* g_hall.c: place where players go (duh) */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  object board, paper;
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild main hall";
  long_desc  = "This is a long, high-ceilinged cabin made for only Lumberjacks. The walls are\n"
              +"supported by what appear to be old growth trees. The ground beneath you is\n"
              +"normal dirt, which has created a small dust cloud inside.\n"
              +"From here, it appears you could go to any part of the guild hall.\n";  
  dest_dir = 
  ({
  ROOM_DIR+"join.c", "meadow",
  ROOM_DIR+"tport.c", "east",
  ROOM_DIR+"advance.c", "west",
  ROOM_DIR+"pet_room.c", "north",
  ROOM_DIR+"shop.c", "up",
  ROOM_DIR+"complain.c", "down",
  ROOM_DIR+"cabinrm.c", "cabin",
  ROOM_DIR+"gc_hall.c", "gc"
  });
  board = clone_object(ROOM_DIR+"bboard.c");
  move_object(board, this_object());
  paper = clone_object("/players/wizardchild/closed/logger/gnews.c");
  move_object(paper, this_object());
}
init() { 
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write("You are not allowed in here!\n");
    move_object(this_player(), "room/church");
    write_file(ROOM_DIR+"ILLEGAL_ENTRY", 
      "<"+ctime(time())+"> "+this_player()->query_real_name()+"\n");
  } else {
    ::init();
    add_action("gc", "gc"); 
  }
}
gc() {
  if(present("logger pack", this_player())->query_grank() < 15) 
    write("You are not a Guild Commander.\n");
  else return 0;
  return 1;
}
