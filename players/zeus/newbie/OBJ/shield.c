
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("steel shield");
  set_alias("shield");
  set_short("A large steel shield");
  set_long(
"This is a large, round steel shield.  The face of the shield is perfectly\n"+
"smooth, as though it is brand new.  It is a very well made shield, and\n"+
"would provide excellent protection in combat.\n");
  set_value(450);
  set_weight(1+random(2));
  set_ac(1);
  set_type("shield");
  set_save_flag(1);
}

do_special(owner) {
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  if(!"/players/zeus/newbie/check.c"->check()) return 0;
  if(!random(4)){
    owner->add_hit_point(1); 
	return 1; 
  }
  return 0; 
}
