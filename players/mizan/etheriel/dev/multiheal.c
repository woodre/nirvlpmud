int intox_total;
int intox_index;
int intox_final;
int power_total;
int value;
int weight;

id(str) { return str == "thermos"; }
short() { return "A multihealing thermos [" + power_total + "]"; }

reset(arg) {
  if(arg) return 0;
  this_object()->enable_commands();
}
long() {
  write("This is the describe\n");
  write("There are  [" + power_total + "] charges remaining.\n");
  write("Heal index [" + intox_total + "].\n");
}

init() {
  add_action("add_heal","add");
  add_action("slurp_me","slurp");
}

get() { return 1; }
query_weight() { return 2; }
query_save_flag() { return 1; }
query_name() { return "Thermos"; }

add_heal(str) {
  if(!str) return 0;
  command(str, this_object());
  write("Absorption complete.\n");
  return 1;
}

slurp_me(arg) {
  int charge;
  if(!arg || sscanf(arg, "%d", charge) != 1) return 0;
  if(charge < 0 || charge > 330) return 0;
  if(charge > power_total) {
    write("You only have [" + power_total + "] charges left!\n");
    return 1;
  }
  if(!this_player(eat_food(intox_final))) {
    write("You are too full to slurp from the thermos.\n");
    return 1;
  }
  this_player()->heal_self(charge);
  return 1;
}

heal_self(arg) {
  int charge,plyr_composite;
  if(!arg || sscanf(arg, "%d", charge) != 1) return 0;
  plyr_composite=(this_player()->query_mhp() + this_player()->query_msp()) / 2;
  if(charge > plyr_composite) {
    charge = plyr_composite;
  }
  power_total = power_total + charge;
  if(power_total < 1) {
    power_total = 0;
  }
  write("[" + charge + "] charges were gained from command '" + arg +"'.\n");
}

add_hit_point(arg) {
  int charge;
  if(!arg || sscanf(arg, "%d", charge) != 1) return 0;
    if(charge < 1) {
    if(charge > this_player()->query_mhp()) {
      charge = this_player()->query_mhp();
    }
    charge = charge / 2;
    power_total = power_total + charge;
    if(power_total < 1) {
      power_total = 0;
    }
    write("[" + charge + "] charges were gained from command '" + arg +"'.\n");
  }
}

add_spell_point(arg) {
  int charge;
  if(!arg || sscanf(arg, "%d", charge) != 1) return 0;
    if(charge < 1) {
    if(charge > this_player()->query_msp()) {
      charge = this_player()->query_msp();
    }
    charge = charge / 2;
    power_total = power_total + charge;
    if(power_total < 1) {
      power_total = 0;
    }
    write("[" + charge + "] charges were gained from command '" + arg +"'.\n");
  }
}

drink_alcohol(arg) {
  int potency;
  if(!arg || sscanf(arg, "%d", potency) != 1) return 0;
    if(potency < 1) {
      potency = 0;
    }
  intox_total = intox_total + potency;
  intox_index = intox_index + 1;
  intox_final = intox_total / intox_index;
  write("The potency index of the solution is now [" + intox_final + "].\n");
}

eat_food(arg) {
  int potency;
  if(!arg || sscanf(arg, "%d", potency) != 1) return 0;
    if(potency < 1) {
      potency = 0;
    }
  intox_total = intox_total + potency;
  intox_index = intox_index + 1;
  intox_final = intox_total / intox_index;
  write("The potency index of the solution is now [" + intox_final + "].\n");
}

drink_soft(arg) {
  int potency;
  if(!arg || sscanf(arg, "%d", potency) != 1) return 0;
    if(potency < 1) {
      potency = 0;
    }
  intox_total = intox_total + potency;
  intox_index = intox_index + 1;
  intox_final = intox_total / intox_index;
  write("The potency index of the solution is now [" + intox_final + "].\n");
}

