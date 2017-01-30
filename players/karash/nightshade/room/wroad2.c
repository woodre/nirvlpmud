inherit "players/nightshade/new_room";
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " West Road";
     long_desc =
"You are alone on this old worn path leading west to the mountains.\n"+
"They tower high up into the heavens and most of the peaks are topped\n"+"with snow and shrouded in clouds.\n";
      dest_dir = 
({
"players/nightshade/room/wroad1", "east",
      "players/nightshade/room/wroad3", "west",
"players/nightshade/room/guild_row", "north",
      });
}
