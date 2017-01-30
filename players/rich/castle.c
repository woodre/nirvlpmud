#define NAME "rich"
#define DEST "room/mount_top"
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

id(str){
	return str == "point";
}

short() {
return "The beam-up point to the Enterprise(type energize)";
}

long() {
write("This is the main beam-up point for the Starship Enterprise.\n");
write("To enter type 'energize', Please visit often as the ship is under\n");
write("construction, so please visit often to keep in touch with\n");
write("reality.  thank you the management!\n");
}

     string dest;
       int rand;
init() {
object test,ob,ob1,test1;
/*
    if(!present("diaper",this_object())) {
    ob=clone_object("players/haji/closed/diap.c");
    move_object(ob,this_object());
   }
       test1=find_object("room/quest_room");
         if(!present("trekkie",test1)) {
          object ob3;
            ob3=clone_object("obj/quest_obj");
          call_other(ob3,"set_name","trekkie");
          call_other(ob3,"set_hint","Find the Ultimate Trekkie with" +
             " the videotape,\n `The Lost Episodes of Star Trek'\n" +
             "Find the Jeffries Tube and toss the tape.\n");
             move_object(ob3,test1);
 }
 */
  add_action("energize", "energize");
}

energize() {
    write("You have a strange feeling.\n");
    write("You see your see your own body from above.\n");
    write("You`re not dead.\n");
    write("You are in a transporter beam.\n");
    write("You rematerialize.\n");
    write("\n\n\n");
    write("To get healed either go all the way n to pub,\n");
    write("or go to upper level all the way s in main hallway.\n");
    write("To sell something go to the quartermasters[n,n,w,n].\n");
    write("\n\n\n");
    write("also if you have any characters related to sci-fi you would like\n");
    write("to kill,send me(rich) a mail message and i`ll see what i can do.\n");
    write("\n\n");
call_other(this_player(), "move_player", "into ship#players/rich/trans_room.c");
    return 1;
}

reset(arg) {
    object local,who;
    object test1,test2,ob2,ob3;
      int count;
     dest=allocate(10);
       dest[0]="room/vill_green";
       dest[1]="room/sea";
       dest[2]="room/south/sforst2";
       dest[3]="room/wiz_hall";
       dest[4]="room/vill_road2";
       dest[5]="room/clearing";
       dest[6]="room/forest1";
       dest[7]="room/adv_guild";
       dest[8]="room/plane8";
       dest[9]="room/ruin";
      rand=random(10);
      local=find_object(dest[rand]);

   call_other("room/church","???");
    test2=find_object("room/church");
        if(!present("computer",test2)) {
            ob2=clone_object("players/rich/locate.c");
              move_object(ob2,test2);
            }
     call_other("players/rich/trans_room","set_dest",dest[rand]);
    emit_channel("junk","You see the Enterprise move overhead...\n"+
                        "It looks like it is changing its orbit.\n");
    if (arg)
	return;
      call_other(dest[rand], "???");
      call_other("players/rich/lower/scotty","???");
      local = find_object(dest[rand]);
      move_object(this_object(),local);
       test1=find_object("room/quest_room");
         if(!present("trekkie",test1)) {
            ob3=clone_object("obj/quest_obj");
          call_other(ob3,"set_name","trekkie");
          call_other(ob3,"set_hint","Find the Ultimate Trekkie with" +
             " the videotape,\n `The Lost Episodes of Star Trek'\n" +
             "Find the Jeffries Tube and toss the tape.\n");
             move_object(ob3,test1);
 }
}
query_location() {
    return dest[rand];
   }
init1() {
object test,ob,ob1,test1;
/*
    if(!present("diaper",this_object())) {
    ob=clone_object("players/haji/closed/diap.c");
    move_object(ob,this_object());
   }
 */
       test1=find_object("room/quest_room");
         if(!present("trekkie",test1)) {
          object ob3;
            ob3=clone_object("obj/quest_obj");
          call_other(ob3,"set_name","trekkie");
          call_other(ob3,"set_hint","Find the Ultimate Trekkie with" +
             " the videotape,\n `The Lost Episodes of Star Trek'\n" +
             "Find the Jeffries Tube and toss the tape.\n");
             move_object(ob3,test1);
 }
}

is_castle() { return 1;}
