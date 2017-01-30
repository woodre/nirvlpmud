string msg;
string text;
object receiver;
#include "/players/vertebraker/closed/shardak/def.h"
#include "/players/vertebraker/closed/shardak/tasks.h"
#define tprn (string)from->query_real_name()

mapping heh;

#define INIT_ARR ({ "Staff of the Wizards", "Staff of the Magus", "Staff of the Lich" })

void
catch_tell(string str)
{
    string      who, what;
    int         i;
    object      mark;

    if (this_player())
        mark = present(GUILD_ID, this_player());
    if (!mark || !str)
        return;

    if (!text && (sscanf(str, "%s says: %s\n", who, what) == 2 ||
                  sscanf(str, "%s asks: %s\n", who, what) == 2 ||
                  sscanf(str, "%s tells you: %s\n", who, what) == 2)) {
        what = lower_case(what);

        if (sscanf(what, "%strial", who)) {
            if (mark->query_solved(STORM_TASK)) {
                text= "\
The dark hermit says,\
\"You have completed my trial.\"\n";
            }
            else {
                text= read_file(ABSPATH + "hermit_task");
            }
        }
        else if (sscanf( what, "%sabilities", who)) {
            if(mark->query_solved(STORM_TASK)) {
                text = "\
The dark hermit says,\
\"You may channel the powers of the raging \"storm\".\n";
        }
       }
        else return;
        receiver = this_player();
        call_out("DoTalk", 2);
    }
}

mixed add_weight(int w)
{
#if 0
    if (w > 0)                  /* I am receiving something of weight */
        if (first_inventory(this_object()))
            return 0;           /* disallow more than 1 object */
        else
#endif
            if(this_player())
        /* maybe this check will kill the catastropic bug?? -Bp */
            call_out("received", 1, this_player());

   /* RECURISON DAMMMIT!!!! -Bp
    return this_object()->add_weight(w);
    */
   return w;
}


void received(object from)
{
    object gore, mark;
    string a;
    int i;

    gore = first_inventory(this_object());
    if (gore && from)
    {
        if ((mark = present( GUILD_ID, from))
        &&  !((int) mark->query_solved(FLAMES_TASK)))
      {
        if(!heh[tprn]) heh[tprn] = INIT_ARR;
        if(stringp(a = (string)gore->query_verte_shardak_consistency()))
        {
          if((i = member_array(a, heh[tprn])) == -1)
            msg = "\
  The hermit tells you,\"You've already given me The " + a + ".\"\n";
          else
          {
            int s;
            heh[tprn][i] = 0;
            msg = "The hermit smiles at you. \"Now I only require:\"\n";
            s = sizeof(heh[tprn]);
            for(i = 0; i < s; i ++)
              if(heh[tprn][i])
                msg += "\tThe " + heh[tprn][i] + "\n";
            msg += "\n";
          }
          tell_object(from, msg);
          if(!heh[tprn][0] && !heh[tprn][1] && !heh[tprn][2])
          {
            tell_object(from, "The hermit nods at you, and waves his fist.\n");
            tell_object(from, "A red aura surrounds you.\n");
            tell_room(environment(from), "A red aura surrounds " +
             (string)from->query_name() + ".\n", ({ from }));
            mark->stop_cmds();
            call_out("congrat", 1, from);
          }
        }
        else 
          tell_room(environment(), "The hermit frowns and destroys something.\n");
      }
    }
    if(gore) destruct(gore);
 
}

void congrat(object from)
{
    object mark;

    if (from) {
        say("A red aura envelopes " + from->query_name() +
            " for a mere instant.\n", from);
        tell_object(from, "\
You are encased in a red aura, and you hear Shardak's voice:\n\
\"The \"storm\" is now at your command.  You are truly a worthy\n\
servant.\n");
        mark= present( GUILD_ID, from);
    }

    if (mark) {
        mark->add_solved(WASTE_TASK);
        mark->save_me();
        mark->enable_cmds();
    }
}
