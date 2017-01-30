status mail;
object ob;

id(str){ return str == "mailbox"; }

short(){ return "A portable mailbox"; }

long(){
    write("Why go to the post office when you can take it with you?\n");
    write("Commands:\n");
    write("xmailer - fire up the magical remote mailbox\n");
    write("      read - read your mail
    write("      mail <who> - Toasts your toast\n");
    write("unmailer - shut down the magical remote mailbox\n");
}

init(){
    add_action("xmailer", "xmailer");
    add_action("unmail", "unmailer");
    if(mail == 1){
        add_action("nope", "w");
        add_action("nope", "e");
        add_action("nope", "s");
        add_action("nope", "n");
    }
}

nope(){
    write("You forgot to close the mailbox before leaving.  Try 'unmailer'.\n");
    return 1;
}

xmailer(){
    ob = clone_object("obj/mail_reader");
    move_object(ob, this_player());
    write("You have been magically enabled to send mail from afar.\n");
    return 1;
}

unmail(){
    destruct(ob);
    write("You shut the mailbox down.\n");
    return 1;
}
