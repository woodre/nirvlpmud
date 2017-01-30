/*
 klingon_transporter.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

string target_room;
object view_obj, view_obj_room;

init() {
  object tmp_obj;
  ::init();

  add_action("set_coordinates",      "coordinates");
  add_action("energize_transporter", "energize");
  tmp_obj=call_other("/players/nooneelse/klingon/klingon_bridge",
                     "query_view_obj", 0);
  if (tmp_obj && present("klingon transporter key", this_player()))
    write("\nAs you enter, you hear the computer say:\n"+
          "    Transporters currently locked onto:\n"+
          "       "+tmp_obj->short()+"\n\n");
}

set_coordinates(target_room) {
  if (!target_room) {
    tell_room(this_object(), "The computer beeps and says:\n"+
              "   Set what coordinates?\n"+
              "   Transporters can only be set for the standard locations.\n");
    return 1;
  }
  view_obj=0;
  if (target_room=="church") {
    call_other("/room/church", "???");
    view_obj=find_object("/room/church");
  }
  else
  if (target_room=="shop") {
    call_other("/room/shop", "???");
    view_obj=find_object("/room/shop");
  }
  else
  if (target_room=="pub") {
    call_other("/room/pub2", "???");
    view_obj=find_object("/room/pub2");
  }
  else
  if (target_room=="jetty") {
    call_other("/room/jetty", "???");
    view_obj=find_object("/room/jetty");
  }
  else
  if (target_room=="clearing") {
    call_other("/room/clearing", "???");
    view_obj=find_object("/room/clearing");
  }
  else
  if (target_room=="enterprise") {
    call_other("/players/rich/trans_room", "???");
    view_obj=find_object("/players/rich/trans_room");
  }
  else
  if (target_room=="romulan" || target_room=="romulan ship") {
    call_other("/players/nooneelse/romulan/romulan_transporter", "???");
    view_obj=find_object("/players/nooneelse/romulan/romulan_transporter");
  }
/* players are winding up inside living critters!
  if (!view_obj) {
    if (!present("klingon transporter key", this_player())) {
      tell_room(this_object(), "The computer beeps and blares:\n"+
          "   Alert!  Alert!  Attempted unauthorized use of transporters! "+
          "Alert!\n");
      return 1;
    }
    view_obj=call_other("players/nooneelse/klingon/klingon_bridge",
                        "query_view_obj", 0);
    if (view_obj->realm()=="NT") {
      tell_room(this_object(), "The computer beeps and blares:\n"+
          "   Alert!  Alert!  Illegal coordinates! Alert!\n");
      view_obj=0;
      return 1;
    }
    if (view_obj) {
      view_obj_room=environment(view_obj);
      view_obj=view_obj_room;
    }
  }
*/
  if (!view_obj) {
    if (!present("klingon transporter key", this_player())) {
      tell_room(this_object(), "The computer beeps and says:\n"+
          "   Set what coordinates transporter officer?\n"+
          "   Transporters can only be set for the standard locations\n"+
          "   or those that have been scanned.\n");
      return 1;
    }
    tell_room(this_object(), "The computer beeps and says:\n"+
         "   Set what coordinates?\n"+
         "   Transporters can only be set for the standard locations.\n");
    return 1;
  }
  if (target_room)
    tell_room(this_object(), "The computer beeps and says:\n"+
        "   Transporters locked onto "+capitalize(target_room)+".\n");
  else
    tell_room(this_object(), "The computer beeps and says:\n"+
        "   Transporters locked in.\n");
  return 1;
}

energize_transporter() {
  string where_str;
  int sp_cost;

  if (!view_obj && present("klingon transporter key", this_player()))
      view_obj=call_other("players/nooneelse/klingon/klingon_bridge",
                          "query_view_obj", 0);
  if (!view_obj) {
    tell_room(this_object(), "The computer beeps and says:\n"+
      "   Impossible transporter officer!\n"+
      "   Transporters have not been locked onto valid coordinates.\n");
    return 1;
  }
  sp_cost = 55+random(5);
  if (this_player()->query_spell_point() < sp_cost) {
    tell_room(environment(this_player()),
              "The computer beeps and says:\n"+
              "   Sorry transporter officer!  Not enough energy to power\n"+
              "   the transporters.\n");
    return 1;
  }
  this_player()->add_spell_point(- sp_cost);
  if (where_str = call_other("obj/base_tele","teleport")) {
    tell_room(where_str,
              "You hear a high-pitched electrical hum and see a sparkling\n"+
              "rainbow of color, which fades away to reveal "+
              capitalize(this_player()->query_name())+".\n");
    move_object(this_player(), where_str);
    tell_room(this_object(),
              "You hear a high-pitched electrical hum and see a sparkling\n"+
              "rainbow of color surround "+capitalize(this_player()->query_name())+
              ", which fades away to\n"+
              "reveal that "+this_player()->query_pronoun()+" has disappeared.\n");
    write("You hear a high-pitched electrical hum and see a sparkling\n"+
          "rainbow of color envelope you.  Suddenly, you hear loud electrical\n"+
          "crackling and popping!  Something has gone wrong with the transport!\n"+
          "When the rainbow fades away, you see:\n\n");
    command("look", this_player());
    return 1;
  }
  tell_room(this_object(), "The computer beeps and says:\n"+
      "   Yes transporter officer!  Energizing transporters.\n");
  tell_room(view_obj,
            "You hear a high-pitched electrical hum and see a sparkling\n"+
            "rainbow of color, which fades away to reveal "+
            capitalize(this_player()->query_name())+".\n");
  if (living(view_obj)) view_obj=environment(view_obj);
  move_object(this_player(), view_obj);
  tell_room(this_object(),
      "You hear a high-pitched electrical hum and see a sparkling\n"+
      "rainbow of color surround "+capitalize(this_player()->query_name())+
      ", which fades away to\n"+
      "reveal that "+this_player()->query_pronoun()+" has disappeared.\n");
  write("You hear a high-pitched electrical hum and see a sparkling\n"+
        "rainbow of color envelope you.  It fades away and you see:\n\n");
  command("look", this_player());
  view_obj=0;
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("Transporter Control");
  long_desc=
    "This is the transporter control room of this Klingon scout ship.  The\n"+
    "deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "There is a doorway leading to engineering.  You can use the ship's\n"+
    "transporters to go to certain locations with:\n"+
    "   coordinates <location> - lock the coordinates into the transporters\n"+
    "                            (due to computer damage, the transporters\n"+
    "                             can only lock on to:\n"+
    "                                church, shop, pub, jetty, clearing,\n"+
    "                                the Enterprise or the Romulan ship\n"+
    "                                unless the transporter key is used\n"+
    "                                to link the transporters to the ship's\n"+
    "                                scanners, in which case, you won't\n"+
    "                                need the 'coordinates' command.)\n"+
    "   energize    - use transporters to go to the coordinates\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "ladder", "A steel runged ladder leading through the plates "+
                "of the floor",
      "transporter", "The transporters are out of reach beyond a wall of\n"+
                "transparent aluminium.  You can command them\n"+
                "via the two commands that the computer understands\n",
      "transporters", "The transporters are out of reach beyond a wall of\n"+
                 "transparent aluminium.  You can command them\n"+
                 "via the two commands that the computer understands\n",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_engineering", "starboard",
    });
  return;
}

realm() { return "NT"; }
