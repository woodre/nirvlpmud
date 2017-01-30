
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("tough leather boots");
  set_alias("boots");
  set_short("A pair of tough leather boots");
  set_long(
"This is a pair of very tough looking leather boots.  You can tell just by\n"+
"glancing at them that they are very finely made.  They are quite tall,\n"+
"protecting a good part of the leg, and are nice and warm.  These boots\n"+
"would provide wonderful protection in combat.\n");
  set_value(450);
  set_weight(1+random(2));
  set_ac(1);
  set_type("boots");
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
