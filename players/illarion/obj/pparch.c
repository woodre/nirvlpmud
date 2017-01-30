/* write and save several lines of text in the lockers */
inherit "obj/treasure";
#include "/players/illarion/dfns.h"
string *text;

reset(arg) {
  if(arg) return;

  if(!text) text=({});
  set_id("parchment");
  set_short("A small sheet of parchment");
  set_long("A seemingly ordinary piece of reading parchment, but\n"+
           "a slight crackle of magic seethes inside it.\n");
  set_value(0);
  set_weight(0);
}
init() {
  ::init();
  add_action("cmd_inscribe","inscribe");
  add_action("cmd_scratch","scratch");
  add_action("cmd_read","read");
}
cmd_inscribe(string str) {
  if(!str) FAIL("Inscribe what?\n");
  write("You add:\n"+str+"\nto the parchment.\n");
  say(TPN+" writes on a piece of parchment.\n");
  text+=({str});
  return 1;
}
cmd_read(string str) {
  int x,size;
  if(!str || !id(str) || this_object()!=present(str,TP)) FAIL("Read what?\n");
  if(!text || sizeof(text) == 0) {
    write("The parchment is blank.\n");
    return 1;
  }
  size=sizeof(text);
  write("The parchment reads:\n");
  for(x=0;x<size;x++)
    write(text[x]+"\n");
  say(TPN+" reads from a parchment.\n");
  return 1;
}
long() {
  ::long();
  if(sizeof(text)) write("There is something written on it.\n");
  write("You may inscribe some text on it, or scratch out the last line.\n");
}
cmd_scratch(string str) {
  if(!str) FAIL("Scratch what?\n");
  if(str != "out line" && str != "out last line") FAIL("Scratch out what?\n");
  if(!sizeof(text)) {
    write("It is already entirely blank.\n");
    return 1;
  }
  write("You scratch out the last line on the parchment, and are\n"+
        "astonished to see it fade off the parchment entirely.\n");
  say(TPN+" scratches at a piece of parchment.\n");
  text-=({text[sizeof(text)-1]});
  return 1;
}
locker_arg() {
  if(sizeof(text))
    return implode(text,"##");
  else
    return "empty";
}
locker_init(string str) {
  if(str=="empty")
    text=({});
  else
    text=explode(str,"##");
}
