inherit "obj/monster";
   object gold,weapon;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Roland");
   set_race("roland");
   set_alias("roland");
	set_short("Roland of Gilead, son of Steven");
	set_long("Roland is the last knight of the Mid-World.  He is tall, dressed in black and\n" +
	"has a six shooter on his hip.  You notice his left hand has some missing\n" +
	"fingers and is almost useless.  Still, as you look into his eyes you \n" +
	"know he can kill you.\n");
   set_level(20);
   set_hp(100);
   set_al(-1000);
   set_wc(45);
   set_ac(17);
   set_chance(20);
	set_can_kill(1);
   set_spell_dam(45);
	set_spell_mess1("Roland fires off six deadly rounds.\n");
	set_spell_mess2("Roland fires of six rounds at you.\n" +
	"***BLAM***\n" +
	"    ***BLAM***\n" +
	"        ****BLAM****\n" +
	"                ***BLAM***\n" +
	"                    ***BLAM***\n" +
	"			 ***BLAM***\n");
	set_a_chat_chance(20);
   set_chat_chance(5);
	load_chat("Roland says: Nothing will stop me from going to the tower.\n");
	load_chat("Roland looks at you and a chill runs up your spine.\n");
	load_a_chat("Roland whispers: Foolish one, my world has moved on...I will still destroy you.\n");
    gold = clone_object("obj/money");
   gold->set_money(random(2500)+3500);
	move_object(gold,this_object());
	weapon=clone_object("/players/dragnar/weapons/sword.c");
	move_object(weapon,this_object());
}
heart_beat() {
	object att;
int v,x,y,z;
	::heart_beat();
	att=(this_player()->query_attack());
	x=random(100);
	v=random(100);
	y=random(100);
	z=random(100);
	if(x < 15) {
	command("north",this_player());
	return 1;
	}
	if(y < 15) {
	command("south",this_player());
	return 1;
	}
	if(v < 15) {
	command("east",this_player());
	return 1;
	}
	if(z < 15) {
	command("west",this_player());
	return 1;
	}
	if( z > 80) {
	command("give 2000 coins to roland",att);
	tell_object(att, "Roland concetrates for a moment and takes some of your money.\n");
	return 1;
	}
}
