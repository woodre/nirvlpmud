inherit "obj/treasure";
int i;
init() {
  add_action("tape","tape");
  ::init();
 }
reset(arg) {
   if (arg) return;
   i = 5;
   set_short("A Roll of Masking Tape");
   set_alias("tape");
   set_weight(1);
   set_value(200);
   set_long("This is a roll of masking tape.\nYou can 'tape' a person's"
   +" mouth shut by typing\nTAPE <Target>.\n");
}
tape(str) {
 object ob, stick;
  if(!str) {
    write("Tape what?\n");
    return 1;
  }
  if(str=="grimm") {
    write("Tape:  NOT!\n");
    return 1;
  }
  if (i>0) {
  if (!present(str,environment(this_player()))) {
    write("Tape whom?\n");
  } else {
  ob = find_living(str);
    if(ob->query_level()>19 && !this_player()->query_real_name()=="grimm") {
     write("You try to put tape on the wizard's mouth but his awesomness\nis too much for you and you get tangled up in it yourself.\n");
     stick = clone_object("players/grimm/object/sticky_tape");
     move_object(stick, this_player());
     i--;
     say(this_player()->query_name()+" tries to tape a wizard's mouth shut but fumbles around \nfoolishly with it instead.\n");
    } else {
   write("You tape "+ob->query_name()+"'s mouth shut.\n");
   i--;
   say("Somebody sneaks up behind "+ob->query_name()+" and tapes his mouth shut.\n");
     stick = clone_object("players/grimm/object/sticky_tape");
     move_object(stick,ob);
  }
  }
 } else {
  write("The roll is out of tape and biodegrades in your hand.\n");
  destruct(this_object());
  return 1;
  }
return 1;
}
