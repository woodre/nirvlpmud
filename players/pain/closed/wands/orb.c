inherit "/obj/treasure";
#include "/players/pain/color.h"
#define N_DIR "players/pain/closed/wands/skills/"
#define TP this_player()
#define tpn this_player()->query_name()
#define tpm this_player()->query_money()
#define tpi this_player()->query_attrib("int")
#define tpw this_player()->query_attrib("wis")
#define tps this_player()->query_attrib("str")
#define tpl this_player()->query_attrib("luc")

int n_skill;
static status readied;
int color;
int charge;
static object ob;

set_charge(str) { charge = str; }
query_charge() { return charge; }
query_readied() { return readied; }

init_arg() {
if(restore_object(N_DIR+this_player()->query_real_name())) {
	write("Restoring Necromancy Skills...\n");
	return 1;
}
else { n_save(); return 1; }
}

short() { return "An Onyx Orb ["+RED+charge+END+"]"; }

long() { write("This is a solid onyx orb carved out from the \n"+
	"depths of the earth. You can feel the power coursing\n"+
	"through it. Perhaps you should <ready> it to use it to \"cast\"\n"+
	"a spell. You think that you might be able to cast the\n"+
	"Deathball spell of the Necromancer with this orb.\n"+
        "\n<"+RED+"orb_help"+END+"> for more information.\n"); }

id(str) { return str == "orb" || str == "wand"; }

init() {
    add_action("cast", "cast");
	add_action("practice", "practice");
	add_action("exit_teach","exit_teach");
	add_action("exit_teach2","exit_teach2");
	add_action("exit_final", "exit_final");
	add_action("orb_color", "o_color");
	add_action("charge_wand", "infuse");
	add_action("ready", "ready");
	add_action("unready", "unready");
	add_action("setstuff", "setstuff");
	add_action("helpme", "orb_help");
	add_action("n_save", "n_save");
	add_action("n_restore", "n_restore");
	add_action("quiet_save","quiet_save");
	readied = 0;
}

helpme() {
	cat("/players/pain/closed/wands/helps/orb_help");
	return 1;
}

practice(str) {
int exp;

if(restore_object(N_DIR+this_player()->query_real_name())) {
write("Restoring Necromancy Skills...\n");
}

else { n_save(); }
ob = this_player();

if(!str) {
	write("What do you want to practice?\n");
	return 1;
}
if(str != "necromancy") {
	write("The orb cannot teach you that!\n");
	return 1;
}

if(n_skill == 10) {
	write("You cannot train that skill any higher!\n");
	return 1;
}

exp = this_player()->query_exp()-call_other("room/adv_guild","get_next_exp",this_player()->query_level()-1);

if(exp < 20000) {
	write("You do not have enough experience to attempt this "+
	      "training.\n");
	return 1;
}
this_player()->add_exp(-20000);
write("A cloud of black fog appears.\n.\n..\n...\n\n");
write("When it clears an old Necromancer stands before you.\n");
write("Exit says: So you want to learn Necromancy do you?\n");
write("Exit lafs.\n");
write("Exit says: Well, let's begin.\n");
call_out("exit_teach",10);
call_out("exit_teach2",20);
call_out("exit_final",100);
n_skill++;
quiet_save();
return 1;
}
exit_teach() {
tell_object(ob, "Exit summons a Deathball and casts it across the room.\n");
tell_object(ob, "You attempt to do the same and fail.\n");
return 1;
}
exit_teach2() {
tell_object(ob, "Exit casts a Deathball.\n");
tell_object(ob, "You attempt to do the same, and one feebly flies from your "+
      "fingertips.\n");
return 1;
}
exit_final() {
tell_object(ob, "Exit whispers a secret hint in your ear.\n");
tell_object(ob, "You give an 'Ahhhh' of comprehension.\n");
tell_object(ob, "You cast a Deathball again, this time it turns out rather well.\n");
tell_object(ob, "Exit congratulates you.\n");
tell_object(ob, "You feel more knowledgable about Deathballs.\n");
}

n_save() {
   save_object(N_DIR+this_player()->query_real_name());
   write("Necromancy skill stats saved...\n");
   return 1;
}

quiet_save() {
   save_object(N_DIR+this_player()->query_real_name());
   return 1;
}

n_restore() {
   restore_object(N_DIR+this_player()->query_real_name());
   write("Restoring Necromancy skill stats. . . .\n");
   return 1;
}

orb_color() {
if(color == 1) {
	write("Orb Color Disabled\n");
	color = 0;
	n_save();
	return 1;
}
if(color == 0) {
	write("Orb Color Enabled\n");
	color = 1;
	n_save();
	return 1;
}
}

charge_wand(str) {
int amt;
string what;
int amt1;


if(!str) {
	write("Usage: <infuse orb #coins>.\n");
	return 1;
}

sscanf(str, "%s %d", what, amt);

if(!amt) {
	write("You must specify an amount.\n");
	return 1;
}

if(amt < 0){ write("It must be greater than zero.\n"); return 1; }
if(what != "orb") {
	write("What do you want to infuse?\n");
	return 1;
}
if(this_player()->query_money() < amt) {
	write("You do not have that many coins.\n");
	return 1;
}

if(restore_object(N_DIR+this_player()->query_real_name()))
	write("Infusing the orb...\n");
else { quiet_save(); }

amt1 = amt / 20;
charge = charge + amt1;
this_player()->add_money(-amt);
write("You charge the orb with "+amt1+".\n");
setstuff();
return 1;
}

