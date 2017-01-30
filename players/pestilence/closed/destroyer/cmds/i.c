#include "/players/pestilence/define.h"
string check_heavy(object ob);

status main(string str) {
  object obj;
  object gob;
  int i;
  i = 1;
  gob = present("destroyer_ob", this_player());
  obj = first_inventory(this_player());
  if(!obj) {
    write("You are carrying nothing.\n");
    return 1;
  }
  write("\n"+YEL+"<~~~~~~~~~~~~~~~~~~~~~~>Army of Pestilence<~~~~~~~~~~~~~~~~~~~~~~>"+NORM+"\n"+
        pad("  WEIGHT",20)+"ITEM\n\n");
  while (obj) {
    if((string)obj->short())
                        if(obj->armor_class()){  write("< "+pad(check_heavy(obj)+" >",16)+ 
      (string)obj->short()+HIR+" <"+obj->query_type()+">"+NORM+"\n"); }
                        else if(obj->weapon_class()){ write("< "+pad(check_heavy(obj)+" >",16)+ 
      (string)obj->short()+HIK+" <Weapon>"+NORM+"\n"); }
                        else write("< "+pad(check_heavy(obj)+" >",16)+ 
      (string)obj->short()+"\n"); 
    obj = next_inventory(obj);

  }
  write("\n"+YEL+"<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>"+NORM+"\n");
  return 1;
}

check_heavy(object ob) {
  int w;
  string mess;
  w = (int)ob->query_weight();
  if(w < 1) mess = "No Weight ";
  if(w == 1 || w == 2) mess = "Very Light";
  if(w == 3 || w == 4) mess = "Light     ";
  if(w == 5 || w == 6) mess = "Heavy     ";
  if(w >= 7) mess = "Very Heavy";
  return mess;
}
