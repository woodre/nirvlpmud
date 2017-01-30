#include <ansi.h>
#define DEST "/players/dragnar/workroom"
#define user this_player()
#define capname capitalize(this_player()->query_real_name())
#define uhp this_player()->query_hp()
#define usp this_player()->query_sp()
#define att this_player()->query_attack()
#define attname att->query_real_name()
#define RN this_player()->query_real_name()
#define hp att->query_hp()
#define mhp att->query_mhp()
#define umhp this_player()->query_mhp()
#define umsp this_player()->query_msp()
#define RANK user->query_guild_rank()
#define LEV user->query_level()
#define guildobj present("shardak_mark", this_player())
#define MONITOR "[HPS: "+uhp+"/"+umhp+"] [SPS: "+usp+"/"+umsp+"] "
object          play1, play2;
string          ppl_list, player1, player2, tell_msg;

id(str)
{
    return str == "object";
}

short()
{
    return "The Shardak guild Master object";
}

long()
{
    write("This machine runs my guild...do NOT clone it.\n");
}

reset()
{
    move_object(this_object(), DEST);
}

/*.................................LEVEL #1.............................*/
info()
{
    write("Type 'shardak' plus the screen you want to see.\n" +
	  "shardak1 -> Level 1 - 2\n" +
	  "shardak2 -> Level 3 - 4\n" +
	  "shardak3 -> Level 5 - 6\n" +
	  "shardak4 -> Level 7 - 8\n" +
	  "shardak5 -> Level 8 - 10\n");
    return 1;
}

shardak1()
{
    write("\n");
    write("	SPELL			FUNCTION			COST\n");
    write("___________________________________________________________________________\n");
    write("\t\t\t\tLEVEL 1\n\n");
    write("gt			Guild tell to members			  --\n");
    write("ge			Guild emote to members			  --\n");
    write("gw\t\t\tSee guild members on\t\t\t  --\n");
    write("gts\t\t\tGuild tell silence\t\t\t  --\n");
    write("-------------------------------------------------------------------------------\n");
    return 1;
}

angel_emote(str)
{
    int             i;
    object          people, sex;

    if (!str) {
	write("Guild emote what?\n");
	return 1;
    }
    people = users();
    for (i = 0; i < sizeof(people); i++) {
	sex = (present("shardak_mark", people[i]));
	if (sex && sex->query_muffled() < 1) {
	    tell_object(people[i], "\n[]: " + capitalize(this_player()->query_real_name()) + " " + str + "\n");
	}
    }
    return 1;
}

angel_tell(str)
{
    object          ob, guild, angel;
    int             i;
    string          me;

    me = this_player();
    angel = this_object();
    if (!str) {
	Write("Tell blood brothers what?\n");
	return 1;
    }
    ob = users();
    for (i = 0; i < sizeof(ob); i++) {
	guild = present("shardak_mark", ob[i]);
	if (guild && guild->query_muffled() < 1) {
	    tell_object(ob[i], "[" + me->query_name() + "]: " + str + "\n");
	}
    }
    return 1;
}

angel_who()
{
    object          list, guild;
    int             i, level;
    string          muffles;

    list = users();
    write("\n");
    write("________________________________________________________________________________\n");
    write("NAME:\t\tGUILD CLASS:\tRANK:\tMUFFLED: LOCATION:\n");
    write("________________________________________________________________________________\n");
    for (i = 0; i < sizeof(list); i++) {
	guild = present("shardak_mark", list[i]);
	if (guild) {
	    write(capitalize(list[i]->query_real_name()));
	    if (strlen(list[i]->query_real_name()) > 7)
		write("\t");
	    else
		write("\t\t");
	    if (guild->query_guild_class() == 0)
		write("None\t\t");
	    if (guild->query_guild_class() == 1)
		write("Goro\t\t");
	    if (guild->query_guild_class() == 2)
		write("Sorcerer\t");
	    if (guild->query_guild_class() == 3)
		write("Fighter\t\t");
	    write(list[i]->query_guild_rank() + "\t");
	    if (guild->query_muffled() > 0)
		write("Yes \t");
	    else
		write("No \t");
	    if (!environment(list[i]))
		write("Logging in");
	    else
		write(environment(list[i])->short ());

	    write("\n");
	}
    }
    write("________________________________________________________________________________\n");
    return 1;
}

