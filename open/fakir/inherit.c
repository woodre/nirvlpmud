#include "/players/fakir/color.h"
inherit "/room/room.c";
init() {
   ::init();
   add_action("travel","travel");
}
travel() {
   string str;
   str = "/players/fakir/ways/room"+random(48)+".c";
   move_object(this_player(),"/players/fakir/ways/room"+random(48));
   command("look",this_player());
   return 1; }

reset(arg) {
   object shin;
   if(arg) return;
   shin = present("shin",this_object());
   if(shin && object_name(this_object()) != "/players/fakir/ways/room23.c")
      destruct(shin);
   long_desc =
   "    Utter and abysmal darkness surrounds, clings, and whispers like a\n"+
   "living entity.  A small patch of ground holds your weight, and bridges\n"+
   "span the gloom, leading to various islands similar to the one on which\n"+
   "you now stand. A sign is attached to the guidepost of the nearest bridge.\n";
   items = ({
         "bridge",    "Light grey stone without joint or seam.  Portions of the\n"+
         "rail and walkway have become diseased and seem unstable.  Still, you\n"+
         "might be able to 'travel' across if you are careful",
         "darkness",  "A result of the corruption and taint spawned by the Dark One\n"+
         "in the Time of Madness....it has become a tangible part of the living ways",
         "ground",    "A soft forgiving substance of some kind, although a heavy mist\n"+
         "clings to its surface and blocks your full view of what its true\n"+
         "appearence might be",
         "bridges",   "It is hard to see in the heavy darkness, but they look to be built\n"+
         "of a light grey stone, though no seams or joints can be seen.  Some\n"+
         "have the appearance of decay, as though they suffer from a virus or\n"+
         "disease and decay from within, making them unstable and dangerous to\n"+
         "cross",
         "gloom",     "Shadows, wisps of mist, shifting images of dark fears...it is\n"+
         "impossible to focus your mind on what you were just thinking",
         "islands",   "Small floating platforms covered in a grey mist that ebbs and wanes",
         "guidepost", "A tall, upright post made of the same material as the bridge", });

dest_dir = ({
   "/players/fakir/inn/room32.c",  "travel", 
});
}

short() { return MAGENTA+"The Ways"+OFF; }

realm() { return "NT"; }
okay_follow() { return 1; }





