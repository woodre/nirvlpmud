inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc="Mall Hallway";
  long_desc="You are standing just north of the entrance to the mall.\n"+
"To the east you can see the entrance to Omar's Novelty Shop.  Although\n"+
"Omar is a real pain in the butt some times, he does have some good stuff\n"+
"in his store.  To the west you can see Bubba's Pub.  And to the north you\n"+
"can see a large fountain in the middle of the hallway.\n";
  set_light(1);
  dest_dir=({
             "/players/grimm/closed/mall/pub","west",
             "/players/grimm/closed/mall/novelty","east",
             "/players/grimm/closed/mall/hall3","north",
             "/players/grimm/closed/mall/hall1","south",
           });
}
