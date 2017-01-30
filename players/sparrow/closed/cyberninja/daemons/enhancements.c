#include "../DEFS.h"
#include DEFS_ENHANCEMENTS
#include DEFS_OFFICES

#define FLUX_TYPE   0
#define FLUX_NAME   1
#define FLUX_COLOR  2
#define FLUX_SYMBOL 3

#define FLUXES ({ ({"light","UV",BOLD,"*"}), ({"fire","Heat",BOLD+RED,"f"}), ({"ice","Freeze",BOLD+CYAN,"z"}), ({"electric","Electric",BOLD+YELLOW,"-"}), ({"laser","Magnetic",BOLD+MAGENTA,"|"}), ({"poison","Acid",BOLD+GREEN,"%"}), ({"mental","Psi",BOLD+BLUE,"O"}) })



int findItemCost(string str)
{
  /* list in order of cost for convenience*/
  switch(str) {
    case GLIMMER:    return COST_GLIMMER;
    case EYES:       return COST_EYES;
    case FLUX:       return COST_FLUX;
    case BLADES:     return COST_BLADES;
    case ARMOR:      return COST_ARMOR;
    case EMT:        return COST_EMT;
    case MATTER:     return COST_MATTER;
    case ORGANIC:    return COST_ORGANIC;
    case BIONICS:    return COST_BIONICS;
    case POISONA:    return COST_POISONA;
    case POISONH:    return COST_POISONH;
    case MECHMON:    return COST_MECHMON;
    case BLOOD:      return COST_BLOOD;
    case INERTIA:    return COST_INERTIA;
    case NANOBLOOD:  return COST_NANOBLOOD;
/* Removed 9/98 -Snow
    case DROID:    return COST_DROID;
*/
  }
  return -1;
}


int hasItem(object ob, string str)
{
  status flag;
  switch(str) {
    case EYES:       if((status)IPOB->item_eyes()) return 1;
                     break;
    case ORGANIC:    if((status)IPOB->item_corpse()) return 1;
                     break;
    case BIONICS:    if((status)IPOB->item_bionics()) return 1;
                     break;
    case BLADES:     if((status)IPOB->item_blades()) return 1;
                     break;
    case FLUX:
                     if((status)IPOB->item_electricflux()) flag=1;
                     if((status)IPOB->item_magneticflux()) flag=1;
                     if((status)IPOB->item_heatflux())     flag=1;
                     if(flag) return 2;
                     break;
    case GLIMMER:    if((status)IPOB->item_flash()) return 1;
                     break;
    case EMT:        if((status)IPOB->item_emt()) return 1;
                     break;
    case MATTER:     if((status)IPOB->item_convert()) return 1;
                     break;
    case ARMOR:      if((status)IPOB->item_armor()) return 1;
                     break;
    case POISONH:    if((status)IPOB->item_poisonh()) return 1;
                     break;
    case POISONA:    if((status)IPOB->item_poisona()) return 1;
                     break;
    case MECHMON:    if((status)IPOB->item_mechmon()) return 1;
                     break;
    case BLOOD:      if((status)IPOB->item_blood()) return 1;
                     break;
    case INERTIA:    if((status)IPOB->item_inertia()) return 1;
                     break;
    case NANOBLOOD:  if((status)IPOB->item_nanoblood()) return 1;
                     break;
  }
  return 0;
}


status setItem(object ob, string str)
{
  switch(str) {
    case EYES:        IPOB->set_eyes(1);           break;
    case ORGANIC:     IPOB->set_corpse(1);         break;
    case BIONICS:     IPOB->set_bionics(1);        break;
    case BLADES:      IPOB->set_blades(1);         break;
    case FLUX:        IPOB->set_electricflux(1);   break;
    case GLIMMER:     IPOB->set_flash(1);          break;
    case EMT:         IPOB->set_emt(1);            break;
    case MATTER:      IPOB->set_convert(1);        break;
    case ARMOR:       IPOB->set_armor(1);          break;
    case POISONH:     IPOB->set_poisonh(1);        break;
    case POISONA:     IPOB->set_poisona(1);        break;
    case MECHMON:     IPOB->set_mechmon(1);        break;
    case BLOOD:       IPOB->set_blood(1);          break;
    case INERTIA:     IPOB->set_inertia(1);        break;
    case NANOBLOOD:   IPOB->set_nanoblood(1);      break;
    default:      return 0;
  }
  return 1;
}