clarknm()
{
    int             color_flag;

    color_flag = (present("shardak_mark", this_player())->query_color_flag());
    if (uhp < umhp / 4 && color_flag == 1) {
	tell_object(user, RED + MONITOR);
    }
    if (uhp < umhp / 2 && uhp >= umhp / 4 && color_flag == 1) {
	tell_object(user, BOLD + YEL + MONITOR);
    }
    if (uhp >= umhp / 2 && uhp < umhp - 50 && color_flag == 1) {
	tell_object(user, GRE + MONITOR);
    }
    if (uhp >= umhp - 50 && color_flag == 1) {
	tell_object(user, CYA + MONITOR);
    }
    if (color_flag == 0) {
	tell_object(user, MONITOR);
    }
    if (!att) {
	tell_object(user, NOSTYLE + "\n");
	return 1;
    }
    if (att) {
	tell_object(user, "[ATT: " + ((hp * 100) / mhp) + "%]" + NOSTYLE + "\n");
	return 1;
    }
}

dagger(str)
{
    int             dmg;
    object          ob, obj;

    dmg = (random(60) + 5);
    if (!str && !att) {
	write("Who do you want to throw a dagger at?\n");
	return 1;
    }
    if (!str && att) {
	str = att->query_real_name();
    }
    ob = present(str, environment(this_player()));
    if (!ob) {
	write(capitalize(str) + "is not here.\n");
	return 1;
    }
    if (find_player(str)) {
	write("Shardak does not allow you to use your powers against players.\n");
	return 1;
    }
    if (!living(ob)) {
	write("Only a foolish warrior would try to kill something that is not alive.\n");
	return 1;
    }
    if (usp < 10) {
	write("You do not have enough spell points to sacrifice!\n");
	return 1;
    }
    write("Your magical dagger stabs " + ob->query_real_name() + " in the chest.\n");
    say(capname + " stabs " + capitalize(ob->query_real_name()) + " in the chest with a magical dagger.\n");
    this_player()->spell_object(ob, "dagger", dmg, 0);
    this_player()->add_spell_point(-10);
    if (ob && !ob->query_attack()) {
	ob->attacked_by(this_player());
    }
    return 1;
}

score()
{
    int             ex_lv;
    int             intox_level;
    string          tmp;
    int             tmpp;

    ex_lv = this_player()->query_extra_level();
    if (this_player()->query_ghost() > 0) {
	write("You are in an immaterial state with no scores.\n");
	return 1;
    }
    write("\n");
    write("[------------------------------------------------------------------------------]\n");
    write(this_player()->short () + "\n");
    write("Level: " + this_player()->query_level());
    if (!ex_lv)
	write("\n");
    if (ex_lv)
	write("\t\t\tExtra Level: " + ex_lv + "\n");
    write("Coins: " + this_player()->query_money() + "          \t\tExperience: " + this_player()->query_exp() + "\n");
    write("Hit points: " + uhp + "/" + umhp + "     ");
    write("\t");
    write("Spell points: " + usp + "/" + umsp + "\n");
    write("Quest points: " + this_player()->query_quest_point() + "\n");
    this_player()->show_age();
    write("\n");
    write("Guild Rank: " + this_player()->query_guild_rank() + "\n");
    write("Guild Exp: " + this_player()->query_guild_exp() + "\n");
    if (guildobj->query_guild_class() == 1)
	write("Guild Class: Goro\n");
    if (guildobj->query_guild_class() == 2)
	write("Guild Class: Sorcerer\n");
    if (guildobj->query_guild_class() == 3)
	write("Guild Class: Fighter\n");
    if (guildobj->query_color_flag() == 1)
	write("Guild Color: ON\n");
    if (guildobj->query_color_flag() == 0)
	write("Guild Color: OFF\n");
    write("\n");
    if (this_player()->query_pregnancy()) {
	tmpp = this_player()->show_age() - this_player()->query_pregnancy();
	write("You are Pregnant (" + tmpp + " / 16200)\n");
    }
    if (this_player()->query_hunted() && call_other(this_player()->query_hunted(), "query_name"))
	write("You are hunted by " + call_other(this_player()->query_hunted(), "query_name") + ".\n");
    if (this_player()->query_intoxination()) {
	intox_level = (this_player()->query_level() + 4) / this_player()->query_intoxination();
	if (intox_level == 0)
	    write("You are in a drunken stupor.\n");
	else if (intox_level == 1)
	    write("You are roaring drunk.\n");
	else if (intox_level == 2)
	    write("You are somewhat drunk.\n");
	else if (intox_level == 3)
	    write("You are quite tipsy.\n");
	else
	    write("You are slightly tipsy.\n");
    }
    if (this_player()->query_stuffed() || this_player()->query_soaked()) {
	tmp = "You are ";

	if (this_player()->query_stuffed()) {
	    tmp += "satiated";

	    if (this_player()->query_soaked())
		tmp += " and ";
	    else
		tmp += ".\n";
	}
	if (this_player()->query_soaked())
	    tmp += "not thirsty.\n";

	write(tmp);
    }
    write("[------------------------------------------------------------------------------]\n");
    write("\n");
    return 1;
}

