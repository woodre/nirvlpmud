/*
 * std_room.c is copied and modified upon hotel generation.
 * Change the std_room.c file in order to change all room files.
 */


#include "../def.h"
inherit "room/room";

string owner;
string roomdesc;
string* storage;
status unlocked;
int floor;
string writing;

init() {
if(TPRN == owner || TPRN == MANAGER || (unlocked)) { }
  else {
    write("The door is locked.\n");
    move_object(this_player(), ROOMPATH+"floor"+floor);
    return 1; }
  add_action("out","out");
  add_action("room_help","services");
  add_action("chest","chest");  
  add_action("store","store");  
  add_action("retrieve","retrieve");  
  add_action("doorlock","doorlock");  
  add_action("redecorate","redecorate");
  ::init();
}


reset(arg) {
  if(!arg) {
    set_light(1);

    if(owner) short_desc= capitalize(owner)+"'s suite";
    else short_desc="Vacant suite";

    if(owner && roomdesc) long_desc = roomdesc;
    else long_desc=
"     Welcome to your personal suite. For a tutorial on\n"+
HOTELNAME+" room services, type 'services'. If you run into\n"+
"any problems, please contact Manager "+capitalize(MANAGER)+".\n";
     }

    dest_dir=({ROOMPATH+"floor"+floor,"out"});
  }


out() {
  string roomdest;
  tell_object(this_player(), 
    "You lock the door and leave your room.\n");
  unlocked = 0;
  roomdest = ROOMPATH+"floor"+floor;
  roomdest = extract(roomdest, 1, strlen(roomdest));
  call_other(this_player(), "move_player", "out#"+roomdest);
  return 1; 
}

int query_floor() { return floor; }

room_help() {
  write(HOTELNAME+" provides the following services...\n"+
        "---------------------------------------------\n"+
        "out           leave room                     \n"+
        "chest         list contents inside room chest\n"+
        "store         store an object in the chest   \n"+
        "retrieve      retrieve an object from chest  \n"+
        "doorlock      lock/unlock room door          \n"+
        "redecorate    change room description        \n"+
        "\n");
  return 1; 
}


doorlock(string onoff) {
  /* lock or unlock room */
  if(!onoff) {
    write("Usage: doorlock [on/off]\n");
    return 1; }
  if(onoff == "on") {
    write("You lock the door.\n");
    unlocked = 0;
    return 1; }
  if(onoff == "off") {
    write("You unlock the door.\n");
    unlocked = 1;
    return 1; }
  return 0;
}


save_me() {
  (PATH+"room_safe.c")->store(owner, storage, owner, roomdesc);
  return 1;
}


restore_me(string guestname, int floornum) {
  /* set up room by restoring variables */
  int x, size, i;
  string* tmp_storage;
  floor = floornum;
  x = (PATH+"room_safe.c")->restore_safe(guestname);
  storage  = (PATH+"room_safe.c")->get_storage();
  owner    = (PATH+"room_safe.c")->get_owner();
  roomdesc = (PATH+"room_safe.c")->get_roomdesc();
  /* tmp var makes sure indexing is correct
   * same situation as setup func in office.c
   */
  tmp_storage = allocate(MAXSAVE); /* correct-sized array */
  size = sizeof(storage);
  if(size > MAXSAVE) size = MAXSAVE;
  for(i = 0; i < size; i++) tmp_storage[i] = storage[i];
  storage = allocate(MAXSAVE); /* clear and allocate good array */
  for(i = 0; i < size; i++) storage[i] = tmp_storage[i];
  if(!x) zero_all(floornum);
  reset();
  return x;
}


zero_all(int floornum) {
  /* make sure all variables are set properly when 
   * guests change rooms */
  int i;
  owner = 0;
  roomdesc = 0;
  unlocked = 0;
  floor = floornum;
  storage = allocate(MAXSAVE);
}


prepare(string guestname) {
  /* prepare room for new guest */
  owner = guestname;
  save_me();
  reset();
  }


chest(string flag) {
  /* each room has a chest which a player can
   * save or retrieve items from.
   * This func allows viewing of items in chest */
  status output;
  int i, items;
  items = 0;
  /* output var makes re-use of this function code possible
   * not only can players use this func, but other funcs
   * in this room code also can use it by preventing output */
  output = 1;
  if((flag) && (flag == "item_query")) output = 0;
  if(output) write("Your chest holds:\n"+
                   "-----------------\n");
  for(i = 0; i < MAXSAVE; i++) {
    if(storage[i]) {
      if(output) write((i+1)+")  "+(storage[i]->short())+"\n");
      items++; }
    }
  if((!items) && (output)) write("nothing\n");
  if(output) write("-----------------\n"+
    "You are currently storing "+items+" out of "+MAXSAVE+" items.\n");
  return (items+1);
}


store(string item) {
  /* command to place an item in the chest
   * item will be saved until guest is checked out or
   * item is retrieved */
  string path, fname, junk;
  object ob;
  int stored, i;
  stored = (chest("item_query") - 1);/* get #items stored in chest */
  if(stored >= MAXSAVE) {
    write("You cannot store more than "+MAXSAVE+" items.\n");
    return 1; }
  if(!item) {
    write("What do you wish to store?\n");
    return 1; }
  if(ob = present(item, this_player())) { }
  else {
    write("You do not have the "+item+".\n");
    return 1; }

  /* get file name of object so we can clone it later */
  path = file_name(ob);
  sscanf(path, "%s#%s", fname, junk);
  fname = "/"+fname;
  for(i = 0; i < MAXSAVE; i++) {
    if(!storage[i]) {
      storage[i] = fname;
      break; }
    }
  write("You store the "+item+" in the chest.\n");
  destruct(ob);
  save_me();
  return 1;
}


retrieve(string numstr) {
  /* command to retrieve an item from the chest.
   * items are given a position # within the chest,
   * so guest only has to specify position # when retrieving */
  int i, num;
  string obfile;
  if(!numstr) {
    write("What item number do you wish to retrieve?\n");
    return 1; }
  sscanf(numstr, "%d", num);
  if((num < 1) || (num > MAXSAVE)) {
    write("You must specify a number between 1 and "+MAXSAVE+".\n");
    return 1; }
  num -= 1;
  obfile = storage[num]+".c";
  /* retrieve works by cloning the stored file name */
  move_object(clone_object(obfile), this_player());
  storage[num] = 0;
  write("You retrieve item "+(num+1)+" from the chest.\n");
  save_me();
  return 1;
}



redecorate() {
  /* change room description, which is saved */
  say(capitalize(TPRN)+" redecorates...\n");
  write("You redecorate your room...\n");
  room_enviro();
  reset();
  return 1;
}


room_enviro() {
  write("Describe new room description.\n");
  write("End with '**', abort with '~q'.\n");
  write("__________________________________________________________\n");
  writing = "";
  input_to("get_description");
}


get_description(string str) {
  if (str == "~q") {
    write("aborted.\n");
    return 1; }
  if (str=="**") {
    write("Ok.\n");
    roomdesc = writing;
    return 1; }
  writing = writing + str + "\n";
  input_to("get_description");
}
