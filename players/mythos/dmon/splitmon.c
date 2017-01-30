#include "/players/mythos/dmon/def.h"
inherit "players/mythos/dmon/mon";

/* when using this, use inherit only.  Do NOT clone directly 
   make sure that individual monster has its own filepath that
   is base 
*/

int parts, line, percent_set;
int once;

set_parts(n) { parts = n; }
set_line(n) { line = n; }
set_percent(n) { percent_set = n; }   /* must place a do_function() in file */
query_percent() { return percent_set; }
query_parts() { return parts; }
quert_line() { return line; }

reset(arg) {
  ::reset(arg);
  if(arg) return;
  parts = line = 0;
  percent_set = 0;
  once = 1; 
}

heart_beat() {
  ::heart_beat();
  if(percent_set) {
  if(hit_point * 100 / max_hp < percent_set && once) {
  this_object()->do_function();  /* must be in actual file */
  } }
}

hit_player(dam,zap) {
int damm, partcp;
string filecopy,null;
object newcp;
  damm = dam;
  if(line && parts) {
  if(damm > line && damm < hit_point && max_check()) { 
    sscanf(this_object(),"%s#%s",filecopy,null);
    partcp = parts;
    while(partcp > 0) {
    newcp = clone_object("/"+filecopy+".c");
    move_object(newcp,environment(this_object()));
    tell_room(environment(this_object()),
    "Suddenly a piece of "+short()+" falls to the ground.\n"+
    "                 "+CYN+"F  L  A  S  H"+NORM+"\n"+
    "The piece has now become a new "+short()+"!\n");
    newcp->attack_object(previous_object());
    partcp = partcp - 1; }
  } }
  ::hit_player(damm,zap);
}

heal_self(n) {
int h, partcp;
object newcp;
string filecopy, null;
  h = n;
  if(h < 0) {
    if(line && parts) {
    if(-h > line && -h < hit_point && max_check()) { 
    partcp = parts;
    sscanf(this_object(),"%s#%s",filecopy,null);
    while(partcp > 0) {
    newcp = clone_object("/"+filecopy+".c");
    move_object(newcp,environment(this_object()));
    tell_room(environment(this_object()),
    "Suddenly a piece of "+short()+" falls to the ground.\n"+
    "                 "+CYN+"F  L  A  S  H"+NORM+"\n"+
    "The piece has now become a new "+short()+"!\n");
    if(attacker_ob) newcp->attack_object(attacker_ob);
    else newcp->frenzy();
    partcp = partcp - 1; }
  } } }
  ::heal_self(h);
}

frenzy() {
object who, what;
int h,j;
  who = ({});
  what = all_inventory(environment(this_object()));
  for(j=0;j<sizeof(what);j++) {
    if(what[j]->is_player() && living(what[j])) {
      who += ({what[j]});
    }
  }
  who = filter_array(who, "nulling",this_object());
  who = filter_array(who,"ghost_check",this_object());
  h = 0; 
  while(h<1) {
    if(sizeof(who) < 1) { h = 1; }
    if(sizeof(who) < 2) { h = 1; this_object()->attack_object(who[0]); }
    if(sizeof(who) > 1) { h = 1; this_object()->attack_object(who[random(sizeof(who))]); }
  }
}
    
nulling(ob){ return objectp(ob); }
ghost_check(ob) { return !ob->query_ghost(); }

max_check() {
object moo;
  moo = all_inventory(environment(this_object()));
  moo = filter_array(moo,"liv",this_object());
  if(sizeof(moo) > 20) return 0;
return 1; }

liv(ob) { return living(ob); }