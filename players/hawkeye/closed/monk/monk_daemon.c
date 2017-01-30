/*----------------------------------------------------------------------*/
/*      The new and improved daemonized monk guild object               */
/*                                                                      */
/*      Edited and improved by Pain 30 OCT 94                           */
/*      version 1.0                                                     */
/*                                                                      */
/*----------------------------------------------------------------------*/

/*                  INCLUDES and DEFINITIONS                            */
#include "/players/hawkeye/closed/monk/color.h"
#include "/players/hawkeye/closed/monk/m_defs.h"
#include "/players/hawkeye/closed/monk/monk_say.c"
#include "/players/hawkeye/closed/monk/special_attack"
#define ME capitalize(this_player()->query_name())
#define HOME "/players/hawkeye/workroom"
#define IT capitalize(obj->query_name())
#define LVLAC this_player()->set_ac
#define POBJ "/players/hawkeye/closed/monk/testobj"
inherit "obj/treasure";

int failed;

reset(){
	move_object(this_object(),HOME);
}
/* -- GONE -- */
gone() {
 write("sorry, that command is now longer avaliable.\n");
 return 1;  }


/* ------ MEND (get new guild object) -------- */
register() {
	object ob, new_robe;
	int rank, exp, sh, stam, loan, wat, wmp, myac;
	string wir;
	object crapola;
crapola = present("mrobe",this_player());

	new_robe = clone_object("players/hawkeye/closed/monk/testobj");
	rank = this_player()->query_guild_rank();
	exp = this_player()->query_guild_exp();
	wat = this_object()->query_wimp_at();
	wmp = this_object()->query_wimp();
	wir = this_object()->query_wimp_dir();
	muffled = this_object()->query_muffled();
	new_robe->set_muffled(muffled);
	new_robe->set_guild_rank(rank);
	new_robe->set_wimp(wmp);
	new_robe->set_wimp_at(wat);
	new_robe->set_wimp_dir(wir);
	new_robe->set_guild_exp(exp);
	new_robe->setum_color(color);
	new_robe->setum_how_often(how_often);
	move_object(new_robe, this_player());
	if(stunwho)
		stunwho->set_wc(stunwc);
	myac = this_player()->query_ac();
	this_player()->set_player_killing(0);
	this_player()->add_ac(-myac);
	if(this_player()->query_guild_rank() < 4)
		this_player()->add_ac(4);
	if(this_player()->query_guild_rank() == 4)
			this_player()->add_ac(4);
	if(this_player()->query_guild_rank() > 4 &&
	   this_player()->query_guild_rank() < 9)
		this_player()->add_ac(7);
	if(this_player()->query_guild_rank() > 8)
		this_player()->add_ac(9);
	if(present("shield_obj", this_player())){
		sh = present("shield_obj", this_player())->query_shields();
		this_player()->add_ac(sh * 2);       }
	destruct(crapola);
	if(color == 1)
		write(CYA+"Your robes have been mended.\n");
	else
		write("Your robes have been mended.\n");
	this_player()->set_guild_name("monk");
command("newspeed",this_player());
return 1;
}

/* -- SET COLOR (turn colors on/off) -- */
set_color(str){
	if(!str && color == 0){
		write("Color On.\n");  color = 1;  return 1; }
	if(!str && color == 1){
		write("Color off.\n");  color = 0;  return 1; }
	if(str == "on" || str == "1"){
		write("Color on.\n");  color = 1;  return 1; }
	if(str == "off" || str == "0"){
		write("Color off.\n");  color = 0;  return 1; }
}

/* --- SANC --- */
sanc() {
object sanc;

if(this_player()->query_sp() < 50){
	write("You do not have the energy to perform this.\n");
	return 1; 
}
if(this_player()->query_guild_rank() < 2) {
	write("You must be a higher level to do this!\n");
	return 1;
}
if(present("sanc", this_player())) {
	write("You are already under a sanctuary.\n");
	return 1;  }
sanc = clone_object("players/hawkeye/closed/monk/sanc");
move_object(sanc, this_player());
command("abcblah", this_player());
this_player()->add_spell_point(-50);
write("You begin to meditate and heal the wounds of your mind and body.\n");
return 1;
}


/* ------ NEW SCORE (show score) --------- */
rank() {
	command("sc",this_player());
	write("\n");
	write("Guild Rank: "+this_player()->query_guild_rank());
	write("          Guild Experience: "+
	this_player()->query_guild_exp()+"\n");
	if(muffled == 1) {
		write("Monk Channel: Muffled     ");
	} else
		write("Monk Channel: Open        ");
   write("\n");
	write("Location: "+
	environment(this_player())->short() + "\n");
	write("Current Time: "+ctime()+"\n");
	write("\n\n");
   return 1;
}



/* ---------- NIRVANA WHO (logged on) ----------- */
nirvana_who(){
	int count;
	string who,guild;
	string gender;
	int x;
	object ob;
	object mas,monk,as,dopp;
	ob = users();

write("--------------------------------------------------------------------------------\n");
write("Name:           Lvl:      Pk:     Guild:     Sex:     Location:\n");
write("--------------------------------------------------------------------------------\n");
for(x=0;x<sizeof(ob);x+=1){
if(ob[x]->query_level() < 1000000){
if(ob[x]->query_invis() == 0){
who = ob[x]->query_real_name();
who = capitalize(who);
count = strlen(who);
count = 16 - count;
write(who);
while(count>0){
write(" ");
count = count - 1;
}
write(ob[x]->query_level()+"\t");
if(ob[x]->query_pl_k() == 1){write("  Yes     ");}
if(ob[x]->query_pl_k() == 0){write("  No      ");}
guild = ob[x]->query_guild_name();
if(present("medal",ob[x])) {write("Paladin    ");}
else
if(present("instrument", ob[x])) {write("Bards      ");}
else
if(present("mrobe", ob[x])) {write("Monk       ");}
else
if(present("life", ob[x])) {write("Undead     ");}
else
if(present("black robes", ob[x])) {write("Mage       ");}
else
if(present("vampirefangs", ob[x])) {write("Vampire    ");}
else
if(present("mark", ob[x])) {write("Shadrak    ");}
else
if(present("badge", ob[x])) {write("Dopple     ");}
else
write("None       ");
gender= ob[x]->query_gender();
if(gender == "male") {write("M        ");}
if(gender == "female") {write("F        ");}
if(gender == "creature") {write("C        ");}
if(!environment(ob[x])){
write("Location Unknown\n");
}
if(environment(ob[x])){
write(environment(ob[x])->short()+"\n");
}
}
}
}
write("--------------------------------------------------------------------------------\n");
write("Total Number of Players: "+x+"\n");
write("--------------------------------------------------------------------------------\n");
return 1;
}

/* --------- BURN (drain a corpse) -------------- */
burn(str) {
   object target;
   int heal;

if(str && str != "corpse") {
	write("Usage: burn corpse.\n");
	return 1;
	}
target = present("corpse",environment(this_player()));
if(!target) {
	write("There is no corpse here to burn.\n");
	return 1;
	}
write("You light the corpse on fire and watch the body burn away.\n"+
      "You spread the ashes in a circle around you and absorb energy\n"+
      "from the freed spirit.\n");
say(ME+" burns a corpse.\n");
heal = target->heal_value();
this_player()->heal_self(heal);
destruct(target);
return 1;
}

/* -------- TITHE (remote sell) --------------- */
xsell(str) {
	string item;
	object itemob;
	int val;

if(this_player()->query_guild_rank() < 4) {
write("You must obtain a higher rank in the Guild to use this ability.\n");
return 1;
}
if(!str || sscanf(str, "%s", item) != 1) {
	write("Useage:  tithe <item>\n");
	return 1;
	}
itemob = present(item, this_player());
if(!itemob) {
	write("You do not have a "+item+".\n");
	return 1;
	}
call_other(this_player(),"add_spell_point", -10);
val = call_other(itemob, "query_value");
if(val > 0) {
	if(val > 1000) {
		val = 1000 + random(600);
		}
	call_other(this_player(),"add_money", val);
	destruct(itemob);
	write("You place the "+item+" on the ground before you\n"+
	      "and slowly move your hands above it.  The object burst\n"+
	      "into a small flame, when it burns away, a small pile of\n"+
	      "coins is left in the ashes. You pick up "+val+" coins.\n");
	say(ME+" places a "+item+" on the ground.  The object burst into\n"+
	    "flame and disappears.  A pile of coins remains in the ashes.\n"+
	    ME+" picks them up.\n");
	return 1;
	}
write("This Item has no value and is not worth\n"+
      "expending your energy on.\n");
return 1;
}

/*------------------------------CURE FLU-----------------------------*/
cure_flu() {
    object flu;
flu = present("flu",this_player());
if(!flu) {
   write("You do not have the flu.\n");
return 1;
}
if(this_player()->query_guild_rank() < 2) { 
   write("You must attain a higher rank in the Guild to use this ability.\n");
return 1;
}
if(this_player()->query_sp() < 75) {
write("You are too low on Spell Points.\n");
return 1;
}
destruct(flu);
this_player()->add_spell_point(-75);
write("You have been cured of the flu.\n");
return 1;
}
/* ------ EMOTE ---------- */
emote(str) {
   string me;
   
	if(!str) {
		write("Emote what?\n");
		return 1;
		}
	me = capitalize(this_player()->query_real_name());
	tell_room(environment(environment()),me+" "+str+"\n");
	return 1;
}


/* -------------- Speed ---------------- */
speed() {
	object obj;

if(this_player()->query_guild_rank() < 3) {
	write("You are too low of Rank to do this.\n");
	return 1;
	}

if(present("monk_speed",this_player())) {
	write("You already have a speedster.\n");
	return 1;
	}

  obj = clone_object("players/hawkeye/closed/monk/monk_speed");
move_object(obj,this_player());
write("You take a speedster out of your Monk Robes.\n");
return 1;
}

/* ------ ESCAPE (take me back to guild) ----- */
escape(){
object gary;
gary = this_player();
if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 40) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}
if(environment(gary)->realm() =="NT") {
     write("You are not allowed to do that here!\n");
     return 1;
}
write("You grab several capsules from the many folds of your robes and\n"+
      "hurl them at the ground.  The tiny objects burst in a brilliant flash!\n"+
      "You open your eyes to the safety of the Guild Hall.\n");
write("\n");
say(ME+" grabs something out of the folds of his Monk Robes and hurls\n"+
    "the tiny objects at the ground.  They explode in a brilliant flash of\n"+
    "light, and when next you can see, "+ME+" is gone!\n");
move_object(gary, "players/hawkeye/closed/guild/guild_room");
command("look", gary);
this_player()->add_spell_point(-40);
return 1;
}

/* ------ MONK TELL ----------- */
monk_tell(str) {
	object ob, guild, monk;
	int i, happy;
	string me, mess;

me = this_player();
monk = this_object();
if(!str) {
	Write("Tell guildmembers what?\n");
	return 1;
	}
mess = "["+capitalize(me->query_real_name())+"]: "+str;
ob = users();
for(i = 0; i < sizeof(ob); i++) {
	guild = present("mrobe", ob[i]);
	if(guild && guild->query_muffled() == 0) {
	if(guild->query_color() == 1){
		happy = random(6)+1;
		if(happy == 1) tell_object(ob[i], WHI+mess+"\n");
		if(happy == 2) tell_object(ob[i], CYA+mess+"\n");
		if(happy == 3) tell_object(ob[i], PUR+mess+"\n");
		if(happy == 4) tell_object(ob[i], GRE+mess+"\n");
		if(happy == 5) tell_object(ob[i], BLU+mess+"\n");
		if(happy > 5) tell_object(ob[i], mess+"\n");
		} else
	tell_object(ob[i],"[" +capitalize(me->query_real_name()) +"]: " +str+"\n");
	}
}
return 1;
}

