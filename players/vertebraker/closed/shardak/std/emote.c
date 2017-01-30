#include "/players/vertebraker/ansi.h"

object Bob;
mapping eMsgs;

void
reset(status arg)
{
    if(arg) return;
    eMsgs = ([ ]);
}

void
load_eMsgs(mapping a)
{
    eMsgs = (a ? a : ([ ]));
}

string
schuffle(string agh)
{
    string *poo;
    int s;
    s = sizeof(poo = explode(agh, "#"));
    while(s--)
    {
      if(poo[s] == "N")
        poo[s] = (string)this_player()->query_name();
      else
        if(poo[s] == "P")
          poo[s] = possessive(this_player());
      else
        if(poo[s] == "T")
          poo[s] = (string)Bob->query_name();
      else
        if(poo[s] == "O") poo[s] = objective(Bob);
      else
        if(poo[s] == "S")
          poo[s] = subjective(this_player());
    }
    return implode(poo, "");
}  

status
main(string arg)
{
    string burp, nt;
    object Ob;

    Bob = 0;
    if(!arg)
    {
      if(nt = eMsgs["NTWrite"])
      {
        write(nt);
        say(schuffle(eMsgs["NTSay"]));
        return 1;
      }
      write("Do that to whom?\n");
      return 1;
    }

    else
    {

      if(!(Ob = find_player(arg)) || (int)Ob->query_invis() ||
         in_editor(Ob) || Ob == this_player())
        return 0;
      if((mixed)Ob->query_tellblock())
      {
        write(capitalize(arg) + " is blocking emotes.\n");
        return 1;
      }

      Bob = Ob;

      if(environment(Ob) != environment(this_player()))
      {
        if(burp = eMsgs["TWrite"])
        {
          write(BOLD + "[afar]" + NORM + " " + schuffle(burp) + "\n");
          tell_object(Ob, BOLD + "[afar]" + NORM + " " + 
            schuffle(eMsgs["TTell"]));
          return 1;
        }
      }

      else
      {
        if(burp = eMsgs["TWrite"])
        {
          write(schuffle(burp));
          say(schuffle(eMsgs["TSay"]), Ob);
          tell_object(Ob, schuffle(eMsgs["TTell"]));
          return 1;
        }
      }
    }
    
    return 1;
}

void
load_targeted_msgs(string *heh)
{
    if(!eMsgs) eMsgs = ([ ]);
    eMsgs["TWrite"] = heh[0];
    eMsgs["TSay"] = heh[1];
    eMsgs["TTell"] = heh[2];
}

void
load_untargeted_msgs(string *heh)
{
    if(!eMsgs) eMsgs = ([ ]);
    eMsgs["NTWrite"] = heh[0];
    eMsgs["NTSay"] = heh[1];
}
