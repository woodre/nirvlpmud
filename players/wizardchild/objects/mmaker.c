int times;
short() {
        return "A marble maker";
}
long() {
        write("This is a semi-portable marble maker. If you wish, you\n");
        write("use your gold to make marbles with it. It seems to have\n");
        write("some information written on it, maybe you could 'read'.\n");
        return 1;
}
 
id(str) { return str == "marble maker" || str == "maker"; }
get() { return 1; }
drop() { return 0; }
init() {
        add_action("read", "read");
        add_action("make", "make");
}
read(st) {
        if(st != "maker" && st != "marble maker") return 0;
        write("This item works by typing 'make 30' (50 bags later)\n");
        write(". The cost is higher than that of buying them in a store,\n");
        write("but that is caused by this items inefficientness.\n");
        return 1;
}
make(st) {
        int cost;
        object ob;
        if(st != 30) return 0;
        cost = 60 * st;
        if(times > 5) {
                write("This item has made too many marbles, and is now broken.\n");
                destruct(this_object());
                return 1;
        }
        if(this_player()->query_money() < cost) {
                write("Whoah, check your cash man, you don't got "+cost+"\n");
                return 1;
        } 
        write("Ok, you pour your money in the marble maker and marbles\n");
        write("drip out the bottom into its own bag.\n");
        if(st == 30) {
                ob = clone_object("/players/wizardchild/objects/bm30.c");
        }
        this_player()->add_money(-cost);
        move_object(ob, this_player());
        times += 1;
        say(this_player()->query_name() + " makes some marbles.\n");
        return 1;
}                
query_value() {
        if(!times) return 1000; 
        return 500;
}