/*-------- MONK EMOTE ------------ */
monk_emote(str) {
	object ob, guild;
	int i, x;
	string me;
   
me = this_player()->query_name();
if(!str) {
	write("Usage: me <emote string>\n");
	return 1;
	}
x= random(6);
ob = users();
for(i = 0; i < sizeof(ob); i++) {
	guild = present("mrobe", ob[i]);
	if(guild && guild->query_muffled() == 0) {
	if(x > 3)
		tell_object(ob[i],"\n->> "+me+" "+str+"\n");
	else
		tell_object(ob[i],"\n"+me+" "+str+"\n");
	}
}
return 1;
}


/* ------ COMMANDER TELL ----------- */
commander_tell(str) {
	object ob, guild;
	int i;
	string me;

me = this_player();
if(!str) {
	Write("Tell commanders what?\n");
	return 1;
	}
ob = users();
for(i = 0; i < sizeof(ob); i++) {
	guild = present("mrobe", ob[i]);
	if(guild && guild->query_muffled() == 0 &&
	   guild->query_guild_rank() > 19) {
		tell_object(ob[i], "{"+capitalize(me->query_real_name())+"}: "+
		str+"\n");
		}
}
return 1;
}

/*-------- COMMANDER EMOTE ------------ */
commander_emote(str) {
	object ob, guild;
	int i;

if(!str) { write("Commander emote what?\n"); return 1;  }
ob = users();
for(i = 0; i < sizeof(ob); i++) {
	guild = present("mrobe", ob[i]);
if(guild && guild->query_muffled() == 0 &&
   guild->query_guild_rank() > 19) {
	tell_object(ob[i], "\n|> "+capitalize(this_player()->query_name())+
	" "+str+"\n");
	}
}
return 1;
}

/* -------- MONKKICK ---------- */
monk_kick(str){
	object obj;
	int dmg;

if(this_player()->query_guild_rank() < 2) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!this_player()->query_attack()){
	write("You must be fighting to Mkick.\n");
	return 1; }
if(!str)
	obj = this_player()->query_attack();
else
	obj = present(str, environment(this_player()));

if(!obj){
	write("That is not here.\n");
	return 1; }
if(obj->query_npc() != 1){
	write("You cannot Mkick a player.\n");
	return 1; }

write("You kick "+IT+" in the face with a stunning circle kick!\n");
say(ME+" kicks "+IT+" in the face with a stunning circle kick!\n");
dmg = 10 + random(this_player()->query_guild_rank());
if(obj->query_hp() < dmg) 
	dmg = obj->query_hp();
obj->hit_player(dmg);
this_player()->add_spell_point(-(10+this_player()->query_guild_rank()));
/* cost raised by 10, no 1sp to 1dam -Bp */
return 1;
/*Cost put back, it can only be one to one at the BEST random number, 
other wise its less than 1 to 1 - GH*/
}

/* -------- EINV (inventory guild locker) ----- */
equip_inv() {
	object trash, trash1, trash2, troom;

if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}

trash = clone_object("players/hawkeye/closed/monk/equip_obj");
move_object(trash, environment(this_player()));
move_object(this_player(), "players/hawkeye/closed/guild/equip_room");
command("look at locker", this_player());
move_object(this_player(), environment(trash));
destruct(trash);
return 1;
}

/* ------- EGET (get from locker) --------- */
equip_take(str) {
	object ob, obj, ob1;
	int wt;

if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 5) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}


if(!str) {
	write("Usage: etake <item>.\n");
	return 1;
	}


ob = clone_object("players/hawkeye/closed/monk/equip_obj.c");
move_object(ob, environment(this_player()));
move_object(this_player(), "players/hawkeye/closed/guild/equip_room");
command("get "+str+" from locker", this_player());
move_object(this_player(), environment(ob));
write("You concentrate carefully on the contents of the\n"+
      "storage locker.  The "+str+" appears in your hands!\n");
say(ME+" concentrates for a moment and a "+str+" suddenly\n"+
    "appears in his hands!\n");
this_player()->add_spell_point(-5);
destruct(ob);
return 1;
}

/* ----- EPUT (put in guild locker) ------ */
equip_put(str) {
	object ob, ob1, obj;
	int wt;

if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 5) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str) {
	write("Usage: eput <item>.\n");
	return 1;
	}

obj = present(str, this_player());
if(!obj) {
	write("You do not have a "+str+".\n");
	return 1;
	}

ob = clone_object("players/hawkeye/closed/monk/equip_obj.c");
move_object(ob, environment(this_player()));
move_object(this_player(), "players/hawkeye/closed/guild/equip_room");
command("put "+str+" in locker", this_player());
move_object(this_player(), environment(ob));
write("You concentrate on the Storage locker and send\n"+
      "the "+str+" to it.\n");
say(ME+" concenrates briefly and an object disappears!\n");
this_player()->add_spell_point(-5);
destruct(ob);
return 1;
}

/* ------ $DONATE (remote donatation) ------ */
donate(str) {
	object ob, ob1;

ob = clone_object("players/hawkeye/closed/monk/equip_obj");
move_object(ob, environment(this_player()));
move_object(this_player(), "players/hawkeye/closed/guild/equip_room");
command("deposit "+str, this_player());
move_object(this_player(), environment(ob));
destruct(ob);
return 1;
}
/*-------------Check to see when Reboot is-------------*/
clock() {
object ob;
ob = clone_object("/players/hawkeye/closed/monk/equip_obj");
move_object(ob, environment(this_player()));
move_object(this_player(),"room/church");
command("look at clock",this_player());
move_object(this_player(),environment(ob));
destruct(ob);
return 1;
}

/* ---- FOLLOW (follow another player...) -------- */
follow(str){
	object monk, victim;

monk = present("mrobe", this_player());
if(this_player()->query_sp() < 15) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(str == "off"){
	write("Follow has been turned off\n");
	set_heart_beat(0);
	follow = 0;
	return 1;
	}
followee = find_player(str);
if(!present(str, environment(this_player()))){
	write("That is not here.\n");
	return 1;
	}
if(followee->query_level() > 20){
	write("You can't follow wizards.\n");
	return 1;
	}
if(!str){
	write("Usage: follow <who> or follow off\n");
	return 1;
	}
if(follow == 1){
	write("You are already following someone.\n");
	return 1;
	}
else {
	write("You begin following "+followee->query_name()+".\n");
	follow = 1;
	this_player()->add_spell_point(-15);
	set_heart_beat(1);
	return 1;
	}
}

/* ------ CAST LIGHT ---------- */
cast_light(str) {
object torch;
if(str == "light") {
if(this_player()->query_guild_rank() < 2) {
	write("You must achieve more higher guild status before\n"+
	      "you can use this ability.\n");
	return 1;
	}
if(this_player()->query_sp() < 0) {
	write("You do not have enough energy to use this ability.\n");
	return 1;
	}
this_player()->add_spell_point(-5);
write("Sparks fly from your hands....smoke rises from the ground\n"+
"The Heavens sing and a glow is about the room....\n"+
"\n\nSomeone taps you on the shoulder and the spell fizzles.\n");
write("\n\n\n");
write("Hawkeye enters the room.\n");
write("Hawkeye says: Sorry about that, i didnt mean to mess you up.\n");
write("Hawkeye says: Here, have a torch.\n");
write("Hawkeye gives you a torch.\n");
write("Hawkeye waves.\n");
write("Hawkeye leaves to his workroom.\n");
torch = clone_object("players/hawkeye/closed/monk/torch.c");
move_object(torch,this_player());
this_player()->add_money(-55);
command("light torch",this_player());
/*
if(set_light(1) >= 1) {
	write("You concentrate briefly and the room as alit with a\n"+
	      "mystical glow.\n");
	say(ME+" spreads a magical aura that lights up the room.\n");
	return 1;
	}
write("You cast a magical aura of light, but it\n"+
      "still remains to dark to see.\n");
*/
return 1;
}
}
/* -------- FARSIGHT ------------ */
farsight(str) {
   object ob;
       
if(this_player()->query_guild_rank() < 2) {
	write("You need to advance higher into the Guild before\n"+
	      "you can use this ability.\n");
	return 1;
	}
if(!str) {
	write("Usage: farsight <direction>.\n");
	return 1;
	}
  
if(this_player()->query_sp() < 15) {
	write("You do not have enough energy for this ability.\n");
	return 1;
	}
   
ob = clone_object("players/hawkeye/closed/monk/equip_obj");
move_object(ob, environment(this_player()));
write("You extend your mind to the "+str+" and see: \n");
write("\n");
command(str, this_player());
move_object(this_player(), environment(ob));
this_player()->add_spell_point(-20);
destruct(ob);
return 1;
}


/* ----------- OFFERING (sacrifice object for gexp) --- */
offering(str) {
	object ob, obj;
	string blah, blow;
	int val, suck, x;

if(this_player()->query_guild_rank() < 2) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 25) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

ob = present(str, this_player());
if(!ob){ 
	write("You do not possess a "+str+".\n"); 
	return 1; 
	}
command("drop "+str, this_player());

if(!present(str, environment(this_player()))) {
	write("You may not offer this object.\n"); 
	return 1; 
	}
val = ob->query_value();
if(val > 500)  
	val = 500+random(150);
destruct(ob);
this_player()->add_guild_exp(val);
write("You place the "+str+" on the ground before you and recite\n"+
      "a mystical chant.  The "+str+" bursts into flames and is gone!\n"+
      "You have offered the "+str+".\n");
say(ME+" places a "+str+" on the ground before them.  After reciting\n"+
    "some mystical words, the "+str+" bursts into flames and disappears!\n");
this_player()->add_spell_point(-25);
return 1;
}

/* ----- MAGBAG (a bag) ------------- */
bag() {
	object ob;
	
if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}

if(this_player()->query_sp() < 20) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}
ob = clone_object("players/hawkeye/closed/monk/magbag");
write("You pull a bag out a one of the many pockets in your robe.\n");
move_object(ob, this_player());
return 1;
}

/* ----- HEAL (self/other) ------------ */
heal_spell(str) {
	string who;
	object ob;
	int much;

if(!str){
	if(this_player()->query_guild_rank() < 3) {
		write("You must attain a higher level in the guild before\n"+
		      "using this skill.\n");
		return 1;
		}
	if(this_player()->query_sp() < 30) {
		write("You do not have the energy to perform this.\n");
		return 1;
		}
	write("You mix up a foul smelling concotion and hurriedly drink "+
	      "it\nYou instantly feel better.\n");
	this_player()->add_hit_point(30);
	this_player()->add_spell_point(-30);
	return 1; 
	}
sscanf(str, "%s %d", who, much);
if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < much) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}
ob = present(lower_case(who), environment(this_player()));
if(!ob) {
	write("That person is not in the room.\n");
	return 1;
	}
