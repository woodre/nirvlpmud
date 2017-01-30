inherit "obj/weapon";

self_destruct(time) { call_out("self_destruct_2", time); }

self_destruct_2() {
     int x;
     x=environment(this_object())->weapon_class();
     x-=weapon_class();
     environment(this_object())->set_class(x);
     destruct(this_object());
}

start_spell() {
     int x;
     x=environment(this_object())->weapon_class();
     x+=weapon_class();
     environment(this_object())->set_class(x);
}
