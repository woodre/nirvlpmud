static general(self, others) {
    string capt_name;
    if (ghost())
        return 0;
    write(self + "\n");
    capt_name = call_other(this_player(), "query_name");
    say(capt_name + " " + others + "\n");
    return 1;
}
 
