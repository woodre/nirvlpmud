#define max 7
inherit "/room/room";
object meme;
object ob;
string tat_list;
string whois;
string tat_name;
int tik;
int tat_amt;
int working;
int count;
reset(arg) {
  if(arg) return;
  count=0;
  working=0;
  whois="Pacoisinthechair";
  meme=find_living("sdflkjwlekfjsdlk");;
  tat_list=allocate(max+1);
  tat_list[1]="a rose.";
  tat_list[2]="a skull.";
  tat_list[3]="a heart.";
  tat_list[4]="a sword.";
  tat_list[5]="a shield.";
  tat_list[6]="a babe.";
  tat_list[7]="a hunk.";
  tik=1;
  tat_amt=0;
  tat_name="Nothin";
  short_desc="Paco's Tatoo Shop";
  long_desc="This is Paco's Tatoo Shop.  In here you can get permanent\n"+
"tatoos to show yourself off; to prove how macho you are; to display your\n"+
"love to your girlfriend/boyfriend; etc; etc.  Here's what you can do:\n"+
"      sit                      sit in Paco's state of the art stool\n"+
"      stand                    get out of Paco's state of the art stool\n"+
"      buy tatoo       $500     purchase an already designed tatoo\n"+
"      buy special     $1000    design your own tatoo\n"+
"      remove tatoo    $1000    using state of the art hammers and chisels\n"+
"                                 get your tatoo removed\n"+
"      tip paco        $100     give Paco a tip on his excellence\n\n";
  dest_dir=({
             "/players/grimm/closed/mall/hall1","east",
           });
  set_heart_beat(1);
}

init() {
  ::init();
  add_action("east","east",1);
  add_action("tip","tip");
  add_action("sit","sit");
  add_action("buy","buy");
  add_action("remove","remove");
  add_action("stand","stand");
}

tip(str) {
  if(!str) {
    write("Tip who?\n");
    return 1;
  }
  if(this_player()->query_money()<100) {
    write("Paco yells: You try to cheat me outta my tip? Get the hell outta my store.\n");
    say(capitalize(this_player()->query_name())+" tries to cheat Paco out of a tip and\ngets thrown out of the store.\n");
    command("east",this_player());
    return 1;
  }
  this_player()->add_money(-100);
  write("Paco thanks you for the tip.\n");
  say(capitalize(this_player()->query_name())+" tips Paco.\n");
  return 1;
}

east() {
  if(whois==this_player()->query_real_name()) {
    whois="Pacoisinthechair";
    meme=find_player("sdlkjsdlfkwjodijf");
    count=0;
    working=0;
  }
  this_player()->move_player("east#/players/grimm/closed/mall/hall1");
  return 1;
}

sit() {
/*
  if(whois!="Pacoisinthechair") {
*/
  if(working) {
    write(capitalize(whois)+" is already in the chair.  Try again in a few mins.\n");
    return 1;
  }
  whois=this_player()->query_real_name();
  meme=this_player();
  write("Paco grabs you by the arm and straps you into his chair.\n");
  say("Paco straps "+capitalize(whois)+" into his chair.\n");
  return 1;
}

stand() {
  if(whois!=this_player()->query_real_name()) {
    write("You are not in the chair!\n");
    return 1;
  }
  if(working) {
    write("Paco is still working.  You wouldn't want to mess up his work of\n"+
          "art now would you?\n");
    return 1;
  }
  write("Paco reluctantly releases you from the chair and then demands a tip.\n");
  say(capitalize(whois)+" is reluctantly released from the chair.\n");
  whois="Pachoisinthechair";
  meme=find_living("sdflkjwlekfjsdlk");;
  count=0;
  working=0;
  return 1;
}

remove(str) {
  if(!str) {
    return; }
  if(str!="tatoo") return;
  if(whois!=this_player()->query_real_name()) {
    write("You are not in the chair!\n");
    return 1;
  }
  if(working) {
    write("Paco is already working on you.  Try again in a few mins.\n");
    return 1;
  }
  if(!present("tatoo",this_player())) {
    write("You need to GET a tatoo before you can have it removed!\n");
    return 1;
  }
  if(this_player()->query_money()<1000) {
    write("Paco yells: You ain't got enuf money for dat.\n");
    return 1;
  }
  this_player()->add_money(-1000);
  working=1;
  count=1;
  write("Paco pulls his rusty tools out of his pocket and proceedes to\n"+
        "go to work to remove your tatoo.\n(be patient...this may take a little while)\n");
  say(capitalize(whois)+" sits down to get a tatoo removed.\n");
  return 1;
}

