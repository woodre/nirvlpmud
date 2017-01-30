#include "../defs.h"

/* Global Variables */
status Dsight;


string short() {
  if (this_player() != environment() && (environment(this_player()) != environment(environment(this_object()))))
    tell_object(environment(), HIC+capitalize((string)this_player()->query_real_name()) + " just scanned your inventory.\n"+NORM+NORM);
  return "A "+HIB+"Frosty"+NORM+NORM+" shot glass";
}

void long() { 
  write("This is a frost covered shot glass that contains Rumplemintz.\n");
  write("He is made of liquid afterall, and needs some mode of containment.\n");
}

status id(string str) { 
  if (str == "dark_sight_object")
    return Dsight;

  return (str == "tool" || str == "glass" || str == "shot glass");
}

int infra(string arg) {

  if (!arg || (arg != "on" && arg != "off"))
  {
    write("Darksight is turned "+(Dsight ? "on" : "off")+".\n");
    return 1;
  }

  write("Darksight is now ");

  if (arg == "on")
  {
    write("on.\n");
    Dsight = 1;
    return 1;
  }

  write("off.\n");
  Dsight = 0;
  return 1;
}

int get() { return 1; }
int drop() { return 1; }

int do_command(string arg) {
  return (int)call_other(BIN+query_verb(),"main",arg);
}

int rumpd_command(string arg) {
  return (int)call_other(RUMPD,"initialize_commands");
}

int do_patch(string arg) {
  string who, what, how;

  if (sscanf(arg,"%s, %s, %s",who,what,how) == 3)
    call_other(BIN+"patch.c","main",who,what,how);
  else if (sscanf(arg,"%s,%s,%s",who,what,how) == 3)
    call_other(BIN+"patch.c","main",who,what,how);
  else if (sscanf(arg,"%s,%s",who,what) == 2)
    call_other(BIN+"patch.c","main",who,what,"");
  else if (sscanf(arg,"%s, %s",who,what) == 2)
    call_other(BIN+"patch.c","main",who,what,"");
  else
    write("Bad syntax: p <who>,<function>,<arg>\n");
  return 1;
}
int do_wwho(string arg) {
  call_other("/players/rumplemintz/closed/jar","ww");
  return 1;
}
void init() { 
  int i, siz;
  object ob, qt;
  string *temp;

 if ((string)this_player()->query_real_name() != "rumplemintz"
  && (string)this_player()->query_real_name() != "rump")
  {
    write("Don't clone this.\n");
    remove_interactive(this_player());
    destruct(this_object());
    return;
  }

  ob = clone_object("/players/rumplemintz/closed/obj/qt_shadow.c");
  qt = this_player();
  ob->init_qt_shadow(qt);

  siz = sizeof(temp = get_dir(BIN));

  for (i = 0; i < siz; i++)
    if (sscanf(temp[i],"%s.c",temp[i]) == 1)
      add_action("do_command",temp[i]);

  add_action("infra", "infra");
  add_action("infra", "dsight");
  add_action("rumpd_command","init");
}

void reset(status arg) {
  if (arg)
    return;

  Dsight = 1;
}
