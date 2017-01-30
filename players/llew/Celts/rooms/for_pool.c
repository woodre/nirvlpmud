inherit "room/room";

reset(arg) {
   if(!present("kiri")) move_object(clone_object("/players/llew/Celts/monsters/kiri.c"),this_object());
if(!arg) {
   set_light(1);
   short_desc="Forest Pool";
   long_desc="\tYou are deep within an impenetrable forest.  There is a sadness here\n"+
      "which you cannot understand.  There is an emptiness.\n"+
      "Pale green light filters through the leafy canopy.  It is warm, with\n"+
      "a slight breeze.  You think you could rest here and be content were\n"+
      "it not for the deep sense of sadness.\n"+
      "A small pool bubbles up from the rocks.  The water is clear and\n"+
      "inviting.  Constant ripples reflect the green light, giving off a relaxing\n"+
      "atmosphere.  A giant tree stands here, as old as time itself.  It looms\n"+
      "above you, filling all of one edge of this small clearing.  You gaze in\n"+
      "awe at the sight, pondering your significance.  What can your simple\n"+
      "existance mean compared to this?\n"+
      "The ground is soft and green grass fills the area.  The peace of this\n"+
      "place calms you, but again that sadness nags at you.\n";
      "clearing. East to Caer, north to road.\n";
   dest_dir=({
   "/players/llew/Celts/rooms/for_road1.c","west",
   });
   items=({
      "tree","The tree is unrecognizable.\nThere is only one way to describe it...  old.\n",
      "pool","The pool is cool and inviting.  Why not go for a swim?\n",
   });
   }
}
init() {
   ::init();
   add_action("swim","swim");
   add_action("search","search");
}
swim() {
write("You gently lower into the pool for a brief swim.\nIt is very comfortable.\n");
   say(this_player()->query_name()+" swims briefly in the pool.\n");
return 1;
}

search() {
   write("You find a few strands of golden hair, but to you it is meaningless.\n");
return 1;
}
