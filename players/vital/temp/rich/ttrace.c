
string short_desc, long_desc, info;
int value, local_weight;
string name, alias_name, alt_name;
string read_msg;

id(str)
{
   return str == "trace" || str == "transporter trace" || str == "rich";
}

short() {
    return "A transporter trace";
}

long() {
    write("This is a transporter trace,its function is to beam you to safety\n");
    write("in case of an emergency.\n");
}

query_value() { return 500; }









get() {
    return 1;
}

query_weight() {
    return 2;
}

init() {
write("Sorry, this ain't legal.  - Maledicta\n"+
       "But feel free to gripe and say that the management is\n"+
       "trying to make the game boring.\n");
       destruct(this_object());
    add_action("trace", "trace");

}


trace() {
say(this_player()-> query_name() + " disappears in a blinding flash " +
              "of light and sound\n");
 write("You have a strange feeling...\n");
 write("You see your body from above...\n");
 write("You`re not dead...\n");
 write("Your trace transported you to safety.\n");
 move_object(this_player(),"players/rich/lower/atrans.c");
return 1;
 }
reset(arg) {}
