#define ROOM "/players/vertebraker/realms/gta/std/room"
#define ROOMDIR "/players/vertebraker/realms/gta/rooms/"
#define OBJDIR "/players/vertebraker/realms/gta/obj/"
string *obs;
string hood;
string *hoods;
string *exits;
string h;
#define FILE ROOMDIR+h+".c"

#define PROMPT write(">> ");

void reset(status arg)
{
  if(arg) return;
  hoods=({
"trenchon", "mooktown", "st. verte's", "red light district", "flapburn heights",
"hardwood", "penga point", "dickens beach", "borington", "elephantitian point",
"kools", "queerville", "mount taint", "asshatria", "cockford",
"kiss state campus", "garden grove", "wampum gardens",
"yike creek", "xavier dam",
});

}

void init()
{
  if((string)this_player()->query_real_name() != "vertebraker") return;

  add_action("rmake", "rmake");
}


string translate_h(int i) {
  string hhh;
  if(i < 10) hhh = "0000"+i;
   else if(i < 100) hhh = "000"+i;
  else if(i < 1000) hhh = "00"+i;
  else if(i < 10000) hhh = "0"+i;
  else if(i < 100000) hhh = ""+i;
  else hhh="ERROR";
  return hhh;
}

rmake(str)
{
 
  string *fs;

  int i;
  fs = get_dir(ROOMDIR);

  i = sizeof(fs);

  h="ERROR";
  if(!i) h = "00001";

  else h = translate_h(i + 1);

  if(h=="ERROR") return (write("MAP TOO LARGE.\n"), 1);

  dspMain();
  input_to("mainMenu");
  return 1;

}

string get_obs(){
  int x, y;
  write("\n");
  if(!obs) obs=({});
  x = sizeof(obs);
  for(y=0;y<x;y++)
  {
    write(obs[y]+"\n");
  }
  write("\n");
}
dspMain()

{

  write("\n");
  write("File: "+h+"\n");
  write("Hood: "+hood+"\n");
  write("Obs:"); get_obs();
  write("Exits:\n");
  get_exits();
PROMPT
  return 1;
}

void get_exits(){
  int x, y;
  write("\n");
  if(!exits) exits=({});
  y = sizeof(exits);
  for(x=0;x<y;x++)
  write(exits[x]+"\n");
  write("\n");
}

mainMenu(str)
{
 string inp;
  if(str=="h") {
    hoodMenu();
  }
  else if(str=="e"){
    exitsMenu();
 }
  else if(str=="o"){
    obsMenu();
  }
  else if(str=="x") save_me();
  else if(str=="q") destruct(this_object());
  else {
    PROMPT
    dspMain();
    input_to("mainMenu");
  }

  return 1;
}

hoodMenu(){
  int i;

  i = sizeof(hoods);
  while(i--) {
    write(capitalize(hoods[i])+", ");
  }
  write("\n");
PROMPT
  input_to("hoodshit");
  return 1;
}

hoodshit(arg){
  int i;
  i = sizeof(hoods);
  while(i --)
  if(hoods[i][0..0] == arg) {
    hood = hoods[i];
  }
  PROMPT
  dspMain();
  input_to("mainMenu");
  return 1;
}

obsMenu(){
  int i;
  string *fs;

  fs = get_dir(OBJDIR);
  i = sizeof(fs);
  while(i--){
    write(capitalize(fs[i])+", ");
  }
  write("~d to delete\n");
  write("\n");
  PROMPT
  input_to("obsshit");
  return 1;
}


obsshit(arg){
  int i;
  string *fs;
  if(strlen(arg) > 3 && arg[0..1] == "~d") {
    int j, k;
    k = sizeof(obs);
    if(k) {
      object *newobs; newobs=({});
      for(j=0;j<k;j++) { if(arg[3..3] != obs[j][0..0]) { newobs += ({ obs[j] }); } } obs=newobs;
  }
 }
  fs = get_dir(OBJDIR);
  i = sizeof(fs);
  while(i --)
  if(fs[i][0..0] == arg){
    obs += ({ fs[i] });
  }
  PROMPT
  dspMain();
  input_to("mainMenu");
  return 1;
}

exitsMenu()
{
  int i;
  write("input number to link to.\n");
  write("~d <number> to delete.\n");
  PROMPT
  input_to("exitsshit");
  return 1;
}

exitsshit(arg)
{

  int num; string strnum;
  string dir, path;
  if(strlen(arg) > 2) {
    if(arg[0..1]=="~d") {
    int j, k;
  k = sizeof(exits);
  if(k) {
     object *newobs; newobs=({});
  arg = arg[3..strlen(arg)-1];
  arg = atoi(arg);
  arg = translate_h(arg);
  write("arg=\""+arg+"\"\n");
  for(j=0;j<k; j++) { if(arg != exits[j]) newobs += ({ exits[j] }); } exits=newobs; }
  }
  }
  else {
    num=atoi(arg);
    if(num) {
    strnum = translate_h(num);
    if(strnum != h)
 {
    if(member_array(strnum, exits) == -1) exits += ({ strnum });
    }
  }
  }
  PROMPT
  dspMain();
  input_to("mainMenu");
  return 1;
}

save_me(){
  int x, y;
  if(h=="0") { write("No hood.\n"); return 1; }
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
  return 1;
  }
