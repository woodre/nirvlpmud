/* Templar Code by Maledicta, 11/99 */
/* Ally commands added by Dragnar, 12/7/99 */

#include "/players/maledicta/ansi.h"

#define ALLY "players/boltar/templar/daemon/Ally.c"
#define CRIM "/players/boltar/templar/daemon/Criminal.c"
#define LOG "/players/boltar/templar/log/Ally"
#define TP this_player()
short(){
	return ""+HIM+"The Tablet"+NORM+"";
}

query_value()
{
	return 0;
}

query_weight() {   return 2000; }
long(){
	write(
		"Inscribed upon its surface are the words...\n\n"+
		"              "+HIB+"-=["+NORM+BOLD+"Code of the Knights Templar"+NORM+HIB+"]=-"+NORM+"\n\n\n"+
		"______________________________________________________________\n"+
		""+BOLD+"   I.      Courage is Life.\n"+
		"   II.     Protect the Innocent and the good\n"+
		"   III.    Aid the weak and Misfortunate\n"+
		"   IV.     Banish All Evil from the Realm\n"+
		"   V.      Honor the Spirit of the Challenge\n"+
		"   VI.     Courtesy in all things\n"+
		"   VII.    Serve Willingly the Knighthood and the Cause\n"+
		"   VIII.   Be a Shining Example unto the Knighthood\n"+
		"   IX.     Respect those of Equal or Higher station\n"+
		"   X.      Never Lie\n"+
		"   XI.     Never Steal\n"+
		"   XII.    Always Be Prepared\n"+
		"   XIII.   Death Before Dishonor\n"+
		"   XIV.    Die with Honor"+NORM+"\n"+
		"______________________________________________________________\n"+
		"   For more information on any of the Codes, type:\n"+
		"         read #   (ex. read III -or-  read 3)\n"+
		"Type 'info ally' for a list of commands.\n"+
		"If you are an ally and wish to gain your object, type: alliance\n");
}


init() {
	object cross;
	cross = present("KnightTemplar", this_player());
	add_action("read","read");
	add_action("amb_title", "atitle");
	add_action("weapon_master", "weapontitle");
	add_action("judge", "judgetitle");
	add_action("get_ally", "alliance");
	if(this_player()->query_guild_file() == "players/boltar/templar/templar" 
		|| this_player()->query_real_name() == "dragnar" 
		|| this_player()->query_real_name() == "maledicta" ) {
			add_action("new_title","title");
		}
		if(this_player()->query_guild_file() == "players/boltar/templar/templar" 
			|| ALLY->Query(this_player()->query_real_name()) 
			|| this_player()->query_real_name() == "dragnar" 
			|| this_player()->query_real_name() == "maledicta") {
				add_action("criminal_who","cwho");
				add_action("ally_who","awho");
				add_action("ally_list","alist");
				add_action("info","info");
			}
			if(this_player()->query_real_name() == "daredevil" || this_player()->query_real_name() == "stone"
				|| this_player()->query_level() > 49
				|| this_player()->query_real_name() == "justin"
				|| (cross && cross->query_council())) {
					add_action("get_rank", "rank");
					add_action("remove_ally","unally");
					add_action("add_ally","ally");
				}
}
judge(){
	if(this_player()->query_real_name() == "larisa" || this_player()->query_real_name() == "justin"){
		this_player()->set_pretitle(HIB+"Judge Advocate"+NORM);
		write("Title set to Judge advocate.\n");
		return 1;
	}
	return 0;
}

amb_title(){

	if(this_player()->query_real_name() == "stone" || 
	   this_player()->query_real_name() == "daredevil"){
		this_player()->set_pretitle(HIW+"Templar Ambassador"+NORM);
		write("Pretitle set to Ambassador.\n");
		return 1;
	}
	
	return 0;
}


weapon_master(){
	if(this_player()->query_real_name() == "jarana"){
		this_player()->set_pretitle(BOLD+"--Templar WeaponMaster--"+NORM);
		write("done.\n");
		return 1;
	}
	return 0;
}

get_rank(){
	if(this_player()->query_guild_rank() > 8){
		write("You are already maxed.\n");
		return 1;
	}
	write("Congratulations! You are the rank 9 Ambassador.\n");
	this_player()->add_guild_rank(9 - this_player()->query_guild_rank());
	return 1;
}

get_ally(){

	if(ALLY->Query(TP->query_real_name())){
		if(present("KnightInvite", TP)){
			destruct(present("KnightInvite", TP));
			move_object(clone_object("/players/boltar/templar/items/bracer.c"), TP);
			write("You renew your object.\n");
			return 1;
		}
		move_object(clone_object("/players/boltar/templar/items/bracer.c"), TP);
		write("You obtain your Alliance object. bracer_info for more assistance.\n");
		return 1;
	}
	return 0;
}

get() {
	write("The tablet is too heavy.\n");
	return 0;
}

id(str) { return str=="tablet"; }

