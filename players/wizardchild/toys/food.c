string name;
string messeat;
string short;
string long;
 
id(str) {
        if(str == "gorp" || str == "food" || str == name) return 1;
}
get() { 
        return 1;
}
drop() {
        return 0;
}
init() {
/*
        add_action("messeat", "messeat");
        add_action("shortm", "short");
        add_action("name", "name");
*/
        add_action("longm", "long");
        add_action("eat", "eat");
        add_action("wha", "wha");
}
messeat(ms) {
        if(!ms) return 0;
        messeat = ms;
        write("Message = " + messeat + ".\n");
        return 1;
}
shortm(shrt) {
        if(!shrt) return 0;
        short = shrt;
        write("Short = " + short + ".\n");
        return 1;
}
name(nm) {
        if(!nm) return 0;
        name = nm;
        write("Name = " + name + ".\n");
        return 1;
}
longm(lng) {
        if(!lng) return 0;
        long = lng;
        write("Long = " + long + ".\n");
        return 1;
}
short() {
        if(!short) {
                return "A pile of gorp";
        } else {
                return short;
        }
}
wha() {
  /* I */
  write("Descriptions manipulation removed due to player abuse.\n");
 /* End additions.    Mizan */
        write("Long = " + long + ".\n");
        write("Short = " + short + ".\n");
        write("Name = " + name + ".\n");
        write("Message = " + messeat + ".\n");
        return 1;
}
long() {
        if(!long) {
                write("No long desc given. Use 'long <str>' to set.\n");
                write("Type 'wha' to see the alterable stats.\n");
                return 1;
        } else {
                write(long + "\n");
                return 1;
        }
}
 
eat(str) {
        if(!str) {
                write("Eat what?\n");
                return 0;
        }
        if(!messeat) {
                write("Yum Yum Yummie! That " + name + " was great!\n");
        } else {
                write(messeat + ".\n");
        }
        say(call_other(this_player(), "query_name") + " eats some " + name + ".\n");
        destruct(this_object());
        return 1;
}
