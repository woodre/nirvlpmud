id(str) { return str == "box" || str == "suggestion box"; }
short() { return "The Emote Suggestion Box";}
long() {
  write("Usage: 'suggest <emote>'\n"+
        "Please drop a suggestion in this box if you\n"+
        "would like to see guild emotes. If enough\n"+
        "suggestions are given, the Cyberninjas will\n"+
        "have special guild emotes.\n"+
        "Example: 'suggest You smile, exposing your fangs'\n");}
get() { return 0; }
drop() { return 1; }
init() {
  add_action("suggest","suggest");
  add_action("show_suggest","show_suggest");
}

suggest(string str) {
  string name;
  if(!str) {
    write("What emote do you suggest?\n");
    return 1; }
  name = capitalize(this_player()->query_real_name());
  write_file("/players/snow/closed/cyber/emotes",
    "["+name+"] "+str+"\n");
  write("Thank you for your emote.\n");
  return 1; }

show_suggest() {
  if(this_player()->query_level() > 20)
    tail("/players/snow/closed/cyber/emotes");
  return 1;
}
