#include "/players/guilds/bards/def.h"


string format_text(string text) {
  int x;
  string *strings;
  text=format(text,50);
  strings=explode(text,"\n");
  for(x=0;x<sizeof(strings);x++)
    strings[x]= "* "+strings[x];
  return implode(strings,"\n");
}

status main(string str) {
  object ob;
  string target, temp, text;
  string str1;

  if (!str)
    FAIL("Illusions need targets and content.\n");
  if (sscanf(str, "%s %s", temp, text) != 2)
    FAIL("Illusions need targets and content.\n");
  
  if( sscanf(text, "%s.",str1) ) text=str1;

  text=format_text(text);
  if (spell(-194, 7, 40) == -1)
    return 0;
  if (temp == "here") {
    ob=clone_object(OBJ+"ill_obj");
    move_object(ob, environment(TP));
    call_other(ob, "set_short", text);
    write("You sing a soft song.\n");
    write("You create an illusion:\n");
    write(text+".\n");
    say(tp + " sings a soft song.\n");
    say("Something has changed.\n");
    call_other(TP, "add_spell_point", -40);
    return 1;
  } else {
    ob = find_player(temp);
    if (!ob || ((int)ob->query_level() >= 20 && (int)TP->query_level() <20 )) {
      write("That player is not within the realm of magic.\n");
      return 1;
    }
    say(tp + " sings a soft song.\n");
    write("You sing a soft song as you send an illusion to " +
        NAME(ob) + ":\n" + text + ".\n\n");
    tell_object(ob, "You see an illusion.\n\n");
    tell_object(ob, text + ".\n\n");
    call_other(TP, "add_spell_point", -40);
    return 1;
  }
}
