init() {
add_action("do1","say");
add_action("do2","tell");
}
get() { return 1; }

do1(str) {
say("Deathmonger says: "+str+"\n");
write("Deathmonger says: "+str+"\n");
}

do2(str) {
string who, what;
object target;
if (sscanf(str,"%s %s",who, what) != 2) return 0;
tell_object(find_player(who), "Deathmonger tells you: "+what+"\n");
write("Deathmonger tells "+who+": "+what+"\n");
return 1;
}
