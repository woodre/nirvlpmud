inherit "obj/weapon";
reset(arg){
if(arg) return;
::reset(arg);
set_name("stinger");
set_alt_name("sting");
set_alias("weapon");
set_short("A scorpion's stinger");
set_long("A black stinger from a scorpion's tail.  You can see the deadly venom\n"+
         "on the tip of it.\n");
set_class(18);
set_weight(3);
set_value(3000);
set_hit_func(this_object());
}
weapon_hit(attacker){
        if (random (100) < 40) {
        write("The deadly vemon seeps into your enemies body.\n");
        say(capitalize(this_player()->query_real_name()) + "'s stinger hits home letting it's deadly venom loose.\n");
        return(random(6)+1);
}
}

/* DO NOT remove the following */
query_s9_shell() { return "020695135444"; }
