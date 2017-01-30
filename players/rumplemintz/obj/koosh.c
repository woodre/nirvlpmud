inherit "obj/treasure";

reset(arg) {
    set_id("koosh");
    set_short("A koosh ball");
    set_long("It's a koosh ball.  Toss it!\n");
    set_weight(1);
    set_value(501);
}

init() {
    ::init();
    add_action("toss_it","toss");
}

toss_it(str) {
    if(!str) {
        write("You need to give a player's name to do that.\n");
        return 1;
    }
    if(!find_player(str)) {
        write("No such player logged in.\n");
        return 1;
    }
    write("You toss the koosh to "+capitalize(str)+"!\n");
    if(!present(find_player(str), environment(this_player()))) {
    say(this_player()->query_name()+" tosses "+capitalize(str)+" the koosh!\n");
    }
    else {
        say(this_player()->query_name()+" tosses "+capitalize(str)+" the koosh!\
n", find_player(str));
    }
    tell_object(find_player(str), this_player()->query_name()+" tosses you a koosh!\n");
    move_object(this_object(), find_player(str));
    return 1;
}
