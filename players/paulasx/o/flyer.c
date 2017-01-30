
int ticket_number;

short() {
    return "A flyer about the Temple of Bishamon";
}

reset(arg) {
    if (!arg)
	ticket_number = random(1000) + 1000;
}

long(str) {
    if (!read(str))
        front();
}

front() {
    write("The flyer is printed on high-quality paper, and the front side says:\n");
    write("    +-------------------------------------------+\n" +
          "               Temple Of Bishamon                \n"+
          "           More monsters than you can kill\n" +
          "                        Go there NOW           \n" +
          "    \n" +
          "          Kill all your favorite monsters \n" +
          "              hurry..... be the first to kill\n" +
          "                See back for directions. \n" +
          "    +-------------------------------------------+\n");
    write("This flyer has number " + ticket_number + ".\n");
    write("There is something printed on the back side.\n");
} /* front */

back() {
    write("On the back side of the flyer there is a map:\n");
    write("    +-------------------------------------------+\n" +
              "                 Start at the Church\n" +
              "                  go s, then 9 west\n" + 
          "    +-------------------------------------------+\n");
} /* back */

init() {
    add_action("read", "read");
}

front_id(str) {
    return    str == "front" || str == "front side" || str == "frontside"
           || str == "front of ticket" || str == "front side of flyer";
}

back_id(str) {
    return    str == "back" || str == "back side" || str == "backside"
           || str == "back of ticket" || str == "back side of flyer"
           || str == "backside of ticket";
}

ticket_id(str) {
    return str == "flyer" || str == "castle flyer";
}

id(str) {
    return ticket_id(str) || front_id(str) || back_id(str);
}

read(str) {
    if (ticket_id(str) || front_id(str)) {
        front();
        return 1;
    }
    else if (back_id(str)) {
        back();
        return 1;
    }
    else
        return 0;
} /* read */

get() { return 1; }
query_weight() { return 1; }
query_value() { return 20; }

set_ticket_number(n) { ticket_number = n; }
query_ticket_number(n) { return ticket_number; }
