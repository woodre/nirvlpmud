inherit "room/room";
object obj;
 reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Grand Master's Room";
long_desc="This is the Monk's GrandMaster's Room.\n"+
  "This small room is where Monk GrandMaster's hold important\n"+
  "meetings, or just like to hang out.\n";


dest_dir=({
    "players/hawkeye/closed/guild/guild_room.c", "up",
   "/room/church", "church",
  "players/boltar/hotel/hotel", "hotel",
});

if(!(present("board", this_object()))) {
obj = clone_object("players/hawkeye/closed/monk/gc_board");
move_object(obj, this_object());
            }
                 }
   }

