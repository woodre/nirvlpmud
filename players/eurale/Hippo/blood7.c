inherit "room/room";
#define TO this_object()

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("thrombo")){
  move_object(clone_object("/players/eurale/Hippo/NPC/thrombo"),TO); }

short_desc = "A blood vessel";
long_desc =
  "  Swirling red liquid pumps its way past here enroute to the body's organs.\n";

dest_dir = ({
  "players/eurale/Hippo/thick_colon3","colon",
  "players/eurale/Hippo/blood6","up",
  "players/eurale/Hippo/blood8","down",
});

}
