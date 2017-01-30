id(str) { return str == "kitten"; }
short() { return "A small frightened kitten"; }
long() { write("The kitten is very small and fluffy.\n");
         write("It is grey with white spots.\n");
         write("It would be nice of you to 'pet' it.\n"); }
get() { return 1; }
init() {
         add_action("pet","pet");
}
pet() {
     say(this_player()->query_name() + " pets the little kitten.\n");
     say("Purrrrrrrrrrrrrrrrr\n");
     write("You pet the frightened kitten.\n");
     write("Purrrrrrrrrrrrrrrrrrr");
     write("\n");
     return 1;
}