color()
{
    int             cl;

    if (guildobj->query_color_flag() == 0) {
	cl = 1;
	guildobj->set_color(cl);
	write("Guild Color is now ON.\n");
	return 1;
    }
    if (guildobj->query_color_flag() == 1) {
	cl = 0;
	guildobj->set_color(cl);
	write("Guild Color now set to OFF.\n");
	return 1;
    }
}

angel_tell_silence()
{
    int             mf;

    if (guildobj->query_muffled() == 0) {
	mf = 1;
	guildobj->set_muffled(mf);
	write("You will no longer hear guild tells.\n");
	return 1;
    }
    if (guildobj->query_muffled() == 1) {
	mf = 0;
	guildobj->set_muffled(mf);
	write("You will now hear guild tells.\n");
	return 1;
    }
}

darken()
{
    object          scar;

    write("You darken your mark of shardak with a knife.\n");
    destruct(present("shardak_mark", this_player()));
    scar = clone_object("players/dragnar/guild/mark");
    move_object(scar, this_player());
    return 1;
}

others()
{
    int             i;
    object          list;

    list = users();
    write("\n");
    write("   Name:\tLevel:\tGuild:\tGender:\tLocation:\n");
    write("[------------------------------------------------------------------------------]\n");
    for (i = 1; i < sizeof(list); i++) {
	if (this_player()->query_level() > list[i]->query_invis()) {
	    if (i < 10)
		write(" " + i + ". ");
	    if (i > 9)
		write("" + i + ". ");
	    write(capitalize(list[i]->query_real_name()));
	    if (strlen(list[i]->query_real_name()) > 3 && i < 10)
		write("\t");
	    if (strlen(list[i]->query_real_name()) < 4 && i < 10)
		write("\t\t");
	    if (strlen(list[i]->query_real_name()) > 3 && i > 9)
		write("\t");
	    if (strlen(list[i]->query_real_name()) < 4 && i > 9)
		write("\t\t");
	    if (list[i]->query_pl_k())
		write(list[i]->query_level() + "*\t");
	    else
		write(list[i]->query_level() + "\t");
	    if (!list[i]->query_guild_name())
		write("None\t");
	    else
		write(list[i]->query_guild_name() + "\t");
	    if (list[i]->query_gender() == "male")
		write("   M\t");
	    if (list[i]->query_gender() == "female")
		write("   F\t");
	    if (list[i]->query_gender() == "creature")
		write("   C\t");
	    if (!environment(list[i]))
		write("Logging In");
	    else
		write(environment(list[i])->short ());
	    write("\n");
	}
    }
    write("[------------------------------------------------------------------------------]\n");
    return 1;
}

