inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Aiel Waste ->", });

if(!present("searcher.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/searcher.c"),this_object());
}
