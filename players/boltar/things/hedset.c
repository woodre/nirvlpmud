#include "/obj/clean.c"

int dmg;
 int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "The headset of mental contact";
}

query_value()
{
        return 212;
}

long()
{
 write("This headset looks very strange.  It is also attached to the wall.\n");
 write("Wear it and try to become someone.\n");
}

init() {
       add_action("wear","wear");
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "tv" || str == "headset";
}

get() {
   string whonme;
    if (call_other(this_player(), "query_name") != "Boltar") {
    write("The headset is attached to the wall. It would be unwise to remove it.\n");
        whonme = call_other(this_player(), "query_name", 0);
        say(whonme + " tried to steal the headset.\n");
        return 0;
    }
    return 1;
}
wear(arr){
   object ob;
   string str, set;
    if(!arr) return 0;
    sscanf(arr, "%s %s", set, str);
    if (set != "headset") {
    return 1;
}
    ob = find_player(str);
    if(!ob || ob->query_level() > 20) {
        write("The headset heats up, smoke comes out the ear pieces..\n");
        write(" It can't contact " + str + "\n");
        say("The headset realeases some somke into the room.\n");
     return 1;
     }
    write("\n\n");
   write("The headset warms up.........\n");
   write(" You become " + str + " for a moment.\n");
   write("\n\n");
    call_other(ob, "score", 0);
     write("\n\n");
    return 1;
}
