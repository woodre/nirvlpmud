inherit "room/room";
 
reset(arg){
 
object garl;
   garl = clone_object("players/snow/MONSTERS/sir_garl");

while( !present("brute 8") ) {
  move_object(clone_object("/players/snow/MONSTERS/brute"),this_object());
  }
  if (!present("Sir Garl")) {
    move_object(garl, this_object());
    tell_room(this_object(), "Sir Garl and his entourage enter.\n");
  }
 
 if(!arg){
 
 set_light(1);
  short_desc = "Bandit Lair";
 long_desc=
 "From the stinking bearskins on the walls to the pile of bones in\n\
the corner, this is a bandit hideout. Putrid smells of wine, sex, and\n\
blood permeate the air.\n";
 
items=({
 "bearskins", "Half-rotted bearskins line the walls. They have no value",
 "bones","A pile of animal bones from the bandits' last feast...\n"+
          "You find a lever among the bones!",
 "lever", "A lever you could pull... if you dared",
  });

  dest_dir=({
  "/players/snow/mountains/bandit/entrance.c","out",
});

call_out("wander",40);
  }
}
 
wander() {
  if(!present("brute",this_object())) {
    tell_room(this_object(),"A brute wanders into the room!\n");
move_object(clone_object("/players/snow/MONSTERS/brute"),this_object());
call_out("wander",10);
return 1;
  }
    else
call_out("wander",10);
return 1;
}
 
init() {
  ::init();
  add_action("smell_room","smell");
  add_action("search_room","search");
  add_action("pull_lever","pull");
}

 
smell_room() {
  write("As you smell the air, you gag from the stench.\n");
  say(capitalize(this_player()->query_name())+" smells the air and gags.\n");
return 1;
}
 
search_room() {
  write("You search the room and find a lever among the bones!\n");
  say(capitalize(this_player()->query_name())+
      " searches the room.\n");
return 1;
}
 
pull_lever(str) {
  object puller, pullname;
pullname = capitalize(this_player()->query_name());
puller = this_player()->query_real_name();
  if(!str) { write("Pull what?\n"); return 1; }
    if(str == "lever") {
  write("You pull the lever and are transported elsewhere!\n");
call_other(this_player(),"move_player","#/players/snow/gate.c");
tell_object(find_player(puller),"You reform in the Interdimensional Nexus!\n");
   say(pullname+" reaches into the bones and disappears!\n");
   tell_room("/players/snow/gate.c",pullname+" reforms beside you!\n");
return 1;
  }
}
