#include "../DEFS.h"

/* prototype */
string check_heavy(object ob);

status main(string str) {
  object obj;
  object gob;
  gob = present(GUILD_ID, TP);
  if(!gob->item_eyes()) return 0;
  obj = first_inventory(TP);
  if(!obj) {
    write("You are carrying nothing.\n");
    return 1;
  }
  write("\n"+BOLD+"-----CyberInventory-----"+OFF+"\n"+
        pad(" WEIGHT",17)+"ITEM\n\n");
  while (obj) {
    if((string)obj->short())
      write("[ "+pad(check_heavy(obj)+" ]",12)+
      (string)obj->short()+"\n");
    obj = next_inventory(obj);
  }
  write("\n"+BOLD+"------------------------"+OFF+"\n");
  return 1;
}

check_heavy(object ob) {
  int w;
  string mess;
  w = (int)ob->query_weight();
  if(w < 1) mess = "No Weight";
  if(w == 1 || w == 2) mess = "Very Light";
  if(w == 3 || w == 4) mess = "Light";
  if(w == 5 || w == 6) mess = "Heavy";
  if(w >= 7) mess = "Very Heavy";
  return mess;
}
