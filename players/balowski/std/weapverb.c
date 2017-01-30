/*
 * Verbs for weapon by Balowski@Nirvana
 * Code full of exceptions. Handles paladin additions and multi-limb
 */

/* I should get rid of this as soon as possible */
void
init()
{
    if (this_player() == environment()) {
	add_action("cmdWield", "wield");
	add_action("cmdUnwield", "unwield");
    }
}

/* old function (called by the ready/# command) */
status
wield(string arg)
{
    if (!id(arg)) return 0;
    if (query_hands() > 1) return 0;
    if (WieldedBy != this_player() && !prevent_wield(this_player()))
      if (this_player()->query_weapon())
	write("You are already wielding a weapon.\n");
      else {
	  ev_wield(this_player(), ({"right hand"}));
	  this_player()->wield(this_object());
      }
}

static string *WieldArgs(string arg)
{
    string a, b;

    if (sscanf(arg, "%s and %s", a, b) > 1) return ({ a, b });
    return explode(arg, ",");
}

static mixed PlayerCanWield(object who, string *limbs)
{
    int i;

    i = sizeof(limbs);
    while (i--) {
	if (limbs[i] == "right hand") {
	    if (who->query_weapon()) {
		return "You are already using your right hand.\n";
	    }
	}
	else if (limbs[i] == "left hand") {
	    object ob;
	    for (ob = first_inventory(who); ob; ob = next_inventory(ob)) {
		if (ob->query_offwielded())
		  return "You are already using your left hand.\n";
		else if (ob->test_type("shield") && ob->query_worn())
		  return "You are wearing a shield.\n";
	    }
	}
	else {
	    return "You have no " + limbs[i] + ".\n";
	}
    }
    return 1;
}

static status CanWield(object who, string *limbs)
{
    mixed x;

    if (function_exists("query_can_wield", who)) {
	x = (mixed) who->query_can_wield(this_object(), limbs);
    }
    else {
	x = PlayerCanWield(who, limbs);
    }
    if (stringp(x)) write(x);
    return (x == 1);
}

status
cmdWield(string arg)
{
    object w;
    string what, where;
    string *wlimbs;
    
    if (!arg) return (notify_fail("Wield what?\n"), 0);
    if (sscanf(arg, "%s in %s", what, where) < 1) {
	what = arg;
    }
    else {
	wlimbs = distinct_array(WieldArgs(where));
    }

    if (present(what, this_player()) != this_object()) {
	notify_fail("Wield what?\n");
	return 0;
    }
    if (query_wielded()) {
	notify_fail("You are already wielding it.\n");
	return 0;
    }
    if (prevent_wield(this_player())) {
	return 1;
    }
    
    if (where) {
	if (sizeof(wlimbs) != Hands) {
	    write("You need " + Hands + " hands to wield it.\n");
	    return 1;
	}
    }
    else {
	/* exception for primary hand in my monsters */
	if (Hands == 1
	&&  (where = (string)this_player()->query_primary_hand())
	&&  !this_player()->query_wielded(where)) {
	    wlimbs = ({ where });
	}
	else {
	    /* call_resolved.. */
	    if (function_exists("query_free_hands", this_player()))
	      wlimbs = (string *)this_player()->query_free_hands();
	    else
	      wlimbs = ({ "right hand", "left hand" });
	}
	if (!wlimbs) {
	    write("You have nowhere to wield it.\n");
	    return 1;
	}
	if (sizeof(wlimbs) < Hands) {
	    write("You do not have enough free limbs.\n");
	    return 1;
	}
	wlimbs = wlimbs[0 .. Hands - 1];
    }
    if (!CanWield(this_player(), wlimbs)) return 1;

    ev_wield(this_player(), wlimbs);
    if (function_exists("offwield", this_player())) {
	if (member_array("left hand", wlimbs) >= 0)
	  this_player()->offwield(this_object());
	if (member_array("right hand", wlimbs) >= 0)
	  this_player()->wield(this_object());
    }
    else {
	this_player()->wield(this_object(), wlimbs);
    }
    return 1;
}

status
cmdUnwield(string arg)
{
    if (arg && !id(arg)) {
	notify_fail("Unwield what?\n");
	return 0;
    }
    if (WieldedBy != this_player()) {
	notify_fail("You are not wielding it.\n");
	return 0;
    }
    if (prevent_unwield(0))
      return 1;
    
    write("You unwield your " + query_name() + ".\n");
    say(this_player()->query_name() + " unwields " + query_name() + ".\n");
    if (function_exists("offwield", this_player())) {
	if (query_offwielded()) {
	    this_player()->stop_offwielding();
	    if (query_hands() > 1) this_player()->stop_wielding();
	}
	else this_player()->stop_wielding();
    }
    else {
	this_player()->stop_wielding(this_object());
    }
    ev_unwield();
    return 1;
}
