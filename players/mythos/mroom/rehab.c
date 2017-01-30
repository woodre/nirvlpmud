#define tp this_player()
object patient;
int cost;
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Rehabilitation Center>> ";
    long_desc =
    "                Tokyo Rehabilitation Center\n"+
    "You enter a large white building. Here all ailments of the mind\n"+
    "and soul are 'cure'd- curses and drug related problem.  Curses are\n"+
    "70000 coins to cure, short term drug problems are 10000 coins, and \n"+
    "long term drug effects are 60000 coins.\n"+
    "All ailments of the body are refered to the medical center.  Also\n"+
    "if you wish to have a complete checkup you must go to the medical\n"+
    "center.\n";
  items = ({
    "out","You see the exit",
    "medical","You see the medical center",
  });

  dest_dir = ({
    "/players/mythos/mroom/med.c","medical",
    "/players/mythos/mroom/masakado.c", "out",
  });
} }

init() {
  ::init();
  add_action("ccure","cure");
}

ccure(str) {
patient = tp;
if(!str) { write("Cure what?\nTypes: curse, drugs\n"); return 1;}
if(str != "curse" && str != "drugs") return 0;
 if(str == "curse") {
  if(!present("curse",tp) && !present("cursed",tp)) { 
  write("There is no curse on you!\n"); return 1;}
  if(tp->query_money() < 70000) { write("You dont have enough money!\n"); return 1;}
    tp->add_money(-70000);
    destruct(present("curse",tp));
    destruct(present("cursed",tp));
    tp->save_me();
    tp->add_hit_point(-random(10));
    write("An old man looks you over and slaps you!\n");
    write("Suddenly, your vision wavers...\n");
    write("You feel better!\n");
 return 1;}
 if(str == "drugs") {
  if(!present("sterm",tp) && !present("lterm",tp)) {
    write("You have no drug related problems!\n"); return 1;}
    if(present("sterm",tp) && !present("lterm",tp)) {
      write("You have a short term drug problem.\n");
      cost = 10000;
      }
    if(present("lterm",tp) && !present("sterm",tp)) {
      write("You have a long term drug problem.\n"); 
      cost = 60000;
      }
    if(present("lterm",tp) && present("sterm",tp)) {
      write("You have both a short term and long term drug problem.\n"); 
      cost = 70000;
      }
     write("Do you wish to have the drug problem cured? <y/n> : ");
     input_to("dcure");
   return 1;}
return 1;}

dcure(str) {
  if(!str) { 
      tell_object(patient,"Do you wish to have the drug problem cured? <y/n> : ");
     input_to("dcure");
   return 1;}
  if(str != "y" && str != "Y" && str != "n" && str != "N") {
      tell_object(patient,"Do you wish to have the drug problem cured? <y/n> : ");
     input_to("dcure");
   return 1;}
  if(str == "n" || str == "N") { 
    tell_object(patient,"Ok. Thank you for coming.\n");
  return 1;}
  if(patient->query_money() < cost) {
    tell_object(patient,"You do not have enoguh money to pay for this cure.\n");
  return 1;}
  patient->add_money(-cost);
  destruct(present("sterm",patient));
  destruct(present("lterm",patient));
  patient->save_me();
  tell_object(patient,
    "A young woman comes up to you and tells you: This wont hurt.'\n"+
    "She holds up a LARGE needle and .....\n\n\n"+
    "                      IT HURTS!!!\n\n\n");
  patient->add_hit_point(-1-random(10));
  tell_object(patient,"After much pain, the young woman leaves.\n");
return 1;}
