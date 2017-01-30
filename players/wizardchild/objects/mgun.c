inherit "/obj/weapon.c";
int val;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        if(!val) val = 1000;
        set_name("gun");
        set_alias("marble gun");
        set_short("A marble gun (empty)");
        set_long("A long steel menace. It looks powerful enough to seriously\n"
                +"injure anyone to experience its power. Luckily, you have it.\n");
        set_value(val);
        set_class(13);
        set_weight(6);
}
id(str) {
        return str == "gun" || str == "marble gun" || str == "a marble gun (empty)";
}
