#include "/players/mythos/closed/guild/def.h"
int n;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("deathwhip");
    set_alt_name("whip");
    set_alias("death whip");
    set_short(RED+"Whip of Death"+NORM);
    set_long("A whip made from a strange black-red material.\n"+
             "It is tough and sleek, power throbs within its\n"+
             "depths.  Even death can be thwarted with this.\n"+
             "Type list for commands.\n");
    set_read(HIR+"For blood is the only true sacrifice...\n"+
            "\t\t\t\- Hunter\n"+NORM);
    set_class(25);
    set_weight(5);
    set_value(10000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(tp->query_attrib("pie") < (random(50)+1)) { 
      if(tp->query_exp() > 0) tp->add_exp(-1000-random(1000)); 
      if(random(3)==0) {
        if(tp->query_attrib("sta") > 0) tp->raise_stamina(-1);
      }
      tp->reset(1);
      move_object(clone_object("/players/mythos/closed/play/save.c"),tp);
}
if(tp->query_attrib("pie") > random(50)) {
  if(tp->query_alignment() < -500 && random(3) == 0) {
    n = random((tp->query_attrib("wil"))/2);
    tell_room(environment(this_player()),
      HIR+"Blood flies and terror strikes!\n"+NORM);
    write("You feel better.\n");
    tp->heal_self(n);
    attacker->heal_self(-n);
  }
  tell_room(environment(tp),HIR+"\n\t\tCRACK\n\n"+NORM+
  attacker->query_name()+" screams in pain as the whip lashes out!\n");
  return (tp->query_attib("ste"))/5;
  }
  return 0;
}

init() { 
  ::init();
    add_action("aaid","aid");
    add_action("plead","plead");
    add_action("llist","list");
}

query_save_flag()  { return 1; }

aaid() {
  write("The whip glows and suddenly you feel rage fill you!\n"+
        "Power fills you and suddenly your wounds disappear!\n");
  say("Suddenly the DEATH WHIP flares and "+capitalize(tpn)+"'s wounds close up!\n");
  tp->heal_self(2000);
  if(tp->query_weapon() == this_object()) { tp->set_wc(3); }
  write("The whip dissolves!\n");
  destruct(this_object());
return 1;}

plead() {
object avatar;
  if(n) {
  write("The whip glows as you mutter a prayer of help...\n");
  say(capitalize(tpn)+" mutters something...\n");
  avatar = clone_object("/players/mythos/closed/guild/forest/mon/avatar.c");
  avatar->set_owner(tpn);
  move_object(avatar,environment(this_player()));
  tell_room(environment(tp),HIR+"\nTerror enters the room!\n\n"+NORM);
  write("You have summoned help!\n");
  write("Pain wracks your body and soul!\n");
  tp->heal_self(-(tp->query_hp())/2);
  n = 0;
  return 1;}
  write("You can only plead for help once.\n");
  write("You feel great pain!\n");
  tp->heal_self(-100);
return 1;}

llist() {
  write("Whip commands:\n"+
        "  Plead  - calls for help once per time.\n"+
        "  Aid    - healing once.\n");
return 1;}
