#define DEST "room/southroad3"

mixed
id(string str) {
  return str == "castle"; 
}

string
short() {
  return "To the south you can see the Castle of Angmar";
}

void
long() {
  write("This is the castle of Angmar.\n");
  write("Angmar, the necromancer, has not been seen in\n");
  write("this world for hundreds of years. Rumours say that\n");
  write("he is long dead. His castle, however, still stands\n");
  write("here as a monument of Evil, and it is quite possible\n");
  write("that the ghastly creatures conjured by Angmar still\n");
  write("lurks inside, guarding his immense riches.\n");
}

void
init() {
    add_action("south", "south");
}

status
south() {
  call_other(this_player(), "move_player",
    "into castle#players/angmar/castle/inside.c");
  return 1;
}

void
reset(status arg) {
  object quest, questroom;
  
  if(arg)
    return;
  
  move_object(this_object(), DEST);
  questroom = find_object("/room/quest_room");
  if (!present("angmar", questroom)) {
    quest=clone_object("obj/quest_obj");
    quest->set_hint(
    "No adventurer can call himself adventurer if he hasn't\n"+
    "broken into Angmar's treasury!\n");
    quest->set_name("angmar");
    move_object(quest,questroom);
  }
}
is_castle(){ return 1; }
