
#include "/obj/clean.c"

/* Jedi additions */
int wep_life;
string owner;
string wep_color;

status wielded;
object wielded_by;
string name_of_weapon;
string cap_name;

int silentwield;
int eff_wc;
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
query_wear(){ return 10000; }

query_name() {
  if(name_of_weapon) return name_of_weapon;
  return alt_name;
 }

long() {
   write(long_desc);
    
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
    
    return 0;
}

get() { return 1; }

query_weight() { return 1; }

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

set_short(sh) { short_desc = sh; }

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





fix_weapon() {
 write("You cannot fix a weapon like this.\n");
 write("Consult the libraries about creating a new LightSaber.\n");
 return 1;
 }


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

