
inherit "/obj/armor";

#include <ansi.h>
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("necklace");
  set_short(""+HIK+"Alucard's"+NORM+" necklace");
  set_long("This Necklace belonged to the legendary Alucard Belmont.\n"+
           " it appears to ward some of the powers of evil. \n");
  
  set_params("other|dark",0,10,0);
  set_params("other|evil",0,10,0);
  set_params("other|light",0,-5,0);
  set_ac(1);
  
  set_type("necklace");
  set_weight(1);
  set_value(5000);
}
  do_special(owner)
{
        if(!worn) 
        {
                return; 
        }
        
    if(owner->query_level() > 10)
    {
            int y;
        y=random(100);
        if (y <15)
        {
                tell_object(owner, "The"+HIK+" Necklace "+NORM+" become warm and and you feel "+HIR+" invigorated"+NORM+"\n");
                        owner->add_spell_point(5+random(10));
        }
        }
        
        else
        {
                return;
        }
        
}
