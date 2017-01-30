id(str) { return str == "descript"; }

string description, pretitle, title, al_title;

short () { return "A Descript"; }

long () { return "Action is Descript"; }

drop() { return 1; }

init()  {
  add_action ("descript","descript");
 }
  descript(str) {

    title = 0; pretitle = 0; al_title = 0; description = 0;
   if(!str) { write("Descript who?\n"); return 1; }

  if(!restore_object("players/"+str)) {
    write("That player does not exit.\n"); return 1; }
  write("Descript\n");
   write(pretitle+" "+capitalize(str)+" "+title+" *"+al_title+"*\n");
   write(description+"\n");
  return 1;  }
