inherit "room/room";

string messages;
int new_mail;

void reset(int arg) {
  if (arg)
    return;
  set_light(1);
  dest_dir = ({
    "room/narr_alley","north",
    "room/lanceroad2", "south"
  });
  short_desc = "The post office";
  long_desc = "You are in the post office. Commands:\n" +
              "read         Read from the mailbox.\n" +
              "mail <name>  Mail to player 'name'.\n" +
              "from         List all headers.\n";
  no_castle_flag = 1;
}

int no_light_damage() { return 1; }

void init() {
  ::init();
  move_object(clone_object("obj/mail_reader"), this_player());
  add_action("say", "say");
#ifndef __LDMUD__
  add_action("say"); add_xverb("\"");
  add_action("say"); add_xverb("'");
#else
  add_action("say", "\"", 3);
  add_action("say", "'", 3);
#endif
}

void exit() {
  object ob;

  if (ob = present("mailread", this_player()))
    destruct(ob);
}

int say() {
  write("Shhhhhhhhh! people are trying to read/write letters!\n");
  return 1;
}

int query_mail(int silent) {
  string name;
  string new;
  mixed *all;

  name = lower_case((string)this_player()->query_real_name());
  new = "";
  if (!restore_object("post_dir/" + name) || messages == "")
    return 0;
  if (silent)
    return 1 + new_mail;
  write("\nThere is " + (new_mail ? " NEW" : "") +
        " mail for you in the post office\n  (south from village road).\n\n");
  return 1;
}

int query_no_fight() { return 1; }

