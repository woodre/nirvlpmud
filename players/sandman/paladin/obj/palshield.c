
/*
 * PALADIN SHIELD OBJECT (4/17/94)
 * Generic shield object for use with Paladins Shield & Sword
 * combat method.  Type is always shield. Ac is based on
 * the guildmembers shield & sword combat modifier
 */

#include "/obj/clean.c"
#define TELL(x) tell_object(environment(this_object()), x);
#define MIN_ALIGN 0

string name, alias, short_desc, long_desc, value, weight;
string type;
int worn, ac;
object next;
string info;

reset(arg) {
    if(arg)
	return;
    worn = 0;
}

id(str) { 
    return str == "paladin_shield" || str == name || 
    str == alias || str == type; 
}

get() { return 1; }      

query_save_flag() { return 1; } /* cannot be saved */ 

query_worn() { return worn; }      

query_paladin_shield() { return 1; } /* identify this as a paladin shield */

query_type() { return "shield"; } /* type is always shield */

rec_short() {
    if(next)
	return name+", "+call_other(next, "rec_short");
    return name;
}

short() {
  string tmp_short;
    if (!short_desc)
	return 0;
    if (call_other(this_player(), "query_level", 0) > 30) {
       tmp_short = short_desc+"  < ac "+ac+", "+type+" >";
      if (worn)
	return tmp_short+" (worn)";
	return tmp_short;
    }
    if (worn)
	return short_desc+" (worn)";
    return short_desc;
}

long(str) { 
   write(long_desc); 
   write("If you experience any problems type 'newshield'.\n");
}     

init() {
    type = "shield";
    name = "shield";
    add_action("wear"); add_verb("wear");
    add_action("remove"); add_verb("remove");
    add_action("newshield","newshield");
}

/*
 * In case of problems get new shield
 */

newshield() {
   object shield;

   shield = clone_object("players/sandman/paladin/obj/shield");
   move_object(shield, this_player());
   write("You have a new shield.\n");
   destruct(this_object());
   return 1;
}

/*
 * Does this player have an off-wielded weapon?
 * If so, do not allow player to wear
 */

wear(str) {
    object ob, invob;
    object guild;
    
    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	write("You must get it first!\n");
	return 1;
    }
    if(worn) {
       write("You already wear it!\n");
       return 1;
    }
    invob = first_inventory(this_player());
    while(invob) {
      guild = invob->query_offwielded();
      if(guild) {
	write("You have an off-wielded weapon!\n");
	return 1;
      }
      invob = next_inventory(invob);
    }
    next = 0;
    ob = call_other(this_player(), "wear", this_object());
    if(!ob) {
	worn = 1;
	return 1;
    }
    write("You already have an armor of class "+type+".\n");
    write("Worn armor "+call_other(ob,"short")+".\n");
    return 1;
}

remove(str) {
    if (!id(str))
	return 0;
    if (!worn) 
	return 0;
    call_other(this_player(), "stop_wearing",name);
    worn = 0;
    return 1;
}

drop(silently) {
    if(worn) {
      call_other(this_player(), "stop_wearing", name);
      worn = 0;
      if(!silently)
	tell_object(environment(this_object()),"You drop your worn armor.\n");
    }
    return 0;
}

/* 
 * For guildmembers ac is based on the combat modifier for shield & sword
 * combat.  Nonguildmembers get AC 0. It is a small combat shield
 * only usable by trained players. Notice lesser trained players
 * will have a -1 AC. This is due to the fact that it is used as 
 * a weapon and to parry blows. 
 */

tot_ac() {
    object guild;
    int ac_mod;
    guild = present("guild_medal", this_player());
    if(guild) {
      ac_mod = guild->query_combat_mod("shield");
      if(ac_mod <= 5)
	ac = -1;
      if(ac_mod >= 6 && ac_mod <= 12)
	ac = 0;
      if(ac_mod >= 13 && ac_mod <= 18)
	ac = 1;
      if(ac_mod > 18)
	ac = 2;
      } else {
	ac = 0;
      }
    if(next)
	return ac+call_other(next, "tot_ac");
    return ac;
}

armor_class() { return ac; }       

test_type(str) {
    if(str == "shield")
	return this_object();
    if(next)
	return call_other(next, "test_type", str);
    return 0;
}

link(ob) { next = ob; }

remove_link(str) {
    object ob;
    if (str == name) {
	ob = next;
	next = 0;
	return ob;
    }
    if (next)
	next = call_other(next, "remove_link", str);
    return this_object();
}

/*
 * Shield Bonus if using Shield & Sword combat method
 * Called from living.c in hit_player()
 */

shield_bonus(ob) {
   int cmod, bonus, luc, counter;
   
   if(environment(this_object())->query_alignment() < MIN_ALIGN) 
     return 0;
   cmod = ob->query_combat_mod("shield");
   luc = environment(this_object())->query_attrib("luc");
   bonus = cmod/4 + random(luc/5);
   counter = (luc*2) + (cmod*3);
   counter = random(counter);
   if(ob->query_blessed()) 
     counter += ob->query_blessed();
   if(counter <= 5) {
     TELL("[P] You badly misjudge the parry!\n");
     return -5;
   } else
   if(counter <= 80) {
     TELL("[P] You deflect part of your opponents blow.\n");
     return bonus;
   } else
   if(counter <= 90) {
     TELL("[P] You take the brunt of the attack on your shield.\n");
     return bonus + 4;
   } else
   if(counter > 90) {
     TELL("[P] You skillfully block your opponents attack.\n");
     return bonus + 8;
   }
   return bonus;   /* shouldn't happen */
}

/*
 * Functions set when inheriting/cloneing
 */

set_id(n) { name = n; }
set_name(n) { name = n; }
set_alias(a) { alias = a; }      
query_name() { return name; }

set_weight(w) { weight = w; }         
query_weight() { return weight; }

set_short(s) { short_desc = s; long_desc = s+".\n"; }
set_long(l) { long_desc = l; }  

set_value(v) { value = v; }
query_value() { return value; }  

set_arm_light(l) { set_light(l); }

set_info(i) { info = i; }
query_info() { return info; }


