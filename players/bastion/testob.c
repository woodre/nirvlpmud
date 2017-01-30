#define TEST 1000

id ( str ) { return str == "testob" || str == "test"; }

short () { return "a deamon test object"; }

long () { 
    write("What do you expect?\n");
}

init () { 
    add_action("test_nondaemon", "testnon");
    add_action("test_daemon", "testdaemon");
    add_action("my_fun", "dump");
}
   
test_nondaemon ( arg ) {
    int i;

    command("status", this_player());
    i = TEST;
    while ( i-- ) {
        move_object(clone_object("players/bastion/nondaemon"), 
                    environment(this_player()));
    }
    command("status", this_player());
    return 1;
}

test_daemon ( arg ) {
    int i;

    command("status", this_player());
    i = TEST;
    call_other("players/bastion/daemon", "???", 0);
    while ( i-- ) {
        move_object(clone_object("players/bastion/daemonob"), 
                    environment(this_player()));
    }
    command("status", this_player());
    return 1;
}

get () { return 1; }

my_fun ( arg ) {
    dumpallobj();
    write("OK.\n");
    return 1;
}
