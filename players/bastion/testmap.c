inherit "/open/mapping.c";

mapping mymap;
mixed *mymap_save; /* vomit */

id ( str ) { return str == "testmap" || str == "test"; }

get () { return 1; }

short () { return "a map tester"; }

long () { write("Use 'testsave' to work it.\n"); }

init () { 
    add_action("test_save", "testsave");
    add_action("test_restore", "testrestore");
}

test_save ( arg ) {
    mymap = ([ "bing1" : 1, 666 : "satan", "foo" : "bar" ]);
    mymap_save = deconstruct_mapping(mymap);
    save_object("players/bastion/testmap");
    return 1;
}

test_restore ( arg ) {
    restore_object("players/bastion/testmap");
    mymap = reconstruct_mapping(mymap_save);
    write(mymap["bing1"] + "\n");
    write(mymap[666] + "\n");
    write(mymap["foo"] + "\n");
    write("Array was " + (sizeof(mymap_save) ? "not " : "") + "cleared.\n");
    write(mymap_save[0] + "\n");
    write("OK.\n");
    return 1;
}

