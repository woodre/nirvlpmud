cmd_disarm(str) {
  object att, att_wep;
  string wepname;
  int myroll, itsroll;
  att = this_player()->query_attack();
  if(!str && !att) {
    write("You must specify a target or be engaged in combat to attempt a disarm!\n");
	return 1;
  }
  if(!att) {
    att = present(str, environment(this_player()));
    if(!att) {
	  write("The target cannot be located!\n");
	  return 1;
	}
  }
  att_wep = att->query_weapon();
  if(!att_wep || att_wep->id("GI") || !att_wep->is_weapon()) {
    write(att->query_name()+" is not wielding a disarmable weapon!\n");
	return 1;
  }
  wepname = att_wep->query_name();
  myroll = this_player()->query_total_level() + this_player()->query_guild_rank() + (this_player()->query_attrib("luc")/3) + (this_player()->query_attrib("dex")/3) + (this_player()->query_attrib("str")/2) + random(30);
  itsroll = att->query_total_level() + (att->query_attrib("luc")/3) + (att->query_attrib("str")/2) + (att->query_attrib("wil")/3) + att_wep->query_wc() + random(30);
  if(itsroll > myroll) {
    write("You fail to disarm "+att->query_name()+"!\n");
	return 1;
  }
  call_other(att, "stop_wielding");
  att_wep->deShadow();
  if(this_player()->query_guild_rank() > 10) {
    move_object(att_wep, this_player());
    write("You rip the "+wepname+" from "+att->query_name()+"'s grasp, keeping it as a trophy!\n");
  }
  else {
    move_object(att_wep, environment(this_player()));
    write("You send "+att->query_name()+"'s "+wepname+" sailing across the room!\n");
  }
  say(this_player()->query_name()+" DISARMS "+att->query_name()+" with ease!\n");
  return 1;
}
 