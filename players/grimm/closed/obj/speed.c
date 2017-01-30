#define owner this_player()->query_real_name()
string dir, go, almost, name, NAME;
int count;
 
reset(arg) {
  if(this_player())
  NAME=owner;
  if(arg) return;
  if(this_player())
  {
  tell_object(find_living(owner),"Speedster...\n");
  NAME=owner;
   }
  dir = allocate(10);
  go = allocate(10);
  clear();
}
 
short() {
  return "A Super Speedster";
}
 
long() {
  write("This is a Directional Speedster.\nThe commands associated with it are:\n"+
  "  learn <pathname> <directions> .... To store a set of directions (separated\n"+
  "                                     with commas) in the path PATHNAME\n"+
  "  learn <pathname> ................. Allows you to manually store a set of\n"+
  "                                     directions in the path PATHNAME\n"+
  "  show ............................. Shows all stored pathnames and their\n"+
  "                                     directions\n"+
  "  erase <pathname> ................. Erases a given path\n"+
  "  go <pathname> .................... Execute the given directions\n"+
  "  backtrack <pathname> ............. Execute the given directions backwards\n"+
  "                                     (i.e. Go from point B to A)\n"+
  "  info ............................. Gives a detailed description of the\n"+
  "                                     Speedster\n");
}
 
id(str) {
  return str=="speedster";
}
 
query_auto_load() {
  return "/players/grimm/closed/obj/speed:"+dir[1]+"#"+dir[2]+"#"+
         dir[3]+"#"+dir[4]+"#"+dir[5]+"#"+dir[6]+"#"+dir[7]+"#"+
         dir[8]+"#"+dir[9]+"#"+dir[0]+"#"+go[1]+"#"+go[2]+"#"+
         go[3]+"#"+go[4]+"#"+go[5]+"#"+go[6]+"#"+go[7]+"#"+go[8]+"#"+
         go[9]+"#"+go[0];
}
 
init_arg(str) {
  sscanf(str,"%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s",
         dir[1],dir[2],dir[3],dir[4],dir[5],dir[6],dir[7],dir[8],dir[9],
         dir[0],go[1],go[2],go[3],go[4],go[5],go[6],go[7],go[8],go[9],
         go[0]);
  clear();
}
 
clear() {
  int i;
  for(i=0;i<10;i++) {
    if(!dir[i]) dir[i] = "None";
    if(!go[i]) go[i] = "None";
  }
}
 
init() {
  add_action("backtrack","backtrack");
  add_action("go","go");
  add_action("show","show");
  add_action("learn","learn");
  add_action("erase","erase");
  add_action("info","info");
}
 
info() {
  cat("/players/grimm/closed/obj/speed_detail");
  return 1;
}
 
drop() { return 1; }
 
get() { return 1; }
 
show() {
  int i,j;
  j=0;
  write("Current paths are:\nPath Name       Path\n");
  write("---------       ----\n");
  for(i=0;i<10;i++) {
    if(dir[i]!="None") {
      j++;
      write(dir[i]);
      if(strlen(dir[i])>7) write("\t");
        else write("\t\t");
      write(go[i]+"\n");
    }
  }
  if(j==0) write("\nNone Entered yet.\n");
  return 1;
}
 
learn(str) {
  string path;
  if(!str) { 
    write("You must supply a name for the path.\n");
    return 1;
  }
  if(sscanf(str,"%s %s",name,path)) {
    if(strlen(path)>59) {
      write("The path was too long.  You can only have 30 directions in it.\n");
      return 1;
    }
  }
  if(sscanf(str,"%s %s",name,path)) 
   {
        if(fill_path(name,path)==1) {
        write("Path: "+name+" checks out and was entered.\n");
        return 1;
        } else {
          write("The paths are full.  Erase one and try again.\n");
          return 1;
        }
    }
  name=str;
  write("\nBegin entering the directions below.  Finish with a \"~S\" or\n"+
        "abort with a \"~Q\".  The directions can be in either the form:\n"+
        "\"north\" or \"n\" (as an example).  You may enter up to 30 directions.\nGO.\n");
  count=1;
  almost="";
  input_to("get_path");
  return 1;
}
 
