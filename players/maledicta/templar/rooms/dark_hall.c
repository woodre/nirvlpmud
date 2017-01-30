#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int elite;

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "a dark passage";
   long_desc =
   "   This is a very dark passage leading to the western part of\n"+
   "the castle. You find it highly unusual that this part of the\n"+
   "castle would be so dark and dank compared to the rest. The\n"+
   "passage leads to the west and out to the main hall to the east.\n";
   
   
   dest_dir = ({
            "/players/jaraxle/templar/rooms/command_post.c","up",
         "/players/maledicta/templar/rooms/hallway2","east",
         "/players/maledicta/templar/rooms/dark_stair","west",
});
}

init(){ 
   ::init();
add_action("up","up");
   this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
up(){
       if(!present("EliteTemplar",this_player())){
write("Something blocks you from moving in that direction.\n");
return 1; }
}
