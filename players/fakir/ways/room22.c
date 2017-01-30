inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Meradon ->", });

if(!present("blight.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/blight.c"),this_object());
if(!present("lurker.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/lurker.c"),this_object());
}
