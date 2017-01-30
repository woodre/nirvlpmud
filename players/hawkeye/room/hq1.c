inherit "room/room";
   string WHAT, ME;
realm(){return "NT";}
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="HQ";
long_desc = "You are in the office of HQ.\n";

dest_dir=({
    "/players/hawkeye/room/hqmac.c", "north",
  "/players/hawkeye/room/hqpipe.c", "west",
"players/hawkeye/room/hq.c", "doors",
"/players/hawkeye/room/hqwrong.c", "east",
});

   }
}

