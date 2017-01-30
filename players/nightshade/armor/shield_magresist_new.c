inherit "/obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: shield_magresist_new.c
 * Path: /players/nightshade/armor
 * Type: Armor / Shield
 * Created: October 2014 by Karash
 *
 * Purpose: A shield with some resistance to all magical damage types.
 * 
 * History:
 *          
 ******************************************************************************/


 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("shield");
  set_short(HIB+"Sh"+NORM+BLU+"iel"+NORM+CYAN+"d o"+NORM+HIC+"f Re"+NORM+CYAN+"sis"+NORM+BLU+"tan"+NORM+HIB+"ce"+NORM);
  set_long("This medium-sized shield seems lighter than it should, but extremely\n\
resistant to most types of "+CYAN+"magical threats"+NORM+", such as magic, good and evil,\n\
light and dark, and mental attacks.  When looking closely, you can\n\
occasionally see a pulse of faint blue light that seems to emanate from\n\
the center and burst to the outer edges.\n");

  set_ac(2);
  
  set_type("shield");
  set_weight(2);
  set_value(2500);
  
  set_res(5);
  set_params("magic",0,2,0);
  set_params("magical",0,2,0);
  set_params("other|dark",0,2,0);
  set_params("other|light",0,2,0);
  set_params("other|good",0,2,0);
  set_params("other|evil",0,2,0);
  set_params("other|mental",0,2,0);
  set_params("other|magic",0,2,0);
  
    
}

