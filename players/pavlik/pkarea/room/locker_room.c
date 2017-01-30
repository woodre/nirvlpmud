inherit "room/room";
#include "/players/pavlik/pkarea/lib/defines.h"
#include "/players/pavlik/closed/colors.h"

#define MEIJIN_ID "pavlik_guild_obj"
#define TEMPLAR_ID "templar_cross"
#define RANGER_ID "RangerCommunicator"
#define CYBER_ID "guild_implants"
#define DMAGE_ID "dmage_thingy"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIW+HIB+"Matrix"+NORM+" Locker Room";
  long_desc=
	"The Matrix "+HIW+"Locker Room"+NORM+".\n"+
	"Because of the strict regulations on equipment permitted into the Matrix players are\n"+
	"provided with lockers to store their posessions before entering.  Each wall of this\n"+
	"large chamber is lined with full size storage lockers.  You can "+HIC+"store"+NORM+" your\n"+
	"equipment here and "+HIC+"recover"+NORM+" it before you leave.\n";
  dest_dir=({
	"/players/pavlik/pkarea/room/start_room", "out",
  });
}

clean_up() { return 1; }

init() {
  ::init();
  if(this_player()->query_invis() && this_player()->query_level() < 20) {
	command("visible", this_player());
  }
  add_action("store", "store");
  add_action("recover", "recover");
  add_action("no_can_do", "quit");
}

no_can_do() {
  write("Sorry, you cannot do that here.\n");
  return 1;
}

query_no_fight() { return 1; }
realm(){ return "NT"; }

store() {
  if(this_player()->query_guild_name() == "polymorph" || present("dmage", this_player())) {
	write("Sorry, members are your guild are not permitted inside the Matrix.\n");
	return 1;
  }
  if(this_player()->query_money() < 200) {
	write("It costs "+HIW+"200 coins"+NORM+" to get a locker.\n");
	write("You can't afford that right now.\n");
	return 1;
  }
  if(present(this_player()->query_real_name()+"_locker", this_object())) {
	store_confirm("y");
	return 1;
  }
  write("\n");
  write("You are about to remove "+HIY+"ALL"+NORM+" of your possessions, including autoloads and\n");
  write("guild objects, and have them stored.\n");
  write("Are you sure you want to continue? (Y/N) : ");
  input_to("store_confirm");
  return 1;
}

store_confirm(str) {
  if(lower_case(str) == "y") {
	string name, *save_string;
	object ob, locker;
	int i;

	if(this_player()->query_guild_name() == "polymorph" || present("dmage", this_player())) {
		write("Sorry, members are your guild are not permitted inside the Matrix.\n");
		return 1;
	}
	if(this_player()->query_money() < 200) {
		write("You can't afford the locker.\n");
		return 1;
	}

	name = this_player()->query_real_name();
	save_string = ({ });

	locker = present(name+"_locker", this_object());
	if(!locker) {
		locker = clone_object("players/pavlik/pkarea/obj/locker");
		move_object(locker, this_object());
		call_other(locker, "set_owner", name);
	}

	write("\nYou pay 200 coins and get a locker.\n\n");
	call_other(this_player(), "add_money", -200);

	/*
	 * Remove Coins
	 */
	write("You put "+this_player()->query_money()+" gold coins into the locker.\n");
	call_other(locker, "add_money", this_player()->query_money());
	this_player()->add_money(-this_player()->query_money());
	
	/*
	 * Handle Guild Objects
	 */
	remove_guild_obj();

	/*
	 * Put all droppable objects in Locker.
	 */
	move_object(this_player(), locker);
	command("drop all", this_player());
	move_object(this_player(), this_object());

	/*
	 * Handle non-dropped objects.
	 */
	ob = all_inventory(this_player());
	for(i=0; i<sizeof(ob); i++) {
		/* don't do anything with the soul */
		if(ob[i]->id("soul")) {
			continue;
		}
		/* save and dest autoloads */
		else if(ob[i]->query_auto_load()) {
			save_string += ob[i]->query_auto_load();
			if(ob[i]->short()) write("You put "+ob[i]->short()+" into the locker.\n");
			destruct(ob[i]);
		}
		/* get rid of everything else */
		else {
			call_other(ob[i], "drop", 1);
			destruct(ob[i]);
		}
	}
	call_other(locker, "add_save_string", save_string);

	write("\n");
	write("The locker door closes and you hear the assuring "+HIB+"click"+NORM+" of the lock.\n");
	write(HIC+"[[[ "+HIW+"Equipment Stored "+HIC+"]]]"+NORM+"\n");
	write("\n");
	say(capitalize(name)+" removes "+this_player()->query_possessive()+" equipment and stores it away in a locker.\n");
	/* add daemon object */
	return 1;
  }
  if(lower_case(str) == "n") {
	write("You decide against storing your equipment at this time.\n");
	return 1;
  }
  write("Are you sure you want to continue? (Y/N) : ");
  input_to("store_confirm");
  return 1;
}

