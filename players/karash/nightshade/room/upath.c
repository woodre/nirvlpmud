inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(0);
        short_desc = "Underground Path";
     long_desc =
"You are walking on an underground path of some sort. The walls are a dull grey color and very smooth. It leads north and south.\n";
      dest_dir = 
({"/room/pub2", "up",
      "players/nightshade/room/upath2", "south",
      });
}
