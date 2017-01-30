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
"players/nightshade/room/vroad3", "out",
"players/nightshade/room/in1", "north",
      });
}
