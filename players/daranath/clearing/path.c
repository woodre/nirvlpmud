inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
    short_desc="Darkened Pathway";
    long_desc=
 "Darkness overwhelms you as you step onto the pathway that leads from the\n"+
 "deep forest to the south. The woods here are named Darkenwood and for\n"+
 "good reason. No light gets through the canopy of trees overhead,\n"+
 "casting deep shadows across the pathway. North of your position, the\n"+
 "path seems to lighten and even open into a clearing of sorts.\n";

items=({
  "path", "The pathway through the Darkenwood is one that does not see\n"+
          "much traffic, leading torwards an overgrown type of look.\n",
  "woods", "The Darkenwood is a place of horrors and humanoids, both of\n"+
           "which give it its reputation for nightmares.\n",
  "trees", "The overgrown trees block all light from coming in.\n",
  "shadows", "The shadows move as the wind moves the trees.\n",
  "clearing", "The clearing seems to open up to the north from here.\n",
 });


dest_dir=({
 "/players/daranath/clearing/clear1.c","north",
 "/room/deep_forest1.c","leave",
           });
        }
        }
