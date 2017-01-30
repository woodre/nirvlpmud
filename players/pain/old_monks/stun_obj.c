inherit "/obj/monster";
    string owner;
reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_alias("trans");
 set_short("transobj");
 set_long("transobj.\n");
     set_level(1);
     set_ac(50);
     set_wc(0);
     set_hp(1000);
     set_al(0);
     set_aggressive(0);
   owner = "Jomama";
   call_out("ridthis", 20+random(10));
 set_heart_beat(1);
   }
}
id(str) { return str == "stun_obj"; }
set_owner(str) { owner = str; }
short() { return; }

heart_beat() {
   object this, that;
  this = environment(this_object());
  that = present(owner, environment(this));
 if(!that) { destruct(this_object()); }
  if(!this) { destruct(this_object()); }
 if(!this->query_hp()) { destruct(this_object()); }
     this->stop_fight();   that->stop_fight();
    this->stop_fight();   that->stop_fight();
    this->stop_hunter();
 tell_room(environment(this), capitalize(this->query_name())+
 " lays on the ground helplessly.\n");
     that->attack_object(this);
   this->stop_fight(); this->stop_fight();
   this->stop_hunter();
}

ridthis() {
  object this;
 this = environment(this_object());
  if(this->query_hp()) {
tell_room(environment(this), capitalize(this->query_name())+
 " shakes off the effects of the stun spell.\n");
  destruct(this_object());
  return 1;
       }
  destruct(this_object());
  return 1;
}
