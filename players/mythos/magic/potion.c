/* skeleton of a potion.
   to use one inherits this object
*/
inherit "players/mythos/magic/core";

string msg1, msg2;

reset(arg) {
	if(arg) return;
	name = handle = altname = alias = "potion";
	type = "potion";
	gettable = 1;
	wait = 0;
	charges = 1;
	maxcharges = 1;
	weight = 1;
	value = 1;
	weightchange = 1;
	chargeshowshort = 0;
	short_desc = "A Potion";
	long_desc = "A Potion";
	msg1 = "You drink the potion.";
	msg2 = "drinks a potion.";
}

init() {
	add_action("drink","drink");
}

static drink(str) {
  if(!str) return 0;
  if(id(str)) {
    user = this_player();
    if(!user) return 1;
    username = user->query_real_name();
    if(!username) username = user->query_name();
    if(username == "") username = user->query_name();
    tell_object(user,msg1+"\n");
    tell_say(user,user->query_name()+" "+msg2+"\n");
    if(wait) { call_out("use",wait); }
    else use();
  return 1; }
}

use() {
    if(!user) return 1;
    effect();
    if(usecharges() < 1) { empty(); return 1; }
}

empty() {
	if(!user) return 1;
	if(destyes) {
		tell_object(user,short_desc + " disappears.\n");
		destruct(this_object());
	return 1; }
	else {
		chargeshowlong = 0;
		short_desc = "An Empty Bottle";
		long_desc = "An Empty Bottle";
		name = "bottle";
		tell_object(user,"The potion is now empty.\n");
	return 1; }
}

effect() {  /* this is the main function which one should rewrite */
  return 1;
}