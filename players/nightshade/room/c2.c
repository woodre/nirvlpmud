inherit "players/nightshade/new_room";
init() {
   ::init();
   add_action("enter", "enter");
   }
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"The cave is damp and slightly dark, but there is ample light for you to\n"+
"to notice that the stone wall seems to be fluid and swirls around.\n"+
"Maybe you could enter the wall if you are brave enough.\n";
      dest_dir = 
({
"players/nightshade/room/c1", "east",
      });
}
enter(str) {
   if(!str) return;
   if(str == "wall") {
write("You meld with the stone and enter another room.\n");
this_player()->move_player("#players/nightshade/room/c3");
return 1;
}
}
