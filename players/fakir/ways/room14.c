inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Saldaea ->", });

if(!present("fade.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/fade.c"),this_object());
if(!present("fade.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/ballrok.c"),this_object());
}
