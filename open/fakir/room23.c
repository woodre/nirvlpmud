realm() { return "NT"; }
#include "/players/fakir/color.h"
inherit "room/room";
int whoop;

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = MAGENTA+"The Ways"+OFF;
long_desc =
   "Utter and abysmal darkness surrounds, clings, and whispers like a living\n"+
   "entity.  A small patch of ground holds your weight, and bridges span the\n"+
   "gloom, leading to various islands similar to the one on which you now stand.\n"+
   "A sign is attached to the guidepost of the nearest bridge.\n";

items = ({
  "darkness",  "A result of the corruption spawned by the Dark One in the Time\n"+
               "of Madness....it has become a tangible part of the living ways",
  "ground",    "A soft forgiving substance of some kind, although a heavy mist\n"+
               "clings to its surface and blocks your full view of what its true\n"+
               "appearence might be",
  "bridges",   "It is hard to see in the heavy darkness, but they look to be built\n"+
               "of a light grey stone, though no seams or joints can be seen.  Some\n"+
               "have the appearence of decay, as though they suffer from a virus or\n"+
               "disease and decay from within, making them unstable and dangerous to\n"+
               "cross",
  "gloom",     "Shadows, wisps of mist, shifting immages of dark fears...it is\n"+
               "impossible to focus your mind on what you were just thinking",
  "islands",   "Small floating platforms covered in a grey mist that ebbs and wanes",
  "sign",      "The sign reads:\n\n"+
               "<- Kinch ->",
  "guidepost", "A tall, upright post made of the same material as the bridge",

});
}
init() {
  ::init();
  add_action("travel","travel");
}

travel() {
  string str;
  str="/players/fakir/ways/room"+random(41)+".c";
  move_object(this_player(),"/players/fakir/ways/room"+random(41));
  command("look",this_player());
  return 1;
}
