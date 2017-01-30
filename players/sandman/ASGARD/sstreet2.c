inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "a red brick road";
   long_desc=
      "The red brick road ends at the base of a slime white spiraling\n" +
      "tower. The draw bridge is down, maybe you could 'enter'?\n";
   items=
   ({
     "red road","This road is paved with glazed brick",
     "tower", "A magestic white tower, maybe you should 'enter'?",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/sstreet1","north",
     "players/sandman/ASGARD/BALDAR/entrance","enter",
   });
}
