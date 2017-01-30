#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("priest")) {
    move_object(clone_object("/players/mythos/amon/priest.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Shrine Center";
    long_desc =
    "You have reached the center of the shrine.\n"+
    "You see the main Priest standing before you.\n"+
    "The walls are made of sliding paper doors\n"+
    "and the floor is tatami.  You feel safe and\n"+
    "content here.  Here a soul may come back\n"+
    "and healing is done.\n";
  items = ({
    "north","You can make out a garden ",
    "east","You make out the east wing",
    "west","You see the west wing",
    "south","You see the main entrance",

  });

  dest_dir = ({
    "/players/mythos/aroom/shrinear2.c","north",
    "/players/mythos/aroom/shrinear3.c","east",  
    "/players/mythos/aroom/shrinear4.c","south",
    "/players/mythos/aroom/shrinear.c", "west",   
  });
} }

init() {
  ::init();
  add_action("pray","pray");
  add_action("heal","heal");
  add_action("ask","ask");
  add_action("cure","cure");
}

pray() {
if(this_player()->query_ghost() == 1) {
  if(!present("priest")) {
    write("Without a Priest, resurrections are not possible.\n");
  return 1; }
  else {
    say("The Priest nods and begins to incant softly...\n"+
      "He raises a hand and makes quick gestures....\n\n"+
      "\t"+CYN+">>>>>>>>>>FLASH<<<<<<<<<<"+NORM+"\n\n"+
      "A brilliant light strikes the shade of "+this_player()->query_real_name()+"!\n");
    write("The Priest nods at your request and begins to incant softly....\n"+
      "He raises a hand and makes quick gestures....\n"+
      "\n\t"+CYN+">>>>>>>>>>FLASH<<<<<<<<<<"+NORM+"\n\n"+
      "A flash of light explodes from the Priest's hand and engulfs you!\n");
    return call_other(this_player(),"remove_ghost",0);
}
return 1; }
  else{
    write("What are you thinking! \n"+"You are not DEAD!\n");
return 1;}
return 1; }

heal() {
  if(!present("priest")) {
    write("Without the Priest no healing can be done!");
    write("\n");
    return 1; }
  else {
  if(this_player()->query_attack()) {
    if(this_player()->query_money() < 20000) {
      write("Not only do you attack the healer, but you can not pay him!\n");
    return 1; }
    else {
      write("The Priest turns to you and says:\n"+
      "\n"+
        "\tThis is a peaceful place and I wish not to\n"+
      "\t"+
        "encourage violence.  However, I can not turn\n"+
        "\taway one in need, I will heal you.\n");
    write("\nThe Priest mumbles something and gestures at you....\n"+
      "\n"+
      "\t"+BLU+"\tFLASH\n\n"+NORM+
      "You feel much better....  The Priest, however, gives you a disapproving look.\n");
    say("The Priest mumbles something and points at "+tp+".\n"+
        "\n\t\t"+BLU+"FLASH\n\n"+NORM+
        "You see a bright light shoot out from the Priest's hand and hit "+tp+"!\n");
    this_player()->heal_self(500);
    call_other(this_player(),"add_money",-20000);
  return 1;}
  return 1;}
  else {
    if(this_player()->query_money() < 10000) {
      write("The Priest shakes his head....It seems you do not have enough money.\n");
    return 1; }
    else {
    write("The Priest nods and places a hand on your forehead.\n"+
      "He slowly incants and you begin to feel warm.....\n\n"+
      RED+"Suddenly, the hand at your forehead seems to grow extremely hot!\n"+
      "\n"+
      NORM+CYN+"It subsides and you feel lightheaded and refreshed.\n"+NORM+
      "\nThe Priest steps back and nods at you...the healing is over.\n");
    say("You see the Priest place a hand on "+tp+"'s forehead.\n"+
      "The Priest slowly incants .........\n\n"+
      "Suddenly.......\n\n"+
      tp+" cries out as if in pain........\n\n"+
      tp+" screams terribly.......\n\n");
   say(""+
      "Then suddenly it is over.......The Priest steps back and nods.\n\n"+
      tp+" seems shaken...sweat clings to the hair and the body shivers in the "+
      "warm air....\n"+
      tp+" seems fully healed though....\n");
    this_player()->heal_self(500);
    call_other(this_player(),"add_money",-10000);
  return 1; }
  return 1;}
return 1;}
return 1;}


ask(str) {
string who, what;
  if(!str) {write("What do you wish to ask?\n"); return 1;}
  if(sscanf(str,"%s about %s",who,what) == 2) {
  if(who != "priest" || what != "feather") 
  {write("Who and what do you wish to ask?\n"); return 1;}
  if(present("feather",this_player())) {
  say("The Priest leans over and whispers to "+capitalize(tp)+".\n");
  write("The Priest leans over and looks at you with a gaze of astonishment and awe.\n"+
       "He smiles and whispers to you:\n\n");
  write("\tThe feather from the head of the Firebird is a prize indeed!\n"+
       "\tIt is the symbol of healing and help- and within it is contained\n");
  write("\tthe powers of protection and healing.  For one to wear the feather,\n"+
       "\tmana is found to be easier to contain and control.  Its control over\n"+
       "\tlight can be called through the command <flame>.  The ability to drive\n"+
   "\toff spirits and to be protected from such can be done through <concentration>.\n"+
      "\tAnd <peace> may be called for the world.\n");
  write("\n\tThe wonderous abilities to help others- healing <dtouch>, resurrection\n"+
        "\t<prayer>, and protection <protect>- are perhaps the greatest measures \n"+
        "\tof sacrifice and Martyrdom.  Be careful should you use these abilites\n"+
        "\tfor power has a price.\n");
  write("The Priest adds as an afterthought:\n\n");
  write("\tThe feather has charges and <concentration> is very dangerous-\n"+
        "\tlevels may be lost...\n\n");
  return 1;}
  write("You do not have it!\n");
  return 1;}
  write("Ask who about what?\n");
  return 1;}

cure() {
if(present("priest")) {
  if(present("disease",this_player()) || present("infection",this_player())) {
  write("The Priest lays his hands upon your head....\n"+
       "His hands gradually feel warmer and warmer till\n"+
       "they seem to be burning up.\n\n");
  write("Then it is over...The Priest smiles...\n");
  destruct(present("disease",this_player()));
  destruct(present("infection",this_player()));
  return 1;}
  write("The Priest looks you over...\n"+
     "The Priest tells you: You are healthy!\n");
  return 1;}
  else {
  write("The priest is not here!\n"); return 1;}
  return 1;}

query_no_fight() { return 1; }
