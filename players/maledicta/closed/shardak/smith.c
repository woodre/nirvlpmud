/* 
 * Shardak guild - (tm) Dragnar/John
 * Smith is (c) Balowski/Rasmus, March 19th 1995.
 * Last change: Mar 19th '95
 * One day I must create a generic monster suiting my purposes.
 */
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit "/obj/monster";

string          text;           /* reply from catch_tell */
object          receiver;       /* talk to this object */
mapping         cash;
mapping         scales;
mapping         helms;

reset(x)
{
    if(x) return;
    ::reset(x);
    set_race("human");
    set_name("Smith");
    set_gender("male");
    set_alias("smith");
    set_alt_name("huge smith");
    set_short("A huge smith");
    set_long("\
The smith is big and burly. Even if he stands a good deal less than\n\
six foot tall, he looks like he could beat just anybody bare-handed.\n\
His face and arms are sooted from hours of work in the smithy. He is\n\
wearing a leather apron over his simple clothes.\n");
    set_level(15);
    set_ac(10);
    set_wc(20);
    set_hp(600);
    set_al(-100);
    set_ghost(1);
    set_chat_chance(6);
    scales = ({ });
    cash = ({ });
    cash = ([ ]);
    scales = ([ ]);
    helms = ([ ]);
    load_chats(({
"The smith walks over to the bellows and pumps air into the furnace.\n",
"The smith walks over to the bellows and pumps air into the furnace.\n\
Sparks from the glowing coals jump out onto the rough floor.\n",
"The smith fetches an old rusty weapon from one of the racks and puts it\n\
into the furnace.\n",
"There is a 'Clang. Clang-clang' as the smith's hammer hits the anvil.\n",
    }));
}

void DoTell()
{
    if (!text || !receiver) { text = 0; return;}
    tell_object(receiver, text);
    text = receiver = 0;
}

void long(string str)
{
    ::long(str);
    if (!text) {
	receiver = this_player();
	text = "\
The smith rumbles: This is no exhibition. What is your errand here?\n";
	call_out("DoTell", 2);
    }
}

void catch_tell(string str)
{
    string      who, what;
    int         i;
    object      mark;

    if (!(str && this_player() && (mark = present(GUILD_ID, this_player()))))
	return;

    if (!text && (sscanf(str, "%s says: %s\n", who, what) == 2 ||
		  sscanf(str, "%s asks: %s\n", who, what) == 2 ||
		  sscanf(str, "%s tells you: %s\n", who, what) == 2)) {
	what = lower_case(what);

	if (sscanf(what, "%strial", who)) {
	    if (mark->query_solved(AVENGER_TASK)) {
		text = "\
The smith rumbles, \"Your next trial awaits you in the lower guild caverns.\"\n";
	    }
	    else text = read_file(ABSPATH + "smith_task");
	}
	else return;

	receiver = this_player();
	call_out("DoTell", 2);
    }
}

/*
 * A little bit of task code..
 */

/*
 * Here we go again.. Player gives me something
 * There are evil objects with weight < 1 that caused me trouble
 * if an item is dropped the return value from add_weight is not used
 */
add_weight(w)
{
#if 0
    if (first_inventory(this_object()))
	return 0;       /* refuse more than one item */
    else
#endif
	call_out("received", 1, this_player());   /* proceed */
    return ::add_weight(w);
}

/*
 * See if it is the right weapon
 */
