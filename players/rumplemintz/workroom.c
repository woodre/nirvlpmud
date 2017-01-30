/* workroom.c
 * 1/7/2007 - Rumplemintz (Updated the code - originally done long ago
 */

#include <ansi.h>

#pragma strict_types

inherit "room/room";

int shield_int, working;
int move_mess;

void reset(int arg) {
  object board;

  if (!present("board")) {
    board = clone_object("obj/bulletin_board");
    board->set_save_file("players/rumplemintz/board_test");
    board->set_short("Rumplemintz's notice board");
    board->set_long("Hello there!\n" +
      "This is a board specifically set here for you to leave messages to\n"+
      "Rumplemintz.  You can praise him, flame him, high-5 him, hit him\n" +
      "with a witty insult, or whatever!\n" +
      "Commands:\n" +
      "note <headline> ... Write a new note with <headline> as the subject\n" +
      "read <#> .......... Read the '#' numbered note\n" +
      "remove <#> ........ Remove the note numbered <#> (if you wrote it)\n" +
      "clip <#> .......... Save a note to your clipboard\n" +
      "edit <#> .......... Edit one of your notes numbered <#>\n" +
      "...................................................................\n");
    move_object(board, this_object());
  }

  if (arg) return;

  working=0;
  move_mess = 1;
  set_light(1);
  custom_exits = 1;
  short_desc = RED + "Rump's Pad" + NORM;
  long_desc = RED + "This is the workroom of " + HIR + "Rumplemintz" + NORM +
              RED + ".\n" +
              "It is here that he spends most of his time.  On the wall, you" +
              " see a button\n" +
              "which has a strange " + HIY + "glow" + NORM + RED + " to it," +
              "and seems to be attracting you in some way.\n" +
              "If you feel thirsty, simply type " + HIW + "shot" + NORM + RED +
              " and Rump's personal bartender will hand\n" +
              "you one.\n" +
              CYN + "Not-so-Obvious exits: shop, church, down" + NORM + "\n";
  add_item("workroom", "It's only a model...");
  add_item("button", "A Jolly, CANDY-like button...");
}

void init(){
  ::init();
  if ((string)this_player()->query_real_name() == "rumplemintz") {
    add_action("swizz", "swizz");
    add_action("shield", "shield");
    add_action("pc_chan", "pc_chan");
  }
  if ((string)this_player()->query_real_name() == "Rumplemintz" ||
      (string)this_player()->query_real_name() == "Rump") {
    add_action("equip", "equip_me");
  }
  add_action("exit_check", "church");
  add_action("exit_check", "shop");
  add_action("exit_check", "down");
  add_action("press","press");
  add_action("press","push");
  add_action("shot","shot");
  add_action("flick","flick");
  add_action("toggle", "toggle");
  if (this_player()->query_level() < 5002)
    if ((string)this_player()->query_real_name() != "rumplemintz" &&
        shield_int) {
      write(RED +
            "Rumplemintz is busy at the moment, and has his shields on.\n" +
            "You have been moved " +
            (this_player()->query_level() > 19 ?
             "to your workroom." :
             "to the pub.") + NORM + "\n");
      if (find_player("rumplemintz"))
        tell_object(find_player("rumplemintz"),
                    capitalize((string)this_player()->query_real_name()) +
                    " just got bounced.\n");
      if ((int)this_player()->query_level() > 19)
        move_object(this_player(),
                    "/players/" + this_player()->query_real_name() +
                    "/workroom");
      else
        move_object(this_player(), "/room/pub2");
    }
}

int swizz(){
  move_object(clone_object("/players/rumplemintz/closed/swizz"),
    this_player());
  move_object(clone_object("/players/rumplemintz/closed/staff"),
    this_player());
  return 1;
}

int shot() {
  if (present("shot", this_player())) {
    write("You may only have one shot at a time.... no two-fisting here!\n");
    return 1;
  }
  move_object(clone_object("/players/rumplemintz/obj/shot"), this_player());
  write("A bartender appears from Rumplemintz's house and hands you a " +
         HIW + "cold" + NORM + HIB + " shot" + NORM + ".\n");
  say("A bartender appears and hands " + this_player()->query_name() +
      " a " + HIW + "cold" + NORM + HIB + " shot" + NORM + ".\n");
  this_player()->recalc_carry();
  return 1;
}

status flick(string str) {
  if (!str || (str != "on" && str != "off"))
    return 0;
  set_light( (str == "on" ? 1 : -1) );
  write("                                   You turn " +
        (str == "on" ? "on" : "off") + " the lights.\n");
  say(this_player()->query_name() + " flicks " +
      (str == "on" ? "on" : "off") + " the lights.\n");
  return 1;
}

