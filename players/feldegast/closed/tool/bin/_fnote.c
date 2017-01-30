string note_file;
notes(str) {
  if(!str) { str="notes.txt"; }
  note_file=str;
  write("New note file is /players/feldegast/log/"+note_file+".\n");
  return 1;
}
int do_cmd(string str) {
  if(!str) {
  write("You need to note something.\n");
  return 1;
  }
  if(!note_file) note_file="notes.txt";
  write("You note: "+str+"\n");
  write_file("/players/feldegast/log/"+note_file,str+"\n");
  return 1;
}