if(much < 0) { write("MUST BE A POSITIVE NUMBER!\n");
	return 1; }

write("You mix up a foul smelling brew and cram it down "+
      capitalize(ob->query_name())+"'s throat!\n"+ capitalize(ob->query_name())+
      " chokes and gasps, and turns green in the face,\n"+
      "and then appears to be better.\n");
say(ME+" stirs up a foul smelling concotion and crams it down\n"+
    capitalize(ob->query_name())+"'s throat.  "+
    capitalize(ob->query_name())+" sputters and gasps,\n"+
    "and turns a little green, then appears to be better.\n");
ob->add_hit_point(much);
this_player()->add_spell_point(-much);
return 1;
}

/* ------------ PEACE (calm a room) --------------- */
peace() {
	object ob, ob2;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 30) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

write("You raise your hands high into the air and force a\n"+
      "peace down onto this room!\n"+
      "All the fighting stops.\n");
say(ME+"'s hands shoot into the air, and with a voice of Power,\n"+
    ME+" calls Peace within this room.\n"+
    "All the fighting stops.\n");
ob2 = first_inventory(environment(this_player()));
while(ob2) {
	ob2->stop_fight();
	ob2->stop_fight();
	ob2->stop_hunter();
	ob2 = next_inventory(ob2);
	}
this_player()->add_spell_point(-30);
return 1;
}


/* ------------ TRANSFER (direct sp's to player) ---- */
transfer(str) {
	object ob, obj, ob1;
	int amt, total;
	string who;
      
if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
  
sscanf(str, "%s %d", who, amt);
if(amt < 0) {
	write("Nice Try CHUMP!.\n");
	return 1;
	}
     
if(this_player()->query_sp() < amt) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}
ob = find_player(who);
if(!ob) {
	write("Cannot locate that player.\n");
	return 1;
	}
if(present("mrobe", ob)) {
	write("You transfer some of you Energy to "+
	capitalize(ob->query_name())+".\n");
	write("You feel a little bit weaker as the energies leaves you.\n"+
	      "      "+amt+" points were transferred.\n");
	tell_object(ob, ME+" transfers some spell points to you.\n"+
		    "You can feel the fresh energy rush through your blood!\n"+
		    "     "+amt+" points were transferred to you.\n");
	this_player()->add_spell_point(-amt);
	ob->add_spell_point(amt);
	return 1;
	}
/*              For non monks the transfer has a penalty                */
total = amt - random(10);
this_player()->add_spell_point(-total);
ob->add_spell_point(amt);
write("You transfer some of your spell points to "+
capitalize(ob->query_name())+".\n");
write("You can feel the extra strain of transferring to a non-guild\n"+
      "member wear on your body.\n"+
      "     "+total+" points were transferred.\n");
tell_object(ob, ME+" transfers some spell points to you.\n"+
      "You can feel the fresh energy rush through your blood!\n"+
      "      "+total+" points were transferred to you.\n");
return 1;
}

/* ----------------- FIRST STAT COMMAND ---------- */
stat_monster(str) {
	object ob;
	int ac, nhp, wc, hp, percent;
	int maxhp,maxhp2;
  
if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 20) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str) {
	write("Usage: stat <target>.\n");
	return 1;
	}
   
ob = present(str, environment(this_player()));
if(!ob) {
	write("There is not a "+str+" here.\n");
	return 1;
	}
       
ac = ob->query_ac();
wc = ob->query_wc();
hp = ob->query_mhp();
nhp = ob->query_hp();
write("\n");
write(ob->short()+" : \n");
if(ac < 3) {
	write("Armor Class: Poor.\n"); 
	}
if(ac > 2 && ac < 7) {
	write("Armor Class: Average.\n"); 
	}
if(ac > 6 && ac < 11) {
	write("Armor Class: Good.\n"); 
	}
if(ac > 10 && ac < 20) {
	write("Armor Class: Excellent.\n"); 
	}
if(ac > 19) {
	write("Armor Class: Godly.\n"); 
	}
if(wc < 5) {
	write("Weapon Class: Poor.\n"); 
	}
if(wc > 6 && wc < 15) {
	write("Weapon Class: Average.\n"); 
	}
if(wc > 14 && wc < 20) {
	write("Weapon Class: Good.\n"); 
	}
if(wc > 19 && wc < 30) {
	write("Weapon Class: Excellent.\n"); 
	}
if(wc > 29) {
	write("Weapon Class: Godly.\n"); 
	}
if(hp < 200) {
	write("Full Health: Weak.\n"); 
	}
if(hp > 199 && hp < 300) {
	write("Full Health: Average.\n"); 
	}
if(hp > 299 && hp < 400) {
	write("Full Health: Good.\n"); 
	}
if(hp > 499 && hp < 600) {
	write("Full Health: Excellent.\n"); 
	}  
if(hp > 599) {
	write("Full Health: Godly.\n"); 
	}
maxhp = ob->query_hp();
maxhp2 = ob->query_mhp();
write("Current Health: "+(maxhp*100/maxhp2)+"%\n");
write("\n");
this_player()->add_spell_point(-20);
return 1;
}


/* ------- MONK PET (PETCOM) (Summon a Pet) ------- */
monk_pet(str) {
	object ob, obj;
	string name, type;
    string fname;
	int hubba;

fname = file_name(environment(this_player()));
if(fname != "players/hawkeye/closed/guild/guild_room"){
write("You must be in the guild room to call a pet.\n");
return 1;
}
if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 50) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
if(find_living(name+"'s pet")) {
	write("You already have a pet.\n");
	return 1;
	}

if(str == "pet") {
	hubba = random(14);
	if(hubba < 2) type = "falcon"; else
	if(hubba == 2) type = "wolf"; else
	if(hubba == 3) type = "bear"; else
	if(hubba == 4) type = "panther"; else
	if(hubba == 5) type = "wolverine"; else
	if(hubba == 6) type = "boar"; else
	if(hubba == 7) type = "snake"; else
	if(hubba == 8) type = "elephant"; else
	if(hubba == 9) type = "gorilla"; else
	if(hubba == 10) type = "rock"; else
	if(hubba == 11) type = "rhinoceros"; else
	if(hubba == 12) type = "porcupine"; else
	if(hubba > 12) type = "tiger";
	} else
if(str == "falcon" || str == "wolf" || str == "bear" ||
str == "panther" || str == "wolverine" || str == "boar" ||
str == "snake" || str == "elephant" || str == "gorilla" ||
str == "porcupine" ||
str == "rock" || str == "tiger" || str == "rhinoceros") {
	if(this_player()->query_guild_rank() < 8) {
		write("You are not of a high enough guild rank to call\n"+
		      "a specific pet.\n");
		return 1;
}
type = str;
} 
else {
	write("Invalid pet choice.  Please choose another.\n");
	return 1;
}

write("You summon a pet from the wilds.  A "+type+" answers your call.\n");
say(ME+" summons a "+type+" to his side.\n");
this_player()->add_spell_point(-50);
ob = clone_object("players/hawkeye/closed/monk/monk_pet");
ob->set_owner(name);
ob->set_type(type);
ob->go();
move_object(ob, environment(this_player()));
return 1;
}

/*
object staff;
object snake;
if(this_player()->query_guild_rank() < 9) {
    write("You must attain a higher position in the Guild to use\n"+
           "this ability.\n");
    return 1;
}
if(this_player()->query_spell_point() < 40) {
    write("You are too low on Spell Points.\n");
return 1;
}
if(!present("gary",this_player())) {
   write("You need to have a Monk Staff to Turn to a Snake.\n");
return 1;
}
attack = this_player()->query_attack();
name = attack->query_name();
staff = present("gary",this_player());
destruct(staff);
type = snake;
this_player()->add_spell_point(-40);
snake = clone_object("players/hawkeye/clsoed/monk/snake_obj");
ob->set_owner(name);
ob->set_type(type);
ob->gp();
move_object(ob, environment(this_player()));
*/
/* ---- SUMMON PET --- (PETCOM) --------- */
summon_pet() {
	object ob, obj;
	string name;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 5) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}
name = this_player()->query_real_name();
ob = find_living(name+"'s pet");
if(!ob) {
	write("You do not have a pet to summon.\n");
	return 1;
	}

ob->bring_me();
this_player()->add_spell_point(-5);
return 1;
}

/* ------ TRAVEL (PETCOM) (command pet to go direction) ---- */
pet_travel(str) {
	object ob, obj, room;
	string name;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 3) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
ob = find_living(name+"'s pet");
if(!ob) {
	write("You do not have a pet.\n");
	return 1;
	}

if(!str) {
	write("Usage: travel <dir>.\n");
	return 1;
	}

if(ob->query_type() == "wolverine" || ob->query_type() == "boar"){
	write("Due to the nature of this pet, you may not use this command.\n");
	return 1;
	}

write("You use a telepathicly command your pet to go "+str+".\n");
ob->set_follow(0);
command(str, ob);
return 1;
}

/* ---- PETEXITS (PETCOM) (show aviable exits for pet) --- */
pet_exits() {
	object ob, obj, room;
	int i,no_more,directions,direction,nbr;
	string name, blah;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
    
name = this_player()->query_real_name();
ob = find_living(name+"'s pet");
if(!ob) {
	write("You do not have a Pet.\n");
	return 1;
	}
  
obj = environment(ob);
write("Location: "+obj->short()+"\n");
if(!obj) 
	{ return 1; }
directions=obj->query_dest_dir();
i = 0;
no_more = 0;

if(!directions) {
	write("Possible Exit(s) are: \n"+
	      " no obvious exits.\n");
	return 1;
	}

nbr = sizeof(directions);
direction = 0;
if(nbr) {
	write("Possible Exit(s) are: \n");
	while(i < sizeof(directions)) {
		blah = directions[i];
		i += 1;
		write(" ["+directions[i]+"] , ");
		i += 1;
		}
	write("\n");
	return 1;
	}
}

/* --- PETEYE (PETCOM) (look through eyes of pet) ---- */
peteye(str) {
	object ob, obj, target;
	string name;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 3) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
ob = find_living(name+"'s pet");
if(!ob) {
	write("You do not have a pet.\n");
	return 1;
	}
    
obj = clone_object("players/hawkeye/closed/monk/equip_obj");
move_object(obj, environment(this_player()));
move_object(this_player(), environment(ob));
if(!str) {
	write("You look through the eyes of your Pet and see: \n");
	command("look", this_player());
	move_object(this_player(), environment(obj));
	destruct(obj);
	this_player()->add_spell_point(-3);
	return 1;
	}

write("Through your pets eyes, you study "+str+" and see: \n");
command("look at "+str, this_player());
move_object(this_player(), environment(obj));
destruct(obj);
this_player()->add_spell_point(-5);
return 1;
}

/* --- ATTAK (PETCOM) (remote attack command) ----- */
pet_attack(str) {
	object ob, obj;
	string name;
  
if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
ob = find_living(name+"'s pet");
if(!str) {
	write("What would you have your pet attack?\n");
	return 1;
	}

if(!ob) {
	write("You do not have a pet.\n");
	return 1;
	}
obj = clone_object("players/hawkeye/closed/monk/equip_obj");
move_object(obj, environment(this_player()));
move_object(this_player(), environment(ob));
write("You send a telepathic command for your pet to attack!\n");
command("attack "+str, this_player());
move_object(this_player(), environment(obj));
destruct(obj);
this_player()->add_spell_point(-10);
return 1;
}

