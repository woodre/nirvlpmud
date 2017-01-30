inherit "/players/mizan/core/monster.c";
object coins, food;

reset(arg) 
{
    ::reset(arg);
    if(!arg) 
    {
        set_name("wombat");
        set_short("A fat, furry wombat");
        set_long("A fat, furry, smelly creature that seemingly wants to be killed.\n");
        set_wc(6);
        set_ac(3);
        set_level(2);

        set_hp(30);
        set_ep(2900);
        coins=clone_object("obj/money");
        coins->set_money(20);
        move_object(coins, this_object());
        food=clone_object("players/mizan/etheriel/heals/banana.c");
        move_object(food, this_object());
    }
}
