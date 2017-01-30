/* George Liberace's violin */

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("violin");
    set_alias("violin");
    set_short("George's violin");
    set_long("This 1939 J.B. Squier violin reflects a lovely golden hue\n"+
            "from its highly polished wood frame, and has a haunting,\n"+
            "mellow tone when played.  It appears to be well cared for.\n");

    set_class(15);
    set_weight(2);
    set_value(500);
    set_hit_func(this_object());
}

weapon_hit(attacker){
int V;
V = random(10);
if(V > 9)  {
 say("The bow rakes across the strings of the violin,\n"+
    "causing an evil HISS to sing out!\n");
  write("The bow rakes across the strings of the violin,\n"+
    "causing an evil HISS to sing out!\n");
return 5;

    }
    return;
}

