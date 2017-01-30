#include "/players/illarion/dfns.h"
#define CLONE_OB "/players/illarion/clone/clone_ob.c"
#define CLONE_ID "illarion_clone_cylinders"
#define INCUBATE_HOURS 96
inherit "/room/room";

object cylinders;

void reset(status arg) {
  if(!(cylinders=present(CLONE_ID))) {
    call_other(CLONE_OB,"XXX");
    cylinders=find_object(CLONE_OB);
    move_object(cylinders);
  }
  if(arg) return;
  set_light(1);
  short_desc="The cloning chambers";
  long_desc=
    "You are in immense chambers made primarily of brushed steel and glass.\n"+
    "Flashing lights and cryptic computer displays are everywhere.  In the\n"+
    "center of the room is a larger and more approachable-looking console.\n"+
    "A pair of double doors stand open at the south end of the room.\n";

  add_item("steel","Brushed, reflective steel, cold and sterile");
  add_item("glass","The glass seems to have been placed for aesthetic reasons\n"+
      "rather than functional ones; it covers some of the flashing\n"+
      "lights");
  add_item("console","Unlike the other equipment in the room, it looks like you\n"+
      "could \"use\" this console");
  add_item("lights","All around the room, display lights blink on and off in\n"+
      "bewildering but hypnotic fashion");
  add_item("displays","You can't make any sense of most of the readouts- they\n"+
      "display unfamiliar symbols that change every so often");

  add_exit("room/church","south");

}

void init() {
  ::init();
  add_action("cmd_use","use");
  add_action("cmd_input","input");
}

status cmd_use(string str) {
  if(str!="console") FAIL("Use what?\n");
  write("You fiddle with the console a bit and manage to make it print\n"+
        "out a help screen.\n");
  say(NAME(TP)+" fiddles with the console.\n");
  write("This console supports the following commands:\n"
       +"information                              free\n"
       +"status                                   free\n"
       +"order                                  80,000\n"
       +"expidite                               80,000\n"
       +"cancel                                   free\n");
  write("To enter a command, use \"input\".\n");
  return 1;
}

status cmd_input(string str) {
  string info;
  string name;
  string incub_time;
  int day,hour,min;
  mixed customer_data;
  int customer_time;
  int now;
  object kid;
  if(!str) FAIL("Input what command to the console?\n");
  if(sscanf(str,"information %s",info))
    str="information";
  write("You input a command into the console.\n"
       +"It prints out the following response:\n");
  say(NAME(TP)+" inputs a command into the console.\n");
  name=TPRN;
  now=time();
  switch(str) {
    case "information":
      switch(info) {
        case "information": default:
          write("This command gives information on the other commands.\n"
               +"Use \"input information <command>\" to get this information.\n");
          return 1;
        case "status":
          write("Lets you check wether you have a clone being grown, and\n"
               +"how long until it's finished.  If your clone is finished,\n"
               +"using this command will cause it to be delivered to you.\n");
          return 1;
        case "order":
          write("Allows you to order a clone of yourself, grown to infancy\n"
               +"and then released for you to raise as you wish.  Clones take\n"
               +"three days to mature.\n");
          return 1;
        case "expidite":
          write("Though it's dangerous, we can attempt to deliver your clone\n"+
                "to you sooner.  However, the process is risky, and may kill\n"+
                "the clone.  If the clone dies, you will not be charged the\n"+
                "expidiation fee, but any other money you have spent will not\n"+
                "be refunded.  The closer a clone is to maturity, the more\n"+
                "risky it is to speed its development.\n");
          return 1;
        case "cancel":
          write("Cancel the growing of your clone.  It is immediately destroyed.\n"+
                "You will not be refunded any of the money you have spent.\n");
          return 1;
      } 
    case "status":
      customer_data=(mixed)cylinders->check_customer(name);
      if(!customer_data) {
        write("We are not currently incubating a clone for you.\n");
        return 1;
      }
      customer_time=customer_data[0];
      customer_time-=now;
      if(customer_time <= 0) {
        write("Congratulations!  Your clone is ready!\n");
        kid=clone_object("obj/kid");
        kid->set_gender(customer_data[1]?"female":"male");
        kid->set_name("baby");
        kid->set_hp(30);
        kid->set_short(capitalize(name)+"'s baby");
        kid->set_long("A little newborn baby.\n");
        kid->set_parent(name);
        kid->set_nparents(name+"#-*unknown*-");
        kid->set_level(1);
        kid->set_chat_chance(10);
        kid->load_chat("The baby cries.\n");
        kid->load_chat("The baby drools.\n");
        kid->load_chat("The baby smiles.\n");
        kid->load_chat("The baby says: OOGA BOOGA MMOOMY\n");
        kid->load_chat("The baby says: OCA PYUPY ORCI SUM\n");
        move_object(clone_object("obj/soul"),kid);
        move_object(kid,TP);
        tell_room(TO,"A steel and glass cylinder rises up out of the floor,\n"+
                     "and slides open to reveal an infant.\n");
        write("You take your new baby from the cylinder.\n"
             +"You can name your child with \"childname <name>\".\n");
        say(TPN+" takes "+POS(TP)+" new child from the cylinder.\n");
        cylinders->remove_customer(name);
        return 1;
      } else {
        incub_time="";
        day=customer_time/86400;
        if(day) incub_time+=" "+day+" day"+(day==1?"":"s");
        customer_time -= day*86400;
        hour=customer_time/3600;
        if(hour || incub_time!="") incub_time+=" "+hour+"hour"+(hour==1?"":"s");
        customer_time -= hour*3600;
        min=customer_time/60;
        incub_time+= " "+min+"minute"+(min==1?"":"s");
        write("Your clone will be done in"+incub_time+".\n");
        return 1;
      }
    case "order":
    case "default":
      write("Sorry, that command is not supported.\n");
      return 1;
  }
}
        

        
        
        
      
        