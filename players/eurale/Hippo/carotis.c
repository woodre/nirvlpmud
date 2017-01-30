inherit "room/room";

reset(arg){
  if(arg) return;
set_light(1);

short_desc = "The arteria carotis interna";
long_desc =
  "  You are in the main artery leading to Hippo's brain.  It is very dark all\n"+
  "around you with swirling red liquid obscuring the way.\n";

items = ({
  "liquid","Swirling red blood rich in oxygen",
});

dest_dir = ({
"/players/hippo/quest_1/willosi.c","willosi",
"/players/eurale/Hippo/aorta.c","aorta",
});
}
