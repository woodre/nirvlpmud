
/*
 * PALADIN WEAPON OBJECT (4/18/94)
 * Generic weapon object for creating Paladin weapons.
 * Uses weapon proficiencies and off-handed wielding
 * for use with dual weapons combat method
 */

#include "/obj/clean.c"
#define GUILD present("pro_object", this_player())
#define MIN_ALIGN 0

static status wielded;
string name_of_weapon;
static string cap_name;
int broke;
int misses,hits;
string alt_name;
string alias_name;
string short_desc;
string long_desc;
string read_msg;
int class_of_weapon;
int value;
int local_weight;
static object hit_func;
static object wield_func;
string info;
int deny_save;
static status offwielded; /* for dual weapons combat method */ 
string weapon_type;  /* for weapon proficiency */

reset(arg) {
    if (arg)
     return;
    wielded = 0; 
    offwielded = 0;
    broke = 0;
    value = 0;
    deny_save = 0;
    weapon_type = "sword";
}

id(str) {
   return str == name_of_weapon || str == alt_name || str == alias_name || 
   str == "weapon" || str == weapon_type || str == "paladin_weapon";
}

get() { return 1; }  

/*
 * Identify this weapon as capable of using weapon proficiency bonuses
 */
query_pro_weapon() { return 1; }

query_offwielded() { return offwielded; }        
query_wielded() { return wielded; }

short() {
   string tmp_short;
    if (call_other(this_player(), "query_level", 0) > 30) {
      tmp_short = short_desc+"  < wc: "+class_of_weapon+" type: "+ 
                   weapon_type+" >" ;
        if (broke) 
           tmp_short = short_desc+" [BROKEN]";
        if (wielded)
         return tmp_short+" (wielded)";
        if(offwielded)
          return tmp_short+" (off-wielded)";
      return tmp_short;
     }
     if(wielded && broke) 
        return short_desc+" [BROKEN] (wielded)";
     if(broke) 
        return short_desc+" [BROKEN]";
     if (wielded)
            return short_desc+" (wielded)";
     if(offwielded && broke)
       return short_desc+" [BROKEN] (off-wielded)";
     if(offwielded)
          return short_desc+" (off-wielded)";
     return short_desc;
}

long() {
    int wear;
    write(long_desc);
    write("It is ");
    wear = query_wear();
    if(wear < 40) write("like new.\n");
    if(wear > 39 && wear < 100) write("a little worn.\n");
    if(wear > 99 && wear < 200) write("somewhat worn.\n");
    if(wear > 199 && wear < 400) write("worn.\n");
    if(wear > 399) write("well worn.\n");
    if(this_player()->query_level() > 100) { 
       write("Wear = "+wear+"\n");
       write("Hits = "+hits+"    Misses = "+misses+"\n");
    }
}

init() {
    if(read_msg) 
      add_action("read","read");
    add_action("offwield","wield2");
    add_action("offwield","offwield");
    add_action("stopoffwield","unwield2");
    add_action("stopoffwield","unoffwield");
    add_action("wield"); add_verb("wield");
    add_action("stopwield"); add_verb("unwield");
}

read(str) {
    if (!id(str))
        return 0;
    write(read_msg);
    return 1;
}

wield(str) {
    if(!id(str))
        return;
    if(environment() != this_player()) {
        write("You must get it first!\n"); 
        return 1;
    }
    if(wielded || offwielded) {
        write("You already wield it!\n");
        return 1;
    }
    if(wield_func)
        if(!call_other(wield_func,"wield",this_object())) 
            return 1;
    this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    return 1;
}

/*
 * If person is wearing a shield they cannot
 * do an off-handed wield
 */

offwield(str) {
   object shield;
   object invob, guild;
   
   if(!id(str))
     return;
   if(!GUILD)
     return;
   if(environment() != this_player()) {
     write("You must get it first!\n"); 
     return 1;
   }
   if(!wielded && !offwielded) {
     if(wield_func)
       if(!call_other(wield_func,"wield",this_object())) 
         return 1;
     invob = first_inventory(this_player());
     while(invob) {
       guild = invob->query_offwielded();
       if(guild) {
         write("You are already using an off-wielded weapon.\n");
         return 1;
       }
       invob = next_inventory(invob);
     } 
     invob = first_inventory(this_player());
     while(invob) {
       shield = 0;
       shield = present("shield", this_player());
       if(shield && shield->query_worn()) {
         write("You are using a shield!\n");
         return 1;
       }
       invob = next_inventory(invob);
     }
     offwielded = 1;
     call_other(this_player(), "offwield", this_object());
     write("Ok.\n");
     return 1;
  }
  return;
}

un_wield() {
   if(wielded)
     wielded = 0;
   if(offwielded)
     offwielded = 0;
}

stopwield() {
   call_other(this_player(), "stop_wielding");
   wielded = 0;
   return 1;
}

