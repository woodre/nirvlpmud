/*
 nautilus_below_deck.c - below the bridge of the nautilus
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("below deck");
  no_castle_flag=1;
  long_desc=
    "This is a narrow hallway below the bridge of the nautilus.  You can\n"+
    "go forward, aft, enter the chart room, or go up to the bridge.\n";
  items=
    ({
      "walls", "They are steel plates, with large rivets.",
      "wall", "They are steel plates, with large rivets.",
      "floor", "It is made of steel plates, covered with a beautiful carpet.",
      "carpet", "It is a richly colored persian rug.",
      "rug", "It is a richly colored persian rug.",
      "ceiling", "They are steel plates, with light panels set in them.",
      "lights", "They are some kind of translucent material that are "+
                "glowing with light.",
      "panels", "They are some kind of translucent material that are "+
                "glowing with light.",
      "panel", "It is some kind of translucent material that are "+
               "glowing with light.",
      "light panels", "They are some kind of translucent material that are "+
                      "glowing with light.",
    });
  dest_dir=
    ({
      "players/nooneelse/sea/nautilus_observation_room", "forward",
      "players/nooneelse/sea/nautilus_engine_room", "aft",
      "players/nooneelse/sea/nautilus_chart_room", "enter",
      "players/nooneelse/sea/nautilus_bridge", "up",
    });
  return;
}
