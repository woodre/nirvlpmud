inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Guild_row";
     long_desc =
"Guild row continues north and south. To the east are the headquarters\n"+
"of the Clerics Guild and to the west is where the Mages Guild is\n"+
"located.\n";
      dest_dir = 
({
   "players/nightshade/room/guild_row2", "south",
"players/nightshade/room/guild_row4", "north",
"players/nightshade/room/mage", "west",
"players/nightshade/room/cleric", "east",
      });
}
