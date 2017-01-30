#include "/players/mythos/closed/guild/def.h"
int cc, nc;
object ob;

id(str) { return str == "night_mare_check" || str == "dark_cloak"; }
drop() {return 1;}
get() { return 0;}

set_ss(n) { cc = n;}

reset(arg) {
  if(arg) return;
  call_out("ccheck",5);
  call_out("zcheck",3);
} 

ccheck() {
if(ep) {
if(!present("xb",environment(ep))) {
 destruct(this_object()); return 1;} }
call_out("ccheck",5);
return 1;}

zcheck() {
if(ep) {
nc = ep->query_sp();
 if(cc < nc) { cc = nc; }
 if(cc > nc && (cc - nc) > 26) { 
 ob = clone_object("/players/mythos/closed/guild/spells/monster2.c");
 ob->set_name("nightmare");
 ob->set_race("demon");
 ob->set_alias("demonling");
 ob->set_short(BOLD+"Nightmare"+NORM);
 ob->set_long("A thing of hideous features. \n"+
              "A being that exists to torment others.\n");
 ob->set_al(-random(1000));
 ob->set_hp(100+ (cc-nc) + random(60));
 ob->set_level(10 + random(10));
 ob->set_wc((cc-nc)+random(30));
 ob->set_ac(10+ random(10));
 ob->set_disease(20);
 ob->set_aggessive(1);
 if(0== random(4)) {
 ob->set_wander();}
 ob->set_a_chat_chance(10);
 ob->load_a_chat("The Nightmare screams!\n");
 ob->load_a_chat("The Nightmare lashes out with its claws!\n"); 
 if(cc - nc > 50) {
 ob->set_mult(2);
 ob->set_mult_chance(20);
 ob->set_mult_dam1(5);
 ob->set_mult_dam2((cc-nc)/4); }
 tell_room(environment(ep),"Magic has been used, causing the fae to erupt!\n"+
          "From the depths of the mind a nightmare appears!\n");
 move_object(ob,environment(ep));
 ob->attack_object(ep);
 if(cc - nc < 40) {
 move_object(clone_object("/players/mythos/closed/guild/spells/level_dest.c"),ob); }
   cc = nc;
  }	 }
 call_out("zcheck",3);
 return 1;
}
