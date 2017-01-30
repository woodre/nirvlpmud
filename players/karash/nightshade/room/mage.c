inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
if(!present("mage"))
{
while(i<5)
{
ob=clone_object("players/nightshade/mons/mage");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = " Mages Room";
     long_desc =
"The room here is dark and forboding. You can barely make out a group\n"+
"of individuals surounding a man-sized, glowing mirror. You notice\n"+
"one of them seems to be talking into the mirror. This is the Mages\n"+
"practicing room for those interested in conversing with beings of\n"+
"another plane. Who knows who or what they are talking to.\n";
      dest_dir = 
({
"players/nightshade/room/guild_row3", "east",
      });
}
