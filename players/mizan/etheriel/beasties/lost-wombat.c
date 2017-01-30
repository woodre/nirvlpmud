inherit "/players/mizan/core/monster.c";

object coins, food;

reset(arg) 
{
    ::reset(arg);
    if(!arg) 
    {
        set_name("wombat");
        set_short("A fat, furry wombat");
        set_long("This is a fat, dopey creature that is not reacting to its new\n"+
        "envioronment happily. Stout and just under a meter in length,\n"+
        "It is a silly looking animal, peering back at through two\n"+
        "beady little eyes.\n");
        set_wc(6);
        set_ac(3);
        set_level(2);
        set_hp(30);
        set_ep(2900);
        set_chat_chance(4);
        load_chat("Wombat quivers uncontrollably.\n");
        load_chat("Wombat appears lost and confused.\n");
        coins=clone_object("obj/money");
        coins->set_money(20);
        move_object(coins, this_object());
        food=clone_object("players/mizan/etheriel/heals/banana.c");
        move_object(food, this_object());
    }
}
