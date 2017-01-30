inherit "obj/weapon";
reset(arg)
{
   ::reset(arg);
   if (!arg) {
        set_class(50);
       set_name("The Ice Sword");
       set_weight(1);
        set_alias("sword");
       set_value(100000);
      set_short("The Ice Sword with a Big Name");
        set_long("The air seems to be freezing around the sword.....\n" +
               "It appears very powerful and weightless in your hand.\n");
}
}

