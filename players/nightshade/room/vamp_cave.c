inherit "players/nightshade/new_room";
object ob;
reset(arg){
if(!present("vampire"))
{
ob=clone_object("players/nightshade/mons/vampire");
move_object(ob, this_object());
}
   if(arg) return;
        set_light(0);
short_desc = "Dark Cave";
     long_desc =
"The old, venerable vampire, Count Magnus Lea has retired to this\n"+
"small cave with a few of his most precious items. He is tired of\n"+
"the day to day routines of his castle. He just wants some peace \n"+
"quiet now. He might get pissed if you distrub him.\n";
      dest_dir = 
({
"players/nightshade/room/i12", "out",
      });
}
