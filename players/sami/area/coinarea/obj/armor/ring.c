inherit "/obj/armor";
#include "/obj/ansi.h"
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("ring");
  set_alias("ring_1");
  set_short("Ring of "+HIK+"Shadows"+NORM+"");
  set_long("A ring seeming to be made of pure "+HIK+"shadows"+NORM+", its consistency appears to change.\n"+
           "the light seems to make the"+HIK+" shadows"+NORM+" retract almost as if in pain.\n");

  
  set_params("other|evil",0,15,0);
  set_ac(1);
  set_type("ring");
  set_weight(1);
  set_value(3000);
}
do_special(owner)
{
        if(!worn) 
        {
                return; 
        }
        
    if(owner->query_level() > 10)
    {
            int X;
        X=random(100);
        if (X <15)
        {
                tell_object(owner, "The"+HIK+" Shadows "+NORM+"expand and you feel "+HIR+"Healthier"+NORM+"\n");
                        owner->add_spell_point(5 + random(10));
        }
        }
        
        else
        {
                return;
        }
        
}