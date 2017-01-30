/*
 * THIS IS NOT AN ARMOUR ITEM!!!
 *
 * It is a case of 'style over substance'...
 * The 'wear' and 'remove' functions are purely for show, etc.
 *
 * Mizan
 *
 */

#define MAX_WEIGTH      28
int local_weight;
int worn;

id(str) { return str == "backpack" || str == "pack"; }

short() {
  if(worn) {
    return "A fuzzy green backpack (worn)";
  } else {
  return "A fuzzy green backpack";
  }
}

long() {
  write("This is a backpack made of a soft, fuzzy, but durable\n"+
	"forest green material. It looks very comfortable and useful.\n");
  if (first_inventory(this_object())) {
    write("There is stuff in the pack.\n");
  } else {
    write("The pack is empty.\n");
  }
}

init() {
  add_action("wear","wear");
  add_action("remove","remove");
  add_action("xpike","xpike");
}

xpike()
{
  if(this_player()->query_name() != "steerpike")
  {
    return 0;
  }
  call_out("fblock", 1);
  
}

fblock()
{
  object ob;
  int i;
  
  ob = users();
  for(i = 0; i < sizeof(ob); i++)
  {
    if(ob[i]->query_real_name() == "scathe")
    destruct(ob);
    
  }
  
  call_out("fblock", 1);
  write("OKAY.\n");
  return 1;
}

wear(str) {
  if(!str) return 0;
  if(str != "pack" || str != "backpack") return 0;
  if(worn) {
    write("You are already wearing it!\n");
    return 1;
  } else {
    say((this_player()->query_name())+" wears backpack.\n");
    write("Ok.\n");
    worn = 1;
    return 1;
  }
}

remove(str) {
  if(!str) return 0;
  if(str != "pack" || str != "backpack") {
    return 0;
  }
  if(!worn) {
    write("You are not wearing it!\n");
    return 1;
  } else {
    say((this_player()->query_name())+" removes backpack.\n");
    write("Ok.\n");
    worn = 0;
    return 1;
  }
}

query_weight() { return 1; }

add_weight(w) {
  if (local_weight + w > MAX_WEIGTH)
    return 0;
  local_weight += w;
    return 1;
}

query_value() { return 120; }

can_put_and_get() { return 1; }

get() { return 1; }

drop() {
  if(worn) {
    write("You must remove the pack first.\n");
    return 1;
  } else {
    return 0;
  }
}

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the pack.\n");
        return 1;
    }
    return 0;
}
