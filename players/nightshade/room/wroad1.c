inherit "players/nightshade/new_room";
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " West Road";
     long_desc =
"This a road leading out of the village towards the Dragonspine\n"+
"mountains to the west.\n";
      dest_dir = 
({
"players/nightshade/room/vroad3", "east",
      "players/nightshade/room/wroad2", "west",
      });
}
