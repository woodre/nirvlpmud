inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("shield");
  set_short("A Durkor shield");
  set_long(
     " A large tower shield with the emblem of Durkor on the front\n"+
     "of it.  The coiled snake emblem seems to glare out of the shield.\n");
  set_type("shield");
  set_ac(1);
  set_weight(3);
  set_value(1000);
}