ready(str) {
if(!str || str != "orb") {
	write("Usage <"+RED+"ready orb"+END+">\n");
	return 1;
}
if(restore_object(N_DIR+this_player()->query_real_name())) {
	write("Restoring Necromancy skill stats. . . .\n");
}
else {
	write("Creating a Necromancy skill stats file. . .\n");
	n_save();
}
if(readied == 0 && color == 0){
write(RED+"-="+END+" You ready an onyx orb for casting "+RED
      +"=-"+END+"\n");
readied = 1;
say(tpn+" readies an onyx orb for casting.\n");
setstuff();
return 1;
}
if(readied == 0 && color == 1){
write("-= You ready an onyx orb for casting =-\n");
readied = 1;
say(tpn+" readies an onyx orb for casting.\n");
setstuff();
return 1;
}
if(readied == 1) {
write("Your orb is readied already.\n");
return 1;
}
}

unready(str) {
if(!str || str != "orb") {
	write("Usage <"+RED+"unready orb"+END+">\n");
	return 1;
}
if(readied == 1 && color == 0){
write(RED+"-="+END+" You unready your onyx orb "+
      RED+"=-"+END+"\n");
readied = 0;
say(tpn+" unreadies an onyx orb.\n");
quiet_save();
setstuff();
return 1;
}
if(readied == 1 && color == 1){
write("-= You unready an onyx orb =-\n");
readied = 0;
say(tpn+" unreadies an onyx orb.\n");
quiet_save();
setstuff();
return 1;
}
}

static cast() {
int cost;
object att;
string attn;
int damage;

if(readied == 0) {
	write("You must have the orb readied to cast!\n");
	return 1;
}

if(!this_player()->query_attack()) {
	write("You must be attacking someone to cast.\n");
	return 1;
}
if(this_player()->query_attack()->is_player()) {
	write("You may not attack players with this spell.\n");
	return 1;
}

damage = n_skill*5/2 + random(10);
if(damage < 0) {
  write("Perhaps you should study necromancy a bit more.\n");
  return 1;
}
if(damage > 35) { damage = 35; }
cost = damage + random(tpw) - random(tpl);
if(cost < 10) {
	cost = 10;
}
if(charge < cost) {
	write(RED+"The orb does not have enough charge to cast!"+END+"\n");
	return 1;
}
charge = charge - cost;
quiet_save();
if(random(10) < 2) {
	write("Your Deathball fizzles.\n");
	this_player()->hit_player(random(11));
	setstuff();
	return 1;
}

att = this_player()->query_attack();
attn = att->query_name();

if(damage < 11) {
/*
write("You hit "+attn+" with a "+BLUE+" deathball "+END+
	"and nog with destructive pleasure.\n");
tell_object(att, "You are hit by a "+BLUE+" Deathball"+END+"!\n");
say(tpn+" nogs with destructive pleasure as a "+BLUE+"Deathball"+END+
	" hits "+attn+"\n");
att->hit_player(damage);
*/
TP->spell_object(att,"Deathball",damage,0,"You hit "+attn+" with a "+BLUE+" deathball "+END+" and nog with destructive pleasure\n","You are hit by a "+BLUE+" Deathball"+END+"!\n",tpn+" nogs with destructive pleasure as a "+BLUE+"Deathball"+END+" hits "+attn+"\n");
setstuff();
return 1;
}

if(damage > 10 && damage < 21) {
/*
write("You grig with glee as your "+YELLOW+" deathball"+END+
	" rips into "+attn+"!\n");
tell_object(att, "You feel a "+YELLOW+" Deathball"+END+" rip into "+
	"you, tearing at your soul.\n");
say(tpn+" grigs with glee as a "+YELLOW+" Deathball"+END+" rips into "+
	attn+".\n");
att->hit_player(damage);
*/
TP->spell_object(att,"Deathball",damage,0,"You grig with glee as your "+YELLOW+" deathball"+END+" rips into "+attn+"!\n","You feel a "+YELLOW+" Deathball"+END+" rip into "+"you, tearing at your soul.\n",tpn+" grigs with glee as a "+YELLOW+" Deathball"+END+" rips into "+attn+".\n");
setstuff();
return 1;
}

if(damage > 20) {
/*
write("You cackle with orgasmic pleasure.\nYour "+RED+"deathball"+END+
	" shreds the very fiber of "+attn+"'s soul.\n");
tell_object(att, "You feel a "+RED+"Deathball"+END+" shred the very fiber"+
	"of your being.\n");
say(tpn+" cackles with orgasmic pleasure as a "+RED+"Deathball"+END+" shreds "+
	attn+"'s soul\n");
att->hit_player(damage);
*/
TP->spell_object(att,"Deathball",damage,0,"You cackle with orgasmic pleasure.\nYour "+RED+"deathball"+END+" shreds the very fiber of "+attn+"'s soul.\n","You feel a "+RED+"Deathball"+END+" shred the very fiber"+"of your being.\n",tpn+" cackles with orgasmic pleasure as a "+RED+"Deathball"+END+" shreds "+attn+"'s soul\n");
setstuff();
return 1;
}
}


setstuff() {
if(readied == 0) {
	this_object()->set_short("An Onyx Orb ["+RED+charge+
	    END+"]");
	return 1;
}
if(readied == 1) {
	this_object()->set_short("An Onyx Orb ["+RED+charge+
	    END+"] ("+BLUE+"readied"+END+")");
return 1;
}
}
