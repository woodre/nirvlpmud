/* master object for newbie heals
 - illarion 8.2009
 */
 
#include "/obj/ansi.h"
 
status use_heal(object user, object heal, int uses, int intox, int stuff, int soak, int hp, int sp,
                string message_self, string message_room, string message_empty) {
  object room;
  room = environment(user);
  if(environment(heal) != user)
    return (notify_fail("You must be carrying the heal to use it.\n"), 0);
  if((stuff && !user->eat_food(stuff))
    ||(soak && !user->drink_soft(soak))
    ||(intox && !user->drink_alcohol(intox)))
    return 1;
  if(message_self)
    tell_object(user,message_self);
  if(message_room && room)
    tell_room(room,message_room);
  if(hp)
    user->add_hit_point(hp);
  if(sp)
    user->add_spell_point(sp);
  user->print_monitor();
  tell_object(user,"The container has "+HIB+"["+(uses--)+"]"+NORM+" uses left.\n");
  heal->set_uses(uses);
  if(uses<=0) {
    if(message_empty)
      tell_object(user,message_empty);
    if(room)
      transfer(heal, room);
    destruct(heal);
  }
  return 1;
}
