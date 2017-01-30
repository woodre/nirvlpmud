
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
int value, buy_value;
int local_weight;
object hit_func;
string hit_func_fn;
object wield_func;
string wield_func_fn;
string info;
string type;
string *message_hit;
string *multipleIds;
static string *wldhist;
static int histcount;

/* Added for dtypes <illarion> */
mixed *params;
status offwielded;
string offwield_desc;
/* End of added vars */

/* another addition */
static mapping enchantments; /* non-saved mods to weapon */

query_guild_bonus() { }
add_guild_bonus() { }
remove_guild_bonus() { }
query_name() {
  if(name_of_weapon) return name_of_weapon;
  return alt_name;
 }

enchant_long() {
  int s;
  string *enchants;
  if(enchantments) {
    enchants=keys(enchantments);
    s=sizeof(enchants);
    while(s--)
      if(enchantments[enchants[s]][4] && time() > enchantments[enchants[s]][4])
        enchantments=m_delete(enchantments,enchants[s]);
      else if(enchantments[enchants[s]][1])
        write(enchantments[enchants[s]][1]
             +(enchantments[enchants[s]][1][-1..-1]!="\n"?"\n":""));
  }
}
 
long() {
   int wear;
    write(long_desc);
    enchant_long();
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
        add_action("read"); add_verb("read");
    }
    add_action("wield"); add_verb("wield");
    add_action("stopwield"); add_verb("unwield");
}

/* added for dtypes  <illarion>
   Note: this function should be called by a guild object only as the
         code allows for multiple offwielded weapons.  offwielded weapons
         behave as closed to wielded weapons as possible- they take wear,
         can break, etc, are unwielded if dropped, etc
         
arguments: object  the object wielding the weapon
returns: 0 for failure, 1 for success
 */
offwield(object ob_offwielding) {
  object no_wield;
  if(!environment() || environment()!=ob_offwielding)
    return 0;
  if(offwielded || wielded)
    return 0;
  if(wield_func)
    if(!call_other(wield_func,"wield",this_object())) 
      return 0;
  if((no_wield==present("notweapon",ob_offwielding))) {
    if(!no_wield->display_notweapon_msg())
      write("For some reason you are unable to wield this weapon.\n");
    return 0;
  }
  wielded=1;
  offwielded=1;
  wielded_by=ob_offwielding;
  if(!params) set_params("physical",class_of_weapon,"hit");
  ob_offwielding->RegisterWeapon(this_object(),params);
  return 1;
}

stop_offwield() {
  wielded=0;
  offwielded=0;
  if(wielded_by)
    wielded_by->RemoveWeapon(this_object());
}

set_offwield_desc(str) {
  offwield_desc=str;
}

/* end of additions */
wield(str) {
    object no_wield;

    if (!id(str))
        return 0;
    if (environment() != this_player()) {
        /* write("You must get it first!\n"); */
        return 0;
    }
    if(!message_hit) 
    message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});
    if((no_wield=present("notweapon",this_player()))) {
        if(!no_wield->display_notweapon_msg())
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
/* modified for dtypes <illarion> */
    call_other(this_player(), "wield", this_object(),silentwield,params);
/* end of modification */
    if(query_guild_bonus() && this_player()) add_guild_bonus();
    wielded = 1;
    return 1;
}

string enchant_shorts() {
  string *enchants;
  string result;
  int s;
  result="";
  if(enchantments) {
    enchants=keys(enchantments);
    s=sizeof(enchants);
    while(s--)
      if(enchantments[enchants[s]][4] && time() > enchantments[enchants[s]][4])
        enchantments=m_delete(enchantments,enchants[s]);
      else if(enchantments[enchants[s]][0])
        result+=" "+enchantments[enchants[s]][0];
  }
  return result;
}

