static specific(self, others, who, target) {
   string capt_name;
    who = present(lower_case(who), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    write(self + "\n");
    capt_name = call_other(this_player(), "query_name");
    tell_object(who, capt_name + " " + target + "\n");
    say(capt_name + " " + others + "\n", who);
    return 1;
}
 
