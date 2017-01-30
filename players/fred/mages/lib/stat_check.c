#include "/players/fred/mages/defs.h"

stat_check(){
  object me;
  int strength, stamina;
  me = environment();
  if(!me) return;
  strength = me->query_attrib("str");
  stamina = me->query_attrib("sta");
  if(strength > 20){
    tell_object(me, BOLD+BLK+"\tDark Energy drains you of your extra strength.\n"+NORM);
   me->set_attrib("str",20);
   me->save();
   me->reset(); }
  if(stamina > 23){
    tell_object(me, BOLD+BLK+"\tDark Energy drains you or your extra stamina.\n"+NORM);
    me->set_attrib("sta",23);
    me->save();
    me->reset(); }
  return 1; }
