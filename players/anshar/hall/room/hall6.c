
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="    Harsh shadows flicker nervously about from the play of\n"+
            "the torchlight on rough-cut stone walls. Shining shields and\n"+
            "ragged banners line the walls in mute testimony to the combat\n"+
            "prowess of some great battle lord. Further north some flickers\n"+
            "of movement can be seen.\n";
  items=({
    "shadows",  "Gloomy shadows fill the hall, dancing fitfully",
    "walls",    "Rough hewn stone walls. Fit to repel any force laid against them",
    "torches",  "Ordinary torches save the fact they let off no heat",
    "shields",  "Beaten, yet polished trophies of war",
    "trophies", "Reminders of some war long past",
    "banners",  "Some mere shreds of cloth, the banners of defeated enemies",
    "movement", "Your eyes may be deceiving you, there is a flicker of silver ahead",
  });
  dest_dir=({
    "/players/anshar/hall/room/hall4", "south",
    "/players/anshar/hall/room/hall8", "north",
  });
}
