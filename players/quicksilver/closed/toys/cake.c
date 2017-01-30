#include <ansi.h>
id(str) { return str == "cake"; }
short () {
   return "A wedding cake";
}
long() {
    write("It is a huge cake, easily the biggest you have ever seen.\n"+
          "There is a message written on the cake saying:\n"+BOLD+ 
          "    Congraduations Rizzo and Tina: Nirvana's Newest Couple!\n"+
          NONE);
}
get() { return 1; }
query_weight() { return -100; }
 
init() {    
    add_action("cut", "cut");
}
 
cut(str) {
    if (str != "cake") { return 0; }
    say(capitalize(this_player()->query_real_name()) + " cuts the cake.\n");
    write("You cut the cake.\n");
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    move_object(clone_object("players/quicksilver/piece.c"), environment(this_object()));
    destruct(this_object());
    return 1;
}
