inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "A garden path";
  long_desc = "Just outside the Blues Alley Pub is a\n"+
              "long winding garden path.  Where it leads\n"+
              "is anyones guess...\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/blue_pub", "in",
      "players/morgoth/CASTLE/Egarden_path2", "south"
  });
}

query_temp() { return 1; }
