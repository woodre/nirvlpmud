
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("steel helm");
  set_alias("helm");
  set_short("A steel helm");
  set_long(
"This is a very finely crafted steel helm.  There is a narrow slit to\n"+
"allow the wearer to see, as well as 3 small slits where the mouth\n"+
"would be.  This piece of armor would provide excellent protection.\n");
  set_value(450);
  set_weight(1+random(2));
  set_ac(1);
  set_type("helmet");
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
