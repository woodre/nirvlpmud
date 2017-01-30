#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpl tp->query_level()
#define tpn tp->query_real_name()
#define eo environment(tp)
#define targ tp->query_attack()
#define hp tp->query_hp()
#define mhp tp->query_mhp()
#define hpp hp*100/mhp
object member;

reset(arg) { if(arg) return; 
member = ({0});
set_heart_beat(1);
}

id(str) { return str == "MASTERAIATTACK"; }


/* spells */

/* healings */

aura() {
  move_object(
    clone_object("/players/mythos/closed/AI/aura.c"),tp);
return 1; }

praise() {
   tp->heal_self(400 + random(200));
return 1; }

healer() {
   tp->heal_self(100 + random(50));
return 1; }

intake() { 
   tp->heal_self(50 + random(25));
return 1; }

lay() {
   tp->heal_self(random(25));
return 1; }

/* attacks */

/* chaos */

chaos() {    /* fight.c makes fightable area */
object victims,vic;
int h,z;  
vic = ({0});
move_object(clone_object(
            "/players/mythos/closed/AI/fight.c"),eo);
  victims = all_inventory(eo);
  victims -= ({tp});
  for(h=0;h<sizeof(victims);h++) {
    if(living(victims[h])) vic += ({victims[h]});
  }
  vic -= ({0});
  z = sizeof(vic);
       for(h=0;h,sizeof(vic);h++) {
           vic[h]->attack_object(vic[random(z)]);
       }
return 1; }

/* mass attack - non selective */

mass(int dam,arg) {
object vic;
int h;
vic = deep_inventory(eo);
for(h=0;h<sizeof(vic);h++) {
   if(living(vic[h]) && vic[h] != tp) {
     if(!arg) vic[h]->hit_player(dam);
     else vic[h]->heal_self(-dam); }
}
return 1; }

/* mass attack - selective */

mass_select(int dam,arg) {
object vic;
int h;
vic = all_inventory(eo);
for(h=0;h<sizeof(vic);h++) {
   if(living(vic[h]) && vic[h] != tp) {
     if(vic[h]->query_attack() == tp) {
      if(!arg) vic[h]->hit_player(dam);
      else vic[h]->heal_self(-dam); }}
}
return 1; }

add_occupant(ob) { member += ({ob}); }

sub_mem(ob) { member -= ({ob}); }

heart_beat() { 
int j;
  for(j=0;j<sizeof(member);j++) {
    if(member[j]) {
       if(!present("eye_power",member[j])) 
         sub_mem(member[j]);
       else {
        present("eye_power", 
        member[j])->add_cost(member[j]->query_level() +
                      random(member[j]->query_level() * 2);
        if(member[j]->query_attack()) 
        present("eye_power",member[j])->set_heart_beat(1);
       }
    } else sub_mem(member[j]);
  }
}

ray(object targ) {
if(random(2)) targ->hit_player(tpl * (4 + random(2)));
else targ->heal_self(-tpl * (4 + random(2)));
return 1; }

slash(object targ){
if(random(2)) targ->hit_player(tpl + random(2 * tpl));
else targ->heal_self(-tpl - random(2 * tpl));
return 1; }

slice(object targ){
if(random(2)) targ->hit_player(tpl + random(tpl));
else targ->heal_self(-tpl - random(tpl));
return 1; }

bite(object targ){
if(random(2)) targ->hit_player(random(tpl * 2));
else targ->heal_self(-random(tpl * 2));
return 1; }

claw(object targ){
if(random(2)) targ->hit_player(random(tpl));
else targ->heal_self(-random(tpl));
return 1; }

whip(object targ){
if(random(2)) targ->hit_player(random(tpl/2));
else targ->heal_self(-random(tpl/2));
return 1; }
