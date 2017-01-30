inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Guild_row";
     long_desc =
"Guild row continues north and south. To the east are the headquarters\n"+
"of the Fighters Guild and to the west is where the Thieves Guild is\n"+
"located.\n";
      dest_dir = 
({
   "players/nightshade/room/guild_row", "south",
"players/nightshade/room/guild_row3", "north",
"players/nightshade/room/thief", "west",
"players/nightshade/room/fighter", "east",
      });
}
