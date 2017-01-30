query_value() {
     return 0; }
id(str) {
     return str == "A dark disk" || str == "disk"; }
long() {
     write("The disk appears to be a solid black,  but as you hold it up to\n");
     write("the light,  you are able to make out some writing...\n"); }
short() {
     return "A fragile disk"; }
get() {
     return 1; }
read(str) {
     if (str == "disk") {
        write(" \n");
        write(" \n");
        write("    This is a very special disk.  A scientist has been looking\n");
        write("    for this disk for some time now.  \n\n");
        write("    Find the Golden One and you may find a way to heal your\n");
        write("    troubles.  You must search carefully though,  for all is\n");
        write("    not as it seems.\n");
        write("\n\n");
        return 1; }
     return 0; }
dump(str) {
     if (str == "disk" || str == "all") {
        write("Unfortunately for you,  the disk is VERY fragile.  You\n");
        write("have erred in dropping the disk.  It splits into two mighty\n");
        write("pieces.  The pieces look almost alive as the shimmer and fade.\n");
        say(call_other(this_player(),"query_name") + " dropped the disk.\n");
        say("The disk splits in two and fades away.\n");
        destruct(this_object());
        return 1; }
    return 0; }
init() {
     add_action("dump","drop");
     add_action("read","read");
}