corpse_heal()
{
    object          corpse;

    corpse = present("corpse", environment(user));
    if (!corpse) {
	write("There is no corpse here to sacrifice.\n");
	return 1;
    }
    user->heal_self(corpse->heal_value());
    destruct(corpse);
    write("You whisper some words and the corpse bursts into flames.\n");
    say(capname + " whispers some words and the corpse bursts into flames.\n");
    return 1;
}

shield(str)
{
    object          shieldmax;
    int             cost, AC, amount, t_pac;

    if (!str) {
	write("How strong do you want your shield to be? (1-10)\n");
	return 1;
    }
    sscanf(str, "%d", amount);
    if (amount < 1 || amount > 10) {
	write("You must specify a number between 1 - 10.\n");
	return 1;
    }
    t_pac = this_player()->query_ac();
    if (t_pac > 9) {
	write("You already have sufficiant armor.\n");
	return 1;
    }
    if ((t_pac + amount) > 9) {
	amount = (10 - t_pac);
    }
    cost = (amount * 20);
    AC = amount;
    if (usp < cost) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1;
    }
    shieldmax = clone_object("/players/dragnar/guild/items/shield.c");
    move_object(shieldmax, user);
    shieldmax->set_class(AC);
    shieldmax->set_rank(RANK);
    write("A cloud of darkness surrounds you.\n");
    say("A cloud of darkness suddenly surrounds " + capname + ".\n");
    this_player()->add_spell_point(-cost);
    this_player()->set_ac(t_pac + AC);
    return 1;
}

scan(str)
{
    object          ob;

    if (!str) {
	write("Who do you want to scan?\n");
	return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob) {
	write(capitalize(str) + " is not here.\n");
	return 1;
    }
    if (!find_living(str)) {
	write("Scan is useless on things that are not alive.\n");
	return 1;
    }
    if (usp < 10) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1;
    }
    write("You close your eyes and concentrate on " + capitalize(str) + ":\n");
    if (umhp > ob->query_mhp()) {
	write("HP: You are the stronger warrior.\n");
    }
    if (umhp == ob->query_mhp()) {
	write("HP: You are equal warriors.\n");
    }
    if (umhp < ob->query_mhp()) {
	write("HP: You are the weaker warrior.\n");
    }
    if (user->query_ac() > ob->query_ac()) {
	write("AC: You are better protected.\n");
    }
    if (user->query_ac() < ob->query_ac()) {
	write("AC: You are less protected.\n");
    }
    if (user->query_ac() == ob->query_ac()) {
	write("AC: You are equally protected.\n");
    }
    if (user->query_wc() > ob->query_wc()) {
	write("WC: You have the advantage.\n");
    }
    if (user->query_wc() < ob->query_wc()) {
	write("WC: You are at a disadvantage.\n");
    }
    if (user->query_wc() == ob->query_wc()) {
	write("WC: You have equal weapons.\n");
    }
    user->add_spell_point(-10);
    say(capname + " closes " + user->query_possessive() + " eyes and concentrates intently on " + capitalize(str) + ".\n");
    return 1;
}

/*.................................LEVEL #2...........................*/
tell(str)
{
    object          play1;

    if (!str) {
	write("Tell who what?\n");
	return 1;
    }
    if (sscanf(str, "%s %s", player1, tell_msg)) {
	play1 = find_player(player1);
	if (!play1) {
	    ppl_list = str;
	    tell2();
	    return 1;
	}
	tell_object(play1, capname + " tells you: " + tell_msg + "\n");
	write("You tell " + player1 + ": " + tell_msg + "\n");
	return 1;
    }
}

tell2()
{
    if (!sscanf(ppl_list, "%s,%s %s", player1, player2, tell_msg)) {
	write("Invalid name given.\n");
	return 1;
    }
    if (sscanf(ppl_list, "%s,%s %s", player1, player2, tell_msg)) {
	play1 = find_player(player1);
	play2 = find_player(player2);
	if (!play2) {
	    tell3();
	    return 1;
	}
	if (play1) {
	    tell_object(play1, capname + " tells " + player1 + "," + player2 + ": " + tell_msg + " \n");
	}
	if (play2) {
	    tell_object(play2, capname + " tells " + player1 + "," + player2 + ": " + tell_msg + "\n");
	}
	write("You tell " + player1 + "," + player2 + ": " + tell_msg + "\n");
	if (!play1) {
	    write(capitalize(player1) + " is not logged on.\n");
	}
	return 1;
    }
}

