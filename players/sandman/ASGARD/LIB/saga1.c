inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Hall of Sagas");
   long_desc=
     "This is a musty crowded room full of history books. One particularly\n"+
     "large book sits on a table. The title reads: History of the Gods.\n";
   items=
   ({
     "book", "The book reads: And so Hemidal, guardian of the realm, keeps\n"+
             "in trust the key to valhalla..",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/LIB/entrance","north",
   });
}