void list(object ob)
{
  tell_object(ob, pad("ITEM",25)+"PRICE (in @'s)\n");
  tell_object(ob,
  "________________________________________\n"+
  pad(POISONA,25)    +findItemCost(POISONA)   +"\n"+
  pad(GLIMMER,25)    +findItemCost(GLIMMER)   +"\n"+
  pad(MECHMON,25)    +findItemCost(MECHMON)   +"\n"+
  pad(FLUX,25)       +findItemCost(FLUX)      +"\n"+
  pad(POISONH,25)    +findItemCost(POISONH)   +"\n"+
  pad(BLADES,25)     +findItemCost(BLADES)    +"\n"+
  pad(BLOOD,25)      +findItemCost(BLOOD)     +"\n"+
  pad(ARMOR,25)      +findItemCost(ARMOR)     +"\n"+
  pad(EMT,25)        +findItemCost(EMT)       +"\n"+
  pad(INERTIA,25)    +findItemCost(INERTIA)   +"\n"+
  pad(EYES,25)       +findItemCost(EYES)      +"\n"+
  pad(MATTER,25)     +findItemCost(MATTER)    +"\n"+
  pad(ORGANIC,25)    +findItemCost(ORGANIC)   +"\n"+
  pad(BIONICS,25)    +findItemCost(BIONICS)   +"\n"+
  pad(NANOBLOOD,25)  +findItemCost(NANOBLOOD) +"\n"+
  "________________________________________\n");
}


void inUse(object ob)
{
  write("\n    ENHANCEMENTS IN USE   \n\n");
  if((status)IPOB->query_blad_on())  write(RED+"  Blades"+OFF+"\n");
  if((status)IPOB->query_bion_on())  write(RED+"  Bionics"+OFF+"\n");
  if((status)IPOB->query_armor_on()) write(BROWN+"  SubDermal Armor"+OFF+"\n");
  if((status)IPOB->query_regen())    write(BLUE+"  Regeneration"+OFF+"\n");
  if((status)IPOB->query_rejuv())    write(BLUE+"  Rejuvenation"+OFF+"\n");
  if((status)IPOB->query_convert_on()) write(GREEN+"  Conversion"+OFF+"\n");
  if((status)IPOB->query_equil())    write(GREEN+"  Equilibration"+OFF+"\n");
  if((status)IPOB->query_digest())   write(BOLD+"  Digestion"+OFF+"\n");
  if((status)IPOB->query_light_on()) write(YELLOW+"  Biolight"+OFF+"\n");
  write("\n");
}


status purchase(object ob, string str)
{
/* Way to buy new enhancements */
  int cost;
  if (!IPOB) return 0;
  if (!str) return 0;
  str = lower_case(str);
  if (findItemCost(str) == -1)
  {
    tell_object(ob, "No such enhancement.\n");
    return 0;
  }
  if (hasItem(ob, str) == 2)
  {
    tell_object(ob, "Only one of this type of enhancement allowed.\n");
    return 0; 
  }
  if (hasItem(ob, str))
  {
    tell_object(ob, "You already have the "+str+"\n");
    return 0; 
  }
  if (str == NANOBLOOD && !call_other(OFFICED, "checkStone", TP, "diamond sapphire"))
  {
    tell_object(ob, 
      "Precious "+NANOBLOOD+" is only afforded to "+capitalize(DIAMOND)+"s and "+
      capitalize(SAPPHIRE)+"s.\n");
    return 0;
  }
  cost = findItemCost(str);
  if (IPOB->balance() < cost)
  {
    tell_object(ob, "Insufficient credits to buy the "+str+"\n");
    return 0; 
  }
  IPOB->addToBalance(-cost);
  setItem(ob, str);
  write_file(LOGDIR + "/PURCHASE",
    ORN+" purchased the "+str+" enhancement. ("+ctime()+")\n");
  tell_object(ob, "You purchase the "+str+"\n");
  IPOB->save_me();
  move_object(IPOB, ob); /* force init */
  return 1;
}


string showStatus(object ob)
{
  int hp, mhp, sp, msp, shp, ssp;
  hp = (int)ob->query_hp();
  mhp = (int)ob->query_mhp();
  sp = (int)ob->query_sp();
  msp = (int)ob->query_msp();
  shp = 10 * hp / mhp;
  ssp = 10 * sp / msp;
  return("HP: "+shp+"/10  SP: "+ssp+"/10");
}


string* getFluxInfoList(string infoType)
{
  string *fluxList;
  int i;
  mixed *fluxes;

  fluxes = FLUXES;
  fluxList = allocate(sizeof(fluxes));
  for (i=0; i < sizeof(fluxes); i++)
  {
    switch(infoType)
    {
      case "type":   fluxList[i] = fluxes[i][FLUX_TYPE];   break;
      case "name":   fluxList[i] = fluxes[i][FLUX_NAME];   break;
      case "color":  fluxList[i] = fluxes[i][FLUX_COLOR];  break;
      case "symbol": fluxList[i] = fluxes[i][FLUX_SYMBOL]; break;
    }
  }

  return fluxList;
}


string getFluxInfo(string infoType, string fluxType)
{
  int i;
  mixed *fluxes;
  fluxes = FLUXES;

  for (i=0; i < sizeof(fluxes); i++)
  {
    switch(infoType)
    {
      case "name":   if (fluxes[i][FLUX_TYPE] == fluxType)
                       return fluxes[i][FLUX_NAME];
                     break;
      case "color":  if (fluxes[i][FLUX_TYPE] == fluxType)
                       return fluxes[i][FLUX_COLOR];
                     break;
      case "symbol": if (fluxes[i][FLUX_TYPE] == fluxType)
                       return fluxes[i][FLUX_SYMBOL];
                     break;
    }
  }
  return 0;
}

