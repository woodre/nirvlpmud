inherit "obj/treasure";

reset(arg)
{
        if (arg)
                return;
        set_id("demon_block");
        set_weight(100);
        set_value(0);
        set_light(0);
        if (!root()) {
                call_out("dark", 90);
        }

}
init () {
   ::init() ;
     add_action ("demon_cast","demon");
     }

demon_cast(str) {
write("You can't use this spell again yet\n");
return 0;
}

dark()
{

        write("You can now use demon again");
        destruct(this_object());
        return 1;
}
