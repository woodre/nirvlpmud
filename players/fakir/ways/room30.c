inherit "/players/fakir/ways/inherit.c";
reset(arg) {
   if(arg) return;
   ::reset(arg);
   items += ({ "sign", "The sign reads:\n\n<- Arafel ->", });

if(!present("hobart.c",this_object()))
 move_object(clone_object("/players/fakir/ways/NPC/hobart.c"),this_object());

dest_dir = ({
   "/players/vertebraker/swamp/ROOMS/s35.c",  "waygate",
   "/players/fakir/inn/room31.c",  "travel", 
});
}
