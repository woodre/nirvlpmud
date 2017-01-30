inherit "room/room";
int i;
reset(arg) {
   if(!present("quarterback")) {
      move_object(clone_object("players/sandman/MONSTERS/qb"), this_object());
   }
   if(!present("linebacker")) {
      for(i=0;i<2;i++) {
         move_object(clone_object("players/sandman/MONSTERS/linebacker"), this_object());
      }
   }
   if(!arg) {
      set_light(1);
      short_desc=("A football field [w]");
      long_desc=
      "This is your high school football field. And on it the star of the\n"+
      "team and his two main stoodges are getting in some extra practice.\n"+
      "Let's see if a foot ball is any match for cold steel!\n";
      dest_dir=
      ({
        "players/sandman/DAYDREAM/dpath1", "west"
      });
   }
}
