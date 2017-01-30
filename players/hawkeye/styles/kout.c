inherit "/obj/treasure";
 string owner;
reset(arg) {
 if(arg)  return;
 set_short("kout");
 set_long("kout.\n");
 set_alias("ko");
 set_weight(0);
 set_value(0);
 set_heart_beat(1);
 owner = "noone";
 call_out("get_up", 10+random(5));
}
id(str) { return str == "ko"; }
set_owner(str) { owner = str; }
short() { return; }

heart_beat() {
   object this, that;
  this = environment(this_object());
  that = present(owner, environment(this));
if(!that)  destruct(this_object());
if(!this)  destruct(this_object());
if(!this->query_hp())  destruct(this_object());
     this->stop_fight();   that->stop_fight();
    this->stop_fight();   that->stop_fight();
    this->stop_hunter();
tell_room(environment(this), "-- "+capitalize(this->query_name())+
   " remains on the ground, out cold.\n");
     that->attack_object(this);
   this->stop_fight(); this->stop_fight();
   this->stop_hunter();
}

get_up() {
 object this;
 string ack;
this = environment(this_object());
ack = this->query_name();
if(this->query_hp()) {
 tell_room(environment(this),
   "- "+capitalize(ack)+" shakes it's head grogily.\n"+
   "- "+capitalize(ack)+" struggles to rise, but falls back down.\n");
   call_out("ridthis", 3+random(3));
   return 1;
       }
 destruct(this_object());
 return 1;
}

ridthis() {
  object this;
 this = environment(this_object());
  if(this->query_hp()) {
tell_room(environment(this), "- "+capitalize(this->query_name())+
   " staggers back to its feet.\n");
  destruct(this_object());
  return 1;
       }
  destruct(this_object());
  return 1;
}
