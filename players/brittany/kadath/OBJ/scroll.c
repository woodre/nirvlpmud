inherit "/obj/treasure";
int current_page;

reset()
{

current_page = 0;
}

short() { return  "A scroll"; }
 
long(str) {
    write("This is an old scroll, the edges have burn marks around them.\n");
    write("The title is:  'The lost box', maybe you should 'read' it.\n");
set_weight(1);
}
 
init() {
   add_action("read_scroll"); add_verb("read");
   add_action("open"); add_verb("open");
}
 
id(str) { return str == "scroll" || str == "scroll"; }

open(str) {
    if (!id(str))
        return 0;
    if (current_page > 0) {
        write("The scroll is already open at page " + current_page + ".\n");
        return 1;
    }
    current_page = 1;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) +
        " rolls the scroll to read it.\n");
    return 1;
}
read_scroll(str)
{
    if (!id(str) && str != "page")
        return 0;
    if (current_page == 0) {
        write("It is closed.\n");
        return 1;
    }
   if (current_page == 1){
        cat("/players/brittany/kadath/OBJ/scrread");
   return 1; }
}
