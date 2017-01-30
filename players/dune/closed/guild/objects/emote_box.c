#include "../DEFS.h"

status id(string str) { 
  return str == "box" || str == "suggestion box"; 
}

string short() { return "The Emote Suggestion Box"; }

void long() {
  write("Usage: 'suggest <emote>'\n"+
        "Please drop a suggestion in this box if you would like\n"+
        "to see a new guild emote. If you want color, specify\n"+
        "in brackets where each color should start and stop.\n"+
        "Please do try to make the emotes interesting, and unique.\n\n"+
        "Example: 'suggest You hiss, showing your [RED]fangs[OFFRED]'\n");
}

status get()  { return 0; }
status drop() { return 1; }

void init() {
  add_action("suggest","suggest");
  add_action("show_suggest","show_suggest");
}


status suggest(string str) {
  string name;
  if(!str) {
    write("What emote do you suggest?\n");
    return 1; }
  name = capitalize((string)this_player()->query_real_name());
  write_file(EMOTES, "["+name+"] "+str+"\n");
  write("Thank you for your emote.\n");
  return 1; 
}


status show_suggest() {
  if(this_player()->query_level() > 20) tail(EMOTES);
  return 1;
}
