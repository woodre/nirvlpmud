
/*
inherit "players/sandman/paladin/obj/weapon";
*/
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     if(!arg)
  return;
     set_name("sword");
      set_short("A sword");
     set_long("A small sword with many nicks and scratches on the blade.\n");
     set_class(10);
     set_value(300);
     set_weight(2);
}

