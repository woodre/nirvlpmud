/*
  workroom.c
*/

#include "/players/nooneelse/ansi.h"

inherit "room/room";

int location_of_gloves, shield_level;
string room_file_name, room_desc_name;

init() {
  ::init();

  if (shield_level > 0 &&
      !this_player()->am_i_a_servant() &&
      this_player()->query_real_name() != "nooneelse" &&
      this_player()->query_level() < shield_level) {
    if (find_player("nooneelse")) {
      tell_object(find_player("nooneelse"),
                  "\n\n"+this_player()->query_real_name()+
                  " just tried to enter your workroom.\n\n");
    }
    tell_object(this_player(), "Nooneelse is busy right now, try later.\n");
    move_object(this_player(), "room/church");
  }
  add_action("set_shield",       "shield");
  add_action("move_guild_gloves", "gloves");
  add_action("get_show_bat",      "getshow");
  add_action("get_ring",         "getring");
  add_action("get_ntell",        "getntell");
  add_action("get_doodad",       "getdoodad");
  add_action("get_fangs",        "getfangs");
   add_action("get_test_fangs",   "gettestfangs");
  add_action("get_pie",          "getpie");
  add_action("get_grenade",      "getgrenade");
}

set_shield(arg){
  int tmp_level;
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  if(!arg) {
    write("Workroom shields are currently at level "+shield_level+".\n");
    return 1;
  }
  if(sscanf(arg, "%d", tmp_level)) {
    if(tmp_level >= 0) {
      write("Workroom shields are changed.\n"+
            "Access is allowed to levels --> "+tmp_level+"\n");
      shield_level = tmp_level;
    }
    else {
      write(arg+" is an invalid parameter.\n");
    }
  }
  return 1;
}

move_guild_gloves(str) {
  int i, nbr, old_location_of_gloves;
  string file_name_str, file_name_str2, users_list;
  object room_obj, player_obj, hole_obj, gloves_obj;
  if(!this_player()) return;
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  if (!str) {
    write("The guild gloves are buried "+room_desc_name[location_of_gloves]+
          ".\n"+
          "                            "+room_file_name[location_of_gloves]+
          "\n");
    return 1;
  }
  sscanf(str, "move %d", nbr);
  if (nbr >= 0 && nbr <=5)
    str="move";
  else
    return;
  if (str=="move") {
    old_location_of_gloves=location_of_gloves;
    /* make a new one & put it in place */
    if (nbr >= 0 && nbr <=5)
      location_of_gloves=nbr;
    else {
      location_of_gloves=random(6);
      /* try 3 times, if it's still there, tough! */
      if (location_of_gloves==old_location_of_gloves)
        location_of_gloves=random(6);
      if (location_of_gloves==old_location_of_gloves)
        location_of_gloves=random(6);
      if (location_of_gloves==old_location_of_gloves)
        location_of_gloves=random(6);
    }
    hole_obj=clone_object("/players/nooneelse/black/guild_hole");
    gloves_obj=clone_object("/players/nooneelse/black/guild_gloves");
    call_other(room_file_name[location_of_gloves], "???", 0);
    move_object(gloves_obj, hole_obj);
    hole_obj->set_hidden(1);
    hole_obj->set_owner("nooneelse");
    move_object(hole_obj, room_file_name[location_of_gloves]);
    /* now destruct the old one */
    call_other(room_file_name[old_location_of_gloves], "???", 0);
    room_obj=find_object(room_file_name[old_location_of_gloves]);
    hole_obj=first_inventory(room_obj);
    while (hole_obj) {
      file_name_str2 = file_name(hole_obj);
      sscanf(file_name_str2, "%s#", file_name_str);
      if (file_name_str=="players/nooneelse/black/guild_hole") break;
      hole_obj=next_inventory(hole_obj);
    }
    if (hole_obj) {
      move_object(hole_obj, this_object());
      destruct(hole_obj);
      gloves_obj=present("vampire gloves", this_object());
      if (gloves_obj) destruct(gloves_obj);
    }
    users_list=users();
    for (i=0; i < sizeof(users_list); i++) {
      player_obj=users_list[i];
      if (present("vampirefangs", player_obj) &&
          player_obj->query_guild_exp() >=671)
        tell_object(player_obj,
                    "\n\nThe location of the gloves has changed!\n\n");
    }
    write("The gloves have been moved from:\n"+
          "   "+room_desc_name[old_location_of_gloves]+
          "   ("+room_file_name[old_location_of_gloves]+")"+
          "\nto:\n"+
          "   "+room_desc_name[location_of_gloves]+
          "   ("+room_file_name[location_of_gloves]+").\n");
  }
  return 1;
}

