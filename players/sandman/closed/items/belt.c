
object who;
string player;

id(str) {
    return str == "belt" || str == "ND" || str == "soul";
}
init(){
     add_action("have_sex","sex");
}

short() { return "A chastity belt"; }
long(str) {
     write("A device to assure your fidelity.\n");
}
set_who(ob) { who=ob; }
set_player(str) {
     player=str;
     if(!str) player="log";
}

query_auto_load() {
   return "players/bastion/closed/belt:";
}

drop(str) {
  return 1;
}

get() { return 1; }

have_sex() {
     string name;
     object where;
     name=this_player()->query_name();
     where=environment(this_player());
     write("The chastity belt about your slim waist, "+
           "from suitors keep you\nsuccumbing to haste.\n");
     tell_room(where, name+" looks very frustrated.\n");
     return 1;
}
