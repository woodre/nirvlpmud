/*
 * SCAN (consider enemy) for the Shardak guild
 * by Drag and Bal
 */
#pragma strict_types
#include "../std.h"
#include "../macros.h"
inherit CMD;

#define COST 10

status
main(string str)
{
    object      ob;
    int         diff;

    if (!str) {
	notify_fail("Who do you want to scan?\n");
	return 0;
    }
    needrank(2);
    needmana(COST);
    ob = present(str, environment(this_player()));
    if (!ob) {
	notify_fail(capitalize(str) + " is not here.\n");
	return 0;
    }
    if (!living(ob)) {
	notify_fail("Scan is useless on things that are not alive.\n");
	return 0;
    }
    write("You close your eyes and concentrate on " + capitalize(str) + ":\n");

    diff = umhp - qmhp(ob);
    if (diff >= 10) {
	write("HP: You are the stronger warrior.\n");
    }
    else if (diff <= -10) {
	write("HP: You are the weaker warrior.\n");
    }
    else {
	write("HP: You are equal warriors.\n");
    }

    diff = ((int) this_player()->query_ac()) - ((int) ob->query_ac());
    if (diff > 1) {
	write("AC: You are better protected.\n");
    }
    else if (diff < -1) {
	write("AC: You are less protected.\n");
    }
    else {
	write("AC: You are equally protected.\n");
    }

    diff = ((int) this_player()->query_wc()) - ((int) ob->query_wc());
    if (diff > 1) {
	write("WC: You have the advantage.\n");
    }
    else if (diff < -1) {
	write("WC: You are at a disadvantage.\n");
    }
    else {
	write("WC: You have equal weapons.\n");
    }

    this_player()->add_spell_point(-10);
    say(capname + " closes " + this_player()->query_possessive() +
	" eyes and concentrates intently on " + capitalize(str) + ".\n");
    return 1;
}
