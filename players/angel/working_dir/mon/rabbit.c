/*
  rabbit.c
*/

inherit "obj/monster";

reset(arg) {
::reset(arg);
if(arg) return;
  set_name("little rabbit");
  set_level(1);
  set_alias("rabbit");
  set_race("rabbit");
  set_hp(62);
  set_al(1000);
  set_short("A rabbit");
  set_long("A little bunny rabbit with a thorn in its paw.\n");
  set_wc(6);
  set_ac(1);
  set_aggressive(0);
}

id(str) { return str=="little rabbit" || str=="nooneelserabbit" ||
                 str=="rabbit" || str=="thorn" || str=="paw"; }

init() {
  ::init();

  add_action("look_thorn",    "look");
  add_action("look_thorn",    "examine");
  add_action("remove_thorn",  "pull");
  add_action("remove_thorn",  "remove");
}

look_thorn(str) {
  string str2;
  if (!str) return 0;
  str2=0;
  sscanf(str, "at %s", str2);
  if (str=="thorn" || str2=="thorn") {
    write("It is a very sharp thorn, stuck in the rabbits paw.\n"+
          "It looks like it hurts a lot.\n");
    return 1;
  }
  if (str=="paw" || str2=="paw" ||
      (sscanf(str, "at rabbits %s", str2)==1 && str2=="paw")) {
    write("It looks like the thorn is making it hurt a lot.\n");
    return 1;
  }
  return 0;
}

remove_thorn(str) {
  string str2;
  object obj;
  if (!str) return 0;
  if (str=="thorn" || sscanf(str, "thorn %s", str2)==1) {
    obj=clone_object("players/nooneelse/obj/mistletoe");
    move_object(obj, environment(this_object()));
    write("The rabbit looks at its paw, then at you.\n"+
        "It hops around a bit, then drags a sprig of leaves from the bushes.\n"+
        "The bunny then looks at the sprig, then at you.\n"+
        "It then scampers off into the underbrush.\n");
    say("The rabbit looks at its paw, then at "+this_player()->query_name()+
        ".\n"+
        "It hops around a bit, then drags a sprig of leaves from the bushes.\n"+
        "The bunny then looks at the sprig, then at "+
        this_player()->query_name()+".\n"+
        "It then scampers off into the underbrush.\n", this_player());
    destruct(this_object());
    return 1;
  }
  return 0;
}
