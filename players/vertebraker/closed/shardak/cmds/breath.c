#include "/players/vertebraker/ansi.h"

/*
 * Dragon breath spell for Shardak guild.
 * Uses the dragon's spell points ("flame") to cast "breath"
 * By Dragnar, modified by Balowski
 * Changed by Verte, expanded messaging, updated to new Dmg types
 */
#pragma strict_types
#include "../std.h"
#include "../macros.h"
inherit CMD;

#define COST 40
#define DAMAGE 30 + random(40)

string *
get_msgs(string y, string z, string x)
{
    string a, b, c;

    switch(random(5))
    {
      case 0:
        a = "\
You stare at " + z + ", hate streaming from the line of energy\n\
between you and your Dragon.\n";
        b = y + " \
stares at " + z + ", eyes full of hate.\n";
        break;
      case 1:
        a = "\
Your eyes twinkle a deep crimson as you nod at " + z + ".\n";
        b = y + " nods at " + z + ".\n";
        break;
      case 2:
        a = "\
You let evil penetrate your thoughts and give license to " + z + "\n\
to wreak havoc.\n";
        b = y + "'s eyes roll back in " + possessive(this_player()) + " \
head.\n";
        break;
      case 3:
        a = "\
Post-apocalyptic thoughts dance through your mind...\n\
You let your companion release his anguish.\n";
        break;
        b = y + " releases " + z + ".\n";
        break;
      case 4:
        a = "\
You nod at " + z + ", fueling the flame that lies deep within him.\n";
        b = y + " nods at " + z + ".\n";
        break;
    }
    switch(random(5))
    {
      case 0:
        c =
z + " puffs a blizzard of " + HIR + "fiery destruction" + NORM +
    " into " + x + ".\n";
        break;
      case 1:
        c = 
z + " spews " + HIR + "flaming lava" + NORM + " from his maw, \
melting " + x + ".\n";
        break;
      case 2:
        c =
HIR + "Flames" + NORM + " erupt from " + z + "'s cavernous mouth, \
severely " + HIR + "burning" + NORM + " " + x + ".\n";
        break;
      case 3:
        c =
HIR + "Fire" + NORM + " leaps from " + z + "'s mouth, scourging \
" + x + "'s flesh.\n";
        break;
      case 4:
        c = "\
Streaks of " + RED + "dark fire" + NORM + " stream from " + z + "'s \
mouth, burning " + x + ".\n"; 
        break;
    }
    return ({ a, b, c });
}

       
status
main(string str)
{
    object          ob, dragon;
    string *msgs;

    needrank(7);

    if(this_player()->query_ghost()) return 0;

    dragon = (object) previous_object()->Dragon();
    if (!dragon) {
	 notify_fail("You do not have a dragon.\n");
	 return 0;
    }
    if (!present(dragon, environment(this_player()))) {
	notify_fail("Your dragon is not here.\n");
	return 0;
    }
    if((qsp(dragon) < COST) || dragon->Casted()) {
	write("\
Your dragon exhales some sulphurous vapours through its nostrils.\n");
	say(capname + "\
's dragon exhales some sulphurous vapours through its nostrils.\n");
	return 1;
    }
    if (str) {
	ob = present(str, environment(this_player()));
	if (!ob) {
	    write("There is no " + str + " here.\n");
	    return 1;
	}
	if (!living(ob)) {
	    write("Only a foolish warrior would try to kill something that is not alive.\n");
	    return 1;
	}
    }
    else
	ob = (object) this_player()->query_attack();

    if (!ob || ob == this_player() || ob == dragon) {
	write((string)dragon->query_name() + " snorts derisively.\n");
	return 1;
    }
    if (!this_player()->valid_attack(ob) || !ob->query_npc()) {
	write((string)dragon->query_name() + " cannot attack " + 
       (string)ob->query_name() + ".\n");
	return 1;
    }

    msgs = get_msgs((string)this_player()->query_name(),
                (string)dragon->query_name(),
                    (string)ob->query_name());
    
    write(msgs[0] + msgs[2]);
    tell_room(environment(this_player()), msgs[1] + msgs[2], ({ this_player() }));
    dragon->add_spell_point(-COST);
    if ((object) ob->query_attack() != this_player())
      ob->attacked_by(this_player());
    if(ob->query_npc())
    ob->hit_player(DAMAGE, "other|fire");
    dragon->Casted(1);
    return 1;
}
