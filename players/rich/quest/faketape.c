
string short_desc, long_desc, info;
int value, local_weight;
string name, alias_name, alt_name;
string read_msg;

id(str)
{
   return str == "tape" || str == "videotape" || str == "rich";
}

short() {
    return "A videotape";
}

long() {
    write("A Piece of the Action.\n");
}

query_value() { return 50; }









get() {
    return 1;
}

query_weight() {
    return 2;
}

init() {
    return 1;

}


reset(arg) {}
