inherit "obj/treasure";
int i;
init() {
  add_action("glue","glue");
  ::init();
 }
reset(arg) {
   if (arg) return;
   i = 2;
   set_short("Super Glue");
   set_alias("glue");
   set_weight(1);
   set_value(100);
   set_long("This is a bottle of super glue.  You can 'glue' a person in place by typing\nGLUE <Target>.\n");
}
glue(str) {
 object ob, stick;
  if (i>0) {
  if (!present(str,environment(this_player()))) {
    write("Glue whom?\n");
  } else {
   ob = find_living(str);
   if (ob->query_attack()) {
    write("Forget it...he is fighting right now.\n");
   } else {
    if (ob->query_level()>1000000) {
      write("You try to glue the wizard's feet but his awesomness overwhelms you and\nyou spill it all over yourself instead.\n");
      say(this_player()->query_name()+" foolishly tries to glue a wizard's feet to the\nground but fumbles the attempt and pours the glue on himself instead.\n");
     i--;
     stick = clone_object("players/grimm/object/sticky_glue");
     move_object(stick, this_player());
   } else {
     write("You glue "+ob->query_name()+"'s feet to the ground.\n");
     i--;
     say("Somebody sneaks up behind "+ob->query_name()+" and super glues his feet to the ground.\n");
     stick = clone_object("players/grimm/object/sticky_glue");
     move_object(stick,ob);
  }
 }
  }
 } else {
  write("The bottle disolved in your hand.\n");
  destruct(this_object());
  return 1;
  }
return 1;
}
