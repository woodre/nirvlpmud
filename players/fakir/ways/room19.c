inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Malkier ->", });

if(!present("ghul.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/ghul.c"),this_object());
if(!present("lurker.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/lurker.c"),this_object());
}
