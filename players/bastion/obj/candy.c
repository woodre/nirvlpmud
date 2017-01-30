#define name "candy"
#define short_desc "A Valentine's Day candy"
#define eater_message "It is delicious, chocolate-covered caramel.\n"
#define eating_message " munches on a piece of candy.\n"
#define value 0
#define strength 2

inherit "obj/food.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
/*
    set_value(name + "#" + short_desc + "#" + message + "#" + heal + "#" +
               value + "#" + strength);
*/
     set_name(name);
     set_short(short_desc);
     set_eater_mess(eater_message);
     set_strength(strength);
     set_eating_mess(eating_message);
}

query_value() { return value; }
