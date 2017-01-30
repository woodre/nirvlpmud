
#include "/obj/clean.c"
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
int broke;
int silentwield;
int eff_wc;
int misses,hits;
string alt_name;
string alias_name;
string short_desc;
string long_desc;
string read_msg;
int save_flag,class_of_weapon;
int value;
int local_weight;
object hit_func;
string hit_func_fn;
object wield_func;
string wield_func_fn;
string info;
string type;
string *message_hit;

query_name() {
  if(name_of_weapon) return name_of_weapon;
  return alt_name;
 }

long() {
   int wear;
    write(long_desc);
    write("It is ");
    wear=query_wear();
    if(wear < 40) write("like new.\n");
    if(wear > 39 && wear < 100) write("a little worn.\n");
    if(wear > 99 && wear < 200) write("somewhat worn.\n");
    if(wear > 199 && wear < 400) write("worn.\n");
    if(wear > 399) write("well worn.\n");
   if(this_player()->query_level() > 100) { write("Wear = "+wear+"\n");
    write("Hits = "+hits+"    Misses = "+misses+"\n");
   }
}

reset(arg) {
    if (arg)
     return;
    wielded = 0; value = 0;
message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});
}

init() {
    if (read_msg) {
  add_action("read", "read");
    }
  add_action("wield", "wield");
  add_action("stopwield", "unwield");
}

wield(str) {
    if (!id(str))
        return 0;
    if (environment() != this_player()) {
        /* write("You must get it first!\n"); */
        return 0;
    }
    if(!message_hit) 
    message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});
    if(present("notweapon",this_player())) {
       write("For some reason you are unable to wield this weapon.\n");
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
    call_other(this_player(), "wield", this_object(),silentwield);
    wielded = 1;
    return 1;
}


short() {
   string tmp_short;
    if (call_other(this_player(), "query_level", 0) > 30) {
      tmp_short = short_desc + "  < wc " + class_of_weapon + ","+eff_wc + " >";
   if (broke) tmp_short = short_desc + " [BROKEN]";
      if (wielded)
         return tmp_short + " (wielded)";
      return tmp_short;
     }
 if(wielded && broke) return short_desc + " [BROKEN] (wielded)";
 if(broke) return short_desc + " [BROKEN]";
    if (wielded)
        if(short_desc)
            return short_desc + " (wielded)";
    return short_desc;
}


weapon_class() {
    return class_of_weapon;
}

id(str) {
   return str == type || str == name_of_weapon || str == alt_name || str == alias_name || str == "weapon" ;
}

drop(silently) {
    if (wielded) {
        call_other(wielded_by, "stop_wielding");
        wielded = 0;
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    return 0;
}

un_wield() {
    if (wielded)
        wielded = 0;
wielded_by = 0;
}

hit(attacker)
{
    if (hit_func)
        return call_other(hit_func,"weapon_hit",attacker);
    return 0;
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
    if (!id(str))
        return 0;
    write(read_msg);
    return 1;
}

query_value() {
    if(broke) return 0;
    return value;
}

get() { return 1; }

query_weight() { return local_weight; }

set_class(c) { class_of_weapon = c; }

 
set_weight(w) { local_weight = w; }

set_value(v) { value = v; }

set_alt_name(n) { alt_name = n; }

set_hit_func(ob) {
string junka,junkk;
  hit_func = ob;
  if(sscanf(file_name(ob),"%s#%s",junka,junkk) == 2)
    hit_func_fn = "/"+junka;
  else
    hit_func_fn = "/"+file_name(ob);
}

query_hit_func() { return hit_func; }

set_wield_func(ob) {
string junka,junkk;
  wield_func = ob;
  if(sscanf(file_name(ob),"%s#%s",junka,junkk) == 2)
        wield_func_fn = "/"+junka;
  else
    wield_func_fn = "/"+file_name(ob);
}

set_alias(n) { alias_name = n; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}

set_long(long) { long_desc = long; }

set_read(str) { read_msg = str; }

set_info(i) {
    info = i;
}

query_info() {
    return info;
}
stopwield() {
    if (environment() != this_player()) return 0;
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
      if(wield_func_fn) {
        call_other(wield_func_fn, "bleechblah",0);
        wield_func = find_object(wield_func_fn);
      }
      if(wield_func_fn) {
        call_other(hit_func_fn, "bleechblah",0);
        hit_func = find_object(hit_func_fn);
      }
      return 1;
   }
set_save_flag(arg) {
save_flag = 1;
if(arg > 0) save_flag = arg;
 }
query_save_flag() {
   int add,i;
    if(class_of_weapon > 18) return 1;
/*
    while(i<5) {
    add=add+hit();
    i=i+1;
    }
    add=add/5;
    add=add+class_of_weapon;
    if(add > 25 ) return 1;
*/
if(eff_wc > 24) return 1;
if(broke) return 1;
/* dont save broken weapons. */
return save_flag;
 }
weapon_breaks(){
   if(broke) return 1;
   tell_object(environment(this_object()), "Your WEAPON BREAKS!!!!\n");
   set_class(class_of_weapon/3);
/*
  log_file("BROKE", "wear = "+query_wear()+" hits ="+hits+" miss="+misses+"\n");
*/
   broke = 1;
   if(random(100) > 84) broke = 7;
   command("unwield "+name_of_weapon,environment(this_object()));
   command("wield "+name_of_weapon,environment(this_object()));
/*
    call_other(environment(this_object()), "wield", this_object());
*/
    return 1;
 }
count_misses() {
   misses += 1;
   return 1;
 }
count_hit_made(w) {
   hits += 1;
   eff_wc=((hits-1)*eff_wc + w)/hits;
   return 1;
  }
query_wear() {
   int wear;
   wear = 3*misses/2 + 4*hits/9;
  return wear;
}
add_wear(arg) {
  int ah;
  /* too many unknowns to break down into hits and misses 
     assign a number of 'hits' */
  ah = random(arg*9/4);
  hits += ah;
  misses = (arg - 4*ah/9)*2/3;
  if(misses < 1) misses = 1;
  if(hits < 1) hits = 1;
}
fix_weapon() {
   if (!broke) {
     return 0;
   }
   if(broke == 7) {
     write("This weapon cannot be repaired, it is too badly damaged.\n");
     return 1;
   }
  broke = 0;
  misses = misses/2;
  set_class(3*class_of_weapon);
  hits = hits/3;
  write("The weapon has been fixed.\n");
  return 1;
  }
re_break() { 
   broke = 1;
   set_class(class_of_weapon/3);
  return 1;
 }

query_broke(){return broke;}
set_type(str) { type = str; }
query_type() { return type;}
set_message_hit(arr) {
   message_hit=arr;
}
query_message_hit(tmp) {
  string *mess;
    mess = ({message_hit[1],message_hit[0]});
  if (tmp < 30) {
    mess = ({message_hit[3],message_hit[2]});
  }
  if (tmp < 20) {
    mess = ({message_hit[5],message_hit[4]});
  }
  if (tmp < 10) {
    mess = ({message_hit[7],message_hit[6]});
  }
  if (tmp < 5) {
    mess = ({message_hit[9],message_hit[8]});
  }
  if (tmp < 3) {
    mess = ({message_hit[11],message_hit[10]});
  }
  if (tmp == 1) {
    mess = ({message_hit[13],message_hit[12]});
  }
  return mess;
}
set_silentwield(arg) { silentwield = arg; }
query_wielded() { return wielded; }
set_misses(arg) { 
   misses = arg;
}
set_hits(arg) { hits = arg; }
query_hits() { return hits; }
query_misses() { return misses; }