/* -------- FREE SPEECH (tells are free after rank 4) --- */
free_speech(str) {
	object ob, obj;
	string who, what;

if(this_player()->query_guild_rank() > 0) {
	if(!str) { 
		write("Tell who?\n"); 
		return 1; 
		}
		
sscanf(str, "%s %s", who, what);
ob = find_player(who);
if(!ob) ob=find_living(ob);
if(!ob) {
	write(capitalize(who)+" is not logged on.\n");
	return 1;
	}
if(in_editor(ob)) {
	write("Sorry, that person is editing.\n");
	return 1;
}

tell_object(ob, ME+" tells you: "+what+"\n");
tell_object(this_player(), "You tell "+who+": "+what+"\n");
if(this_player()->query_guild_rank() < 4) {
         if(this_player()->query_sp() > 5) {
     this_player()->add_spell_point(-5);
}
}
return 1;
}
}

/*-------------------------Fast Tells---------------------*/
/*
fast_tell(str) {
object who;
string what;
who = find_player(POBJ->TOLDTO);
if(!who) who = find_living(who);
if(!who) {
    write(capitalize(who) +" is not logged on.\n");
       return 1;
          }
sscanf(str, "%s",what);
if(in_editor(who)) {
    write("Sorry, that person is editing.\n");
     return 1;
}
tell_object(who, ME+" tells you: "+what+"\n");
tell_object(this_player(),"You tell "+who+": "+what+"\n");
}
*/
/* --- STAFF (get a monk staff) --- */
get_staff(){
	object ob;

if(this_player()->query_sp() < 30) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(present("staff", this_player())){
	write("You already have a staff.\n");
	return 1;   
	}

ob = clone_object("players/hawkeye/closed/monk/monk_staff");
move_object(ob, this_player());
write("You now have a Monk Staff.\n");
this_player()->add_spell_point(-30);
return 1;
}

/* ------- CASH (dont know if it will go in yet...) ----- */
cash(str){
	object obj;
	int damage;

if(this_player()->query_guild_rank() < 5) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}

if(!this_player()->query_attack()){
	write("You must be fighting to use this spell.\n");
	return 1; 
	}

if(!str && !this_player()->query_attack()){
	write("Usage: cash <target>.\n");
	return 1; 
	}

if(!str && this_player()->query_attack())
	obj = this_player()->query_attack();
else
	obj = present(str, environment(this_player()));

if(!obj){
	write("That is not here.\n");
	return 1; 
	}

if(obj->query_npc() != 1){
	write("You cannot use this spell on a player.\n");
	return 1; 
	}

if(this_player()->query_money() < 500){
	write("You are to poor to use this spell.\n");
	return 1; 
	}

say(ME+" tosses some coins into the air.\n"+
    "The coins burst into flame and drive into "+IT+"!\n");
write("You reach into your purse and pull out some coins.\n"+
      "You toss the coins into the air and use your magical energy to make\n"+
      "them burst into flame and set fire to your enemy!\n");
damage = (25+random(30));
if(damage > obj->query_hp())
damage = obj->query_hp();
obj->hit_player(damage);
this_player()->add_money(-(200 + random(200)));
return 1;
}

/*------------INFOSHEET------------------------*/
info_sheet(str) {
object sheet;
sheet = clone_object("/players/hawkeye/closed/guild/infosheet.c");
if(!str) {

   write("Who do you want to give a sheet to?\n");
return 1;
}
if(!present(str,environment(this_player()))) {
write("That player is not here.\n");
return 1;
}
move_object(sheet,str);
write("You give an information sheet to "+str+" \n");
tell_object(str,"You get an information sheet on the Monks\n");
return 1;
}
/*----------------------------CHOP-----------------------*/
chop(str){
	object obj;
	int dmg;

if(this_player()->query_guild_rank() < 2) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 20) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!this_player()->query_attack()){
	write("You must be in battle to use Chop.\n");
	return 1; 
	}

if(!str && !this_player()->query_attack()){
	write("Usage: chop <target>.\n");
	return 1; 
	}

if(!str)
	obj = this_player()->query_attack();
else
	obj = present(str, environment(this_player()));
if(!obj){
	write("That is not here.\n");
	return 1; 
	}

if(obj->query_npc() != 1){
	write("You cannot Chop another player.\n");
	return 1; 
	}

write("You pull back your robes and with a mighty hand you chop "+
      "the crap out of "+IT+"!\n");
say(ME+" reaches out with a mighty hand and chops "+IT+"!\n");
obj->hit_player(5+random(15));
this_player()->add_spell_point(-20);
return 1;
}

/* -------- CONSIDER ------------ */
consider(str) {
	object target;
	int strength, power;
	string rating;

if(this_player()->query_guild_rank() < 7) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 30) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

target = present(str, environment(this_player()));
if(!target){
	write("No "+str+" here.\n");
	return 1;
	}

if(!living(target)){
       write(capitalize(str)+" is not a living thing.\n");
       return 1;
	}

/* showing level/hp/wc/ac of monsters/players is illegal 
    removed by wizardchild */
/*
write(capitalize(target->query_name())+"\n");
write("Level: "+target->query_level()+"\n");
write("Hit points: "+target->query_hp()+"\n");
write("WC: "+target->query_wc()+"\n");
write("AC: "+target->query_ac() +"\n");
write("% Health: "+(target->query_hp() *100/target->query_mhp()) +"\n");
if(target->query_interactive())
if(target->query_pl_k())
	write("This player has his player killing set! (Yeah!)\n");
if(target->query_interactive() && !target->query_pl_k())
	write("This player does not have his player killing set.\n");
if(present("medal", target))
	write("Member of Paladin guild\n");
if(present("fangs", target))
	write("Member of Vampire guild\n");
if(present("mrobe", target))
	write("A fellow monk (friend)\n");
if(present("symbol", target))
	write("Member of the Clerics guild\n");
if(present("black robes", target)) 
	write(" Member of the Mage guild\n");
this_player()->add_spell_point(-50);
*/
write("Sorry, this command has been removed.\n");
return 1;
}

/* --------- RAISE (ressurection) -------- */
raise(str) {
	object victim;

if(this_player()->query_guild_rank() < 10) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 100) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if (!str) {
	write("Raise whom?\n");
	return 1;
	}
   
victim = present("ghost of "+str,environment(this_player()));
if (!victim) {
	write("Your person is not here.\n");
	return 1;
	}
   
if (!living(victim) || victim->query_npc()) {
	write("You find you cannot cast your spell on" + 
	      "that.\n");
	return 1;
	}
   
if (!victim->query_ghost()) {
	write("You cannot raise " +
	      "something that is alive.\n");
	return 1;
	}
  
write("You raise your hands to the sky, and as you do "+
      "you feel a suddern surge of energy through your "+
      "body. Focusing this energy on the corpse you raise " +
      "it from the dead!\n");
say(this_player()->query_name() + " calls on the" +
    " powers of the sky to raise "+str+" .\n" +
    "You feel as though you are in the presence of greatness!\n");
call_other(victim, "remove_ghost", 0);
this_player()->add_spell_point(-100);
/******** Added by Wizardchild *********/
"room/adv_guild"->correct_level(victim);
if(victim->query_extra_level())
  "room/exlv_guild"->correct_level(victim);
/********** End Wiz Additions **********/
write("Ok.\n");
return 1;
}

/* ------ MONK WHO (guild members logged on) ----- */
monk_who(){
	int count;
	string who,guild;
	string gender;
	int x;
	object ob;
	object mas,monk,as,dopp;
	ob = users();
write("--------------------------------------------------------------------------------\n");
write("Name:           Rank:     Muffled:     Sex:     Location:\n");
write("--------------------------------------------------------------------------------\n");
for(x=0;x<sizeof(ob);x+=1){
	if(ob[x]->query_invis() < 20) {
		guild = present("mrobe", ob[x]);
		if(guild) {
			who = ob[x]->query_real_name();
			who = capitalize(who);
			count = strlen(who);
			count = 16 - count;
			write(who);
			while(count>0){
				write(" ");
				count = count - 1;
				}
			write(guild->query_guild_rank() + "  " +"\t");
			if(guild->query_muffled() == 1){write("    Yes     ");}
			if(guild->query_muffled() == 0){write("    No      ");}
			gender= ob[x]->query_gender();
			if(gender == "male") {write("   M        ");}
			if(gender == "female") {write("   F        ");}
			if(gender == "creature") {write("   C        ");}
			if(!environment(ob[x])){
				write("Location Unknown\n");
				}
			if(environment(ob[x])){
				write(environment(ob[x])->short()+"\n");
				}
			}
	}
}
write("--------------------------------------------------------------------------------\n");
return 1;
}

/* ------ PROMOTE (Guild Wizzies Only!) ----- */
promote_member(str) {
	object ob, obj;
	string who;
	int level, old_rank, old_exp, old_rank1, xp;
   
sscanf(str, "%s %d", who, level);
obj = find_player(who);
ob = present("mrobe", obj);
ob->set_guild_rank(level);
old_rank1 = obj->query_guild_rank();
obj->add_guild_rank(-old_rank1);
obj->add_guild_rank(level);
tell_object(obj, "You have been promoted to rank "+level+".\n");
write("You promote "+capitalize(who)+" to rank "+level+".\n");
old_exp = obj->query_guild_exp();
obj->add_guild_exp(-old_exp);
if(level == 1) { xp = 1; }
if(level == 2) { xp = 25000; }
if(level == 3) { xp = 75000; }
if(level == 4) { xp = 175000; }
if(level == 5) { xp = 475000; }
if(level == 6) { xp = 1000000; }
if(level == 7) { xp = 1700000; }
if(level == 8) { xp = 2500000; }
if(level == 9) { xp = 3600000; }
if(level > 9) {  xp = 5500000; }
obj->add_guild_exp(xp);
ob->set_guild_exp(xp);
write_file("/players/hawkeye/closed/monk/PROMOS",
capitalize(this_player()->query_real_name())+" PROMOTED "+
capitalize(who)+" to LEVEL "+level+" on "+ctime()+".\n");
return 1;
}

/* ------- MR's ----------- */
monk_robe0(){ cat("/players/hawkeye/closed/monk/helps/spells"); return 1;}
monk_robe1(){ cat("/players/hawkeye/closed/monk/helps/spells1"); return 1;}
monk_robe2(){ cat("/players/hawkeye/closed/monk/helps/spells2"); return 1;}
monk_robe3(){ cat("/players/hawkeye/closed/monk/helps/spells3"); return 1;}
monk_robe4(){ cat("/players/hawkeye/closed/monk/helps/spells4"); return 1;}
monk_robe5(){ cat("/players/hawkeye/closed/monk/helps/spells5"); return 1;}
monk_robe6(){ cat("/players/hawkeye/closed/monk/helps/spells6"); return 1;}

