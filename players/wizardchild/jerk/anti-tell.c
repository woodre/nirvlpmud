string who;
set_who(str) {
        who = str;
        if(!find_player(who)) {
                who = "wizardchild";
                write("Player "+str+" not found. Default set.\n");                       
                return 1;
        } else {
                write("Player "+who+" set in.\n");
                return 1;
}        
}
short() {
        return "Anti-tell wiz device";
}
long() { short(); return 1; }
get() { return 1; }
drop() { return 1; }
id(str) { return str == "tell" || str == "device"; }
init() {
        add_action("tell", "tell");
}
tell(str) {
        string name, st;
        if(!who) who = "wizardchild";
        if(sscanf(str, "%s %s", name, st) == 2) {
                write("Fuck off man, "+name+" don't want to talk w/ u.\n");
                return 1;
        } else {
                ::tell(str);
                return 1;
        }
}
