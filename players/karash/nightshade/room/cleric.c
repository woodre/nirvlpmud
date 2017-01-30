inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
if(!present("cleric"))
{
while(i<5)
{
ob=clone_object("players/nightshade/mons/cleric");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = " Clerics Room";
     long_desc =
"Holy symbols of many different gods line the walls here. You see\n"+
"they teach here many different mythos. You see a group of young,\n"+
"scantily clad women, in a circle praying to the goddess of fertility.\n";
      dest_dir = 
({
"players/nightshade/room/guild_row3", "west",
      });
}
