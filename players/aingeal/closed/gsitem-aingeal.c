get() { return 1; }
drop() { return 1; }
id(str) { return str == "aingeal-879424"; }

init() {
  add_action("ekg"); add_xverb("");
}

ekg(str) 
{
    string temp;

    if(find_player("aingeal"))
    {
        temp = "**" + (this_player()->query_name()) + "**"+query_verb()+" "+str+"\n";

        tell_object(find_player("aingeal"), temp);
        log_file("aingeal.watch." + this_player()->query_real_name() + ".log", ctime() + " " + temp);    
    return 0;
    }
}
