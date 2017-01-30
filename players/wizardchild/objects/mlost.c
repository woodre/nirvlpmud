short() {
        return "A set of lost marbles";
}
long() {
        write("Some crazy guys lost marbles. Don't hold on to them too\n");
        write("long, they might send you over the edge too!\n");
        return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 450; }
id(str) { return str == "marbles" || str == "lost marbles"; }