/* --- ALL HELP FILES WILL GO IN HERE! ---- */
help_files(str) {
if(!str) {
 write("USAGE:mhelp topic\n");
 write("TOPICS: ranks, levitate, pet, armor, advance, new, gc, dir, death, mrobe, teleport\n");
  return 1;
}
if(str == "ranks") {
	cat("/players/hawkeye/closed/monk/helps/ranks");
	return 1;
	}

if(str == "levitate") {
	cat("/players/hawkeye/closed/monk/helps/levitate");
	return 1;
	}

if(str == "pet") {
	cat("/players/hawkeye/closed/monk/helps/pet");
	return 1; 
	}

if(str == "armor") {
	cat("/players/hawkeye/closed/monk/helps/armor");
	return 1; 
	}
  
if(str == "advance") {
	cat("/players/hawkeye/closed/monk/helps/advance");
	return 1;
	}

if(str == "new") {
	cat("/players/hawkeye/closed/monk/helps/new");
	return 1;
	}
   
if(str == "gc") {
	if(this_player()->query_guild_rank() < 19) {
		return 1;
		}
	cat("/players/hawkeye/closed/monk/helps/gc");
	return 1;
	}
   
if(str == "dir") {
	cat("/players/hawkeye/closed/monk/helps/dir");
	return 1; 
	}

if(str == "death") {
	cat("/players/hawkeye/closed/monk/helps/death");
	return 1;
	}
   
if(str == "mrobe") {
	cat("/players/hawkeye/closed/monk/helps/dir");
	return 1; 
	}
  
if(str == "weapons") {
	cat("/players/hawkeye/closed/monk/helps/weapons");
	return 1; 
	}

if(str == "wimp") {
	cat("/players/hawkeye/closed/monk/helps/wimp");
	return 1; 
	}
   
if(str == "locker") {
	cat("/players/hawkeye/closed/monk/helps/lockers");
	return 1;
	}
  
if(str == "teleport") {
	cat("/players/hawkeye/closed/monk/helps/teleport");
	return 1; 
	}
}

/* --------- READ NEWS --------------- */
read_news() {
cat("/players/hawkeye/closed/monk/guild_news");
return 1;
}

/* ----------- MONSTER STATUS ----------------- */
mons() {
	object mons;
	int monhp, monmhp;
	string shape, atname;
   
mons = shit->query_attack();
atname = mons->query_name();
monhp = mons->query_hp();
monmhp = mons->query_mhp();
if(monhp < monmhp/10) shape = "VBS"; else
if(monhp < monmhp/5) shape = "BS"; else
if(monhp < monmhp/2) shape = "SWH"; else
if(monhp < monmhp - 1) shape = "SLH"; else
shape = "GS";
tell_object(shit, "  [ATT:"+shape+"]\n");
return 1;
}

/* ----- BEEP A GUILD MASTER (so i can edit and still help) --- */
beep_wiz(str) {
  object ob, obj;
  string me;
if(!str) { 
	write("Usage: beep <hawkeye> or <pain>.\n");
	return 1; 
	}

if(str == "pain" || str == "hawkeye") {
	ob = find_player(str);
	tell_object(ob, capitalize(this_player()->query_real_name())+
		    " needs your help!\n");
	write("You beep "+capitalize(str)+".\n");
	return 1;
	}
   
write("Usage: beep <hawkeye> or <pain>.\n");
return 1;
}

/*              Set the players start to the guild room                 */
set_starting() {
    object target;

target = this_player();
target->set_home("players/hawkeye/closed/guild/guild_room.c");
write("Start place set.\n");
return 1;
}

/* ---- AMEND (mend Another players robes <20++ only>)---- */
amend(str) {
	object ob, guild;

if(!str) { 
	write("Usage: amend <player>.\n"); 
	return 1; 
	}
   
ob = find_player(str);
if(!ob) { 
	write(capitalize(str)+" is not logged on.\n"); 
	return 1; 
	}
   
guild = present("mrobe", ob);
if(!guild) { 
	write(capitalize(str)+" doesn't have a Robe.\n"); 
	return 1; 
	}

write("You have "+capitalize(str)+"'s robes mended.\n");
tell_object(ob, "A guild commander mends your robes.\n");
command("mend", ob);
return 1;
}

/* --------- MEND ALL (force all monks to mend) ------ */
mend_all() {
	object ob, guild;
	int i;
 
if(this_player()->query_real_name() == "pain" ||
   this_player()->query_real_name() == "hawkeye") {
	write("The Guild Memebers have mended their robes.\n");
	ob = users();
	for(i = 0; i < sizeof(ob); i++) {
		guild = present("mrobe", ob[i]);
		if(guild && ob[i]->query_level() < 50) {
			tell_object(ob[i], "A Guild Master requests that you Mend your Robes.\n");
			command("mend", ob[i]);  
			}
		}
		return 1;
	}
}

/* ----- ROBE (give robe to guild member) ------ */
robe(str) {
	object ob, obj, ob1;

if(this_player()->query_guild_rank() < 20) {
  write("You are NOT a guild commander.\n");
    return 1;
}
  
if(!str) {
	write("Robe who?\n");
	return 1;
	}
  
ob = find_player(str);
if(!ob) {
	write("Cannot find player: "+capitalize(str)+".\n");
	return 1;
	}
if(ob->query_guild_name() != "monk") {
write("That person is NOT a monk.\n");
return 1;
}
   
obj = clone_object("players/hawkeye/closed/monk/testobj.c");
obj->set_guild_rank(1);
move_object(obj, ob);
write(capitalize(str)+" now has a Monk Robe!\n");
tell_object(ob, "You now have a Monk Robe!\n");
command("mend", ob);
return 1;
}

/* ------- GUILD TITLE (set guild title) ----- */
guild_title() {
	string title;
	object me;

if(this_player()->query_guild_rank() == 1) { title = "the Monk Initiate"; }
if(this_player()->query_guild_rank() == 2) { title = "the Novice Monk"; }
if(this_player()->query_guild_rank() == 3) { title = "the Monk"; }
if(this_player()->query_guild_rank() == 3) { title = "the Monk Superior"; }
if(this_player()->query_guild_rank() == 4) { title = "the Master Monk"; }
if(this_player()->query_guild_rank() == 5) { title = "the Grandmaster Monk"; }
if(this_player()->query_guild_rank() > 5) { title = "the Grandmaster of Shadows"; }

this_player()->set_title(title);
write("Your guild title has now been set.\n");
return 1;
}

/*---------------TITLE------------------*/
new_title(str) {
	int level;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

level = this_player()->query_level();
if(level > 19) {
	this_player()->set_title(str);
	write("Your title has been changed...\n");
	return 1;
	}

this_player()->set_title(str+" (player:"+level+")");
write("Your new title is : "+str+" (player:"+level+")\n");
this_player()->add_spell_point(-10);
return 1;
}

/* --- TRYING TO FIX THIS FUCKIN HEARTBEAT PROBLEM ----- */
fixme() {
	object obj;

if(this_player()->query_attack()) {
	write("You cannot Fixme while in battle.\n");
	return 1;
	}
  
call_other(this_player(),"reset",1);
this_player()->recalc_quest();
obj = present("shobj", this_player());
if(obj)  obj->dump_shield();
write("You have been fixed (i hope i hope).\n");
return 1;
}

/* --------- LOCATE A PLAYER ------------ */
locate_player(str) {
	string gender;
	object ob;
 
if(this_player()->query_guild_rank() < 2) {
   write("You must attain a higher level in the guild\nbefore you can use this ability!\n");
       return 1;
}
   
ob = find_player(str);
if(!ob) { 
	write(capitalize(str)+" is not logged on.\n");
	return 1; 
	}

if(ob->query_level() > 22) {
	write(capitalize(str)+" is not logged on.\n");  
	return 1;
	}

write("\n");
write(ob->short()+"\n");
gender = ob->query_gender();
if(gender == "male") { write("Gender: Male          Guild: "); }
if(gender == "female") { write("Gender: Female        Guild: "); }
if(gender == "creature") { write("Gender: Creature      Guild: "); }
if(present("mrobe", ob)) { write("Monk\n"); }
else
if(present("vampirefangs", ob)) { write("Vampire\n");
 }
else
if(present("seal", ob)) { write("Mason\n"); }
else
if(present("shadow_mark", ob)) { write("Shadow\n"); }
else
if(present("license", ob)) { write("Assassin\n"); }
else write("None\n");
if(ob->query_pl_k() == 1) { write("Player killer: Yes    Location: "); }
if(ob->query_pl_k() == 0) { write("Player killer: No     Location: "); }
if(!environment(ob)) { write("Unknown\n");}
if(environment(ob)) { write(environment(ob)->short()+"\n");}
write("\n");
return 1;
}

/* ----- SET TRACER (for teleports) ------- */
set_tracer() {
	object ob, one, two;
	string number, name;

if(this_player()->query_guild_rank() < 6) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 25) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
one = find_living(name+"'s tracer one");
two = find_living(name+"'s tracer two");

if(environment(this_player())->realm()=="NT") {
	write("You may not trace runes of teleportation here.\n");
	return 1; 
	}
  
if(one && two) {
	write("You already have both tracers set,  You must erase\n"+
	      "one before you can set another.\n");
	return 1; 
	}

if(one) { number = "two"; }
if(two) { number = "one"; }
if(!one && !two) { number = "one"; }
ob = clone_object("players/hawkeye/closed/monk/trans_obj");
ob->set_owner(name);
ob->set_which(number);
move_object(ob, environment(this_player()));
write("You trace magical runes of teleportation upon the ground here.\n");
this_player()->add_spell_point(-25);
return 1;
}

/* --- REMOVE A TRACER ---------- */
remove_tracer(str) {
	object one, two;
	string name;

if(this_player()->query_guild_rank() < 6) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
one = find_living(name+"'s tracer one");
two = find_living(name+"'s tracer two");
if(str == "1") {
	if(!one) { 
		write("You don't have that tracer set.\n"); 
		return 1; 
		}
	write("You remove tracer 1.\n");
	destruct(one);
	return 1;    
	}
if(str == "2") {
	if(!two) { 
		write("You don't have that tracer set.\n"); 
		return 1; 
		}
	write("You remove tracer 2.\n");
	destruct(two);
	return 1;    
	}
  
write("Usage: rmtrace <1 or 2>.\n");
return 1;
}

/*               Balance one's spell points and hit points               */
balance() {
	int hp,sp,bal;

if(this_player()->query_guild_rank() < 4) {
	write("You must gain a higher level in the guild before using this skill.\n");
	return 1;
	}

hp = this_player()->query_hp();
sp = this_player()->query_sp();
this_player()->add_hit_point(-hp);
this_player()->add_spell_point(-sp);
bal = (hp + sp) /2;
this_player()->add_spell_point(bal);
this_player()->add_hit_point(bal);
write("Your Hit Points and Spell Points have been balanced.\n");
return 1;
}

/* -------- TELEPORT --------------- */
teleport() {
	object one, two;
	string name;

if(this_player()->query_guild_rank() < 6) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 40) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
one = find_living(name+"'s tracer one");
two = find_living(name+"'s tracer two");
if(!one || !two) {
	write("You need to have both tracers set before you can teleport.\n");
	return 1; 
	}

if(present(name+"'s tracer one", environment(this_player()))) {
	move_object(this_player(), environment(two));
	write("You teleport to your other tracer.\n");
	this_player()->add_spell_point(-40);
	return 1; 
	}

if(present(name+"'s tracer two", environment(this_player()))) {
	move_object(this_player(), environment(one));
	write("You invoke the magical runes of this tracer and\n"+
	      "your body is magically transported through space.\n"+
	      "Teleport successful.\n");
	this_player()->add_spell_point(-40);
	return 1; 
	}
  
