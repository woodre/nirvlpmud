inherit "/players/persephone/closed/thingys.c";
string openning;
string unlocked;
#include "/players/persephone/rooms.h"

reset(arg){
 if(!arg){
  unlocked="no";
  openning="no";
  set_light(1);
  short_desc="Cell Block Corridor";
  long_desc="You have found where the residents of Stormhold use to keep their\n" +
            "criminals no however the cells appear to be empty however, you seem to\n" +
            "hear a noise from the west cell. Perhaps you should check it out.\n" +
            "Back to the south you see the main room of the police station while\n" +
            "while to the North you can see a great deal of rubble.\n";
  items=({"cells","The cells look like any normal jail cells with bars\n" +
                  "facing on to the corridor and barred windows looking out.\n" +
                  "They have the standard jail cots and sanitary facilities",
          "criminals","There are no criminals here in fact the jail feels\n" +
                      "empty",
          "office","The office is empty",
          "residents","There are no residents of Stormhold around",
          "bars","Big steel bars you definately could not force them\n" +
                 "or break them without the proper equipment",
          "doors","Both the western and eastern cell doors appear to be\n" + 
                  "securely locked. However on closer inspection you think\n" +
                  "you can unlock the western door if you found a key\n\n",
          "key","You cannot see any key around here\n\n",
          "door","Both the western and eastern cell doors appear to be\n" + 
                  "securely locked. However on closer inspection you think\n" +
                  "you can unlock the western door if you found a key\n\n",
          "keyhole","Upon examining the keyhole you discover that a skeleton\n" +
                    "key would probably unlock the door\n\n",
          "equipment","What equipment? Anyway how are you trying\n" +
                      "to break out of jail",
          "cot","Just a mattress really but you would have to get closer\n" +
                "to find out",
          "rubble","It appears someone tried breakout of jail and used\n" +
                   "a bit much dynamite. You feel however you might\n" +
                   "be able to find a path throught the dynamite",
          "windows","The windows are small",
          "ceiling","Reinforced concrete in fact it looks like the same\n" +
                    "stuff as the rubble",
          "floor","The floor is white and like the ceiling made of concrete",
          "noise","It is a low moaning and is definitely coming from the\n" +
                  "west cell",
        });
  dest_dir=({"players/persephone/rooms/rubble","north",
             "players/persephone/rooms/pol_stat","south",
           });
 }
}
realm() { return "NT"; }
init(){
  ::init();
     add_action("pick","pick");
     add_action("unlock","unlock");
     add_action("open","open");
     add_action("close","close");
     add_action("wibbke","west");
     add_action("wibbke","w");
}
pick(str){
  if(str=="lock"||str=="door"||str=="celldoor"){
     write("As you try to pick the lock in the cell door you activate\n" +
           "a needle that jabs deeply in you finger and you cannot continue\n" +
           "picking the lock\n\n");
     say(CAPTPLNM + " tries to pick the lock but fails miserably\n\n");
  return 1;
   }
  write("What do you think you are trying to pick???\n");
return 1;
}

unlock(str) {
    string door, key;
    object ob, *obs;
    int i, num, cnt;

    notify_fail("Unlock what?\n");
    if (!str)
        return 0;
    if (sscanf(str, "%s with %s", door, key) < 2) {
        door = str;
        key = "key";
    }
    if (door != "lock" && door != "door" && door != "celldoor")
        return 0;

    obs = all_inventory(this_player());
    for (i=0, num=-1, cnt=0 ; i<sizeof(obs) ; i++)
        if (obs[i]->id(key)) {
            num = i;
            cnt++;
        }

    notify_fail("Unlock it with what?\n");
    if (num < 0)
        return 0;

    notify_fail("Unlock it with which " + key + "?\n");
    if (cnt > 1)
        return 0;

    notify_fail(obs[num]->short() + " does not fit.\n");
    if (!obs[num]->id("skeleton key"))
        return 0;

    write("You hear a loud click as you unlock the door with\n" +
          "the large skeleton key\n\n");
    say(CAPTPLNM + " turns the key in the lock and you hear a loud\n" +
                   "clicking noise.\n\n");
    unlocked="yes";

    return 1;
}
open (str){
  if(str=="cell"||str=="door"){
    if(unlocked=="yes"){
      write("You open the cell door to the west.\n");
      say(CAPTPLNM + "opens the door into the cell\n");
      long_desc="You have found where the residents of Stormhold use to keep their\n" +
                "criminals no however the cells appear to be empty however, you seem to\n" +
                "hear a noise from the west cell. Perhaps you should check it out.\n" +
                "Back to the south you see the main room of the police station while\n" +
                "while to the North you can see a great deal of rubble and an open door leading west.\n";

      openning="yes";
    return 1;
    }
    write("You cannot open the locked door perhaps you should\n" +
          "unlock it.\n");
    say(CAPTPLNM + " tries to open the locked door\n\n");
  return 1;
  }
  write("What do you want to open?\n");
return 1;
}
close (str){
  if(str=="door"||str=="cell"){
    write("You close the door and for safety lock it behind you\n");
    say(CAPTPLNM + " closes the door behind them\n");
    long_desc="You have found where the residents of Stormhold use to keep their\n" +
              "criminals no however the cells appear to be empty however, you seem to\n" +
              "hear a noise from the west cell. Perhaps you should check it out.\n" +
              "Back to the south you see the main room of the police station while\n" +
              "while to the North you can see a great deal of rubble.\n";
    openning="no";
    unlocked="no";
  return 1;
  }
  write ("What do you wish to close??\n");
return 1;
}
wibbke()
{
  if(openning=="yes"){
    write("You enter the western cell through the open cell door.\n");
  TPL->move_player("west through the cell door#"+"players/persephone/rooms/cells");
  return 1;
  }
  write("You walk into the closed cell door!!!\n");
   say(CAPTPLNM + " walks into the closed cell door.\n");
return 1;
}
