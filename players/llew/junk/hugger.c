#include "/players/llew/closed/ansi.h"
int check;

id(str) {
    return str == "hugger";
}

reset(arg) {
  if(arg) return;
}

silence(n) { check = n; }

long() {
    write("A hugger made my Llew. For hugging. Type lhug (player)\n");
}

drop() {return 1;}


init() {
  add_action("lhug","lhug");
}
lhug (str)
{
string what, who;
  if(!str) {
    write("Hug who?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("To use: lhug (player)\n");
  return 1;}
  if(!find_player(what) || check == 1) {
    write(what+" is not here...\n");
  return 1; }
  tell_object(find_player(what),BOLD+"\n       * * * * *** ***\n"+
 "       * * * * *   *\n"+
 NORM+" Llew  "+BOLD+"*** * * * * ***  "+NORM+"YOU!!!\n"+
 BOLD+"       * * * * * *   *\n"+
 "       * * *** *** ***\n\n"+NORM);
  write("You HUG "+what+"!\n");
return 1;
}

