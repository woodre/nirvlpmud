#include "/obj/clean.c"

int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "A new years' party favor";
}

query_value()
{
        return 2;
}

long()
{
    if (new_object) {
       write(new_long + "\n");
    return;
    }
    write("A great sounding instrument.\n");
     write("You can blow into it.\n");
}

init() {
       add_action("blow", "blow");
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "favor" || str == "party favor";
}

blow(str) {
    if (str && !id(str))
        return 0;
    if (new_object)
        return 0;
  write ("You blow into the party favor.\n");
  write ("Happy New Year!!!!!\n");
  write ("\n");
say(call_other(this_player(), "query_name") +
   " makes noise using a party favor.\n" +
/*
   "  \n"+
   "         \n"+
*/
   "HAPPY NEW YEAR!!!!!!\n");
    return 1;
}

get() {
    if (call_other(this_player(), "query_level") < 1) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
