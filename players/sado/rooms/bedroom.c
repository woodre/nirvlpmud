inherit "/players/sado/rooms/mansion.c";

reset()
{
   set_short("Sado's master bedroom");
   set_long("Two things bring themselves most immediately to your attention:\n"+
   "The bed in the center of the room, and the huge bay window.\n"+
   "\n"+
   "You are also surprised that the entire floor is littered with cushions.\n"+
   "This room is well lit, but has light switches everywhere.\n");
   set_items(({"bed","This is a large wood-frame bed.  It's cherry wood, the dark natural color\n"+
         "filling the room with its beauty and richness.  On the elegant\n"+
         "frame sits a very comfy looking mattress.  Satin sheets cover\n"+
         "that, and a down comforter lies on top.  You could definitely\n"+
         "learn to enjoy falling asleep on this bed.  Especially with\n"+
         "Sado there beside you",
         "window","The bay window takes up one whole side of the room.  The east side,\n"+
         "so that the warm rays of the sun can enter in the morning, waking Sado\n"+
         "and any companion(s) with its warm and gentle touch.\n"+
         "The view from the window is stunning",
         "view","You gaze out the window, taking in the stunning view.  You look\n"+
         "out over the top of a cliff onto a beach some 50 feet below, with\n"+
         "ocean waves breaking on a coral reef about a mile offshore.\n"+
         "In the lagoon below you, a single-masted sailboat rests at\n"+
         "anchor.  In the far distance, an island sticks out of the\n"+
         "endless blue horizon.  It's just too far to be able to make\n"+
         "out individual trees, but you can clearly see that the whole\n"+
         "island is ringed by a pristine white beach.\n"+
         "You wish Sado would take you on a trip there some time",
         "cushions","They are scattered everywhere.  All over the floor, from wall to\n"+
         "wall.  They are mostly covered in satin and velvet in a variety of\n"+
         "light colors, adding to the light in the room.  As you look closer,\n"+
         "you notice that in fact the cushions you see aren't in fact covering\n"+
         "the floor, but are in fact covering another layer of cushions under\n"+
         "the first",}));
set_dest_dir(({"/players/sado/rooms/workroom.c","work",}));
   set_light(1);
}
