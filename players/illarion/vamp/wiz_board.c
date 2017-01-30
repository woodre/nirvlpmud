#include "/players/eurale/defs.h"
string board_message_file, messages, new_hd, new_body;
int num_messages;
object who;

id(str) { return
  str == "bulletin board" ||
  str == "board" ||
  str == "bulletinboard"; }

long() { write(
  "This is the "+HIR+"Important Bulletin Board"+NORM+".\n"+
  "Only the guild wizards can write or remove notes, but everyone\n"+
  "should read them.\n");
  if(this_player()->query_level() > 19)
  write(
  "  To write a note:   'note <topic>'.\n"+
  "  To read a note:    'read #'\n"+
  "  To remove a note:  'remove #'\n"+
  "  To finish a note:  '**'\n"+
  "\n");

if(num_messages == 0) { write("It is empty.\n"); return 1; }
write("The bulletin board contains ("+num_messages+")");
if(num_messages == 1) write(" note:\n\n");
  else write(" notes:\n\n");
say(capitalize(TPN)+" studies the bulletin board.\n");
headers();
}

short() { return HIR+"Important Bulletin Board"+NORM; }

get() {
  write("It is secured to the ground.\n");
  return; }


init() {
  add_action("new",    "note");
  add_action("read",   "read");
  add_action("remove", "remove");
}

reset(arg) {
  if (arg) return;

board_message_file = "players/eurale/VAMPIRES/OBJ/wiz_board_notes";
restore_object(board_message_file);
board_message_file = "players/eurale/VAMPIRES/OBJ/wiz_board_notes";
}

headers() {
  string hd, body, rest;
  int i, tmp;

  i = 1;
  rest = messages;
  while(rest != 0 && rest != "") {
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3) {
      write("Corrupt.\n");
      return; }
    write(i+":\t"+hd+"\n");
    i += 1;
  }
}

new(hd) {
  if (!hd) return;
  if (who && environment(who) == environment(this_object())) {
    write(who->query_name()+" is busy writing.\n");
    return 1; }

  if (num_messages == 25) {
    write("You have to remove an old message first.\n");
    return 1; }

  if (strlen(hd) > 50) {
    write("Too long header to fit the paper.\n");
    return 1; }

  if((TPRN!= "vital") && (TPRN != "brittany") && (TPRN != "khrell")) {
    write("Only the guild wizard can write on this board.\n");
    return 1; }

  new_hd = hd;
  input_to("get_body");
  write("Give message, and terminate with '**'.\n");
  write("]");
  new_body = "";
  return 1;
}

get_body(str) {
  if (str == "**") {
/*
    new_hd = new_hd+"("+this_player()->query_real_name()+", "+
             extract(ctime(time()), 4, 9)+", "+TPL+")";
*/
    new_hd = new_hd + " [" + TPRN + "] (" + extract(ctime(),4,9) + ", " +
             extract(ctime(),20,23) + ")";
/*
  new_hd = new_hd+"("+this_player()->query_real_name()+", "+
          extract(ctime(time()), 4, 9)+")";
*/
    messages = messages+new_hd+":\n**\n"+new_body+"\n**\n";
    num_messages+= 1;
    new_body = 0;
    new_hd = 0;
    save_object(board_message_file);
    write("Ok.\n");
    who = 0;
    return; }

  new_body = new_body+str+"\n";
  write("]");
  input_to("get_body");
}

read(str) {
  string hd, body, rest;
  int i, tmp;

  if(str == 0 || (sscanf(str, "%d", i) != 1 &&
    sscanf(str, "note %d", i) != 1)) return;

  if (i > num_messages) {
    write("Not that number of messages.\n");
    return 1; }

  rest = messages;
  while(rest != 0 && rest != "") {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3) {
      write("Corrupt.\n");
      return; }

    if (i == 0) {
      say(capitalize(TPN)+" reads a note titled '"+hd+"'.\n");
      write("The note is titled '"+hd+"':\n\n");
      write(body);
      return 1; }
  }
  write("Hm. This should not happen.\n");
}

remove(str) {
  string hd, body, rest;
  int i, tmp;

  if(str == 0 || (sscanf(str, "%d", i) != 1 &&
    sscanf(str, "note %d", i) != 1)) return;

    /*  limit who can remove notes  */
  if(TPRN != "vital" && TPRN != "khrell" && TPRN != "fred" && TPRN != "illarion") {
    write("Only the guild wizard can remove notes from this board.\n");
    return 1; }

  if (i > num_messages) {
    write("Not that number of messages.\n");
    return 1; }

  rest = messages;
  messages = "";
  while(rest != 0 && rest != "") {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3) {
      write("Corrupt.\n");
      return; }

    if (i == 0) {
      say(capitalize(TPN)+" removes a note titled '"+hd+"'.\n");
      write("Ok.\n");
      messages = messages+rest;
      num_messages -= 1;
      save_object(board_message_file);
      return 1; }

    messages = messages+hd+":\n**\n"+body+"\n**\n";
  }
  write("Hm. This should not happen.\n");
}
