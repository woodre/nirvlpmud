/* skeleton of a scroll.
   to use one inherits this object
*/
inherit "players/mythos/magic/core";

static string msg1, msg2;
static int waiting;

reset(arg) {
	if(arg) return;
	name = handle = altname = alias = "scroll";
	type = "scroll";
	wait = 10;
	waiting = 0;
	gettable = 1;
	charges = 1;
	maxcharges = 1;
	value = 1;
	weight = 1;
	destyes = 1;
	weightchange = 0;
	chargeshowshort = 0;
	chargeshowlong = 0;
	short_desc = "A scroll";
	long_desc = "A scroll";
	msg1 = "You read the scroll.";
	msg2 = "reads from a scroll.";
}

init() {
	add_action("read","read");
}

static read(str) {
  if(!str) return 0;
  if(id(str)) {
    user = this_player();
    if(!user) return 1;
    username = user->query_real_name();
    if(!username) username = user->query_name();
    if(username == "") username = user->query_name();
    tell_object(user,msg1+"\n");
    tell_say(user,user->query_name()+" "+msg2+"\n");
    if(wait) { if(!waiting) { waiting = 1; call_out("use",wait); } else {} }
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
		tell_object(user,short_desc + " bursts into flame and turns into ashes.\n");
		destruct(this_object());
	return 1; }
	else {
		short_desc = "A piece of paper";
		long_desc = "A blank piece of paper";
		name = "paper";
		tell_object(user,"The scroll's writing fades...\n");
	return 1; }
}

effect() {  /* this is the main function which one should rewrite */
  return 1;
}