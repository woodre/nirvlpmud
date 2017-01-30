/* CYBERNINJA GUILD WEAPON BASE */
 
#include "/obj/clean.c"
#include "/players/snow/closed/cyber/definitions.h"
 
status wielded;
object wielded_by;
string name_of_weapon, cap_name;
int silentwield, eff_wc, misses, hits, prof;
string alt_name, alias_name, short_desc, long_desc, read_msg;
int save_flag, class_of_weapon, value, local_weight;
object hit_func, wield_func;
string info, type;
string *message_hit;
 
query_name() {
  if(name_of_weapon) return name_of_weapon;
  return alt_name; }
 
long() {
    write(long_desc);
    if(TP->query_level() > 100)
    write("Hits = "+hits+"    Misses = "+misses+"\n");
}
 
reset(arg) {
  if (arg) return;
  wielded = 0; value = 0;
  message_hit=({"massacre"," to small fragments",
              "smashed"," with a bone crushing sound",
              "hit"," very hard",
              "hit"," hard",
              "hit","",
              "grazed","",
              "tickled"," in the stomach"});
}
 
init() {
    add_action("wield", "wield");
    add_action("stopwield", "unwield");
}
 
wield(str) {
    if (!id(str))
        return 0;
    if (environment() != TP) return 0;
    if(!message_hit)
    message_hit=({"massacre"," to small fragments",
                  "smashed"," with a bone crushing sound",
                  "hit"," very hard",
                  "hit"," hard",
                  "hit","",
                  "grazed","",
                  "tickled"," in the stomach"});
    if (wielded) {
        write("You already wield it!\n");
        return 1;
    }
    if(!present("CyberNinja Implants",TP) ) {
      write("You are not a CyberNinja!\n");
      transfer(TO, "/players/snow/storage.c");
      return 1; }
    wielded_by = TP;
    call_other(TP, "wield", TO, silentwield);
    wielded = 1;
    return 1;
}
 
short() {
  string tmp_short;
  if(TP->query_level() > 30) {
    tmp_short = short_desc+"  < wc "+
                class_of_weapon+","+eff_wc+" >";
    if(wielded) return tmp_short + " (wielded)";
  return tmp_short; }
  if(name_of_weapon == "CyberNinjaHands") return;
  if(wielded)
    if(short_desc) return short_desc + " (wielded)";
  return short_desc;
}
 
weapon_class() { return class_of_weapon; }
 
id(str) {
   return str == "nwep" || str == name_of_weapon ||
          str == alt_name || str == alias_name ||
          str == "weapon" || str == "pro_object"; }

query_pro_weapon() { return 1; }
mod_prof(int num) { prof += num; }
set_prof(int num) { prof = num; }
query_prof() { return prof; }
proficiency_hit() { return prof; }
 
drop(silently) {
  if (wielded) {
      call_other(wielded_by, "stop_wielding");
      wielded = 0;
    if(!silently && name_of_weapon != "CyberNinjaHands")
            write("You drop your wielded weapon.\n");
    }
  return 0;
}
 
un_wield() {
  if(wielded) wielded = 0;
  wielded_by = 0; }
 
hit(attacker) {
  if(hit_func) return call_other(hit_func,"weapon_hit",attacker);
  return 0; }
 
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
 
query_value() { return 0; }
get() { return 1; }
query_weight() { return local_weight; }
set_class(c) { class_of_weapon = c; }
set_weight(w) { local_weight = w; }
set_alt_name(n) { alt_name = n; }
set_hit_func(ob) { hit_func = ob; }
query_hit_func() { return hit_func; }
set_wield_func(ob) { wield_func = ob; }
set_alias(n) { alias_name = n; }
set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}
set_long(long) { long_desc = long; }
 
set_info(i) { info = i; }
query_info() { return info; }
 
stopwield() {
  call_other(this_player(), "stop_wielding");
  wielded = 0;
  wielded_by = 0;
  return 1; }
 
save_thing(str){ save_object(str); return 1; }
restore_thing(str){ restore_object(str); return 1; }
 
query_save_flag() { return 1; }
 
count_misses() { misses += 1; return 1; }
count_hit_made(w) {
   hits += 1;
   eff_wc=((hits-1)*eff_wc + w)/hits;
   return 1;
  }
 
query_type() { return "nwep";}
 
set_message_hit(arr) { message_hit = arr; }
 
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
set_wielded(int num) { wielded = num; }
set_wielded_by(object ob) { wielded_by = ob; }
