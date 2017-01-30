inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
if(!present("thief"))
{
while(i<5)
{
ob=clone_object("players/nightshade/mons/thief");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = " Thieves Room";
     long_desc =
"This is where all the thieves in Ledsville come to practice and\n"+
"hone their skills to perfection. There are quite a few you see.\n";
      dest_dir = 
({
"players/nightshade/room/guild_row2", "east",
      });
}