stopoffwield() {
   call_other(this_player(), "stop_offwielding");
   offwielded = 0;
   return 1;
}

drop(silently) {
    if (wielded) {
        call_other(this_player(), "stop_wielding");
        wielded = 0;
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    if(offwielded) {
      offwielded = 0;
      call_other(this_player(), "stop_offwielding");
      if(!silently)
         write("You drop your off-wielded weapon.\n");
    }
    return 0;
}

/*
 * Some functions for extra damage
 */

hit(attacker) {
    if(hit_func)
        return call_other(hit_func,"weapon_hit",attacker);
    return 0;
}

/* Add proficiency damage..called from living.c in attack() */
proficiency_hit(ob) {
   int pro, counter, str;       
   
   if(environment(this_object())->query_alignment() < MIN_ALIGN) {
     write("[P] You are unworthy of Paladin skills!\n");
     return 0;
   }
   str = environment(this_object())->query_attrib("str");
   pro = ob->query_weapon_pro(weapon_type);
   pro = (pro*2)/5;
   counter = (str*2) + (pro*3);
   counter = random(counter);
   if(ob->query_blessed()) 
     counter += ob->query_blessed();
   if(counter <= 5) {
     write("[P] You swing wildy at your opponent.\n");
     return -10;
   } else
   if(counter <= 40) {
     return pro;
   } else
   if(counter <= 70) {
     write("[P] You skillfully attack your target.\n");
     return (pro + str/5);
   } else
   if(counter <= 85) {
     write("[P] You throw all your strength behind your blow.\n");
     return (pro + (2*str)/5);
   } else
   if(counter > 85) {
     write("[P] All your skill and strength come together for a "+ 
                                      "punishing strike!\n");
     return ((pro*3)+str)/2;
   }
   return pro;
}   

/* Dual weapons damage..also called from attack() in living.c */
dual_hit(ob) {
   int cmod, pro, dual_dam;
   
   if(environment(this_object())->query_alignment() < MIN_ALIGN) 
     return 0;
   cmod = ob->query_combat_mod("dual");
   pro = ob->query_weapon_pro(weapon_type);
   if(class_of_weapon > 18)
      class_of_weapon = 18;
   dual_dam = random(cmod/5) + random((pro * class_of_weapon)/50);
   write("[P] You strike for a second hit.\n");
   return dual_dam;
}   

/*
 * For storing weapons
 */

save_thing(str) {
   save_object(str);
   return 1;
}

restore_thing(str) {
   restore_object(str);
   return 1;
}

set_deny_save(f) { deny_save = f; }
query_deny_save() { return deny_save; }

/* can only be stored in paladin weapon lockers */
query_save_flag() { return 1; }


/*
 * Functions for breaking/fixing weapons and showing wear
 */

weapon_breaks() {
   if(broke) 
      return 1;
   tell_object(environment(this_object()), "Your WEAPON BREAKS!!!!\n");
   set_class(class_of_weapon/3);
   broke = 1;
   if(wielded) {
     command("unwield "+name_of_weapon,environment(this_object()));
     command("wield "+name_of_weapon,environment(this_object()));
   }
   if(offwielded) {
     command("unwield2 "+name_of_weapon,environment(this_object()));
     command("wield2 "+name_of_weapon,environment(this_object()));
   }
   return 1;
}

count_misses() {
   misses += 1;
   return 1;
}

count_hit_made() {
   hits += 1;
   return 1;
}

query_wear() {
   int wear;
   wear = 3*misses/2 + 4*hits/9;
   return wear;
}

fix_weapon() {
   if(!broke) 
     return 0;
   broke = 0;
   misses = misses/2;
   set_class(3*class_of_weapon);
   hits = hits/3;
   write("The weapon has been repaired.\n");
   return 1;
}

re_break() { 
   broke = 1;
   set_class(class_of_weapon/3);
   return 1;
}

query_broke() { return broke; }


/*
 * Functions for setting/querying values of weapon
 */

set_id(n) { set_name(n); }
set_alt_name(n) { alt_name = n; }  
set_alias(n) { alias_name = n; }  
set_name(n) {
    name_of_weapon = n;
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = "You see nothing special.\n";
}
query_name() { return name_of_weapon; } 

set_value(v) { value = v; }    
query_value() {
    if(broke) return 0;
    return value;
}

set_weight(w) { local_weight = w; } 
query_weight() { return local_weight; }

set_class(c) { class_of_weapon = c; }
weapon_class() { return class_of_weapon; }   

set_hit_func(ob) { hit_func = ob; }
set_wield_func(ob) { wield_func = ob; }

set_short(sh) { short_desc = sh; long_desc = short_desc+"\n";}
set_long(long) { long_desc = long; }

set_read(str) { read_msg = str; }

set_info(i) { info = i; }
query_info() { return info; }

set_weapon_type(t) { weapon_type = t; }
query_weapon_type() { return weapon_type; }


