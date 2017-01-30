#include "/players/maledicta/ansi.h"
inherit "obj/armor";
#define USER environment()
reset(arg) {
 ::reset(arg);
 if(arg) return;

}

generic_object(){ return 1; }

int spec_amt,spec_perc;
string spec_me,spec_other;
int spec_amt2,spec_perc2;
string spec_me2,spec_other2;
int dam_perc,dam_amt,dam_rand,dam_type;
string dam_me,dam_other;

set_dam_perc(int i){ dam_perc = i; }
set_dam_amt(int i){ dam_amt = i; }
set_dam_rand(int i){ dam_rand = i; }
set_dam_type(int i){ dam_type = i; }
set_dam_me(str){ dam_me = str; }
set_dam_other(str){ dam_other = str; }

query_dam_perc(){ return dam_perc; }
query_dam_amt(){ return dam_amt; }
query_dam_rand(){ return dam_rand; }
query_dam_type(){ return dam_type; }
query_dam_me(){ return dam_me; }
query_dam_other(){ return dam_other; }


set_spec_me(str){ spec_me = str; }
set_spec_other(str){ spec_other = str; }
set_spec_perc(int i){ spec_perc = i; }
set_spec_amt(int i){ spec_amt = i; }

query_spec_perc(){ return spec_perc; }
query_spec_amt(){ return spec_amt; }
query_spec_me(){ return spec_me; }
query_spec_other(){ return spec_other; }

set_spec_me2(str){ spec_me2 = str; }
set_spec_other2(str){ spec_other2 = str; }
set_spec_perc2(int i){ spec_perc2 = i; }
set_spec_amt2(int i){ spec_amt2 = i; }

query_spec_perc2(){ return spec_perc2; }
query_spec_amt2(){ return spec_amt2; }
query_spec_me2(){ return spec_me2; }
query_spec_other2(){ return spec_other2; }


do_special(owner){
int tot,damager;
object enemy;
 tot = 0;
enemy = USER->query_attack();

 if(random(100) < spec_perc && spec_amt){
   if(spec_me) tell_object(USER, spec_me+"\n");
   if(spec_other) 
    tell_room(environment(USER), spec_other+"\n", ({ USER }));
   tot += spec_amt;
   }
 if(random(100) < spec_perc2 && spec_amt2){
   if(spec_me2) tell_object(USER, spec_me2+"\n");
   if(spec_other2) 
    tell_room(environment(USER), spec_other2+"\n", ({ USER }));
   tot += spec_amt2;
   }
  if(random(100) < dam_perc && dam_amt){
   if(dam_me) tell_object(USER, dam_me+"\n");
   if(dam_other) tell_room(environment(USER), dam_other+"\n", ({ USER }));
   if(dam_rand) damager = random(dam_amt);
   else damager = dam_amt;
   if(dam_type == 1) enemy->hit_player(damager);
   if(dam_type == 2){ enemy->add_spell_point(damager); enemy->heal_self(damager); }
   }

return tot;
}
