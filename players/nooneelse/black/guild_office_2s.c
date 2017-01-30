/*
  guild_office_2s.c
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "room/room";

int door_is_locked, lamp_is_on, fire_is_out;
string long_desc_office, fire_msg, door_msg, command_str, new_long_desc_office;

init() {
  :: init();

  add_action("lock_door",   "lock");
  add_action("unlock_door", "unlock");
  add_action("lamp",        "lamp");
  add_action("lamp",        "light");
  add_action("lamp",        "lights", 5 );
  add_action("fire_out",    "extinguish", 3);
  add_action("fire",        "throw");
  add_action("fire",        "pour");
  add_action("read",        "read");
  add_action("decorate_office",    "decorate");
  if (file_size(
      "/players/nooneelse/black/offices/"+query_office_owner()+".o")>=1)
    restore_object("players/nooneelse/black/offices/"+query_office_owner());
}

decorate_office(str) {
  string my_name;
  my_name = this_player()->query_real_name();
  if (my_name!=query_office_owner() &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_ASSISTANT)
    return 0;
  if (!str) return 0;
  if (str=="office reset") {
    new_long_desc_office =
      "This is a small private office.  There is a large rosewood desk\n"+
      "with a crystal lamp and a brass name plaque on it and a comfortably\n"+
      "padded chair sitting in front of a wall of bookshelves.\n";
    long_desc_office = new_long_desc_office;
    new_long_desc_office=0;
    long_desc = long_desc_office+fire_msg+door_msg+command_str;
    save_object("players/nooneelse/black/offices/"+query_office_owner());
    write("Ok.\n");
    return 1;
  }
  if (!str || str != "office") return 0;
  write("<<< Don't forget to include something about the desk, plaque,\n"+
        "    lamp and bookshelves or the player's won't know they're here\n"+
        "    too look at.>>>\n");
  input_to("get_description");
  write("Enter the new description of the interior of your office.\n"+
        "Terminate with '**'.  Abort with '~q'.\n");
  write("]");
  new_long_desc_office="";
  return 1;
}

get_description(str) {
  if (str=="~q") {
    write("Aborting.\n");
    return 0;
  }
  if (str=="**") {
    long_desc_office = new_long_desc_office;
    long_desc = long_desc_office+fire_msg+door_msg+command_str;
    new_long_desc_office=0;
    save_object("players/nooneelse/black/offices/"+query_office_owner());
    write("Ok.\n");
    return 0;
  }
  new_long_desc_office = new_long_desc_office+str+"\n";
  write("]");
  input_to("get_description");
}

lock_door(str) {
  if (!str || str!="door") return 0;
  if (door_is_locked) {
    write("The door is already locked.\n");
    return 1;
  }
  else {
    door_is_locked=1;
    door_msg="The door is locked.\n";
    long_desc=long_desc_office+fire_msg+door_msg+command_str;
    write("The door is now locked.\n");
    return 1;
  }
}

unlock_door(str) {
  if (!str || str!="door") return 0;
  if (door_is_locked) {
    door_is_locked=0;
    door_msg="The door is not locked.\n";
    long_desc=long_desc_office+fire_msg+door_msg+command_str;
    write("The door is now unlocked.\n");
    return 1;
  }
  else {
    write("The door is not locked.\n");
    return 1;
  }
}

lamp(str) {
  if (!str) {
    write("Light what?\n");
    return 1;
  }
  if (str=="on") {
    if (lamp_is_on) {
      write("The lamp is already on.\n");
      return 1;
    }
    else {
      lamp_is_on=1;
      set_light(1);
      write("The lamp turn on.\n");
      return 1;
    }
  }
  if (str=="off") {
    if (lamp_is_on) {
      lamp_is_on=0;
      set_light(-1);
      write("The lamp dims until it is off.\n");
      return 1;
    }
    else {
      write("It's not on.\n");
      return 1;
    }
  }
  if (str=="fire") {
    if (fire_is_out) {
      fire_is_out=0;
      set_light(1);
      fire_msg="There is a small cheerful fire in the fireplace.\n";
      long_desc=long_desc_office+fire_msg+door_msg+command_str;
      write("The fireplace bursts into a cheery, warm fire.\n");
      return 1;
    }
    else {
      write("The fire is already lit.\n");
      return 1;
    }
  }
}

fire_out(str) {
  if (str=="fire") {
    if (fire_is_out) {
      write("There is no fire in the fireplace.\n");
      return 1;
    }
    else {
      fire_is_out=1;
      fire_msg="The fireplace looks dark and cold.\n";
      long_desc=long_desc_office+fire_msg+door_msg+command_str;
      set_light(-1);
      write("The fire dims until it finally goes out.\n");
      return 1;
    }
  }
}

fire(str) {
  object glass_obj;
  string where;
  if (!str) {
    write("Throw what?\n");
    return 1;
  }
  where=0;
  sscanf(str, "water on %s", where);
  if (where=="fire") str="water";
  sscanf(str, "glass on %s", where);
  if (where=="fire") str="glass";
  if (str != "glass" && str != "water") return;
  if (!present("glass", this_player())) return;
  if (fire_is_out) {
    write("The fire is already out!\n");
    if (str=="water")
      write("As you pour water in the fireplace, you drop the glass "+
            "and it breaks.\n");
    if (str=="glass") write("The glass shatters in the fireplace.\n");
    say(this_player()->query_name()+" pours water in the fireplace.\n");
    return 1;
  }
  glass_obj=0;
  glass_obj=present("glass");
  if (glass_obj && !glass_obj->query_glass()) {
    write("The glass is empty.\n");
    return 1;
  }
  if (str=="water")
    write("As you put the fire out with the water, you drop the glass "+
          "and it breaks.\n");
  if (str=="glass")
    write("The glass shatters in the fireplace and the fire goes out.\n");
  say("As "+call_other(this_player(), "query_name")+
      " pours water on the fire, the glass drops and shatters.\n");
  fire_is_out = 1;
  fire_msg="The fireplace looks dark and cold.\n";
  long_desc=long_desc_office+fire_msg+door_msg+command_str;
  set_light(-1);
  if (str=="glass" || str=="water") {
    glass_obj=present("glass", this_player());
    destruct(glass_obj);
  }
  return 1;
}

read(str) {
  if (!str || (str!="book" && str!="books")) return 0;
  write("A bright spark flares up as you try to touch the book.  You\n"+
        "change your mind about messing with them.\n");
  return 1;
}

reset (arg) {
  if (arg) return 0;

  no_castle_flag=1;
  short_desc=("A Guild Lieutenant's Office");
  long_desc_office=
    "This is a small private office.  There is a large rosewood desk\n"+
    "with a crystal lamp and a brass name plaque on it and a comfortably\n"+
    "padded chair sitting in front of a wall of bookshelves.\n";
  fire_msg="There is a small cheerful fire in the fireplace.\n";
  door_msg="The door is locked.\n";
  command_str=
    "You can do many things here:\n"+
    "   lock/unlock door        (this will not keep players in,\n"+
    "                            but will keep them out)\n"+
    "   lamp on/off             turns the lamp on the desk on or off\n"+
    "   light/extinguish fire   lights or puts out the fireplace\n"+
    "   decorate office [reset] change the description of your office or\n"+
    "                           reset it to the original\n";
  long_desc=long_desc_office+fire_msg+door_msg+command_str;
  items =
    ({
      "desk",
        "It is a beautiful old rolltop desk with a brass name plaque on it.\n"+
        "All the drawers are locked",
      "drawers", "All the drawers are locked",
      "drawer", "The drawer is locked",
      "chair", "A nice comfortable chair",
      "bookshelves",
        "They contain books with titles like 'Disciplining Unruly Vampires',\n"+
        "'No One Else Can Top This' and 'Running A Happy Guild'",
      "shelves",
        "They contain books with titles like 'Disciplining Unruly Vampires',\n"+
        "'No One Else Can Top This' and 'Running A Happy Guild'",
      "shelf",
        "They contain books with titles like 'Disciplining Unruly Vampires',\n"+
        "'No One Else Can Top This' and 'Running A Happy Guild'",
      "lamp", "It is made of fine-cut crystal.  It is fixed to the desk",
      "fireplace", "It is a red brick fireplace",
      "fire", "It is a red brick fireplace",
  });
  dest_dir =
    ({
      "players/nooneelse/black/guild_office_floor_2", "north",
      "room/post", "post",
    });
  fire_is_out = 0;
  door_is_locked = 1;
  lamp_is_on = 1;
  set_light(2);
}

query_door() { return door_is_locked; }

query_office_owner() {
  return "/players/nooneelse/black/guild_office_floor_top"->
         find_office_name(7);
}
query_guild_office_level() {
  return " - Vampire Guild "+
         "/players/nooneelse/black/guild_office_floor_top"->
         find_office_level(7);
}

look_at_plaque(str) {
  if (str!="brass name plaque" && str!="name plaque" && str!="brass plaque" &&
      str!="plaque") return 0;
  write("It reads '"+capitalize(query_office_owner())+
        query_guild_office_level()+"'\n");
  return 1;
}

look_at_fireplace(str) {
  if (!str || str!="fireplace") return 0;
  if (fire_is_out) {
    write("The wood in the fireplace is cold and wet.\n");
  }
  else {
    write("The wood in the fireplace is burning hotly.\n");
  }
  return 1;
}

look_at_door(str) {
  if (!str || str!="door") return 0;
  if (door_is_locked) {
    write("The door is locked.\n");
  }
  else {
    write("The door is not locked.\n");
  }
  return 1;
}

id(str) {
  if (str=="fire" || str=="fireplace") {
    look_at_fireplace("fireplace");
    return 1;
  }
  if (str=="door" || str=="lock") {
    look_at_door("door");
    return 1;
  }
  if (str=="brass name plaque" || str=="name plaque" || str=="brass plaque" ||
      str=="plaque") {
    look_at_plaque("plaque");
    return 1;
  }
  return (str=="desk" ||
          str=="drawers" ||
          str=="drawer" ||
          str=="chair" ||
          str=="bookshelves" ||
          str=="shelves" ||
          str=="lamp" ||
          str=="indentation");
}
