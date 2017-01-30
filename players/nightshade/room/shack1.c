inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = "Small Shack";
     long_desc =
"You are inside a small shack. An old man sits in the middle of\n"+
"the shack. He seems to be meditating. Across his lap lays a pair\n"+
"of beautiful looking scimitars. Behind him is a glowing vortex set in the middle of the wall.\n";
      dest_dir = 
({
    "players/nightshade/room/forest24", "out",
      });
}
monster()
{
object duh;
if(!present("man"))
{
duh=clone_object("players/nightshade/mons/old_man");
move_object(duh, this_object());
}
}

