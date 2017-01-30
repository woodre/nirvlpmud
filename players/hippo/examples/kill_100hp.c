inherit "obj/weapon";

reset(arg){
if(arg) return;
::reset(arg);
set_name("mace");
set_alias("mace");
set_short("Mace of Arioch");
set_long("This is an extremely heavy mace that seems to also be \n"+
"perfectly balanced to bludgeon someone.  It has something enruned \n"+
"on the handle but you can't quite make it out.  Could this be the \n"+
"famed mace that Arioch used to vanquish the legions of zombies.....\n");
set_class(19);
set_weight(4);
set_heart_beat(1);
set_value(20000);
set_hit_func(this_object());
}

weapon_hit(attacker){
	if (random (100) < 30) {
write("Your blood boils as you crush " + capitalize(attacker->query_name()) + ".\n");
say("The room turns blood red as " + capitalize(this_player()->query_name())+ " uses the bludgeoning force of the mace!!\n");
	return(random(30)+3);
}
}

init() {
  ::init();
    add_action("wmess","wield");
}
wmess(str) {
if (!id(str))
	return 0;
	if(environment() !=this_player()) {
/*write("You must get it first!\n");*/
	return 0;
}
if (wielded) {
	write("You already wield it!\n");
	return 1;
}
if(wield_func)
	if(!call_other(wield_func,"wield",this_object()))
	return 1;
if(this_player()->query_level() > 1) {
write("You feel the awesome power of Arioch enter your body.\n");
}
wielded_by=this_player();
call_other(this_player(), "wield",this_object());
wielded=1;
} /*wield*/
heart_beat() {
	object user, attacker;
	user=environment(this_object());
	attacker=(environment(this_object())->query_attack());
	if(attacker->query_hp() < 100) {
	attacker->hit_player(120);
	environment(this_object())->add_spell_point(-40);
tell_object(user, "A surge of adrenalized power runs from the mace at" + attacker->query_name() +"\n" +
"causing an instant but painful death.\n\n" +
"The mace seems to glow for a bit, then it slowly loses its luster\n"+
"to its seemingly normal form...\n");
	return 1;
	}
}
