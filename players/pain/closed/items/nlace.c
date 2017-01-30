#include <ansi.h>

#define LIGHT_BLUE CYAN

int check,li;

id(str) {
    return str == "necklace";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }
listen(a) { li = a; }

long() {
    write("A "+BOLD+"P E A R L"+END+" Necklace.\n");
    write("Usage: pp and ppe\n");
}

short() {
     return "A "+BOLD+"P E A R L"+END+" necklace from "+RED+"Pain"+END;
}
drop() {return 1;}

query_auto_load() {
    return "/players/pain/closed/items/nlace.c:";
}

init() {
  add_action("pp","pp");
   add_action("ppe", "ppe");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("lis");add_xverb("");
#else
  add_action("lis", "", 3);
#endif
}
pp (str)
{
string what, who;
  if(!str) {
     write("You need a message to send to Pain\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: pp [what]\n");
  return 1;}
  if(!find_player("pain") || check == 1) {
    write("Pain is not here....\n");
  return 1; }
  tell_object(find_player("pain"),LIGHT_BLUE+"<*>"+"  "+
  END+capitalize(this_player()->query_real_name())+END+" tells you: "+LIGHT_BLUE+what+END+"\n");
  write("You tell Pain : "+LIGHT_BLUE+what+END+"\n");
  return 1; 
}

ppe (str)
{
string what, who;
  if(!str) {
     write("You need to specify a message to emote to Pain\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: ppe [emote]\n");
  return 1;}
  if(!find_player("pain") || check == 1) {
    write("Pain is not here....\n");
  return 1; }
  tell_object(find_player("pain"),LIGHT_BLUE+"<*>"+"  "+
  END+capitalize(this_player()->query_real_name())+LIGHT_BLUE+" "+what+END+"\n");
   write("You send a message to Pain: "+this_player()->query_name()+" "
          +what+"\n");
  return 1; 
}


lis(str) {
  if(li == 1) {
   write_file("/players/pain/closed/items/tell/"+this_player()->query_real_name(),ctime(time())+" "+this_player()->query_real_name()+" "+str+"\n");
}
}
