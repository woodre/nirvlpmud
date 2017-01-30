inherit "players/pain/closed/weapons/p_weap";
#include "/players/pain/color.h"
#define SC BOLD+RED+"SoulCrusher"+END
#define stuff environment(this_object())
#define att who
#define attn who->query_name()
#define tp this_player()
#define tpn this_player()->query_name()
#define tps this_player()->query_attrib("ste")
#define tpsr this_player()->query_attrib("str")
#define tpl this_player()->query_level()
/* I use stealth here for dexterity */

int i;
int j;
int k;
object who;
reset(arg) {
   ::reset(arg);
   if(arg) return;
    set_short("a mace named "+SC);
    set_alias("mace");
	set_long("This is a huge mace, seemingly with a mind of its own.\n");
	set_class(20);
	set_weight(5);
	set_value(100000);
        set_hit_func(this_object());
	call_out("setstuff",1);
}


weapon_hit(attacker) {
who = attacker;
k = random(tps);
if(k > who->query_hp()) { k = who->query_hp(); }
i=random(100);
j = tpl+tps+tpsr;  /* The max here is 59 */
if( i > j) {       /* Do the extra stuff */
while(k > 1) {
if(k < 5) {
	write(SC+" hums quietly in your hand and lashes out at "+attn
	     +".\n");
	say(SC+" hums in "+tpn+"'s hand and lashes out at "+attn
	   +".\n");
	tell_object(who, SC+" hums quietly and lashes out at you.\n");
	who->hit_player(k);
	k = k - 5;
}
if(k > 4 && k < 10) {
	write(SC+" rages in your hand, smashing into "+attn+".\n");
	say(SC+" rages in "+tpn+"'s hand, smashing into "+attn+".\n");
	tell_object(who, SC+" rages, smashing into you.\n");
	who->hit_player(k);
	k = k - 5;
}
if(k > 9 && k < 15) {
	write(SC+" glows with power, utterly destroying "+attn+".\n");
	say(SC+" glows with power in "+tpn+"'s hand, utterly destroying "
	   +attn+".\n");
	tell_object(who, SC+" glows with power, utterly destroying you.\n");
	who->hit_player(k);
	k = k - 5;
}
if(k > 14 && k < 21) {
	write(SC+" says \"Welcome to PLANET MOTHERFUCKER\".\n");
	say(SC+" says \"Welcome to PLANET MOTHERFUCKER\".\n");
	tell_object(who, SC+" says \"Welcome to PLANET MOTHERFUCKER\".\n");
	who->hit_player(k);	
	k = k - 5;
}
}
}
else if(i < 15) { 
	tp->hit_player(random(10)); 
	write(SC+" smacks you.\n"); 
	return; 
}
return;
}

