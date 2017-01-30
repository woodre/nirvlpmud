#define tp this_player()
#define NM capitalize(name)
#include "/players/pavlik/closed/colors.h"
#define MAX_WEIGHT 25
#define MAX 25

string name;
int local_weight;
int bag_weight;

reset(arg){
  if(arg) return;
  name = "boltar";
  local_weight = 0;
  bag_weight = 0;
}

id(str) { 
  return str == "bag" || str == "mbag" || str == "pouch" ||
   str == "hide" || str == name+" hide";
}

get() { return 1; }
drop() { return 0; }
can_put_and_get() { return 1; }
query_value() { return 5; }
query_save_flag() { return 0; }
set_name(str){ name = str; }
query_name(){ return name; }

query_weight() {
  return bag_weight;
}

short() { return "A bag made from "+NM+" hide"; }

long() {
  write(
  "You hold a sturdy pouch made of treated "+NM+" hide!\n"+
  "Use 'baginv' to see what's inside.\n");
  return;
}
       
init() {
  add_action("whats_inside","baginv");
}

add_weight(w) {
  if(local_weight + w > MAX_WEIGHT) return 0;
  local_weight += w;
  bag_weight += w / 8;
  if(environment()) environment()->add_weight(w / 8);
  return 1;
}

/* 
   give credit where credit is due -
   Mythos thought up the original idea behind the nice
   inventory display, which i modified greatly for this
   object.  if you want to see his original see:
   /players/mythos/prac/bag.c
*/
whats_inside() {
  object items;
  object ob;
  int i, x;
  int item_count;
  int obj_count;
  int count;
  int match;
  int total;
  int wet;

  item_count = allocate(MAX);
  items = allocate(MAX);
  obj_count = 0;

write("Bag Inventory:\n\n"+
      "[#]\t"+pad("Name", 20)+"Type\t"+pad("Weight", 12)+"Value\n"+
      "-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-\n");
  /*
   * First thing to do is build an array of items in the bag
   * and count how many of each item is present.
   */
  ob = all_inventory(this_object());

  for(i=0; i<sizeof(ob); i++) {
    match = 0;
    for(x=0; x<obj_count; x++) {
      if(ob[i]->query_name() == items[x]->query_name()) {
        item_count[x]++;
        match = 1;
      }
    }
    if(match == 0) {
      items[obj_count] = ob[i];
      item_count[obj_count] = 1;
      obj_count++;
    }
  }

  if(obj_count == 0) {
    write("The bag is empty.\n");
    return 1;
  }

  for(count=0; count<obj_count; count++) {
    write("["+item_count[count]+"]\t");
    write(pad(items[count]->short(), 20));
    if(items[count]->weapon_class()) { write("Weapon\t"); }
    else if(items[count]->armor_class()) { write("Armor\t"); }
    else if(items[count]->is_heal()) { write("Heal\t"); }
    else write("Misc\t");
    wet = items[count]->query_weight();
    if(wet > 7) write(pad("Ext. Heavy", 12));
    else if(wet > 5) write(pad("Heavy", 12));
    else if(wet > 3) write(pad("Light", 12));
    else if(wet > 1) write(pad("Very Light", 12));
    else write(pad("Weightless", 12));
    write(items[count]->query_value());
    write("\n");
  }
  if(sizeof(ob) == 1)
    write("There is 1 item inside the hide.\n");
  else
    write("There are "+sizeof(ob)+" items inside the hide.\n");

  return 1;
}

prevent_insert() { return 0; }

