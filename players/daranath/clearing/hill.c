inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
    short_desc="Entrance to Burrow";
    long_desc=
  "The hill rises up from the eastern edge of the Darkenwood clearing.\n"+
  "A small round door has been placed within the center of the hillock,\n"+
  "an entrance into a burrow of some sort. The hill is covered with a\n"+
  "thick layer of grass and the woods are all about.\n";

items=({
 "hill", "Its a rather small hill, standing just over six feet\n"+
         "at its apex and is surrounded by the Darkenwood",
 "woods", "The Darkenwood is a dangerous place, where humanoids and\n"+
          "other nasty creatures stalk about in the night",
 "grass", "The thick grass would make for a nice place for a picnic",
 "door", "A small, round door about 3 feet across at its widest point.\n"+
         "A small glass window is centered within it",
 "window", "Looking through the window brings about a scene of a homely\n"+
           "and comfortable place, if a bit small",
 "burrow", "The burrow appears to be occupied at this time",
 });


dest_dir=({
 "/players/daranath/clearing/burrow1.c","enter",
 "/players/daranath/clearing/clear6.c","west",
           });
        }
        }
