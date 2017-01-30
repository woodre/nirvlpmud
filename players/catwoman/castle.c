
#define NAME "Catwoman"
#define DEST "room/eastroad1"
object ob,ob2,ob3,ob5,room2;
object room,quest,quest2;
object shop;
object sta,road;
object qob;
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle"; }


short() {
 
    return "To the east you can see some sort of object floating in the air";
}

long() {
    write("there seems to be a path heading east.\n");
/*    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("just the same. However, the gates are closed.\n");*/
}

init() {
  add_action("east", "east");
}
east(){

        call_other(this_player(), "move_player", "east#players/catwoman/road2");
return 1;
 
}

reset(arg) {
/*
if (arg) return;
*/
move_object(this_object(),DEST);
if (ob) destruct(ob);
ob5 = clone_object("/players/catwoman/closed/ering");
/*
shop = clone_object("/players/catwoman/obj/menut");
if (shop) destruct(shop);
        room = find_object("room/quest_room");
        if (!present("chisel", room)){
                quest = clone_object("obj/quest_obj");
                quest->set_name("chisel");
                quest->set_hint("Kill the dragon give the tool to the old man.\n");
                move_object(quest,room);
                }
  took out this quest due to its rundown condition -Mythos
     4/25/20000
*/

if(!present("super",find_object("room/quest_room"))) {
  qob = clone_object("obj/quest_obj");
  call_other(qob,"set_name","super");
  call_other(qob,"set_hint",
    "Kill Superman\n"+
    "Read what is written on the shell of the clam in\n"+
    "the waters of Metropolis Bay.\n");
  move_object(qob,"room/quest_room");
}

      call_other("players/catwoman/road2", "???");
     road = find_object("players/catwoman/road2");
/*
     if(!present("statue",road)) {
        sta = clone_object("players/catwoman/stat1");
        move_object(sta,road);
     }
*/

}
is_castle(){return 1;}
