#define user environment(this_object())
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w,n,ahp,ob,elevel,ph;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
set_name("foot");
set_alias("big foot");
set_short("A BIG foot");
set_long("A big hairy foot with razor sharp toenails\n");
    set_save_flag(1);
   set_class(20);
   set_weight(3);
   set_value(1000);
   set_hit_func(this_object());
}
weapon_hit(attacker){
  if(call_other(this_player(),"query_attrib","str")>random(60)){
say(tp+" leaves a size 22 imprint on its victims forehead!\n");
write("You leave a size 22 imprint on your victims forehead!\n");
ph=this_player()->query_sp();
ob=this_player()->query_level();
elevel=this_player()->query_extra_level();
	if(ph > 0) {
	if((elevel > 4)&&(ob > 14)) {
	this_player()->add_spell_point(-25);
	return random(45);
	} else if((elevel < 5)&&(ob > 14)) {
	this_player()->add_spell_point(-20);
	return random(40);
	} else if((ob < 15)&&(ob > 9)) {
	this_player()->add_spell_point(-15);
	return random(30);
	} else if((ob < 10)&&(ob > 4)) {
	this_player()->add_spell_point(-10);
	return random(20);
	}
     }
    return 0;
}
}
