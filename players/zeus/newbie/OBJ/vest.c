
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("leather vest");
  set_alias("vest");
  set_short("A tough leather vest");
  set_long(
"This is a finely crafted leather vest.  The person who made it clearly\n"+
"put a lot of time and effort into it.  Every single stitch looks perfectly\n"+
"in place.  This is a wonderful piece of armor that would provide excellt\n"+
"protection for the wearing in combat, and keep them looking great.\n");
  set_value(450);
  set_weight(1+random(3));
  set_ac(3);
  set_type("armor");
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
