inherit "room/room";
int i;
reset(arg) {
   if(!present("baldar")) {
      move_object(clone_object("players/sandman/MONSTERS/baldar"), this_object());
   }
   if(!present("guard")) {
      for(i=0;i<2;i++) {
         move_object(clone_object("players/sandman/MONSTERS/bald_grd"), this_object());
      }
   }
   if(!arg) {
      set_light(1);
      short_desc=("Baldar's Study [leave]");
      long_desc=
        "This is an elegantly decorated study. Leather bound tomes line the\n"
+       "wall. Here and there hang an ancient weapon or armour. Sitting in\n"
+       "a deep plush chair sits the majestic figure of Baldar the Brave.\n"
+       "he is flanked by two giant attendents. On the far wall is a\n"
+       "swirling portal.\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/sstreet2", "leave"
      });
   }
}
