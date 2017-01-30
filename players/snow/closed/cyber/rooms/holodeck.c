#define TP   this_player()
#define TR   tell_room
#define TE   tell_object
#define EP   environment(TP)
#define SAVR "players/snow/closed/cyber/holodeck/"
#define SAVE "/players/snow/closed/cyber/holodeck/"
#define RN   this_player()->query_real_name()
#define OBJ  "players/snow/closed/cyber/holodeck/holodeck_object.c"

inherit "room/room";

static int locked;

init() {
  add_action("get_commands_from_say","say");
  ::init();
  if(locked) {
    write("Holodeck is locked and sealed.\n");
    move_object(TP, "/players/snow/closed/cyber/rooms/hallway1.c");
    return 1; }
  }

string holosetting, item1, item2, item3, item4,
       writing;

reset(arg) {

 locked = 0;
 if(item1) clone_holo_object("object 1");
 if(item2) clone_holo_object("object 2");
 if(item3) clone_holo_object("object 3");
 if(item4) clone_holo_object("object 4");

 if(!arg){
 set_light(1);
 short_desc="HOLODECK";
 if(!holosetting)
   long_desc=
   "     You are in a square black void checkered with\n"+
   "bright yellow gridlines.  You are in the CyberNinja Holodeck.\n";
 else long_desc= holosetting;

items=({
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/hallway1.c","out",
      });
  }   }

save_me() {
  string file;
  file = SAVR+RN;
  if(!save_object(file)) {
    TR(EP,"Computer: Unable to save program.\n");
    return 0;}
  TR(EP,"Computer: Program saved.\n");
  return 1;}

restore_me(string name) {
  string file;
  file = SAVR+name;
  if(!restore_object(file)) {
    TR(EP,"Computer: Unable to execute program.\n");
    return 0;}
  TR(EP,"Computer: Program executed.\n");
  return 1;}

get_commands_from_say(string str) {
  string verbose;
  if(!str) { }
  else if(sscanf(str, "computer, %s", verbose)) commands(verbose);
  if(verbose == "allow me to change environment") return 1;
}