info(string str) {
	object cross;

	if(!str) return 0;
	cross = present("KnightTemplar", this_player());
	if(str == "ally" || str == "allies") {
		write("Commands available:\t");
		if(cross && (this_player()->query_real_name() == "stone" 
			|| this_player()->query_real_name() == "daredevil")) {
				write("awho, cwho, alist, ally, unally, and title.\n");
			}
		else if( (cross && !cross->query_council()) || (!cross && ALLY->Query(this_player()->query_real_name()))) {
			write("awho, cwho, and alist.\n");
		}
		else if(cross && cross->query_council()) {
			write("awho, cwho, alist, ally, and unally.\n");
		} 
		else write("None.\n");
	}
	return 1;
}

ally_list() {
	cat("/players/boltar/templar/daemon/ally_record");
	return 1;
}

ally_who() {
	int i, z, ally;
	object *list;

	list = users();
	write(HIB);
	write(pad("",40,'~')+"\n");
	write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+HIB+"@\n");


	write(NORM+HIB);
	write("@"+pad("",38,'~')+"@\n");
	write("@"+pad("",38)+"@\n");
	write(NORM);
	for(i = 0, z = 0; i < sizeof(list); i++) {

		ally = ALLY->Query(list[i]->query_real_name());
		if(!environment(list[i]) || list[i]->query_level() > 19) continue;
		if(ally) {
			write(HIB+"@  "+HIW+pad(list[i]->query_name(),14)+NORM);
			z++;

			if (list[i]->query_pl_k())
				write(list[i]->query_level() + "*\t");
			else
				write(list[i]->query_level() + "\t");

			if (!list[i]->query_guild_name())
				write(pad("None",15));
			else
				write(pad(capitalize(list[i]->query_guild_name()),15));
			write(HIB+"@\n");
		}
	}
	if(!z) write(HIB+"@  "+NORM+pad("No Allies logged in.",36)+NORM+HIB+"@\n");
	write(HIB);
	write("@"+pad("",38)+"@\n");
	write(pad("",40,'@')+"\n");
	write(NORM);
	return 1;
}

criminal_who() {
	int i, z, crim;
	object *list;

	list = users();
	write(GRN);
	write(pad("",40,'~')+"\n");
	write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+GRN+"@\n");


	write(NORM+GRN);
	write("@"+pad("",38,'~')+"@\n");
	write("@"+pad("",38)+"@\n");
	write(NORM);
	for(i = 0, z = 0; i < sizeof(list); i++) {

		crim = CRIM->Query(list[i]->query_real_name());
		if(!environment(list[i]) || list[i]->query_level() > 19 || ALLY->Query(list[i]->query_real_name())) continue;
		if(crim || (list[i]->query_level() > 8 && list[i]->query_alignment() < -40)) {

			if(crim)
				write(GRN+"@  "+BOLD+RED+pad(list[i]->query_name(),14)+NORM);
			else write(GRN+"@  "+NORM+pad(list[i]->query_name(),14));
			z++;

			if (list[i]->query_pl_k())
				write(list[i]->query_level() + "*\t");
			else
				write(list[i]->query_level() + "\t");

			if (!list[i]->query_guild_name())
				write(pad("None",15));
			else
				write(pad(capitalize(list[i]->query_guild_name()),15));
			write(GRN+"@\n");
		}
	}
	if(!z) write(GRN+"@  "+NORM+pad("No Criminals logged in.",36)+NORM+GRN+"@\n");
	write(GRN);
	write("@"+pad("",38)+"@\n");
	write(pad("",40,'@')+"\n");
	write(NORM);
	return 1;
}

add_ally(string who) {
	if(!who) {
		write("ally <name>\n");
		return 1;
	}
	ALLY->Insert(who);
	write_file(LOG, ctime(time())+": "+capitalize(this_player()->query_real_name())+" added "+capitalize(who)+".\n");
	return 1;
}

remove_ally(string who) {
	if(!who) {
		write("unally <name>\n");
		return 1;
	}
	if(find_living(lower_case(who))){
		if(present("KnightInvite", find_living(who))){
			tell_object(find_living(who),
				"You have been removed from the Knight Alliance.\n");
			destruct(present("KnightInvite", find_living(who)));
		}
	}
	ALLY->Delete(who);
	write_file(LOG, ctime(time())+": "+capitalize(this_player()->query_real_name())+" removed "+capitalize(who)+".\n");
	return 1;
}

new_title(){
	if(this_player()->query_real_name() == "daredevil" ||
		this_player()->query_real_name() == "maledicta"){
			this_player()->set_title(BLU+"Ambassador of the Knights"+NORM);
			tell_object(this_player(),
				"You are awarded the Title of Ambassador. Do well with it.\n");
			return 1;
		}
		return 0;
}

