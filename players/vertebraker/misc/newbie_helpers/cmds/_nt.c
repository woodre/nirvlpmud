#include <ansi.h>

int main(string str)
{
  object *us;
  int s;
  us=users();
  s=sizeof(us);
  while(s--) {
    if(us[s] && present("newbie_helper", us[s])) {
      tell_object(us[s], "("+HIB+"Newbie Helper"+NORM+") "+(string)this_player()->query_name()+" ==> "+str+"\n");
    }
  }
  return 1;
}
