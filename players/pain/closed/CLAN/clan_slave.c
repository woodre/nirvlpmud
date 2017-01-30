/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*
/*  Guild Slave Object for Clan McKay
/*
/*  Pain 01/23/95
/*
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include "/players/pain/color.h"

#define member this_player()
#define me capitalize(this_player()->query_real_name())
#define m_name this_player()->query_real_name()
#define faction this_player()->query_guild_name()
#define m_sp this_player()->query_SP()
#define m_hp this_player()->query_HP()
#define m_gl this_player()->query_guild_rank()
#define m_gx this_player()->query_guild_exp()
#define m_str this_player()->query_attrib("str")
#define m_mag this_player()->query_attrib("mag")
#define m_dex this_player()->query_attrib("stl")

   /* substitute dex for stl */

help_clan() {
   cat("/players/pain/closed/CLAN/clan_help");
   return 1;
}

clan_levels() {
   cat("/players/pain/closed/CLAN/DOCs/levels");
   write("\n");
}

clan_cost() {
   cat("/players/pain/closed/CLAN/DOCs/cost");
   write("\n");
}

clan_talk(str) {

int x;
object ob;
object kilt;

if(!str){
	write("And what pray-tell would you like to share with the "+
	      "rest of the clan??\n");
	return 1;
}

ob = users();
for( x = 0; x < sizeof(ob); x += 1) {
if(present("kilt", ob[x])){
kilt = present("kilt", ob[x]);
if(kilt->query_muff() == 0 && kilt->query_color() == 0){
	tell_object(ob[x],RED+"<CLAN>"+END+me+": "+str+"\n");
}
if(kilt->query_muff() == 0 && kilt->query_color() == 1){
	tell_object(ob[x],"<CLAN>"+me+": "+str+"\n");
}
}
}
return 1;
}

