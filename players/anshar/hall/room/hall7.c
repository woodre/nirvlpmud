
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="    The long hallway takes a turn here at what appears to be\n"+
            "some sort of guard post. The torches are more proliferous\n"+
            "here, and there is a lantern on a table filling the room with\n"+
            "a healthy glow. there is an archway to the east, through which\n"+
            "a warm light flows.\n";
  items=({
    "columns",  "Striated marble columns",
    "arch",     "Pristine marble highly decorated",
    "archway",  "Marble columns uphold an ornate arch",
    "table",    "Of rather modest, but sturdy construction",
    "lantern",  "Bolted to the table, it seems to be well used",
    "post",     "Evidently the function of this bend in the hall",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  dest_dir=({
    "/players/anshar/hall/room/hall5", "south",
    "/players/anshar/hall/room/hall9", "east",
  });
if(!present("defender"))
{
move_object(clone_object("/players/anshar/hall/mon/defender"),this_object());
move_object(clone_object("/players/anshar/hall/mon/defender"),this_object());
move_object(clone_object("/players/anshar/hall/mon/defender"),this_object());
}
}
init() {
   ::init();
   add_action("east","east");

   }

  east() {
  if(present("defender")) {
  present("defender",this_object())->attack_object(this_player()); 
  if(present("defender 2")) {
  present("defender 2",this_object())->attack_object(this_player()); 
  if(present("defender 3")) {
  present("defender 3",this_object())->attack_object(this_player()); 
   }
  }
 return 1;
 }
 this_player()->move_player("east#/players/anshar/hall/room/hall9");
 return 1; 
}
