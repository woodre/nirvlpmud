inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
string unlocked;
string openning;
reset(arg){
 if (!arg) {
  unlocked="no";
openning="no";
 short_desc="Hotel Corridor";
 long_desc="This is the end of the third floor corridor which continues to the west\n" +
           "There is a large painting on the south wall and some sort of red box on\n" +
           "the north wall other than these items this corridor appears to be gothic\n" +
           "including the imposing set of double doors in the east wall\n";
  items=({"doors","They look as if they have come straight out of the louvre\n" +
                  "and have two large and ornate handles with an intricate\n" +
                  "looking lock on the left hand door\n",
          "lock","It looks fare to complex to pick and rather out of place\n" +
                 "as you think it requires one of those plastic keys\n",
          "box","A red box that looks like a fire alarm box with the glass\n" +
                "still in it and a button that says push in case of fire\n",
          "painting","A classic painting of the old ones of the earth including\n" +
                     "Shogoths and as you look closely you can even see the\n" +
                     "Necromicon\n\n",
         });
  dest_dir=({"players/persephone/rooms/hcorr3a","west",
           });
 }
}
realm(){ return "NT"; }
init(){
  ::init();
     add_action("pick","pick");
     add_action("unlock","unlock");
     add_action("open","open");
     add_action("close","close");
     add_action("wibble","east");
     add_action("wibble","e");
}
pick(str){
  if(str=="lock"||str=="door"||str=="frenchdoor"){
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
    if (door != "lock" && door != "door" && door != "frenchdoor")
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
    if (!obs[num]->id("plastic key"))
        return 0;

    write("You hear a click as you unlock the door with\n" +
          "the large plastic key\n\n");
    say(CAPTPLNM + " inserts the card in the lock and you hear a\n" +
                   "clicking noise.\n\n");
    unlocked="yes";

    return 1;
}
open (str){
  if(str=="frenchdoor"||str=="door"||str=="doors"){
    if(unlocked=="yes"){
      write("You open the big Frenchdoors in the eastern wall.\n");
      say(CAPTPLNM + " opens the french doors leading east\n");
 long_desc="This is the end of the third floor corridor which continues to the west\n" +
           "There is a large painting on the south wall and some sort of red box on\n" +
           "the north wall other than these items this corridor appears to be gothic\n" +
           "including the imposing set of open double doors in the east wall\n" +
           "leading into a grand room\n";
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
  if(str=="door"||str=="doors"){
    write("You close the door and for safety lock it behind you\n");
    say(CAPTPLNM + " closes the door behind them\n");
 long_desc="This is the end of the third floor corridor which continues to the west\n" +
           "There is a large painting on the south wall and some sort of red box on\n" +
           "the north wall other than these items this corridor appears to be gothic\n" +
           "including the imposing set of double doors in the east wall\n";
    unlocked="no";
     openning=="no";
  return 1;
  }
  write ("What do you wish to unlock??\n");
return 1;
}
wibble(){
  if(openning=="yes"){
    write ("You head east through the open frecnh doors\n");
    TPL->move_player("east through the french doors#"+"players/persephone/rooms/rsuite");
  return 1;
  }
  write ("You foolishly walk into the closed french doors. OUCH!!!!\n");
  say(CAPTPLNM + " walks in the closed door and winces in pain\n");
return 1;
}
