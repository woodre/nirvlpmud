inherit "/obj/weapon.c";

void reset(int arg) { 

    ::reset(arg);
     if(arg) return;
    set_name("rifle");
    set_short("A Rifle");
    set_long("This is a very basic rifle handed out to new recruits.\n");
    set_type("rifle");
    set_class(18);
    set_weight(2);
    set_value(350);

}
