/* Guild Level 6 - Misc Spell
   Spell brings a badmoon into play, which can affect other 
   necro spells at far as increasing damage and other stats
   TotalCost - 42sp (10 sp,1 heart, 1 blood)      
*/
#include "../defs.h"

cmd(str) {
object ob;

ob = GOB;
  if(!ob->checklev(6,11)) return 1;
  if(tp->query_sp() < 10){
    notify_fail("You do not have the spell points available for the Blood Moon.\n");
    return 0;
  }
  if(ob->query_heart() < 1 || ob->query_blood() < 1) {
    notify_fail("You do not have the components available for this spell.\n");
    return 0; 
  }
  if(BLOODMOON){
    write(ROD+"There is already a Bloodmoon within that area.\n");
    return 1; 
  }
  write("You take out a heart and a vial of blood.  You pour the blood across\n"+
        "the heart and as the drops fall to the ground you feel the realm of death's\n"+
        "pleasure to your sacrifice.\n");
  call_out("rise_moon",5,tp);      
  tp->add_spell_point(-10);
  ob->add_val(2);
  ob->add_heart(-1);
  ob->add_blood(-1);
  return 1;
}

rise_moon(player){
    tell_room(environment(player),HIR+"A "+OFF+RED+"blood red"+HIR+" moon rises through the clouds above.  Shadows fall across the land.\n"+OFF);
    move_object(clone_object(OBJ+"/misc/bloodmoon.c"),environment(player));
}
