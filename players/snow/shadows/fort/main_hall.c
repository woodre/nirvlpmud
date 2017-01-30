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
#define SHLORD "/players/snow/shadows/mon/slord"
#define SHGUARD "/players/snow/shadows/mon/sguard"
 
realm() { return "NT"; }
 
 
reset(arg){
 
  object lo1,lo2,g1,g2,g3,g4;
lo1 = clone_object(SHLORD);
lo2 = clone_object(SHLORD);
g1 = clone_object(SHGUARD);
g2 = clone_object(SHGUARD);
g3 = clone_object(SHGUARD);
g4 = clone_object(SHGUARD);
 
  if(!PRE("shadow lord"))  {
    move_object(g1,TO);
    move_object(g2,TO);
    move_object(g3,TO);
    move_object(g4,TO);
    move_object(lo1,TO);
    move_object(lo2,TO);
 }
 
 if(!arg){
 
 set_light(0);
  short_desc="ShadowFortress Great Hall";
 long_desc=
 "A huge, dark hall. Human-like shadow figures move swiftly around, moving in\n"+
 "and out of exits you cannot discern. There is a large opening at the other \n"+
 "end of the hall. There are no other exits so if you wanted to leave this room,\n"+
 "you could possibly enter the opening.\n";
 
items=({
 "hall", "The Great Hall must be at least 200 meters long by 50 meters wide.\n"+
         "Shadow figures seem to be passing through the walls somehow",
 "wall","The walls seem to be solid",
 "walls","The walls seem to be solid",
 "opening","You should be able to enter this opening... though where it leads\n"+
           "you cannot tell",
});
 
  }   }
 
init() {
  ::init();
this_player()->set_fight_area();
add_action("enter_op","enter");
}

exit() { if(this_player()) this_player()->clear_fight_area(); }
 
enter_op() {
  write("You walk the length of the Great Hall and pass through the opening.\n");
  say(TPN+" walks the length of the Great Hall and passes through the opening.\n");
 call_other(TP,"move_player",
    "through the opening#players/snow/shadows/fort/throne_room");
return 1;
}
query_srealm() { return "shad"; }
