#define ME capitalize(this_player()->query_name())

reset(arg){
  if(arg) return;
}

id(str){
  return str == "box" || str == "follow_box" || str == "wooden box" ||
  str == "small box";
}

long(){
  write(
  "  Because of the way Nirvana works, the standard follow (allowing one or\n"+
  "  more players to automatically follow a leader) will not work in the\n"+
  "  Realms of Ilstkarn.  Because of this, I have created special object that\n"+
  "  will allow you to use follow.  ONLY THE LEADER needs to get one of these\n"+
  "  objects.  Once you have one, look at it (look at follow) for special\n"+
  "  directions.  You will need add all the members of your party before\n"+
  "  continuing onward.\n\n"+
  "  To get a follow object type 'getfollow'.\n");
  return;
}

short(){
  return "A small wooden box";
}

get() {
  return 1;
}

drop() {
  return 1;
}

query_weight() {
  return 9999;
}

init() {
  add_action("getfollow","getfollow");
}

getfollow() {
  if(present("ilstkarn_follow", this_player())) {
    write("You already have one.\n");
    return 1;
  }
  write("You get an Ilstkarn follow object from the box.\n");
  say(ME+" gets a follow object from the box.\n");
  move_object(clone_object("players/pavlik/items/ilstkarn/ilstkarn_leader"),
  this_player());
  return 1;
}

