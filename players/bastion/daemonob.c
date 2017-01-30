#define MASTER "players/bastion/daemon"

string name, title;
int experience, level;

reset ( arg ) {
    name  = this_player()->query_name();
    title = this_player()->query_title();
    level = this_player()->query_level();
}

init () {
    add_action("fun1", "test");
    add_action("fun2", "test");
    add_action("fun3", "test");
    add_action("fun4", "test");
}

fun1 ( arg ) {
    return MASTER->fun1(arg);
}

fun2 ( arg ) {
    return MASTER->fun2(arg);
}

fun3 ( arg ) {
    return MASTER->fun3(arg);
}

fun4 ( arg ) {
    return MASTER->fun4(arg);
}

heart_beat () {
    return MASTER->heart_beat();
}

bullshit_fun ( arg ) {
    return MASTER->bullshit_fun();
}

