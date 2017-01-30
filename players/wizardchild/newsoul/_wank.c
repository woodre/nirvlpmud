#include "/bin/ghost.c"
inherit "/players/wizardchild/newsoul/gender.c";

#pragma strict_types
#pragma save_types

int cmd_wank(string str) {
  object who;
  if(ghost()) {

    write("God didn't intend for ghosts to wank off.\n");
    return 1;
  }
  if(!str) {
    write("You wank and wank all over the room while grinning like a chimp.\n");
    say(this_player()->query_name()+" wanks and wanks all over the room while grinning like a chimp.\n");
    return 1;
  }
  who=present(str,environment(this_player()));
  if(who && living(who)) {
    if(who == this_player()) {
      write("You wank and wank all over yourself while grinning like a chimp.\n");
      say(this_player()->query_name()+" wanks and wanks all over "+noun()+"self while grinning like a chimp.\n");
      return 1;
    }
    write("You wank and wank all over "+who->query_name()+" while grinning like a chimp.\n");
    tell_object(who,this_player()->query_name()+" wanks and wanks all over you while grinning like a chimp.\n");
    say(this_player()->query_name()+" wanks and wanks all over "+who->query_name()+" while grinning like a chimp.\n",who);
    return 1;
  } else {
    who = find_player(str);
    if(!who || who->query_invis() >= 20) {
      write("That player is not logged in.\n");
      return 1;
    }
    if(in_editor(who) || who == this_player()) {
      write("That player is not available.\n");
      return 1;
    }
    tell_object(who,"From afar, "+this_player()->query_name()+" wanks and wanks all over you while grinning like a chimp.\n");
    write("From afar, You wank and wank all over "+who->query_name()+" while grinning like a chimp.\n");
    return 1;
  }
}
