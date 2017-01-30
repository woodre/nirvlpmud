inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Stedding Heartstone ->", });

if(!present("htrolloc.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/htrolloc.c"),this_object());
if(!present("trolloc2.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/trolloc2.c"),this_object());
}
