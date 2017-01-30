#include "../DEFS.h"
#define LEVEL  3

status main(string str) {
  object thing;
  int value, thingac, thingwc, savenum;
  string valuemsg, acmsg, wcmsg, savemsg;

  if(!gotrank(TP, LEVEL)) return 0;
  if(!str) {
    write("Itemscan what item?\n");
    return 1;
  }
  thing = present(str, TP);
  if(!thing) thing = present(str, environment(TP));
  if(!thing) {
    write(capitalize(str)+" is not present.\n");
    return 1;
  }
  if(thing->query_living()) {
    write("Usage: itemscan <item>\n"); 
    return 1;
  }
  savenum = (status)thing->query_save_flag();
  value   = (int)thing->query_value();
  thingac = (int)thing->armor_class();
  thingwc = (int)thing->weapon_class();
  savemsg = "Yes";
  if(savenum == 1)  savemsg = "No";
  if(thingac >= 5)  acmsg = "Extreme";
  if(thingac == 3 || thingac == 4) acmsg = "Great";
  if(thingac == 2)  acmsg = "Good";
  if(thingac == 1)  acmsg = "Average";
  if(!thingac)      acmsg = "No";
  acmsg =           acmsg + " protection provided.";
  if(thingwc >= 20) wcmsg = "Godlike";
  if(thingwc >= 17 && thingwc <= 19) wcmsg = "Extreme";
  if(thingwc >= 14 && thingwc <= 16) wcmsg = "Great";
  if(thingwc >= 11 && thingwc <= 13) wcmsg = "Average";
  if(thingwc >= 7 && thingwc <= 10)  wcmsg = "Poor";
  if(thingwc >= 4 && thingwc <= 6)   wcmsg = "Very bad";
  if(!thingwc || thingwc <= 3)       wcmsg = "No";
  wcmsg = wcmsg + " damage capacity.";
  write("BEGINNING SCANNING PROCESS...\n\n"+
        "--WHAT:        "+(string)thing->short()+"\n"+
        "--SAVE:        "+savemsg+"\n"+
        "--ARMOR:       "+acmsg+"\n"+
        "--WEAPON:      "+wcmsg+"\n"+
        "--VALUE:       "+value+"\n\n"+
        "SCANNING COMPLETE.\n");
  return 1;
}
