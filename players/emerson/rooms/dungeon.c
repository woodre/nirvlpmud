short() {
      return "Emerson's dungeon";
}
long () {
     write ("You are in a dark dungeon.\n");
write("There are no exits.\n");
}
reset (arg) {
    if (arg)
    return;
  set_light(1);
}
init(){
  add_action ("quit","quit");
}
quit(){
if(this_player()->query_level() < 21) {
write("You can't do that in here.\n");
return 1;
}
}
