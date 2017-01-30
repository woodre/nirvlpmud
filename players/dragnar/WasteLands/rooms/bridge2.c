inherit "room/room";
init() {
   ::init();
   this_player()->set_fight_area();
	add_action("east","east");
}

reset(arg) {
   if( !present( "man" ) )
     move_object(clone_object("/players/dragnar/WasteLands/mons/pirate.c"), this_object());

   if(arg) return;
   set_light(1);
   short_desc=("Gate to town");
   long_desc=
   "The absence of light makes crossing more difficult, but you make it\n"+
   "without falling victim to the collapsing bridge.  As you  approach\n"+
   "the end of the bridge, you can see the town farther to the east.\n",
   items=
   dest_dir=
   ({
         "players/dragnar/WasteLands/rooms/bridge.c","west",
         "players/dragnar/WasteLands/rooms/townrd.c","east",
    });
}
east() {
	if(present("man")){
	write("Man says: I will not let you into town.\n");
	return 1;
	}
}
