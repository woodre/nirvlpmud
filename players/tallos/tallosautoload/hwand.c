inherit "obj/treasure";
#include "/players/pain/color.h"
#define HDIR "players/pain/NEW/items/healing/"
#define tpn environment(this_object())->query_name()
#define tpm environment(this_object())->query_money()
#define tpg environment(this_object())->query_guild_name()
#define tps environment(this_object())->query_sp()
#define tph environment(this_object())->query_hp()
#define MAXS environment(this_object())->query_msp()
#define MAXH environment(this_object())->query_mhp()
#define wvalue present(what,environment(environment(this_object())))
#define heal_msg "You wave the wand and are surrounded by a blue aura.\nYou begin to feel much better.\n"

int charge;
int div;
static int waste;


init_arg() {
	if(restore_object(HDIR+this_player()->query_real_name())) {
		write("Restoring Healing Wand information. . .\n");
		write("Some of the healing power of the wand has"+
		      "dissapated in your absence.\n");
		waste = random(40);
		if(charge < waste) { waste = charge; }
		charge = charge - waste;
		q_save();
	}
	else {
		write("Creating Healing Wand file . . . \n");
		h_save();
	}
}

query_auto_load() { return "players/pain/NEW/items/hwand.c:"; }

reset(arg) {
	if(arg) return;
set_weight(1);
set_value(1000+charge*div);
short_desc = "A knarled old wand";
long_desc = 
	"This is an ancient wand carved out of solid oak.\n"+
	"As you gaze at it you think you can see a healing\n"+
	"energy pulsing through its twists and knobs.\n"+
	"Perhaps you could learn more about it by typing\n"+
	"<healing>.\n"+
	"You see that the wand has a value of $"+charge*div+
	" and a total charge of "+charge+" remaining.\n";

set_stuff();
}

init() {
	add_action("healing", "healing");
	add_action("heal", "heal");
	add_action("charge_wand", "charge");
	add_action("set_stuff", "set_stuff");
	add_action("heals", "heals");
	add_action("h_restore", "h_restore");
	add_action("h_save", "h_save");
	add_action("q_save", "q_save");
}

healing() {
	cat("/players/pain/NEW/items/heal");
	return 1;
}

charge_wand(str) {
int amt;
string what;

if(!str) {
	write("Usage: <charge wand #coins>.\n");
	return 1;
}

sscanf(str, "%s %d",what,amt);
if(!amt) {
	write("You must specify an amount to charge.\n");
	return 1;
}
if(what != "wand") {
	write("What would you like to charge?\n");
	return 1;
}
if(tpm < amt) {
	write("You do not have that many coins.\n");
	return 1;
}

if(tpg == "Knights Templar") { div = 35; }
if(tpg == "vampire") { div = 30; }
if(tpg == "bard") { div = 30; }
if(tpg == "monk") { div = 30; }
if(tpg == "undead") { div = 35; }
if(tpg == "cyberninja") { div = 40; }
if(tpg == "polymorph") { div = 35; }
if(tpg == "shardak") { div = 35; }
if(tpg == "rangers") { div = 40; }
if(tpg == "mage" ) { div = 30; }

charge = charge + (amt / div);
this_player()->add_money(-amt);
write("You charge the wand with $"+amt+". The wand now contains "+charge+
      " total charge.\n");
h_save();
set_stuff();
return 1;
}

h_save() {
   save_object(HDIR+this_player()->query_real_name());
   write("Saving Heal Wand Information...\n");
   set_stuff();
   return 1;
}

h_restore() {
   restore_object(HDIR+this_player()->query_real_name());
   write("Restoring Heal Wand Information...\n");
   set_stuff();
   return 1;
}

set_stuff() {
short_desc = "A knarled wand <$"+charge*div+">";
long_desc = 
        "This is an ancient wand carved out of solid oak.\n"+
        "As you gaze at it you think you can see a healing\n"+
        "energy pulsing through its twists and knobs.\n"+
        "Perhaps you could learn more about it by typing\n"+
        "<healing>.\n"+
        "You see that the wand has a value of $"+charge*div+
        " and a total charge of "+charge+" remaining.\n";
return 1;
}

heals() {
write(charge+" heals remaining.\n");
return 1;
}

heal(str) {

if(!str || (str != "s" && str != "h")) {
	if(charge == 0) {
		write("No healing remaining.\n");
		return 1;
	}
        if(charge < 40) {
		write("Not enough healing remaining.\n");
		this_player()->heal_self(charge);
		charge = 0;
		write("0 healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
	if((MAXH-tph) < 40) {
		this_player()->heal_self(40);
		charge = charge - 40;
		write(heal_msg);
		write(charge+" healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
	if((MAXH-tph) > charge) {
		this_player()->heal_self(charge);
		charge = 0;
		write("Not enough healing for a full heal.\n");
		write("No healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
	else {
            	charge = charge - (MAXH-tph);
		this_player()->heal_self(MAXH-tph);
		write(heal_msg);
		write(charge+" healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
}

if(str == "s") {
	if(charge == 0) {
		write("No healing remaining.\n");
		return 1;
	}
	if(charge < 40) {
		write("Not enough healing remaining.\n");
		this_player()->add_sp(charge);
		charge = 0;
		write("0 healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
	if((MAXS-tps) < 40) {
		this_player()->add_sp(40);
		charge = charge - 80/3;
		write(heal_msg);
		write(charge+" healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
        if((MAXS-tps) > charge) {       
                this_player()->add_sp(charge);
                charge = 0;
                write("Not enough healing for a full heal.\n");
                write("No healing remaining.\n");
                set_stuff();
                q_save();
                return 1;
        }
	else {
            charge = charge - ((MAXS-tps)*2)/3;
		this_player()->add_sp(MAXS-tps);
		write(heal_msg);
		write(charge+" healing remaining.\n");
		set_stuff();
		q_save();
		return 1;
	}
}

if(str == "h") {
	if(charge == 0) {
                write("No healing remaining.\n");
                return 1;
        }
        if(charge < 40) {
                write("Not enough healing remaining.\n");
                this_player()->add_hp(charge);
                charge = 0;
                write("0 healing remaining.\n");
                set_stuff();
		q_save();
                return 1;
        }
        if((MAXH-tph) < 40) {
                this_player()->add_hp(40);
                charge = charge - 80/3;
                write(heal_msg);
                write(charge+" healing remaining.\n");
                set_stuff();
		q_save();
                return 1;
        }
        if((MAXH-tph) > charge) {       
                this_player()->heal_self(charge);
                charge = 0;
                write("Not enough healing for a full heal.\n");
                write("No healing remaining.\n");
                set_stuff();
                q_save();
                return 1;
        }
        else {
                 charge = charge - ((MAXH-tph)*2)/3;
                this_player()->add_sp(MAXH-tph);
                write(heal_msg);
                write(charge+" healing remaining.\n");
                set_stuff();
                q_save();
                return 1;
        }
}

else {
	return 0;
}

}

id(str) { return str == "wand"; }
q_save() {
save_object(HDIR+this_player()->query_real_name());
return 1;
}
drop() { return 1; }
