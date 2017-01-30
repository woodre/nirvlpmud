/*
 * This file defines a general purpose weapon. See below for configuration
 * functions: set_xx.
 */

/*
 * If you are going to copy this file, in the purpose of changing
 * it a little to your own need, beware:
 *
 * First try one of the following:
 *
 * 1. Do clone_object(), and then configure it. This object is specially
 *    prepared for configuration.
 *
 * 2. If you still is not pleased with that, create a new empty
 *    object, and make an inheritance of this objet on the first line.
 *    This will automatically copy all variables and functions from the
 *    original object. Then, add the functions you want to change. The
 *    original function can still be accessed with '::' prepended on the name.
 *
 * The maintainer of this LPmud might become sad with you if you fail
 * to do any of the above. Ask other wizards if you are doubtful.
 *
 * The reason of this, is that the above saves a lot of memory.
 */

status wielded;
object wielded_by;
string name_of_weapon;
string cap_name;
string alt_name;
string alias_name;
string short_desc;
string long_desc;
string read_msg;
int save_flag,class_of_weapon;
int value;
int local_weight;
object hit_func;
object wield_func;
string info;

/* nooneelse - decaying weapon stuff */
string weapon_breaks_message, decay_messages;
int chance_of_breaking, break_wc, rate_of_decay, its_broken;
int dullness, accumulated_damage, max_accumulated_damage, damage_to_wc;
/* nooneelse - end of decaying weapon stuff  */

query_name() { return name_of_weapon; }

long() {
  write(short()+".\n");
  write(long_desc);
}

reset(arg) {
  if (arg) return;
  wielded = 0;
  value = 0;
/* nooneelse - decaying weapon stuff  */
  its_broken = 0;
  chance_of_breaking = 3; /* default = 3 in 1000 */
  set_break_message("Your weapon breaks!"); /* default msg */
  rate_of_decay = 200; /* default = 1 decay per 200 hp damage done */
  max_accumulated_damage = rate_of_decay * 5; /* 5 = # of decay_messages */
  decay_messages = ({"Excellent Condition","Slightly dulled","Dull",
                     "Very dull","Almost useless","Broken"});
  dullness=1;
/* nooneelse - end of decaying weapon stuff  */
}

init() {
  if (read_msg)
    add_action("read", "read");
  add_action("wield",     "wield");
  add_action("stopwield", "unwield");
}

wield(str) {
  if (!id(str)) return 0;
  if (environment() != this_player()) {
    /* write("You must get it first!\n"); */
    return 0;
  }
  if (its_broken) {
    write("You can't wield a broken weapon!\n");
    return 1;
  }
  if (wielded) {
    write("You already wield it!\n");
    return 1;
  }
  if(wield_func)
    if(!call_other(wield_func,"wield",this_object()))
      return 1;
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object());
  wielded = 1;
  return 1;
}

short() {
  string tmp_short;
/* nooneelse - decaying weapon stuff  */
  string dullstr, cap_short_desc;
  cap_short_desc = capitalize(short_desc);
  dullstr = " (" + decay_messages[dullness-1] + ")";
  if (call_other(this_player(), "query_level", 0) > 30) {
    tmp_short = cap_short_desc + "  < wc " + class_of_weapon + " >";
    if (wielded && short_desc)
      return tmp_short + " (wielded)" + " " + dullstr;
    else
      return tmp_short + " " + dullstr;
  }
  if (wielded && short_desc)
    return cap_short_desc + " (wielded)" + " " + dullstr;
  return cap_short_desc + " " + dullstr;
/* nooneelse - end of decaying weapon stuff  */
}

weapon_class() { return class_of_weapon; }

id(str) {
    return str == name_of_weapon || str == alt_name || str == alias_name;
}

drop(silently) {
  if (wielded) {
    call_other(wielded_by, "stop_wielding");
    wielded = 0;
    if (!silently) write("You drop your wielded weapon.\n");
  }
  return 0;
}

un_wield() {
  if (wielded) wielded = 0;
  wielded_by = 0;
}