write("You must be in the same room as one of your tracers to\n"+
      "be able to teleport.\n");
return 1;
}

/* ----- LOCATE TRACERS ------ */
locate_tracer() {
	object one, two;
	string name;
      
name = this_player()->query_real_name();
one = find_living(name+"'s tracer one");
two = find_living(name+"'s tracer two");
write("Tracer Locations: \n");
if(one) {
	write("1) "+environment(one)->short()+".\n");
	} 
if(!one) { write("1) Not placed.\n"); }
if(two) {
	write("2) "+environment(two)->short()+".\n");
	} 
if(!two) { write("2) Not placed.\n"); }
return 1;
}

/* -- CHAIN LIGHTNING (area attack) ------- */
chain_lightning() {
	object ob, obj, room;
	int dmg, x;
   
if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher position in the guild before using this skill!\n");
	return 1;
}

if(this_player()->query_sp() < 35) {
	write("You lack the magical power to perform this!\n");
	return 1;
}
room = environment(this_player());
ob = first_inventory(room);
dmg = 15+random(10);
write("You raise your hands into the air and dark clouds gather\n"+
      "over head.  The room lights with a brilliant flash as a streak of\n"+
      "lightning blazes out of the sky!\n");
say(ME+" raises his hands into the air..dark clouds mass overhead...\n"+
    "thunder crashes in the sky above and a brilliant flash lights the\n"+
    "room as a bolt of lightning streaks out of the sky!\n");
this_player()->add_spell_point(-35);
while(ob) {
	object cur;
	cur = ob;
	ob = next_inventory(ob);
	if(living(cur)) {
		if(cur->query_npc() !=1) {
			tell_room(room, capitalize(cur->query_name())+
				  " is knocked to the ground!\n"); 
			}
	if(cur->query_npc()==1 && cur->query_name() != "A Falcon") {
		tell_room(room,"The Bolt of lightning leaps to its next target...\n"+
			  capitalize(cur->query_name())+" is struck by a bolt of lightning!\n");
	cur->hit_player(dmg);
	dmg = dmg - 5;
	if(dmg < 1) 
		dmg = 1;
	if(random(100) < 60) {
		if(cur && !cur->query_attack()) {
			cur->attack_object(this_player());
			}
	}
	}
     }
}
write("The bolt of lightning dives into the ground, blasting a large\n"+
      "hole into the earth.\n");
return 1;
}

/* TORNADO */
tornado_attack() {
	object ob, obj, room;
	int dmg, x;

if(this_player()->query_guild_rank() < 8) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 65) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

room = environment(this_player());
ob = first_inventory(room);
dmg = 25+random(20);
write("You raise your hands into the air and dark clouds gather\n"+
      "over head.  Rains begin to fall and a gigantic funnel cloud appears\n"+
      "off in the distance.\n");
say(ME+" raises his hands into the air..dark clouds mass overhead...\n"+
    "Rains begin to fall and a Tornado rips through the area!\n");

this_player()->add_spell_point(-65);
while(ob) {
	object cur;
	cur = ob;
	ob = next_inventory(ob);
	if(living(cur)) {
		if(cur->query_npc() !=1) {
			tell_room(room, capitalize(cur->query_name())+
				  " is spun around in circles and thrown to the ground!\n"); }

		if(cur->query_npc()==1 && cur->query_name() != "A Falcon") {
			tell_room(room,
				  "The Tornado moves on to its next target...\n" +
				  capitalize(cur->query_name())+" is attacked by a violent tornado!\n");
		cur->hit_player(dmg);
		dmg = dmg - 8;
		if(dmg < 1) 
			dmg = 1;
		if(random(100) < 60) {
			if(cur && !cur->query_attack()) {
				cur->attack_object(this_player());
				}
		}
	}
     }
}
write("The Tornado moves past taking several large trees with it in\n"+
      "its destructive path.\n");
return 1;
}


/* ----- QUIT (set all modifiers, counters, etc Zip) -- */
quit(){
 object trace1, trace2;
if(iquit == 0){
 trace1 = find_living(this_player()->query_real_name()+"'s trace 1");
 trace2 = find_living(this_player()->query_real_name()+"'s trace 2");
    if(trace1) destruct(trace1);   if(trace2) destruct(trace2);
while(present("monk_obj", this_player())){
    destruct(present("monk_obj", this_player()));
		     }
 iquit = 911;
command("quit", this_player());
return 1;
}
}

/*  ------ GXP (set members guild XP) ---------- */
gxp_member(str) {
	object ob, obj, robe;
	int xp, old_exp;
	string who;

if(!str || sscanf(str, "%s %d", who, xp) != 2) {
	write("Usage: gxp <player> <#>.\n");  
	return 1;   
	}
  
ob = find_player(who);
if(!ob) { 
	write(capitalize(who)+" is not logged on.\n");
	return 1;  
	}
  
robe = present("mrobe", ob);
if(!robe) { 
	write(capitalize(who)+" doesn't have a monk robe.\n");
	return 1;  
	}
 
old_exp = robe->query_guild_exp();
robe->set_guild_exp(old_exp + xp);
ob->add_guild_exp(xp);
write("You give "+capitalize(who)+" "+xp+" guild exp points.\n");
return 1;
}

/* --- GSTAT ---- */
gstat(str) {
	object ob, obj;

if(!str) { 
	write("Usage: gstat <player>.\n"); 
	return 1; 
	}
 
ob = find_player(str);
if(!ob) { 
	write(capitalize(str)+" is not logged on.\n"); 
	return 1; 
	}

obj = present("mrobe", ob);
if(!obj) { 
	write(capitalize(str)+" doesnt have a Monk Robe.\n");
	return 1; 
	}

write(ob->short()+"\n");
write("level: "+ob->query_level()+"  extralevel: "+
ob->query_extra_level()+"\n");
/* give me a break, i'm sick of seeing crap that shows wc/ac 
write("Hitpoints: "+ob->query_hp()+"/"+ob->query_mhp()+"\n");
write("Spellpoints: "+ob->query_sp()+"/"+ob->query_msp()+"\n");
write("Weapon Class: "+ob->query_wc()+"\n");
write("Armor Class: "+ob->query_ac()+"\n");
write("Experience: "+ob->query_exp()+"\n");
*/
write("Player Rank: "+ob->query_guild_rank()+"\n");
write("object rank: "+obj->query_guild_rank()+"\n");
write("Player Guild Exp: "+ob->query_guild_exp()+"\n");
write("object guild exp: "+obj->query_guild_exp()+"\n");
write("Guild name: "+ob->query_guild_name()+"\n");
write("\n");
return 1;
}

/* --- BATTLE WHO (who's in battle vs. what, where) ---- */
battle_who() {
	object ob, obj, guild;
	string atname, myname;
	int i, x, xx;
	
ob = users();
write("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
x= 0;    
xx = 0;
for(i = 0; i < sizeof(ob); i++) {
	guild = present("mrobe", ob[i]);
	if(guild) {
		myname = ob[i]->query_name();
		if(ob[i]->query_attack()) {
			obj = ob[i]->query_attack();
			atname = obj->query_name();
			if(!atname) atname = "unknown";
			write("< "+capitalize(myname)+" > attacked by < "+
			      capitalize(atname)+" > at "+environment(ob[i])->short()+"\n");
			x++;   
			xx++;    
			} 
		else {
			xx++;   
			}
		}
	}
write("- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
write(xx+" Monks logged on.  "+x+" Monks in battle.\n\n");
return 1;
}

/* ------------ MIND BLAST --------------- */
mind_blast(str) {
	object ob, obj;
	int dmg, heal;
	string dik;

if(this_player()->query_sp() < 50) {
     write("You are too low on power.\n");
     return 1;
     }

if(this_player()->query_hp() < 20) {
	write("You need more hit points to mindblast.\n");
	return 1;
	}

if(!str && !this_player()->query_attack()) {
	write("Usage: mindblast or blast <target>.\n"); 
	return 1;   
	}

if(!str && this_player()->query_attack()) {
	ob = this_player()->query_attack();     
	} 
else {
	ob = present(str, environment(this_player()));
	}
    
if(!ob) {
	write("You cannot blast from something that is not in the room.\n");
	return 1; 
	}
  
if(!this_player()->query_attack()) {
	write("You must be in battle to use this spell.\n");
	return 1; 
	}
   
if(ob->query_npc() != 1) {
	write("You cannot use this spell on players!\n");
	return 1; 
	}

dik = ob->query_name();
write(dik+ " falls to the ground while grasping at its head, with perfect\n" +
      "control you send another jolt of energy into "+dik+"\n");
say(ME +" concentrates and sends a jolt of energy into "+dik+"'s brain.\n");
this_player()->add_spell_point(-75);
dmg = 35+random(55);
ob->hit_player(dmg);
this_player()->add_hit_point(-10);
return 1;
}

/* ----- LEVITATE (in a room) --------- */
levitate() {
	object me, putz, lev;
	int x;
	string name;

if(this_player()->query_guild_rank() < 10) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 50) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

name = this_player()->query_real_name();
if(this_player()->query_attack() && 
   random(25) < call_other(this_player(),"query_attrib","wil")){
	write("You attempt to levitate your body into the air, but you cannot\n"+
	      "concenrate and fight at the same time.\n");
	this_player()->add_spell_point(-35);
	say(ME+" tried to levitate, but failed.\n");
	return 1;
	}

write("You command the forces of nature to lift your body into the air!\n"+
      "Your feet leave the ground and you begin to magically float above\n"+
      "everyone else!  <type 'down' to get back down.> \n");

say(ME+" lifts into the air!\n");
putz = clone_object("players/hawkeye/closed/monk/levtate_obj");
move_object(putz, environment(this_player()));
move_object(this_player(), putz);
putz->set_owner(name);
putz->set_nme(this_player()->short());
this_player()->add_spell_point(-50);
return 1;
}


/* ---- CRUSH (higher level attack spell) ---- */
crush(str) {
	object ob, me, blow;
	int x;  
	string name, suck;

if(this_player()->query_guild_rank() < 6) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str && !this_player()->query_attack()) {
	write("Usage: Crush <target>.\n"); 
	return 1; 
	}
 
if(!this_player()->query_attack()) {
	write("You must be fighting before you can use this ability.\n");
	return 1; 
	}
 
if(!str && this_player()->query_attack())
	ob = this_player()->query_attack();
else
	ob = present(str, environment(this_player()));

if(ob->query_npc()==0) { 
	write("Unfortunately you cannot use this spell on players.\n");
	return 1; 
	}

if(!ob) { 
	write("That target is not here to crush.\n"); 
	return 1; 
	}
 
suck = ob->query_name();
write("You grab "+capitalize(suck)+" and crush it like a grape!\n"+
      capitalize(suck)+"'s eyes bulge out of its head as you squeeze\n"+
      "the life from its wimpy body.\n");
say(ME+" grabs "+capitalize(suck)+" and squeezes the life out of it!\n"+
    capitalize(suck)+"'s eyes bulge out of its head as "+ME+" squeezes\n"+
    "the life from its pathetic body.\n");
x = this_player()->query_guild_rank();
if(x > 15) x = 15;
ob->hit_player(random(x) + x/2);
this_player()->add_spell_point(-(x+random(x)));
return 1;
}

