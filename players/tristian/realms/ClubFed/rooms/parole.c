/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison Mid-Level Area
//  Create Date:  2005.06.03
//	Thanks to everyone who helped me...
//  especially Illarion & Vertebraker
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/room.c";
int timeserved;

reset(arg) {
 ::reset(arg);
 if(arg) return;

set_light(1);

short_desc = "The Parole Board";
long_desc =
  " This is where a convict ends up on his way out of prison, the dreaded\n"+
  "parole board inquiry.  A panel of three people sits behind a table\n"+
  "ready to to pass judgement on whether you are reformed or not. If you\n"+
  "feel you have served your time here, you can 'apply' for 'parole'.\n";
add_property("NT");

items = ({
"people",
"The three people on the parole board who decide your fate",
"board",
"The three people on the parole board who decide your fate",
"panel",
"The three people on the parole board who decide your fate",
"table",
"A solid wood table for the convict to sit at while awaiting his or her fate",
});

dest_dir = ({
RMS+"hall_com_01", "east",
RMS+"office", "south",
});
}

init(){
::init();
  AA("apply","apply");
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
}

apply(str)
{
  tell_room(this_object(), 
    "The parole board reviews the case and goes into the next office to discuss the outcome.\n\n");
  call_out("parole_1", 5, this_player());
  return 1;
}

parole_1(object ob)
{
 tell_room(this_object(),
  "Ten minutes later the parole board files back in.\n\n");
 call_out("parole_2", 2, ob);
}

parole_2(object ob)
{
 tell_room(this_object(),
  "The chairman gives you the news concerning your release.\n\n");
 call_out("parole_3", 2, ob);
}

parole_3(object ob)
{
 tell_room(this_object(),
  "'You seem to honestly repent your crime and you have made tremendous\n"+
  "strides towards being a better individual.'\n\n");
 call_out("parole_4", 3, ob);
}

parole_4(object ob)
{
 tell_room(this_object(),
  "'We shall allow "+ob->query_name()+"'s release, but "+ subjective(ob) +" has to report to "+possessive(ob)+"\n"+
  "parole officer and shall not leave the realm of Nirvana.'\n\n",
  ({ ob }));
 tell_object(ob,
  "'We shall allow your release, but you are to report to your\n"+
  "parole officer and shall not leave the realm of Nirvana.'\n\n"); 
 tell_object(ob,
  "The guard walks you out the front door of the prison.\n\n");
 move_object(ob,"room/forest9");
 command("look",ob); 
 return 1;
}
    
Smell(str) {
  if(!str || str == "air") {
  write("There are no smells present in the air.\n");
  return 1;
}
  return 1;
}

Search() {
  write("You find nothing special.\n");
  return 1;
}

Listen() {
  write("Strangely enough there is no sound in this room, except\n"+
  "the sound of your heart beating.\n");
  return 1;
}