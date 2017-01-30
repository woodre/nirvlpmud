/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Function:     Combination armor/weapon object
 *  Create Date:  2004.07.09
 *  Last Edit:    2004.07.09 -Forbin
 *  Notes:        -Idea taken from code created/modified by
 *                 Pavlik@Nirvana Orignal Copyright (c) unknown
 *                -Any item inheriting this file will function as both a
 *                 weapon and an armor
 *  Notable Changes:         
 */ 

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"

int LocalWeight;
int Broken;
int WeaponClass;
int EffWeaponClass;
int Hits;
int Misses;
int ArmorClass;
int Res;
int SetAcFlag;
int Value;
int WornWield;
int Size;
int SilentWield;
int ArmorClassHold;
int SaveFlag;
status Silently;
string *MessageHit;
string *MultipleIDs;
string Name;
string AliasName;
string AltName;
string Info;
string LongDesc;
string ShortDesc;
string Protect;
string Special;
string ArmorType;
string WeaponType;
string ReadMsg;
string Special;
string WieldFuncFn;
string HitFuncFn;
object WornWieldBy;
object WieldFunc;
object HitFunc;
object Next;
mixed *Params;

query_guild_bonus() { }

remove_guild_bonus() { }

add_guild_bonus() { }

reset(arg) {
  if(arg) return;
  ArmorType = "armor";
  Protect = "physical";
  Special = "do_special";  
  WornWield = 0;
  Value = 0;
  MessageHit = ({
    "massacre"," to small fragments",
    "smashed"," with a bone crushing sound",
    "hit"," very hard",
    "hit"," hard",
    "hit","",
    "grazed","",
    "tickled"," in the stomach" });
}

init() {
  if(ReadMsg) { add_action("read"); add_verb("read"); }
  add_action("wear"); add_verb("wear");
  add_action("remove"); add_verb("remove");
  add_action("remove"); add_verb("unwear");
}

rec_short() {
  if(Next)
	return Name + ", " + call_other(Next, "rec_short");
  return Name;
}

short() {
  string tmp_short;
  if(!ShortDesc) return 0;
  tmp_short = ShortDesc;
  if(this_player()->is_player() && Size) {
    if(Size == 1) tmp_short = tmp_short + " (XS)";
    if(Size == 2) tmp_short = tmp_short + " (S)";
    if(Size == 3) tmp_short = tmp_short + " (M)";
    if(Size == 4) tmp_short = tmp_short + " (L)";
    if(Size > 4) tmp_short = tmp_short + " (XL)";
  }
  if(call_other(this_player(), "query_level", 0) > 30) {
    tmp_short = tmp_short+" < ac "+ArmorClass+", "+ArmorType+" >";
  }
  if(call_other(this_player(), "query_level", 0) > 30) {
    tmp_short = tmp_short+" < wc "+WeaponClass+"/"+EffWeaponClass+", "+WeaponType+" >";
  }
  if(WornWield) {
       tmp_short = tmp_short + " (worn)";
  }
  if(Broken) {
       tmp_short = tmp_short + " [BROKEN]";
  }
  return tmp_short;
}

long(str) {
  int wear;
  write(LongDesc);
  write("It is ");
  wear = query_wear();
  if(wear < 40) write("like new.\n");
  if(wear > 39 && wear < 100) write("a little worn.\n");
  if(wear > 99 && wear < 200) write("somewhat worn.\n");
  if(wear > 199 && wear < 400) write("worn.\n");
  if(wear > 399) write("well worn.\n");
  if(this_player()->query_level() > 39) {
    write("Wear = "+wear+"  Hits = "+Hits+"  Misses = "+Misses+"\n");
  }
}

id(str) {
 if(!MultipleIDs) MultipleIDs = ({ });
    return (str == Name || str == AliasName || str == AltName || 
            str == ArmorType || member_array(str, MultipleIDs) > -1);
}

