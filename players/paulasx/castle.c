#define NAME "paula"
#define DEST "room/orc_dump"

 id(str) { return str == "temple"; }
       
       short() {
           return "(* Temple of Bishamon *)   --pray to enter--";
       }
       
      long() {
          write("This is the Temple of Bishamon.  It used to be one of\n" +
                "the Holyest places in the land, but alas, the demons\n" +
                "sent by Benju Matsutomo, the arch lord to Satan, have\n" +
                "taken over.  The Temple is in ruins, with thieves and\n" +
                "bandits throughout.  At the top floor of the temple is\n" +
                "the Diamyo of Aru, the last of the priests in the land.\n" +
                "Unfortunately, he is losing the battle against evil....\n" +
                "The Temple will surely perish... all will be lost...\n\n");
          write("The gates to the Temple have been barred shut.\n");
      }
init() {
  add_action("move", "pray");
}

move() {
    object ob;
    call_other(this_player(),"move_player", "north" + "#" + "players/paulasx/temple/temple_entrance");
    return 1;
}


  object ob, room;
reset(arg) {
    if (arg)
        return;
room=find_object("room/quest_room");
          if(!present("temple_quest",room)) {
            ob=clone_object("/obj/quest_obj");
            ob->set_name("temple_quest");
            ob->set_hint("Seek Deacon Thomas in the Temple of Bishamon, ask about the Diamyo.\n");
            move_object(ob,room);
          }
            move_object(this_object(), DEST);
}

is_castle() { return 1; } /* Duh! -Feldegast 10-8-00 */
