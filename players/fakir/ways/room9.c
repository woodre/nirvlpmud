inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- White Tower ->", });

if(!present("spirit.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/spirit.c"),this_object());
}
