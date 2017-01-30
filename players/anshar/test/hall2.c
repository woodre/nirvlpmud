
inherit "/players/anshar/inherit/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="     Flickering torchlight glints from giant silvery suits\n"+
            "of armour standing sentinal at the gates. Ahead, a large\n"+
            "painting is hung against grey stone walls. The silence is\n"+
            "complete save the nearly noiseless flickerings of the torches.\n"+
            "The exit does indeed appear inviting.\n";
  room_listen=1;
  room_search=1;
  items=({
    "suits",    "Full suits of armour stand rigidly at attention",
    "armour",   "Full suits of armour stand rigidly at attention",
    "gates",    "Made of a dark metal, the carvings fill you with ominous thoughts",
    "carvings", "Bas relief apon the gates, the sculptures are scenes of battle",
    "painting", "It appears to be some sort of huge map",
    "map",      "As you gaze at the map, it flickers and shifts disturbingly",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  read_mess=({
    "suits",    "Full suits of armour stand rigidly at attention",
    "armour",   "Full suits of armour stand rigidly at attention",
    "gates",    "Made of a dark metal, the carvings fill you with ominous thoughts",
    "carvings", "Bas relief apon the gates, the sculptures are scenes of battle",
    "painting", "It appears to be some sort of huge map",
    "map",      "As you gaze at the map, it flickers and shifts disturbingly",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  search_items=({
    "suits",    "Full suits of armour stand rigidly at attention",
    "armour",   "Full suits of armour stand rigidly at attention",
    "gates",    "Made of a dark metal, the carvings fill you with ominous thoughts",
    "carvings", "Bas relief apon the gates, the sculptures are scenes of battle",
    "painting", "It appears to be some sort of huge map",
    "map",      "As you gaze at the map, it flickers and shifts disturbingly",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  listen_items=({
    "suits",    "Full suits of armour stand rigidly at attention",
    "armour",   "Full suits of armour stand rigidly at attention",
    "gates",    "Made of a dark metal, the carvings fill you with ominous thoughts",
    "carvings", "Bas relief apon the gates, the sculptures are scenes of battle",
    "painting", "It appears to be some sort of huge map",
    "map",      "As you gaze at the map, it flickers and shifts disturbingly",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  dest_dir=({
    "/players/anshar/hall/room/hall1", "back",
    "/players/anshar/hall/room/hall3", "west",
    "/players/anshar/hall/room/hall4", "east",
  });
}
