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
"players/nightshade/room/in6", "east",
"players/nightshade/room/in2", "north",
"players/nightshade/room/in5", "west",
"players/nightshade/room/in_fount", "south",
      });
}
