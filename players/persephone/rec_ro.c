inherit "room/room";
object cha;
reset(int arg){
 if (arg) return;
  set_light(1);
  short_desc="Relaxation Room";
  long_desc="As you entered this large room you could not help but be astounded\n" +
            "by the decore indeed after the perils of adventuring it appears\n" +
            "quite relaxing. Immediately in front of you is the large and\n" +
            "inviting pool while in the middle of the North Wall is a large door\n" +
            "that leads on to the spa and the mage sauna. Placed strategically\n" +
            "around the room are large chairs and tables. In the middle\n" +
            "of the floor is a large important looking plaque\n" +
            "\n";
  items=({"floor","The floor is highly polished yet not slippery and you can\n" +
                  "see your reflection in it. Unfortunately you cannot determine the\n" +
                  "the type of stone it is made from but it appears to have magical\n" +
                  "properties",
          "ceiling","The ceiling is high and vaulted and appears to be made of\n" +
                    "the same magical material",
          "walls","The walls are covered with pictures both magical and\n" +
                  "fascinating.  As you examine the walls closely you\n" +
                  "notice that they are filled with a magical aura",
          "pictures","These are masterpieces from the magical and real\n" +
                     "world.  There are many that your recognise.\n" +
                     "One particular painting grabs your attention",
          "painting","This is a portrait of the greatest mage Nirvana has\n" +
                     "ever seen.  Yes you guessed it Merlyn depicting his\n" +
                     "triumph over the haters of magic and other\n" +
                     "arcane arts",
          "chairs","These chairs look quite relaxing and comfortable\n" +
                   "perhaps you should sit down in one of them and relax",
          "plants","These are the magical plants that give mages their powers\n" +
                   "do not damage these exquisite plants or you might destroy\n" +
                   "the very fabric of Nirvana",
          "lights","The lights appear to be large balls of a dark fire\n" +
                   "but they add a mysterious comfort to the room",
          "pool","The pool looks exquisite in its crescent moon shape\n" +
                 "and you feel somehow to be drawn towards it",
          "tables","The tables appear to be made out of a magical wood\n" +
                   "and are quite light but no matter how you try to lift\n" +
                   "them you cannot",
          "door","The door is made out of Adamentite and is obviously\n" +
                 "magical witha large sign made on the middle of it",
          "sign","The sign is made out of a black obsidian with mithril\n" +
                 "lettering that you might want to read",
          "sauna","You cannot see the Sauna from here but you have heard\n" +
                  "about its glory throughout the lands of Nirvana",
          "spa","You are unable to see the spa but legend has it the spa\n" +
                "has magical powers that assist in revitalisation of sore\n" +
                "and stiff bodies",
          "plaque","The plaque has large letters on it you might want to\n" +
                   "read it",
        });
  dest_dir=({
           });
}
init(){
 ::init();
  add_action("read1","read");
  add_action("read1","decipher");
  add_action("enter1","enter");
  add_action("enter1","down");
  add_action("dive1","dive");
  add_action("jump1","jump");
  add_action("sit1","sit");
  add_action("help1","help");
  add_action("run","run");
  add_action("push1","push");
      }
read1(str){
 if(str=="sign" || str=="note" || str=="writing"){
  write("\n" +
        "               Mage Guild Spa and Sauna.\n" +
        "               Please take care in both\n" +
        "               the spa and sauna. While\n" +
        "               Mages may suffer no ill\n" +
        "               effects in these rooms\n" +
        "               others may.\n" +
        "\n");
  say(capitalize(this_player()->query_real_name())+" deciphers the sign on the door.\n");
 return 1;
 }
 if (str=="plaque"){
  write("     If you need help on commands of how to get in the pool\n" +
        "     or use the chairs type help pool or help chair\n");
  say(capitalize(this_player()->query_real_name())+" reads the plaque.\n");
 return 1;
 }
 write("What are you trying to read\n");
 return 1;
}
enter1(str){
 if(str=="pool" || str=="water"){
  write("You slowly walk down the stairs into the pool relishing\n" +
        "the soothing water rising up your body\n");
  this_player()->move_player("walking down the stairs into the pool#","players/merlyn/closed/guild/proom");
  return 1;
 }
 write("You do a passable mime of climbing down some stairs mayb you\n" +
       "should try the pool\n");
 say(capitalize(this_player()->query_real_name())+" is acting like Marcel Marceau");
 return 1;
}
jump1(str){
 if(str=="pool" || str=="water"){
  write("You jump into the pool splashing every one around the edge of the pool\n");
  this_player()->move_player("jumps into the pool splashing you with water#","players/merlyn/closed/guild/proom");
  return 1;
 }
 write("No need to have a temper tantrum if you want to jump in the pool\n" +
       "jump into it\n");
 say(capitalize(this_player()->query_real_name())+" jumps up and down throwing a temper tantrum.\n");
 return 1;
}
dive1(str){
 if(str=="pool" || str=="water"){
  write("You perform a beautiful swan dive into the pool surprising everyone\n" +
        "with your prowess\n");
  this_player()->move_player("diving into the pool like an olympic champion#","players/merlyn/closed/guild/proom");
  return 1;
 }
 write ("You Dive into the hard stone floor you think you have cracked open your skull.\n" +
        "OUCH!!!!");
 say (capitalize(this_player()->query_real_name())+" Dives and lands flat on his head.\n");
 return 1;
}
sit1(str){
 if(str=="chair" || str=="settee" || str=="lounge" || str=="sofa"){
  cha=clone_object("players/merlyn/closed/guild/chair");
  move_object(cha,this_player());
  write("You sit down in a comfortable chair and enjoy the atmosphere\n" +
        "of the pool area.\n");
  say(capitalize(this_player()->query_real_name())+" sits down in a comfortable chair.\n");
  return 1;
 }
 write("You sit on your backside\n");
 say(capitalize(this_player()->query_real_name())+" sits on the floor you wonder why\n" +
     "they did not sit on a chair\n");
 return 1;
}
help1(str){
 if(str=="chair" || str=="chairs" || str=="settee" || str=="lounge" || str=="sofa"){
  write("\n" +
        "         To sit in one of these comfortable and\n" +
        "         relaxing chairs just type sit chair, sofa,\n" +
        "         lounge, settee.  In the chair you can sleep,\n" +
        "         recline, or relax buy just typing those\n" +
        "         commands. If you want further commands for\n" +
        "         the chairs please mail Merlyn or Persephone\n" +
        "\n");
  say (capitalize(this_player()->query_real_name())+" reads help entitled chairs\n");
 return 1;
 }
 if(str=="pool" || str=="water"){
  write("\n" +
        "This pool is for the use and enjoyment of Mages do not run\n" +
       "around the edge of the pool or push other people in if you\n" +
        "if you do you will be asked to leave the room and you could\n" +
        "possibly get hurt. If anyone misbehaves in this room\n" +
        "please report them to Merlyn or Persephone or the Guild commander\n" +
        "There are three different commands for entering the pool\n" +
        "1)..enter pool this is perhaps the safest way to enter it.\n" +
        "2)..dive pool this enables you to do a glorious swan dive.\n" +
        "3)..jump pool this allows you to jump into the pool splashing\n" +
        "    everyone around the pool.\n" +
        "For a list of commands in the pool type help pool when you\n" +
        "are in it\n" +
        "\n");
  say (capitalize(this_player()->query_real_name())+" reads help entitled pool\n");
 return 1;
 }
}
run(){
 write("You run around the outside of the pool like a little child.\n");
 say(capitalize(this_player()->query_real_name())+ " runs around the pool like a child\n" +
     "perhaps they should be reported.\n");
return 1;
}
