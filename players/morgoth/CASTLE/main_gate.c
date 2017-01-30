inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "main gate";
  long_desc = "The main gate to Morgoth's fortress.\n"+
              "The fortress is modeled after the Castle Warwyck in\n"+
              "Yorkshire, England.  Large stone gargoyles leer at you\n"+
              "from the battlements above.  They serve to ward of evil\n"+
              "and enemies of all kinds.  A wide iron bar gate is raised allowing you access.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/pen_lane2", "south",
      "players/morgoth/CASTLE/main_gate2", "north"
  });
}
