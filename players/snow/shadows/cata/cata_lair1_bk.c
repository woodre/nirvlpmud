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
 
 if(!present("balathuil")) {
  move_object(clone_object("/players/snow/shadows/mon/death_knight"),TO);
 }
 
 if(!arg){
 
 set_light(0);
  short_desc="In the Catacomb Tomb";
 long_desc=
 "You have come to a dark, tomblike room. Sigils of ancient power line\n"+
 "the walls. A bed of shadow iron lies along the far wall. Black roses are\n"+
 "the dominant motif. At least the scratching noises are gone.\n"+
 "The only way from this room is out.\n";
 
items=({
 "walls", "Shadow-rock carved by powers beyond your comprehension. Sigils of\n"+
          "power are inscribed in slightly glowing script",
 "sigils","Silvery scripts of some ancient spell-caster",
 "bed", "A bed made of dark shadow-metal. It looks very uncomfortable but\n"+
        "you could lie on it if you wanted to rest\n",
 "roses", "Beautifully formed soot-colored roses are carved into just about\n"+
          "everything you can see\n",
});
 
 
  }   }
 
init() {
  ::init();
this_player()->set_fight_area();
add_action("wander_cata","out");
add_action("lie_on_bed","lie");
}

exit() { if(this_player()) this_player()->clear_fight_area(); }
 
wander_cata() {
  int SHW;
  string destdir;
SHW = random(40);
  if(TP->query_guild_name() == "cyberninja") SHW = random(7);
  write("You wander through the twisting catacombs...\n");
    if(SHW == 0) destdir = CATAL2;
    if(SHW == 1) destdir = CATA1;
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
 
lie_on_bed(arg) {
  object dk;
dk = present("death knight");
  if(!arg) { write("Lie on what?\n"); return 1; }
  if(!arg == "on bed") { write("Lie on what?\n"); return 1; }
else
  write("You lie on the bed of black roses and feel strangely peaceful.\n");
  say(TPN+" lies down on the bed of black roses.\n");
  if(dk) {
    say("The Death Knight roars: How dare you so brazenly disrespect me?\n");
    dk->attack_object(TP);
  return 1;
  }
return 1;
}
query_srealm() { return "shad"; }
