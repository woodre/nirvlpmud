inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Ghu'lar ->", });

if(!present("trolloc5.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/trolloc5.c"),this_object());
if(!present("trolloc3.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/trolloc3.c"),this_object());
if(!present("fade.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/fade.c"),this_object());
}
