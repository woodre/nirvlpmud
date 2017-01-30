#include "/players/pavlik/guild/mages/macs"
string message;
string owner;

long() {
  if(present("mageobj", this_player()))
    write(capitalize(owner)+"'s wizard mark ...\n");
  else
    write("Some strange markings burned into the ground ...\n");
  write(rancol2(message)+"\n");
  if(present("mageobj", this_player()))
    write("You can erase this mark with the command 'erace'.\n");
}

reset(arg) {
 if(arg)
  return;
  message = "";
}

set_message(str){ message = str; }
set_owner(str){ owner = str; }

short() {
  if(present("mageobj", this_player()))
    return capitalize(owner)+"'s wizard mark";
  else
     return "strange markings burned into the ground";
}

id(str) {
  return str == "wizard_mark" || str == "mark" || 
     str == "markings" || str == "ground";
}

query_value() {
    return 0;
}

get() {
    return 0;
}

init(){
  if(present("mageobj", this_player()))
  add_action("erace","erace");
}

erace(){
  write("You obliterate the wizard mark.\n");
  destruct(this_object());
  return 1;
}
