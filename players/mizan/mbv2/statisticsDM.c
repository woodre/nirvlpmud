/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

/*
 * This is going to be a simple object to record events and statistics.
 * We're looking for the following things to log:
 *
 * Player attacking us, and damage inflicted with each round.
 * Org/Guild name 
 *
 * how is this going to stored...
 * Guild simply is a small 2D array recording an instance of a guild member
 * calling attack on us.
 * 
 * guild =({ 
 *     ({ "knight", 10 }),
 *     ({ "assassin", 12 }),
 *     ({ "monk", 3 }),
 * });
 *
 * Player info is stored similarly...
 * player =({
 *     ({ "plyrname1", hpdam, rounds, attacks_on_us, }),
 *     ({ "plyrname2", hpdam, rounds, attacks_on_us, }),
 *     ({ "plyrname3", hpdam, rounds, attacks_on_us,}),
 * });
 * 
 *
 */



/* IMPORTANT TO MAKE NO DISTINCTION BETWEEN PAYING AND NONPAYING TRIAL CUSTOMERS */

/* our member variables */
string my_guild_index;
string my_player_index;

object temp_analysis_data;
string temp_analysis_string;
int temp_analysis_int;

object my_primary_target_result;
object my_secondary_target_result;
string my_guildname_target_result;


/* we are being fed the name of the player that hit us, and how much
 * damage they did. Will log this info into the index.
 */
report_hit_player(attname, dam)
{

}

/* we are being fed the name of the attacker, and what guild they are from. */
report_attack_object(attname, guildname)
{
}





/* Analyzing the data of current logins will take several rounds. 
 *
 * We are doing a lot here so we are going to spread it across several methods.
 * The end goal is to populate our result objects.
 *
 */
login_analysis_step01()
{
    /* just collect data from our indexes about who is current logged in */
    remove_call_out("login_analysis_step02");

    call_out("login_analysis_step02", 2);
}


login_analysis_step02()
{
    /* Here we are going to decide who has committed the most damage against us 
     * as an individual player.
     */
    remove_call_out("login_analysis_step03");

    call_out("login_analysis_step03", 2);
}


login_analysis_step03()
{
    /* Here we are going to decide who has committed the most damage against us 
     * as an entire guild.
     */
    remove_call_out("login_analysis_step04");

    call_out("login_analysis_step04", 2);
}


login_analysis_step04()
{
    /* Here we are going to formulate our combat strategies.
     */
    remove_call_out("login_analysis_step05");

    call_out("login_analysis_step05", 2);
}


login_analysis_step06()
{
    /* Here we call up additional units if required, and acquisition
     * existing units where possible..
     */
    remove_call_out("login_analysis_step03");
    call_out("login_analysis_step03", 2);
}


login_analysis_step07()
{
    /* Now, we deploy those units into the field.
     */
}

