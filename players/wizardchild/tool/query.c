short() { return "An inquisitive mind"; }
id(str) { return str == "query" || str == "mind" || str == "inquisitive mind"; }
get() { return 1; }
drop() { return 0; }
long() { write ("Type \"query <who> <what>\".\n"); }
init() { if(this_player()->query_level() < 20) destruct(this_object());
add_action("query","query");
}
query(str){
string who,what;
if(!str || sscanf(str,"%s %s",who,what) != 2) {
write("Incorrect # of args.\n");
return 1;
}
if(!find_player(who)){
write("Player not found.\n");
return 1;
}
write("Querying...\n");
write("Returns: ");
write(call_other(find_player(who), "query_"+what));
write("\n");
return 1;
}
