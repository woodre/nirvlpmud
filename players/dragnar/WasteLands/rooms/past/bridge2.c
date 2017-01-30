inherit "room/room";
realm() { return "NT"; }
init() {
   ::init();
   this_player()->set_fight_area();
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Wastelands bridge");
   long_desc=
"Directly to your east you can see the begining of the town.  There are\n"+
"houses all over this part of the land.  To your west is the road that\n"+
"head towards the forest.\n",
   items=
   dest_dir=
   ({
         "players/dragnar/WasteLands/rooms/past/bridge.c","west",
         "players/dragnar/WasteLands/rooms/past/townrd.c","east",
    });
}
