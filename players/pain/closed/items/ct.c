#include <ansi.h>

#define PURPLE MAGENTA

int check,li;

id(str) {
    return str == "talk";
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
    write("A Cellular Phone\n");
    write("Usage: talk\n");
}

short() {
     return "cell phone";
}
drop() {return 1;}

query_auto_load() {
    return "/players/pain/closed/items/ct.c:";
}

init() {
  add_action("talk","talk");
   add_action("talke", "talke");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("lis");add_xverb("");
#else
  add_action("lis", "", 3);
#endif
}
talk (str)
{
string what, who;
  if(!str) {
     write("You cannot place a call without a message to Pain\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: talk [what]\n");
  return 1;}
  if(!find_player("pain") || check == 1) {
    write("Pain is not here....\n");
  return 1; }
  tell_object(find_player("pain"),PURPLE+"[]"+"  "+
  END+capitalize(this_player()->query_real_name())+END+" talks you: "+PURPLE+what+END+"\n");
  write("You talk Pain : "+PURPLE+what+END+"\n");
  return 1; 
}

talke (str)
{
string what, who;
  if(!str) {
     write("You cannot place a call without a message to Pain\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: talke [emote]\n");
  return 1;}
  if(!find_player("pain") || check == 1) {
    write("Pain is not here....\n");
  return 1; }
  tell_object(find_player("pain"),PURPLE+"[]"+"  "+
  END+capitalize(this_player()->query_real_name())+PURPLE+" "+what+END+"\n");
   write("You send a message to Pain: "+this_player()->query_name()+" "
          +what+"\n");
  return 1; 
}


lis(str) {
  if(li == 1) {
   write_file("/players/pain/closed/items/tell/*"+this_player()->query_real_name(),ctime(time())+" "+this_player()->query_real_name()+" "+str+"\n");
}
}
