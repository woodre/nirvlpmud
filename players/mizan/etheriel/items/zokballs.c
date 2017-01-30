#define MAX_WEIGTH 5
inherit "obj/armor";

int local_weight;
int drinks;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  drinks = 16;
  set_name("camelbak");
  set_value(6001);
  set_ac(1);
  set_weight(1);
  set_type("misc");
  set_alias("waterbag");
}

init() {
  add_action("drinkme","sip");
}

clean_up() { return 1; }

long() {
  write("This is a funky plastic waterbag that you wear on your back\n"+
  "like a camel. It was meant for mountain biking but has been adapted\n"+
  "for variable-gravity use in the Plane of Etheriel. It has a neoprene\n"+
  "cover in a black and white cow-pattern, and a one-way valve for the\n"+
  "mouth hose.\n"+
 "");
  if(drinks) {
    write("There are [" + drinks + "] sips of bug juice left in the camelbak.\n"+
    "('sip juice').\n");
  }
  if(first_inventory(this_object())) write("There are things in the pocket.\n");
  else write("You can put things in the camelbak.\n");
}

add_weight(w) {
  if (local_weight + w > MAX_WEIGTH) return 0;
  local_weight += w;
  return 1;
}

short() {
  if(worn) {
    return "A Camelbak waterbag [" + drinks + "] (worn)";
  }
  return "A Camelbak waterbag [" + drinks + "]";
}


can_put_and_get() { return 1; }

get() { return 1; }

query_save_flag() { return 1; }

prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in the pocket.\n");
    return 1;
  }
  return 0;
}

drinkme(str) {
  if(!str || str != "juice") return 0;
  if(drinks == 0) return write("The Camelbak [tm] is empty!\n");
  drinks = drinks -1;
  if(!this_player()->drink_soft(6)) return 1;
  write("You fumble with the hose, put it in your mouth and suck.\n");
  write("Bug juice comes squirting down your throat and you feel refreshed.\n");
  say((this_player()->query_name()) + " sucks down some bug juice from a Camelbak [tm].\n");
  this_player()->heal_self(13);
  if(drinks == 0) write("You take your last sip and finish off the waterbag. Huba!\n");
  return 1;
}