get_path(str) {
  if(count>30) return 1;
  write("Path step #"+count+".\n");
/*
  if(!valid_direction(str)) {
    write("INVALID DIRECTION!  \"Learn\" aborted.\n");
    return 1;
  }
*/
  if(str=="~Q") {
    write("\"Learn\" aborted by user request.\n");
    return 1;
  }
  if(str=="~S") {
      if(fill_path(name,almost)==1) {
      write("Path: "+name+" checks out and was entered.\n");
      return 1;
      } else {
        write("The paths are full.  Erase one and try again.\n");
        return 1;
      }
  }
  command(str,this_player());
  almost=almost+str+",";
  write("'"+almost+"'\n");
  if(count==30) {
    get_path("~S");
  }
  count++;
  input_to("get_path");
  return 1;
}
 
check_path(str) {
  string first, rest;
  while(sscanf(str,"%s,%s",first,rest)) {
    if(first=="n" || first=="s" || first=="e" || first=="w" || first=="nw" || first=="ne" || first=="se" || first=="sw" || first=="north" ||
       first=="south" || first=="east" || first=="west" || first=="northwest" || first=="northeast" || first=="southeast" || first=="southwest" || first=="up" || first=="u" || first=="down" || first=="d") {
      str=rest;
    } else { str="PUKE"; }
  }
  if(str=="PUKE") { return 0; }
  return 1;
}
 
fill_path(name,path) {
  int i,j;
  j=-1;
  for(i=0;i<10;i++) {
    if(dir[i]=="None") { j=i; }
  }
  if(j==-1) {
    return 0;
  }
  erase(name,1);
  path=path+"#";
  dir[j]=name;
  if(!sscanf(path,"%s,#",go[j])) {
  sscanf(path,"%s#",go[j]);
  }
  return 1;
}
 
erase(str,x) {
  int i,j;
  if(!str) {
    write("What pathname do you want to erase?\n");
    return 1;
  }
  j=-1;
  for(i=0;i<10;i++) {
    if(str==dir[i]) j=i;
  }
  if(j==-1) {
    if(!x)
    write("Path: "+str+" was not found.\n");
    return 1;
  }
  if(!x)
  write("Path: \n"+dir[j]+" ("+go[j]+")\nHas been erased.\n");
  dir[j]="None";
  go[j]="None";
  return 1;
}
 
go(str) {
  int i,j, brief;
  string first,rest,full;
  if(!str) {
/*
    write("You must give the pathname.\n");
    return 1;
*/
    return 0;
  }
  j=-1;
  for(i=0;i<10;i++) {
    if(str==dir[i]) j=i;
  }
  if(j==-1) {
/*
    write("Path: "+str+" was not found.\n");
    return 1;
*/
    return 0;
  }
  write("Executing path: "+str+".\n");
/*
  if(!this_player()->query_brief()) {
    brief=1;
    this_player()->toggle_brief();
  } else brief=0;
*/
  full=go[j]+",#";
  while(sscanf(full,"%s,%s",first,rest)) {
    command(first,this_player());
    full=rest;
  }
/*
  if(brief) command("brief",this_player());
*/
  write("Done.\n");
  return 1;
}
 
backtrack(str) {
  string front, full, build, com;
  int i,j;
  if(!str) {
    write("You must supply the path you want to backtrack.\n");
    return 1;
  }
  j=-1;
  for(i=0;i<10;i++) {
    if(dir[i]==str) j=i;
  }
  if(j==-1) {
    write("Path: "+str+" was not found.\n");
    return 1;
  }
  if(!check_path(go[j])) {
    write("Path cannot be backtracked due to \"other\" commands in it.\n");
    return 1;
  }
/* REVERSE go[j] !! */
  full=go[j]+",0,0";
  build="#";
  while(sscanf(full,"%s,%s",front,com)) {
    if(com!="0") {
    build=front+","+build;
    }
    full=com;
  }
  full=build;
  while(sscanf(full,"%s,%s#",com,front)) {
    full=front+"#";
    if(com=="n" || com=="north") command("south",this_player());
    if(com=="s" || com=="south") command("north",this_player());
    if(com=="e" || com=="east") command("west",this_player());
    if(com=="w" || com=="west") command("east",this_player());
    if(com=="u" || com=="up") command("down",this_player());
    if(com=="d" || com=="down") command("up",this_player());
    if(com=="sw" || com=="southwest") command("northeast",this_player());
    if(com=="se" || com=="southeast") command("northwest",this_player());
    if(com=="nw" || com=="northwest") command("southeast",this_player());
    if(com=="ne" || com=="northeast") command("southwest",this_player());
  }
  write("Done.\n");
  return 1;
}
