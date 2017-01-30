
inherit "obj/weapon";

int redstate;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("sword");
   set_alias("longsword");
   set_short("A red longsword");
   set_long("This is a well crafted longsword which has a red tinge to the "+
            "blade.\n");
   set_class(12);
   set_value(2000);
   set_weight(2);
   set_hit_func(this_object());
   redstate = 100;
}

set_redstate(s) { redstate = s; }

query_redstate() { return redstate; }


weapon_hit(attacker) {
    if(redstate > 0) {
      write("The sword glows violently.\n");
      redstate = redstate - 1;
      return 10;
    }
}

