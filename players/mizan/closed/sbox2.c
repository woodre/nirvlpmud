inherit "obj/monster";

object owner;
string owner_name;

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_name("Salvation Army Box");
    set_race("box");
    set_alias("box");
    set_short("A Salvation Army Box");
    set_level(19);
    set_hp(200000);
    set_al(100);
    set_ac(60);
    set_wc(0);
    set_no_clean(1);

}

init() 
{
    add_action("stash","stash");
}

realm() { return "NT"; }

long() 
{
    write("This is a large greenish bin that you can dump things that you\n"+
    "don't need anymore into. It is designed for anyone, newbies can take\n"+
    "from it, as well as high-level players down on their luck. \n\n"+
    "If you don't need anything from this box please don't take from it!!\n"+
    "Be generous and understanding...\n"+
    "You can donate things by typing 'put <object> in box'.\n"+
    "A command 'stash all' will allow you to drop all of your things into the box.\n\n"+
    "Please mail any comments/suggestions/flames to Mizan.\n");
}

can_put_and_get() { return 0; }
add_weight() { return 1; }
second_life() { return 1; }
query_hp() { return 1; }
query_mhp() { return 1; }
attack() {  return 1; }
attack_object()
{
    if(this_player()) this_player()->attack_object();

    if(this_object()->query_attack())
    {
        this_object()->query_attack()->attack_object();
        this_object()->query_attack()->attack_object();
        this_object()->query_attack()->stop_fight();
        this_object()->query_attack()->stop_fight();
        this_object()->query_attack()->stop_hunter();
        this_object()->query_attack()->stop_hunter();
    }

    return 1;
}

hit_player() { return 1; }
move_player() { return 1; }

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


