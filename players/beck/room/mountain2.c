/* Modified on date: 9/6/05 at 3:39 PM by guilds */
/* Corrected numerous typos and added item descriptors */
/* 2005.10.15 at 11:15 PM by guilds - CommandCenter */

inherit "room/room";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=("Top of a mountain");
  long_desc=
"This is the top of the great mountain that sits off the main road\n\
and off in the distance is what could be a small town or village.\n\
From this distance it is hard to make out but the view is so magnificent\n\
from this height that the climb is worth it. The climb to the peak here\n\
is a difficult one and wears out even the most hardy of mountaineers.\n\
Down below are the fields that surround the mountain.\n";
  items=
  ({
    "road",
    "The main road that leads through the valley and fields below",
    "town",
    "The image in the distance faintly resembles a town or village",
    "village",
    "The image in the distance faintly resembles a town or a village",
    "fields",
    "Ripe fields of grain surround the base of the mountain",
  });
  dest_dir=
  ({
    "players/beck/room/mountain1.c","down",
  });
  if(!present("command center", this_object()))
    move_object("/players/guilds/Rangers/CommandCenter/CommandCenter.c",
                this_object());
}
