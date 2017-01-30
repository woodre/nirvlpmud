
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     if(!arg)
return;
     set_name("shortsword");
     set_alias("sword");
     set_short("A shortsword");
     set_long("A well made shortsword");
     set_class(14);
     set_value(700);
     set_weight(2);
}

