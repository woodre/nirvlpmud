inherit "obj/armor";
/******************************************************************************
 * Program: fboots.c
 * Path: /players/dragnar/SevenSpires/armor
 * Type: Armor
 * Created: Sept 21st, 2016 by Dragnar
 *
 * Purpose: Shield that has huge resistance to physical damage, but also high
 *          chance of breaking.  Cannot be repaired.
 *
 * History:
 *          09/21/2016 - Dragnar
 *            Created
 ******************************************************************************/
#include <ansi.h>

reset(arg){
   ::reset(arg);
   set_short(HIK+"Shield"+NORM);
   set_long( "A simple shield.\n\
Test.\n");
   set_ac(0);
   set_weight(1);
   set_value(8500);
   set_name("shield");
   SetMultipleIds( ({ "shield","spireobj" }) );
   set_type("shield");
   set_params("physical",0,30,"ArmorSpecial");
}

/** Armor cannot be repaired **/
fix_armor() {
  if (!broke) {
    return 0;
  }

  write("This armor cannot be repaired, it is too badly damaged.\n");
  return 2;
}

/* This needs to be updated so the longer it is used the higher the chance of breaking */
ArmorSpecial() {
  if(!random(20)) {
    if(worn_by)
      tell_object(worn_by, HIK+"\n\n\t\tYour shield shatters as it absorbs a massive amount of force!\n\n"+NORM);
    armor_breaks();
  }
}
