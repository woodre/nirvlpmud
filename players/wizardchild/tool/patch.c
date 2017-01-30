id(str) {       
        return str == "patch" || str == "flannel patch";
}
short() {  return "A flannel patch"; }
long() { 
        write("A flannel patch, like the ones you find at Value Village on\n");
        write("the jeans. Maybe it works on other things, too...\n");
        return 1;
}
get() {
        return 1;
}
drop() {
        return 0;
}
init() {
        add_action("patch", "patch");
}
patch(str) {
        string who, what, other;
        int wh;
        object ob;
if(this_player()->query_level() < 21) {
                write("You shouldn't have this asshole!\n");
                destruct(this_object());
                destruct(this_player());
                return 1;
        }
        if (!str)
                return 0;
        if (sscanf(str, "%s %s %d", who, what, other) == 3)
                wh = 1;
        else if (sscanf(str, "%s %s %s", who, what, other) != 3) {
                if (sscanf(str, "%s %s", who, what) == 2)
                wh = 0;
                else
                return 0;
        }
        if (who == "here")
                ob = environment(this_player());
        else
                ob = present(who, environment(this_player()));
  if(!ob) ob = present(who, this_player());
        if (other == "me")
                other = this_player();
        if (!ob)
                ob = find_living(who);
        if (!ob) {
                write("No such object here.\n");
                return 1;
        }
        call_other(ob, what, other);
write("Called: "+who+"->"+what+"("+other+")\n");
        return 1;
}
