#define TP this_player()
#define TO this_object()
#define TPN CAP(TP->query_name())
#define GEN TP->query_possessive()
#define CAP capitalize
#define PRE present
#define CO call_other
#define MO move_player
#define TE tell_object
#define TR tell_room
#define CATA1 "wandering..#players/snow/shadows/cata/cata1"
#define CATA2 "wandering..#players/snow/shadows/cata/cata2"
#define CATA3 "wandering..#players/snow/shadows/cata/cata3"
#define CATA4 "wandering..#players/snow/shadows/cata/cata4"
#define CATA5 "wandering..#players/snow/shadows/cata/cata5"
#define CATA6 "wandering..#players/snow/shadows/cata/cata6"
#define CATAL1 "wandering..#players/snow/shadows/cata/cata_lair1"
#define CATAL2 "wandering..#players/snow/shadows/cata/cata_lair2"
 
realm() { return "NT"; }
 
inherit "room/room";
 
reset(arg){
 
 
 set_light(-1);
  short_desc="In the Dark Catacombs";
 
items=({
 "rock", "Shadow-rock carved by powers beyond your comprehension",
 "passageway","Several passages lead away into the darkness",
});
 
 
}

init() {
  ::init();
this_player()->set_fight_area();
  wandering();
add_action("wander_cata","wander");
add_action("listening","listen");
}

exit() {
  if(this_player()) {
    if(this_player()->is_player()) this_player()->clear_fight_area(); } }
 
up_move() {
  say(TPN+" rises up out of the catacombs...\n");
  write("You rise up out of the catacombs...\n");
  call_other(TP,"move_player","#players/snow/shadows/fort/throne_room");
return 1;
}
 
wander_cata() {
  int SHW;
  string destdir;
SHW = random(35);
  if(TP->query_guild_name() == "cyberninja") SHW = random(8);
  write("You wander through the twisting catacombs...\n");
    if(SHW == 0) destdir = CATAL2;
    if(SHW == 1) destdir = CATAL1;
    if(SHW == 2) destdir = CATA2;
    if(SHW == 3) destdir = CATA3;
    if(SHW == 4) destdir = CATA4;
    if(SHW == 5) destdir = CATA5;
    if(SHW == 6) destdir = CATA6;
    if(SHW == 7) destdir = CATA1;
    if(SHW > 6 && SHW < 14) destdir = CATA2;
    if(SHW > 13 && SHW < 20) destdir = CATA3;
    if(SHW > 19 && SHW < 25) destdir = CATA4;
    if(SHW > 24 && SHW < 30) destdir = CATA5;
    if(SHW > 29 && SHW < 35) destdir = CATA6;
    if(SHW > 34) destdir = CATA1;
  call_other(TP,"move_player",destdir);
return 1;
}
 
listening() {
  write("You hear faint noises from your subconscious... strange.\n");
return 1;
}
 
wandering() {
  object mo, here;
mo = clone_object("/players/snow/shadows/mon/dark_crawler");
here = present("dark crawler");
  if(!here) {
    if(random(100) < 25) {
      move_object(mo,TO);
    return 1;
    }
  }
return 1;
}
query_srealm() { return "shad"; }
