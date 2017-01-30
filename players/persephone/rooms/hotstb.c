inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
string unlocked;
string revealed;
string isopen;
reset(arg){
 if (!arg) {
  unlocked="no";
  revealed="no";
  isopen="no";
  set_light(0);
  short_desc="Third Floor Landing";
 long_desc="You have reached the third floor of this prestigious hotel and the\n" +
            "top of the stairs however you are certain that there should be another\n" +
           "floor to the hotel. To the south through a doorway you see a corridor\n" +
           "while the stairs only appear to go down. Above your head there is a\n" +
           "strange looking hook.\n" +
           "\n";
items=({"stairs","You know the things you are walking up. Actually they appear to be\n" +
                   "made of beautiful white marble inlaid with intricate designs",
          "corridor","It looks like an ordinary hotel corridor to you except the carpet\n" +
                     "appears to be very fine quality",
           "sign","Just one of those signs that tells you the room numbers of the level\n" +
                 "perhaps if you wiped the sign you might be able to read it",
          "light","Yep you guessed it the light globe is blown",
          "marble","It appears to be the finest quality Italian White Marble",
          "carpet","Nothing but the finest Berber available made with beautiful\n" +
                   "Tasmanian wool.",
           "wool","Tasmanian wool and therefore you know it is good, perhaps even the\n" +
                 "best available wool",
           "hook","This hook looks extremely strange almost as if it is meant to be pulled.\n" +
                  "Perhaps you should try pulling it and seeing what happens",
           "ceiling","The ceiling here looks as if it is out of place perhaps it has\n" +
                     "something to do with the hook",
            });
  dest_dir=({"players/persephone/rooms/hcorr3a","south",
             "players/persephone/rooms/hotsta","down"
  });
 }
}
realm() { return "NT"; }
init(){
  ::init();
     add_action("pull","pull");
     add_action("pick","pick");
     add_action("unlock","unlock");
     add_action("open","open");
     add_action("close","close");
     add_action("snizzle","up");
     add_action("snizzle","u");
}
pull(str) {
  if (str=="hook"||str=="handle"){
    write("You pull the hook out of the ceiling to reveal a round\n" +
          "shaped lock.\n\n");
    say(CAPTPLNM + " does not know his own strength he just pulled\n" +
        "the hook out of the ceiling\n\n");
    revealed="yes";
  return 1;
  }
  write("What do you want to pull? Someone's leg!\n");
return 1;
}
pick(str){
  if(str=="lock"||str=="door"||str=="hatch"){
    if(revealed=="yes"){
      write("As you try to pick the lock in the cell door you activate\n" +
            "a needle that jabs deeply in you finger and you cannot continue\n" +
            "picking the lock\n\n");
      say(CAPTPLNM + " tries to pick the lock but fails miserably\n\n");
    return 1;
    }
    write("You cannot see a lock to pick\n");
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
    if (door != "lock" && door != "door" && door != "hatch")
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
    if (!obs[num]->id("adamentite key"))
        return 0;

    write("As you insert the key the hatch drops down slightly so \n" +
          "that you think you can open it\n\n");
    say(CAPTPLNM + " inserts the key in the lock and the hatch above\n" +
                   "you lowers itself slightly.\n\n");
    unlocked="yes";

    return 1;
}
open (str){
  if(str=="hatch"||str=="door"){
    if(unlocked=="yes"){
      write("You pull open the hatch above you revealing a set.\n" + 
            "a set of stairs leading up\n");
      say(CAPTPLNM + "pulls down the hatch\n");
 long_desc="You have reached the third floor of this prestigious hotel and the\n " +
      "top of the stairs however you are certain that there should be another\n" +
      "floor to the hotel. To the south through a doorway you see a corridor\n" +
      "while stairs lead both up and down.\n" +
           "\n";
      isopen="yes";

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
  if(str=="door"||str=="hatch"){
    write("You close the door and for safety lock it behind you\n");
    say(CAPTPLNM + " closes the door behind them\n");
 long_desc="You have rrd floor of this prestigious hotel and the\n" +
            "top of the stairs however you are certain that there should be another\n" +
           "floor to the hotel. To the south through a doorway you see a corridor\n" +
           "while the stairs only appear to go down. Above your head there is a\n" +
           "strange looking hook.\n" +
           "\n";
    unlocked="no";
    isopen="no";
  return 1;
  }
  write ("What do you wish to unlock??\n");
return 1;
}
snizzle(){
 if(isopen=="yes"){
    write("YOU tread wearily up the stairs not knowing what AWAITS YOU.\n");
  this_player()->move_player("up the stairs#"+"players/persephone/rooms/ch_att");
  return 1;
  }
  write("You try to walk up the wall\n");
return 1;
}
