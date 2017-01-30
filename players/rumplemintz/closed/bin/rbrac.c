#include <ansi.h>

int rbrac(string str){
  if(!str){
    notify_fail("Usage: rbrac <str>\n");
    return 0;
  }
  if(!find_player(str)){
    notify_fail("Cannot find "+str+" currently.\n");
    return 0;
  }
  move_object(clone_object("/players/rumplemintz/obj/bracelet"), find_player(str));
  tell_object(find_player(str),"\n"+
  HIW+"Rumplemintz "+NORM+"comes roarin' through the room on his pogo stick.\n"+
  HIW+"Rumplemintz "+NORM+"says: Hey there!  Catch!!\n"+
  "\n"+
  "You received a Friendship bracelet from "+HIW+"Rumplemintz"+NORM+". (Nice catch!)\n");
  return 1;
}
