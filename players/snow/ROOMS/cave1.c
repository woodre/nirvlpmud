inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(0);
  short_desc="In the cave";
 long_desc=
 "After lighting the room you can see you are indeed in a cave. It smells \n\
like wet fur and death in here and you can see bits of crunched bone and \n\
hair lying about. The cave expands to the west while a passage \n\
leads to the southeast.\n";
 
items=({
 "bone", "The bits of bone look like they have been chewed by powerful jaws",
 "hair","Little wisps of hair, some of it looks human", });
 
  dest_dir=({
  "/players/snow/ROOMS/path3.c","leave",
  "/players/snow/ROOMS/cave2.c","southeast",
 "/players/snow/ROOMS/cave3.c", "west"});
  }   }
 
 
init()  {
 ::init();
  add_action("smell_room","smell"); 
  add_action("search_room","search");
}
 
smell_room() {
  write("You sniff the air, then wrinkle your nose and gag in disgust.\n");
  say (this_player()->query_name() +"sniffs the air and gags in disgust.\n");
  return 1;  }
 
search_room() {
  write("You search the room but find nothing of value.\n");
  say (this_player()->query_name() +"searches the room in vain.\n");
  return 1;  }
