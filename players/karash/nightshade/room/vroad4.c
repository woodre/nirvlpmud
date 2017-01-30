inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
if(!present("vendor"))
{
while(i<1+random(3))
{
ob=clone_object("players/nightshade/mons/vendor");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = " Ledsville";
     long_desc =
"These are the gates leading up to the Ledsville mansion. They do\n"+
"not want visitors so it is closed and locked. Off to the west you\n"+
"notice a Magic Shop has been set up and to the east is a funky\n"+
"armor shop.\n";
      dest_dir = 
({
   "players/nightshade/room/shoprd", "north",
/*
"players/nightshade/room/arm_shop", "east",
*/
"players/nightshade/room/test2", "west",
      });
}
