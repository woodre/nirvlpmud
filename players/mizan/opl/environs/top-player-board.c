
short() 
{
    return "The Proving Grounds high score chart" ;
}

long() 
{
    cat("/players/mizan/opl/data/top_players.txt");
}

init() 
{
add_action("read", "read");
}

id(str) 
{
    return str == "chart" || str == "top" || str == "top players" ||
        str == "chart of top players" || str == "top list";
}

read(str) 
{
    if (!id(str)) return 0;
    say(call_other(this_player(), "query_name") + " reads the high score chart.\n");
    long();
    return 1;
}

get() { return 0; }
