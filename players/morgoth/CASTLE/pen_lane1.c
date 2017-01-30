inherit "room/room";
object blue, fireman, portrait, poppy;
int i;
reset(arg)
{
    if (arg) return;
    set_light(1);
    i = 0;
    if (!blue || !living(blue))
     {
       while (i < random(5))
      {
      i += 1;
      blue = clone_object("players/morgoth/MONSTERS/blue_meanie");
      poppy = clone_object("players/morgoth/OBJ/poppy");
      move_object(poppy, blue);
      move_object(blue, this_object());
      }
    }
    if (!fireman || !living(fireman))
    {
      fireman = clone_object("players/morgoth/MONSTERS/fireman");
      portrait = clone_object("players/morgoth/ARMOR/portrait");
      move_object(portrait, fireman);
      move_object(fireman, this_object());
    }
    short_desc = "Penny Lane";
    long_desc = "In Penny Lane there is a fireman with an hourglass.\n" +
                "And in his pocket is a portrait of the queen.\n" +
                "He likes to keep his fire engine clean.\n" +
                "It's a clean machine !\n";

dest_dir = 
({
   "players/morgoth/CASTLE/forest_3", "east",
   "players/morgoth/CASTLE/pen_lane2", "west",
});
}
