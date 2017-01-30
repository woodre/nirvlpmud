inherit "room/room";
 
reset(arg) {
  while(!present("clerk 7"))
#if 0 /* Rumplemintz */
    move_object(clone_object("/players/trix/castle/town/monst/clerk.c"));
#else
    move_object(clone_object("/players/trix/castle/town/monst/clerk.c"),
                this_object());
#endif
  if(arg) return;
  set_light(1);
  long_desc = 
"  You're in the eastern part of Trixtown Bank.  You can see Trixtown 2nd\n"+
"street to the north, while there are other rooms to the west.\n";
  short_desc = "Trixtown Bank";
  dest_dir = ({ "/players/trix/castle/town/2str1s.c","north",
                "/players/trix/castle/town/bank2.c","west"});
}
