/* Orginal code from Bern's Templars,
Modified to become The Knight's Templar by Boltar.
*/
#include "/players/maledicta/ansi.h"
#include "std.h"
#include "tune.h"
inherit "room/room";

#define num_skill 7
object owner;

reset(arg) {
	if(!present("templar_trainer")){
		owner = clone_object("/players/maledicta/templar/mobs/trainer.c");
		move_object(owner, this_object());
	}
	if (arg) return;
	skill_setup();
	set_light(1);
	short_desc = "Templar Training Hall "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
	long_desc =
	"  This is the main training hall of the Knights.  This room is\n"+
	"divided into specific areas, each targeting a necessary function\n"+
	"of the knights skills.  A door leads to the west to the hallway,\n"+
	"with an archway leading north to the Templar Lockers.\n";
	skill_setup();
	items = ({
			"door",
			"A heavy wooden door inlaid with solid strips of iron",
	});
	
	dest_dir = ({
			"/players/maledicta/templar/rooms/hallway2.c","west",
			"/players/maledicta/templar/rooms/templar_locker.c","north",
	});
	
}


init(){
	::init();
if(this_player())
if(present("warrior_gob", this_player())) return;
add_action("cost_for_level", "cost");
add_action("advance", "advance");
add_action("raise", "raise");
	add_action("cross","cross");
	add_action("train","train");
	this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }







int next_level;
int valexp;
int next_exp;
int rankxp;
int level;
int exp;
string guild_title;
string title;         /* now with arrays. ! */
object player_ob;
string skills;
string banished_by;

/* called by the fixtitle function */

query_title(ob) {
	int i;
	i = ob->query_level();
	if (i>19) return ob->query_title();
	return guild_title[i-1];
}

cross() {
	object cross;
	if (this_player()->query_guild_file() != "players/boltar/templar/templar") {
		write("You do not belong to this guild.\n");
		return 1;
	}
	cross = present("KnightTemplar", this_player());
	if (!cross) {
		write(
			"You walk over to a fine oak cabinet and open it. Inside\n"+
			"you find a small box that contains a Templar cross. You\n"+
		"place it around your neck and feel comforted.\n");
		move_object(clone_object("players/boltar/templar/templar"), this_player());
		return 1;
	}
	destruct(cross);
	move_object(clone_object("players/boltar/templar/templar"), this_player());
	write(
		"You walk over to a fine oak cabinet and open it. Inside\n"+
		"you find a small box that contains a Templar cross. You\n"+
	"place it around your neck and feel comforted.\n");
	
	return 1;
}

int exp_str;

advance(str) {
	if(this_player()->query_guild_file() != "players/boltar/templar/templar") {
		write("You do not belong to this guild.\n");
		return 1;
	}
	
	if(!str || str!="rank") {
		write("advance 'rank'\n");
		return 1;
	}
	if(!present("templar_trainer", this_object())){
		write("You do not see a trainer here.\n");
		return 1;
	}
	
	if(str=="rank") {
		int minexp,expcost;
		int current;
		object guild_ob;
		guild_ob=present("KnightTemplar",this_player());
		if(!guild_ob) {
			write("You do not have the symbol of the Knights Templar.\n");
			return 1;
		}
		current = this_player()->query_guild_rank();
		if(current > 7) {
			write("You have reached the highest of Templar ranks.\n");
			return 1;
		}
		expcost = get_rank_exp(current + 1)-get_rank_exp(current);
		if(this_player()->query_extra_level() < 1 && this_player()->query_level() < 21)
		minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",this_player()->query_level()-1);
		if(this_player()->query_extra_level() > 0 && this_player()->query_level() < 21)
		minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
		if(this_player()->query_level() > 20) minexp = 7000000;
		if(expcost > minexp) {
			write("You do not have enough available experience to to advance your templar rank.\n");
			return 1;
		}
		this_player()->add_guild_rank(1);
		this_player()->add_guild_exp(expcost);
		this_player()->add_exp(-expcost);
		this_player()->save_me();
		command("fixtitle", this_player());
		write("You advance your rank within the Templars.\n");
		say(this_player()->query_name()+" advances within the Knights Templar.\n");
		return 1;
	}
}

