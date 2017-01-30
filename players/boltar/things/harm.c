
int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "A blues harmonica";
}

query_value()
{
        return 212;
}

long()
{
    if (new_object) {
       write(new_long + "\n");
    return;
    }
    write("A great sounding instrument.\n");
}

init() {
       add_action("play", "play");
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "harmonica" || str == "blues harmonica";
}

play(str) {
    if (str && !id(str))
        return 0;
    if (new_object)
        return 0;
write ("You press the harmonica to your lips.\n");
write ("You play your favorite song.\n");
say(call_other(this_player(), "query_name") +
    " plays the blues on the harmonica.\n");
    return 1;
}

get() {
    if (call_other(this_player(), "query_level") < 1) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
