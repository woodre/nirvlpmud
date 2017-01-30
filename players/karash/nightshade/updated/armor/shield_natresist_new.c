inherit "/obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: shield_natresist_new.c
 * Path: /players/nightshade/armor
 * Type: Armor / Shield
 * Created: October 2014 by Karash
 *
 * Purpose: A shield with some resistance to all natural damage types.
 * 
 * History:
 *          
 ******************************************************************************/


 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("shield");
  set_short(HIY+"Sh"+NORM+YEL+"iel"+NORM+HIW+"d o"+NORM+"f Re"+HIW+"sis"+NORM+YEL+"tan"+NORM+HIY+"ce"+NORM);
  set_long("This medium-sized shield seems lighter than it should, but extremely\n\
resistant to most types of "+GRN+"natural threats"+NORM+", such as the elements, poison,\n\
electricity and sound.  When looking closely, you can occasionally see a\n\
faint pulse of light that seems to emanate from the center and burst to\n\
the outer edges.\n");

  set_ac(2);
  
  set_type("shield");
  set_weight(2);
  set_value(2500);
  
  set_res(5);
  set_params("other|fire",0,2,0);
  set_params("other|ice",0,2,0);
  set_params("other|wind",0,2,0);
  set_params("other|earth",0,2,0);
  set_params("other|water",0,2,0);
  set_params("other|poison",0,2,0);
  set_params("other|electric",0,2,0);
  set_params("other|sonic",0,2,0);
  
    
}

