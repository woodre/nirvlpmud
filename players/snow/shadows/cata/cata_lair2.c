/*  10/09/06 - Rumplemintz: moved inherit above #define statement  */

inherit "room/room";
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
 
reset(arg){
 
 if(!present("cleoprites")) {
  move_object(clone_object("/players/snow/MONSTERS/cleop.c"),TO); }
 
 if(!arg){
 
 set_light(0);
  short_desc="In the Demon Lair";
 long_desc=
 "Black fires seem to be the walls of this nightmarish room. Negative\n"+
 "lightning sketches black relief across your eyes. You realize you have\n"+
 "reached a junction between the planes of shadow and flame.\n"+
 "The only exit for the living is out.\n";
 
items=({
 "fires", "Shadow-fire burns a different type of heat, but equally deadly",
 "lightning","Slashing streaks of negative energy formed at the planar\n"+
             "junction. Death awaits those who try to cross through it",
 "junction","A meeting point of the planes of flame and shadow. Nothing\n"+
            "living could pass through it",
});
 
  }   }
 
init() {
  ::init();
this_player()->set_fight_area();
add_action("wander_cata","out");
add_action("cross_junction","cross");
}

exit() { if(this_player()) this_player()->clear_fight_area(); }
 
wander_cata() {
  int SHW;
  string destdir;
SHW = random(40);
  if(TP->query_guild_name() == "cyberninja") SHW = random(7);
  write("You wander through the twisting catacombs...\n");
    if(SHW == 0) destdir = CATA1;
    if(SHW == 1) destdir = CATAL1;
    if(SHW == 2) destdir = CATA2;
    if(SHW == 3) destdir = CATA3;
    if(SHW == 4) destdir = CATA4;
    if(SHW == 5) destdir = CATA5;
    if(SHW == 6) destdir = CATA6;
    if(SHW > 6 && SHW < 14) destdir = CATA2;
    if(SHW > 13 && SHW < 20) destdir = CATA3;
    if(SHW > 19 && SHW < 25) destdir = CATA4;
    if(SHW > 24 && SHW < 30) destdir = CATA5;
    if(SHW > 29 && SHW < 35) destdir = CATA6;
    if(SHW > 34) destdir = CATA1;
  call_other(TP,"move_player",destdir);
return 1;
}

cross_junction(arg) {
  if(!arg) { write("Cross what?\n"); return 1; }
  if(arg == "junction") {
    write("You foolishly try to cross the planar junction...\n");
    say(TPN+" foolishly tries to cross the planar junction...\n");
    if(TP->query_ghost()) {
      write("Your soul is trapped between the planes and annihilated!\n");
      destruct(TP);
    return 1;
    }
    call_other(TP,"hit_player",random(150));
    write("You are ripped apart by shadow flames!\n");
    write(TPN+" is ripped apart by shadow flames!\n");
    if(TP->query_ghost()) {
      write("Your soul is trapped between the planes and annihilated!\n");
      destruct(TP);
    return 1;
    }
    write("You endure the planar forces...\n");
    call_other(TP,"move_player",
               "across the planar junction#players/dune/room/fire5.c");
    return 1;
  }
}
query_srealm() { return "shad"; }
