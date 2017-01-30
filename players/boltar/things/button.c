#include "/obj/clean.c"

int new_object;
int x, val;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "A small push button switch";
}

query_value()
{
  val = 200 - (66 * x);
        return val;
}

long()
{
    if (new_object) {
       write(new_long + "\n");
    return;
    }
    write("The switch case is clear. You can see the inner workings.\n");
    write("It seems to be made to work only three times. \n");
    write("It has been used " + x + " times.\n");
}

init() {
       add_action("push","push");
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "button" || str == "switch";
}


get() {
    if (call_other(this_player(), "query_level") < 1) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
push(str) {
 string plynam;
 if (str !="button") {
  write("push what?\n");
 return 1;
}
 if (call_other(environment(this_player()), "realm", 0) == "NT") {
    write("The switch begins to get very hot.\n");
    write("The switch disappears in a bright flash of green light.");
    write("\n");
    destruct(this_object());
return 1;
}
 write("You are magically transported somewhere.\n");
  plynam = call_other(this_player(), "query_name", 0);
  say(plynam + " pushes a button on some small device.\n");
  say(plynam + " vanishes in a bright flash of green light.\n");
 move_object(this_player(), "players/boltar/lv2/shop.c");
 x += 1;
 if (x == 3) {
   write("You are out of charges.\n");
   write("The button disappears.\n");
   destruct(this_object());
  return 1;
}
 return 1;
}
