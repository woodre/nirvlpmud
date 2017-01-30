/* speedster.c: guild pickup truck */
#define POSS (this_player()->query_gender() == "male" ? "his" : (this_player()->query_gender() == "female" ? "her" : "its"))
string owner;
status brief;
status moving;
short() { 
  if(moving) return 0;
  return "A light pickup truck ("+capitalize(owner)+"'s)"; 
}
long() {
  if(moving) return 0;
  write("A dusty looking Toyota, with just a hint of the original metallic blue paint.\n");
  write("The mere sight of it makes you consider a cow as clean transportation.\n");
  write("If your nice, you could 'oogle' it...\n");
  write("This is the Logger's guild speedster (duh).\n");
  if(this_player()->query_real_name() == owner) 
    write("Type 'lhelp speedster' for more info.\n");
  return 1;
}
id(str) { 
  return str == "truck" || str == "pickup truck" || str == "light pickup truck"
   || str == "speedster";
}
get() { 
  write("Who are you, He-Man?\n");
  return 0;
}
init() {
  if(this_player()->query_real_name() == owner) {
    add_action("toggle", "toggle");
    add_action("drive", "drive");
    add_action("ditch", "ditch");
  }
  add_action("oogle", "oogle");
}
set_owner(str) { owner = lower_case(str); }
toggle(str) {
  if(!str) 
    write("Brief is "+(brief ? "on" : "off")+".\n");
  else if(str == "brief") {
    brief = !brief;
    write("Brief is now "+(brief ? "on" : "off")+".\n");
  }
  return 1;
}
oogle(str) {
  if(!id(str) || moving) return 0;
  write("You look at the sport utility truck and say: woo woo woo! I want one!\n");
  say(this_player()->query_name()+" looks at the truck and says: woo woo woo! I want one!\n");
  tell_object(find_player(owner), this_player()->query_name()+" oogles your truck.\n");
  return 1;
}
drive(str) {
  string *dir;
  string tmp;
  int x;
  x = 0;
  dir = allocate(40); 
  tmp = str;
  if(strlen(tmp) < 3 && tmp[2] != ',')
    tmp += ",";
  moving = 1;
  if(brief && !this_player()->query_brief()) this_player()->toggle_brief();
  write("You hop in your truck and turn on the engine.\n");
  say(this_player()->query_name()+" jumps in "+POSS+" truck and hits the road.\n");
  while(sscanf(tmp, "%s,%s", dir[x], dir[x+1]) >= 1)  {
    x++;    
    if(x == 5) { dir[x] = 0; break; }
    tmp = dir[x];
  }
  tmp = dir[0];
  for(x = 0; tmp; x++) {
    if(tmp != "s" && tmp != "n" && tmp != "e" && tmp != "w" && tmp != "se"
    && tmp != "sw" && tmp != "ne" && tmp != "nw" && tmp != "u" && tmp != "d")
      write("Invalid direction.\n");
    else
      command(tmp, this_player());
    tmp = dir[x+1];
  }
  move_object(this_object(), environment(this_player()));
  moving = 0;
  write("You jump out of your truck.\n");
  say(this_player()->query_name()+" hops out of "+POSS+" truck.\n");
  if(brief) this_player()->toggle_brief();
  return 1;
}
ditch(str) {
  write("You place your truck in neutral and watch it roll off.\n");
  say(capitalize(owner)+" ditches "+POSS+" truck.\n");
  destruct(this_object());
  return 1;
}