/*----------------RECRUIT----------------*/
recruit(str) {
	object ob;
	object obj;

if(this_player()->query_guild_rank() < 2) {
    write("You must attain a higher level in the guild\nbefore you can use this ability!\n");
       return 1;
}
ob = present(str, environment(this_player()));
if(!ob) {
	write(str+ " is not here.\n"); 
	return 1;
	}
obj = clone_object("players/hawkeye/closed/monk/recruit.c");
move_object(obj,ob);
write("You have recrited "+str+" they may now join the Guild.\n");
return 1;
}



/* --------- MAKE WIMP (on or off) ----------- */
make_wimp(str) {
if(!str) { 
	write("Usage: wimp <on/off>.\n"); 
	return 1; 
	}
if(str == "on") {
	wimp = 1;
	write("*-- Wimp: On.  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+
	      " --*\n");
	return 1;
	}

if(str == "off") {
	wimp = 0;
	write("*-- Wimp: Off.  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+
	      " --*\n");
	return 1;
	}

write("Usage: wimp <on/off>.\n");
return 1;
}

/* --- MAKE WHIMPY NUMBER --------- */
make_wimp_at(str) {
	int num;

if(!str) {
	wimp_at = 10;
	if(wimp == 1){
		write("*-- Wimp: On."); 
		} 
	else { 
		write("*-- Wimp: Off."); 
		}
	write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
	return 1;
	}
	
sscanf(str, "%d", num);
if(num < 1) {
	 write("You must select a number greater than 1.\n");
	 return 1; 
	 }

if(num > 99) {
	 write("What are you a total pansy?\n");
	 write("You must select a number between 1 and 99.\n");
	 return 1; 
	 }
wimp_at = 100 / num;
if(wimp == 1){
	 write("*-- Wimp: On."); 
	 } 
else { 
	write("*-- Wimp: Off."); 
	}
write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
return 1;
}

/* ------ MAKE WIMP DIR ------------ */
make_wimp_dir(str) {
if(!str) {
	wimp_dir = "none";
	if(wimp == 1){
		write("*-- Wimp: On."); 
		} 
	else { 
		write("Wimp: Off."); 
		}
write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
return 1;
}
wimp_dir = str;
if(wimp == 1){
	write("*-- Wimp: On."); 
	} 
else { 
	write("*-- Wimp: Off."); 
	}
write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
return 1;
}

/*---------------GC-----------------*/
gc(){
cat("/players/hawkeye/closed/monk/gc");
return 1;
}
/* --- MSAY (monk_say) --- */
monk_say(str){
	object ob, room;

if(!str){
	write("Say what?\n");
	return 1; 
	}
room = environment(this_player());
ob = first_inventory(room);
while(ob){
	object cur;
	cur = ob;
	ob = next_inventory(ob);
	if(cur->query_npc() != 1){
		if(present("mrobe", cur))
			if(cur == this_player())
				write("You monk_say: "+str+"\n");
			else
				tell_object(cur, capitalize(this_player()->query_name())+" monk_says: "+
					    str+"\n");
		else
			tell_object(cur, capitalize(this_player()->query_name())+" says: "+
				msay(str)+"\n");
		}
	}
return 1;
}

/*---------QUICK SCORE-------------*/
mon() {
	int hp,sp,money;
	int intox;
	int xp;

xp = this_player()->query_exp();
intox = this_player()->query_intoxination();
hp = this_player()->query_hp();
sp = this_player()->query_sp();
money = this_player()->query_money();
write("HP: "+hp+"   SP: "+sp+"   XP: "+xp+"   MONEY: "+money+"  INTOX: "+intox+"/"+min+"\n");
return 1;
}

/* --- SNEAK (leave a room silently) --- */
sneak(str){
	object obj, room, exits;
	string blah;
	int i, nbr;

if(this_player()->query_guild_rank() < 5) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 15) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}


obj = present(this_player()->query_real_name()+"'s invis_obj", 
      environment(this_player()));

if(str == "e") str = "east";  if(str == "w") str = "west";
if(str == "n") str = "north"; if(str == "s") str = "south";
if(str == "d") str = "down";  if(str == "u") str = "up";
i = 0;
if(!str){
	if(!obj) 
		write("Usage: sneak <dir>.\n");
	else 
		write("what?\n");
	return 1; 
	}

room = environment(this_player());
exits = room->query_dest_dir();
if(!exits){
	if(!obj) 
		write("For some reason you cannot sneak from this room.\n");
	else 
		write("You cannot exit this way while super invisible.\n");
	return 1; 
	}
nbr = sizeof(exits);
while( i < sizeof(exits)){
	if(str == exits[i]){
		i -= 1;
		blah = exits[i];
		if(!obj) 
			write("You sneak "+str+".\n");
		move_object(this_player(), blah);
		command("look", this_player());
	if(!obj) this_player()->add_spell_point(-10);
    i += 1;
    }
  i++;
  }
return 1;
}

/* -- TOUCH (player-ta-player telee) -- */
touch(str){
	object target;

if(this_player()->query_guild_rank() < 8) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 70) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str){
	write("Usage: touch <player>.\n");
	return 1; 
	}

target = find_player(str);
if(!target){
	write(capitalize(str)+" cannot be found.\n");
	return 1; 
	}

if(!present("mrobe", target)){
	write(capitalize(str)+" is not a Monk.\n");
	return 1; 
	}

if(target->query_level() > 19){
	write("You cannot touch a Wizard!\n");
	return 1; 
	}

if(environment(this_player())->realm() == "NT"){
	write("Something here is blocking your spell.\n");
	return 1; 
	}

if(environment(target)->realm() == "NT"){
	write("Something there is blocking your spell.\n");
	return 1; 
	}

write("You reach out and Touch "+capitalize(str)+".\n");
say(ME+" vanishes suddenly.\n");
move_object(this_player(), environment(target));
tell_object(target,
	    "You feel a soft touch on your arm.\n"+
	    ME+" suddenly appears at your side.\n");
say(ME+" appears suddenly at the side of "+capitalize(str)+".\n");
this_player()->add_spell_point(-70);
return 1;
}

/*              What the fuck is this??                                 */
/* -- attack SPELL (chex everything for combat spells) -- */
attack_spell(sep, ronk, sucker, cow, wmes, smes) {
   int damge;
if(!shit->query_attack()){
  write("You must be fighting to use this spell.\n");
  failed = 1;  return 1;   }
if(shit->query_sp() < sep){
  write("You do not have enough Spell Points to use this spell.\n");
  failed = 1;  return 1;   }
if(shit->query_guild_rank() < ronk){
  write("You are not high enough in the Guild to use this spell.\n");
  failed = 1;  return 1;   }
if(!sucker){
  write("That is not here.\n");
  failed = 1;  return 1;   }
if(!present(sucker, environment(shit))){
  write("That is not here.\n");
  failed = 1;  return 1;   }
if(sucker->query_npc() != 1){
  write("You cannot use this spell on Players.\n");
  failed = 1;  return 1;   }
damge = sep + random(cow);
sucker->hit_player(damge);
shit->add_spell_point(-sep);
write(wmes+"\n");
say(smes+"\n");
return 1;
}

/* ---- TRIP (two player attack spell) ---- */
trip(str){
	object ob, obj, he;
	string him;
if(!str){
	write("Trip what?\n");
	return 1;   
	}
obj = present(str, environment(this_player()));
if(!obj){
	write("That is not here.\n");
	return 1;   
	}
if(obj->query_npc() != 1){
	write("As much as you might want to, you cannot Trip this player.\n");
	return 1;   
	}

if(present("trip_obj", obj)){
	ob = present("trip_obj", obj);
	him = ob->query_owner();
	he = find_player(him);
	if(him == this_player()->query_real_name()) 
		return 1;
	him = capitalize(him);
	write("You give "+capitalize(str)+" a mighty shove!\n"+
	      capitalize(str)+" falls over "+him+" and lands with a heavy THUD!\n");
	write("You snicker mischeviously.\n"+him+" snickers mischeviously.\n");
	say(ME+" gives "+capitalize(str)+" a mighty shove!\n"+
	    capitalize(str)+" falls over "+him+" and lands with a heavy THUD!\n");
	say(ME+" snickers mischeviously.\n");
	command("dtrip "+str, he);
	obj->hit_player(20+random(30));
	this_player()->add_spell_point(-50);
	destruct(present("trip_obj", obj));
	if(random(10) > 5)
		obj->attack_object(this_player());
	else
		obj->attack_object(he);
	return 1;
} 
else {
	write("You sneak behind "+capitalize(str)+" and crouch down behind the "+
	      "poor suckers legs.\n");
	say(ME+" sneaks behind "+capitalize(str)+" and crouches behind his legs.\n");
	ob = clone_object("players/hawkeye/closed/monk/trip_obj");
	ob->set_owner(this_player()->query_real_name());
	move_object(ob, obj);
	return 1;   
	}
}

dtrip(str){
	object obj;

obj = present(str, environment(this_player()));
if(!obj) 
	return 1;
obj->hit_player(20+random(30));
this_player()->add_spell_point(-50);
return 1;
}

/* --- SHIELD --- */

/* --- FLAME --- */
flame(str){
	int x, pain;
	object obj;

if(this_player()->query_guild_rank() < 7) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 50) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str){
	write("Usage: Flame <target>.\n"); 
	return 1;  
	}

obj = present(str, environment(this_player()));
if(!obj){
	write("There is no "+capitalize(str)+" here.\n"); 
	return 1;  
	}
if(obj->query_npc() != 1){
	write("You cannot Flame another player.\n"); 
	return 1;  
	}

if(!this_player()->query_attack()){
	write("You must be fighting to cast this spell.\n"); 
	return 1; 
	}

x = random(100);
write("You whisper an ancient incantation and summon a magical fire.\n"+
      "A searing blue flame appears in your hands.\n");
say(ME+" whispers an ancient incantation and summons a magical fire.\n"+
    "A searing blue flame appears in "+ME+"'s hands.\n");
if(x > 95){
	write("Something goes wrong ... the Fireball explodes in your hand!\n"+
	      "You scream in pain and hurriedly extinguish the flames.\n");
	say("Something goes wrong with "+ME+"'s spell ... the Fireball explodes in "+
	    "his hands!\n"+ME+" screams in pain and hurriedly extinguishes the flames.\n");
	this_player()->hit_player(10+random(30));
	} 
else {
	write("You hurl a huge ball of fire at your enemy!\n"+
	      "The Fireball explodes over "+IT+", engulfing the monster in flames!\n");
	say(ME+" hurls a huge ball of fire at his enemy!\n"+
	    "The Fireball explodes over "+IT+", engulfing the monster in flames!\n");
	obj->hit_player(31+random(19));
	}
this_player()->add_spell_point(-50);
return 1;
}

