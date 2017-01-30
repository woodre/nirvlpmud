inherit "players/nightshade/new_room";
object lotto;
reset(arg){
   if(arg) return;
        set_light(1);
short_desc = "Trail!";
     long_desc =
"You have come up to a small clearing in the Phost Forest.  Trees\n"+
"such as Bronzewood, Phost, and Hornwood are tightly packed together\n"+
"at the edge of the clearing.  You can, however, spot a trail leading\n"+
"south through the forest.\n";
      dest_dir = 
({
"/room/station", "east",
"/players/nightshade/room/trail2", "south",
      });
}
init()
{
::init();
add_action("do_read", "read");
add_action("stop", "east");
/* We don't really need this.  - Feldegast 12-3-00
write_file("/players/nightshade/closed/AREA",

ctime(time())+" : "+this_player()->query_name()+" entered area.\n");
*/
}
do_read(str)
{
if(!str) return;
if(str == "sign")
{
write("IF YOU WANT SOME GOOD STUFF, DONT FORGET TO READ THE LONG DESCRIPTIONS! ALSO HIKE ON OVER TO MY ISLAND. LOTSA STUFF TO KILL!!\n");
return 1;
}
}

stop() {
  if(this_player()->query_name()
  == "Lag demon" || this_player()->query_name() == "lag demon") {
  return 1;
}
return 0;
}
