inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(12);
                set_value(300);
                set_weight(5);
                set_alias("sword");
                set_hit_func(this_object());
set_short("The sword of Bone");
set_long("This is a sliver of a Skeleton dragon, the edges of it are\n"+
         "very sharp.\n");
}
}
