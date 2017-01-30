string shortname;
int worn;

void
reset(status arg) {
  if(arg)
    return;
  shortname = "A silver ring";
}

int query_weight() { return 0; }
int query_value() { return 0; }

string
short() { 
  if(worn)
    return shortname + " (worn)";
  else
    return shortname;
}

status
get() { 
  if(!this_player()->query_npc()) {
    write("The silver ring slips onto one of your fingers by\n");
    write("some invisible force as you take it.\n");
    worn = 1;
  }
  return 1;
}

void long() {
  write("A beautiful silver ring. It is very skillfully made, with\n");
  write("some writings in it. Although you don't understand the language,\n");
  write("you can decipher the name Angmar.\n");
}

void
init() {
  add_action("read", "read");
  add_action("wear_ring", "wear");
  add_action("quit", "quit");
}

mixed
id(string str) {
  return str == "ring" || 
         str == "silver ring" ||
         str == "trlock1";
}

status
wear_ring(string str) {
  if (id(str)) {
    if (worn)
      write("You are already wearing it.\n");
    else
      write("You must get it first.\n");
    return 1;
  }
}

void
destring() {
  write("The silver ring suddenly disappears in a puff of smoke.\n");
  say("The silver ring suddenly disappears in a puff of smoke.\n");
  destruct(this_object());
}

status
drop(status silent) {
  if (!worn)
    return 0;
  return 1;
}

status
quit() {
  if (!worn)
    return 1;
  write("The silver ring suddenly disappears in a puff of smoke.\n");
  say("The silver ring suddenly disappears in a puff of smoke.\n");
  destruct(this_object());
  this_player()->quit();
  return 1; /* Rumplemintz */
}

status
read(string str) {
  if (!str)
    return 0;
  if (str != "ring" && str != "writing")
    return 0;
  write("The writing on the ring is in a different language.\n");
  write("However, you recognize some of the glyphs to mean 'Angmar'.\n");
  return 1;
}
