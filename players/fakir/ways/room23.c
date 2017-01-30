inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Kinch ->", });

if(!present("deceiver.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/deceiver.c"),this_object());
}
