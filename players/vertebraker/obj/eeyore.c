
#include <ansi.h>
#define OWNER find_player("stardream")

inherit "/obj/monster";

/* later implementation */
static int fed;
static int leaking;
static int whining;
static int bounced;
static int lost_tail;
static int silenced;

void eeyore_chat(string c)
{
	load_chat(query_name()+" says sadly, "+MAG+"..."+NORM+c+MAG+"... "+
		HIM+":(\n"+NORM);
}

void reset(int arg)
{
	int s;
	string *chats;
	::reset(arg);
	if(arg) return;
	set_name(BBLU+HIM+"Eeyore"+NORM);
	set_alias("donkey");
	set_alt_name("eeyore");
	set_short("A gloomy donkey named "+BBLU+HIM+"Eeyore"+NORM);
	set_long("\
A very gloomy, blue-gray donkey, Eeyore is stuffed with sawdust.\n\
Despite this, he is a very intelligent animal, although he keeps\n\
most of his knowledge to himself. That's why he is very quiet most\n\
of the time and a bit depressed.\n\n\
Eeyore's favorite food is thistles and he loves to be remembered\n\
on his birthday. He frequently loses his tail and often gets\n\
depressed over this. He also likes balloons.\n");
  set_level(5);
  set_hp(100);
  set_ac(3);
  set_wc(5);
  set_race("creature");
  chats=({
	  "you think you can depend on tails",
	  "you don't expect tails to go wrong",
	  "the last time i looked, it was right there",
	  "now when i look there, it's gone",
	  "it was always just behind me",
	  "i thought it was there, and it's gone",
	  "i assumed it was attached to me",
	  "maybe i need some glue",
	  "i'd hoped it was firmly stuck on",
	  "it used to trail right behind me",
	  "my little extra at the back.. is gone",
	  "birthdays are here today and gone tomorrow",
	  "sitting on thistles doesn't do them any good",
	  "i don't really like baths",
	  "i must move about more",
	  "i must come and go",
	  "if anyone asks, i can leave",
	  "i can drop out again. just let me know",
	  "i don't seem to have felt well in a long time",
	  "the others will be sorry if i'm cold",
	  "the others will be sorry if i'm hot",
	  "i'm only eeyore, so i don't count",
	  "help yourself",
	  "it's a little patch and it's mine. so it doesn't count",
	  "i have my friends. someone spoke to me only yesterday",
	  "good morning. if it is a good morning, which i doubt",
	  "nobody tells me",
	  "nobody keeps me informed",
	  "i make it seventeen days since friday since someone spoke to me",
	  "please don't bustle me",
	  "if you like cold and wet places, my place is home",
	  "i'm definitely an eeyore",
	  "the nicest thing about the rain is that it stops. eventually",
	  "accidents are funny. until you have them",
	  "somebody *bounced* me.",
	  "pathetic. that's what it is. pathetic",
	  "as i thought. no better from this side.",
	  "my friends gave me an empty honey pot and a broken balloon.",
	  "owl flew past and noticed me. he didn't say anything, but he noticed me",
	  "sing. enjoy yourself. some can",
	  "small applause is better than no applause, i suppose",
	  "when someone says \"how-do-you-do\", just say you didn't",
	  "i'm rarely welcome",
	  "it's not much of a tail, but i'm sort of attached to it",
	  "i'd look on the bright side if i could find it.",
	  "i'm not sad, i'm just not very happy",
	  "it will rain soon, you will see if it doesn't",
	});
	s=sizeof(chats);
	set_chat_chance(30);
	while(s--)
		eeyore_chat(chats[s]);
}

void long()
{
	::long();
	if(this_player()==OWNER)
		write("You can \"silence\" Eeyore to toggle his chats.\n");
}

void init()
{
	::init();
	if(this_player()==OWNER)
	{
		add_action("cmd_silence","silence");	
	}
}

void heart_beat()
{
	if(root())
	{
                destruct(this_object());
		return;
	}
	::heart_beat();
	if(OWNER && environment(OWNER) &&
	   environment(OWNER) != environment())
	{
		tell_room(environment(),
			query_name()+" sadly waddles out on all fours.\n");
		move_object(this_object(), environment(OWNER));
		tell_room(environment(),
			query_name()+" sadly waddles in on all fours.\n");
	}
}

int cmd_silence()
{
	if(silenced==0)
	{
		tell_room(environment(),
			query_name()+" nods mutely.\n");
	  silenced=1;
	  set_chat_chance(0);
	}
	else
	{
		tell_room(environment(),
			query_name()+" says: it's ok. i don't have much to say.\n");
	  silenced=0;
	  set_chat_chance(30);
	}
	return 1;
}
