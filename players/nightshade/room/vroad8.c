inherit "players/nightshade/new_room";
object ob;
int i;
reset(arg){
if(!present("sentry"))
{
while(i<3)
{
ob=clone_object("players/nightshade/mons/sentry");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = "Dock road";
     long_desc =
"The end of the dock is here. As you look down at the water you notice\n"+
"its a greenish color. Somehow you do not think that is normal. To the\n"+
"north is the storage facility for the boats and south of you is a rowdy\n"+
"looking tavern that the sailors and only the sailors dare to enter.\n"+
"A boat pulls up to the dock as you are standing here. Everyone is busy\n"+
"loading and unloading stuff. Maybe you could sneak aboard if you wanted\n"+
"to visit some place new.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad7", "west",
      "players/nightshade/room/vroad9", "north",
   "players/nightshade/room/vroad10","south",
      });
}
init()
{
::init();
add_action("do_stow", "sneak");
}
do_stow(str)
{
if(str == "aboard")
{
this_player()->move_player("onto the ship#players/nightshade/room/ship");
return 1;
}
}
