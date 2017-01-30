#include "../macros.h"

#define MANA (30 + random(30))
#define RANK 6

#include "/players/vertebraker/ansi.h"

#define tracer "/players/vertebraker/closed/shardak/obj/tracer"

string *cali;

void
reset(status arg)
{
    if(arg) return;

    cali = ({ "\tFear pours through your soul.\n",
              "\tDarkness weaves through every fiber of your being.\n",
              "\tEvil seeps over you...\n",
              "\tDecay settles over the area...\n",
              "\tImages of destruction flash through your mind...\n",
              "\tLife scuttles to a halt all around you...\n",
              "\tEverything dies...\n",
              "\tDemons flutter past your eyes...\n",
              "\tSpecters haunt your sight...\n",
              "\tDeath is all around you...\n",
              "\t          DESTRUCTION\n", });
}

status
main(string arg)
{
    int i;
    object a, ob;

    needmana(MANA); needrank(RANK);
    if(!arg && !(ob = (object)this_player()->query_attack()))
    {
      write("Intone the spell of coursing upon whom?\n");
      return 1;
    }
    if(arg && !(ob = present(arg, environment(this_player()))))
    {
      write("You don't see " + arg + " here.\n");
      return 1;
    }

    if(ob->is_player())
    {
      write("Shardak forbids this action against players.\n");
      return 1;
    }
    if(!this_player()->valid_attack(ob)) return 1;
    if(present("54a2dakt2ac32", ob))
    {
      write((string)ob->query_name() + " is being coursed.\n");
      return 1;
    }

    write("\
You point a finger towards " + (string)ob->query_name() + ".\n\n");
    say((string)(a = this_player())->query_name() + " \
points a finger towards " + (string)ob->query_name() + ".\n",
    ({ ob }));
    tell_object(ob, (string)a->query_name() + " \
points a finger towards you.\n");

    for(i = 0; i < (1 + random(3)); i ++)
      tell_object(ob, cali[random(sizeof(cali))]);

    if((int)ob->query_attrib("int") > random(60))
      tell_object(ob, "\n\
You feel as though you should not run from a fight.\n");

    tell_room(environment(a), BOLD + "\
Fear" + NORM + 
" grips the face of " + (string)ob->query_name() + ".\n",
    ({ ob }));
    move_object(clone_object(tracer), ob);
    this_player()->add_spell_point(-MANA);
    return 1;
}
