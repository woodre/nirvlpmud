inherit "room/room";
 
reset(arg){
 
if(!present("brute"))  {
move_object(clone_object("/players/snow/MONSTERS/brute"),this_object());  }
if(!present("brute 2"))  {
move_object(clone_object("/players/snow/MONSTERS/brute"),this_object());  }
 
 if(!arg){
 
 set_light(1);
  short_desc="A cave entrance";
 long_desc=
"The winding path ends at the mouth of a cave here.\n"+
"The inside of the cave emanates a smell of death.\n";
 
items=({
 "trail", "A winding trail that seems safe for walking",
 "cave","A dark, forboding cave",
  });
 
  dest_dir=({
  "/players/snow/mountains/path","east"});
call_out("wander",10);
  }   }
 
wander() {
  if(!present("brute",this_object())) {
    tell_room(this_object(),"A brute wanders into the room!\n");
move_object(clone_object("/players/snow/MONSTERS/brute"),this_object());
call_out("wander",40);
return 1;
  }
    else
call_out("wander",40);
return 1;
}
 
init() {
  add_action("enter_cave","enter");
}
 
enter_cave() {
  if(present("brute",this_object())) {
    write("The brute will not let you past!\n");
return 1;
  }
else
  write("You enter the cave.\n");
call_other(this_player(),"move_object",
          "into the cave#players/snow/mountains/bandit/entrance.c");
return 1;
}
 
