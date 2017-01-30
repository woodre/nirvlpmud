/*
 * Guild PROMOTE command for the Servants of Shardak
 * Set the 'class' of a guild member
 */
#pragma strict_types
#include "../people.h"
#include "../def.h"
#include "../std.h"
inherit CMD;

status
main(string arg)
{
    string      name, msg, class;
    int         new, myclass, current;
    object      p, ob;



    if (!arg || sscanf(arg, "%s %s", name, class) != 2) {
	notify_fail("Usage: gpromote <who> <class>\n");
	return 0;
    }
    class = capitalize(lower_case(class));
    name = capitalize(lower_case(name));
    new = strtoclass(class);
    if (new < C_NOVICE || new > C_MAGUS) {
	write("The class \"" + class + "\" is invalid.\n");
	return 1;
    }

    myclass = (int) previous_object()->GuildClass();
    /* special has the power of law in promoting */
    if (myclass < C_SENIOR)
    {
      notify_fail("\
You do not have the power to promote.\n");
      return 0;
    }
    if (myclass == C_SPECIAL) myclass = C_SENIOR;
    /* promoting to above law is done by wizzes */
    if (new >= myclass || (myclass < C_MAGUS && new > C_LAW)) {
	write("You can only promote members up to the class below your own.\n");
	return 1;
    }
    p = find_player(lower_case(name));
    if (!p || ((int) p->query_invis(this_player()->query_level()) > 0)) {
	write("That person isn't around.\n");
	return 1;
    }
    if (!(ob = present(OBJID, p))) {
	write(name + " does not bear the mark of Shardak.\n");
	return 1;
    }

    current = (int) ob->GuildClass();
    if (current == new) {
	write(name + " is already of class " + class + ".\n");
	return 1;
    }
    /* again: all classes above law are handled by wizards */
    if (new < current &&
	(myclass <= current ||
         (myclass < C_MAGUS && current > C_LAW))) {
	write("You cannot degrade " + name + "!\n");
	return 1;
    }
    ob->ClassName(class);

    /* broadcast and log the command */
    msg = (current > new) ? " has been degraded to class "
			  : " has been promoted to class ";
    CHANNELD->broadcast(name + msg + class + " by " +
	this_player()->query_name() + ".\n", 0, "{Servants}");

    write_file(LOGDIR + "gpromote",
	this_player()->query_real_name() + " [" + ctime()[4..15] +
	"] gpromoted " + name + " to " + class + "\n");
    return 1;    
}
