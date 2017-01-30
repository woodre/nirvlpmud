inherit "players/nightshade/new_room";
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"The cave looks to be widening now, and it gets very big further\n"+
"north. In that direction you see some huge creature, although you\n"+
"cant figure out what, laying on top of a pile of glittering items.\n"+
"You hear loud wheezin sounds coming from the creature.\n";
      dest_dir = 
({
"players/nightshade/room/c25", "south",
      "players/nightshade/room/c27", "north",
      });
}