clan_emote(str) {

int x;
object ob;
object kilt;

if(!str) {
	write("And what pray-tell would you like to emote to the "+
	      "rest of the clan??\n");
	return 1;
}

ob = users();
for( x = 0; x < sizeof(ob); x += 1) {
if(present("kilt",ob[x])) {
kilt = present("kilt",ob[x]);
if(kilt->query_muffs() == 0 && kilt->query_color() == 0) {
	tell_object(ob[x],RED+"<CLAN>"+END+me" "+str+"\n");
}
if(kilt->query_muffs() == 0 && kilt->query_color() == 1) {
	tell_object(ob[x],"<CLAN> "+me+" "+str+"\n");
}
}
return 1;
}

apprentice(str) {
   object obj,
	  appr;
   if(!str) {
      write("Usage: apprentice <playername>\n");
      return 1;
   }
   appr = present(str,environment(member));
   if(!appr) {
      write("Player must be present in order to be apprenticed\n"+
	    "to the Clan\n");
      return 1;
   }
   obj = clone_object("/player/pain/closed/CLAN/recruit.c");
   move_object(obj,appr);
   return 1;
}

call_to_action() {

int x;
object ob;
object kilt;

ob = users();

for( x = 0; x < sizeof(ob); x += 1) {

        if(present("kilt", ob[x])){
                kilt = present("kilt", ob[x]);
                if(kilt->query_muff() == 0 && kilt->query_color() == 0){
                        tell_object(ob[x],RED+"<CLAN>"+END+me+": I am fighting "
                                +member->query_attack()->query_name()+" in "
                                +environment(member)->query_short()+RED+" help"
                                +"!\n");
                }
                if(kilt->query_muff() == 0 && kilt->query_color() == 1){
                        tell_object(ob[x],RED+"<CLAN>"+END+me+": I am fighting "
                                +member->query_attack()->query_name()+" in "
                                +environment(member)->query_short()+RED+" help"
                                +"!\n");
                }
        }
}

return 1;
}

members() {
int count,
    rank,
    invis,
    i,
    x;

object kilt,
       ob;

string name,
       faction,
       location;

ob = users();
i = 0;
invis = 0;

write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
write(" Name:           Faction:       Rank:     Location:\n");
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");

for( x = 0; x < sizeof(ob); x += 1) {
if(present("kilt",ob[x]) {
	name = capitalize(ob[x]->query_real_name());

	if(ob[x]->query_invis < 0) { invis = 1; }

7	if(ob[x]->query_guild_name() == "clan_druid") {
		faction = "Druid";
	}
	else faction = "Swordsmen";

	rank = ob[x]->query_guild_level();

	location = environment(ob[x])->query_short()

	if(invis < 0) { write("*"); }
	else write(" ");
	count = strlen(name);
	count = 16 - count;
	write(name);
	while(count > 0) {
		write(" ");
		count = count - 1;
	}
	count = strlen(faction);
	count = 18 - count;
	write(faction);
	while(count > 0) {
		write(" ");
		count = count - 1;
	}
	if(rank > 9) { write(rank); }
	else write(" "+rank);
	write("     ");
	write(location+"\n");
	i = i + 1;
}
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
write(" Clan Members Currently Logged in: "+i+"\n");
write("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");

mud_who() {
}

guild_title() {
   if(m_gl == 1 && faction == "clan_druid") {
      member->set_title("the initiate Druid");
      return 1;
   }
   if(m_gl == 1 && faction == "clan_sword") {
      member->set_title("the initiate Swordsman");
      return 1;
   }
   if(m_gl == 2 && faction == "clan_druid") {
      member->set_title("the apprentice Druid");
      return 1;
   }
   if(m_gl == 2 && faction == "clan_sword") {
      member->set_title("the apprentice Swordsman");
      return 1;
   }
   if(m_gl == 3 && faction == "clan_druid") {
      member->set_title(", Nature's apprentice");
      return 1;
   }
   if(m_gl == 3 && faction == "clan_sword") {
      member->set_title("the soldier of the Clan");
      return 1;
   }
   if(m_gl == 4 && faction == "clan_druid") {
      member->set_title("a Druid of the First Order");
      return 1;
   }
   if(m_gl == 4 && faction == "clan_sword") {
      member->set_title("the Sargeant of the Guard");
      return 1;
   }
   if(m_gl == 5 && faction == "clan_druid") {
      member->set_title("a Druid of the Second Order");
      return 1;
   }
   if(m_gl == 5 && faction == "clan_sword") {
      member->set_title("the Blademaster");
      return 1;
   }
   if(m_gl == 6 && faction == "clan_druid") {
      member->set_title("a Druid of the Third Order");
      return 1;
   }
   if(m_gl == 6 && faction == "clan_sword") {
      member->set_title("a protector of the Thane");
      return 1;
   }
   if(m_gl == 7 && faction == "clan_druid") {
      member->set_title("a Druid of the Fourth Order");
      return 1;
   }
   if(m_gl == 7 && faction == "clan_sword") {
      member->set_title("the Captain of the Guard");
      return 1;
   }
   if(m_gl == 8 && faction == "clan_druid") {
      member->set_title("an initiate to the Inner Circle");
      return 1;
   }
   if(m_gl == 8 && faction == "clan_sword") {
      member->set_title("the Hero of the Army of the Clan");
      return 1;
   }
   if(m_gl == 9 && faction == "clan_druid") {
      member->set_title("an apprentice to the Inner Circle");
      return 1;
   }
   if(m_gl == 9 && faction == "clan_sword") {
      member->set_title("General of the Army of the Clan");
      return 1;
   }
   if(m_gl == 10 && faction == "clan_druid") {
      member->set_title("a member of the Inner Circle");
      return 1;
   }
   if(m_gl == 10 && faction == "clan_sword") {
      member->set_title("Champion of the Thane, Lord of the Clan");
      return 1;
   }
   if(m_gl > 10 && faction == "clan_druid") {
      member->set_title("the Master of Nature");
      return 1;
   }
   if(m_gl > 10 && faction == "clan_sword") {
      member->set_title("the Master of the Blade");
      return 1;
   }
}

   /* Druid Faction Spells */

/* icy grasp */
grasp(str) {
   object attack;
   string a_name;
   int roll;

   if(!str) {
      write("Whom do you wish to grasp?\n");
      return 1;
   }
   attack = present(str,environment(member));
   if(!attack) {
      write("That monster is not in the room!\n");
      return 1;
   }
   if(attack->query_npc() == 0) {
      write("You cannot grasp another player!\n");
      return 1;
   }

   if(m_sp < 20) {
	write("You need more spell points to cast this.\n");
	return 1;
   }
   member->add_sp(-20);
   a_name = attack->query_real_name();
   write("You reach out to grasp "+a_name()+".\n");
   say(m_name+" grasps "+a_name+" with an icy hand.\n");
   roll = random(100);
   if(roll < 20 && m_gl < 3) {
      write(a_name+" is chilled by your grasp.\n");
      a_name->hit_player(7);
      return 1;
   }
   if(roll < 20 && m_gl < 5) {
      write("You freeze "+a_name+" with your grasp.\n");
      a_name->hit_player(12);
      return 1;
   }
   if(roll < 20 && m_gl < 8) {
      write(a_name+" quivers as you grasp him.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 50 && m_gl < 3) {
      write("You freeze "+a_name+" with your grasp.\n");
      a_name->hit_player(12);
      return 1;
   }
   if(roll < 50 && m_gl < 5) {
      write(a_name+" quivers as you grasp him.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 50 && m_gl < 8) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 85 && m_gl < 3) {
      write(a_name+" quivers at your icy grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 85 && m_gl < 5) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 85 && m_gl < 8) {
      write(a_name+" is thrown back by your icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 101 && m_gl < 3) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 101 && m_gl < 5) {
      write(a_name+" is thrown back by your icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 101 && m_gl < 8) {
      write(a_name+"'s soul is frozen by your icy grasp.\n");
      a_name->hit_player(30);
      return 1;
   }
   if( m_gl > 8) {
      write("You devestate "+a_name+" with your icy grasp!\n");
      a_name->hit_player(20+random(m_mag));
      return 1;
   }
}
/* end icy grasp */

/* meld with your surroundings */
meld() {
   if(m_sp < 20) {
      write("You need more spell points to cast this.\n");
      return 1;
   }

   member->add_sp(-20);
   write("As you meld with the surrounding nature, you begin to feel\n"+
      "stronger. You feel the power of Nature coursing through you.\n");
   say(m_name+" melds with Nature and appears stonger.\n");
   member->add_hp(20);
   return 1;
}
/* end meld */

/* rain */
rain() {
   object attack;
   string a_name;
   int roll;

   if(m_gl < 2) {
      write("You must be a higher level in the guild\n"+
	    " to use this spell.\n");
      return 1;
   }

   if(member->query_attack() == 0) {
      write("You must be in battle to use this spell.\n");
      return 1;
   }

   if(m_sp < 35) {
      write("You need more spell points to cast this.\n");
      return 1;
   }
   attack = member->query_attacker();
   if(attack->query_npc == 0) {
      write("You can not call for a rain storm on a player.\n");
      return 1;
   }

   a_name = attack->query_real_name();
   write("You call for a Rain Storm from Mother Nature.\n");
   say(m_name+" calls for a Rain Storm from Mother Nature.\n");
   member->add_sp(-35);
   roll = random(100);
   if(roll < 30 && m_gl < 4) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the arm.\n");
      a_name->hit_player(10);
      return 1;
   }
   if(roll < 30 && m_gl < 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the leg.\n");
      a_name->hit_player(13);
      return 1;
   }
   if(roll < 30 && m_gl > 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the forehead.\n");
      a_name->hit_player(18);
   }
   if(roll < 70 && m_gl < 4) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the leg.\n");
      a_name->hit_player(13);
      return 1;
   }
   if(roll < 70 && m_gl < 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the forehead.\n");
      a_name->hit_player(18);
      return 1;
   }
   if(roll < 70 && m_gl > 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the neck.\n");
      a_name->hit_player(22);
      return 1;
   }
   if(roll < 101 && m_gl < 4) {
      write(a_name+"'s weapon slips and nicks "+a_name+" in the forehead.\n");
      a_name->hit_player(18+random(m_mag));
      return 1;
   }
   if(roll < 101 && m_gl < 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" in the neck.\n");
      a_name->hit_player(22+random(m_mag));
      return 1;
   }
   if(roll < 101 && m_gl > 7) {
      write(a_name+"'s eyes grow large as "+a_name+"'s weapon slips "+
	    "and\n nicks"+a_name+" in the groin!\n");
      a_name->hit_player(25+random(m_mag));
      return 1;
   }
}
/* end rain */

/* lightning (stronger attack spell) */
lightning(str) {
   object attack;
   string a_name;
   int roll;

   if(m_gl < 3) {
      write("You must attain a higher level in the Clan to cast this.\n");
      return 1;
   }

   if(!str) {
      write("Who do you wish to strike with lightning?\n");
      return 1;
   }

   attack = present(str,environment(member));
   if(attack->query_npc() == 0) {
      write("You cannot use this spell on a player!\n");
      return 1;
   }
   if(m_sp < 45) {
      write("You need more spell points to cast this.\n");
      return 1;
   }

   write("You call upon the powers of nature to strike "+a_name+" with\n"+
      "lightning from the skys above.\n");
   say(m_name+" calls lightning down from to attack "+a_name+".\n");
   member->add_sp(-45);
   roll = random(100);
   if(roll < 10 && m_gl < 5) {
      write("The lightning misses "+a_name+"!\n");
      return 1;
   }
   if(roll < 10 && m_gl < 9) {
      write("The lightning weakens after travelling and barely shocks "+
	    a_name+", sending a light shock through him.\n");
      a_name->hit_player(5);
      return 1;
   }
   if(roll < 30 && m_gl < 5) {
      write("The lightning strikes "+a_name+" and you smell "+
	    "burning hair.\n");
      a_name->hit_player(15);
      return 1;
   }
}
