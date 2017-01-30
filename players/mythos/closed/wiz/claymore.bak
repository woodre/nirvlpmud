
inherit "obj/weapon";
#define tpn this_player()->query_name()
#define atn attacker->query_name()
#define tp this_player()
#define tpl this_player()->query_level()
#define tpsr this_player()->query_attrib("str")
#define te environment(this_object())
object part;
int i;
int wclass;


init() {
	add_action("check_wield","wield");
	add_action("extra","extra");
}
reset(arg) {
    ::reset(arg);
	if(arg) return;
	set_short("A HUGE Claymore Sword");
	set_alias("claymore");
	set_long("You see something special\n");
	set_value(10);
	set_weight(3);
	set_class(20);
	set_hit_func(this_object());
}

query_save_flag() { return 1; }

check_wield(str) {
if(!living(environment(this_object()))) { ::wield("claymore"); return; }
	if(str != "claymore") {
		::wield(str);
	}
	if(str == "claymore" && tpl < 8) {
		write("You attempt to wield the Claymore, but you haven't the experience!\n");
		say(tpn+" attempts to wield the Claymore and fails miserably!\n");
		return 1;
	}
	if(str == "claymore" && tpl > 7 && tpsr < 14) {
		write("You attempt to wield the Claymore and find that you haven't got the strength.\n");
		say(tpn+" is too weak to wield the Claymore!\n");
		return 1;
	}

if(str == "claymore") {
		::wield("claymore");
	if(tpl > 7 && tpl < 15) {
		this_object()->set_class(15);
		write("The claymore whispers to you: 'Rock with me!'\n");
	}
	if(tpl > 14 && tpsr < 19) {
		this_object()->set_class(16);
		write("The claymore whispers to you: 'Let us rock my master!'\n");
	}
	if(tpl > 15 && tpl < 17 && tpsr > 18) {
		this_object()->set_class(17);
		write("The claymore whispers to you: 'What is your bidding master?'\n");
	}
	if(tpl > 17 && tpsr > 18) {
		this_object()->set_class(18);
		write("The claymore whispers to you: 'You are a mighty warrior, master!'\n");
	}
	extra();
return;
}
}

weapon_hit(attacker) {
	if(attacker->is_pet()){
	attacker->heal_self(-25);
	}
    if(this_player()->is_pet()) {
    this_player()->heal_self(-25);
    }
	i = random(100);
	if(i < 3){
	   write("You slice off one of "+attacker->query_name()+"'s arms.\n");
       	   attacker->heal_self(-random(20));
	   part = clone_object("players/pain/closed/misc/part");
	   part->setup("arm",atn,tpn);
	   /*
	   part->set_part("arm");
	   part->set_name(atn);
	   part->set_owner(tpn);
	   */
	   move_object(part,environment(this_player()));
	   return 0;
}

if((i>3)&&(i<7)){
	write("You swing wildly and hack off your opponents leg just below the kneecap.\n");
	say(tpn+" lunges forward and hacks off "+attacker->query_name()+"'s leg.\n");
	attacker->heal_self(-random(20));
	part = clone_object("players/pain/closed/misc/part");
	part->setup("leg",atn,tpn);
	/*
	part->set_part("leg");
	part->set_name(atn);
	part->set_owner(tpn);
	*/
	move_object(part, environment(this_player()));
	return 0;
}

if((i>20)&&(i<24)){
	write("In an excellent show of swordsmanship, you whack off your opponent's nose.\n");
	say(tpn+" removes "+attacker->query_name()+"'s nose with crushing blow.\n");
	attacker->heal_self(-random(20));
	part = clone_object("players/pain/closed/misc/part");
	part->setup("nose",atn,tpn);
	/*
	part->set_part("nose");
	part->set_name(atn);
	part->set_owner(tpn);
	*/
	move_object(part, environment(this_player()));
	return 0;
}

if((i>30)&&(i<34)){
	write("You swing the claymore around, aiming for the head, but only get some ear.\n");
	say(tpn+" misses the head but manages to get a good chunk of ear.\n");
	attacker->heal_self(-random(10));
	return 0;
}

if((i>40)&&(i<44)){
	write("You swing your claymore and slash open your opponents gut.\n");
	write(attacker->query_name()+"'s guts fall out on the ground in a bloody heap.\n");
	attacker->heal_self(-random(20));
	part = clone_object("players/pain/closed/misc/part");
	part->setup("guts",atn,tpn);
	/*
	part->set_part("guts");
	part->set_name(atn);
	part->set_owner(tpn);
	*/
	move_object(part, environment(this_player()));
	return 0;
}

if((i==69) || (i==68)){
	if(random(30) > 14){
	write("You remove your opponent's head with a swing of your claymore. THWAK!\n");
	say(tpn+" deals "+attacker->query_name()+" a deadly blow.\n");
	attacker->heal_self(-random(20));
	part = clone_object("players/pain/closed/misc/part");
	part->setup("head",atn,tpn);
	/*
	part->set_part("head");
	part->set_name(atn);
	part->set_owner(tpn);
	*/
	move_object(part, environment(this_player()));
	}
	return 0;
}

if(i > 90){
	write("The claymore slips and you deal yourself a devastating blow!\n");
	this_player()->heal_self(-5 - random(20));
return -6;
}
return 0;
}

extra() {
	this_object()->set_short(te->query_name()+"'s Battle Claymore");
}

