inherit "room/room";

string messages;
int new_mail;

reset(arg) {
    if (arg)
	return;
    set_light(1);
     dest_dir =({"room/narr_alley","north","room/lanceroad2", "south" });
    short_desc="Haven's Post Office";
    long_desc = "You are in the post office. Commands:\n" +
	"read         Read from the mailbox.\n" +
	"mail <name>  Mail to player 'name'.\n" +
	"from         List all headers.\n";
    no_castle_flag = 1;
}

init() {
    ::init();
    {
      object reader;
      reader=clone_object("obj/mail_reader");
      reader->seteuid(0);
      move_object(reader,this_player());
    }
    add_action("say","say");
#ifndef __LDMUD__
    add_action("say"); add_xverb("\"");
    add_action("say"); add_xverb("'");
#else
    add_action("say","\"",3);
    add_action("say","'",3);
#endif
}

exit() {
    object ob;
    if (ob = present("mailread", this_player()))
	destruct(ob);
}
say() {
   write("Shhhhhhhhh! people are trying to read/write letters!\n");
   return 1;
}

query_mail(silent) {
    string name;
    string new;

    name = lower_case(call_other(this_player(), "query_real_name"));
    if (!restore_object("post_dir/" + name) || messages == "") return 0;
    if (silent) return 1;
    new = "";
    if (new_mail)
	new = " NEW";
    write("\nThere is" + new + " mail to you in the post office\n"+
        "   (south from village road).\n\n");
    return 1;
}
query_no_fight() { return 1; }
