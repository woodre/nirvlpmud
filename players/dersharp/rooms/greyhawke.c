inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="The Portal to GreyHawk";
   long_desc ="Swirling colors blind your vision as you enter this room.\n"+
              "On the floor is a circular piece of obsidian....the portal.\n"+
              "To the south you hear the sounds of a great city and \n"+
              "and the smell of refuse....You have entered the City of \n"+
              "Hawks! beware for treachery and deceit are everywhere!\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey4", "south",
   });
      items = ({
                "portal","This is a huge circular piece of obsidian the \n"+
                         "air around it tingles with electricity...\n"
});
}
