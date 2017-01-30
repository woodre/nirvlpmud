#define ROOMDIR "/players/vertebraker/realms/gta/room/"
#define OBJDIR "/players/vertebraker/realms/gta/std/room"
#define ROOM "/players/vertebraker/realms/gta/std/room"
#define FILE "/"+file_name(this_object())+".c"

string hood;
string *exits;
string *obs;

string short() {
  return "San Texteles" + (hood ? " ("+hood+")": "");
}

void reset(status arg){
  int i;

  if(arg) return;

  if(!obs) obs=({});

  exits=({});

  i = sizeof(obs);
  while(i--) move_object(clone_object(obs[i]), this_object());
}

void set_exits(string *e){
  exits=e;
}

string * query_exits() {
  return exits;
}

void set_hood(string h){
  hood=h;
}

string query_hood(){
  return hood;
}


void long(string str){
  return write(short()+".\n");
}

void set_obs(string *o) {
  obs=o;
}

string * query_obs() {
  return obs;
}

void save_me(){
    int x, y;
  rm(FILE);
  write_file(FILE, "inherit \""+ROOM+"\";\n\n");
  write_file(FILE,
 "reset(arg){\n");
  write_file(FILE,
 "set_hood(\""+hood+"\");\n");
  y = sizeof(obs);
  if(y > 0)
  {
    write_file(FILE, "set_obs(({\n");
    for(x=0;x<y;x++){
      write_file(FILE, "\""+OBJDIR+obs[x]+"\",\n");
  }
  write_file(FILE, "}));\n");
  }
  y = sizeof(exits);
  if(y > 0)
  {
  write_file(FILE,"set_exits(({\n");
  for(x=0;x<y;x++) {
    write_file(FILE,"\""+ROOMDIR+exits[x]+"\",\n");
  }
  write_file(FILE, "}));\n");
  }
  write_file(FILE, "}\n");
  }
