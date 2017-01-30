inherit "room/room";
object obj;
object list;
string guild;
   string name;
 reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Monks Cove";
  long_desc="You are in the inner Monk's Cove.  Only members\n"+
   "of this sacred guild may enter here.  In this room you\n"+
   "may relax and enjoy the company of fellow guild members\n"+
   "the bothersome company of those members of lesser guilds.\n";

dest_dir=({
   "players/hawkeye/closed/guild/join.c", "east",
    "players/hawkeye/closed/guild/advance.c", "west",
    "players/hawkeye/closed/guild/commanders.c", "down",
   "/room/church", "church",
  "players/boltar/hotel/hotel", "hotel",
     "players/catwoman/tl.c", "lockers",
    "/room/adv_guild","advguild",
     "/room/post", "post",
});

  if(!present("guild board", this_object())) {
   obj = clone_object("players/hawkeye/closed/monk/guild_board");
   move_object(obj, this_object());
                 }
   }
}

init() {
   ::init();
  add_action("down", "down");
    name = this_player()->query_real_name();
   guild= this_player()->query_guild_name();
if(this_player()->is_pet() < 1) {
if(this_player()->query_guild_name() != "monk" && this_player()->query_level () < 21) {
move_object(this_player(),"/players/hawkeye/closed/guild/join");
write("You are not a member of the Monks Guild!\n");
this_player()->set_title("is a Monk Wanna Be!");
return 1;
}
}
     }
down() {
  if(this_player()->query_guild_rank() < 19) {
       write("You are NOT a guild commander.\n");
return 1;
}
if(this_player()->query_guild_rank() > 19) {
move_object(this_player(), "players/hawkeye/closed/guild/commanders.c");
write("You enter the guild commander room.\n");
command("look",this_player());
return 1;
}

}
