#include "base_spell.h"
string id_name, spell_desc, spell_name, *properties, spell_type;
int base_chance, spell_cost, casting_time, spell_level, needs_target;
int counter, no_attack, duration;

int ssay(object target, string mess);

int id(string str) { return str==id_name || str=="spell"; }
string short() { return spell_name; }
int long() { write(spell_name + ".\n"); }
string query_info() { return spell_desc; }

int query_spell_level() { return spell_level; }
int query_base_chance() { return base_chance; }
int query_casting_time() { return casting_time; }
int query_spell_cost() { return spell_cost; }
string query_name() { return id_name; }
int query_duration() { return duration; }
string *query_property() { return properties; }
string query_spell_type() { return spell_type; }

int abs(int x) { return ( x * ((x<0) ? -1 : 1)); }

int ssay(object targ, string mess) {
     object ob, here;
     here=environment(me);
     ob=first_inventory(here);
     while(ob) {
          if(ob!=targ)
            tell_object(ob, format(mess));
          ob=next_inventory(ob);
     }
     return 1;
}

/*
int target_still_here() {
     if(present(targ, me) || present(target, environment(caster)))
          return 1;
     tell_object(caster, "That is no longer here.\n");
     return 0;
}

int say_fail() {
     say(caster->query_name() + " gets a frustrated look on " +
         caster->query_possesive() + " face and stops casting.\n");
}
*/

object player() { return this_player(); }
