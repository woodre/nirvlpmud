/* 
   by verte - holds unlimited items per rules
   plus has a drawback: major for non-shardaks,
                        minor for shardaks
*/

#include "../def.h"
#include "/players/vertebraker/ansi.h"

#define CALL 200 + random(40)

inherit "/obj/container";

void 
reset(int x)
{
    if(x) return;
    ::reset();
    max_weight = 1000000; /* unlimited */
    set_can_open(666);
    set_value(450 + random(50));
    set_name("manskin bag");
    set_short("A manskin bag "+RED+"[BloodHot]"+NORM);
    set_long("\
The flesh sack in front of you looks like it could hold\n\
many things.  A loose rawhide drawstring hangs loosely from\n\
the top of the bag.  A magical glow encompasses it, and a\n\
faint veil of steam rises.  You feel a slight heat to it as\n\
you touch it.\n");
    call_out("burn_me", CALL);
}

mixed
id(string str)
{
    return str == name || str == "bag" || str == "skin bag";
}

int 
close(string str)
{
    if(!id(str)) return 0;
    if(!opened)
    {
      notify_fail("The bag is already closed...\n");
      return 0;
    }
    opened = 0;
    write("\
You grab ahold of the skin bag, and pull back the\n\
tight drawstring.\n");
    say(this_player()->query_name() + " closes up " +
        this_player()->query_possessive() + " manskin bag, and pulls back\n"
        + "the tight drawstring.\n");
    return 1;
}

int
open(string str)
{
    if(!id(str)) return 0;
    if(opened)
    {
      notify_fail("The bag is already open...\n");
      return 0;
    }
    opened = 1;
    write("\
You pull the drawstring back on the manskin bag, and you open\n\
it up.\n");
    say(this_player()->query_name() + " pulls the drawstring back "
        + this_player()->query_possessive() + " manskin bag, and\n"
        + " opens it up.\n");
    return 1;
}

int 
query_weight()
{
    int x, tmp_weight;
    object *i;

    i = all_inventory(this_object());
    for(x = 0; x < sizeof(i); x ++)
      tmp_weight += ((int)i[x]->query_weight());
    return (tmp_weight / 8);
}

void
burn_me()
{
    object User;

    User = environment();
    if(User)
    {
      if(living(User) && User->is_player())
    /* cheating people using to kill NPCs, fixed -Bp */
      {
        if(!present(OBJID, User) && !present("allymark", User)) 
        {
          tell_object(User, "\
The manskin bag glows a deep crimson.....\n\
A "+HIR+"volley of flames"+NORM+" launches from the bag, burning you intensely!\n");
          User->hit_player(30 + random(30));
        }
        else
        {
          tell_object(User, "\
The manskin bag glows a dim red....\n\
A small blaze enflames all around you...\n");
          User->hit_player(10 + random(10));
        }
      }
    }

    call_out("burn_me", CALL);
}

string
query_real_name()
{
    return "A curse of Shardak";
}

short() { return short_desc + (opened ? " (open)" : " (closed)" ); }

query_save_flag() { return 1; }

init() {
  ::init();
  add_action("give","give");
}
/* stupid ass shards giving the bags to players to kill em. fixed, -Bp */
give(str) {
  string item,dest;
  object dest_ob;
  if (sscanf(str, "%s to %s", item, dest) == 2) {
     if(!id(item)) return 0;
     dest_ob = present(dest, environment(this_player()));
     if(!dest_ob) return 0;
     if (!living(dest_ob)) return 0;
     if (dest_ob->is_player()) {
        write("No more cheating, you cannot give the bag to players.\n");
        return 1;
     }
  }
  return 0;
}