tell3()
{
    string          player3;
    object          play3;

    if (!sscanf(ppl_list, "%s,%s,%s %s", player1, player2, player2, tell_msg) && !player3) {
	if (!play1 && !play2) {
	    write("Neither one of them are loggeg on.\n");
	    return 1;
	}
	tell_object(play1, capname + " tells you: " + tell_msg + "\n");
	write(capitalize(player2) + " is not logged on.\n");
	return 1;
    }
    if (sscanf(ppl_list, "%s,%s,%s %s", player1, player2, player3, tell_msg)) {
	play1 = find_player(player1);
	if (player2) {
	    play2 = find_player(player2);
	}
	if (player3) {
	    play3 = find_player(player3);
	}
	if (!play1 && !play2 && !play3) {
	    write("They are not logged on.\n");
	    return 1;
	}
	if (play1) {
	    tell_object(play1, capname + " tells " + player1 + "," + player2 + "," + player3 + ": " + tell_msg + "\n");
	}
	if (play2) {
	    tell_object(play2, capname + " tells " + player1 + "," + player2 + "," + player3 + ": " + tell_msg + "\n");
	}
	if (play3) {
	    tell_object(play3, capname + " tells " + player1 + "," + player2 + "," + player3 + ": " + tell_msg + "\n");
	}
	write("You tell " + player1 + "," + player2 + "," + player3 + ": " + tell_msg + "\n");
	if (!play1) {
	    write(capitalize(player1) + " is not logged on.\n");
	}
	if (!play2) {
	    write(capitalize(player2) + " is not logged on.\n");
	}
	if (!play3) {
	    write(capitalize(player3) + " is not logged on.\n");
	}
	return 1;
    }
}

track(str)
{
    int             fl;
    object          tw;

    if (!str && guildobj->query_follow() == 0) {
	write("Who do you wish to begin tracking?\n");
	return 1;
    }
    if (!str && guildobj->query_follow() == 1) {
	write("You are no longer tracking anyone.\n");
	fl = 0;
	guildobj->set_follow(fl);
	return 1;
    }
    if (!present(str, environment(user))) {
	write(capitalize(str) + " is not here.\n");
	return 1;
    }
    if (!find_living(str)) {
	write("You can't track something that is not alive.\n");
	return 1;
    }
    if (find_living(str)->query_level() > 100000) {
	write("You can not track a wizard.\n");
	return 1;
    }
    if (usp < 40) {
	write("You do not have enough spell points to sacrifice!\n");
	return 1;
    }
    tw = find_living(str);
    fl = 1;
    user->add_spell_point(-40);
    guildobj->set_trackwho(tw);
    guildobj->set_follow(fl);
    write("You are now set to track " + capitalize(str) + ".\n");
    return 1;
}

light()
{
    object          lantern;

    if (usp < 5) {
	write("You don't have enough spell points to sacrifice.\n");
	return 1;
    }
    guildobj->set_light_on();
    write("You raise your hands to the sky and the room is blasted with light.\n");
    say("" + capname + " raises his hands to the sky and you are blinded by light.\n");
    user->add_spell_point(-5);
    return 1;
}

equil()
{
    int             amount;

    amount = (usp + uhp) / 2;
    if (uhp < amount) {
	this_player()->heal_self(amount - uhp);
	this_player()->add_spell_point(-(usp - amount));
	write("You use some of your magic to become stronger.\n");
	return 1;
    }
    if (uhp > amount) {
	this_player()->heal_self(-(uhp - amount));
	this_player()->add_spell_point(amount - usp);
	write("You use some of your strength to increase your magic.\n");
	return 1;
    }
    if (uhp == amount) {
	write("Your magic and strength are already equil.\n");
	return 1;
    }
}

