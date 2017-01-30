inherit "obj/armor";
reset(arg){
   ::reset(arg);
    set_short("A Crucifix");
   set_arm_light(0);
set_long(
  "This is a very powerful and coveted object, guard it with\n" +
"your life. The power of GOD is within it!\n");
   set_ac(5);
   set_weight(2);
   set_value(1000000);
   set_alias("crucifix");
   set_name("crucifix");
   set_type("armor");
}
If random(30) > 5 then {
    this_player()->heal_self(3);
write"The power of GOD comes down on you and you feel a bit stronger.\n");
}
