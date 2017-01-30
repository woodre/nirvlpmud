

short()
{
     return "An emoter";
}

query_value()
{
        return 10;
}

  query_weight() {   return 1; }
long()
{
   write("A emoter. just type 'z message' and everybody in the room will see\n"+
   "your name message\n");
}

init() {
     add_action("z","z");
}

id(str) {
    return str == "emoter" || str == "An emoter";
}

z(str) {
say(call_other(this_player(), "query_name") +
    " " + str + "\n");
write("you emote: " + call_other(this_player(), "query_name") + " " + str + "\n");
    return 1;
}

get() {
      write("The emoter feels magical.\n");
    return 1;
}
