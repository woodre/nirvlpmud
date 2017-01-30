/*
 * FATALITY spell for the Shardak guild
 * tinkered with by verte, make it kill! : add more type syntax
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../macros.h"
#define msg(x) tell_room(environment(this_player()), x)
inherit CMD;

#define COST 13

status
main(string arg)
{
    object          ob, weapon, entrails;
    string          name, oname, wname, type;
    int             dam, health, mhealth;

    if (arg) return 0;
    
    needrank(1);
    needmana(COST);
    if (!(weapon = (object) this_player()->query_weapon())) {
	write("You must have a weapon.\n");
	return 1;
    }    
    ob = (object) this_player()->query_attack();
    if(!ob)
   {
	write("You are not fighting anybody.\n");
	return 1;
    }
    if (ob->is_player()) {
	write("Shardak does not allow you to use this power against players.\n");
	return 1;
    }
    this_player()->add_spell_point(-COST);
    name = (string) this_player()->query_name();
    oname = (string) ob->query_name();
    wname = ((string) weapon->query_name() || "weapon");

    if (!(mhealth = qmhp(ob))) mhealth = 1;
    health = qhp(ob);
    if ((health > 60) || (health*100/mhealth) > 10) {
	write(oname + " easily dodges your headlong attack.\n");
	say(name + " charges at " + oname + ", who dodges nimbly.\n", ob);
	tell_object(ob, name + " charges at you, but you easily dodge the attack.\n");
	if (random(100) < 30) {
	    write(oname + " promptly punishes your unsuccesful attack.\n");
	    say(oname + " promptly punishes " + name + "'s wild swing.\n", ob);
	    tell_object(ob, "You promptly punish the unsuccesful attack.\n");
	    this_player()->hit_player(random((int) ob->query_wc()));
	}
	return 1;
    }

    type = (string) weapon->query_type();
    switch (type) {
      case "sharp":
      case "cutting":
      case "sword":
      case "axe":
      case "knife":
	write(format(
	    "You fake a swing at " + oname + "'s left side and " +
	    subjective(ob) + " shifts " + possessive(ob) +
	    " guard to block the attack.\n" +
	    "Instead you rotate and swing your " + wname + " backhand at " +
	    oname + "'s neck.\n"));
	say(format(
	    name + " lunges at " + oname +
	    ", who shifts his guard to block the attack.\n" +
	    name + " turns swiftly and swings " + possessive(this_player()) +
	    " " + wname + " backhand at " + oname + "'s neck.\n"));
	if (random(100) < 10) {
	    write("Your swing almost takes " + oname + "'s head off.\n" +
		  "Blood squirts from " + possessive(ob) + " sliced artery.\n");
	    say("The swing almost takes " + oname + "'s head off.\n" +
		"Blood squirts from " + possessive(ob) + " sliced artery.\n");
	}
	else {
	    object head;
	    
	    write(oname + "'s head comes clean off.\n");
	    say(oname + "'s head comes clean off.\n");
            head = clone_object("/obj/treasure");
	    head->set_id("head");
	    head->set_short("the head of " + oname);
	    head->set_long(format(
"This is the maimed head of " + oname + ". The nose is broken and the one "+
"eye has been crushed. But most prominently, the body, to which this head "+
"belongs, is missing.\n" + oname + " was decapitated by " + name + ".\n"));
            head->set_value(random((int)ob->query_level() * 3));
	    head->set_weight(1);
	    move_object(head, environment(ob));
	}
	break;
      case "bludgeoning":
      case "blunt":
      case "club":
      case "mace":
      case "stick":
	write("You bombard your weakened enemy with blows.\n");
	say(name + " bombards " + oname + " with blows from " +
	    possessive(this_player()) + " " + wname + ".\n");
	if (random(100) < 90)
	  msg(oname + "'s right arm breaks with a sickening crunch.\n");
	if (random(100) < 90)
	  msg(oname + " gets " + possessive(ob) + " face smashed in.\n");
	if (random(100) < 90)
	  msg(oname + " screams as " + possessive(ob) + " left arm breaks.\n");
	if (random(100) < 90)
	  msg(oname + " topples at a direct hit to " + possessive(ob) +
	      " temple.\n");
	write("Your last blow crushes " + oname + "'s cranium.\n");
	say("The last blow crushes " + oname + "'s cranium.\n");
	break;
/*
      case "pointed":
      case "piercing":
	break;
*/
      default:
        write("You disembowel " + oname + " with the final blow.\n");
        say(this_player()->query_name() + " disembowels " + oname + ".\n",
	    ob);
        tell_object(ob, this_player()->query_name() + " disembowels " +
		    "you.\n");
        entrails = clone_object("/players/vertebraker/closed/shardak/obj/entrails");
        entrails->set_id("entrails of " + 
          lower_case((string)ob->query_name()));
        entrails->set_alias("entrails");
        entrails->set_short("The bloody entrails of " + 
         (string)ob->query_name());
        entrails->set_long("\
Heaps of steaming entrails, intestines, and other nastiness\n\
left by the untimely death of " + (string)ob->query_name() + " \
by " + name + "'s hands.\n");
        entrails->set_weight(1);
        entrails->set_value(random((int)ob->query_level() * 3));
        move_object(entrails, environment(ob));
        break;
    }
    ob->death();
    return 1;
}
