/* Daemonized bag of marbles */
#define MASTER "/players/wizardchild/objects/mbagm.c"
short() {
        return "A bag of marbles";
}
long() {
        write("A bag of marbles (30). They can be used for many things....\n");
        return 1;
}
id(str) { 
        return str == "bag" || str == "bag of marbles" || str == "mmarbles";
}
get() { return 1; }
drop() { return 0; }
init() {
        add_action("load", "load");
        add_action("play", "play");
}
load(st) {
        MASTER->load(st);
        return 1;
}
query_player() {
        return this_player();
}
play(st) {
        MASTER->play(st);
        return 1;
}
query_caller() {
        return this_object();
}