toggle(str)
{
    int             amount, amount2, TSPS;
    string          what, thisp;

    if (!str || sscanf(str, "%d %s", amount, what) != 2) {
	write("Usage Example: toggle 100 hps\n");
	return 1;
    }
    if (!amount) {
	write("How much to you want to toggle?\n");
	return 1;
    }
    if (!what) {
	write("Do you want to toggle 'hps' or 'sps'?\n");
	return 1;
    }
    if (what != "sps" && what != "hps") {
	write("You can only toggle 'hps' or 'sps'.\n");
	return 1;
    }
    if (amount < 1) {
	write("Shardak forbids you to dishonor him by cheating.\n");
	return 1;
    }
    if (what == "sps") {
	thisp = this_player()->query_sp();
	TSPS = usp;
    }
    if (what == "hps") {
	thisp = this_player()->query_hp();
    }
    if (amount > thisp) {
	write("You don't have enough " + what + " to toggle that much.\n");
	return 1;
    }
    if (what == "sps") {
	this_player()->heal_self(amount);
	if (usp == umsp) {
	    amount2 = ((umsp - TSPS) + amount);
	    this_player()->add_spell_point(-amount2);
	    write("You toggle " + amount + " sps to make yorself stronger.\n");
	    return 1;
	}
	if (usp < umsp) {
	    this_player()->add_spell_point(-(amount * 2));
	}
	write("You toggle " + amount + " " + what + " to make yourself stronger.\n");
	return 1;
    }
    if (what == "hps") {
	this_player()->heal_self(-amount);
	this_player()->add_spell_point(amount * 2);
	write("You toggle " + amount + " " + what + " to increase your magic.\n");
	return 1;
    }
}

title(str)
{
    string          plus;

    if (!str) {
	write("What do you want to set your to?\n");
	return 1;
    }
    if (RANK < 4) {
	plus = "(Shardak Initiate: " + LEV + ")";
    }
    if (RANK > 4 && RANK < 7) {
	plus = "(Shardak Player: " + LEV + ")";
    }
    if (RANK > 7) {
	plus = "(Shardak Assassin: " + LEV + ")";
    }
    this_player()->set_title(str + " " + plus + "");
    write("Your title for the Shardak guild has been changed.\n");
    return 1;
}

do_sell(str)
{
    int             value, weight;
    object          ob;

    if (!str) {
	write("What do you want to junk?\n");
	return 1;
    }
    ob = present(str, this_player());
    if (!ob) {
	write("You do not have that object.\n");
	return 1;
    }
    if (usp < 10) {
	write("You don't have enough spell points to sacrifice.\n");
	return 1;
    }
    value = ob->query_value();
    if (!value) {
	write(ob->short () + " has no value.\n");
	return 1;
    }
    if (environment(ob) == this_player()) {
	if (call_other(ob, "drop", 0)) {
	    write("You can't junk that!\n");
	    return 1;
	}
	weight = call_other(ob, "query_weight", 0);
	call_other(this_player(), "add_weight", -weight);
    }
    if (value > 1000) {
	value = (random(200) + 1000);
    }
    this_player()->add_spell_point(-10);
    write("The ground opens and the " + ob->short () + " is sucked into it.\n" +
	  "When the ground closes " + value + " gold coins appear.\n" +
	  "You bend down and pick them up.\n");
    say("The gound opens and the " + ob->short () + " is sucked into it.\n" +
	"When the ground closes a pile of gold coins appear.\n" +
	"" + capname + " bends over and picks them up.\n");
    call_other(this_player(), "add_money", value);
    destruct(ob);
    return 1;
}

/*..........................LEVEL #3..................................*/
calm()
{
    object          ob;

    ob = first_inventory(environment(this_player()));
    while (ob) {
	if (living(ob)) {
	    if (ob->query_attack()) {
		ob->query_attack()->stop_fight();
		ob->stop_fight();
	    }
	}
	ob = next_inventory(ob);
	ob;
    }
    write("You command fighting to stop.\n");
    return 1;
}

