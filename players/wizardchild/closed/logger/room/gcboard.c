/* bboard.c: main bulletin board */
/* this is 100% on the fly, so don't get on my case */
#define THIS_BOARD "players/wizardchild/closed/logger/board/gc_board"
 
static string new_note;
static string *headers, *notes;
int num_notes;
string header;
string note;
reset(arg) {
  if(arg) return 0;
  num_notes = 0;
  headers = allocate(30);
  notes = allocate(30);
  restore_me();
}
id(str) { return str == "table" || str == "board" || str == "alder table"; }
short() { 
  if(num_notes > 1) return "A long alder table ("+num_notes+" notes)"; 
  else if(num_notes) return "A long alder table ("+num_notes+" note)";
  return "A long alder table (no notes)";
}
long() {
  int i;
  write("This board is ONLY for Guild Commanders.\n");
  write("This table appears perfect for carving on. On the side, there lies a knife.\n");
  write("Commands: read <num>, carve <headline>\n\n");
  for(i = 1; i <= num_notes; i++) 
    write(i+": "+headers[i-1]+"\n");
  return 1;  
}
init() {
  save_me();
  restore_me();
  add_action("read", "read");
  add_action("carve", "carve");
  if(present("logger pack", this_player())->query_grank() > 10) 
    add_action("remove", "remove");
}
remove(str) {
  int which, i;
  if(sscanf(str, "%d", which) != 1 && sscanf(str, "note %d", which) != 1) 
    return 0;
  if(which > num_notes);
  headers[which-1] = 0;
  notes[which-1] = 0;
  for(i = which-1; i < num_notes; i++) {
    headers[i] = headers[i+1];
    notes[i] = notes[i+1];
  }
  num_notes--;
  save_me();
  write("Removed.\n");
  return 1;
}
read(str) {
  int which;
  if(sscanf(str, "%d", which) != 1 && sscanf(str, "note %d", which) != 1)
    return 0;
  if(which > num_notes) {
    write("Not that many notes carved.\n");
    return 1;
  }
  write("Note is titled: "+headers[which-1]+"\n");
  write(notes[which-1]+"\n\nDone.\n");
  return 1;
}
carve(str) {
  string tmp;
  if(!str) {
    write("You must choose a header for this note.\n");
    return 1;
  }
  if(strlen(str) > 40) {
    write("Header too long, we are short on table space here.\n");
    return 1;
  }
  tmp = extract(ctime(time()),0,9);
  headers[num_notes] = str+" <"+this_player()->query_real_name()+", "+tmp+">";
  new_note = "";
  input_to("take_msg");
  write("Enter message text. On a blank line, '**' will save, '~q' will abort.\n");
  write("[>");
  return 1;
}
take_msg(str) {
  if(str == "**") {
    notes[num_notes] = new_note;
    new_note = 0;
    num_notes++;
    save_me();
    write("Ok.\n");
    return ;
  } else if(str == "~q") {     
    write("You shave off the half-carved piece of table.\n");
    new_note = 0;
    headers[num_notes] = 0;
    return ;
  } else {
    new_note = new_note+str+"\n";
    write("[>");
    input_to("take_msg");
  }
}
save_me() {
  header = implode(headers, "\n**\n");
  note = implode(notes, "\n**\n");
  save_object(THIS_BOARD);
  return 1;
}
restore_me() {
  restore_object(THIS_BOARD);
  if(!header) return 1;
  headers = explode(header,"\n**\n");
  notes = explode(note,"\n**\n");
  return 1;
}
