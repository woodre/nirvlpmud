
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     if(!arg)
return;
     set_name("spear");
     set_short("A spear");
     set_long("A long sturdy spear.\n");
     set_class(15);
     set_weight(2);
     set_value(500);
}

