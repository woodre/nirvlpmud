string contents;
string header;
id(str) { return str == "notepad" || str == "pad"; }
short() { return "A notepad"; }
long() { 
  write("This is plain paper notepad that you can write things\n"+
	"down on. Here are the following commands:\n"+
	"text <str>    Record a line of text into your note.\n"+
	"read note     Displays the contents of your current note.\n"+
	"tear note     Saves your message and clears the notepad for\n"+
	"              new text entry.\n"+
	"header <str>  Title your current note.\n");
}

get() { return 1; }
query_value() { return 15; }

init() {
  add_action("text_entry","text");
  add_action("header_entry","header");
  add_action("display_current","read");
  add_action("save_message","tear");
}

text_entry(str) {
  if(!str) return 0;
  if(!contents) contents = "";
  contents = contents + str + "\n";
  say(capitalize(this_player()->query_name())+" jots something down in a notepad.\n");
  write("Ok.\n");
  return 1;
}

header_entry(str) {
  if(!str) {
    write("Note header cleared.\n");
    header = 0;
    return 1;
  }
  header = str;
  write("Ok.\n");
  return 1;
}

display_current(str) {
  if(!str || str != "note") return 0;
  say(capitalize(this_player()->query_name())+" flips through a notepad.\n");
  if(header) {
    write("Note titled: "+header+"\n");
  }
  write(contents);
  return 1;
}

save_message(str) {
  object ob;
  if(!contents) {
    write("You have no text entered!\n");
    return 1;
  }
  ob=clone_object("/players/mizan/etheriel/items/notepad_txt.c");
  ob->set_text(contents);
  if(header) {
    ob->set_header(header);
  }
  move_object(ob, this_player());
  write("You tear off your current note and save it.\n");
  say(capitalize(this_player()->query_name())+" rips a page out of a notepad.\n");
  contents=0;
  header=0;
  return 1;
}
