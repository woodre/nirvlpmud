
inherit "/obj/armor";

#include <ansi.h>
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("necklace");
  set_short(""+HIK+"Alucard's"+NORM+" necklace");
  set_long("This Necklace belonged to the legendary Alucard Belmont.\n"+
           " it appears to ward some of the powers of evil. \n");
  
  set_params("other|dark",0,3,0);
  set_params("other|evil",0,3,0);
  set_params("other|light",0,-2,0);
  set_params("other|good",0,-2,0);
  set_ac(1);
  
  set_type("necklace");
  set_weight(1);
  set_value(500);
}
  do_special(owner)
{
        if(!worn) 
        {
             return; 
        }
        
      if((int)owner->query_attrib("mag") > random(100))
  {
    tell_object(owner,
      "The"+HIK+" Necklace "+NORM+""+HIY+"flashes"+NORM+" brightly as you feel"+HIR+" invigorated"+NORM+"\n");
    tell_room(environment(owner),
    owner->query_name()+"'s "+HIG+"N"+HIK+"ecklace"+NORM+" "+HIY+"flashes"+NORM+" brightly!\n", ({ owner }));
    owner->add_spell_point(5+random(6));
    return random(2);
   }
  return;
}
