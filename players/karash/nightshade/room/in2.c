inherit "players/nightshade/new_room";
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Inside Fountain";
     long_desc =
"You are inside the fountain.\n";
      dest_dir = 
({
"players/nightshade/room/in3", "east",
"players/nightshade/room/in4", "west",
"players/nightshade/room/in1", "south",
"players/nightshade/room/in10", "north",
      });
}
