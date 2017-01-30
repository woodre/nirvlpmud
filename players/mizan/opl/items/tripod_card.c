/*****************************************************************************
 *      File:                   tripod_card.c
 *      Function:               The membership card to the realm. Keeps stats
 *                              on how many monsters a player kills.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

#include "../definitions.h"
#include "/obj/ansi.h"

#define DATA_ROOT	"players/mizan/opl/data/tripodcards/"

/* our member variables */
object owner;
string owner_name;
int my_access_level;
int news_index;
int is_brief_mode;
int my_kills;        /* an array of how many monsters we killed sorted by difficulty */
int my_assists;
int my_points;       /*  the composite score of how many kills we landed */
int my_damage_taken;
int my_damage_given; 

/* these don't save */
static string new_hd;
static string new_body;

/* methods */
id(str) {
    return str == "card" || str == "tripod_card";
}

short()
{
    if (!owner_name) return 0;
    else
        return HIB + capitalize(owner_name) + "'s Tripod Card" + NORM;
}

long()
{
    write(
        "  This is a hard plastic-like card that was issued to you at the\n"+
        "Proving Grounds of the OverPowerLord. It allows membership access\n"+
        "to the various levels within his stately underground arenas, and\n"+
        "also acts like a debit card to purchase items and services.\n"+
        "There is a picture of the OverPowerLord holding a three-legged tiger\n"+
        "and both are smiling at the camera. It can be assumed that Tripod is\n"+
        "the name of this large cat.\n\n"+
        "On the back of the card is some bold text saying:\n"+
        "  Give the command '3help' for instructions on how to use your card.\n\n");
    write("Your access level is '" + my_access_level + "'.\n");

}

get() {
    return 1;
}

drop() {
    return 1;
}

string query_auto_load() {
    return "/players/mizan/opl/items/tripod_card.c";
}

init()
{
    add_action("on_help","3help");

    add_action("show_stats","3score");
    add_action("news_post","3p");
    add_action("news_read","3r");
    add_action("news_delete","3delete");
    add_action("news_headers","3h");
    add_action("news_grouplist","3l");
    add_action("news_next_group","3next");
    add_action("news_goto_group","3g");
    add_action("on_toss","3toss");
}


/* when a monster dies at our hands, we logged with a kill. */
log_kill(int difficulty)
{
    if(difficulty < 0 || difficulty > 4) return;

    my_kills[difficulty] ++;
    calculate_points();
    save_object(DATA_ROOT + owner_name);
}

log_assist(int difficulty)
{
    if(difficulty < 0 || difficulty > 4) return;

    my_assists[difficulty] ++;
    calculate_points();
    save_object(DATA_ROOT + owner_name);
}

log_damage_taken(int arg)
{
    my_damage_taken += arg;
}

log_damage_given(int arg)
{
    my_damage_given += arg;
}

on_help()
{
    write("Some words appear in midair...\n\n"+
          "These are the things that you can do with your official Tripod Card,\n"+
          "available only at the Proving Grounds of the OverPowerLord.\n\n"+
          "3help      Shows the contents of this screen.\n"+
          "3toss      Toss away *gasp* this card! Why would you do such a thing!\n"+
          "3score     Show statistics about monsters you have killed in the maze.\n"+
          "3l         List available posting groups on the Tripod News Network.\n"+
          "3h         Lists the headers from within your currently selected group.\n"+
          "3r <num>   Reads the selected message within currently selected group.\n"+
          "3n         Goes to the next group in the Tripod News Network.\n"+
          "3g <num>   Goes the the specified posting group.\n"+
          "3p <title> Begins process of posting a message within current group.\n");
    return 1;
}

on_toss()
{
    write("You toss the Tripod card into the wind. You bastard!\n");
    say(this_player()->query_name() + " tosses out " + this_player()->query_possessive() +
        " Tripod card into the wind! It dies of rejection.\n");
    calculate_points();
    save_object(DATA_ROOT + owner_name);
    destruct(this_object());
    return 1;
}

