inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Dock road";
     long_desc =
"Large crates and bags are all neatly arranged in here. Different\n"+
"parts for the ships are stored here in case any of them have a run\n"+
"in with mages minions and get damaged.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad8", "south",
      });
}
init()
{
::init();
add_action("pry", "pry");
}
pry(str)
{
object duh;
if(str == "crate")
write("Due to abuse this has been shut down completely.\n");
return 1;
{
write("You pry open the crate.\n");
duh=clone_object("players/nightshade/misc/sail");
move_object(duh, this_object());
return 1;
}
}
