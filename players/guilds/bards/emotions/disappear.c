#include "/players/guilds/bards/def.h"

status main(string str){
  object ob;
  
  if (!str) {
    write
    ("You mutter a brief incantation, and momentarily cloak yourself in invisibility.\n");
    say(tp + " disappears in a puff of blue smoke.\n");
    call_out("reappear",1,({TP,ENV}));
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) FAIL("Who do you want to make disappear?\n");
  write("You incant sharply and point at " + CAP + ", binding " +
    ob->query_objective() + "\n" +
  "with a momentary cloak of invisibility.\n");
  say(tp + " incants sharply and points at " + CAP + ".\n" +
    PRON(ob)+ " disappears in a puff of blue smoke!\n", ob);
  tell_object(ob,
    tp + " incants sharply and points at you.\n" +
    "A puff of blue smoke momentarily blinds you.\n");
  call_out("reappear",1,({ob,ENV}));
  return 1;
}

void reappear(object *obs) {
  object who,where;
  who=obs[0];
  where=obs[1];
  if(!who || !where || !environment(who) || environment(who) != where)
    return;
  tell_object(who,"After only a moment, you reappear.\n");
  tell_room(where,NAME(who)+" quickly reappears.\n",({who}));
}
