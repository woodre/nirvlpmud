#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define to this_object()
#define eo environment(to)
#define eon eo->query_real_name()
#define eeo environment(eo)
#define targ eo->query_attack()
#define hp eo->query_hp()
#define mhp eo->query_mhp()
#define tghp  targ->query_hp()
#define tgmhp targ->query_mhp()
#define tgp tghp*100/tgmhp
#define hpp hp*100/mhp
#define Mas add_action("masterdef"
#define MASTER "/players/mythos/closed/AI/m_attack.c"
int intel;
int cost;
int anger,mss,msa,tyma,tyms;

id(str) { return str == "eye_power"; }

extra_look() { return RED+"eYeS oF FuRY"+NORM; }

drop() { destruct(to); return 0; }

get() { 
if(tp == eo) return 0;
object coin;
coin = clone_object("/obj/money.c");
coin->set_coins(random(5000));
move_object(coin,tp);
destruct(to);
return 1; }

reset(arg) { if(arg) return; intel = 0; cost = 0;
    anger = 0; msa = mss = tyms = tyma = 0;}

init() {
  if(eo == tp) {
    if(eo->is_player()) { destruct(to); return 1; }
      MASTER->add_occupant(eo);
      intel = eo->query_level();
      cost = eo->query_level() * 1000;
      anger = random(eo->query_level());
      if(random(intel) > 5) msa = intel + random(intel * 2);
      if(random(intel) > 10)mss = intel + random(intel * 3);
      if(msa) tyma = random(2);
      if(mss) tyms = random(2);
      Mas,"aura");
      Mas,"healer");
      Mas,"praise");
      Mas,"intake");
      Mas,"lay_on_hands");
      Mas,"ray");
      Mas,"slice");
      Mas,"slash");
      Mas,"bite");
      Mas,"claw");
      Mas,"whip");
  }
}

set_intel(n) { intel = n; }
query_intel() { return intel; }
query_cost() { return cost; }
add_cost(n) { cost += n; }

heart_beat() {
 if(!eo->query_attack()) set_heart_beat(0);
      /* defense */
/* aural protection */
   if(intel > random(150) && hpp > 95) {
        if(cost > 1000) {
         command("aura",eo); cost -= 1000; }
   }

/* healing */
   if(hpp < 50 && intel > random(80)) {  
     if(cost > 100) { 
         command("praise",eo); cost -= 100; }
     else if(cost > 60) {
         command("healer",eo); cost -= 60; }
     else if(cost > 40) {
         command("intake",eo); cost -= 40; }
     else if(cost > 20) {
         command("lay_on_hands",eo); cost -= 20; }
   }

    /* offense */

  /* mass attack */

/* mass attack non selective */
if(confirm()) {
   if(cost > 2000 && intel > random(120) && msa) {
     command("mass",eo); cost -= 2000; }

/* mass attack selective */

  if(cost > 1500 && intel > random(150) && mss) {
    command("mass_select",eo); cost -= 1500; }

/* chaos */

  if(confirm() > 3)
    if(anger > random(90) && cost > 1000) {
    command("chao",eo); cost -= 1000; }
}
if(cost > 500 && random(intel) > random(100)) {
         command("ray",eo); cost -= 500; }
  if(cost > 300 && intel > random(80) && tgp > random(100)){
         command("slash",eo); cost -= (150 + random(150)); }
  if(cost > 200 && intel > random(60) && tgp < random(60)) {
         command("slice",eo); cost -= 200; }
  else if(cost > 100 && intel > random(60) && tgp < 40) {
         command("bite",eo); cost -= 100; }
  else if(cost > 50 && intel > random(60) {
         command("claw",eo); cost -= 50; }
  else if(cost > 20  && intel > random(6)) {
         command("whip",eo); cost -= 20; }

}


masterdef(str) {
  if(str == "aura") MASTER->aura();
  if(str == "praise") MASTER->praise();
  if(str == "intake") MASTER->intake();
  if(str == "lay_on_hands") MASTER->lay();
  if(str == "mass") MASTER->mass(msa,tyma);
  if(str == "mass_select") MASTER->mass_select(mss,tyms);
  if(str == "choa") MASTER->chaos();
  if(str == "ray") MASTER->ray(targ);
  if(str == "slash") MASTER->slash(targ);
  if(str == "slice") MASTER->slice(targ);
  if(str == "bite") MASTER->bite(targ);
  if(str == "claw") MASTER->claw(targ);
  if(str == "whip") MASTER->whip(targ);
return 1; }

confirm() {
object z;
int y,w,x;
z = all_inventory(eoo);
y = 0; w = 0;
for(x=0;x<sizeof(z);x++) {
  if(living(z[x]) && z[x] != eo) {
     y++;
     if(z[x]->is_player() && z[x]->query_level() < 20)
        w++;
  }
}
if(w > 1) return x;
if(y > 4) return y; 
return 0; }