commands(string str) {
  string pname, type, name, short, item, file;
  int num, i;
  object * inv;
  object ob;
  if(str == "show program") {
    TR(EP,"The Computer chimes electronically in response.\n");
    TE(TP,"A small visual display appears in mid-air.\n"+
          "__________________________________________\n"+
          holosetting);
    TE(TP, pad("\nObject 1: "+item1, 25));
    TE(TP, pad("\nObject 2: "+item2, 25));
    TE(TP, pad("\nObject 3: "+item3, 25));
    TE(TP, pad("\nObject 4: "+item4, 25));
    TE(TP,"\n__________________________________________\n");
    return 1; }
  if(sscanf(str, "make %s %d", type, num)) {
    if(num <= 0 || num >= 5) {
      TR(EP,"Computer: Enumeration out of range, should be 1 to 4.\n");
      return 1; }
    clone_holo_object(type+" "+num);
    return 1; }
  if(sscanf(str, "remove %s %d", type, num)) {
    if(num <= 0 || num >= 5) {
      TR(EP,"Computer: Enumeration out of range, should be 1 to 4.\n");
      return 1; }
    if(type == "object") {
      item = get_item(num);
      if(!item) {
        TR(EP,"Computer: Object program not loaded.\n");
        return 1; }
      sscanf(item, "%s %s", name, short);
      if(present(name, this_object())) {
        destruct(present(name, this_object()));
        TR(EP,"The Computer chimes electronically in response.\n");
        return 1; }
      return 1; }
    else {
      TR(EP,"Computer: Invalid type.  Should be object.\n");
      return 1; }
    return 1; }
  if(sscanf(str, "set object %d name %s short %s",
            num, name, short)) {
    if(num == 1) item1 = name+" "+short;
    if(num == 2) item2 = name+" "+short;
    if(num == 3) item3 = name+" "+short;
    if(num == 4) item4 = name+" "+short;
    TR(EP,"The Computer chimes electronically in response.\n");
    return 1; }
  if(sscanf(str, "clear %s %d", type, num)) {
    if(num <= 0 || num >= 5) {
      TR(EP,"Computer: Enumeration out of range, should be 1 to 4.\n");
      return 1; }
    if(type == "item") {
      if(num == 1) item1 = "";
      if(num == 2) item2 = "";
      if(num == 3) item3 = "";
      if(num == 4) item4 = "";
      TR(EP,"The Computer chimes electronically in response.\n");
      return 1; }
    else {
      TR(EP,"Computer: Invalid type.  Should be object.\n");
      return 1; }
    return 1; }
  if(str == "terminate program") {
    item1 = 0; item2 = 0; item3 = 0; item4 = 0; holosetting = 0;
    locked = 0;
    inv = all_inventory(this_object());
    for(i = 0; i < sizeof(inv); i++) {
      if(inv[i]) {
        if(inv[i]->is_player() || inv[i]->is_pet()) {}
        else destruct(inv[i]);
        }
      }
    reset();
    TR(EP,"The Computer chimes electronically in response.\n");
    return 1; }
  if(sscanf(str, "execute program %s", pname)) {
    pname = lower_case(pname);
    file = SAVE+pname+".o";
    if(file_size(file) >= 0) {
      restore_me(pname);
      reset();
      TR(EP,"The Computer chimes electronically in response.\n");
      return 1; }
    else {
      TR(EP,"Computer: No such program.\n");
      return 1; }
    return 1; }
  if(str == "save program") {
    save_me();
    TR(EP,"The Computer chimes electronically in response.\n");
    return 1; }
  if(str == "allow me to change environment") {
    TR(EP,"The Computer chimes electronically in response.\n");
    holodeck_enviro();
    return 1; }
  if(str == "lock doors" || str == "lock door") {
    locked = 1;
    check_for_vacancy(this_player());
    TR(EP, "Computer: Doors locked.\n");
    return 1; }
  if(str == "unlock doors" || str == "unlock door") {
    locked = 0;
    TR(EP, "Computer: Doors unlocked.\n");
    return 1; }
  return 1;
}

holodeck_enviro() {
  write("Enter Holodeck description.\n");
  write("End with '**', abort with '~q'.\n");
  write("__________________________________________________________\n");
  writing = "";
  input_to("get_description");
  return 1;
}

get_description(string str) {
  if (str == "~q") {
    write("aborted.\n");
    return 1; }
  if (str=="**") {
    write("Ok.\n");
    holosetting = writing;
    return 1; }
  writing = writing + str + "\n";
  input_to("get_description");
}

string get_item(int num) {
  switch(num) {
    case 1: return item1;
    case 2: return item2;
    case 3: return item3;
    case 4: return item4;
    }
  return item1;
}

check_for_vacancy(object ob) {
  if(!present(ob, this_object())) {
    tell_room(this_object(), "The doors unseal and unlock.\n");
    tell_room("/players/snow/closed/cyber/rooms/hallway1.c",
              "The doors to Holodeck unlock and unseal.\n");
    locked = 0;
    return 1; }
  call_out("check_for_vacancy", 5, ob);
}

clone_holo_object(string str) {
    string type, name, short, item;
    int num;
    object ob;
    sscanf(str, "%s %d", type, num);
    if(type == "object") {
      item = get_item(num);
      if(!item) {
        TR(EP,"Computer: Object program not loaded.\n");
        return 1; }
      sscanf(item, "%s %s", name, short);
      ob = clone_object(OBJ);
      ob->set_alias(name);
      ob->set_short(short);
      move_object(ob, this_object());
      TR(EP,"The Computer chimes electronically in response.\n");
      return 1; }
    else {
      TR(EP,"Computer: Invalid type.  Should be object.\n");
      return 1; }
    return 1;
}

realm() { return "NT"; }
feel() { return "no"; }