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
 
inherit "room/room";
 
reset(arg){
 
 if(!PRE("shadow king"))  {
  move_object(clone_object("/players/snow/shadows/mon/sking"),TO);  }
 if(!PRE("shadow lord 2")) {
  move_object(clone_object("/players/snow/shadows/mon/slord"),TO);
  move_object(clone_object("/players/snow/shadows/mon/slord"),TO);
 }
 
 if(!arg){
 
 set_light(0);
  short_desc="ShadowFortress Throne Room";
 long_desc=
 "A great shadowy room looms around you. A huge throne of some dusky material\n"+
 "stands against the far wall. There is an opening in the floor that leads to an\n"+
 "area blacker than the shadows themselves. A swirling portal is floating by the\n"+
 "throne. You could go back out to the great hall, down into the darkness, or\n"+
 "enter the portal.\n";
 
items=({
 "throne", "About 4 meters in height, this throne was made for someone of huge\n"+
           "stature... It is made of an unknown material",
 "opening","Pure black is all you can see in the opening",
 "portal","It looks like an interdimensional portal",
 });
 
  }   }
 
init() {
  ::init();
this_player()->set_fight_area();
add_action("out_room","out");
add_action("down_dark","down");
add_action("enter_portal","enter");
}

exit() { if(this_player()) this_player()->clear_fight_area(); }
 
out_room() {
  write("You leave the throne room toward the great hall.\n");
  say(TPN+" leaves the throne room toward the great hall.\n");
  call_other(TP,"move_player",
    "to the main hall#players/snow/shadows/fort/main_hall");
return 1;
}
 
down_dark() {
  if(present("king")) {
    write("The Shadow King stops you from descending.\n");
    return 1; }
  write("You descend into the dark...\n");
  say(TPN+" descends into the darkness...\n");
call_other(TP,"move_player",
    "into the catacombs#players/snow/shadows/cata/cata1");
return 1;
}
 
enter_portal(arg) {
  object sk;
sk = PRE("shadow king",environment(TP));
  if(!arg) { write("Enter what?\n"); return 1; }
  if(sk) {
    if(sk->query_gem() != 1 || sk->query_attack()) {
      TR(environment(TP),"The Shadow King blocks the portal.\n");
    return 1;
    }
    TR(environment(TP),"The Shadow King says: Farewell heroes.\n");
  }
  say(TPN+" enters the portal.\n");
  write("You enter the portal.\n");
  call_other(TP,"move_player","through the portal#players/snow/gate");
return 1;
}
query_srealm() { return "shad"; }
