inherit "room/room";

reset(arg) {
   if(arg) return;
   short_desc="Clearing";
   long_desc="Tall trees surround an open, flat, rocky clearing.\n";
   dest_dir=({"/players/llew/workroom","home"});
   set_light(1);
   move_object(clone_object("/players/llew/Other/monsters/blob"),this_object());
}

init()
{
   ::init();
   add_action("arena", "arena");
   add_action("suitup", "suitup");
}

arena()
{
   this_player()->move_player("to the arena#players/llew/Other/rooms/test_arena5");
   return 1;
}

suitup(string str)
{
   return "/players/llew/Other/rooms/suitup"->suitup(str);
}
