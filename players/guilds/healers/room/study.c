#include "../def.h"
#define XPCOST 7000
string own;
int locked, staf;
static string bk;
static int bkl;

id(str) { return str == "study" || str == "healerstudy"; }

short() { return capitalize(own) + "'s Private Study"; }

long() {
    write("You enter a small modest study.  A place of peace and serenity.\n"+
      "The hardwood floor softly glows with the reflected light of the fire\n"+
      "in the fireplace.  The bookcase against the wall is filled with books.\n"+
      "A desk sits near the window with a comfortable leather chair being used\n"+
      "as a deskchair. A small altar sits near the door you just entered.\n");
    if(own == tpn) write("You may 'invite' others in if they are in the hall.\n");
    write("The only obvious exit is: hall\n");
}

reset(arg) {
    object inv;
    int h,i;  
    if(arg) {
	inv = all_inventory(TO);
	h = 1;
	while(h && i < sizeof(inv)) {
	    if(query_ip_name(inv[i])) h = 0;
	    i++;
	}
	if(h) destruct(TO);
	return;
    }
    locked = 0;
    staf = 0;
    bk = ({"Chronicles","BloodQuest","Learnings","DreamBook","Visions","Grimoire"});
    bkl = ({4,2,4,4,2,6});
    set_light(2);
    own = "someone";
}

init() { 
    if(locked && tpn != own) {
	write("You find the door to "+short()+" locked.\n");
	move_object(tp,root+"room/hall.c");
	return 1; }
    if(tpn == own) {
     if((string)this_player()->query_guild_name() != "healer")
       {
       this_player()->set_guild_name("healer");
      move_object(clone_object("/"+root+"guildob.c"),tp);
       }
	if(!present("mythos_healer",tp)) move_object(clone_object(root+"guildob.c"),tp);
        if(present("mythos_healer",tp))
	if(present("mythos_healer",tp)->query_rec()) staf = 1;

	add_action("retrieve","retrieve");  
	add_action("lock","lock");
	add_action("unlock","unlock");
	add_action("invite","invite");
	add_action("repent","repent");
	add_action("rise","advance");
	add_action("rise","raise");
	add_action("list_quests","list");
	add_action("pick","pick");
    }
    add_action("hall","hall");
    add_action("pray","pray");
    add_action("look_at","look");
    add_action("look_at","l");
}

look_at(str) {
    if(str) {
	if(str == "at altar" || str == "altar") {
	    write("A small beautiful altar of white marble.\n"+
	      "Upon the altar, resting on a red silk fabric,\n"+
	      "lies a crystal orb");
	    if(!staf) write(" and a white oak staff.\nYou may pray at the altar.\n"); else write(".  You may pray\nat the altar.\n");
	    return 1; }
	if((str == "at staff" || str == "staff") && !staf) {
	    write("The staff is made of the stoutest white oak.\n"+
	      "As you gaze upon it you feel at peace.\n");
	    if(tpn == own) write("You will want to 'retrieve' this staff\nwhen you walk the world.\n");
	    return 1; }
	if(str == "at orb" || str == "orb") {
	    write("The orb gleams brightly in the reflected firelight.\n"+
	      "As you gaze within its hidden depths, you feel at peace.\n");
	    if(own == tpn) 
		write("You will want to 'advance' your levels, 'raise'\nyour attributes and 'list' quests here.\n");
                write("Use 'retrieve' to get your staff if you're new\n");
	    return 1; }
	if(str == "at bookcase" || str == "bookcase") {
	    write("Many books from various ages stand neatly in the bookcase.\n");
	    if(own == tpn) 
		write("You can 'pick' a book from the bookcase.\n");
	    return 1; }
    }
}

pray() {
    if(tp->query_ghost()) return tp->remove_ghost();
    write("You pray quietly.  You feel at peace\n");
    say(tp->query_name()+" prays at the altar.\n");
    return 1;
}

static lock() {
    locked = 1;
    write(">> CLACK <<\nYou lock the door.\n");
    say(">> CLACK <<\n"+tp->query_name()+" locks the door.\n");
    return 1; }

static unlock() {
    locked = 0;
    write("You unlock the door.\n");
    say(tp->query_name()+" unlocks the door.\n");
    return 1; }

static repent() {
    if(tl + tx > 4) {
	write("You have no need to repent.\n");
	return 1; }
    if(tp->query_exp() > 6000) {
	write("Go and advance your level!\n"); return 1; }
    write("You kneel before the altar and pray for forgiveness.\n");
    say(tp->query_name()+" kneels before the altar and prays.\n");
    tp->add_xp(10);
    return 1; }

