/*
 * A spell to compare weapons and armor for the Bards Guild of Ryllian
 * v3.0 by Saber / Geoffrey Z.
 *
 */


compare(str)  {

object OB, OB2;
string CHECKIT, ARMOR, OBJECT, OBJECT2;
int CHECK, CHECK2, AV, AV2, GOLD, GOLD2;

  if(!str || sscanf(str, "%s %s", OBJECT, OBJECT2) < 2)  {
    write("Syntax: compare < item > < item >\n\n");
    return 1; 
        }
  
  OB = present(OBJECT, ENV);
  if(!OB)  OB = present(OBJECT, TP);

  if(!OB)  {
    write("You do not see a "+OBJECT+" here to identify.\n");
    return 1;
        }

  OB2 = present(OBJECT2, ENV);
  if(!OB2)  OB2 = present(OBJECT2, TP);

  if(!OB2)  {
    write("You do not see a "+OBJECT2+" here to identify.\n");
    return 1;
        }
  
  if(living(OB) || living(OB2))  {
    write("This spell does not work on the living.\n");
    return 1;
        }
  
  CHECK  = OB->weapon_class();     AV  = OB->armor_class();
  CHECK2 = OB2->weapon_class();    AV2 = OB2->armor_class();
  GOLD = OB->query_value();        GOLD2 = OB2->query_value(); 
            
  write("\nYou glance at "+lower_case(OB->short())+" and "+
           lower_case(OB2->short())
           +".\n");
  say(tp+" glances at "+lower_case(OB->short())+" and "+
           lower_case(OB2->short())+".\n");
  
  if(CHECK > CHECK2)  {
    write(OB->short()+" is a better weapon then "+lower_case(OB2->short())+".\n");
            }
  else if(CHECK < CHECK2) {
    write(OB2->short()+" is a better weapon then "+lower_case(OB->short())+".\n");
            }
  else {
    write(OB->short()+" and "+lower_case(OB->short())+" have equal value as weapons.\n");
            }

  if(AV > AV2)  {
    write(OB->short()+" is better armor then "+lower_case(OB2->short())+".\n");
            }
  else if(AV < AV2) {
    write(OB2->short()+" is better armor then "+lower_case(OB->short())+".\n");
            }
  else {
    write(OB->short()+" and "+lower_case(OB2->short())
    +" have equal value as armor.\n");
            }

   if(GOLD > GOLD2)  {
    write(OB->short()+" is worth more then "+lower_case(OB2->short())+".\n");
            }
  else if(GOLD < GOLD) {
    write(OB2->short()+" is worth more then "+lower_case(OB->short())+".\n");
            }
  else {
    write(OB->short()+" and "+lower_case(OB2->short())
    +" have equal value.\n");
            }
 
  write("\n");

  return 1;
        }
