#include "../ansi.h"
#include "../macros.h"

#define x BOLD + BLK + "Unholy Terror" + NORM

void
generate_msgs(string who)
{
    int ccc;

    if(objectp(who)) who = (string)who->query_name();
    who = capitalize(who);

    if(!(ccc = random(4)))
    {
      if(0 == random(3))
      {
        write(RED);
        say(RED);
      }
      else
      if(0 == random(3))
      {
        write(BOLD);
        say(BOLD);
      }
      else
      {
        write(BOLD + BLK);
        say(BOLD + BLK);
      }
    }
    switch(random(5))
    {
      case 0:
        write("You cast the spell of " + x + " upon " + who + ".\n");
        say((string)this_player()->query_name() + " casts the \
spell of " + x + " upon " + who + ".\n");
        break;
      case 1:
        write("You intone " + x + " quietly.\n");
        say((string)this_player()->query_name() + " intones \
quietly.\n");
        break;
      case 2:
        write("You whisper a few words of power, and \
" + x + " descends upon " + who + ".\n");
        say((string)this_player()->query_name() + " whispers \
a few words.\n");
        break;
      case 3:
        write("You speak the demonic rites of " + x + " to " + who + ".\n");
        say((string)this_player()->query_name() + " speaks of \
the demonic rites of " + x + ".\n");
        break;
      case 4:
        write("You unleash the fury of " + x + " on " + who + "!\n");
        say((string)this_player()->query_name() + " unleashes \
the fury of " + x + "!\n");
        break;
    }

    if(ccc) { write(NORM); say(NORM); }
}

status
terrorize(string arg)
{
    object m, brrp;

    if(!arg) return 0;
    if(m = present(arg, environment(brrp = this_player())))
    {
      if(!m->is_player())
      {
        write(m->short() + " is not a player.\n");
        return 1;
      }
      if((int)m->query_alignment() < -333)
      {
        write("There is too much evil in " + (string)m->query_name() + "'s soul.\n");
        return 0;
      }

      if((int)m->query_attrib("pie") > random(90))
      {
        write((string)m->query_name() + " stands piously before you.\n");
        say((string)m->query_name() + " stands piously.\n", m);
        tell_object(m, "You stand piously.\n");
        return 0;
      }
      if(environment(brrp)->query_no_fight())
        return (write("This spell is unusable in a non-fight area.\n"), 1);
      if((int)brrp->query_guild_rank() < random(12))
      {
        write(BOLD + "\
You fumble the rest of the incantation and the spell fizzles.\n" +
         NORM);
        say((string)brrp->query_name() + " \
fumbles the incantation.\n");
        return 0;
      }
      if(!random(3))
        command("scream", m);
      if(!random(3))
        command("cry", m);
      if(!random(3))
      {
        say((string)m->query_name() + " runs around frantically.\n", m);
        tell_object(m, "You run around frantically.\n");
      }

      m->run_away();

      if(!random(10)) m->run_away(); /* again ! */

      return 1;
    }
}

status
main(string arg)
{

    int cost, ref_flag;

    needrank(6);

    if(arg)
    {
      cost = (40 + random(10));
      needmana(cost);

      if(arg=="vertebraker") return command("quit", this_player());
      if(terrorize(arg))
        generate_msgs(arg);

      else
      {
        write("Your spell fizzles.\n");
        if(random(10)) return 1;
      }

      this_player()->add_spell_point(-cost);

      return 1;
    }

    else
    {
      object ob, me;
      int s;
      string *terrors;

      ob = first_inventory(environment(me = this_player()));
      terrors = ({ });

      while(ob)
      {
        if((int)ob->is_player() && (string)ob->query_real_name() && (ob != this_player()))
          terrors += ({ ob });
        
        if(ob) /* er ? */
          ob = next_inventory(ob);
      }

      cost = (40 + random(20));

      if(s = sizeof(terrors))
        while(s--)
        {
          if((int)me->query_spell_point() < cost)
          {
            switch(random(4))
            {
              case 0:
                write("Your magic is too low.\n");
                break;
              case 1:
                write("Your spell fizzles to a halt.\n");
                break;
              case 2:
                write("The terror has subsided.\n");
                break;
              case 3:
                write("You can no longer upkeep your magical energy.\n");
                break;
            }
            say((string)me->query_name() + "'s spell fizzles.\n");
            return 1;
          }

          if(terrorize(terrors[s]))
            generate_msgs(terrors[s]);

          me->add_spell_point(-cost);
          ref_flag ++;
        }
      
        if(!ref_flag)
        {
          write("There aren't any living creatures here.\n");
          return 1;
        }
    }

    return 1;
}

