inherit "/obj/armor";
#include <ansi.h>
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("sandals");
  set_short(""+HIY+"Simon's Sandals"+NORM+"");
  set_long("These sandals belong to the legendary Simon Belmont. They seem to\n"+
           " offer some sort of protection against the elements. \n");
  
  set_params("other|earth",0,10,0);
  set_ac(1);
  
  set_type("boots");
  set_weight(1);
  set_value(500);
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
                tell_object(owner, "The"+HIK+" Sandals "+NORM+" become warm and and you feel "+HIR+" invigorated"+NORM+"\n");
                        owner->add_spell_point(5+random(10));
        }
        }
        
        else
        {
                return;
        }
        
}