void
received(object from)
{
    object      mark;           /* guild mark */
    int    scale_num;
    int    flag;
    string fname;
    int    gold;
    object      item;           /* item received */

    item = first_inventory(this_object());
    if (!item)
	return;

    if (from)
	mark = present(GUILD_ID, from);
    if (!mark) {/* not something I expect to happen */
	tell_room(environment(), "The smith crumbles a piece of scrap.\n");
	destruct(item);
	return;
    }

    fname = (string)from->query_real_name();
    gold = cash[fname];
   if(item->id("shardak_dragon_scale"))
   {
     scales[fname] ++;
     scale_num = scales[fname];
     tell_object( from, "\
The smith says, \"Thank you.  You have given me " + scale_num + " " +
((scale_num > 1) ? "scales" : "scale") + ".\"\n");
    destruct(item);
    if(scale_num >= 2)
    {
      if(helms[fname])
      {
        tell_object(from, "\"I'll create a powerful helm for you.\"\n");
        RACKS->work_on_item("/players/maledicta/closed/shardak/armors/dragonhelm");
        helms[fname]--;
        scales[fname]-=2;
      }
      else
        tell_object(from, "\"I will forge a powerful helm if you give me one in\n\
exchange.\"\n");
    }
    if(scale_num >= 4)
    {
      if(gold >= 1500) {
        scales[fname]-=4;
        cash[fname]-=1500;
        tell_object(from, "\"A powerful suit of armor will be created for you.\"\n");
        RACKS->work_on_item("/players/maledicta/closed/shardak/armors/shard_armor");
     }
     else
       tell_object(from, "\
\"With " + (1500-gold) + " more gold coins, I will create a suit of armor\n\
for you.\"\n");
    }
     return;
   }
   if(item->is_armor() && ((int)item->armor_class() >= 2))
   {
     destruct(item);
     scale_num = scales[fname];
     if(scale_num >= 2)
     {
       tell_object(from, "\
The smith says, \"I'll create a powerful helmet for you!  Just\n\
give me a half-hour.\"\n");
        scales[fname]-=2;
        RACKS->work_on_item("/players/maledicta/closed/shardak/armors/dragonhelm");
     }
     else
       tell_object(from, "\
\"With two Red Dragon scales, I will create you a helmet.\"\n");
    return;
}
    /* hmm.. this section is rather messy */
    /* see if this is really a weapon */
    if (function_exists("weapon_class", item)) {

	/* there should be no doing this trial twice */
	if (mark->query_solved(AVENGER_TASK)) {
	    tell_object( from, "\
The smith says, \"You shouldn't keep coming with weapons to me, but\n\
since it is you I'll try and make something nice out of it.\"\n");
	    transfer(item, RACKS);
	    return;
	}

	/* haven't passed the trial yet, check weapon id */
	if (item->id("holy avenger")) {
	    tell_room( environment(), "\
The smith smiles as he realizes that he is holding the Holy Avenger.\n\
He says: Ah, I have been itching to get my nubbies on this lil beauty.\n");
	    tell_object( from, "\
And I am giving you pre-emption on the result. I better get working.\n");
	    tell_room( environment(), "\
The smith hurries back to the furnace.\n");

	    /* mark the weapon as belonging to 'from' */
	    item->set_info( from->query_real_name());
	    call_out( "solved", 1, from);
	}

	else {  /* wrong weapon */
	    tell_object( from, "\
The smith tells you: Oi, this is not the sword I asked for. I may\n\
be able to make a decent weapon out of it, but you need not wait\n\
around, 'cause I am a busy man and it will take some time to do.\n");
	    tell_room( environment(), "\
The smith walks over to the racks bulging with old iron and throws\n\
the weapon in between all the others.\n");
	}
	transfer(item, RACKS);
    }
    else        /* not a weapon */
    if (function_exists("armor_class", item)) {
	tell_room(environment(), "\
The smith walks over and throws something into a heap of rusty armours.\n");
	transfer(item, RACKS);
    }
    else {      /* neither weapon nor armour */
	tell_room( environment(), "\
The smith frowns at the item he received and throws it into the furnace.\n");
	destruct(item);
    }
}

void
solved(object from)
{
    object      mark;

    if (from)
	mark = present(GUILD_ID, from);

    if (mark) {
	say( "\
The smith staggers to a halt. He comes back and whispers something\n\
to " + from->query_name() + ".\n", from);

	tell_object( from, "\
The smith staggers to a halt and comes back to you.\n\
Preoccupied he says, \"I promised you a reward, didn't I?\"\n\
He whispers a formula into your ear, \"That will summon the slayer\n\
sword.  You must first have an earthly sword at the ready, however.\n\
All there is to it.\"  He chuckles as he returns to work.\n");

	mark->add_solved(AVENGER_TASK);
	mark->save_me();                /* save guild info, init() restores */
    }
}

add_money(x)
{
     object   c;
     ::add_money(x);
     if((c = this_player()) && present(OBJID, c))
       call_out("process_money", 1, ({ x, c }));
}

process_money(ob)
{
     object   c;
     string   cname;
     int      bux;

     if(!ob) return;
   
     bux=ob[0];
     c  =ob[1];
     if(!c) return;

     tell_object(c, "The smith nods at you.\n");

     cname=(string)c->query_real_name();
     cash[cname]+=bux;
     bux=cash[cname];

     if(bux >= 1500)
     {
       if(scales[cname] >= 4)
       {
         tell_object(c, "The smith says, \"I will now create you an armor of great power.\"\n");
         scales[cname] -= 4;
         cash[cname] -= 1500;
         RACKS->work_on_item("/players/maledicta/closed/shardak/armors/shard_armor");
       }
     }
}
