short() {
    return "A obituary notice" ; }
long() {
    write("This is the daily obituary notice.\n\n");
    write("**note** exp does not show death penalty\n");
    tail ("/log/DEATHS"); }
init() {
    add_action("read","read"); }
id(str) {
    return str == "notice" || str == "paper" || str == "news"; }
read(str) {
    if (!id(str))
	return 0;
    say(call_other(this_player(), "query_name") + " reads the newspaper.\n");
    long();
    return 1; }
query_weight() { return 1; }
query_value() { return 5; }

