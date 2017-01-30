inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
if(!present("thief"))
{
ob=clone_object("players/nightshade/mons/master_thief");
move_object(ob, this_object());
}
if(!present("cleric"))
{
ob=clone_object("players/nightshade/mons/master_cleric");
move_object(ob,this_object());
}
if(!present("fighter"))
{
ob=clone_object("players/nightshade/mons/master_fighter");
move_object(ob, this_object());
}
if(!present("mage"))
{
ob=clone_object("players/nightshade/mons/master_mage");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(1);
        short_desc = " Guild_row";
     long_desc =
"This is the end of Guild Row. Here the master of all guilds\n"+
"resides. He doesnt take to kindly to anyone not of a guild,\n"+
"bothering him. He looks very experienced, and if challenged\n"+
"will gladly destroy whomever was foolish enough to do so.\n";
      dest_dir = 
({
   "players/nightshade/room/guild_row3", "south",
      });
}
