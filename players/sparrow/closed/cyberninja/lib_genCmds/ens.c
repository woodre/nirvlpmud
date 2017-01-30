#include "../DEFS.h"


status corpse, electricflux, magneticflux, heatflux, flash, emt, 
    armor, mechmon, bionics, blades, eyes, activate_droid, legs, 
    convert, poisona, poisonh, blood, inertia, nanoblood;

int weplink;


string showItemfunc()
{
/* This function creates a list of enhancements */
  string ensList;
  ensList = "____________________ _____ __\n";
  if(eyes)           ensList += "Cybereyes\n";
  if(corpse)         ensList += "Organic Converter\n";
  if(activate_droid) ensList += "Droid\n";
  if(bionics)        ensList += "Bionics\n";
  if(blades)         ensList += "Blades\n";  
  if(electricflux ||
     magneticflux ||
     heatflux)       ensList += "Flux Generator\n";
  if(flash)          ensList += "Biolight\n";
  if(emt)            ensList += "Emotion Controller\n";
  if(legs)           ensList += "Leg Actuators\n";
  if(convert)        ensList += "Matter Converter\n";
  if(poisona)        ensList += "Tranquilizer Poison Cannon\n";
  if(poisonh)        ensList += "Degenerative Poison Cannon\n";
  if(mechmon)        ensList += "Mech Monitor\n";
  if(nanoblood)      ensList += "Nano Blood\n";
  else if(blood)     ensList += "Polymer Blood\n";
  if(inertia)        ensList += "Inertia Field\n";
  if(armor)          ensList += "Sub-dermal Armoring\n";
  if(weplink)        ensList += "Smartweapon Link ["+weplink+"]\n";
  ensList += "____________________ _____ __\n";
  return ensList;
}


status main(string str) {
/* shows all enhancements the person has */
  object ob;
  string pName, capName;

  if (!str)
  {
    if (!restore_object(SAVEDIR + "/" + this_player()->query_real_name()))
    {
      write("Your guild record is corrupt!\n");
      return 1;
    }
    write("Your enhancements are....\n");
    write(showItemfunc());
    return 1;
  }

  pName = str;
  capName = capitalize(pName);

  if (call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl ruby emerald onyx glass"))
  {
    if (!restore_object(SAVEDIR + "/" + pName))
    {
      write("No guild record exists for " + capName + ".\n");
      return 1;
    }
    write(capName + "'s enhancements are....\n");
    write(showItemfunc());
    return 1; 
  }
  else
  {
    write("You cannot view the enhancements of others.\n");
  }

  return 1;
}
