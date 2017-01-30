
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("tough leather gloves");
  set_alias("gloves");
  set_short("A pair of tough leather gloves");
  set_long(
"These are a pair of very well crafted leather gloves.  They are quite\n"+
"tough, and would provide excellent protection in combat.\n");
  set_value(450);
  set_weight(1+random(2));
  set_ac(1);
  set_type("ring");
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

