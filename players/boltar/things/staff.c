
int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
     if (new_object)
        return new_short;
     return "The staff of death";
}

query_value()
{
     if (new_object)
        return new_value;
     return 0;
}

long()
{
    if (new_object) {
       write(new_long + "\n");
    return;
    }
    write("It is a six foot staff made of redwood.\n");
    write("This belongs to Boltar, do not touch.\n");
    write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    write("You can't use it.\n");
}

init() {
    if (!new_object && call_other(this_player(), "query_level") >= CREATE) {
       add_action("silence", "silence");
       add_action("spin", "spin");
       add_action("fetch", "fetch");
       add_action("low_remove", "low_remove");
       add_action("destr", "destr");
       add_action("rem_room", "rem_room");
       add_action("crash", "crash");
       add_action("trace", "trace");
       add_action("remove", "remove");
       add_action("find", "find");
       add_action("patch", "patch");
#ifndef __LDMUD__
       add_action("echo"); add_xverb("$");
#else
       add_action("echo", "$", 3);
#endif
   }
}

id(str) {
    if (new_object)
        return str == new_name;
    return str == "staff" || str == "staff of death";
}

spin(str) {
    if (str && !id(str))
        return 0;
    if (new_object)
        return 0;
write ("The staff glows brightly.\n");
write ("You can create a new object.\n");
if (call_other(this_player(), "query_level") < 36) {
    write("Something has gone wrong.\n");
    return 1;
}
write("Give the name of the object: ");
say(call_other(this_player(), "query_name") +
    " spins the staff of death.\n");
input_to("set_new_name");
return 1;
}

set_new_name(str) {
    if (str == "") {
       write("Aborted\n");
    }
    new_name = lower_case(str);
    write("Give short disc: ");
    input_to("set_new_short");
}

set_new_short(str) {
    if (str == "") {
       write("Aborted\n");
    }
    new_short = str;
    write("Give long desc. end**: \n");
    input_to("set_new_long");
    new_long = 0;
}

set_new_long(str) {
    if (str == "") {
        write("Aborted.\n");
        return;
    }
    if (str == "**") {
        write("Give object's value: \n");
        input_to("set_new_value");
        return;
    }
    if (new_long)
        new_long = new_long + str + "\n";
    else
        new_long = str + "\n";
    input_to("set_new_long");
}

set_new_value(str) {
    if (str == "") {
       write("Aborted\n");
       return;
    }
    if (sscanf(str, "%d", new_value) == 1) {
      new_object = 1;
      write("DONE.\n");
      say(call_other(this_player(), "query_name") +
      " has created " + new_short + ".\n");
move_object(clone_object("players/boltar/things/staff"), this_player());
return;
}
write("Bad Value, Aborted");
}

get() {
    if (call_other(this_player(), "query_level") < EXPLORE) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
reset(arg) {
   if (!arg)
      set_light(1);
}

crash() {
    shout("You hear a distant rumble.\n");
    shout("something in the world has changed.\n");
    write("Ok.\n");
    return 1;
}
echo(str) {
   if (!str)
      return 0;
   say (str + "\n");
   return 1;
}

trace(str) {
    object ob;
    if (call_other(this_player(), "query_level") < 20) {
        write("Failure.\n");
        return 1;
    }
    if (!str) {
        write("give monster as arg.\n");
        return 1;
}
    ob = present(str, environment(this_player()));
    if (!ob)
         ob = find_living(str);
         if (!ob) {
         write("not found.\n");
         return 1;
    }
         write(ob); write("\n");
         write(environment(ob)); write("\n");
    return 1;
}

find(str) {
        object ob;
    ob = find_object(str);
    write(ob);
    return 1;
}

fetch(str) {
    move_object(str, this_player());
    return 1;
}
