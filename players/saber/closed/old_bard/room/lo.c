#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
  t = 0;
short_desc="Bard Lore Chamber- Ruins";
long_desc=
   "Gone, lost, destroyed in a singular act of vengence, the heart of\n"+
   "bardic lore is now broken.  Shelves of scrolls and books have been\n"+
   "burned by the vicious heat of a fire, and only scraps remain.  A large\n"+
 "pile of rubble spreads in one corner. Melted,bent,but still recognizable,\n"+
 "a rapier is wedged between two rocks.\n";

items=({
  "rubble","Broken stone and splintered wood pile together in\n"+
           "one corner.  Barely visible are what appear to be\n"+
           "fingers- outstreched in a final, desperate plea for\n"+
           "aid which went unheeded",
  "rapier","This rapier was once worn by Tuyen, Keeper of Bardic\n"+
           "Lore.  It has been fused to the rock by some extreme heat",
 });

  dest_dir=({
 "/players/saber/closed/old_bard/room/adv.c","north",
 "/players/saber/closed/old_bard/room/com.c","east",
           });
  call_out("flicker",5);
  }   
}

flicker() {
  tell_room(this_object(),
  "The blaze of a great conflagration, to the\n"+
  "northeast, burns into your eyes.\n");
  call_out("flicker",10+random(80));
return 1; }
