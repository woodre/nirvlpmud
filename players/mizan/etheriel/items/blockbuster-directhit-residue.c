#include "/players/mizan/esc.h"
string chat_msgs;

id(str) { return str == "stains"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + " is covered from head to toe in thick black soot";
}

reset()
{
    remove_call_out("erase_me");
    remove_call_out("random_chat");

    call_out("erase_me", 400);
    call_out("random_chat", 30);
}

erase_me()
{
    destruct(this_object());
    return 1;
}

random_chat()
{
    if(!chat_msgs)
    {
        chat_msgs = ({
            " appears to be sizzling and smouldering, as if hit by an explosive.",
            "'s hair seems to be smoldering, and smells like burnt gunpowder.",
            " emits a strange funky, steam cloud.",
            " reeks of gunpowder!",
        });
    }

    if(environment(this_object()) && living(environment(this_object())))
    {
        call_other(environment(this_object()), "remote_say", environment(this_object())->query_name() + chat_msgs[random(sizeof(chat_msgs))] + "\n\n");

        tell_object(environment(this_object()), "You feel dizzy as all you feel is burnt, and all you can smell is smoke.\n");
    }

    remove_call_out("random_chat");
    call_out("random_chat", 30);

}
