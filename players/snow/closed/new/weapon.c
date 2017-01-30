/* GUILD WEAPON BASE */
 
inherit "/obj/weapon.c";
#include "/players/dune/closed/guild/DEFS.h"

int prof, damage;

long() {
    write(long_desc);
    if((int)TP->query_level() >= 40)
      write("Hits = "+hits+"    Misses = "+misses+"\n");
}
 
status wield(string str) {
    if (!id(str)) return 0;
    if (environment() != TP) return 0;
    if(!message_hit)
    message_hit=({"massacre"," to small fragments",
                  "smashed", " with a bone crushing sound",
                  "hit",     " very hard",
                  "hit",     " hard",
                  "hit",     "",
                  "grazed",  "",
                  "tickled", " in the stomach"});
    if (wielded) {
        write("You already wield it!\n");
        return 1;
    }
    if(!IPTP) {
      write("You are not a "+FUNKYNAME+"!\n");
      destruct(this_object());
      return 1; 
    }
    wielded_by = TP;
    call_other(TP, "wield", this_object(), silentwield);
    wielded = 1;
    return 1;
}

string short() {
  string tmp_short;
  if((int)TP->query_level() > 30) {
    tmp_short = short_desc+"  < wc "+
                class_of_weapon+","+eff_wc+" >";
    if(wielded) return tmp_short + " (wielded)";
  return tmp_short; }
  if(wielded)
    if(short_desc) return short_desc + " (wielded)";
  return short_desc;
}

status id(string str) {
   return str == WEAPON_ID || str == name_of_weapon ||
          str == alt_name  || str == alias_name ||
          str == "weapon"  || str == "pro_object"; 
}

drop(silently) {
  if (wielded) {
      call_other(wielded_by, "stop_wielding");
      wielded = 0;
    if(!silently && name_of_weapon != WEAPON_HANDS)
            write("You drop your wielded weapon.\n");
    }
  return 0;
}
 
query_pro_weapon() { return 1; }
mod_prof(int num)  { prof += num; }
set_prof(int num)  { prof = num; }
mod_damage(int num){ damage += num; }
set_damage(int num){ damage = num; }
query_prof()       { return prof; }
proficiency_hit()  { return prof; }
query_value()      { return 0; } 
query_save_flag()  { return 1; } 
count_misses()     { misses += 1; return 1; }
set_wielded(int num)      { wielded = num; }
set_wielded_by(object ob) { wielded_by = ob; }
query_type()              { return WEAPON_ID; }
