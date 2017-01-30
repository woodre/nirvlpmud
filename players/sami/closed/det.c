#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"
#include "/sys/ansi.h"

main(object user, object wep, string name, string short){ 
  int stu, soa;
  if(random(100) < 20) { 
    return 0;
  }
  tell_object(user,
  HIW+"["+HIG+"+"+HIW+"]"+NORM+GREEN+" Your "+HIK+name+NORM+GREEN+" siphons power from your digestive system!\n"+NORM);
  stu = user->query_stuffed();
  soa = user->query_soaked();
  if(stu && stu > 5) { 
    user->add_stuffed(-5);
  }
  else if(stu > 0) {
    user->add_stuffed(-stu);
  }
  if(soa && soa > 5) {
    user->add_soaked(-5);
  }
  else if(soa > 0) {
    user->add_soaked(-soa);
  }
  return 0;
}