status toggle(string str) {
  if (str != "display")
    return 0;
  write("You toggle the movement meesage " +
        (move_mess ? "off" : "on") + ".\n");
  say(this_player()->query_name() + " toggles the display.\n");
  move_mess = !move_mess;
  return 1;
}

int query_movemess() { return move_mess; }

int shield(string str) {
  if (!str || (str != "on" && str != "off"))
    return 0;
  write("You " +
        (str == "on" ?
        "surround the room with a magic" :
        "clean away the") + "aura.\n");
  say(this_player()->query_name() + 
      (str == "on" ? "rubs" : "snaps") +
      this_player()->query_possessive() +
      (str == "on" ? "hands together" :  "fingers and grins") +
      ".\n");
  say((str == "on" ? "***** POOF *****\nThe room glows slightly" :
                     "The shield flickers and dies") +
      ".\n");
  shield_int = !shield_int;
  return 1;
}

int exit_check() {
  string used_verb, exitloc, exitshort, exitmsg;

  used_verb = query_verb();
  if (shield_int) {
    write("A magical force stops you from using the " + used_verb + " exit.\n");
    return 1;
  }
  switch(used_verb) {
    case "down": exitloc = "/room/vill_green"; exitshort = GRN + "Green"; break;
    case "shop": exitloc = "/room/shop"; exitshort = RED + "Shop"; break;
    default:     exitloc = "/room/church"; exitshort = HIW + "Church"; break;
  }
  say(this_player()->query_name() +
      " travels through the portal leading to the " + exitshort + NORM + "\n",
      this_player());
  tell_object(this_player(),
              "You travel through the portal to the " + exitshort + NORM +
              "\n");
  tell_room(exitloc, this_player()->query_name() +
            " arrives from Rumplemintz's workroom.\n");
  move_object(this_player(), exitloc);
  return 1;
}

int destruct_contents(){
  object *all_objects;
  int dest, i;

  all_objects = all_inventory(this_object());
  for(i=0; i < sizeof(all_objects); i++) {
    if (!living(all_objects[i]) || (int)all_objects[i]->query_npc()) {
      dest += 1;
      tell_room(this_object(), "Zap! ");
      destruct(all_objects[i]);
    }
  }
  return dest;
}

int pc_chan(string str) {
  object target;

  if (!str)
    return 0;

  target = find_player(str);

  if (!target) {
    write("Cannot locate " + capitalize(str) + ".\n");
    return 1;
  }
  if (present("player_channel", target)) {
    write(target->query_name() + " is already on that channel.\n");
    return 1;
  }
  move_object(clone_object("/players/rumplemintz/PC/pc.c"), target);
  tell_object(target, "You have been subscribed to the Player Channel!\n");
  tell_object(target, "The channel where it's players and only players!\n");
  tell_object(target, "The channel that says: No Wizards allowed!\n");
  tell_object(target, "Fight the man!\n\n");
  tell_object(target, "You can view the commands by using 'pchelp' \n");
  tell_object(target, "Welcome aboard!\n");
  write("Sent a Player Channel object to " + target->query_name() + "\n");
  return 1;
}

int press(string str) {
  if (!str || str != "button")
    return 0;
  if (working) {
    write("The button is still pushed down.\n");
    return 1;
  }
  working = 1;
  write("You touched the " + WHT + "HISTORY ERASER " + NORM +
        "button you FOOL!\n");
  say(this_player()->query_name() + " pressed the " + WHT + "HISTORY ERASER " +
      NORM + "button!\n");
  call_out("pb",10);
  return 1;
}

void pb() {
  tell_room(this_object(), "An alarm signal begins to wail....\n");
  call_out("pb_2",5);
}
void pb_2() {
  tell_room(this_object(), "oooo---iiii---oooo---iiii---oooo!!!!!\n");
  call_out("pb_3",5);
}
void pb_3() {
  tell_room(this_object(), "Ren says: Stimpy, you iiidioott!!!\n");
  call_out("pb_4",5);
}
void pb_4() {
  tell_room(this_object(), "Ren says: Everything will be destroyed!\n");
  call_out("pb_6",5);
}
void pb_6(){
  int how_many;

  tell_room(this_object(), "There is a blinding flash of light.\n");
  how_many = destruct_contents();
  tell_room(this_object(), "\n");
  tell_room(this_object(), how_many + " objects were destroyed!\n");
  working=0;
}

int equip() {
  move_object(clone_object("/players/rumplemintz/wiz/mycloak"),
              this_player());
  move_object(clone_object("/players/rumplemintz/wiz/rump_shaker"),
              this_player());
  move_object(clone_object("/players/rumplemintz/wiz/mybag"),
              this_player());
/*
  move_object(clone_object("/players/rumplemintz/wiz/mytorch"),
              this_player());
*/
  write("Equipped!\n");
  return 1;
}

