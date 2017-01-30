 inherit "obj/weapon.c";
int i;
 reset(arg) {
    ::reset(arg);
    if (arg) return;

i=1000+random(1000);
    set_name("short sword");
    set_alias("sword");
   set_short("A short sword");
    set_long("A short sword with a small rune at the hilt.\n");
    set_class(10);
    set_weight(3);
    set_value(500+random(201));
set_read("Delnoch Armory #"+i+"\n");
}
