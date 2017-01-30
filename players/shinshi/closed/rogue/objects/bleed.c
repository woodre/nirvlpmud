int time;

id(str) { return str == "bleed_damage_yo"; }
get() { return 1; }
drop() { return 1; }

set_garlength(num) {
	time = num;
	call_out("end_garrote", time);
}

start_it(){
  set_heart_beat(1);
}

heart_beat()
{
  object ob;
  int damage;
  
  ob = environment();
  damage = 30 + random(15);
  
  tell_object(ob, "\
Blood pours from your wound.\n");
  tell_room(environment(ob), "\
"+ob->query_name()+"'s wound bleeds profusely.\n");
  ob->hit_player(damage);
}

end_garrote(){
	if(environment(this_object())){
		if(environment(environment(this_object())))
		tell_room(environment(environment(this_object())), capitalize(environment()->query_name())+"'s wound magically closes up!\n");
	else
		tell_room(environment(environment(this_object())), "Your wound magically closes up!\n");
		destruct(this_object());
	}
}