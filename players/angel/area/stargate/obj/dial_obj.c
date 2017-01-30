/*                                                                    *
 *    File:             /players/angel/area/stargate/obj/dial_obj.c   *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/07/08                                      *
 *    Notes:            Include file for Stargate                     *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
/*
#define OWNER "angel"

int shield; /* This is to prevent unwanted intruders. */
/*int cloak; /* This is for hiding the room's short. */
/*int locked; /* For preventing any conventional exits. */ 

init()
  {
    ::init();
    add_action("teleport",  "teleport");
    add_action("cmd_smell", "smell");
    add_action("cmd_listen","listen");
    add_action("teleport",  "tp");
    add_action("stop",      "north");
    add_action("stop",      "northeast");
    add_action("stop",      "east");
    add_action("dial",      "SG1N11");
    add_action("dial_02",   "ST3438");
    add_action("dial_03",   "P3X774");
    add_action("dial_04",   "PS2888");
/*  add_action("dial_05",   "W3S765");
    add_action("dial_06",   "EV4539");
    add_action("dial_07",   "TSD171");
    add_action("dial_08",   "HR6907");
    add_action("dial_09",   "SNO823");
    add_action("dial_10",   "PBJ748");
    add_action("dial_11",   "DKR239");
    add_action("dial_12",   "TWC542");
    add_action("dial_13",   "NHS989");
    add_action("dial_14",   "JLH736");
    add_action("dial_15",   "SSH612");*/
/*
if(this_player()->query_real_name()==OWNER) {
    add_action("shields","shields");
    add_action("cloak","cloak");
    add_action("locks","locks");
    add_action("scry","scry");
    add_action("gaze","gaze");
    add_action("escort","escort");
  }

if(this_player()->query_real_name() != OWNER && shield == 1) {
    write("You feel an electric shock and see a flash of white light.\n");
    write("Your body decenigrated before your eyes and your soul flees to Hell.\n");
    this_player()->move_player("off the shields#players/angel/closed/hell.c");

}
*/
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
/* display_file shows a file with a picture of the stargate\n\
 * each time they travel through */

/* prevents players from going into the base untill they kill the NPC */
stop() {
    if(present("sergeant", environment(this_player())))
      {write("The sergeant says: You are not allowed beyond this point.\n");
      say(this_player()->query_name()+", you are not allowed beyond this point.\n");
        return 1;
}}

dial(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/stargate/room/sg1.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_02(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/atlantis/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_03(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/nox/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_04(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/town/room/foyer.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_05(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/lowthar/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_06(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/elvandar/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_07(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/thanagar/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_08(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/acheron/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_09(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/arachnos/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_10(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/halla/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_11(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/kandahar/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_12(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/twilight/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_13(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/nulato/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_14(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/selangor/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

dial_15(str) {
	"/players/angel/closed/displays"->display_file("/players/angel/area/stargate/obj/gate");
    this_player()->move_player(
    " walks forward into the stargate to another world#/players/angel/area/gehenna/room/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
