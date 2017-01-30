#include "/players/mizan/esc.h"
string chat_msgs;

id(str) { return str == "stains"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + " is covered with a disgusting, smelly brown residue";
}

reset()
{
    remove_call_out("erase_me");
    remove_call_out("random_chat");

    call_out("erase_me", 300);
    call_out("random_chat", 25);
}


init()
{
    add_action("on_hug","hug");
}


on_hug(arg)
{
   object ob;
   if(!arg || !environment(this_player())) return 0;

   ob = present(arg, environment(this_player()));

   /* make sure we are not a wizard. */
   if(ob &&
      ob->is_player() &&
      !present("stains-shit-huggedon", ob) &&
      ob->query_level() < 21)
   {
      write("You spread your filth to " + ob->query_name() + ".\n");
      tell_object(ob, this_player()->query_name() + " is covered with shit! YUCK!!!\n");
      move_object(clone_object("/players/mizan/etheriel/items/shit-hug-residue.c"), ob);
   }
   return 0;
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
            " smells really damn bad.",
            "'s hair STINKS!",
            " is covered with a smelly brown stain.",
            " smells pretty damn gross.",
            " appears to have been pelted with semi-liquid fecal matter.",
        });
    }

    if(environment(this_object()) && living(environment(this_object())))
    {
        call_other(environment(this_object()), "remote_say", environment(this_object())->query_name() + chat_msgs[random(sizeof(chat_msgs))] + "\n\n");

        tell_object(environment(this_object()), "You are covered with shit, and you smell bad.\n");
    }

    if(environment(this_object()) &&
        environment(this_object())->query_level() >= 21 &&
        environment()->query_name(this_object()) != "mizan")
    {
        tell_object(environment(this_object()), "Being a wizard that is not Mizan, the shit stains magically dissapate...\n");

        destruct(this_object());
    }
    else
    {
        remove_call_out("random_chat");
        call_out("random_chat", 25);
    }

}
