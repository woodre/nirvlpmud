
object who;
string player;

id(str) {
    return str == "butt" || str == "ND" || str == "soul";
}
init(){
     add_action("display","display");
}

short() { return "A really nice butt"; }
long(str) {
     write("A magnificent specimen if you do say so.\n");
     write("\nType 'display.'\n");
}

query_auto_load() {
   return "players/bastion/closed/butt:";
}

drop(str) {
  return 1;
}

get() { return 1; }

display() {
     write("\nYou display your fine wares.\n");
     tell_room(environment(environment(this_object())),
       this_player()->query_name()+" shakes "+this_player()->query_possessive()+
       " booty in a most delicious fashion.\n");
     return 1;
}
