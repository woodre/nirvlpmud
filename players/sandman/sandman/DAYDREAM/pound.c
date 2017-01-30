inherit "room/room";
int i;

reset(arg) {
   if(!present("puppy")) {
      for(i=0;i<6;i++) {
         move_object(clone_object("players/sandman/MONSTERS/puppy"), this_object());
      }
   }
   if(!arg) {
      set_light(1);
      short_desc="Dog Pound [w]";
      long_desc=
        "This is a typical dog pound. The pound is full of adorable little\n"+
        "puppy dogs. They look up at you with love in thier eyes.\n";
      dest_dir=
      ({
        "players/sandman/DAYDREAM/gpath2", "west"
      });
   }
}