query_name() { return Name; }
set_name(n) { Name = n; }
set_alt_name(n) { AltName = n; }
set_alias(n) { AliasName = n; }

set_armor_type(n) { ArmorType = n; }
set_weapon_type(n) { WeaponType = n; }

weapon_class() { return WeaponClass; }
set_class(c) { WeaponClass = c; }
armor_class() { return ArmorClass; }
set_ac(c) { ArmorClass = c; }
set_res(a) { Res = a; }
set_special(a) { Special = a; }
set_protect(a) { Protect = a; }

set_silently(a) {Silently = a; }

query_type() { return ArmorType; }

set_hit_func(ob) { 
  string junka, junkk;
  HitFunc = ob; 
  if(sscanf(file_name(ob), "%s#%s", junka, junkk) == 2)
    HitFuncFn = "/"+junka;
  else
    HitFuncFn = "/"+file_name(ob);
}

query_hit_func() { return HitFunc; }

set_wield_func(ob) {
  string junka,junkk;
  WieldFunc = ob;
  if(sscanf(file_name(ob),"%s#%s",junka,junkk) == 2)
    WieldFuncFn = "/"+junka;
  else
    WieldFuncFn = "/"+file_name(ob);
}

set_read(str) { ReadMsg = str; }
set_info(i) { Info = i; }
query_info() { return Info; }

set_id(n) { Name = n; }

set_short(s) { ShortDesc = s; LongDesc = s + ".\n"; }
set_long(l) { LongDesc= l; }

set_value(v) { Value= v; }

set_weight(w) { LocalWeight = w; }
query_weight() { return LocalWeight; }

set_arm_light(l) { set_light(l); }

set_silentwield(arg) { SilentWield = arg; }

query_wielded() { return WornWield; }

is_weapon() { return 1; }
is_armor() { return 1; }

query_long() { return LongDesc; }
query_short() { return ShortDesc; }

query_worn() { return WornWield; }
query_worn_by() { return WornWieldBy; }

SetMultipleIds(string *x) { MultipleIDs = x; }

string *QueryMultipleIds() { return MultipleIDs; }

save_thing(str){
  save_object(str);
  return 1;
}

restore_thing(str){
  restore_object(str);
  return 1;
}

set_save_flag(arg) {
  SaveFlag = 1;
  if(arg > 0) SaveFlag = arg;
}

wear(str) {
  object ob;
  object guild, invob;
  int tmp;

  if(!id(str)) return 0;
  if(environment() != this_player()) {
    write("You must get it first!\n");
	  return 1;
  }
  if(present("notarmor", this_player())) {
    if(!present("notarmor", this_players())->display_notarmor_msg())
      write("For some reason you are unable to wear armor.\n");
    return 1;
  }
  if(present("notweapon", this_player())) {
    write("For some reason you are unable to wield weapons.\n");
    return 1;
  }
  if(WornWield) {
    write("You already wear it!\n");
	  return 1;
  }
  if(!MessageHit) {
    MessageHit = ({ "massacre"," to small fragments",
                    "smashed"," with a bone crushing sound",
                    "hit"," very hard",
                    "hit"," hard",
                    "hit","",
                    "grazed","",
                    "tickled"," in the stomach" });
  }
  if(Size) {
     tmp = find_size(this_player());
     if(tmp > Size) {
       write("You find that it is too small for you.\n");
       return 1;
     }
     if(tmp < Size - 1) {
       write("It is far to big for you, it simply falls off.\n");
       return 1;
     }
     if(tmp < Size) write("It's a little big but you can wear it.\n");
  }
  Next = 0;
  invob = first_inventory(this_player());
  while(invob) {
    guild = invob->query_offwielded();
    if(guild && ArmorType == "shield") {
      write("You have an offwielded weapon.\n");
      return 1;
    }
    invob = next_inventory(invob);
  }
  if(!Protect) Protect = "physical";
  if(!Special) Special = "do_special";
  set_params(Protect, ArmorClass, Res, Special);
  ob = call_other(this_player(), "wear", this_object(), Silently, ArmorType, Params);
  if(!ob) {
    if(WieldFunc) {
	    if(!call_other(WieldFunc, "wield", this_object()))
      return 1;
    }
	  WornWieldBy = this_player();
	  WornWield = 1;
	  call_other(this_player(), "wield", this_object(), SilentWield);
	  if(query_guild_bonus() && this_player()) add_guild_bonus();
	  return 1;
  }
  write("You already have an armor of class "+ArmorType+".\n");
  return 1;
}

