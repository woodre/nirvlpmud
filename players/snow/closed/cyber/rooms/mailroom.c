inherit "room/room";

string messages;
int new_mail;

reset(arg) {
    if (arg)
	return;
    set_light(1);
  dest_dir = ({"players/snow/closed/cyber/rooms/teleport","ninja"});
  short_desc = "CyberNinja Mailroom";
  long_desc = "The CyberNinja Mailroom. Any CyberNinja who wishes may\n"+
              "choose to 'attach' to one of the mail processors.\n";
}

init() {
    ::init();
  if(!present("CyberNinja Implants", this_player()) &&
    this_player()->query_level() <= 20) {
    write("A CyberNinja ForceShield blocks your progress!\n");
    move_object(this_player(), "room/church");
    command("look", this_player());
    }
  add_action("attach_mail","attach");
}

exit() {
    object ob;
    if (ob = present("mailread", this_player()))
	destruct(ob);
}

attach_mail() {
  if(!present("mailread", this_player())) {
  write("You attach yourself to a CyberMail Converter. Now you may:\n"+
        "  read, mail <player>, or check mail with 'from'.\n");
  move_object(clone_object("obj/mail_reader"), this_player());
  return 1; }
  write("You are already attached to the CyberMail system.\n");
  return 1;
}
