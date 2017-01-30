inherit "obj/weapon";
int sheathed;
#include "/players/illarion/dfns.h"

object current_att;

reset(arg) {
  ::reset(arg);
  
  sheathed=0;
  set_name("sword");
  set_short("The runeblade "+BOLD+BLK+"["+RED+"Stormbringer"+BLK+"]"+NORM);
  set_long(
"A truly nasty looking double edged blade that seems to pulse with\n"+
"malevolent energy.  A long leather hilt seems suited to the hands of\n"+
"some demon or dark god, and a small black jewel gleams at the pommel.\n");
  set_class(42);
  set_value(0);
  set_weight(0);
  set_hit_func(this_object());
}
query_wear() { return 1;}
id(str) {
  return (::id(str) || str == "kill_check_object");
}
weapon_hit(object att) {
  if(sheathed) this_object()->cmd_draw(name_of_weapon);
  current_att=att;
}
query_message_hit(tmp) {
  if(!random(3)) {
    tell_room(environment(wielded_by),
"The runesword glows with a hellish "+BLK+BOLD+"black"+NORM+" light.\n");
    tell_object(wielded_by,
"You feel a surge of power flow from the runesword's hilt.\n");
    wielded_by->heal_self(random(tmp)+1);
  }
  tmp=(tmp*50/class_of_weapon);
  switch(tmp) {
    default:         return ({"'s "+({"leg","arm","head"})[random(3)],
                              "nearly severed"});
    case 31..40:     return ({" with a blinding slash","eradicated"});
    case 21..30: return ({" with quick stabs","perforated"});
    case 16..20: return ({" opening a minor wound","slashed"});
    case 11..15: return ({" tearing some flesh","stabbed"});
    case 6..10:  return ({" opening a small cut","slashed"});
    case 4..5:   return ({" barely piercing the skin","stabbed"});
    case 2..3:   return ({" with a weak slash","nicked"});
    case 1:      return ({" with a slow stab","tapped"});
    case 0:       return ({"","missed"});
  }
}
init() {
  ::init();
  call_out("check_me",1);
  add_action("cmd_sheath","sheath");
  add_action("cmd_empower","empower");
  add_action("cmd_draw","draw");
}
check_me() {
  if(!environment()) return;
  if(environment()->query_level() && environment()->query_level() < 21) {
    tell_object(environment(),"The black sword fades away.\n");
    destruct(this_object());
  }
}
cmd_sheath(string str) {
  if(!str || !id(str)) FAIL("Sheath what?\n");
  if(!wielded) FAIL("You must be wielding it.\n");
  if(sheathed) FAIL("It is already sheathed.\n");
  write("You sheath your "+name_of_weapon+".\n");
  say(TPN+" sheaths "+TP->query_possessive()+" "+name_of_weapon+".\n");
  sheathed=1;
  return 1;
}
cmd_draw(string str) {
  if(!str || !id(str)) FAIL("Draw what?\n");
  if(!sheathed) FAIL("It must be sheathed first.\n");
  write("You draw your "+name_of_weapon+".\n");
  say(TPN+" draws "+TP->query_possessive()+" "+name_of_weapon+".\n");
  sheathed=0;
  return 1;
}
short() {
  if(!wielded) sheathed=0;
  if(sheathed) return short_desc+" (sheathed)";
  if(wielded) return short_desc+" (wielded)";
  return short_desc;
}
int cmd_empower(string str) {
  int x;
  if(!str || !sscanf(str,"%d",x)) FAIL("Empower to what power?\n");
  class_of_weapon=x;
  if(wielded_by) {
    stopwield();
    wield(name_of_weapon);
  }
  write("Runesword empowered to "+x+".\n");
  return 1;
}
kill_check(what) {
  string name;
  name=(string)what->query_name();
  tell_room(environment(wielded_by),format(
  "The runesword screams its pleasure as it devours "+name+"'s"+
  "soul, and cries its hunger for more!\n"),
   ({wielded_by}));
   tell_object(wielded_by,"The sword's dark energy pours into your soul.\n");
}
do_extra_attacks() {
  object att;
  int k,dam,reps;
  string *mess,name;
  att=current_att;  
  if(!att) return;
  name=att->query_name();
  reps=1+random(5);
  for(k=1;k<=reps;k++) {
    dam=random(class_of_weapon);
    dam=att->hit_player(dam);
    if(!att) {
      return 0;
    }
    mess=query_message_hit(dam);
    write("You "+mess[1]+" "+name+mess[0]+".\n");
    say(TPN+" "+mess[1]+" "+name+mess[0]+".\n");
  }
}
count_misses() {
  do_extra_attacks();
  return ::count_misses();
}
count_hit_made() {
  do_extra_attacks();
  return ::count_hit_made();
}