take_off() {
  WornWieldBy = this_player();
  WornWieldBy = 0;
  WornWield = 0;
  return 1;
}

stopwield() {
  if (environment() != this_player()) return 0;
  call_other(this_player(), "stop_wielding");
  call_other(this_player(), "stop_wearing", Name);
  WornWieldBy = 0;
  WornWield = 0;
  return 1;
}

remove(str) {
  if(!id(str)) return 0;
  if (!WornWield) { return 0; }
  call_other(WornWieldBy, "stop_wearing", this_object(), Name, Silently);
  call_other(WornWieldBy, "stop_wielding");
  WornWieldBy = 0;
  WornWield = 0;
  return 1;
}

drop(Silently) {
    if(WornWield) {
	  call_other(WornWieldBy, "stop_wearing", this_object(), Name);
	  call_other(WornWieldBy, "stop_wielding");
    WornWield = 0;
	  WornWieldBy = 0;
    WornWieldBy = 0;
    if(query_guild_bonus() && this_player()) remove_guild_bonus(); 
	  if(!Silently) tell_object(environment(this_object()), "You drop your worn armor.\n");
  }
  return 0;
}

get() { return 1; }

set_size(arg) { Size = arg; }

query_size() { return Size; }

find_size(plob) {
  int hf,pr,hi,we,sizew,sizeh,sizea;
  string ge;
  hf = plob->query_phys_at(1);
  hi = plob->query_phys_at(2);
  we = plob->query_phys_at(3);
  ge = plob->query_gender();
  pr = plob->query_pregnancy();
  if(ge == "male" || ge == "creature") {
     if(hf == 7) sizeh = 5;
     if(!sizeh && hf == 6 && hi > 6) sizeh = 5;
     if(!sizeh && hf == 6 && hi < 7) sizeh = 4;
     if(!sizeh && hf == 5 && hi > 6) sizeh = 3;
     if(!sizeh && hf == 5 && hi > 0) sizeh = 2;
     if(!sizeh) sizeh = 1;

     if(we > 250) sizew = 5;
     if(!sizew && we > 190) sizew = 4;
     if(!sizew && we > 150) sizew = 3;
     if(!sizew && we > 110) sizew = 2;
     if(!sizew) sizew = 1;
  }
  if(ge == "female") {
     if(hf > 6) sizeh = 5;
     if(!sizeh && hf == 5 && hi > 9) sizeh = 4;
     if(!sizeh && hf == 5 && hi > 2) sizeh = 3;
     if(!sizeh && hf == 5 && hi < 3) sizeh = 2;
     if(!sizeh) sizeh = 1;

     if(we > 220) sizew = 5;
     if(!sizew && we > 160) sizew = 4;
     if(!sizew && we > 130) sizew = 3;
     if(!sizew && we > 100) sizew = 2;
     if(!sizew) sizew = 1;
  }
  if(pr) {
    if(pr > 3000) sizew +=1;
    if(pr > 8100) sizew +=1;
    if(pr > 13000) sizew +=1;
  }
  sizea = (sizeh + sizew)/2;
  return sizea;
}

query_save_flag() {
  if(ArmorClass > 2) {
    if(ArmorType == "boots" || ArmorType == "ring" || ArmorType == "amulet" || ArmorType == "misc" ) return 1;
  }
  if(ArmorClass > 5) return 1;
  if(EffWeaponClass > 30) return 1;
  if(Broken) return 1;
  return SaveFlag;
}

