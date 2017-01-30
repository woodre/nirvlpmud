/* 
 * Forbin
 * Created:   unknown -vertebraker
 * Last edit: 2003.10.28 -forbin
 * Change log:  -minor editing for personal preference of code
 *              -originally coded for Shardak guild by Vertebraker,
 *               borrowed for personal emote use
 */

#include "/players/forbin/ansi.h"

object Bob;
mapping eMsgs;

void reset(status arg) {
  if(arg) return;
  eMsgs = ([ ]);
}

void load_eMsgs(mapping a) {
  eMsgs = (a ? a : ([ ]));
}

string schuffle(string agh) {
  string *poo;
  int s;
  s = sizeof(poo = explode(agh, "#"));
  while(s--) {
    if(poo[s] == "N")       poo[s] = capitalize((string)this_player()->query_real_name());
    else if(poo[s] == "P")  poo[s] = possessive(this_player());
    else if(poo[s] == "O")  poo[s] = objective(this_player());
    else if(poo[s] == "S")  poo[s] = subjective(this_player());
    else if(poo[s] == "T")  poo[s] = (string)Bob->query_name();
    else if(poo[s] == "TP") poo[s] = possessive(Bob);
    else if(poo[s] == "TO") poo[s] = objective(Bob);
    else if(poo[s] == "TS") poo[s] = subjective(Bob);
  }
    return implode(poo, "");
}  

status main(string arg) {
  string burp, nt;
  object Ob;

  Bob = 0;
  if(!arg) {
    if(nt = eMsgs["NTWrite"]) {
      write(nt);
      say(schuffle(eMsgs["NTSay"]));
        return 1;
    }
    write("Do that to whom?\n");
      return 1;
  }
  else {
    if(!(Ob = find_player(arg)) || Ob == this_player()) return 0;
    if(in_editor(Ob)) {
      write(capitalize(arg)+" is in editor.\n");
        return 1;
    }
    if((mixed)Ob->query_tellblock()) {
      write(capitalize(arg)+" has tellblock on.\n");
        return 1;
    }
    Bob = Ob;
    if(environment(Ob) != environment(this_player())) {
      if(burp = eMsgs["TWrite"]) {
        write(HIY+"(["+HIW+"afar"+HIY+"])"+NORM+" "+schuffle(burp));
        tell_object(Ob, HIY+"(["+HIW+"afar"+HIY+"])"+NORM+" "+schuffle(eMsgs["TTell"]));
          return 1;
      }
    }
    else {
      if(burp = eMsgs["TWrite"]) {
        write(schuffle(burp));
        say(schuffle(eMsgs["TSay"]), Ob);
        tell_object(Ob, schuffle(eMsgs["TTell"]));
          return 1;
      }
    }
  }
    return 1;
}

void load_targeted_msgs(string *heh) {
  if(!eMsgs) eMsgs = ([ ]);
  eMsgs["TWrite"] = heh[0];
  eMsgs["TSay"] = heh[1];
  eMsgs["TTell"] = heh[2];
}

void load_untargeted_msgs(string *heh) {
  if(!eMsgs) eMsgs = ([ ]);
  eMsgs["NTWrite"] = heh[0];
  eMsgs["NTSay"] = heh[1];
}