remove_guild_obj() {
  string name;
  object obj;

  name = this_player()->query_guild_name();

  switch (name) {
	case "meijin" :
		if((obj = present(MEIJIN_ID, this_player()))) {
			call_other(obj, "save_me", 1);
			destruct(obj);
			write("Your "+HIB+"Meijin"+NORM+" guild object is removed.\n");
		}
		return 1;
	case "Knights Templar" :
		if((obj = present(TEMPLAR_ID, this_player()))) {
			destruct(obj);
			write("Your "+HIW+"Knight"+NORM+" guild object is removed.\n");
		}
		return 1;
	case "rangers" :
		if((obj = present(RANGER_ID, this_player()))) {
			destruct(obj);
			write("Your "+HIG+"Power Ranger"+NORM+" guild object is removed.\n");
		}
		return 1;
	case "dark rangers" :
		if((obj = present(RANGER_ID, this_player()))) {
			destruct(obj);
			write("Your "+HIM+"Dark Ranger"+NORM+" guild object is removed.\n");
		}
		return 1;
	case "cyberninja" :
		if((obj = present(CYBER_ID, this_player()))) {
			destruct(obj);
			call_other(this_player(), "stop_defense");
		}
		return 1;
	case "polymorph" :
		write("Error.  Your guild is not permitted here.\n");
		return 1;
	default :
		if((obj = present(DMAGE_ID, this_player()))) {
			write("Error.  Your guild is not permitted here.\n");
			return 1;
		}
		write("No guild object found to be removed.\n");
		break;
  }
  return 0;
}

recover() {
  string name, *save_string;
  object locker;
  int i, coins;

  name = call_other(this_player(), "query_real_name", 0);

  if(!(locker = present(name+"_locker", this_object()))) {
	write("Uh ho.  No locker for you exists here.\n");
	write("Are you sure you "+HIC+"store"+NORM+"d your equipment?\n");
	return 1;
  }

  write("\nYou unlock your locker and open it.\n");

  coins = call_other(locker, "query_money", 0);
  write("You take "+coins+" gold coins from the locker.\n");
  call_other(this_player(), "add_money", coins);

  save_string = call_other(locker, "query_save_string", 0);

  for(i=0; i<sizeof(save_string); i++) {
	string file, arg;
	object ob;
	if(sscanf(save_string[i], "%s:%s", file, arg) != 2) {
		write("Error!  Auto Load string is corrupted!\n");
		return 1;
	}
	ob = clone_object(file);
	if(ob) {
		if(arg) call_other(ob, "init_arg", arg);
		move_object(ob, this_player());
		if(ob->short()) write("You take "+ob->short()+" from the locker.\n");
	}
  }

  restore_guild_obj();

  call_other(this_player(), "recalc_carry", 0);
  move_object(this_player(), locker);
  command("get all", this_player());
  move_object(this_player(), this_object());
  destruct(locker);

  write(HIC+"[[[ "+HIW+"Equipment Recovered "+HIC+"]]]"+NORM+"\n");
  return 1;
}

restore_guild_obj() {
  string name;
  object obj;

  name = this_player()->query_guild_name();

  switch (name) {
	case "meijin" :
		if(present(MEIJIN_ID, this_player())) return 1;
		obj = clone_object("players/pavlik/guild/gob");
		move_object(obj, this_player());
		call_other(obj, "guild_init", 1);
		return 1;
	default :
		write("Restore guild object here ... \n");
		return 1;
  }

  return 1;
}

