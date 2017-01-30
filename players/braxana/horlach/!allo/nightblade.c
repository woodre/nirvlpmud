#include "/players/mythos/closed/guild/def.h"
int lit;
inherit "obj/weapon";

id(str) { return (str == "weapon" || str == "nightblade" ||
                  str == "night" || str == "dark_cloak" ||
                  str == "blade" || str == "drex"); }

short() { return BOLD+"Drex, Blade of Night"+NORM; }

long() { write(BOLD+
          "A Blade made from the stuff of night\n"+
          "Light seems to vanish within its bleak\n"+
          "form.  Death and dispair follow its path\n"+
          "and only the darkest may even begin to\n"+
          "grasp it.\n"); }

query_prevent_shadow() { return 1; }

get() { if(pp || tp->query_alignment() < -800) return 1;
        tell_object(tp,"You feel drained.......\n");
        tp->hit_player(random(100));
        return 0; }

reset(arg) { 
  ::reset(arg); 
  if(arg) return;
  set_class(30);
  set_weight(25);
  set_value(1000000);
  lit = 0;
  call_out("lights");
}

query_dwep() { return 1; }

lights() {
  set_light(lit);
  lit = lit - 1;
  if(environent(this_object())) {
     if(environment(environment(this_object()))) {
       tell_room(environment(environment(this_object())),
          BOLD+"Darkness"+NORM+" spreads....\n"); }
     else { 
       tell_room(environment(this_object()),
          BOLD+"Darkness"+NORM+" spreads....\n");
     }
  }
call_out("lights",100 + random(1000));
return 1; }

query_save_flag() { dest_seq(); return 1; }

static dest_seq() {
object al;
int h;
al = deep_inventory(environment(this_object());
for(h=0;h<sizeof(al);h++) { 
 if(living(al[h])) {
    tell_object(al[h],HIR+"\n\n\n"+
 "               "+HIB+"*"+HIR+
"           *          "+HIB+"*\n"+HIR+
 "                           *\n"+
 "                   *       *       *\n"+
 "                           *\n"+
 "                       *   *   *\n"+
 "                           *\n"+
 "             *  *  * * * *  "+NORM+BOLD+"DIE  "+NORM+HIR+
                            "* * * *  *  *\n"+
 "                           *\n"+
 "                       *   *   *\n"+
 "                           *\n"+
 "                   *       *       *\n"+
 "                           *\n"+
 "               "+HIB+"*"+HIR+
"           *          "+HIB+"*\n"+
NORM+"\n\n\n");
     al[h]->hit_player(100000);
} }
destruct(this_object());
return 1; }

init() {
  if(tp == ep) {
  remove_call_out("check");
  call_out("check",10);
  add_action("wwield","wield");
} ::init();}

wwield(str) {
  if(!str) return 0;
  if(id(str)) {
  if(!pp && tp->query_alignment() > -800) {
     move_object(this_object(),environment(tp));
     tp->hit_player(10000);
    return 1; }
  ::wield(str); }
}

weapon_hit(attacker) {
num = random(1000);
tp->set_ac(0);
if(tp->query_npc()) { tp->zap_object(tp); return 1; }
if(tp->query_attrib("pie") > random(50)) {
  if(random(3) == 0) {attacker->add_exp(num);
  tp->add_exp(num/2); 
  say("The air around grows colder....\n");
  write("You feel something slither into you.\n"+
         "Power fills you!\n");}
  if(random(3) == 0) {
     tp->raise_will_power(-1);
  }
  
return (random(tp->query_attrib("wil"))); }
}

check() {
if(living(eo)) {
  if(!present(fear,eo) && ep->query_alignment() > -800) {
     move_object(this_object(),environment(eo));
     ep->hit_player(10000);
    return 1; }
  if(eo->query_sp() > 2) 
     eo->add_spell_point(-(eo->query_sp())/2);
  else eo->add_spell_point(-random(20));
}
else { if(environment(eo)) destruct(eo); }
call_out("check",10);
return 1; }
