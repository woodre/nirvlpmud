inherit "room/room";

string messages;
int new_mail;

reset(arg) {
    if (arg)
	return;
    set_light(1);
     dest_dir=({ "players/bastion/guild/court4", "southwest" });
    short_desc = "The Guild Post Sub-station";
    long_desc = "You are in the guild's post office. Commands:\n" +
	"read         Read from the mailbox.\n" +
	"from         List all headers.\n";
    no_castle_flag = 1;
}

init() {
    ::init();
    move_object(clone_object("obj/mail_reader"), this_player());
    add_action("say");   add_verb("say");
     add_action("say"); add_xverb("\"");
    add_action("say"); add_xverb("'");
    add_action("say", "mail");
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
    if (!restore_object("closed/post_dir/" + name) || messages == "") return 0;
    if (silent) return 1;
    new = "";
    if (new_mail)
	new = " NEW";
    write("\nThere is" + new + " mail to you in the post office\n"+
        "   (south from village road).\n\n");
    return 1;
}
