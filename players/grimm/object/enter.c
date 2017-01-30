string LONG,SHORT,READ,ID;

id(str){
  if(ID && SHORT && LONG)
    return str==ID || str==SHORT || str==LONG;
  return str=="hole";
}

get(){ return 0; }

long(){
  if(!LONG){
    write("A hole in the ground just large enough for a person to enter.\n");
    return 1;
  }
  write(LONG);
  return 1;
}

short(){
  if(!SHORT)
     return "A small hole";
  return SHORT;
}

reset(){}

init(){
  add_action("enter","enter");
}

set_long(s){ LONG = s; }
set_short(s){ SHORT = s; }
set_read(s){ READ = s;}
set_id(s){ ID = s; }
enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str=="hole") {
write("You enter the hole and emerge on the other side.\n");
this_player()->move_player("through the hole#/players/grimm/guild");
return 1;
}
return;
}
