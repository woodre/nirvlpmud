inherit "players/nightshade/new_room";
init()
{
::init();
add_action("north", "north");
}
object ob;
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"This is the lair of Hephastus, a mighty red dragon. He has now\n"+
"taken up residence here, prevent the noble inhabitants of the\n"+
"village of Ledsville from mining the gems they need to live on.\n"+
"He is now sleeping on a huge pile of gems and other treasures\n"+
"that he has acquired. It would not be wise to wake him. Unless\n"+
"you want to gain the treasure he has stored in a small room to the\n"+
"north.\n";
      dest_dir = 
({
"players/nightshade/room/c26", "south",
      });
}
monster()
{
object x;
if(!present("dragon"))
{
x = clone_object("players/nightshade/mons/red_dragon");
move_object(x, this_object());
}
}
north()
{
if(!present("dragon"))
{
this_player()->move_player("leaves to claim his spoils#players/nightshade/room/c28");
write("You got lucky.\n");
return 1;
}
write("It would not be a good idea to try to sneak by Hephastus.\n"+
"Even though he is asleep, his hearing is far beyond the norm.\n");
return 1;
}
