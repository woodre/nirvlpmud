#include "/players/mythos/closed/ansi.h"
inherit "room/room";

reset(arg){
  if(!present("updater")) {
    move_object(clone_object("/players/mythos/closed/play/updates.c"),
      this_object()); }
/*
  if(!present("setter")) {
    move_object(clone_object("/players/mythos/closed/play/setter.c"),this_object());
    }
   if(!present("impr")) {
    move_object(clone_object("/players/mythos/closed/play/impr.c"),this_object());
    } 
   if(!present("impr2")) {
    move_object(clone_object("/players/mythos/closed/play/impr2.c"),this_object());
    } 
   if(!present("smoke")) {
    move_object(clone_object("/players/mythos/closed/play/moo_ORG/meow.c"),this_object());
   }
    
   if(!present("smoke2")) {
    move_object(clone_object("/players/mythos/closed/play/moo_ORG/meow1.c"),this_object());
   }
  if(!present("usagi")) {
  move_object(clone_object("/players/mythos/closed/play/moo_ORG/meow2.c"),this_object());
}
*/
   if(!present("guest")) {
    move_object(clone_object("/players/mythos/closed/play/guest.c"),this_object());
    } 
  if(!arg){
  clone_object("/players/braxana/castle.c");
    set_light(4);
    short_desc=GRN+"Garden of War"+NORM;
    long_desc=
    "You have entered a room of utter tranquility.\n"+
    "The air is sweet and the birds chirp quietly.\n"+
    "However, there is one thing that mars this garden.\n"+
    "This is the place where Mythos tests his many items....\n";

    items=({
    "garden","It is quiet, calm, and green...",
    "portal","Leads back to Mythos's Workroom...",
    });

    dest_dir=({
    "/players/mythos/workroom.c","portal",
    });
  }
}

init() {
  ::init();
  add_action("test","test");
  add_action("doom","doom");
}

query_prevent_shadow() { return 1; } 
test() {
  say("A Dread Lord has been brought into existance!");
  say("\n");
  write("You summon a Dread Lord.\n");
  move_object(clone_object("/players/mythos/prac/dread.c"),this_object());
return 1;
}

doom() {
  write("DOOM has been called.\n");
  move_object(clone_object("/players/mythos/prac/doom.c"),this_object());
return 1;}

clean_up() { return 1; }
dest_inv() { return 1; }

wait() {
move_object(clone_object("/players/mythos/closed/play/impr2.c"),this_object());
return 1; }
