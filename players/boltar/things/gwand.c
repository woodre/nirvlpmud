#include "/obj/clean.c"

int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "A dark green wand";
}

query_value()
{
        return 35;
}

long()
{
    if (new_object) {
       write(new_long + "\n");
    return;
    }
    write("This wand looks special.\n");
}

init() {
       add_action("wave", "wave");
       add_action("spin", "spin");
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "wand" || str == "green wand";
}

spin(str) {
    if (str && !id(str))
        return 0;
    if (new_object)
        return 0;
write ("You see your body appear.\n");
write ("You are now visible.\n");
say(call_other(this_player(), "query_name") +
    " thinks he is visible now ().\n");
    return 1;
 }
wave(str) {
    if (str && !id(str))
        return 0;
    if (new_object)
        return 0;
write ("You see your body disappear.\n");
write ("You are now invisible.\n");
say(this_player()->query_name() + " waves a green wand.\n");
say(call_other(this_player(), "query_name") +
    " thinks he is invisible (play along please).\n");
    return 1;
}

get() {
    if (call_other(this_player(), "query_level") < 1) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
