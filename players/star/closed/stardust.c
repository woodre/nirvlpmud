#include <ansi.h>
int check;

id(str) {
     return str == "speck" || str == "ND";
}

reset(arg) {
  if(arg) return;
   check = 0;
}


long() {
    write("This is a very shiny, and very tiny, speck of what looks like stardust.\n");
    write("You can use it to talk to Star.\n");
    write("Usage: wish and wishe\n");
}

short() {
     return "A Speck of Stardust";
}
drop() {return 1;}

query_auto_load() {
    return "players/star/closed/stardust.c:";
}

init() {
  add_action("wish","wish");
  add_action("wishe","wishe");
}
wish (str)
{
string what, who;
  if(!str) {
     write("What would you like to say to Star?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: wish [what]\n");
  return 1;}
  if(!find_player("star") || check == 1) {
    write("Star is not here right now.\n");
  return 1; }
  tell_object(find_player("star"),HIB+"**"+"  "+
NORM+capitalize(this_player()->query_real_name())+NORM+" wishes to you: "+HIB+what+NORM+"\n");
  write("You wish to Star : "+HIB+what+NORM+"\n");
  return 1; 
}

wishe (str)
{
string what, who;
  if(!str) {
     write("What would you like to emote to Star?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: wishe [emote]\n");
  return 1;}
  if(!find_player("star") || check == 1) {
    write("Star is not here right now.\n");
  return 1; }
  tell_object(find_player("star"),HIB+"**"+"  "+
  NORM+capitalize(this_player()->query_real_name())+HIB+" "+what+NORM+"\n");
   write("You send a message to Star: "+this_player()->query_name()+" "
          +what+"\n");
  return 1; 
}