read(str){

	if(!str) return 0;
	if(!this_player()->query_guild_file() == "players/boltar/templar/templar"
		|| !this_player()->query_real_name() == "dragnar"
		|| !this_player()->query_real_name() == "maledicta" ) {
			write("You cannot make out the writing for some reason.\n");
			return 1;
		}
		if(str == "1" || str == "I"){
			write(
				"The tablet reads...\n"+
				"Live a courageous life.  In all of your actions think\n"+
				"without fear.  Fight without fear in your heart and\n"+
				"you will know victory.\n");
			return 1;
		}

		if(str == "2" || str == "II"){
			write(
				"The tablet reads...\n"+
				"Never allow harm to come to those around you that\n"+
				"have good in their hearts.  Defend with your life\n"+
				"all of those who fight the true cause.\n"+
				"Protect all good allies.\n"+
				"Allies are anyone who fights evil beside you or\n"+
				"assists the guild.\n");
			return 1;
		}

		if(str == "3" || str == "III"){
			write(
				"The tablet reads...\n"+
				"If one should fall upon hard times, be ready to assist\n"+
				"in any way possible.  Aid those who are unfortunate\n"+
				"enough not to enjoy your skills.\n"+
				"Assist Newbies with coins, party time, equipment, or\n"+
				"information whenever you can.  Remember that this\n"+
				"assistance will be paid back at a later date.\n");
			return 1;
		}

		if(str == "4" || str == "IV"){
			write(
				"The tablet reads...\n"+
				"Destroy all evildoers in the land.  These are the\n"+
				"criminals, thieves, and murderers of the realm.\n"+
				"Never ally with evil, for it will destroy your\n"+
				"spirit.\n"+
				"Those who commit acts of harrasment and murder\n"+
				"are deemed killable. As are those with an evil\n"+
				"alignment or targeted as criminals. Kill them to\n"+
				"preserve what is good in the realm.\n");
			return 1;
		}

		if(str == "5" || str == "V"){
			write(
				"The tablet reads...\n"+
				"Each moment seek valor in the face of a challenge\n"+
				"that is greater than yourself.\n"+  
				"Never attack someone that is more than 8 levels below\n"+
				"you. This does not include extra levels. The only\n"+
				"exception is in the defense of a fellow Knight or\n"+
				"innocent civilian.\n");
			return 1;
		}

		if(str == "6" || str == "VI"){
			write(
				"The tablet reads...\n"+
				"Chivalry is the heart of a Knight. Act with\n"+
				"manners in all things. Treat each other with\n"+
				"the respect of a brotherhood.\n"+
				"Never Curse on open lines.\n"+
				"Treat each knight with the utmost respect.\n"+
				"Be kind.\n");
			return 1;
		}

		if(str == "7" || str == "VII"){
			write(
				"The tablet reads...\n"+
				"Do what is necessary to further the cause of the\n"+
				"Knighthood.  Follow the orders of the council and\n"+
				"know that their decisions are based on furthering\n"+
				"the cause.\n");
			return 1;
		}

		if(str == "8" || str == "VIII"){
			write(
				"The tablet reads...\n"+
				"Act with chivalry and honor. Remember that courage\n"+
				"is your life, and shoulder the responsibilities of\n"+
				"your station readily.\n"+
				"A knight does not complain when things happen to go\n"+
				"wrong. A knight will act with mature dignity and\n"+
				"respect.\n");
			return 1;
		}

		if(str == "9" || str == "IX"){
			write(
				"The tablet reads...\n"+
				"Whether in or out of the Knighthood, respect those\n"+
				"who have worked hard in their endeavors, whether\n"+
				"they be the enemy before you, or the ally beside\n"+
				"you.\n"+
				"Talking 'trash' is not knightly.\n");
			return 1;
		}

		if(str == "10" || str == "X"){
			write(
				"The tablet reads...\n"+
				"Lies are the place of thieves and murderers. Never\n"+
				"lower yourself within this evil web of deceit. Lies\n"+
				"are trickery and deceit. Fight with courage, never\n"+
				"with tricks.\n");
			return 1;
		}

		if(str == "11" || str == "XI"){
			write(
				"The tablet reads...\n"+
				"Thieves are to be put to death. Do not ally\n"+
				"yourself with this element.\n");
			return 1;
		} 

		if(str == "12" || str == "XII"){
			write(
				"The tablet reads...\n"+
				"Battle is the highest means of glory. Be prepared\n"+
				"always to test your valor.\n"+
				"When you are on, let others know your present\n"+
				"situation and if you can assist if the time\n"+
				"comes.\n");
			return 1;
		}

		if(str == "13" || str == "XIII"){
			write(
				"The tablet reads...\n"+
				"Your honor is your soul. Whomever befouls it must\n"+
				"feel the might of your truth. Never dishonor your-\n"+
				"self in any way. You are a pillar unto the knights,\n"+
				"and lead by way of your honor.\n");
			/*  Don't like how this can be viewed - Dragnar 
			"You have the right to challenge anyone for a match\n"+
			"to the death if you feel your honor has been blemished\n"+
			"by anothers words or actions.  This includes fellow\n"+
			"knights who should know better than to trample another\n"+
			"knights honor.\n");
			******************************/
			return 1;
		}

		if(str == "14" || str == "XIV"){
			write(
				"The tablet reads...\n"+
				"Die in combat, with courage, and knowing that your\n"+
				"sword was striking for truth.\n");
			return 1;
		}

}
