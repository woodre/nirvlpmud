#define EN environment(this_object())
int healed, piety;
id(str) { return str == "sanc"; }
short() { return; }
long() { return "sanc\n"; }
get() { return 1; }
drop() { return 1; }
reset(arg) {
if(arg) return;
  healed = 0;
}
init() {
  add_action("sanct", "abcblah");
}

sanct() {
 call_out("do_heal", 5);
return 1;
}

do_heal() {
if(EN->query_attack()){
  call_out("do_heal", 5);
  return 1;   }
piety = call_other(EN,"query_attrib","pie");
if(EN->query_hp() == EN->query_mhp() &&
      EN->query_sp() == EN->query_msp()) {
 tell_object(EN,
   "Your wounds have completely healed.  Your body feels whole\n"+
   "once again and your spirit renewed.  The sanctuary is\n"+
   "complete.  The blue aura surrounding you disappears.\n");
      destruct(this_object());
 return 1;  }

if(healed > 6) {
  tell_object(EN,
   "Your wounds have healed and your body feels rested.\n"+
  "Your sanctuary is complete and the blue aura surrounding\n"+
  "your body disappears.\n");
        destruct(this_object());
   return 1;
   }
tell_object(EN,
 "You meditate peacefully and cleanse your spirit.\n"+
 "The wounds of your mind and body fade away.\n");
 EN->add_hit_point(9+random(piety));
 healed++;
 call_out("do_heal", 15+random(15));
return 1;
}


query_value() { return 0; }