heart_beat() {
if(tik==2) {
  tik=0;
  if(meme) {
    if(working==1) {
       if(count==1)
         tb("Paco rev's up his sander.\n","Paco rev's up his sander.\n");
       if(count==2)
         tb("Paco takes a HUGE swig of tequilla.\n","Paco pads his brow.\n");
       if(count==4)
         tb("Paco puts crisco on your arm (to stop any flames).\n"
            ,"Paco applies an anti-burning chemical to "+capitalize(whois)+
            "'s arm.\n");
       if(count==8)
         tb("Paco takes another HUGE swig of tequilla.\n",
            "Paco pads his brow.\n");
       if(count==16)
         tb("Paco puts all his weight behind the sander.\n"+
            "(Your arm feels like it is going to fall off)\n",
            "Paco lightly brushes "+capitalize(whois)+"'s arm with "+
            "the sander.\n");
       if(count==32) {
         tb("Paco steps back to admire his work.\nPaco grins and exposes "+
            "his two black teeth.\n",
            "Paco steps back to admire his work.\n");
        destruct(present("tatoo",meme));
        count=0;
        working=0;
       }
    }
    if(working==2) {
      if(count==1)
        tb("Paco rev's up his drill set.\n","Paco rev's up his drill set.\n");
      if(count==2)
        tb("Paco bores down into your arm with the rusty drill.\n",
           "Paco gently applies pressure to "+capitalize(whois)+"'s arm.\n");
      if(count==4)
        tb("Paco pauses to take a HUGE swig of tequilla.\n",
           "Paco pauses to pad his brow.\n");
      if(count==8)
        tb("Paco curses and attempts to correct his mistake.\n",
           "Paco moves like an artist.\n");
      if(count==16)
        tb("Paco takes another swig of tequilla.\n",
           "Paco pads his brow again.\n");
      if(count==32)
        tb("Paco fans at your arm to distill the smoke.\n",
           "Paco fans at "+capitalize(whois)+"'s arm to allow his artwork"+
           " to dry.\n");
      if(count==64) {
        tb("Paco steps back to admire his work.\n"+
           "(Your arm is throbing so much you wonder if it is still there)\n",
           "Paco steps back to admire his work.\n");
        count=0;
        working=0;
        ob=clone_object("/players/grimm/closed/mall/tatoo");
        ob->set_my_tat(tat_name);
        move_object(ob,meme);
      }
    }
  }
  count+=count;
}
tik++;
}

tb(me,them) {
  tell_object(meme,me);
  tell_room(environment(meme),them);
  return 1;
}

buy(str) {
  if(whois!=this_player()->query_real_name()) {
    write("You are not sitting in the chair.\n");
    return 1;
  }
  if(working) {
    write("Paco is still working.  Wait until he is done.\n");
    return 1;
  }
  if(present("tatoo",this_player())) {
    write("Paco says: You already have a tatoo!\n");
    return 1;
  }
  if(!str) {
    write("What do you want to buy?\n");
    return 1;
  }
  if(!(str=="tatoo" || str=="special")) {
    write("What do you want to buy?\n");
    return 1;
  }
  if((str=="tatoo" && this_player()->query_money()<500) ||
     (str=="special" && this_player()->query_money()<1000)) {
    write("Paco yells: You tryin to cheat me? You don't have enuf for that.\n");
    return 1;
  }
  if(str=="tatoo") {
    tat_amt=500;
    tat_menu();
    return 1;
  }
  tat_amt=1000;
  write("Paco says: Your tatoo will appear as \"A tatoo of XXXXX\"\n");
  write("Paco says: I need you to fill in the XXXXX space.\n");
  write("\n\nA tatoo of ");
  input_to("get_tat_name");
  return 1;
}

get_tat_name(str) {
  if(!str) {
    write("\nAborted.\n\nPaco says: come back when you make up your mind.\n");
    return 1;
  }
  tat_name=str;
  write("\nPacos says: \"A tatoo of "+tat_name+"\"\n");
  write("Paco says: is that right?\n");
  write("Type \"yes\" or \"no\": ");
  input_to("check_tat_name");
  return 1;
}

check_tat_name(str) {
  if(!str) {
    write("\nAborted.\n\nPaco says: come back when you make up your mind.\n");
    return 1;
  }
  if(str=="no" || str=="NO" || str=="No" || str=="n" || str=="N") {
    buy("special");
    return 1;
  }
  write("Paco says: okey, hang on while I get my drills\n");
  write("(be patient, this may take a little while)\n");
  working=2;
  count=1;
  meme=this_player();
  this_player()->add_money(-tat_amt);
  return 1;
}

tat_menu() {
  int i;
  write("The following are predesigned tatoos you can choose from.\n");
  for(i=1;i<max+1;i++)
    write("    "+i+".    A tatoo of "+tat_list[i]+"\n");
  write("\nWhich would you like? (enter the number): ");
  input_to("get_from_menu");
  return 1;
}

get_from_menu(str) {
  int x;
  if(!str) {
    write("\nAborted.\n\nPaco says: Come back when you make up your mind.\n");
    return 1;
  }
  if(!sscanf(str,"%d",x)) {
    write("\nIllegal entry.\n\nPaco says: Try again.\n");
    return 1;
  }
  if(x<1 || x>max) {
    write("\nIllegal entry.\n\nPaco says: Try again.\n");
  }
  tat_name=tat_list[x];
  this_player()->add_money(-tat_amt);
  working=2;
  count=1;
  write("Paco says: okey, lemme get my drill set.\n"+
        "(be patient, this may take a little while)\n");
  return 1;
}