static retrieve() {
    if(tl + tx < 5) {
	write("You are below the minimum level for a Healer.\nYou are a disgrace.\n\nRepent to gain back what was lost.\n");
	return 1; } 
    if(!present("mythos_healer",tp))
    {
     if(own == tpn)
     if((string)this_player()->query_guild_name() != "healer")
       this_player()->set_guild_name("healer");
      move_object(clone_object("/"+root+"guildob.c"),tp);
    }
    if(present("mythos_healer",tp)->query_rec()) {
	write("You already have your staff.\n");
	return 1; }
    present("mythos_healer",tp)->set_rec();
    write("You retrieve your staff from its place upon the altar.\n");
    write("hhelp give you the help files.\n");
    say(tp->query_name()+" takes a staff from the altar.\n");
    staf = 1;
    return 1; }

hall() {
    tp->move_player("hall#"+root+"room/hall.c");
    return 1; }

static rise(str) { 
    int sb, minexp;
    int current, new;
    string attrib, raise;
    minexp = sb = 0;                       
    if(!str) { 
        if(tx || tl==19)
            "/room/exlv_guild"->advance();
        else
            "/room/adv_guild"->advance();
    } else {
        if (str !="str" && str !="sta" && str !="wil" && str !="mag" && str !="pie" && str !="ste" && str !="luc" && str !="int" && str !="dex" && str !="cha")
	{
	    write ("Raise what?\n");
	    return 1;
	}
	if(tx) minexp = tp->query_exp() - call_other("room/exlv_guild", "get_next_exp",tx - 1);
	else minexp = tp->query_exp() - call_other("room/adv_guild","get_next_exp",tl - 1); 
	if(XPCOST > minexp) write("You need "+(XPCOST - minexp)+" more exp to raise an attrib.\n"); 
	else { 
	    if (str == "str") attrib = "strength";
	    if (str == "sta") attrib = "stamina";
	    if (str == "wil") attrib = "will_power";
	    if (str == "mag") attrib = "magic_aptitude";
	    if (str == "pie") attrib = "piety";
	    if (str == "ste") attrib = "stealth";
	    if (str == "luc") attrib = "luck";
	    if (str == "int") attrib = "intelligence";
            if (str == "dex") attrib = "dexterity";
            if (str == "cha") attrib = "charisma";
	    raise = "raise_" + attrib;
	    current = call_other(this_player(), "query_attrib", str);
	    new = current + 1;
	    if (current > 29) {
		write (attrib + " is at highest possible value.\n");
		return 1;
	    }
	    tp->add_xp(-XPCOST); 
	    call_other(this_player(), raise, 1);
	}
    }
    return 1; }

cost() {
    int next_exp, exper, cst;
    exper = tp->query_exp();
    cst = 0;
    if(tx || tl==19){
	next_exp = call_other("room/exlv_guild","get_next_exp",exper); 
	cst = call_other("room/exlv_guild","query_cost_for_extra_level",tx,exper);
    } else {
	next_exp = call_other("room/adv_guild","get_next_exp",exper); 
	cst = call_other("room/adv_guild","query_cost_for_level",tl,exper);
    }
    if (cst){ 
	if ((next_exp - exper) > next_exp/10 || (next_exp - exper) > 15000) {
	    write("You must be closer to the next level before buying experience.\n");
	    return 0;}
	if(tp->query_money() < cst) { write("You need "+cst+" coins to buy experience to advance.\n"); return 0; }
	tp->add_money(-cst); 
	tp->add_xp(next_exp - exper); 
    }
    return 1; }

list_quests(str) {
    call_other("room/exlv_guild","list_quests",str);
    return 1; }

static invite(str) {
    object who;
    string w1,w2,w3;
    if(!str) { write("Usage: invite <name of person in hall>\n"); return 1; }
    if(locked) { write("The door is locked!\n"); return 1; }
    if(!(who=find_player(str))) { write("That person is not in game.\n"); return 1; }
    if(sscanf(environment(who),"%sguilds/healers/room/hall%s",w1,w2) == 2) {
	tell_room(environment(who),who->query_name()+" is invited into one of the Healer's study.\n");
	move_object(who,TO);
	tell_room(TO,who->query_name()+" arrives.\n");
    } else write("That person is not in the hall.\n");
    return 1; }

pick(str) {
    int h;
    object book;
    if(!str) { write("List of books to pick:\n");
	for(h=0;h<sizeof(bk);h++) 
	    write("              "+bk[h]+"\n");
	write("\n");       
	return 1; }
    if(member_array(str,bk) == -1) { write("That is not a book you can pick!\n"); return 1; }
    book = clone_object("/"+root+"obj/book.c");
    book->set_title(str);
    book->set_last(bkl[member_array(str,bk)]);
    move_object(book,tp);
    write("You pick out a copy of "+book->short()+"\n");
    say(tp->query_name()+" takes a book from the bookcase.\n");
    return 1; }

set_ownn(str) { own = str; }

drop() { return 1; }
get() { return 0; }

realm() { return "NT"; } 

query_no_fight() { return 1; }

exit() { object mr; if(mr=present("mailread",tp)) destruct(mr); }
