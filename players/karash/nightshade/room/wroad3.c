inherit "players/nightshade/new_room";
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " West Road";
     long_desc =
"The road comes to an abrupt end here and a dark cave begins.\n";
      dest_dir = 
({
"players/nightshade/room/wroad2", "east",
      "players/nightshade/room/c17", "west",
      });
}
