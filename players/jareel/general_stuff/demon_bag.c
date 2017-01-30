 inherit "obj/container.c";
#define MAX 10000
#define MAX_WEIGHT 10000

id(str) { return str == "bag" || str == "demon bag"; }

 reset(arg) {
  ::reset(arg); /* changed from reset() */
    if (arg) return;
    set_name("demon bag");
    set_short("Demon hide Bag");
    set_long("A bag made from the hide of a Dark Demon.\n");
    set_weight(2);
    set_value(30000);
    set_max_weight(10000);
}
init() {
  add_action("whats_inside","baginv");
}

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

  write("Bag Inventory:\n\n"+
    "[#]\t"+pad("Name", 20)+"Type\t"+pad("Weight", 22)+"Value\n"+
    "-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-\n");
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

query_save_flag() { return 1; }
