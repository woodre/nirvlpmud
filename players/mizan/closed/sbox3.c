inherit "/obj/clean";
#define MAX_WEIGTH 100000
add_weight(w) { return 1; }
id(str)
{
  return str == "box" || str == "army_box" || str == "army box"; 
}
short() { return "A Salvation Army Box"; }
long() {
  write("This is a large greenish bin that you can dump things that you\n"+
  "don't need anymore into. It is designed for anyone, newbies can take\n"+
  "from it, as well as high-level players down on their luck. \n\n"+
  "If you don't need anything from this box please don't take from it!!\n"+
  "Be generous and understanding...\n"+
  "You can donate things by typing 'put <object> in box'.\n"+
  "A command 'stash all' will allow you to drop all of your things into the box.\n\n"+
  "Please mail any comments/suggestions/flames to Mizan.\n");
}
can_put_and_get() { return 1; }


reset(arg) 
{
    if(arg) return;
    set_no_clean(1);
}

init()
{
    add_action("stash","stash");
}

stash(str) 
{
    if(!str) return 0;
    
    if(str == "all") 
    {
        write_file("/players/mizan/logs/box.log", (this_player()->query_name())+" stashed all.\n");
        move_object(this_player(), this_object());
        command("drop all", this_player());
        write("So kind of you to donate all of your equips... what comes around goes around :)\n");
        move_object(this_player(), environment(this_object()));
        return 1;
    }
    return 0;
}

catch_tell(str)
{
    object ob;
    object from;
    object next_dest;
    string a, b, c;
    string next_out;
    string name_oc;

    from = this_player();

    if(!from)
    return 1;

    /* we want to prevent recursion errors */
    if(str &&
/*       toggle_headview && */
       environment(this_object()) &&
       environment(this_object()) != find_object("players/mizan/core/02h/room07.c"))
        tell_room("players/mizan/core/02h/room07.c", "%" + str);
    return 1;
/*
    if(sscanf(str, "%s tells you: %s", a, b) == 2) 
    {
        tell_room(LISTENING_ROOM,"**" + query_name() + "** "+a+" tells " + query_name() + ": "+b+"\n");
        return 1;
    }
    if(sscanf(str, "%s whispers to you: %s", a, b) == 2) 
    {
        tell_room(LISTENING_ROOM,"**" + query_name() + "** "+a+" whispers to " + query_name() + ": "+b+"\n");
        return 1;
    }
 */
}
