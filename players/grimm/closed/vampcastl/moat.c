inherit "room/room";
realm() { return "NT";  }
int wait, jewel;
reset(arg) {
monst();
jewel = 0;
if(arg)
   return;

short_desc="Moat Bottom";
long_desc="You have sunk to the bottom of the moat!!!  Death is certain!!!\n";
set_light(1);
}
init() {
   add_action("up","up");
   add_action("search","search");
   if(present("vamp_amulet",this_player())) {
     while(present("ghoul")) {
       destruct(present("ghoul"));
     }
     write("\nAs you sink into the muk the amulet glows brightly!\n");
     write("\nThe amulet fires out and destroys the ghouls!\n");
   }
   ::init();
}
up() {
  int  count;
   count = random(100);
  if(time() < wait) {
    write("You have to rest your legs before trying again!\n");
    return 1;
  }
  if(count > 60) {
    write("You manage to swim up through the muck to the top!\n");
     this_player()->move_player("swimming up#players/grimm/closed/vampcastl/castle2");
   return 1; }
      else {
        write("You try very hard but your legs grow tired ( keep trying!! )\n");
        wait = time() + 3;
       }
  return 1;
}
monst() {
   object monster;
   int count;
   if(present("ghoul",this_object())) return 1;
   while(count<8) { count += 1;
   monster = clone_object("players/grimm/monster/moatghoul");
   move_object(monster,this_object());
   }
return 1; }
search() {
  if(!jewel) {
    move_object(clone_object("players/grimm/object/jewel"),this_object());
    write("You uncover something in the muk\n");
    jewel = 1;
    return 1;
  }
  return 1;
}
