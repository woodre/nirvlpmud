inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Saidin Zarl ->", });

if(!present("trolloc4.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/trolloc4.c"),this_object());
if(!present("trollcpt.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/trollcpt.c"),this_object());
}