reset(arg)
{
    if (arg) return;
    remove_call_out("delayed_reset");
    call_out("delayed_reset", 1);
}

delayed_reset()
{

    if (!environment(this_object()) ||
            !environment(this_object())->is_player()) return;

    owner = environment(this_object());
    owner_name = environment(this_object())->query_real_name();

    /* if a player does not have a save file, we make one with basic
     * access level.
     */
    if (!restore_object(DATA_ROOT + owner_name))
    {
        /* establish a minimum level */
        if (owner->query_level() > 19) my_access_level = 2;
        else my_access_level = 1;

        my_kills = allocate(5);
        my_assists = allocate(5);
        my_points = 0;
        my_damage_given = 0;
        my_damage_taken = 0;

        save_object(DATA_ROOT + owner_name);
    }

}

show_stats()
{
    int i;
    /* not mechanized, but it works. */

    write(">> Kill Difficulty      Points Each     Corpses\n");
    write("   H'ORDERVES           1               " + my_kills[0] + "\n");
    write("   APPETIZERS           2               " + my_kills[1] + "\n");
    write("   SALADS               5               " + my_kills[2] + "\n");
    write("   MAIN ENTREES         10              " + my_kills[3] + "\n");
    write("   EATING CONTESTS      50              " + my_kills[4] + "\n");

    write("\n");

/*
    write(">> Assist Difficulty    Points Each     Corpses\n");
    write("   H'ORDERVES           1               " + my_assists[0] + "\n");
    write("   APPETIZERS           2               " + my_assists[1] + "\n");
    write("   SALADS               3               " + my_assists[2] + "\n");
    write("   MAIN ENTREES         5               " + my_assists[3] + "\n");
    write("   EATING CONTESTS      10              " + my_assists[4] + "\n");

    write("\n");
*/
    write(">> Total Proving Ground Loyalty Points: " + calculate_points() + "\n");
    write("   These points will NEVER expire.\n");

    return 1;
}

query_points()
{
    return calculate_points();
}

calculate_points()
{
    int result;
    result = (my_kills[0]) + (my_kills[1] * 2) + (my_kills[2] * 5) + (my_kills[3] * 10) + (my_kills[4] * 50);
/*
    result += my_assists[0] + (my_assists[1] * 2) + (my_assists[2] * 3) + (my_assists[3] * 5) + (my_assists[4] * 10);
*/
    my_points = result;
    return result;
}

query_access_level() {
    return my_access_level;
}
set_access_level(str) {
    my_access_level = str;
}

is_brief_mode() {
    return is_brief_mode;
}
toggle_brief_mode() {
    is_brief_mode = !is_brief_mode;
}

query_news_index() {
    return news_index;
}
set_news_index(str) {
    news_index = str;
}

news_read(str) {
    return TRIPOD_DM->news_read(str);
}
news_delete(str) {
    return TRIPOD_DM->news_delete(str);
}
news_delete_group(str) {
    return TRIPOD_DM->news_delete_group(str);
}
news_add_group(str) {
    return TRIPOD_DM->news_add_group(str);
}
news_headers() {
    return TRIPOD_DM->news_headers();
}
news_grouplist() {
    return TRIPOD_DM->news_grouplist();
}
news_next_group() {
    return TRIPOD_DM->news_next_group();
}
news_goto_group(arg) {
    return TRIPOD_DM->news_goto_group(arg);
}

news_post(str)
{
    if (!TRIPOD_DM->news_post_check(str)) return 1;
    input_to("get_body");
    new_hd = str;
    new_body = "";
    return 1;
}

get_body(str)
{
    if (str == "**")
    {
        TRIPOD_DM->news_feed(new_hd,new_body);
        new_body = 0;
        new_hd = 0;
        return 1;
    }

    if (str == "~q")
    {
        write("\n>> Aborted.\n");
        new_body = 0;
        new_hd = 0;
        return 1;
    }

    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
}

