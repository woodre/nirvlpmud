/*
	Changelog:
	Bal 1996-03-15:
	- fixed typo in shout() (defeaded->defeated)
	* fixed assumptions in heart beat (now no run-time errors)
*/
#define LOGFILE "/players/dragnar/logs/champs.log"
inherit "obj/monster";
inherit "/obj/user/one_chan.c";

object gold;

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_name("tsung");
    set_race("shang");
    set_alias("shang");
    set_short("Shang Tsung, champion of Mortal Kombat");
    set_long(
"He seems to be an old man, about 700 years old.  He has not been\n"+
"defeated in his 500 years as champion of Mortal Kombat.  Even Goro\n"+
"bows to the master.  If you defeat him you will be crowned the victor.\n");
    set_level(20);
    set_hp(2000);
    set_al(-1000);
    set_wc(30);
    set_ac(random(40));
    gold = clone_object("obj/money");
    gold->set_money(random(4000)+5000);
    move_object(gold,this_object());
}

heart_beat() {
    object att, scar, amulet;

    ::heart_beat();

    if (!(att = (object) this_player()->query_attack()))
	return;
    if (att == this_object()) {
	set_hp(2000);
	stop_fight();
	if (!(att = (object) this_player()->query_attack()))
	  return;
    }
    
    if (att->query_hp() < 50) {
	tell_object(att,
		"Shang Tsung smashes you and makes you bleed.\n"+
		"He lets you suffer as you bleed to death.\n");
/*  changed as per Boltar instruction  -Eurale 4/23/97
	shout("Shang Tsung has defeated " +
		capitalize(att->query_real_name()) +
		" and is still Champion of Mortal Kombat.\n");
*/
chan_msg("Shang Tsung has defeated "+
  capitalize(query_attack()->query_real_name())+
  " and is still Champion of Mortal Kombat.\n","msg");
	att->hit_player(200);
	return;
    }
    if (random(100) < 20) {
	say("Shang Tsung looks stronger as he drains energy from you.\n");
	att->hit_player(20);
	this_object()->heal_self(20);
    }
    if (this_object()->query_hp() < 900) {
/*  changed:  4/23/97  -Eurale
	shout(capitalize(att->query_real_name()) +
		" has defeated Shang Tsung and is now Champion of Mortal Kombat.\n");
*/
chan_msg(capitalize(query_attack()->query_real_name())+
  " has defeated Shang Tsung and is now Champion of Mortal Kombat.\n","msg");
	scar = clone_object("/players/dragnar/closed/scar");
	move_object(scar, att);
	amulet=clone_object("/players/dragnar/items/amulet");
	move_object(amulet, this_object());
	say("Shang Tsung died.\n");
	tell_object(att, "You killed Shang Tsung.\n");
	att->add_exp(20000);
	destruct(this_object());
    }
}
