inherit "obj/treasure";

reset(arg)
{
        if (arg)
                return;
        set_id("darkness");
        set_weight(100);
        set_value(0);
        set_light(-1);
        if (!root()) {
                call_out("dark", 90);
        }

}

dark()
{

        if (environment()) {
                tell_room(environment(),
                                  "The darkness which fills the room dissipates.\n");
        }
        destruct(this_object());
        return 1;
}
