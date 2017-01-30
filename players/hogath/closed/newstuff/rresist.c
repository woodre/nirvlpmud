/*
 *      File:                   rresist.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 06/08/04 
 *      Notes:                  ring of resistences
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/armor";

reset(arg){
  if(arg) return;
  ::reset(arg);
  set_name(HIB+"Ring "+HIR+"of"+NORM+" "+BOLD+"Res"+HIW+"ist"+HIM+"en"+HIB+"ces"+NORM);
  set_alias("ring");
  set_short(HIB+"Ring "+HIR+"of"+NORM+" "+BOLD+"Res"+HIW+"ist"+HIM+"en"+HIB+"ces"+NORM);
  set_type("ring");
  set_ac(0);
  set_weight(1);
  set_value(5000);
  set_long("This ring was crafted to protect from the many spells\n"+
           "cast by the demons in the forest.  It is a simple silver.\n"+
           "band with several bright gems set into it.\n");
  set_params("other|mental" , 1, 10, "do_mental_special");
  set_params("other|ice" , 1, 10, "do_ice_special");
  set_params("other|fire" , 1, 10, "do_fire_special");
  set_params("other|acid" , 1, 10, "do_acid_special");
  /* 1 ac and 10% resistence vs fire, ice, mental and acid forces,
     and calls respective functions regarding each.*/
     }

do_special(owner)/*not sure if really need to put this in, but anyway ;P*/
{  
  if(!random(5))
     {
      tell_object(owner, HIY+"Your ring glows dimly!\n");
      return 1+random(1);
    }
}
  
int do_mental_special(object owner)
{
 
    
     tell_object(owner, HIW+"Your Ring glows as the diamond channels away some of "+atn+" mental attack.\n"+NORM);
     return 1002;
     /*10% [10] boost to resistance for mental attacks
      2 ac [02] boost vs mental attacks
      */
   
}

int do_fire_special(object owner)
{
  
    
     tell_object(owner, HIR+"The ruby on your ring draws heat away from you.\n"+NORM);
     return 1002;
     /*10% [10] boost to resistance for fire attacks
      2 ac [02] boost vs fire attacks
      */
   
}

int do_ice_special(object owner)
{
  
    
     tell_object(owner, HIB+"A warm glow surronds you as the sapphire draws cold into it"+NORM+".\n");
     return 1002;
     /*10% [10] boost to resistance for ice attacks
      2 ac [02] boost vs ice attacks
      */
   
}

int do_acid_special(object owner)
{
 
    
     tell_object(owner, BOLD+"Your ring flashes and deflects some of the acid.\n"+NORM);
     return 1002;
     /*10% [10] boost to resistance for acid attacks
      2 ac [02] boost vs acid attacks
      */
   
}
