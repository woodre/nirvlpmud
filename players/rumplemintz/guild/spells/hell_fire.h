/*
  hell_fire.h
*/

/* -------- Hellfire ---------- */
hell_fire() {
    object target_obj, next_target_obj;
    string target_name;
    int target_hit;
    if (target_obj->query_npc() &&
      living(target_obj) &&
      !target_obj->am_i_a_servant()  &&
      !target_obj->is_kid())
	target_name = lower_case(target_obj->query_name());
    while (target_obj) {
	next_target_obj=next_inventory(target_obj);
	if (target_obj->query_npc() &&
	  living(target_obj) &&
	  !target_obj->am_i_a_servant()  &&
	  !target_obj->is_kid()) {
	    target_obj->attacked_by(this_player());
	    target_obj->hit_player(100+random(1000));
	    target_hit=1;
	}
	target_obj=next_target_obj;
    }
    if (target_hit) {
	this_player()->add_spell_point(- 25);
	write("You shriek some gutteral words and the gates of hell\n"+
	  "open to blast your enemies with flame!\n");
	tell_object(environment(this_player()),capitalize(this_player()->query_name())+
	  " shrieks some gutteral words and the gates of hell\n"+
	  "open to blast "+this_player()->query_possessive()+
	  " enemies with flame!");
    }
    else
	write("There are no monsters here to roast in the fires of hell!\n");
    return 1;
}
