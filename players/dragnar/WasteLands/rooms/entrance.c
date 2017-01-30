inherit "room/room";

object tyme, sign;

init() {
	::init();
   add_action("reset_scar_obj","reset_scar_obj");
   add_action("ask","ask");
}

exit() {
  if(this_player())
    this_player()->clear_fight_area(); 
}

reset(arg) {
  if(!present("tyme",this_object())) {
    tyme = clone_object("players/dragnar/WasteLands/mons/tyme.c");
    move_object(tyme, this_object());
  }
  if(!present("sign",this_object())){
    sign=clone_object("players/dragnar/WasteLands/obj/sign.c");
    move_object(sign, this_object());
  }
  
  if(arg) return;
  set_light(1);
  short_desc=("Entrance to the Wastelands");
  long_desc=
"The world you are in is a vast wasteland.  You would be able\n"+
"to see far in all directions if it was not for the lack of light.\n"+
"The sun is blocked by a strange looking cloud that covers the entire\n"+
"sky.  To the north the land looks almost entirely barren, but it\n"+
"is the only direction that looks passable.\n",
items=
({
"cloud","The dust cloud hangs over the land like a mask of death.  Some light\n"+
   "manages to get through, but at best it seems like dusk.  Only a nuclear\n"+
   "war could cause a cloud as massive and devastating as this one",
"sun","You can barely make out where it is in the sky because of the dust cloud"
});
    dest_dir=
  ({
  "players/dragnar/WasteLands/rooms/arena.c","north",
  "room/sunalley2","back",
  });
}

ask( string str ) {
  if( !str ) {
    write("Tyme says: Perhaps you want to ask about the scar or the quest?\n");
    return 1;
  }
  write("You ask: "+str+"\n");
  say(capitalize(this_player()->query_name())+" asks: "+str+"\n");
  return 1;
}

reset_scar_obj() {
  object      gob;
  string name;

  if(!this_player()->query_interactive() ) return 1;
  
  name = lower_case(this_player()->query_name());
  
  if(!present("tyme", this_object())) {
    write("Tyme isn't here to help you.\n");
    return 1;
  }
  
  if(present("bloodscar", this_player())) {
    write("Tyme screams: You already have a scar, fool!\n");
    return 1;
  }

  if( restore_object("players/dragnar/kills/" + name) ) {
    gob = clone_object("players/dragnar/closed/scar");
    move_object(gob, this_player());
    write("Tyme says: Your scar has been returned.\n");
    return 1;
  }
  
  write("Tyme says:  Sorry, can't help you.\n");
  write("Tyme says: Perhaps Dragnar could assist in this matter?\n\n");
  destruct(gob);
  return 1;
}
