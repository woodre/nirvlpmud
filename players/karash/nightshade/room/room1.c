inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
   monster();
        set_light(0);
        short_desc = "Underdark";
     long_desc =
"You have entered a vast cavern in the earth. You can go up or south.\n";
      dest_dir = 
      ({ "/players/nightshade/room/room2", "south",
      });
}
monster() {
object duh;
if(!present("guard"))
{
duh=clone_object("players/nightshade/mons/crysguard");
move_object(duh, this_object());
}
}
