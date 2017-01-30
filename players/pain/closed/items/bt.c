#include "/players/pain/color.h"
int check,li;

id(str) {
    return str == "microphone";
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
	
	write("A Microphone\n");
    write("Usage: sing\n");
}

short() {
     return "A Microphone";
}
drop() {return 1;}

query_auto_load() {
    return "/players/pain/closed/items/bt.c:";
}

init() {
  add_action("talk","sing");
   add_action("talke", "singe");
  add_action("lis");add_xverb("");
}
talk (str)
{
string what, who;
  if(!str) {
     write("You cannot sing to your love without a message \n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: sing [what]\n");
  return 1;}
  if(!find_player("pain") || check == 1) {
    write("Pain is not here....\n");
  return 1; }
  tell_object(find_player("pain"),LIGHT_BLUE+"[]"+"  "+
  END+capitalize(this_player()->query_real_name())+END+" sings to you: "+LIGHT_BLUE+what+END+"\n");
  write("You sing to your love : "+LIGHT_BLUE+what+END+"\n");
  return 1; 
}

talke (str)
{
string what, who;
  if(!str) {
     write("You cannot sing to your love without a message to Pain\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: singe [emote]\n");
  return 1;}
  if(!find_player("pain") || check == 1) {
    write("Pain is not here....\n");
  return 1; }
  tell_object(find_player("pain"),LIGHT_BLUE+"[]"+"  "+
  END+capitalize(this_player()->query_real_name())+LIGHT_BLUE+" "+what+END+"\n");
   write("You send a message to Pain: "+this_player()->query_name()+" "
          +what+"\n");
  return 1; 
}


lis(str) {
  if(li == 1) {
   write_file("/players/pain/closed/items/tell/*"+this_player()->query_real_name(),ctime(time())+" "+this_player()->query_real_name()+" "+str+"\n");
}
}
