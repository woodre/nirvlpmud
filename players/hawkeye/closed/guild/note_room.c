inherit "room/room";
static int rank, level, next_exp, min_exp, next_money;
   string ME;
 reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Writing a Note (leave me alone)";
long_desc="You are in the corner writing a note, to go back to where the\n"+
 "action is, go: up";

dest_dir=({
 "players/hawkeye/closed/guild/guild_room", "up",
});

   }
}
