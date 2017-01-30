/* gc_hall.c: GC's private hall */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  object ob;
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild GC hall";
  long_desc  = "This room is ONLY for Guild Commanders and Wizards.\n"
              +"Compared to the rest of the building, this area is very well furnished.\n"
              +"It is not, however, the Taj Mahal (sp). Lying in the middle of the room\n"
              +"is a table, apparently with some notes on it.\n";
  dest_dir = 
  ({
  ROOM_DIR+"g_hall.c", "back"
  });
  ob = clone_object(ROOM_DIR+"gcboard.c");
  move_object(ob, this_object());
}
init() {
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file(ROOM_DIR+"ILLEGAL_ENTRY", "<"+ctime(time())+"> "+this_player()->query_real_name()+" gc room\n");    
    move_object(this_player(), "room/plane12");
  }
  ::init();
}
