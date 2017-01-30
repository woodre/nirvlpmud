/*  10/09/06 - Rumplemintz: moved inherit above #include statement  */

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
 
realm() { return "NT"; }
 
 
reset(arg){
 
  object g1,g2;
g1 = clone_object("/players/snow/shadows/mon/sguard");
g2 = clone_object("/players/snow/shadows/mon/sguard");
 
if(!present("major domo"))  {
move_object(g1,TO);
move_object(g2,TO);
move_object(clone_object("/players/snow/shadows/mon/majdomo"),TO);
}
 
 if(!arg){
 
 set_light(0);
  short_desc="ShadowFortress Reception Room";
 long_desc=
 "You have entered an ornately (yet monochromatically) decorated room.\n"+
 "The reception room of the ShadowFortress is no lighter than the outside.\n"+
 "There is one exit from this room- leading to a hall of shadows. For lack of\n"+
 "orientation you can only call the exit 'out'.\n";
 
items=({
 "decorations", "Intricate designs writh around the walls. You grow dizzy",
 "room","This appears to be a reception room of the fortress",
});
  }   }
 
init() {
  ::init();
this_player()->set_fight_area();
add_action("out_room","out");
}

exit() {   if(this_player()) this_player()->clear_fight_area(); }
 
out_room() {
  object md;
md = present("major domo");
  if(md) {
    if(!(md->query_bribed() == 1)) {
      write("The major domo looks displeased and blocks your exit from the room.\n");
    return 1;
    }
    if(md->query_bribed() == 1) {
      write("The major domo bows as you pass out of the room.\n");
      say("The major domo bows to "+TPN+".\n"+
          TPN+" leaves the reception room.\n");
    }
  }
 call_other(TP,"move_player","out#players/snow/shadows/fort/main_hall");
 tell_object(TP,"The opening you came through vanishes!\n");
return 1;
}
query_srealm() { return "shad"; }
