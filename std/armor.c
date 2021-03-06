inherit "/obj/objtracker.c"; /* 07/04/06 Earwax */
#include "/obj/clean.c"


/*
 * This file defines a general purpose armor. See below for configuration
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

/* Change History:
 * 10/17/05 Earwax: Added support for multiple-slot armors.
 */

string name, alias, short_desc, long_desc;
int worn_tag_short_flag;
int buy_value,value, weight;
string type, protect, special;
int size, save_flag, worn, ac, res;
status silently;
object worn_by;
object next;
string info;
int ac_hold,broke,set_ac_flag;
string *multipleIds;
string *Types;                /* Support multi-slot armors */
mixed *params;

mapping enchantments;

/* added for donated armors at the green. Fred [7.28.06] */
static int donated_item;


query_guild_bonus() { }
remove_guild_bonus() { }
add_guild_bonus() { }

reset(arg)
{
  if(arg) return;
  type = "armor";
  Types = ({ "armor" });
  protect = "physical";
  special = "do_special";
}


init()
{
  objtracker_init_check(); /* 07/04/06 Earwax */
  add_action("wear","wear");
  add_action("remove","remove");
  add_action("remove","unwear");
}


rec_short()
{
  if(next)
    return name + ", " + call_other(next, "rec_short");
  return name;
}