/* modified for dtypes.  <illarion> */
/* Rather than try to figure the original code out, totally redone */
short() {
  string tmp_short;
  if(!this_player()) return short_desc;
  tmp_short=short_desc;
  if(!tmp_short)
    tmp_short="";
  if(this_player()->query_level() > 30)
    tmp_short+= "  < wc " + class_of_weapon + ","+eff_wc + " >";
  if(broke)
    tmp_short+= " [BROKEN]";
  tmp_short+=enchant_shorts();
  if(offwielded) {
    if(offwield_desc)
      tmp_short+=" ("+offwield_desc+")";
    else
      tmp_short+= " (offwielded)";
  } else if(wielded)
    tmp_short+= " (wielded)";
  return tmp_short==""?0:tmp_short;
}
/* end of mod.  original below */
short_old() {
   string tmp_short;
    if(!this_player()) return short_desc;
  if(this_player()->query_level() > 30) {
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
   if(!multipleIds) multipleIds = ({ });
   return str == type || str == name_of_weapon || str == alt_name || str == alias_name || str == "weapon" || member_array(str, multipleIds) > -1 ;
}

drop(silently) {
/* Added for dtypes <illarion> */
    if(offwielded) {
      offwielded=0;
      wielded=0;
      if(wielded_by)
        wielded_by->RemoveWeapon(this_object());
    } else if (wielded) {
/* End of addition */
        call_other(wielded_by, "stop_wielding");
        wielded = 0;
        if(query_guild_bonus() && this_player()) remove_guild_bonus();
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    return 0;
}

un_wield() {
    if (wielded)
    {
        if(query_guild_bonus() && this_player()) remove_guild_bonus();
        wielded = 0;
     }
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

query_value(arg) {
    if(broke) return 0;
    return value;
    if(arg==2)
      return buy_value;
    return value;
}

get() { return 1; }

query_weight() { return local_weight; }

/* Modified for dtypes */
set_class(c) { 
  class_of_weapon = c; 
  set_params("physical",c,"hit");
}
query_class() {
  return class_of_weapon;
}
/* End of modification */

set_weight(w) { local_weight = w; }

set_value(v) { value = v; }
set_buy_value(v) { buy_value = v; }

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
    if(query_guild_bonus() && this_player()) remove_guild_bonus();
    write("Ok.\n");
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
/*
    if(class_of_weapon > 18) return 1;
    while(i<5) {
    add=add+hit();
    i=i+1;
    }
    add=add/5;
    add=add+class_of_weapon;
    if(add > 25 ) return 1;
*/
if(eff_wc > 30) return 1;
/* dont save broken weapons. */
if(broke) return 1;
/* don't save enchanted weapons */
if(enchantments && sizeof(enchantments)) return 1;
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
   if(wielded) {
     if(!offwielded) {
       command("unwield "+name_of_weapon,environment(this_object()));
       command("wield "+name_of_weapon,environment(this_object()));
     } else {
       wielded_by->RemoveWeapon(this_object());
       this_object()->offwield(wielded_by);
     }
   }
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
     return 2;
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
set_broke(b) { broke = b; }
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
/* Added for dtypes <illarion> */
query_offwielded() { return offwielded; }
/* end of addition */
set_misses(arg) { 
   misses = arg;
}
set_hits(arg) { hits = arg; }
query_hits() { return hits; }
query_misses() { return misses; }
is_weapon() { return 1; }
set_wep_light(int x) { set_light(x); }
query_long() { return long_desc; }

set_wielded(x) { wielded = x; }
set_wielded_by(x) { wielded_by = x; }

query_message_hit_array() {
    return message_hit; }

void SetMultipleIds(string *x)
{
 multipleIds = x;
}

string * QueryMultipleIds()
{
 return multipleIds;
}
/* added for dtypes */
set_params(style,class,special2){
   string cat, subcat;
   int i;
   if(!params) params = ({ });
   if(sscanf(style, "%s|%s",cat,subcat) !=2){ 
      if(style != "physical" && style != "magical") style = "physical";
   }
   else if(cat != "other") style = "physical";
   if(member_array(style,params) != -1){
      for(i=0;i<sizeof(params);i++){
         if(style == params[i]){
            params[i+1] = class;
            params[i+2] = special2;
            return;
         }
      }
   } 
   params += ({style,class,special2});
}
/* end of addition */

query_params() { return params; }

int add_enchantment(string name, string short_desc, string long_desc, int amt, 
                string dtype, int seconds, int hits, string fun, object ob) {
  if(!enchantments)
    enchantments=([]);
  if(!name)
    return 0;
  if(enchantments[name])
    return -1;
  enchantments[name]=({short_desc,long_desc,amt,dtype,seconds?time()+seconds:0,hits,fun,ob});
  return 1;
}

int remove_enchantment(string name) {
  if(!enchantments)
    enchantments=([]);
  if(enchantments[name]) {
    enchantments=m_delete(enchantments,name);
    return 1;  
  } else
    return 0;
}

mixed *query_enchantment(string name) {
  if(!enchantments)
    enchantments=([]);
  return enchantments[name];
}

mixed *query_enchantments() {
  if(enchantments && sizeof(enchantments))
    return keys(enchantments);
  return 0;
}

mixed *get_enchantment_damage(object attacker) {
  mixed *ret;
  string *enchants;
  int amt;
  int s;
  ret=({ ({}), ({}) });
  if(!enchantments || !sizeof(enchantments))
    return ret;
  enchants=keys(enchantments);
  s=sizeof(enchants);
  while(s--) {
    /* check time limit */
    if(enchantments[enchants[s]][4] && time() > enchantments[enchants[s]][4]) {
      enchantments=m_delete(enchantments,enchants[s]);
      continue;
    }
    /* check hit limit */
    if(enchantments[enchants[s]][5]) {
      enchantments[enchants[s]][5]--;
      if(enchantments[enchants[s]][5]<=0) {
        enchantments=m_delete(enchantments,enchants[s]);
        continue;
      }
    }
    amt=enchantments[enchants[s]][2];
    if(enchantments[enchants[s]][6]) {
      if(enchantments[enchants[s]][7])
        amt+=(int)call_other(enchantments[enchants[s]][7],enchantments[enchants[s]][6],attacker,this_object());
      else
        amt+=(int)call_other(this_object(),enchantments[enchants[s]][6],attacker,this_object());
    }
    if(amt) {
      ret[0]+=({amt});
      ret[1]+=({enchantments[enchants[s]][3]});
    }
  }
  return ret;
}

history() {
 object toaster;
 int k;
 toaster = this_player();
 if(!toaster) return 0;
 if(!toaster->is_player()) return 0;
 if(!wldhist) { 
    wldhist = ({"0","1","2","3","4","5","6","7","8","9"});
    histcount = -1;
 }
 if(histcount > -1)
   if(wldhist[histcount] = query_ip_number(toaster))
     return 1;
 histcount += 1;
 if(histcount > 8) histcount = 0;
 wldhist[histcount] = query_ip_number(toaster);
 while(k <= 8) {
  if(k != histcount)
   if(wldhist[k] == wldhist[histcount]) {
     add_wear(100);
     class_of_weapon -= 2;
   }
   k+=1;
  }
  return 1;
}
query_weapon() { return 1; }