correct_level(player)
{
	level = call_other(player, "query_level", 0);
	exp = call_other(player, "query_exp", 0);
	/* Shouldn't "correct" wizards. */
	if (level >= 20)
	return;
	get_level(level);
	while (exp < next_exp) {
		level -= 1;
		get_level(level);
	}
	if (next_level == 20 && call_other("room/quest_room", "count", 0))
	next_level = 19;
	call_other(player, "set_level", next_level);
	call_other(player, "set_title", title);
}

realm() { return "NT"; }

cost_for_level() {
	call_other("room/adv_guild","cost_for_level",0);
	return 1;
}

train(str) {
	int minexp,expcost;
	int i,cost,new;
	int current;
	object guild_ob;
	if(this_player()->query_guild_file() != "players/boltar/templar/templar") {
		write("You do not belong to this guild.\n");
		return 1;
	}
	
	if(!str) {
		write("Train what skill?\n");
		return 1;
	}
	if(!present("templar_trainer", this_object())){
		write("You do not see a trainer here.\n");
		return 1;
	}
	
	if(str=="cost") {
		cost = 1;
	}
	if(!cost && str != "sword" && str != "axe" && str !="club" && str != "knife" && str != "bow" && str !="shield" && str != "polearm" && str != "horse") {
		write("You must specify sword, axe, shield, polearm, bow, club, horse, or knife.\n");
		return 1;
	}
	guild_ob=present("KnightTemplar",this_player());
	if(!guild_ob) {
		write("You do not have the symbol of the Knights Templar.\n");
		return 1;
	}
	if(!cost) {
		current=guild_ob->query_skill(str);
		new = current + 1;
		if(this_player()->query_extra_level() < 1 && this_player()->query_level() < 21)
		minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",this_player()->query_level()-1);
		if(this_player()->query_extra_level() > 0 && this_player()->query_level() < 21)
		minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
		if(this_player()->query_level() > 20) minexp = 7000000;
		if(new < 3) expcost=SKILL_COST;
		if(new > 2 && new < 5) expcost=SKILL_COST_TWO;
		if(new > 4) expcost = SKILL_COST_THREE;
		if(new > 6) expcost = 3*SKILL_COST_THREE/2;
		if(current > 9) {
			write("You are already at the maximum possible training value.\n");
			return 1;
		}
		write("You have a "+str+" training value of "+current+" it costs "+expcost+" experience to raise to a value of "+new+"\n");
		say(this_player()->query_name()+" trains in the methods of the "+str+"\n");
	}
	else {
		while(i < num_skill) {
			current=guild_ob->query_skill(skills[i]);
			new = current + 1;
			if(new < 3) expcost=SKILL_COST;
			if(new > 2 && new < 5) expcost=SKILL_COST_TWO;
			if(new > 4) expcost = expcost=SKILL_COST_THREE;
			if(new > 6) expcost = 3*SKILL_COST_THREE/2;
			if(current > 9) {
				write(skills[i]+" is at maximum.\n");
			}
			else
			write(skills[i]+" from "+current+" to "+new+" cost: "+expcost+"\n");
			i+=1;
		}
		return 1;
	}
	if(expcost > minexp) {
		write("You do not have enough available experience to train in that skill.\n");
		return 1;
	}
	this_player()->add_exp(-expcost);
	guild_ob->add_skill(str,1);
	this_player()->add_guild_exp(expcost);
	this_player()->save_me();
	return 1;
}

get_rank_exp(arg) {
	rankxp=allocate(10);
	rankxp[1] = 0;
	rankxp[2] = 15000;
	rankxp[3] = 60000;
	rankxp[4] = 140000;
	rankxp[5] = 460000;
	rankxp[6] = 800000;
	rankxp[7] = 1175000;
	rankxp[8] = 1600000;
	return rankxp[arg];
}

skill_setup() {
	skills = allocate(num_skill+1);
	skills[0]="sword";
	skills[1]="knife";
	skills[2]="axe";
	skills[3]="club";
	skills[4]="bow";
	skills[5]="polearm";
	skills[6]="shield";
}
