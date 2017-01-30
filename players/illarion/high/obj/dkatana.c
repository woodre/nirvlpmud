/* sort of a mini-quest special attack:  if the player finds the
 * right verb to use, he can spend 30 spell points to get a 
 * hit_player(7+random(16)) with an emote like a second attack
 * however, they won't be able to do this any more often than
 * every two minutes
 */


/* replaced with a weapon inherit that uses /obj/weapon.c
    [7.9.01]  ~

   see /players/illarion/closed/weapon.c for a copy
    of the inherit. */

inherit "/players/vertebraker/closed/std/weapon";
#include "/players/illarion/dfns.h"
#define DELAY 120

int last_second,second;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("katana");
  set_short("A "+BOLD+"dragon-head"+NORM+" katana");
  set_long(
"A truly awesome weapon forged by a japanese weaponsmith over two centuries\n"+
"ago.  The blade is long, double-edged, and slightly curved, with a wicked\n"+
"point.  The long white hilt is carved into a fanciful representation of\n"+
"a dragon that has made this sword famous.\n");
  set_class(18);
  set_type("sword");
  set_weight(5);
  set_value(3000);
  set_two_handed(1);
  set_hit_func(this_object());
}
id(str) {
    if(!query_wielded()) return ::id(str) || str == "katana";
    else return ::id(str) || str == "no_spell" || str == "katana";
}
init() {
  ::init();
  add_action("cmd_focus","focus");
}
cmd_focus(str) {
  object att;
  if(!wielded || !str || !id(str)) return 0;
  if(time()<last_second+DELAY) {
    write("The sword's power must have some time to collect.\n");
    return 1;
  }
  if(TP->query_sp()<30) {
    write("You do not have enough power to focus.\n");
    return 1;
  }
  att=TP->query_attack();
  if(!att || !present(att,environment(TP)) || !att->is_npc()) {
    write("The sword does not respond.\n");
    return 1;
  }
  last_second=time();
  TP->add_spell_point(-30);
  second=1;
  write("The sword begins to hum with power.\n");
  return 1;
}
query_message_hit(tmp) {
  switch(tmp) {
    default:     return ({" with a blinding slash","eradicated"});
    case 21..30: return ({" with quick stabs","perforated"});
    case 16..20: return ({" opening a minor wound","slashed"});
    case 11..15: return ({" tearing some flesh","stabbed"});
    case 6..10:  return ({" opening a small cut","slashed"});
    case 4..5:   return ({" barely piercing the skin","stabbed"});
    case 2..3:   return ({" with a weak slash","nicked"});
    case 1:      return ({" with a slow stab","tapped"});
  }
}
weapon_hit(att) {
  if(second) {
    string *mess;
    second=0;
    mess=query_message_hit((int)att->hit_player(7+random(16)));
    write("You "+mess[1]+" "+att->query_name()+mess[0]+".\n");
    say(TPN+" "+mess[1]+" "+att->query_name()+mess[0]+".\n");
    return 0;
  }
  if(random(5)) return 0;  /* 20% chance of special */  
  if(att->query_alignment()>0 || TP->query_alignment()<0)
    return 0;  /* must be good against evil */
  write("The katana leaps eagerly at "+att->query_name()+".\n");
  tell_object(att,"The katana seems to pull "+TPN+"'s arm forward as it strikes you.\n");
  say("The katana seems to pull "+TPN+"'s arm forward as it leaps at\n"+
      att->query_name()+".\n",({att,TP}));
  return 7;
}