slayer(str)
{
    object          slayer;
    int             AMT;

    if (!str) {
	write("How strong to you wish your slayer to be?\n");
	return 1;
    }
    if (str != "ready" || str != "unready") {
	sscanf(str, "%d", AMT);
	if (usp < AMT) {
	    write("You do not have enough spell points to sacrifice.\n");
	    return 1;
	}
	if (present("slayer", this_player())) {
	    write("Shardak does not allow you to have more than one Slayer Sword.\n");
	    return 1;
	}
	slayer = clone_object("/players/dragnar/guild/items/slayer.c");
	move_object(slayer, this_player());
	slayer->set_amt(AMT);
	write("The land parts and a Slayer Sword surges from the ground into your hands.\n");
	say("The land parts nad a Slayer Sword surges from the ground into " + capname + "'s hands.\n");
	this_player()->add_spell_point(-AMT);
	return 1;
    }
}

heal(str)
{
    int             amount;
    string          who;

    if (!str || sscanf(str, "%s %d", who, amount) != 2) {
	write("To heal someone: 'heal <who> <amount>'\n");
	return 1;
    }
    if (amount < 1) {
	write("Shardak forbids you to dishonor him by cheating.\n");
	return 1;
    }
    if (!present(who, environment(user))) {
	write(capitalize(who) + " is not here.\n");
	return 1;
    }
    if (amount > usp) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1;
    }
    if (!find_player(who)) {
	write("You can not heal something that isn't a player.\n");
	return 1;
    }
    find_player(who)->heal_self(amount / 2);
    user->add_spell_point(-amount);
    write("You touch " + capitalize(who) + " and heal " + find_player(who)->query_possessive() + " wounds.\n");
    say(capname + " touches " + capitalize(who) + " and heals " + find_player(who)->query_possessive() + " wounds.\n");
    return 1;
}

send(str)
{
    int             amount;
    string          who;

    if (!str || sscanf(str, "%s %d", who, amount) != 2) {
	write("To use send: 'send <who> <amount>'\n");
	return 1;
    }
    if (!find_player(who)) {
	write(capitalize(who) + " is not on.\n");
	return 1;
    }
    if (amount < 1) {
	write("Shardak forbids you to dishonor him by cheating.\n");
	return 1;
    }
    if (amount > usp) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1;
    }
    find_player(who)->add_spell_point(amount);
    this_player()->add_spell_point(-amount);
    write("You send " + amount + " hit points to " + capitalize(who) + ".\n" +
	  "You stumble from the loss of energy.\n");
    tell_object(find_player(who), capname + " uses his Shardak energy to send you " + amount + " spell points.\n");
    return 1;
}

waste_msg(str)
{
    int             msg;

    if (!str) {
	write("What do you want your waste message to be?\n");
	return 1;
    }
    sscanf(str, "%s", msg);
    if (!msg) {
	write("Error...\n");
	return 1;
    }
    guildobj->set_wstmsg(msg);
    write("When you use waste the room will now see:\n" +
	  "" + capname + " " + guildobj->query_wstmsg() + "\n");
    guildobj->save_me();
    return 1;
}

waste(str)
{
    int             dmg;
    object          ob, obj;
    string          w_msg;

    w_msg = guildobj->query_wstmsg();
    dmg = (random(20) + 20);
    if (!w_msg) {
	write("You must set your waste message first, 'waste_msg <message>'.\n");
	return 1;
    }
    if (!str && !att) {
	write("Who do you want to waste?\n");
	return 1;
    }
    if (!str && att) {
	str = att->query_real_name();
    }
    ob = present(str, environment(this_player()));
    if (!ob) {
	write(capitalize(str) + " is not here.\n");
	return 1;
    }
    if (find_player(str)) {
	write("Shardak does not allow you to use your powers against players.\n");
	return 1;
    }
    if (!living(ob)) {
	write("Only a foolish warrior would try to kill something that is not alive.\n");
	return 1;
    }
    if (usp < 30) {
	write("You do not have enough spell points to sacrifice!\n");
	return 1;
    }
    write(capname + " " + w_msg + "\n");
    say(capname + " " + w_msg + "\n");
    this_player()->spell_object(ob, "waste", dmg, 0);
    if (ob && !ob->query_attack()) {
	ob->attacked_by(this_player());
    }
    this_player()->add_spell_point(-30);
    return 1;
}

