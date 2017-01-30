inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Shadow's Cawl ->", });

if(!present("lurker.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/lurker.c"),this_object());
}
