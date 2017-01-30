
#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("tool");
  set_alias("vamptool");
  set_short("Vamp Tool");
  set_long("A tool for fixing vampires.\nCommands: formfix <player>\n");
}

void init() {
  add_action("cmd_formfix","formfix");
}

int cmd_formfix(string str) {
  object play,fangs;
  notify_fail("Usage: formfix <vampire>\n");
  if(!str) return 0;
  play=find_player(lower_case(str));
  if(!play) return 0;
  fangs=present("fangs",play);
  if(!fangs) {
    write("That person is not a vampire.\n");
    return 1;
  }
  if((int)fangs->query_levitating()) {
    fangs->stop_levitating();
    write("Levitation bug fixed.\n");
    tell_object(play,TPN+" has fixed your levitation bug.\n");
  }
  if((int)fangs->query_in_a_form()) {
    fangs->remove_form();
    write("Form bug fixed.\n");
    tell_object(play,TPN+" has fixed your form bug.\n");
  }
  write(capitalize(str)+" fixed.\n");
  tell_object(play,TPN+" has fixed your form bug.\n");
  return 1;
}