string enchant_shorts()
{
  string *enchants;
  string result;
  int s;
  result="";
  if(enchantments)
  {
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


/*
get_worn_flag() {
  string fl;
  switch(type) {
    case "armor": fl="on body"; break;
    case "helmet": fl="on head"; break;
    case "shield": fl="held in hand"; break;
    case "boots": fl = "on feet"; break;
    case "amulet": case "misc": fl = "worn"; break;
    case "chest": fl= "on chest"; break;
    case "neck": fl="around neck"; break;
case "cloak": fl="on back"; break;
case "bracelet": fl="on wrists"; break;
case "pants": fl="on legs"; break;
case "belt": fl="around waist"; break;
case "gloves": fl="on hands"; break;
case "earrings": fl="on ear"; break;
case "ring": fl="on finger"; break;
}
if(type!="amulet" && type!="misc" && type!="misc" && type!="shield") return "worn "+fl;
else return fl;
}
*/

short()
{
  string tmp_short;
  if (!query_short())
    return 0;
  if(!this_player()) return query_short();
  tmp_short = query_short();
  if(broke) tmp_short = tmp_short + " <broken>";
  if(this_player()->is_player() && size)
  {
    if(size == 1) tmp_short = tmp_short + " (XS)";
    if(size == 2) tmp_short = tmp_short + " (S)";
    if(size == 3) tmp_short = tmp_short + " (M)";
    if(size == 4) tmp_short = tmp_short + " (L)";
    if(size == 5) tmp_short = tmp_short + " (XL)";
    if(size > 5) tmp_short = tmp_short + " (XXL)";
  }
  if (call_other(this_player(), "query_level", 0) >= 40)
  {
    tmp_short = tmp_short + " < ac " + ac + ", " +type +" >";
  }
  tmp_short+=enchant_shorts();
  if (worn)
    return tmp_short + (worn_tag_short_flag ? "" : " (worn)"); 
  return tmp_short;
}


enchant_long()
{
  int s;
  string *enchants;
  if(enchantments)
  {
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


/* Show armor type(s) as well - Earwax */
long(str)
{
  string tmp_long;
  int i, siz;

  tmp_long="";
  if(this_player()->is_player() && size)
  {
    if(size == 1) tmp_long = tmp_long + " [XS]";
    if(size == 2) tmp_long = tmp_long + " [S]";
    if(size == 3) tmp_long = tmp_long + " [M]";
    if(size == 4) tmp_long = tmp_long + " [L]";
    if(size == 5) tmp_long = tmp_long + " [XL]";
    if(size > 5) tmp_long = tmp_long + " [XXL]";
  }
  write(long_desc);
  enchant_long();
  if(size) write("Size: "+tmp_long+"\n");
  if(donated_item) write("This piece of armor was donated.\n");
  if(!this_object()->query_save_flag())
  {
    write("This armor is Saveable.\n");
  }
  else
  {
    write("This armor is Non-Saveable.\n");
  }

  siz = sizeof(Types);
  if (siz)
  {
    if (siz == 1)
    {
      write("This armor is type "+Types[0]+".\n");
      return;
    }

    write("This armor is of types: "+implode(Types, ", ")+".\n");
  }
}


id(str)
{
  if(!multipleIds) multipleIds = ({ });
  return str == name  ||
         str == alias ||
         str == type  ||
         member_array(str, multipleIds) > -1 ||
         member_array(str, Types) > -1;
}


query_type()
{
/* Don't need this, I think - Earwax
if (sizeof(Types))
  return Types;
*/

  return type;
}


query_value(arg)
{
  if(broke) return 0;
  if(donated_item) return 0;
  if(!arg)
    return value;
  if(arg == 1) return value;
  if(buy_value && arg==2) return buy_value;
}


query_worn() { return worn; }

query_name() { return name; }

armor_class() { return ac; }

wear(str)
{
  object nw, ob;
  object guild, invob;        /* For paladin additions */
  int tmp;

  if(!str)
  {
    notify_fail("Wear what?\n");
    return 0;
  }

  if (!id(str))
  {
    notify_fail("You may only wear \""+name+"\".\n");
    return 0;
  }
  if (environment() != this_player())
  {
    notify_fail("You must get it first!\n");
    return 0;
  }
/* Rather than play around with all params on broken armor
   simply make it unusable
 */
  if(broke)
  {
    notify_fail("The broken armor won't stay on your body.\n");
    return 0;
  }
  if(nw=present("notarmor",this_player()))
  {
    if(!nw->display_notarmor_msg())
      write("For some reason you are unable to wear armor.\n");
    return 1;
  }
  if (worn)
  {
    notify_fail("You already wear it!\n");
    return 0;
  }
  if(size)
  {
    tmp=find_size(this_player());
    if(tmp > size)
    {
      notify_fail("You find that it is too small for you.\n");
      return 0;
    }
    if(tmp < size - 1)
    {
      notify_fail("It is far to big for you, it simply falls off.\n");
      return 0;
    }
    if(tmp < size)
      write("It's a little big but you can wear it.\n");
  }
  next = 0;
/* BEGIN PALADIN ADDITION */
/* If the paladin has an off-wielded weapon they cannot wear shields! */
/* no need to do this except with shield - Ill */
  if(type=="shield")
  {
    invob = first_inventory(this_player());
    while(invob)
    {
      if(invob->query_offwielded())
      {
        notify_fail("You have an offwielded weapon!\n");
        return 0;
      }
      invob = next_inventory(invob);
    }
  }
/* END PALADIN ADDITION */
  if(!protect)
    protect = "physical";
  if(!special)
    special="do_special";
  if(!params || member_array(protect,params)==-1)
    set_params(protect,ac,res,special);

  ob = call_other(this_player(), "wear", this_object(), silently, type, params);
  if(ob)
  {
    worn_by = this_player();
    worn = 1;
    if(query_guild_bonus() && this_player())
      add_guild_bonus();
    return 1;
  }
  write("You are already wearing an armor of type " + type + ".\n");
  return 1;
}


get() { return 1; }

drop(silently)
{
  if(worn)
  {
    if(worn_by)
      call_other(worn_by, "stop_wearing", this_object(), type);
    worn = 0;
    worn_by = 0;
    if(query_guild_bonus() && this_player()) remove_guild_bonus();
    if(!silently)
      tell_object(environment(this_object()),"You drop your worn armor.\n");
  }
  return 0;
}


remove(str)
{
  if(!str)
  {
    notify_fail("Remove what?\n");
    return 0;
  }
  if(!id(str))
  {
    notify_fail("You may only remove \""+str+"\"\n");
    return 0;
  }
  if(!worn)
  {
    notify_fail("You aren't wearing \""+str+"\"\n");
    return 0;
  }
  call_other(worn_by, "stop_wearing", this_object(), type, silently);
  if(query_guild_bonus() && this_player())
    remove_guild_bonus();
  worn_by = 0;
  worn = 0;
  return 1;
}


query_weight() { return weight; }

set_id(n) { name = n; }
set_name(n) { name = n; }
set_short(s) { short_desc = s; if(!long_desc) long_desc = s+".\n"; }
set_value(v) { value = v; }
set_buy_value(v) { buy_value = v; }
set_weight(w) { weight = w; }
set_ac(a)
{
  if(broke) return 0;
  ac = a;
  set_ac_flag = 7;
}


set_res(a){ res = a;  }
set_special(a){ special = a; }
/* Left in for backwards compatibility.
   Do not use when making new items
   for non-physical defense, call set_params directly
*/
set_protect(a){ protect = a; }

set_silently(a){ silently = a; }

set_alias(a) { alias = a; }
set_long(l) { long_desc = l; }
set_type(t)
{
/*
   if (ac > 0 || !set_ac_flag) {
    if (t !="armor" && t !="helmet" && t != "boots" && t != "ring" && t !="amulet" && t != "shield" && t != "misc")
    destruct (this_object());
     }
*/
  type = t;
  Types = (                   /* Earwax: support for multi-slot armors */
  {
    t
  });
}


/* ***** Multi-slot Support Funs ***** */
query_types() { return Types; }

void
add_type(string t)
{
  int x, y;
  x = 0;
  if ( (t == "ring" || t == "earring") && (y = sizeof(Types)) )
  {
    while (y--)
    {
      if ( Types[y] == t ) x++;
    }
    if ( x == 1 ) Types += ({ t });
  }
  if (member_array(t, Types) < 0) Types += ({ t });
}

void set_types(string *types) { Types = types; }

add_types(t)
{
  if (pointerp(t)) Types += t;
  else
  if (stringp(t)) Types += ({ t });
}


remove_types(t)
{
  if (!Types || !sizeof(Types)) return;
  if (pointerp(t)) Types -= t;
  else Types -= ({ t });
}


/* ****** End multi-slot stuff ***** */

set_arm_light(l) { set_light(l); }
set_info(i)
{
  info = i;
}


query_info()
{
  return info;
}


take_off()
{
  worn_by = this_player();
  worn_by = 0;
  if(query_guild_bonus() && this_player()) remove_guild_bonus();
  worn = 0;
  return 1;
}


save_thing(str)
{
  save_object(str);
  return 1;
}


restore_thing(str)
{
  restore_object(str);
  return 1;
}


set_save_flag(arg)
{
  save_flag = 1;
  if(arg > 0) save_flag = arg;
}


set_size(arg)
{
  size = arg;
}


query_size() { return size; }
find_size(plob)
{
  int hf,pr,hi,we,sizew,sizeh,sizea;
  string ge;
  hf=plob->query_phys_at(1);
  hi=plob->query_phys_at(2);
  we=plob->query_phys_at(3);
  ge=plob->query_gender();
  if((int)plob->query_pregnancy())
    pr=(int)plob->query_age()-(int)plob->query_pregnancy();
  if(ge == "male" || ge == "creature")
  {
    if(hf == 7) sizeh = 50;
    if(!sizeh && hf == 6 && hi > 6) sizeh = 45;
    if(!sizeh && hf == 6 && hi < 7) sizeh = 40;
    if(!sizeh && hf == 5 && hi > 6) sizeh = 30;
    if(!sizeh && hf == 5 && hi > 0) sizeh = 20;
    if(!sizeh) sizeh = 10;

    if(we > 300) sizew = 60;
    if(!sizew && we > 275) sizew = 60;
    if(!sizew && we > 230) sizew = 50;
    if(!sizew && we > 190) sizew = 40;
    if(!sizew && we > 150) sizew = 30;
    if(!sizew && we > 110) sizew = 20;
    if(!sizew) sizew = 10;
  }
  if(ge == "female")
  {
    if(hf > 6) sizeh = 50;
    if(!sizeh && hf == 5 && hi > 9) sizeh = 40;
    if(!sizeh && hf == 5 && hi > 2) sizeh = 30;
    if(!sizeh && hf == 5 && hi < 3) sizeh = 20;
    if(!sizeh) sizeh = 10;

    if(we > 300) sizew = 70;
    if(!sizew && we > 250) sizew = 55;
    if(!sizew && we > 250) sizew = 55;
    if(!sizew && we > 220) sizew = 52;
    if(!sizew && we > 200) sizew = 50;
    if(!sizew && we > 160) sizew = 40;
    if(!sizew && we > 130) sizew = 30;
    if(!sizew && we > 100) sizew = 20;
    if(!sizew) sizew = 10;
  }
  if(pr)
  {
    if(pr > 3000) sizew +=10;
    if(pr > 8100) sizew +=10;
    if(pr > 13000) sizew +=10;
  }
  sizea = (sizeh + 2*sizew)/3;
/*
    write(sizeh+"-"+sizew+"-"+sizea+"-"+ge+"-"+hf+"-"+hi+"-"+we+"\n");
*/
  if(sizea > 59) sizea = 6;
  if(sizea > 49) sizea = 5;
  if(sizea > 39) sizea = 4;
  if(sizea > 29) sizea = 3;
  if(sizea > 19) sizea = 2;
  if(sizea > 9) sizea = 1;
  if(sizea > 6) sizea = 1;
  return sizea;
}


query_save_flag()
{
/* upped armor that can be saved, cant save broken -Bp 6-nov-02 */
  if(ac >2)
  {
    if(type != "helmet" && type != "armor" && type != "shield")
      return 1;
  }
  if(ac > 5) return 1;
  if(broke) return 1;
  if(donated_item) return 1;
/* can't save enchanted armor - illarion 5 dec 04 */
/* this isn't critical as the mapping won't save anyway but could
   be used to clear a curse-type enchant */
/* make them save
  if(enchantments && sizeof(enchantments)) return 1;
-verte */
  return save_flag;
}


/* Calls a wizard defined function */
call_armor_special(owner)
{
  int bonus;

  bonus=call_other(this_object(),"do_special",owner);
  if(next)
    bonus+=next->call_armor_special(owner);
  return bonus;
}


set_params(style,class,res2,special2)
{
  string cat, subcat;
  int i;
  if(!params) params = ({ });
  if(sscanf(style, "%s|%s",cat,subcat) !=2)
  {
    if(style != "physical" && style != "magical") style = "physical";
  } else if(cat != "other")
  style = "physical";
  if((i=member_array(style,params)) != -1)
  {
    params[i+1] = class;
    params[i+2] = res2;
    params[i+3] = special2;
  } else
  params += ({style,class,res2,special2});
}


is_armor() { return 1; }
query_long() { return long_desc; }
armor_breaks()
{
  if(broke) return 1;
  if(worn)
  {
    if(worn_by)
      tell_object(worn_by,"Your "+name+" breaks and falls off your body.\n");
    remove(name);
  }
  broke = 1;
/* not needed as broken armor can't be worn
ac_hold = ac;
ac = 0;
if(!protect) protect = "physical";
if(!special) special = "do_special";
set_params(protect,ac,res,special);
*/
  return 1;
}


fix_armor()
{
  if (!broke)
  {
    return 0;
  }
  if(broke == 7)
  {
    write("This armor cannot be repaired, it is too badly damaged.\n");
    return 2;
  }
  broke = 0;
/* not needed as broken armor can't be worn
ac = ac_hold;
if(!protect) protect = "physical";
if(!special) special = "do_special";
set_params(protect,ac,res,special);
*/
  return 1;
}


query_broke() { return broke; }
query_worn_by() { return worn_by; }

void SetMultipleIds(string *x)
{
  multipleIds = x;
}


string * QueryMultipleIds()
{
  return multipleIds;
}


query_params() { return params; }

int add_enchantment(string name, string short_desc, string long_desc, int amt,
string dtype, int seconds, int hits, string fun, object ob, int res)
{
  if(!enchantments)
    enchantments=([]);
  if(!name)
    return 0;
  if(enchantments[name])
    return -1;
  enchantments[name]=({short_desc,long_desc,amt,dtype,seconds?time()+seconds:0,hits,fun,ob,res}
  );
/* the dtype for the enchantment must be in the armor params to do anything */
  if(!params)
    params=({});
  if(member_array(dtype,params)==-1)
    params+=({dtype,0,0,0});
  return 1;
}


int remove_enchantment(string name)
{
  if(!enchantments)
    enchantments=([]);
  if(enchantments[name])
  {
    enchantments=m_delete(enchantments,name);
    return 1;
  } else
  return 0;
}


mixed *query_enchantment(string name)
{
  if(!enchantments)
    enchantments=([]);
  return enchantments[name];
}


mixed *query_enchantments()
{
  if(enchantments && sizeof(enchantments))
    return keys(enchantments);
  return 0;
}


int get_enchantment_defense(object wearer,string style)
{
  string *enchants;
  int amt;
  int s;
  if(!enchantments || !sizeof(enchantments))
    return 0;
  enchants=keys(enchantments);
  s=sizeof(enchants);
  while(s--)
  {
/* check for correct dtype */
    if(enchantments[enchants[s]][3]!=style)
      continue;
/* check time limit */
    if(enchantments[enchants[s]][4] && time() > enchantments[enchants[s]][4])
    {
      enchantments=m_delete(enchantments,enchants[s]);
      continue;
    }
/* check hit limit */
    if(enchantments[enchants[s]][5])
    {
      enchantments[enchants[s]][5]--;
      if(enchantments[enchants[s]][5]<=0)
      {
        enchantments=m_delete(enchantments,enchants[s]);
        continue;
      }
    }                         /* class+100*res */
    amt=enchantments[enchants[s]][2]+(100*enchantments[enchants[s]][8]);
    if(enchantments[enchants[s]][6])
    {
      if(enchantments[enchants[s]][7])
        amt += (int)call_other(enchantments[enchants[s]][7], 
          enchantments[enchants[s]][6], wearer, this_object());
      else
        amt += (int)call_other(this_object(), enchantments[enchants[s]][6], 
          wearer, this_object());
    }
  }
  return amt;
}


query_armor() { return 1; }

query_short() { return short_desc; }

query_res() { return res; }
query_special() { return special; }

query_light(){
  return set_light(0);
}

set_donated_item(int arg){ donated_item = arg; }
query_donated_item(){ return donated_item; }