/*..........................LEVEL #4....................................*/
summon()
{
    object          dragon, ob;
    string          idstr, ownstr;

    if (usp < 100) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1;
    }
    if (find_living(this_player()->query_real_name() + "dragon")) {
	write("You already have a dragon.\n");
	return 1;
    }
    dragon = clone_object("/players/dragnar/guild/pet.c");
    idstr = this_player()->query_real_name() + "dragon";
    ownstr = this_player()->query_real_name();
    move_object(dragon, environment(this_player()));
    dragon->set_owner(ownstr);
    dragon->set_variable(idstr);
    write("You summon the spirits of past warriors and they form into a dragon.\n");
    say(capname + " forms a dragon from the spirits of past warriors.\n");
    return 1;
}

dragon()
{
    if (!find_living(this_player()->query_real_name() + "dragon")) {
	write("You do not have a dragon.\n");
	return 1;
    }
    move_object(find_living(this_player()->query_real_name() + "dragon"), environment(this_player()));
    write("Your dragon swoops down from the sky.\n");
    say(capname + "'s dragon swoops down from the sky.\n");
    return 1;
}

morph(str)
{
    int             cs;

    if (!str) {
	write("What class do you want to morph into?\n");
	return 1;
    }
    if (str == "goro") {
	write("You grow into a Goro.\n");
	cs = 1;
	guildobj->set_guild_class(cs);
	return 1;
    }
    if (str == "sorcerer") {
	write("You turn into a Sorcerer.\n");
	cs = 2;
	guildobj->set_guild_class(cs);
	return 1;
    }
    if (str == "fighter") {
	write("You form into a fighter.\n");
	cs = 3;
	guildobj->set_guild_class(cs);
	return 1;
    }
    write("That is not an acceptable guild class.\n");
    return 1;
}

/*..........................LEVEL #5...................................*/
drag(str)
{
    int             DN;
    object          bringobj, who;
    string          bgr;

    if (!str && guildobj->query_drag() == 0) {
	write("Who do you want to drag?\n");
	return 1;
    }
    if (!str && guildobj->query_drag() == 1) {
	write("You are no longer dragging anyone.\n");
	DN = 0;
	guildobj->set_drag(DN);
	return 1;
    }
    who = find_player(str);
    if (!present(str, environment(this_player()))) {
	write(capitalize(str) + " is not here.\n");
	return 1;
    }
    if (!present(find_player(str), environment(this_player()))) {
	write(capitalize(str) + " is not here.\n");
	return 1;
    }
    if (usp < 40) {
	write("You do not have enough spell points to sacrifice.\n");
	return 1;
    }
    bgr = this_player()->query_real_name();
    write("Attempting to drag " + str + ", waiting for acceptance.\n");
    tell_object(who, capname + " wishes to drag you.  This will allow you to follow them.\n" +
	     "Type 'accept' to start following, or 'decline' to cancel.\n");
    bringobj = clone_object("/players/dragnar/guild/items/bringob");
    move_object(bringobj, who);
    bringobj->set_bringer(bgr);
    return 1;
}

wand(str)
{
    int             amount, COIN;
    object          wand;

    if (!str) {
	write("How many gold coins to you want to use?\n");
	return 1;
    }
    if (!sscanf(str, "%d", amount)) {
	write("You must specify the number of gold coins you want to use.\n");
	return 1;
    }
    if (amount < 1) {
	write("Shardak forbids you to dishonor him by cheating.\n");
	return 1;
    }
    if (user->query_money() < amount) {
	write("You do not have enough gold coins to sacrifice.\n");
	return 1;
    }
    COIN = (amount / 10);
    wand = clone_object("/players/dragnar/guild/items/wand.c");
    move_object(wand, this_player());
    wand->set_amt(COIN);
    write("You summon a Wand of Acid from the depths of hell.\n");
    say(capname + " summons a Wand of Acid from the depths of hell.\n" +
	"You cringe in fear.\n");
    this_player()->add_money(-amount);
    return 1;
}
