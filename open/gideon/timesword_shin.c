inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("timesword");
    set_alias("sword");
    set_short("The TimeSword");
    set_long(
		"As you peer intently at this sparkling blade, you see that material essence\n"+
		"is quite rare.\n");
    set_class(17);
    set_weight(1);
    set_value(10000);
    set_hit_func(this_object());
}

query_save_flag() { return 1; }

weapon_hit() {
int WC,agehit,wilnum,timestop;
object meat;
WC = random(32);
    wilnum = call_other(this_player(),"query_attrib","wil");
    agehit = ((this_player()->query_age())/50000);
    meat = this_player()->query_attack();
    timestop = random(8640000);
  if(agehit > 10) agehit = 10;
   if(agehit > 20) agehit = 12;
   if(agehit > 30) agehit = 15;
  if(WC < wilnum) {
  say(capitalize(this_player()->query_name())+ "'s TimeSword splits asunder the temp asunder the temporal dimension!\n");
  tell_room(environment(this_player()),capitalize(meat->query_name())+ " reels in a culmination of past and future pain!\n");
	}
  if(timestop < this_player()->query_age()) {
    if(meat->query_npc()) {
		tell_room(environment(this_player()),capitalize(meat->query_name())+ "'s wounds are frozen in time!\n");
		call_other(meat,"set_heal",0,0);
	}
	}
}