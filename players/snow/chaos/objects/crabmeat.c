/* Heal found on ~/chaos/mon/crab.c */
/* Weight is less than normal due to this being found on a monster
 * plus the tox is 30. Number of uses has same rationale. If
 * this item becomes popular, I will change it. -Snow */

#define TP this_player()
#define TO this_object()

int bites;

id(str) { return str == "crab meat" || str == "crabmeat" ||
                 str == "slab"; }
short() { return "A slab of giant crabmeat"; }
long() {
  write("This is a slab of crabmeat taken from the corpse of a\n"+
        "giant crab. There appear to be "+bites+" bites left.\n");
  return 1;
}

drop() { return 0; }
get() { return 1; }
query_weight() { return 3; }

reset() {
  bites = 10;
}

init() {
  add_action("meat_eat","eat");
}

meat_eat(str) {
  if(!str) { write("Eat what?\n"); return 1; }
  if(str == "crabmeat" || str == "crab meat" || str == "slab") {
    if(!TP->eat_food(30)) {
      write("You are too full to eat that much!\n");
      return 1;
    }
  if(bites == 10) {
    write_file("/players/snow/log/heals",ctime(time())+" "+
          this_player()->query_real_name()+" ate some chaos crab meat.\n");
  }
  write("You devour the delicious crabmeat!\n");
  bites --;
  TP->heal_self(35);
  write("    HP ["+TP->query_hp()+"]  SP ["+TP->query_sp()+"]\n");
  if(bites < 1) {
    write("You finished the crabmeat!\n");
    transfer(this_object(),"/players/snow/storage.c");
    return 1;
  }
  write("  There are "+bites+" bites left.\n");
  return 1;
  }
}

query_save_flag() { return 1; }
