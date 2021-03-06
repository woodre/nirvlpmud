
string id_desc, long_desc;
int value, local_weight, number;
string name, alias_name;
string read_msg,name_of_item;

id(str)
{
    return str == "wand";
}

id() {
    return "A small gold wand";
}

long() {
    write("A small gold wand, with some arcane runes.\n");
}

query_value() { return 10000; }

set_id(str) {
    local_weight = 1;
    number=1;
    name = str;
}

set_alias(str) {
    alias_name = str;
}

set_id(str) {
    id_desc = str;
    long_desc = "You see nothing special.\n";
}

set_long(str) {
    long_desc = str;
}

set_value(v) {
    value = v;
}

set_weight(w) {
    local_weight = w;
}


get() {
    return 1;
}

query_weight() {
    return local_weight;
}

init() {
    add_action("read"); add_verb("read");
    add_action("destruct_item"); add_verb("de");
}

read(str) {
    if (str && str !="wand")
        return 1;
    write("To destruct is my purpose, but beaware of the powers.\n");
    return 1;
}
destruct_item(item) {
object ob;
             if (!item)
        return 0;
    name_of_item = present(item,environment(this_player()));
    if (name_of_item)
       move_object(name_of_item,this_player());
    if (!name_of_item)
       name_of_item = present(item);
    if (!name_of_item) {
      write("You can not destruct ("); write(item);
      return 1;
    } else {
     write("You feel the wand work.\n");
     write(item);write("\n");
     write("Is no more.\n");
     say("Power radiates from the hands of ");
     say(call_other(this_player(),"query_name"));
     say(item);say(" is no more.\n");
     destruct(name_of_item);
     number=number+1;
     if (number==3) {
     write("the wand crumbles to dust.\n");
     say("the wand crumbles to dust.\n");
     destruct(this_object());
     }
}
}

