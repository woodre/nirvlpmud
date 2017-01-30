inherit "room/room";
#define TP this_player()
#define TR tell_room
#define TE tell_object

init() {
 add_action("listen","listen");
 add_action("westfunc","west");
 add_action("restoration","restore");
 add_action("fix","fix");
 ::init();
}

reset(arg){

 if(!arg){
 set_light(1);
 short_desc="Entrance to Netropolis";
 long_desc=
"     The vast city of Netropolis lies westward.  Looking west,\n"+
"streams of lights and optical cables lace across the\n"+
"futuristic landscape.  A broad arch looms just over your\n"+
"head.  Upon the arch rests the huge figurine of a technological\n"+
"nightmare.  Red eyes glare through the ninja-like figure.\n"+
"This statue seems to have something important to say.\n"+
"Perhaps if you 'listen' you might learn more about what lies ahead.\n"+
"A moniter rests embedded in the metallic arch.\n"+
"A warning sign reads: Unlawful Entry Prohibited.  Trespassers will\n"+
"be instantly killed! ~~This a promise, not a threat.~~\n";

items=({
 "lights", "The lights shine brightly in the otherwise dark city",
 "cables","Thick colorful cables run along the Netropolis streets",
 "landscape","The electronic landscape is dark and alive with energy",
 "arch","The broad red arch towers above you",
 "figure","The menacing figure of a ninja warrior stands before you",
 "statue","The statue is black, with red glowing eyes",
 "monitor","The monitor reads:\n"+
"If your implants have broken or disappeared, \n"+
"type 'restore' and then 'fix' to solve the problem",
 "moniter","The moniter reads:\n"+
"If your implants have broken or disappeared, \n"+
"type 'restore' and then 'fix' to solve the problem",
 "netropolis","Netropolis, city of the CyberNinja",
 "Netropolis","Netropolis, city of the CyberNinja",
 "city","Netropolis, city of the CyberNinja",
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/guildhall.c","west",
 "/players/snow/gate","vortex",
      });
  }   }

westfunc() {
 if( (!present("implants",TP)) ||
     (!present("temporary implants",TP)) ) {
     TE(TP, "You cannot proceed west without proper access.\n");
     TE(TP, "Only guild members or recruits may enter Netropolis.\n");
     TE(TP, "However, the CyberNinja guild is always looking\n"+
            "for new members.\n");
     return 1; }
 else {
     call_other(TP,"move_player",
           "west#players/snow/closed/cyber/rooms/guildhall.c");
     return 1;}
}

listen() {
   TR(environment(TP),
"A deep voice emanates from the dark warrior statue.....\n"+
"To be a CyberNinja, you first seek out a CyberNinja who can\n"+
"show you the Way.  You must learn this Way, and only then may\n"+
"you become one of us!\n"+
"...The voice dies into silence.\n");
  return 1;
}

restoration() {
  string file, name;
  object imp;
  int lev, xp;
  name = this_player()->query_real_name();
  name = lower_case(name);
  file = "/players/snow/closed/cyber/ninjas/"+name+".o";
  if(file_size(file) <= 0) {               
    write("You are not a CyberNinja!\n");
    return 1; }
  if(present("implants", this_player()))
    destruct(present("implants", this_player()));
  move_object(clone_object("/players/snow/closed/cyber/implants.c"),
             this_player());
  write("Your implants have been restored.\n");
  return 1;
}

fix() {
  object imp;
  int xp, lev;
  if(!present("implants", TP)) {
    write("You have no implants. Type 'restore' first.\n");
    return 1; }
  imp = present("implants", TP);
  xp = ((int)imp->guild_exp());
  lev = ((int)imp->guild_lev());
  TP->set_guild_name("cyberninja");
  TP->add_guild_rank(-TP->query_guild_rank());
  TP->add_guild_rank(lev);
  TP->add_guild_exp(-TP->query_guild_exp());
  TP->add_guild_exp(xp);
  if(!TP->query_guild_exp()) TP->add_guild_exp(1);
  TP->set_guild_file("/players/snow/closed/cyber/implants.c");
  TP->save_me();
  write("Guild status fixed.\n");
  return 1;
}
