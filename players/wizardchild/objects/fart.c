short() {
        return "A fart";
}
long() {
        write("A fart. It was somehow preserved from an old fart. You\n");
        write("could 'stinky <player>' to make someone REALLY mad...\n");
        return 1;
}
get() { return 1; }
drop() { return 0; }
id(str) { return str == "fart"; }
init() {
        add_action("stinky", "stinky");
}
stinky(pl) {
        if(!pl || pl == "") return 0;
        if(!find_player(pl)) {
                write("And just where the hell is that person?\n");
                return 1;
        }
        tell_object(find_player(pl), "You notice a faint odor in the air. It is");
        tell_object(find_player(pl), "becoming VERY unpleasant.\n");        
        tell_object(environment(find_player(pl)), pl+" cuts a stinky!!! NASTY!!\n");
        tell_object(find_player(pl), "You better kill the fucker who did this!!!\n");
        write("Good going man!! You sent that boy a stinky!\n");
        return 1;
}
query_value() {
        return 600;
}
