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
int j,i,b;
  i = 0;
  b = 1;
  write("\nItems in storage:\n");
  for(j=0;j<MAX;j++) {
    if(shelf[j]) 
    {
      write(b+".");
      write("\t"+shelf_short[j]+"\n");
      i = 1; b++; 
    }
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

if(!str) { write("Retrieve 1-3.\n"); return 1; }

if(str != "1" && str != "2" && str != "3")
{
  write("Retrieve 1-3.\n"); return 1;
}

if(str == "1")
{
  targ = clone_object(shelf[0]);  
  shelf[0] = shelf_name[0] = shelf_short[0] = wear[0] = 0; 
  if(wear[0]) targ->add_wear(wear[0]); 
}
if(str == "2")
{
  targ = clone_object(shelf[1]);
  shelf[1] = shelf_name[1] = shelf_short[1] = wear[1] = 0; 
  if(wear[1]) targ->add_wear(wear[1]);
}
if(str == "3")
{
  targ = clone_object(shelf[2]);
  shelf[2] = shelf_name[2] = shelf_short[2] = wear[2] = 0; 
  if(wear[2]) targ->add_wear(wear[2]);
}

if(!targ) 
{
  write("Somehow the object you have tried to retrieve has gone bad.\n"+
   "We apologize for this inconveniance.\n");
  save_object(LOCKERS+TP->query_real_name());
  return 1;
}
  move_object(targ,TP);
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
  