get_show_bat() {
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Cloning a show bat.\n");
  command("clone /players/nooneelse/black/show_bat", this_player());
  write("You now have the show bat.\n");
  return 1;
}

get_ring() {
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Destroying current ring.\n");
  command("dest ring", this_player());
  write("Updating the ring.\n");
  command("update /players/nooneelse/closed/nooneelse_ring", this_player());
  write("Cloning a new ring.\n");
  command("clone /players/nooneelse/closed/nooneelse_ring", this_player());
  write("You now have the ring.\n");
  return 1;
}

get_ntell() {
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Cloning an ntell.\n");
  move_object(clone_object("/players/nooneelse/closed/ntell"), this_player());
  write("You now have the ntell.\n");
  return 1;
}

get_doodad(str) {
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Destroying current doodad.\n");
  command("dest doodad", this_player());
  write("Cloning doodad.\n");
  move_object(clone_object("players/nooneelse/obj/doodad"), this_player());
  return 1;
}

get_fangs() {
  object fangs;

  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Destroying current fangs.\n");
  command("dest fangs", this_player());
  write("Updating the fangs.\n");
  command("update /players/nooneelse/black/vampire_fangs", this_player());
  write("Updating the fangs base.\n");
  command("update /players/nooneelse/black/vampire_fangs_base", this_player());
  write("Cloning new fangs.\n");
  move_object(clone_object("players/nooneelse/black/vampire_fangs"), this_player());
  write("You now have the fangs.\n");
  return 1;
}

get_test_fangs() {
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Destroying current fangs.\n");
  command("dest fangs", this_player());
  write("Updating the fangs.\n");
  command("update /players/nooneelse/black/fangs", this_player());
  write("Updating the fangs base.\n");
  command("update /players/nooneelse/black/vampire_fangs_base", this_player());
  write("Cloning new fangs.\n");
  command("clone /players/nooneelse/black/fangs", this_player());
  write("You now have the 'test' fangs.\n");
  return 1;
}

get_pie(str) {
  object pie;
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Cloning pie.\n");
  pie = clone_object("players/nooneelse/obj/pie");
  if (str) {
    write("Setting pie type.\n");
    pie->set_pie_type(str);
  }
  move_object(pie, this_player());
  write("You now have a pie.\n");
  return 1;
}

get_grenade(str) {
  object grenade;
  if (lower_case(this_player()->query_real_name())!="nooneelse") {
    write("Say what "+this_player()->query_name()+"?\n");
    return 1;
  }
  write("Cloning paint grenade.\n");
  grenade=clone_object("players/nooneelse/obj/paint_grenade");
  move_object(grenade, this_player());
  write("You now have a paint grenade.\n");
  return 1;
}

