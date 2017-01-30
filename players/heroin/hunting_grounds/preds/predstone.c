/* Resuscitated by Vertebraker after
   Mythos and Mizan?  hacked it to pieces.
   Now it works only in the Predator area,
   has a value, and makes sense on how to use it.
   Also the short isn't cheeso anymore.
*/

#include "/players/vertebraker/ansi.h"
#define PATH "players/heroin/hunting_grounds/preds/"

int base_val;

void
reset(status arg)
{
    if(!arg) base_val = 666 + random(333);
}

status 
id(string str)
{
    return (str == "gem" || str == "control gem");
}

string
short()
{
    return "A control gem <" + GRN + "*" + NORM + ">";
}

void
long()
{
   write("\
This is the Predator's control gem.\n\
And by looking at the gem, you get the idea\n\
that you should \"fasten\" it to yourself somehow.\n");
}

void
init()
{
   add_action("cmd_fasten","fasten");
}

status
cmd_fasten(string arg)
{
    int s;
    string what, file;

    if(!arg)
    {
      notify_fail("Fasten what?\n");
      return 0;
    }

    if(!id(arg) && (sscanf(arg, "the %s", what) && !id(what)))
    {
      notify_fail("You may fasten the gem.\n");
      return 0;
    }

    file = file_name(environment(this_player()));

    if(strlen(file) < (s = strlen(PATH)) ||
       file[0..s-1] != PATH)
    {
      notify_fail("You fasten the gem, but nothing happens.\n");
      return 0;
    }

    if((object)this_player()->query_attack())
    {
      notify_fail("You are busy.\n");
      return 0;
    }
    write("You fasten the gem securely to your person.\n\n");
    write("Suddenly everything around you shimmers...\n\n");
    write(BOLD + "\tYou disappear.\n\n" + NORM);
    write("You reappear before Angst.\n");
    say((string)this_player()->query_name() + " \
fastens the gem to " + objective(this_player()) + "self.\n" + 
    capitalize(subjective(this_player())) + " disappears.\n");
    move_object(this_player(), "/" + PATH + "safety");
    tell_room(environment(this_player()),
        (string)this_player()->query_name() + " appears from \
nothingness.\n", ({ this_player() }));
    write("The gem disappears.\n");
    destruct(this_object());
    return 1;
}

int
query_value()
{
    return base_val;
}

status
query_save_flag()
{
    /* sweet */
    write("The control gem " + GRN + "pulses" + NORM + ".\n");
    return 1;
}

status
get()
{
    return 1;
}

