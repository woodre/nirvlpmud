#include <ansi.h>

object shadow_me(object who){
    shadow(who, 1);
}

object unshadow_me(object who){
    shadow(who, 0);
}

string short(){
    string *s;
    int sz;
    s = ({
      HIW+"Rumplemintz "+NORM+"the "+HIG+"Druid Guild "+NORM+"Master",
      this_player()->query_name()+" is looking at Rumplemintz",
      "Rumplemintz says: Hello "+this_player()->query_name()+"!",
      "R u m p l e m i n t z",
      ".o0O -= Rumplemintz =- O0o.",
      "Rumplemintz is too cool to be a woman (manly man)",
      "Rumplemintz is better than "+this_player()->query_name(),
      "Rumplemintz of the many titles",
      "Have you sent a dollar to Rumplemintz today? ($$$)",
      "              --rump",
      "this_player()->query_real_name() { return \"Rumplemintz\"; } /"+"* me */",
      "Your sensitive mind notices a Rumplemintz in the fabric of space.",
      this_player()->query_pretitle()+" Rumplemintz "+this_player()->query_title()+" ("+this_player()->query_align_title()+")",
      "\b\b\b\b\b\b\b\b\b\b[Rumplemintz] ;)",
      "Rumplemintz says:  Beep me if it's not important!",
    });
    sz = sizeof(s);
    return s[random(sz)];
}