hit(attacker) {
/* nooneelse - decaying weapon stuff  */
  int this_damage;
  if(wielded_by && interactive(wielded_by)) {
    if (random(1000) < chance_of_breaking && !its_broken)
      accumulated_damage=1000;
  }
  if (hit_func)
    this_damage = call_other(hit_func,"weapon_hit",attacker) +
                  (class_of_weapon - damage_to_wc);
  else
    this_damage = class_of_weapon - damage_to_wc;
  accumulated_damage = accumulated_damage + this_damage;
  make_duller();
  if (dullness==6 && !its_broken) {
    write(weapon_breaks_message);
    set_its_broken(1);
  }
  return this_damage;
/* nooneelse - end of decaying weapon stuff  */
}

set_id(n) {
  name_of_weapon = n;
  cap_name = capitalize(n);
  short_desc = cap_name;
  long_desc = "You see nothing special.\n";
}

set_name(n) {
  name_of_weapon = n;
  cap_name = capitalize(n);
  short_desc = cap_name;
  long_desc = "You see nothing special.\n";
}

read(str) {
  if (!id(str)) return 0;
  write(read_msg);
  return 1;
}

query_value() {
/* nooneelse - decaying weapon stuff  */
  int value_level, level_percent, value_percent, v;
  value_percent = 1 - ((dullness * rate_of_decay) / max_accumulated_damage);
  v = value * value_percent;
  if (v < 0) v=0;
  return v;
/* nooneelse - end of decaying weapon stuff  */
}

get() { return 1; }

query_weight() { return local_weight; }

set_class(c) { class_of_weapon = c; }

set_weight(w) { local_weight = w; }

set_value(v) { value = v; }

set_alt_name(n) { alt_name = n; }

set_hit_func(ob) { hit_func = ob; }

set_wield_func(ob) { wield_func = ob; }

set_alias(n) { alias_name = n; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}

set_long(long) { long_desc = long; }

set_read(str) { read_msg = str; }

set_info(i) { info = i; }

query_info() { return info; }

stopwield() {
  call_other(this_player(), "stop_wielding");
  wielded = 0;
  wielded_by = 0;
  return 1;
}

save_thing(str){
  save_object(str);
  return 1;
}

restore_thing(str){
  restore_object(str);
  return 1;
}

set_save_flag() { save_flag = 1; }

query_save_flag() { return save_flag; }

/* nooneelse - decaying weapon stuff                                */
/* it has 'chance' chances in 1000 of breaking (in addition to decaying) */
set_break_chance(chance) { chance_of_breaking=chance; }

/* the message it displays when it breaks */
set_break_message(str) { weapon_breaks_message="\n"+str+"\n\n"; }

/* set the rate of decay */
set_rate_of_decay(arg) {
  rate_of_decay=arg;
  max_accumulated_damage = rate_of_decay * 5; /* 5 = # of decay_messages */
}

/* decaying weapon messages */
set_decay_array(a) {
  if (a==0)
    decay_messages = ({""});
  else
    decay_messages = a;
}

make_duller() {
  int old_dullness, damage_percent;
  old_dullness = dullness;
  if (!dullness) dullness=1;
  damage_percent = accumulated_damage / (max_accumulated_damage / 100);
  if (damage_percent <  20) { dullness=1; damage_percent=0; }
  else
  if (damage_percent <  40) { dullness=2; damage_percent=20; }
  else
  if (damage_percent <  60) { dullness=3; damage_percent=40; }
  else
  if (damage_percent <  80) { dullness=4; damage_percent=60; }
  else
  if (damage_percent <  100) { dullness=5; damage_percent=80; }
  else
  if (damage_percent >= 100) { dullness=6; damage_percent=100; }
  damage_to_wc = class_of_weapon * (damage_percent / 100);
  if (old_dullness && dullness > old_dullness)
    write("\nYour weapon is damaged somewhat.\n\n");
}

query_accumulated_damage() { return accumulated_damage; }

set_its_broken(b) {
  its_broken = b;
  if (b)
    stopwield();
  else
    class_of_weapon=break_wc; /* repair it */
}

query_break_chance() { return chance_of_breaking; }
query_its_broken() { return its_broken; }
query_rate_of_decay() { return rate_of_decay; }
/* nooneelse - end of decaying weapon stuff  */