armor_breaks() {
  if(Broken) return 1;
  Broken= 1;
  ArmorClassHold = ArmorClass;
  ArmorClass = 0;
  return 1;
}
 
fix_armor() {
  if(!Broken) { return 0; }
   if(Broken == 7) {
     write("This armor cannot be repaired, it is too badly damaged.\n");
     return 2;
   }
  Broken = 0;
  ArmorClass = ArmorClassHold;
  return 1;
  }

weapon_breaks() {
  if(Broken) return 1;
  tell_object(environment(this_object()), 
    "Your WEAPON BREAKS!!!!\n");
  set_class(WeaponClass/3);
  Broken = 1;
  command("unwear "+Name, environment(this_object()));
  command("wear "+Name, environment(this_object()));
  return 1;
}

fix_weapon() {
  if(!Broken) { return 0; }
 if(Broken == 7) {
   write("This weapon cannot be repaired, it is too badly damaged.\n");
   return 2;
  }  
  Broken = 0;
  Misses = (Misses / 2);
  set_class(3 * WeaponClass);
  Hits = (Hits / 3);
  write("Your weapon has been fixed.\n");
  return 1;
}

set_misses(arg) { Misses = arg; }
set_hits(arg) { Hits = arg; }
query_misses() { return Misses;}
query_hits() { return Hits; }

count_misses() {
  Misses += 1;
  return 1;
}

count_hit_made(w) {
  Hits += 1;
  EffWeaponClass = ((((Hits - 1) * EffWeaponClass) + w) / Hits);
  return 1;
}

query_wear() {
  int wear;
  wear = (((3 * Misses) / 2) + ((4 * Hits) / 9));
  return wear;
}

add_wear(arg) {
   int ah;
   ah = random(((arg * 9) / 4));
   Hits += ah;
   Misses = (((arg - (4 * (ah / 9))) * 2) / 3);
   if(Misses < 1) Misses = 1;
   if(Hits < 1) Hits = 1;
}

re_break() {
  Broken = 1;
  set_class(WeaponClass / 3);
  return 1;
}

hit(attacker) {
  if(HitFunc) return call_other(HitFunc, "weapon_hit", attacker);
  return 0;
}

read(str) {
  if(!id(str)) return 0;
  write(ReadMsg);
  return 1;
}

query_message_hit(tmp) {
  string *mess;
    mess = ({ MessageHit[1], MessageHit[0]} );
  if(tmp < 30) {
    mess = ({ MessageHit[3], MessageHit[2]} );
  }
  if(tmp < 20) {
    mess = ({ MessageHit[5], MessageHit[4]} );
  }
  if(tmp < 10) {
    mess = ({ MessageHit[7], MessageHit[6]} );
  }
  if(tmp < 5) {
    mess = ({ MessageHit[9], MessageHit[8]} );
  }
  if(tmp < 3) {
    mess = ({ MessageHit[11], MessageHit[10]} );
  }
  if(tmp == 1) {
    mess = ({ MessageHit[13], MessageHit[12]} );
  }
  return mess;
}

call_armor_special(owner) {
  int bonus;

  bonus = call_other(this_object(), "do_special", owner);
  if(Next) bonus += Next->call_armor_special(owner);
  return bonus;
}

set_params(style, class, res2, special2) {
  string cat, subcat;
  int i;
  if(!Params) Params = ({ });
  if(sscanf(style, "%s|%s", cat, subcat) !=2) { 
    if(style != "physical" && style != "magical") style = "physical";
  }
  else if(cat != "other") style = "physical";
  if(member_array(style, Params) != -1) {
    for(i=0; i<sizeof(Params); i++) {
      if(style == Params[i]) {
        Params[i+1] = class;
        Params[i+2] = res2;
        Params[i+3] = special2;
        return;
      }
    }
  } 
  Params += ({ style, class, res2, special2 });
}