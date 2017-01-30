/*
 nautilus_chart_room.c - chart room of the nautilus
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("chart room");
  no_castle_flag=1;
  long_desc=
    "The starboard wall of this small room is one large chart of the seas.\n";
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
      "chart","The chart is labeled:  Current patrol route.\n\n"+
              "____________________________________\n"+
              "____                   ________ ___ \n"+
              "_                        ____  ___  \n"+
              "               .....                \n"+
              "               .### .               \n"+
              "               .#SS# .              \n"+
              "               #.SSS# .             \n"+
              "              ##S%SSS# .            \n"+
              "              #SSSSSS# .            \n"+
              "             ###SS### %             \n"+
              "   ___ __      #####       ____     \n"+
              "__________              ______ ____ \n"+
              "____________________________________\n"+
              "------------------------------------\n"+
              "  = Ocean    %= Harbour   S= Land\n"+
              " #= unknown  .= Sea link\n",
    });
  dest_dir=
    ({
      "players/nooneelse/sea/nautilus_below_deck", "leave",
    });
  return;
}
