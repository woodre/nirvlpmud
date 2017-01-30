#include "/players/mizan/esc.h"
string chat_msgs;
int player_exp;

id(str) { return str == "shit-consumption-sickness"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + " appears to be vomitously sick";
}

reset(arg)
{
    if(arg) return;

  if(!root()) {
    remove_call_out("erase_me");
    remove_call_out("random_chat");
    remove_call_out("extra_reset");

    call_out("extra_reset", 1);
    call_out("random_chat", 15);
    call_out("erase_me", 300);
  }

}

extra_reset()
{
    string temp;
    object player;

    player = environment(this_object());
    if(player && living(player))
    {
        player_exp = player->query_exp();

        temp = ctime() + " " + player->query_real_name() + " (" + player->query_exp() + "exp) has been infected with shit-consumption-sickness.\n";
        log_file("mizan.SHIT_CONSUMPTION", temp);
    }
}


erase_me()
{
    string temp;

    temp = ctime() + " " + environment(this_object())->query_real_name() +
        " (" + environment(this_object())->query_exp() + "exp) erase_me() called. Quitting.\n";
    log_file("mizan.SHIT_CONSUMPTION", temp);
    destruct(this_object()); /* moved to here by verte */
    return 1;
}

random_chat()
{
    int hurt_potential;
    int current_exp;
    object player;
    string temp;

    player = environment(this_object());
    if(player) current_exp = player->query_exp();

    if(!chat_msgs)
    {
        chat_msgs = ({
            " appears to be very pale.",
            " looks to be poisoned or something.",
            " does not appear to be very well.",
            " has brown stains all over.",
            " does not look very good.",
            " looks very sick.",
            " appears to have eaten some... shit!",
            " is foaming used corn kernels.",
            " has strange, brown liquid goop foaming from the mouth.",
            " appears about to vomit.",
        });
    }

    if(environment(this_object()) && living(environment(this_object())))
    {
        /* the potention for hurting is based on the level */
        hurt_potential = environment(this_object())->query_level();

        call_other(environment(this_object()), "remote_say", environment(this_object())->query_name() + chat_msgs[random(sizeof(chat_msgs))] + "\n\n");

        tell_object(environment(this_object()), "You feel poisoned by the pile of shit.\n");

        /* if they are disconnected, dont do damage */
        if(environment(this_object())->query_interactive())
            environment(this_object())->hit_player(20 + random(hurt_potential));

        /* random emote */
        if(1 == random(2))
            command("puke", environment(this_object()));

        if(1 == random(2))
            command("scream", environment(this_object()));

        /* let them know, really clearly.  */
        command("mon", environment(this_object()));

        /* if they are dead, the joke is over */
        if(environment(this_object())->query_dead())
            destruct(this_object());

        if(current_exp < player_exp && environment(this_object()))
        {
            temp = ctime() + " " + environment(this_object())->query_real_name() +
                " (" + environment(this_object())->query_exp() + "exp) has less experience. Shit-consumption-sickness quitting.\n";
            log_file("mizan.SHIT_CONSUMPTION", temp);
            destruct(this_object());
        }

    }

    

    remove_call_out("random_chat");
    call_out("random_chat", 15);

}
