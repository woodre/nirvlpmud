/*******************************************************/
/* croom.c: congo room driver                          */
/* please refer to the readme(s) in the root           */
/* directory for instructions in case of room failure  */
/*******************************************************/
/* Revision history:                                   */
/* 7/16/95           Creation                          */                                                         
/*                    Usage of daemon for common junk  */
/*******************************************************/
#define ROOT "/players/wizardchild/congo/"
#define MASTER "/players/wizardchild/congo/rmaster.c"
#define VER "0.1"
string short_desc,long_desc;
string *exits;         /* exits (i.e. n,s,w,e,etc)    */  
object *erooms;        /* rooms (driver assigned)     */
string xcmd_fname;     /* for extra commands          */
status realm;          /* for the realm() function    */
string *actions;       /* all actions                 */
status first;          /* on first load get exits     */
/* without the first variable we would crash the mud in an infinite loop */
int num;               /* room number                 */
status no_objects;     /* can this room have xtra obs */
 
set_short(str) { short_desc = str; }
set_long(str)  { long_desc  = str; }
set_erooms(ar) { erooms     =  ar; }
set_exits(arr) { exits      = arr; }
set_xcmdf(str) { xcmd_fname = str; }
set_realm(x)   { realm      =   x; }
set_actions(a) { actions    =   a; }
set_num(x)     { num        =   x; }
set_no_objects() { no_objects = 1; }
 
query_num()     { return num;            }
query_version() { return "Version "+VER; }
query_no_objects() { return no_objects;  }
 
reset(arg) {
  string foo,foo2;
  if(arg) return ;
  set_light(1);
  /* set defaults to handle room distributor failure */
  short_desc = "Someplace in the Congo";
  long_desc  = "eek! This room seems to be unfinished! Please try and leave\n"
              +"or teleport out.\n";
  exits = allocate(10); /* u,d,w,e,n,s,ne,nw,se,sw */
  erooms = allocate(10); /* one per direction */
  actions = allocate(20); /* one per direction plus 10 for extra */
  realm = 0;
}
/* this is called by the room creator when it is done */
delayed_reset() { 
  string tmp,ob;
  int i,x,so;
  if(xcmd_fname) {
    xcmd_fname = ROOT+"xcmd/"+xcmd_fname;
    tmp = xcmd_fname->query_actions();
    if(so = sizeof(tmp)) {
      for(i = 0; i < so; i++) 
        actions[i] = tmp[i];
    } 
    ob = xcmd_fname->query_objects();
    if(so = sizeof(ob)) {
      for(i = 0; i < so; i++) {
        if(file_size(ob[i]) > 0)
          move_object(clone_object(ob[i]), this_object());
      }
    }
  }
}
init() {
  int i,so;
  so = sizeof(actions);
  if(!first) {
    MASTER->init_setup(this_object());
    first=1;
  }
  for(i = 0; i < so; i++) {
    if(actions[i] != 0 && actions[i] != "")
      add_action("remote_handler", actions[i]);
  }
  so = sizeof(exits);
  for(i = 0; i < so; i++) {
    if(exits[i] != 0 && exits[i] != "")
      add_action("move_me", exits[i]);
  }
  if(this_player()->query_level() > 20) {
    write(" - Type \"reset_room\" to destruct this room ("+
          MASTER->cushion(num)+") -\n");
    add_action("wizard_reset", "reset_room");
  }
}
short() { return short_desc;     }
long()  { 
  int i, so,x;
  string *arr;
  arr = ({"o","one","two","three","four","five","six","seven","eight","nine","ten"});
  if(!set_light(0)) {
    write("It is dark.\n");
    return 1;
  }
  for(i=0,x=sizeof(exits);i<x;i++) {
    if(exits[i] && exits[i] != 0 && exits[i] != "")
      so++;
  }
  write(long_desc);      
  if(!so) 
    write("    There are no obvious exits.\n");
  else {
    if(so == 1)
      write("    There is one obvious exit:");
    else if(so > 10)
      write("    There are many obvious exits:");
    else
      write("    There are "+arr[so]+" obvious exits:");
    for(i = 0; i < so; i++) {
      if(exits[i] != 0 && exits[i] != "") {
        write(" "+exits[i]);
        if(i == so-2)
          write(" and");
        else if(i != so-1)
          write(",");
      }
    }
    write(".\n");
  }
}
realm() { return (realm?"NT":0); }
/* stupid proof even, to compensate for no updating */
wizard_reset() {
  object ob,nob; string foo,foo2;
  tell_room(this_object(), "Room reset called. Removing all occupants...\n");
  ob = first_inventory(this_object());
  while(ob) {
    nob = next_inventory(ob);
    if(ob->is_player())
      ob->move_player("church#room/church");
    else if(creator(ob) == "wizardchild") {
      if(sscanf(file_name(ob),"%s#%s",foo,foo2) != 2)
        foo = file_name(ob);
      destruct(find_object(foo));
      if(ob) destruct(ob);
    }
    ob = nob;
  }
  write("Room cleared. Destructing.\n");
  MASTER->remove_room(num);
  destruct(this_object());
  return 1;
}
remote_handler(str) {
  return xcmd_fname->handler(query_verb(), str);
}
move_me() {
  string dir;
  int i, so;
  dir = query_verb();
  so = sizeof(exits);
  for(i = 0; i < so; i++) {
    if(exits[i] == dir) {
      move_player(this_player(), dir, erooms[i]);
      break;
    }
  }
  if(i == so) 
    write("Something has gone wrong...Try another direction...\n");
  return 1;
}
move_player(who, dir, where) {
  who->move_player(dir+"#"+file_name(where));
}
