#define name "potion"
#define short_desc "A potion of heal (intox)"
#define message "A cool, tingling sensation soothes your wounds"
#define heal 400
#define value 2500
#define strength 10

inherit "obj/drink.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_value(name + "#" + short_desc + "#" + message + "#" + heal + "#" +
               value + "#" + strength);
}

query_value() { return value; }
