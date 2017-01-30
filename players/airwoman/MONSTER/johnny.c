/* Changed level from 18 to 14 and unset hps to 300  -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money,apple;
    ::reset(arg);
    if(!arg) {
    set_name("johnny");
    set_alias("john");
    set_level(14);
    set_hp(300);
    set_short("Johnny Appleseed --- The best apple grower");
    set_long("Johnny holds a magical apple.  His most\n"+
              "prized possession.\n");
    set_aggressive(0);
    set_wc(15);
    set_ac(26);
    set_chat_chance(10);
   load_chat("Johnny says:  An apple a day keeps the doctor away!\n");
    money=clone_object("obj/money");
    money->set_money(100+random(100));
    move_object(money, this_object());
    apple=clone_object("players/airwoman/food/apple");
    move_object(apple, this_object());
}
}
 
 
