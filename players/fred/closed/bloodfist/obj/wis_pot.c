inherit "/obj/treasure.c";
#include "/players/fred/ansi.h"
#define WISDOM_BUFF 400
int duration;
object gob, me;

reset(arg){
  if (arg) return;

  duration = 39+random(12);
  set_id("potion");
  set_alias("wisdom potion");
  set_short(HIW+"A Potion of Distilled Wisdom"+NORM);
set_long(
"  Contained within a thin vile is a blue-tinted, softly glowing liquid.\n"+
"A white label has been affixed to the side of the vial which reads:\n"+
"                      POTION OF DISTILLED WISDOM\n"+
"The effect of this potion will only last for a short time.  To consume\n"+
"the contents of the vial, simply 'drink' it.  This potion will have no\n"+
"effect if you are not in the Bloodfist guild.\n");
  set_weight(1);
  set_value(1865);
}

drop(){ 
  if(!local_weight && gob)
  {
    gob->add_attribb(4, -WISDOM_BUFF);
    duration = 0;
    return 1;
}
else if(!local_weight)
    return 1;
  return 0; 
}
id(str){ if(local_weight) return (::id(str)); else return "invis_wis_pot"; }
query_save_flag(){ return 1; }

void init(){
  ::init();
  add_action("use", "drink");
}

status use(string str)
{
  if(!present(this_object(), this_player())) return 0;
  if(str != "potion" && str != "wisdom" && str != "wisdom potion")
    return 0;
  if(!(gob = present("bloodfist_gob", this_player())))
    return(notify_fail("You are not a Bloodfist.\n"), 0);
if(present("invis_wis_pot", this_player()))
    return(notify_fail("You are already under the effect of this potion.\n"),
    0);

  write(HIW+
    "You quickly quaff the contents of the vial labeled 'potion of distilled\n"+
    "wisdom'.  It has a flavor reminiscent of blueberries.  A warmth pulses\n"+
    "through your bloodstream as the potion takes effect.\n");
  say(HIW+this_player()->query_name()+" drinks a potion of distilled wisdom.\n"+
  NORM);
  local_weight = 0;
  short_desc = 0;
  long_desc = 0;
  this_player()->recalc_carry();
gob->add_attribb(4, WISDOM_BUFF);
me = this_player();
call_out("end_effect", duration);
  return 1;
}

end_effect()
{
if(!duration) return;
if(!environment()) return;
if(!gob) return;
if(environment() != me) return;
  tell_object(environment(),
    HIW+"\nThe effect of the potion of distilled wisdom fades away...\n\n"+
    NORM);
  tell_room(environment(environment()), HIW+
    "The effect of "+environment()->query_name()+
    "'s potion of distilled wisdom fades away...\n"+NORM,
    ({ environment() }));
  gob->add_attribb(4, -WISDOM_BUFF);
destruct(this_object());
return;
}
