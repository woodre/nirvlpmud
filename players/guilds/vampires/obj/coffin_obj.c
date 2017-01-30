#define EO environment(this_object())
#define TP this_player()
#define LOCKERS "players/eurale/VAMPIRES/OBJ/lockers/"
#define MAX 3
#define WEP_MAX 18
string shelf;
string shelf_name;
string shelf_short;
int wear;

id(str) { return str == "coffin_ob"; }

reset(arg) {
  if(arg) return;
  shelf = allocate(MAX);
  shelf_name = allocate(MAX);
  shelf_short = allocate(MAX);
  wear = allocate(MAX);
}

init() {
  if(EO == TP) {
    if(!restore_object(LOCKERS+TP->query_real_name())) 
       save_object(LOCKERS+TP->query_real_name());
    add_action("Store","store");
    add_action("Retrieve","retrieve");
    add_action("Clear","clear");
    add_action("List","list");
  }
}

List() {
int j,i;
  i = 0;
  write("\nItems in storage:\n");
  for(j=0;j<MAX;j++) {
    if(shelf[j]) { write("\t"+shelf_short[j]+"\n");
                     i = 1; }
  }
  if(!i) write("\tThere is nothing in storage.\n");
return 1; }

Store(str) {
int i,j;
object targ;
  i = 0; j = -1;
    while(i<MAX) {
      if(!shelf[i]) { j = i; i = MAX; }
      else i += 1;
   }
   if(j == -1) { write("No more storage space available.\n"); return 1; }
   if(!str) { write("Store what?\n"); return 1; }
   if(!(targ = present(str,TP))) {
     write("You do not have that item.\n");
   return 1; }
   if(targ->query_save_flag() || !targ->query_weight() || !targ->short() ||
      targ->drop() || !targ->get() || targ->query_auto_load()) { 
      write("That item cannot be stored.\n");
    return 1; }
    command("drop "+str,TP);
    TP->reset(1);
     sscanf(file_name(targ),"%s#%s",shelf[j]);
     shelf_short[j] = targ->short();
     shelf_name[j] = str;
     wear[j] = targ->query_wear();
     save_object(LOCKERS+TP->query_real_name());
     destruct(targ);
     write(str+" has been stored.\n");
     return 1; 
}

Retrieve(str) {
int i,j;
int mo;
object targ;
mo = 0;
if(!str) { write("Retrieve what?\n"); return 1; }
  i = 0;
  while(i < 3) {
    if(shelf_name[i] == str) { j=i; i = 3; mo = 1; }
    else i += 1;
  }
  if(!mo) {
  write("That is not something you can retrieve.\n");
  return 1; }
  targ = clone_object(shelf[j]);
  if(!targ) {
  write("Somehow the object you have tried to retrieve has gone bad.\n"+
   "We apologize for this inconveniance.\n");
  shelf[j] = shelf_name[j] = shelf_short[j] = wear[j] = 0;
  save_object(LOCKERS+TP->query_real_name());
  return 1;
}
  if(!TP->add_weight(targ->query_weight())) {
    write("You cannot carry anymore.\n"); 
    destruct(targ);
  return 1; }
  move_object(targ,TP);
  if(wear[j]) targ->add_wear(wear[j]);
  shelf[j] = shelf_name[j] = shelf_short[j] = wear[j] = 0;
  save_object(LOCKERS+TP->query_real_name());
  write("You retrieve "+targ->short()+"\n");
return 1; }

Clear() {
  write("This will clear out all items saved in your storage.\n");
  write("Ok <y/n>? ");
  input_to("clear_ok");
return 1; }

clear_ok(str) {
  if(!str) {
    write("Ok <y/n>? ");
   input_to("clear_ok");
  return 1; }
  if(str != "y" && str != "n") {
    write("Ok <y/n>? ");
  input_to("clear_ok");
  return 1; }
  if(str == "n") { write("aborting...\nAction aborted\n"); return 1; }
  write("Clearing lockers...\n");
  shelf = allocate(MAX);
  shelf_name = allocate(MAX);
  shelf_short = allocate(MAX);
  wear = allocate(MAX);
  save_object(LOCKERS+TP->query_real_name());
  write("Cleared.\n");
return 1; }
  
