#include "../def.h"
#include <ansi.h>

#define TP this_player()
#define ENV environment
#define QN query_name()

object e;

start_it(x){
  shadow(x, 1);
  e = x;
  call_out("dissolve", 300);
}

short(){
  return e->short()+" "+RED+"[FireGripped]"+NORM;
}

long(str){
  e->long(str);
  write(RED+"A spell has been cast on the hilt of this weapon.\n"+NORM);
}

dissolve()
{
  if(e)
    tell_object(ENV(e),
      "The flames around "+e->query_name()+" die down.\n");

  destruct(this_object());
}

query_firegripped(){
  return 1;
}

set_wielded_by(x){
  if(!x){
    if(TP != environment(e)){
      command("wield "+e->query_name(), ENV(e));
      TP->hit_player(10+random(25), "other|fire");
      write(RED+"You are burned by the attempt!\n"+NORM);
      say(TP->QN+" is burned by the "+RED+"FireGrip"+NORM+"!\n");
      return 1;
    }
  }
  return e->set_wielded_by(x);
}