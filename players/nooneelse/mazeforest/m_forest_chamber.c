/*
  m_forest_chamber.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object obj;
  if (arg) return 0;

  set_light(0);
  short_desc="A dark chamber";
  long_desc=
    "You are in a dark chamber.  It is completely empty except for a\n"+
    "large wooden box in the far corner and the staircase leading up.\n";
  items=({
          "box", "The box is strangly shaped and has a hinged top.\n"+
                 "It is large enough for a human to lay down in.\n",
          "coffin", "The coffin is made of finely polished ironwood.\n",
          "staircase", "It is carved into solid granite and leads down",
          "stairs", "It is carved into solid granite and leads down",
        });
  dest_dir=({
             "players/nooneelse/mazeforest/m_forest20", "up",
           });
  obj=clone_object("/players/nooneelse/obj/coffin");
  move_object(obj, this_object());
}
