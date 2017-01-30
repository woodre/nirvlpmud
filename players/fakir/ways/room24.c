inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Pal'nor ->", });
if(!present("devourer",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/devourer.c"),this_object());
}
