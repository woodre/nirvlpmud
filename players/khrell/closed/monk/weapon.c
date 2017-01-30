
#include "/obj/clean.c"

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
int ac;
object hit_func;
object wield_func;
string info;

query_name() { return name_of_weapon; }

long() {
    write(long_desc);
}

reset(arg) {
    if (arg)
     return;
    wielded = 0; value = 0;
}

init() {
    if (read_msg) {
        add_action("read"); add_verb("read");
    }
 add_action("wield","wield");
 add_action("stopwield","unwield");
}

wield(str) {
    if (!id(str))
        return 0;
    if (environment() != this_player()) {
        return 0;
    }
    if (wielded) {
        return 1;
    }
 if(this_object()->query_name() == "Monk's Staff")
   this_object()->adjusts();
    if(wield_func)
        if(!call_other(wield_func,"wield",this_object())) 
            return 1;
    wielded_by = this_player();
    wielded = 1;
    call_other(this_player(), "wield", this_object());
    return 1;
}


short() {
   string tmp_short;
    if (call_other(this_player(), "query_level", 0) > 30) {
      tmp_short = short_desc + "  < wc " + class_of_weapon + " >";
      if (wielded)
         return tmp_short + " (wielded)";
      return tmp_short;
     }
    if (wielded)
        if(short_desc)
            return short_desc + " (wielded)";
    return short_desc;
}


weapon_class() {
    return class_of_weapon;
}

id(str) {
   return str == name_of_weapon || str == alt_name || str == alias_name || str == "weapon" ;
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
    return value;
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

set_info(i) {
    info = i;
}

query_info() {
    return info;
}
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
set_save_flag() {
save_flag = 1;
 }
query_save_flag() {
return save_flag;
 }
