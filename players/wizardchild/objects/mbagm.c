/* Master bag of marbles for bm30.c - Daemonized */
#define SLAVE "/players/wizardchild/objects/bm30.c"
#define this_player() SLAVE->query_player()
int check;
reset() {
        move_object(this_object(), "/players/wizardchild/workroom.c");
}
init() {
        check = 1;
}
id(str) { return str == "master" || str == "master object"; }
short() { return "A master daemonized object (bm30.c)"; }
long() {
        write("A master daemonized object. This object is for a bag\n");
        write("of marbles (30) [file = players/wizardchild/objects/bm30.c]\n");
        return 1;
}
get() { return 0; }
load(st) {
        string empty, loaded, bag, big_bag;
        object new, is_there, bag_there;
        if(st != "marbles" && st != "gun") return 0;
        empty = "marble gun";
        is_there = present(empty, this_player());
        big_bag = "/players/wizardchild/objects/bm50.c";
        if(file_name(is_there) == big_bag) return 0;
        bag = "mmarbles";
        bag_there = present(bag, this_player());
        if(bag_there && is_there) {
                new = clone_object("/players/wizardchild/objects/mgun30.c");
                move_object(new, this_player());
                destruct(bag_there);
                destruct(is_there);
                tell_object(this_player(), "You are loaded up and ready to fire!\n");
                tell_object(environment(this_player()), this_player()->query_name());
                tell_object(environment(this_player()), " loads up his marble gun.\n");
                return 1;
        }
        if(bag_there && !is_there) {
                write("You have no gun!\n");
                return 1;
        }
        if(!bag_there) {
                write("You have no marbles!\n");
                return 1;
        }
        return 1;
}
 
play(st) {
        if(!st || st == "") return 0;
        if(st == "with marbles" || st == "marbles") {
		write("You sit down on the ground and try to figure out how\n");
                write("one is supposed to play with marbles.\n");
                say(this_player()->query_name() + " plays with a set of marbles.\n");
                return 1;
        } else {
                return 0;
        }
}
