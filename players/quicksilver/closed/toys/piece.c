inherit "obj/treasure";
id(str) { return str == "piece"; }
short () {
   return "A piece of wedding cake";
}
long() {
    write("It is a delicious looking piece of cake.  Eat it.  :]\n");
}
 

init() {    
    add_action("eat", "eat");
}
 
eat(str) {
    if (str != "cake") { return 0; }
write(regmatch("abcdefcdf", "cd"));
    say(capitalize(this_player()->query_real_name()) + " eats a piece of cake.\n");
    write("You eat a piece cake.  It is delicious.\n");
    destruct(this_object());
    return 1;
}
