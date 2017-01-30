inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Stedding Heartstone ->", });

if(!present("strolloc.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/strolloc.c"),this_object());
if(!present("trolloc3.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/trolloc3.c"),this_object());
}
