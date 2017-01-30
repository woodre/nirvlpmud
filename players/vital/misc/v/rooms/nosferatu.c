inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
set_light(-2);

short_desc = "Nosferatu Lounge";
long_desc =
  "Soft, comfortable couches and chairs sit in disarray about this\n"+
  "cozy room.  The floor has been covered with a thick, blood-red\n"+
  "carpet that keeps the noise to a minimum.  Cut into the stone walls\n"+
  "is a beautiful fireplace with logs burning to do away with the\n"+
  "chill.  This is a place where those vampires who have mastered the\n"+
  "skill of "+HIR+"NOSFERATU"+NORM+" can meet and share tales of "+
  "victory and defeat.\n";

items = ({
  "couches","Overstuffed leather couches with worn patches from much\n"+
            "use over the years",
  "chairs","Thick, stuffed chairs with high backs covered in dark "+
           "fabric",
  "floor","A soft carpet, the color of blood",
           "could best be described as a deep blood red",
  "fireplace","A curved opening, set right into the wall with a grey\n"+
              "stone hearth to catch any sparks",
  "logs","Hardwood that is buring with a reddish-yellow flame licking\n"+
         "off of it",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/mirrors","north",
  "players/eurale/VAMPIRES/RMS/cafe.c","south",
});

}

realm() { return "NT"; }
