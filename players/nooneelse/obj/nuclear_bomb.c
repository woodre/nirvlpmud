/*
  nuclear_bomb.c
*/

inherit "/obj/treasure";

int bomb_activated, explosion_time;

init() {
  ::init();

  add_action("activate_bomb",   "activate");
  add_action("deactivate_bomb", "deactivate");
  add_action("adjust_timer",    "adjust");
}

activate_bomb(str) {
  if (!str || str != "bomb") return 0;
  if (bomb_activated) {
    write("The bomb has already been activated.\n");
    return 1;
  }
  write("You open a panel and flip the big red switch!\n");
  say(this_player()->query_name()+" opens a panel on a bomb and "+
      "flips a big red switch!\n", this_player());
  bomb_activated=1;
  explosion_time=time()+300;
  call_out("bomb_explode", 1);
  if (find_player("nooneelse"))
    tell_object(find_player("nooneelse"), "\n\n>>> Nuclear bomb activated!! \n\n");
  return 1;
}

deactivate_bomb(str) {
  if (!str || str != "bomb") return 0;
  if (!bomb_activated) {
    write("The bomb hasn't been activated.\n");
    return 1;
  }
  write("You open a panel and try to flip the big "+
        "red switch, but it's stuck!\n");
  say(this_player()->query_name()+" opens a panel on a bomb and\n"+
      "tries to flip a big red switch, but it's stuck!\n", this_player());
  return 1;
}

adjust_timer(arg) {
  int i;

  if (this_player()->query_real_name() != "nooneelse") return 0;
  if (!arg) {
    write("Use:  adjust timer nnn\n");
    return 1;
  }
  sscanf(arg, "timer %d", i);
  explosion_time=explosion_time-(i*60);
  write("Explosion time altered.\n");
  return 1;
}

bomb_explode() {
  object paint_obj, confetti_obj;
  string who, bucket_color;
  int i, random_nbr;

  i=explosion_time+2;
  if (time() > i) {
    destruct(this_object());
    return 1;
  }
  if (time() < explosion_time) {
    call_out("bomb_explode", 1);
    return 1;
  }

  /* cover everyone */
  if (find_player("nooneelse"))
    tell_object(find_player("nooneelse"),
                "\n\n\n>>>  The nuclear bomb just detonated!  <<<\n\n\n");
  who=users();
  for (i=0; i<sizeof(who); i++) {
tell_object(find_player("nooneelse"),who[i]->query_name()+"\n");
    if (find_object(who[i]) &&
        living(who[i]) &&
        environment(who[i]) &&
        who[i]->query_level() <= 20) {
tell_object(find_player("nooneelse"),">>> 1\n");
      paint_obj=clone_object("/players/nooneelse/obj/bucket_stuff");
      random_nbr=random(5);
      if (random_nbr==0) bucket_color="red";
      if (random_nbr==1) bucket_color="yellow";
      if (random_nbr==2) bucket_color="blue";
      if (random_nbr==3) bucket_color="green";
      if (random_nbr==4) bucket_color="pink";
      paint_obj->start_bucket_stuff(bucket_color);
      if (find_object(who[i])) move_object(paint_obj, who[i]);
tell_object(find_player("nooneelse"),">>> 2\n");
      confetti_obj=clone_object("/players/nooneelse/obj/confetti");
      if (find_object(who[i])) move_object(confetti_obj, who[i]);
      confetti_obj=clone_object("/players/nooneelse/obj/confetti");
      if (find_object(who[i])) move_object(confetti_obj, environment(who[i]));
      if (find_object(who[i]))
        tell_object(who[i],
          "\nKABLOOOOMMMMM!  You hear an incredible explosion and look up\n"+
          "to see paint and confetti flying everywhere!!!!!!!!!\n\n");
      if (find_player("nooneelse"))
        tell_object(find_player("nooneelse"),
                    ">>> "+capitalize(who[i]->query_real_name())+
                    " has just been nuked.\n");
    }
  }
  destruct(this_object());
  if (find_player("nooneelse"))
    tell_object(find_player("nooneelse"),
    ">>> The nuclear bomb has just self destructed.\n");
  return 1;
}

reset(arg) {
  if (arg) return 0;

  set_id("nuclear bomb");
  set_alias("bomb");
  set_short("A nuclear bomb");
  set_value(0);
  set_weight(0);
  bomb_activated=0;
  explosion_time=0;
}

get() { return 0; } /* no picking it up */

long() {
  write("This is a deadly nuclear bomb!  If used, it will affect everyone.\n");
  if (bomb_activated)
    write("    The readout panel says:\n"+
          "        current time:    "+ctime(time())+"\n"+
          "        detonation time: "+ctime(explosion_time)+"\n\n"+
          "     To deactivate, type 'deacivate bomb'\n");
  else
    write("     To activate, type 'acivate bomb'\n"+
          "     To deactivate, type 'deacivate bomb'\n");
  if (this_player()->query_real_name()=="nooneelse")
    write("     To change the detonation time, type 'adjust timer nnn'\n");
  write("\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
}