/* ----- HURL ------- */
hurl(str){
	object obj, ob;
	int x, Wc, luck;
	string jerk;

if(this_player()->query_guild_rank() < 7) {
	write("You must attain a higher level in the guild\n"+
	      "before using this ability!\n");
	return 1;
	}
if(!this_player()->query_attack()){
	write("You must be fighting to use Hurl.\n");
	return 1;   
	}

if(this_player()->query_attack()->query_npc() != 1){
	write("You cannot hurl something at another player.\n");
	return 1;   
	}

if(!str){
	write("Usage: hurl <obj>.\n");
	return 1;   
	}

obj = present(str, this_player());
if(!obj){
	write("You do not have a "+str+" to Hurl.\n");
	return 1;   
	}

if(obj->weapon_class() < 1){
	write("You can only Hurl weapons at your enemy.\n");
	return 1;   
	}

jerk = capitalize(this_player()->query_attack()->query_name());
Wc = obj->weapon_class();
luck = call_other(this_player(), "query_attrib", "luc");
write("You use all your strength to Hurl the "+str+" at "+jerk+".\n");
say(ME+" uses all his strength to Hurl a "+str+" at "+jerk+".\n");
if(obj->query_name() == "Monk's Staff")  
	luck = 0;
if(random(20) > luck){
	write("Your aim is off and the "+str+" sails harmlessly over "+jerk+
	      "'s head.\n");
	say(ME+"'s aim is off and the weapon sails harmlessly over "+jerk+
	    "'s head.\n");
	} 
else {
	write("Your aim is true and the weapon plunges deep into "+jerk+
	      "'s chest!\n");
	say(ME+"'s aim is true and the weapon plunges deep into "+jerk+
	    "'s chest!\n");
	this_player()->query_attack()->hit_player(10 + random(Wc)*2);
	}
destruct(obj);
return 1;
}

/* --- GOLD CORPSE (turn corpse into some coins) --- */
gold(str){
	object ob, obj;
	int x;

if(this_player()->query_guild_rank() < 4) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str){
	write("Usage: gold corpse.\n");
	return 1; 
	}

obj = present("corpse", environment(this_player()));
if(!obj){
	write("There is no corpse here.\n");
	return 1; 
	}

x = obj->heal_value();
/*
x = x * 100 + random(x);
 thats alot of money!!! 50 coins max!!! -Bp
*/
x=20+random(x);
if(x>50) 
	x=50;
this_player()->add_money(x);
write("You burn the corpse and pick some coins up off the ground.\n");
say(ME+" burns a corpse and picks up some coins.\n");
destruct(obj);
this_player()->add_spell_point(-10);
return 1;
}

/* --- PURSE --- */
purse(str){
	object ob;

if(!present("coin pouch", this_player())){
	ob = clone_object("players/hawkeye/closed/monk/purse.c");
	move_object(ob, this_player());
	write("You take a small coin pouch out from your robes.\n");
	command("purse "+str, this_player());
	return 1; 
	}
}

/* ---- BREW ---- */
brew(){
if(this_player()->query_money() < 200){
	write("You need more money to do this.\n");
	return 1; 
	}
if(!call_other(this_player(), "drink_alcohol", 7)){
	write("You can't possible stomach another drink right now.\n");
	return 1; 
	}
write("You mix yourself up a strong drink and slam it down.\n");
say(ME+" mixes a strong drink and then slams it.\n");
this_player()->heal_self(14);
/*
  at intox 10, 14 coins for each heal. */
this_player()->add_intoxination(10);
this_player()->add_money(-200);
return 1;
}

/* ---- AID (send HP's to another Monk) ---- */
aid(str){
	object ob, obj;
	int amt;
	string who;

if(this_player()->query_guild_rank() < 5) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 10) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str){
	write("Usage: aid <plyr> <amt>.\n");
	return 1; 
	}

if(!sscanf(str, "%s %d", who, amt)){
	write("Usage: aid <plyr> <amt>.\n");
	return 1; 
	}

obj = find_player(who);
if(!obj){
	write(capitalize(who)+" is not on the game.\n");
	return 1; 
	}

if(this_player()->query_hp() < amt){
	write("You do not have "+amt+" to send.\n");
	return 1; 
	}
if(amt < 1) {
   write("You can not use aid to take away hp you cheating bastard.\n");
   return 1;
}

write("You send "+amt+" hit points to "+capitalize(who)+".\n");
tell_object(obj, ME+" aids you by sending "+amt+" hit points.\n");
obj->add_hit_point(amt);
this_player()->add_hit_point(-amt);
if(!present(obj, environment(this_player())))
	this_player()->add_spell_point(-10);
/*      Small penalty if the recepiant is not a monk                    */
if(!present("mrobe", obj))
this_player()->add_spell_point(-random(10));
return 1;
}

/* --- LEAD (take the lead in battle) --- */
lead(){
	object obj;

if(!this_player()->query_attack()){
	write("You must be fighting to take the lead.\n");
	return 1; 
	}

obj = this_player()->query_attack();
obj->attack_object(this_player());
write("You step up to the front of the fighting.\n");
return 1;
}

/* ----- PRAYER ------ */
prayer(){
	object ob, obj, room;

if(this_player()->query_guild_rank() < 7) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 50) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

room = environment(this_player());
ob = first_inventory(room);
write("You recite a quick prayer to ensure good fortune.\n");
say(ME+" recites a quick prayer to ensure good fortune.\n");
this_player()->add_spell_point(-45);
while(ob){
	object cur;
	cur = ob;
	ob = next_inventory(ob);
	if(living(cur) && cur->query_npc() != 1){
		if(present("prayer_obj", cur)){
			if(cur == this_player())
				write("You are already under the effect of a Prayer.\n");
			else
				write(capitalize(cur->query_name())+" is already under the affect of "+
				      "a Prayer.\n");
		} 
		else {
			obj = clone_object("players/hawkeye/closed/monk/pray_obj");
			move_object(obj, cur);
			obj->set_owner(this_player()->query_real_name());
			obj->prayer();
			this_player()->add_spell_point(-15);
			if(cur != this_player()){
				write(capitalize(cur->query_name())+" is under the effect of "+
				      "your Prayer.\n");
				tell_object(cur, "You are under the effect of "+ME+"'s Prayer Spell.\n"+
					    "You feel stronger and more courageous with "+ME+"'s blessing.\n");
				}
			}
		}
	}
return 1;
}

/* --- FIRST STAT --- */
first_stat(str){
	object obj;
if(!str){
	write("Usage: stt <target>.\n");
	return 1; 
	}
obj = present(str, environment(this_player()));
if(!obj){
	write("There is no "+str+" here.\n");
	return 1; 
	}

if(!living(obj)){
	write("This command is for living things.\n");
	return 1; 
	}
write("\n");
write("You compare "+capitalize(obj->query_name())+":\n");
write(obj->short()+"\n");
if(obj->query_level() > this_player()->query_level())
	write(": is higher level than you.\n");
else
	write(": is lower level than you.\n");
if(obj->query_hp() > this_player()->query_hp())
	write(": has More hit points than you.\n");
else
	write(": has Less hit points than you.\n");
if(obj->query_wc() > this_player()->query_wc())
	write(": has a Better weapon class than you.\n");
else
	write(": has a Worse weapon class than you.\n");
if(obj->query_ac() > this_player()->query_ac())
	write(": has a Better armor class than you.\n");
else
	write(": has a Worse armor class than you.\n");
return 1;
}

/*                      SHIELD                                          */
shield() {
 object ob;

if(!present("shield_obj", this_player())){
	ob = clone_object("players/hawkeye/closed/monk/shield_obj");
	move_object(ob, this_player());   }
	command("shiel_d", this_player());
	return 1;
}

/* --- SEND --- */
send(str){
	object ob, obj;
	string who, what;

if(this_player()->query_guild_rank() < 3) {
	write("You must attain a higher level in the guild before\n"+
	      "using this skill.\n");
	return 1;
	}
if(this_player()->query_sp() < 20) {
	write("You do not have the energy to perform this.\n");
	return 1;
	}

if(!str || !sscanf(str, "%s %s", who, what)){
	write("Usage: send <who> <what>.\n");
	return 1; 
	}

obj = find_player(who);
if(!obj){
	write(capitalize(who)+" is not on the game.\n");
	return 1; 
	}

if(obj->query_level() > 19){
	write("You cannot send stuff to Wizards.\n");
	return 1; 
	}

ob = present(what, this_player());
if(!ob){
	write("You do not have a "+what+".\n");
	return 1; 
	}

command("drop "+what, this_player());
if(!present(what, environment(this_player()))){
	write("You cannot send That!\n");
	return 1; 
	}

write("You put the "+what+" on the ground and a large Eagle comes to "+
      "carry it off.\n");
say(ME+" gives something to a large Eagle.  The bird flies off.\n");
this_player()->add_spell_point(-20);
move_object(ob, obj);
tell_object(obj,
	    "An Eagle flies into the room and gives you something.\n");
tell_room(environment(obj),
	  "A large bird enters the room and gives something to "+who+".\n");
call_out("delivered", 10);
package = capitalize(what);
return 1;
}

delivered(){
tell_object(shit,
	    "Your package was delivered safely. ["+package+"]\n");
return 1;
}

/* --- ATTACKS (extra monk attacks) --- */

/* -- start special attack -- */
/* Special Attack: see explanation: 
		/players/hawkeye/closed/monk/special_attack
*/
start_special_attack(){
/*
  call_out("special_attack", 3);
  return 1;
*/
}

special_attack(){
  object obj;
  int when;
  obj = environment(this_object());
  when = obj->query_guild_rank();
  when = 25 - when;
  if(when < 15)  when = 15;
  if(!obj->query_attack())
    return 1;
  if(obj->query_attack()->query_npc() != 1)
    return 1;
  command("sp_attack", obj);
  call_out("special_attack", when);
  return 1;
}
/* NOTE: func 'sp_attack' is located in
       /players/hawkeye/closed/monk/special_attack
*/

 

/* ---- STUN MONSTER ------- */

stun_monster(str){

 string who;
write("This command has been disabled. -Bp\n");
/*this command is bugged as also idiotic something a level 21 would code.
the monks are becoming a shit-like newbie wiz guild agian. I want all 
the stuff like this removed. you will be VERY unhappy if you make me
check the object.
*/
return 1;

if(this_player()->query_guild_rank() < 9) {
    write("You must attain a higher level in the guild before\n"+
         "using this skill.\n");
return 1;
}
if(this_player()->query_sp() < 50) {
     write("You do not have the energy to perform this.\n");
return 1;
}

if(!this_player()->query_attack()){

 write("You must be fighting to use stun.\n");

 return 1; }

if(stunwait > 0){

 write("You cannot use another Nerve Pinch yet.\n");

 return 1; }

if(!str)

 stunwho = this_player()->query_attack();

else

 stunwho = present(str, environment(this_player()));

if(stunwho->query_npc() != 1){

 write("You cannot Stun players.\n");

 return 1; }

if(present("fire_wall", stunwho)){

 write("Your intended victim cannot be stunned inside a Firewall.\n");

 return 1; }

who = capitalize(stunwho->query_name());

stunwait = 1;

stunwc = stunwho->query_wc();

stunwho->set_wc("GRABBED");

call_out("recover", 25);

this_player()->add_spell_point(-50);

write("You reach out and grab "+who+"'s neck.\n"+

 "You apply pressure to "+who+"'s nerve points and immobilize "+

 "your victim.\n");

say(ME+" grabs who by the neck and pinches a nerve center.\n"+

 who+" is immobilized!\n");

return 1;

}

 

recover(){

if(stunwho){

 stunwho->set_wc(stunwc);

 tell_room(environment(stunwho), capitalize(stunwho->query_name())+

 " recovers from the nerve pinch.\n");

 stunwho->attack_object(shit);

           }

stunwait = 0;

stunwho = 0;

return 1;

}

