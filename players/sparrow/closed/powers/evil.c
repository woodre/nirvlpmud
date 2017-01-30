#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"
#include "/sys/ansi.h"

main(object user, object wep, string name, string short){ 

  if(random(100) > 20) { 
    return 0;
  }
  tell_object(user, HIK+"["+HIR+"E"+HIK+"]"+NORM+RED+" Your "+HIK+name+NORM+RED+" fills you with "+HIK+HBRED+"HATRED"+NORM+RED+" of "+ATT->query_name()+"!"+NORM+"\n");
  user->add_alignment(-300);
  return 0;
}