reset(arg) {
  object hole_obj, gloves_obj;
  if (arg) {
    move_guild_gloves("move");
    if (find_player("nooneelse"))
      tell_object(find_player("nooneelse"),
                  "\n\nWorkroom==>The Mud has just reset.\n\n");
    send_scroll();
    return;
  }

  set_light(1);
  no_castle_flag=1;
  shield_level=21;
  fill_name_desc_table(); /* get the room names & clues for the gloves task */
  location_of_gloves=random(6);
  hole_obj=clone_object("/players/nooneelse/black/guild_hole");
  gloves_obj=clone_object("/players/nooneelse/black/guild_gloves");
  call_other(room_file_name[location_of_gloves], "???", 0);
  move_object(gloves_obj, hole_obj);
  hole_obj->set_hidden(1);
  hole_obj->set_owner("nooneelse");
  move_object(hole_obj, room_file_name[location_of_gloves]);
/*
  call_other("room/church", "???", 0);
  if (!present("marble tablet", find_object("room/church")))
    move_object(clone_object("/players/nooneelse/obj/marble_tablet"),
                "room/church");
  call_other("room/adv_guild", "???", 0);
  if (!present("marble tablet", find_object("room/adv_guild")))
    move_object(clone_object("/players/nooneelse/obj/marble_tablet"),
                "room/adv_guild");
  call_other("room/pub2", "???", 0);
  if (!present("marble tablet", find_object("room/pub2")))
    move_object(clone_object("/players/nooneelse/obj/marble_tablet"),
                "room/pub2");
*/
  call_other("/players/nooneelse/entryforest/e_forest0", "???", 0);
  dest_dir=
    ({
      "room/church","church",
      "room/pub2", "pub",
      "room/shop", "shop",
      "room/post", "post",
      "/room/adv_inner","inner",
      "players/nooneelse/private_room", "pr",
      "room/mine/tunnel_room", "castle",
        "players/nooneelse/hunt/entry_hall", "hunt",
      "/players/nooneelse/closed/keep/keep_sales_office", "keep",
      "/players/nooneelse/closed/magic_shop/magic_shop", "magic",
      "/players/nooneelse/black/guild_office_tn", "office",
    "/players/eurale/VAMPIRES/RMS/vguild_hall", "guildboard"
    });
}

send_scroll() {
  object obj;
  if (!present("nooneelse ad scroll", find_object("/room/vill_green"))) {
    obj=clone_object("/players/nooneelse/obj/scroll_advertisement");
    move_object(obj, "/room/vill_green");
  }
  return 1;
}

is_castle() { return 1; }

short() {
  if(lower_case(this_player()->query_real_name())=="nooneelse")
    return "Nooneelse's Workroom"+
           "  (Workroom shield level is-->"+shield_level+")\n\n"+
           "                      "+
           "The guild gloves are buried "+room_desc_name[location_of_gloves]+
           ".\n"+
           "                      "+
           "                           "+room_file_name[location_of_gloves]+
           "\n\n"+
           "You can:\n"+
           "   shield <new level/0=off>\n"+
           "   gloves <move> <#> (0-5)\n"+
           "   getring\n"+
           "   getshow\n"+
           "   getntell\n"+
           "   getdoodad\n"+
           "   getfangs\n"+
           "   gettestfangs\n"+
           "   getpie <pie type>\n"+
           "   getgrenade\n";
  return "Nooneelse's Workroom";
}

long(str) {
  write(short()+"\n"+
    "This is where Nooneelse dabbles in creation.  Beware what you touch\n"+
    "because he isn't that good at it yet.\n"+
    "   The exits are: church, pub, shop, post");
  if (this_player()->query_level() > 20)
    write(", inner, pr, castle, hunt, keep,\n");
    write("                  magic, office, guildboard");
  write("\n");
  write("\n"+NORM+CYN+"Remember to check /debug.log & lpmud.log once in a while\n"+
          "to see if your stuff is creating errors.\n"+NORM);
}


query_location_of_gloves() { return location_of_gloves; }
query_gloves_file_name() { return room_file_name[location_of_gloves]; }
query_gloves_desc_name() { return room_desc_name[location_of_gloves]; }

fill_name_desc_table() {
  room_file_name = allocate(6);
  room_desc_name = allocate(6);

  room_file_name[0]="/room/attic";
  room_desc_name[0]="as high as you can go where the young ones start";

  room_file_name[1]="/room/south/sshore26";
  room_desc_name[1]="by the broken bridge";

  room_file_name[2]="/room/plane1";
  room_desc_name[2]="by the lair of the black snake";

  room_file_name[3]="/room/mount_top2";
  room_desc_name[3]="below the clouds";

  room_file_name[4]="/room/plane11";
  room_desc_name[4]="where Bill & Ted found Napoleon";

  room_file_name[5]="/room/mine/tunnel16";
  room_desc_name[5]="by the sturdy dwarf";
}

