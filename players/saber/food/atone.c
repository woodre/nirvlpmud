int full;
int temp;

id(str) {
    if (str == "potion" && full)
	return 1;
    return str == "bottle";
}

short() {
    if (full)
     return "A potion of atonement";
    return "An empty bottle";
}

/* The shop only buys empty bottles ! */

query_value()
{
    if (!full) return 5;
    return 7000;
}

long() {
    write(short() + ".\n");
}

reset(arg) {
    if (arg)
        return;
    full = 1;
}

drink(str)
{
    if (str && str != "potion" && str != "from potion")
	return 0;
    if (!full)
	return 0;
    full = 0;
   write("You drink a potion of atonement.\n"+
      "Your soul feels lighter.\n");
  temp = this_player()->query_alignment();
  if(temp < 0) temp = 0;
  temp = temp + random(400);
     if(temp > 1000) temp = 5;
    say(call_other(this_player(), "query_name", 0) +
     " drinks a potion.\n");
   call_other(this_player(), "add_alignment", temp);
    return 1;
}

init() {
    add_action("drink","drink");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
