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
int crime;

reset(arg) {
 ::reset(arg);
 if(arg) return;

MOB_DAEMON->set_npc();
set_light(1);

short_desc = "The Federal Courthouse";
long_desc =
  " A federal court room, quiet and dignified. There is the judges bench,\n"+
  "the jury box, and two tables, one for you, the defendant, and a second for\n"+
  "the prosecutor in this room.\n"+
  "Please say your plea to the court or read the sign to find out your rights.\n";
add_property("NT");

items = ({
"bench",
"A piece of woodworking art, solid oak and impressive, it exudes a sense of power",
"jury box",
"A two tiered platform with twelve chairs on it, where the people who decide your fate will sit",
"table",
"A solid wood table for the defendant to sit at while awaiting his or her fate",
"floor",
"A drab, uneventful looking floor",
});
}

init(){
::init();
  AA("fun_tocall", "say");
#ifndef __LDMUD__
  AA("fun_tocall");add_xverb("'");
#else
  AA("fun_tocall","'", 3);
#endif
  AA("Read","read");
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
}

fun_tocall(string arg)
{ 
  arg=lower_case(arg);
  if (arg == "guilty") return guilty();
  if (arg == "not guilty") return not_guilty();
  if (arg == "no contest") return no_contest();
  return 0;
}
  
guilty()
{
 tell_room(this_object(), 
  "The judge bangs down his gavel and says, 'So entered the plea of "+HIG+"Guilty"+NORM+"'\n\n");
 call_out("guilty_2", 3, this_player());
 return 1;
}
guilty_2(object ob)
{
 tell_room(this_object(),
  "The judge declares, 'I will now pass sentence on "+ob->query_name()+".'\n\n");
 call_out("guilty_3", 2, ob);
}
guilty_3(object ob)
{
 tell_room(this_object(),
  "The plaintiff shall serve five years in the Minimum Security Prison known\n"+
  "as '"+HIY+"Club Fed"+NORM+"'.\n\n");
 call_out("guilty_4", 2, ob);
}
guilty_4(object ob)
{
 tell_room(this_object(),
  "The bailiff comes over to "+ob->query_name()+" and hauls \n"+
  objective(ob)+" off to serve "+possessive(ob)+" sentence.\n\n",
  ({ ob }));
 tell_object(ob,
  "The bailiff comes over to you and hauls you off to serve your sentence.\n\n");
 move_object(ob,RMS+"cb10.c");
 command("look",ob); 
 return 1;
}

not_guilty()
{
 crime = (random(5));
  if (crime <= 3) 
  {
  tell_room(this_object(), 
   "The judge bangs down his gavel and says, 'So entered the plea of "+HIM+"Not Guilty"+NORM+"'\n\n");
  call_out("not_guilty_2_1", 3, this_player());
  return 1;
  }
  if (crime == 4)
  {
  tell_room(this_object(),
   "The judge bangs down his gavel and says, 'So entered the plea of "+HIM+"Not Guilty"+NORM+"'\n\n");
  call_out("not_guilty_3_1", 3, this_player());
  return 1;
  }
}

not_guilty_2_1(object ob)
{
 tell_room(this_object(),
  "Months pass as the trial lingers on, finally the day comes when the\n"+
  "jury comes back from its deliberation.\n\n");
 call_out("not_guilty_2_2", 2, ob);
}
not_guilty_2_2(object ob)
{
 tell_room(this_object(),
  "The judge bangs his gavel and calls the court to order.\n\n");
 call_out("not_guilty_2_3", 2, ob);
}

not_guilty_2_3(object ob)
{
 tell_room(this_object(),
  "The jury foreperson reads the verdict.\n\n");
 tell_room(this_object(),
  "'We the jury in the above titled action find the\n"+
  "plaintiff "+ob->query_name()+""+HIG+BLINK+" guilty"+NORM+".'\n\n");
 call_out("not_guilty_2_4", 2, ob);
}

not_guilty_2_4(object ob)
{
 tell_room(this_object(),
  "The judge says, 'I will now pass sentence on "+ob->query_name()+".'\n\n"+
  ob->query_name()+" shall serve 5 years in the Minimum Security Prison known\n"+
  "as 'Club Fed'\n\n");
 call_out("not_guilty_2_5", 2, ob);
}

not_guilty_2_5(object ob)
{
 tell_room(this_object(),
  "The bailiff comes over to "+ob->query_name()+" and hauls "+
  objective(ob)+" off to serve "+possessive(ob)+" sentence.\n\n",
  ({ ob }));
 tell_object(ob,
  "The bailiff comes over to you and hauls you off to serve your sentence.\n\n");
 move_object(ob,RMS+"cb10.c");
 command("look",ob); 
 return 1;
}

not_guilty_3_1(object ob)
{
 tell_room(this_object(),
  "Months pass as the trial lingers on, final the day comes when the\n"+
  "jury comes back from its deliberation.\n\n");
 call_out("not_guilty_3_2", 2, ob);
}

not_guilty_3_2(object ob)
{
 tell_room(this_object(),
  "The judge bangs his gavel and calls the court to order.\n\n");
 call_out("not_guilty_3_3", 2, ob);
}

not_guilty_3_3(object ob)
{
 tell_room(this_object(),
  "The jury foreperson reads the verdict.\n");
 tell_room(this_object(),
  "'We the jury in the above titled action find the\n"+
  "plaintiff "+ob->query_name()+""+HIR+BLINK+" Not Guilty"+NORM+".'\n\n");
 call_out("not_guilty_3_4", 2, ob);
}

not_guilty_3_4(object ob)
{
 tell_room(this_object(),
  "The judge says, ' "+ob->query_name()+" is free to go.\n\n",
  ({ ob }));
 tell_object(ob,
  "The bailiff comes over to you and sets you free.\n\n");
 move_object(ob,"/room/forest9");
 command("look",ob); 
 return 1;
}

no_contest()
{
 tell_room(this_object(), 
  "The judge bangs down his gavel and says, 'So entered the plea of "+HIR+"No Contest"+NORM+".'\n\n");
 call_out("no_contest_2", 3, this_player());
 return 1;
  }

no_contest_2(object ob)
{
 tell_room(this_object(),
  "The judge accepts your plea of '"+HIR+"No Contest"+NORM+"' and prepares\n"+
  "to pass sentence.\n\n");
 call_out("no_contest_3", 2, ob);
}

no_contest_3(object ob)
{
 tell_room(this_object(),
  "The judge orders you to serve five years probation and releases you.\n\n");
 call_out("no_contest_4", 2, ob);
}

no_contest_4(object ob)
{
 tell_room(this_object(),
  "The judge says, ' "+ob->query_name()+" is free to go.\n\n",
  ({ ob }));
 tell_object(ob,
  "The bailiff comes over to you and sets you free.\n\n");
 move_object(ob,"/room/forest9");
 command("look",ob); 
 return 1;
}

Read(str) {
 if(str != "sign")
 {
   return 0;
 }
 if(str == "sign")
 {
  write("You can plead "+HIR+"'Guilty' "+NORM+" to the crime and go directly to jail.\n"+
  "You can plead "+HIG+"'Not Guilty' "+NORM+"in which case a trial will be held and\n"+
  "you leave yourself up to the decision of the jury or you can plead\n"+
  HIM+"'No Contest' "+NORM+"and take your sentence and go on your way.\n");
 return 1;
 }
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
  write("Strangely enough there is no sound in this room.\n");
  return 1;
}
