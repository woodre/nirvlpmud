/*
 *  Cantrips for version 3.0 of the Bards.
 *
 */
 

cantrip(str)  {

object ob;        int COINS, ALI_CHANCE;
string CAN, CAN2;

#define CANTRIP "players/saber/closed/bard/cantrip/"

if(!str)  {

  write("\n");
  cat("/players/saber/closed/bard/CANTRIP_LIST");
  write("\n");
  return 1;
        }
 
sscanf(str, "%s %s", CAN, CAN2);      
 
 /* 29 */
        
       if(CAN == "alarm")       { CANTRIP+"alarm();           return 1; }
/*
  else if(CAN == "bauble")      { CANTRIP->bauble();          return 1; }
  else if(CAN == "bubble")      { CANTRIP->bubble();          return 1; }
  else if(CAN == "charity")     { CANTRIP->charity(CAN2);     return 1; }
  else if(CAN == "conjure")     { CANTRIP->conjure(CAN2);     return 1; }
  else if(CAN == "dance")       { CANTRIP->dance();           return 1; }
  else if(CAN == "exterminate") { CANTRIP->exterminate(CAN2); return 1; }
  else if(CAN == "firestorm")   { CANTRIP->firestorm(CAN2);   return 1; }
  else if(CAN == "fleas")       { CANTRIP->fleas(CAN2);       return 1; }
  else if(CAN == "groan")       { CANTRIP->groan();           return 1; }
  else if(CAN == "haunt")       { CANTRIP->haunt();           return 1; }
  else if(CAN == "health")      { CANTRIP->health();          return 1; }
  else if(CAN == "inform")      { CANTRIP->inform();          return 1; }
  else if(CAN == "intox")       { CANTRIP->intox();           return 1; }
  else if(CAN == "kiss")        { CANTRIP->kiss(CAN2);        return 1; }
  else if(CAN == "leap")        { CANTRIP->leap();            return 1; }
  else if(CAN == "lighten")     { CANTRIP->lighten(CAN2);     return 1; }
  else if(CAN == "mark")        { CANTRIP->mark(CAN2);        return 1; }
  else if(CAN == "pixie")       { CANTRIP->pixie(CAN2);       return 1; }
  else if(CAN == "preserve")    { CANTRIP->preserve(CAN2);    return 1; }
  else if(CAN == "potect")      { CANTRIP->protect(CAN2);     return 1; }
  else if(CAN == "rainbow")     { CANTRIP->rainbow(CAN2);     return 1; }
  else if(CAN == "spook")       { CANTRIP->spook(CAN2);       return 1; }
  else if(CAN == "strand")      { CANTRIP->strand();          return 1; }
  else if(CAN == "summon")      { CANTRIP->summon();          return 1; }
  else if(CAN == "tease")       { CANTRIP->tease(CAN2);       return 1; }
  else if(CAN == "vandalize")   { CANTRIP->vandalize(CAN2);   return 1; }
  else if(CAN == "weight")      { CANTRIP->weight(CAN2);      return 1; }
  else if(CAN == "wilt")        { CANTRIP->wilt(CAN2);        return 1; }
         
  else if(CAN == "help")        { CANTRIP->help(CAN2);        return 1; }
*/
        
  else  {
  write("\nYou know of no cantrip by that name...\n\n");
  return 1;
        }
        }
