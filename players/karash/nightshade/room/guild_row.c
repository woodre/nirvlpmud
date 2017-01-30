inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Guild_row";
     long_desc =
"This is whats known as Guild Row. All the guilds in Ledsville\n"+
"have there headquarters and training halls along this road. Each\n"+
"guild is headed by a commander, who teaches and trains prospective\n"+
"guild members.\n";
      dest_dir = 
({
   "players/nightshade/room/wroad2", "south",
"players/nightshade/room/guild_row2", "north",
      });
}
