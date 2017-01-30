#include "obj/security.h"
#include "players/mythos/closed/guild/def.h"
#define MAX_LIST			20
#define NAME_OF_GHOST			"some mist"

object player;

set_player(str) {player=str;}

init() {
if(living(player)) {
shadow(player, 1);}

}

quit() {
   shadow(player, 0);
   player->quit();
   return 1;
}

move_player(dir_dest)
{
  string dir, dest;
  object ob;
  int is_light;
  
  if(!dir_dest)
    return 0;

  if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
    tell_object(player, "Move to bad dir/dest\n");
    return;
  }
  current_room = dest;
  hunting_time -= 1;
  if (hunting_time == 0) {
    if (hunter)
      call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
  }
  if (attacker_ob && present(attacker_ob)) {
    hunting_time = 10;
    tell_object(this_object(), "You are now hunted by " +
		call_other(attacker_ob, "query_name", 0) + ".\n");
    hunter = attacker_ob;
  }
  if (!msgout)
    msgout = "leaves";
  is_light = set_light(0);
  if (is_light < -2)
    is_light = 0;
  if (ghost)
    say(NAME_OF_GHOST + " " + msgout + " " + dir + ".\n");
  else if (dir == "X" && query_invis() < INVIS_TELEPORT)
    say(cap_name + " " + mmsgout + ".\n");
  else if (query_invis() < NO_SHORT && is_light)
    say(cap_name + " " + msgout + " " + dir + ".\n");
  move_object(this_object(), dest);
  is_light = set_light(0);
  if (is_light < -2)
    is_light = 0;
  if (level >= 20)
    tell_object(this_object(), dest + "\n");
  if (!msgin)
    msgin = "arrives";
  if (ghost && is_light)
    say(NAME_OF_GHOST + " " + msgin + ".\n");
  else if (query_invis() < INVIS_TELEPORT && dir == "X")
    say(cap_name + " " + mmsgin + ".\n");
  else if (query_invis() < NO_SHORT && is_light)
    say(cap_name + " " + msgin + ".\n");
  if (hunted && present(hunted))
    attack_object(hunted);
  if (hunter && present(hunter))
    call_other(hunter, "attack_object", this_object());
  if (is_npc)
    return;
  if (!is_light) {
    write("A dark room.\n");
    return;
  }
  ob = environment(this_object());
  if (brief) {
    write(call_other(ob, "short", 0)); 
    write(".\n"); /* killed '+' --Wulkwa */
  } else
    call_other(ob, "long", 0);
  ob = first_inventory(ob);
  while(ob) {
    if (ob != this_object()) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str)
	write(short_str + ".\n");
    }
    ob = next_inventory(ob);
  }
}

static test_dark() {
    if (set_light(0) < -2) {
	write("It is too dark.\n");
	return 1;
    }
    return 0;
}

look(str, remote) {
    object ob, ob_tmp;
    string item;
    int max;
    if (test_dark())
	return 1;
    if (!str) {
        if (remote && call_other(this_player(), "query_brief")) {
	    write(call_other(environment(), "short")); write("\n");
	} else {
	    call_other(environment(), "long");
	}
	ob = first_inventory(environment());
	max = MAX_LIST;
	while(ob && max > 0) {
	    if (ob != myself) {
		string short_str;
		short_str = call_other(ob, "short");
		if (short_str) {
		    max -= 1;
		    write(short_str + ".\n");
		    it = short_str;
		}
	    }
	    ob = next_inventory(ob);
	}
	return 1;
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
	item = lower_case(item);
	ob = present(item, this_player());
	if (!ob && call_other(environment(this_player()), "id", item))
	    ob = environment(this_player());
	if (!ob)
	    ob = present(item, environment(this_player()));
	if (!ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	it = item;
	call_other(ob, "long", item);
	if (!call_other(ob, "can_put_and_get", item))
	    return 1;
        if (living(ob)) {
	    object special;
	    special = first_inventory(ob);
	    while (special) {
	        string extra_str;
		extra_str = call_other(special, "extra_look");
		if (extra_str)
		    write(extra_str + ".\n");
		special = next_inventory(special);
	    }
	}
	ob_tmp = first_inventory(ob);
	while (ob_tmp && call_other(ob_tmp, "short") == 0)
	    ob_tmp = next_inventory(ob_tmp);
	if (ob_tmp) {
	    if (living(ob))
		write("\t" + capitalize(item) + " is carrying:\n");
	    else
		write("\t" + capitalize(item) + " contains:\n");
	}
	max = MAX_LIST;
	ob = first_inventory(ob);
	while (ob && max > 0) {
	    string sh;
	    sh = call_other(ob, "short");
	    if (sh)
		write(sh + ".\n");
	    ob = next_inventory(ob);
	    max -= 1;
	}
	return 1;
    }
    write("Look AT something, or what?\n");
    return 1;
} 
