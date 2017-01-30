inherit "room/room";
#include "../DEFS.h"

string messages;
int new_mail;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = FUNKYNAME+" Mailroom";
  long_desc =  "The "+FUNKYNAME+" Mailroom. Any "+FUNKYNAME+" who wishes may\n"+
               "choose to 'attach' to one of the mail processors.\n";
  dest_dir = ({
    ROOMDIR + "/teleport","ninja"
  });
}

init() {
  ::init();
  if(!IPTP && ((int)this_player()->query_level() <= 20)) {
    write("An unseen force blocks your progress!\n");
    move_object(this_player(), "room/church");
    call_other(this_player(), "glance");
  }
  add_action("attach_mail","attach");
}

exit() {
  object ob;
  if (ob = present("mailread", this_player())) destruct(ob);
}

attach_mail() {
  if(!present("mailread", this_player())) {
    write("Having attached yourself to the\n"+
          "CyberMail Terminal, you may:\n"+
          "  read\n"+
          "  mail <player>\n"+
          "  or check mail with 'from'.\n");
    move_object(clone_object("obj/mail_reader"), this_player());
    return 1; 
    }
  write("You are already attached to CyberMail.\n");
  return 1;
}
