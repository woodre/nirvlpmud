#include "shaddefs.h"
realm() { return "NT"; }
 
inherit "room/room";
 
reset(arg){
  
 if(!arg){
 
 set_light(0);
  short_desc="ShadowPlane";
 long_desc=
 "Shadows flit around the corners of your vision. What seems clear one moment\n"+
 "disappears the next. Vague shadow bushes appear here and there- sometimes\n"+
 "you think you might even see a tree. Shapes of animals suddenly appear... \n"+
 "and as suddenly leave. The landscape appears to somehow flow around your\n"+
 "solidity here. To move from place to place, you must make a huge effort. \n"+
 "As you can tell no direction, you can but 'walk' around and hope to get\n"+
 "somewhere.\n";
 
items=({
 "bushes", "Bushes of shadowstuff. When you touch them, your hand meets little\n"+
           "resistance and passes through without noticable effect",
 "tree","You think you see a shadow tree but it fades away as you draw near",
 "animals","Vague animal shapes seem to peer at you, then fade away..",
 "landscape","Features of the land pass before your eyes",
});
 
call_out("wandering",100);
   }   }
 
init() {
  ::init();
add_action("walk_player","walk");
}
 
walk_player() {
  int SHW,RW;
  string destdir;
SHW = random(15);
  if(TP->query_guild_name() == "cyberninja") SHW = random(5);
  write("You slowly trudge across the shadowplain...\n");
    if(SHW == 0) destdir = SFORT;
    if(SHW == 1) destdir = SHILL;
    if(SHW == 2) destdir = SH2;
    if(SHW == 3) destdir = SH1;
    if(SHW == 4) destdir = SH4;
    if(SHW > 4 && SHW < 9) destdir = SH2;
    if(SHW > 8 && SHW < 13) destdir = SH1;
    if(SHW > 12 && SHW < 17) destdir = SH4;
    if(SHW > 16) destdir = SH3;
  call_other(TP,"move_player",destdir);
return 1;
}
 
wandering() {
  object shc, monst;
  int det;
 call_out("wandering",random(400));
shc = present("shadowcreature");
det = random(100);
  if(det < 2) monst = "/players/snow/shadows/mon/sdragon";
  if(det > 1 && det < 10) monst = "/players/snow/shadows/mon/shunter";
  if(det > 9 && det < 30) monst = "/players/snow/shadows/mon/ssnake";
  if(det > 29 && det < 40) monst = "/players/snow/shadows/mon/swraith";
  if(det > 39 && det < 60) monst = "/players/snow/shadows/mon/slion";
  if(det > 59) monst = "/players/snow/shadows/mon/swolf";
 if(!shc && random(100) < 45) {
   move_object(clone_object(monst),TO);
   return 1;
 }
 if(shc->query_real_name() == "shadow dragon") return 1;
 if(shc->query_real_name() == "shadow wraith") {
   if(present("shadow wraith 3")) return 1;
   if(random(100) < 30) {
     move_object(clone_object("/players/snow/shadows/mon/swraith"),TO);
   }
 return 1;
 }
 if(shc->query_real_name() == "shadow hunter") {
   if(present("shadow hunter 5")) return 1;
   if(random(100) < 40) {
     move_object(clone_object("/players/snow/shadows/mon/swraith"),TO);
   }
  return 1;
  }
 if(shc->query_real_name() == "shadow lion") {
   if(present("shadow lion 5")) return 1;
   if(random(100) < 20) {
     move_object(clone_object("/players/snow/shadows/mon/slion"),TO);
   }
 return 1;
 }
 if(shc->query_real_name() == "shadow wolf") {
   if(present("shadow wolf 4")) return 1;
   if(random(100) < 40) {
     move_object(clone_object("/players/snow/shadows/mon/swolf"),TO);
   }
 return 1;
 }
 if(shc->query_real_name() == "shadow snake") {
   if(present("shadow snake 6")) return 1;
   if(random(100) < 20) {
     move_object(clone_object("/players/snow/shadows/mon/ssnake"),TO);
   }
 return 1;
 }
return 1;
}
query_srealm() { return "shad"; }
