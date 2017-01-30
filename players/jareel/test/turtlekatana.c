inherit "obj/weapon.c";

#include "/players/pestilence/ansi.h"
#define tp this_player()->query_name()
int w, i;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+HIB+"Leonardo"+NORM+"'"+HIB+"s"+NORM+" katana");
  set_alias("katana");
  set_short(""+HIB+"Leonardo"+NORM+"'"+HIB+"s"+NORM+" katana");
  set_long(
"This weapon is a curved, slender, single-edged blade with a squared guard\n"
  );
  set_type("katana");
  set_class(20);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
    call_out("forcec",random(2000));
  message_hit=({
    ""+HIR+"EvIcErAtEd"+NORM+""," with the might katana", 
    ""+RED+"iMpAlEd"+NORM+"","'s lung with a mighty thrust",
    ""+HIK+"SlIcEd"+NORM+"","with a heftly slash",
    ""+RED+"sTaBbEd"+NORM+""," in the chest",
    ""+RED+"hItS"+NORM+""," with a decent blow",
    ""+BLU+"grazed"+NORM+""," with a slight attack",
    ""+BLU+"nicks"+NORM+""," with a pathetic attack",
  });
}

query_save_flag()  { return 0; }

  init() {
    ::init();
      add_action("CHECK","moneymoney");
}

forcec() {
if(environment(this_object())) {
        if(living(environment(this_object()))) {
        if( environment(this_object())->is_player()) {
        command("moneymoney", environment(this_object()));
        return 1;} 
        call_out("forcec",random(1000));
    return 1;
        } }
        call_out("forcec",random(1000));
        return 1;}
        
CHECK() {
  int a;
  a=random(75);
  if(a>0 &&  a<11 ) {
    tell_object(this_player(),"Something checks your soul.....\n");
      call_other(this_player(),"add_alignment",random(1000));
      if(this_player()->query_alignment() > 2000) {
      call_other(this_player(),"add_alignment",2000-(this_player()->query_alignment()));}
      this_player()->clear_crime();
      call_out("forcec",random(100)+3);
    return 1;}
  if(a>10 && a<21) {
    tell_object(this_player(),"Something checks your soul.....\n");
    call_other(this_player(),"add_alignment",-random(1000));
      if(this_player()->query_alignment() < -2000) {
      call_other(this_player(),"add_alignment",-2000-(this_player()->query_alignment()));}
    this_player()->set_crime();
    call_out("forcec",random(100)+3);
    return 1;}
  if(a==69) {
    tell_object(this_player(),"You feel something has changed...\n You may wish to look at yourself\n");
    {this_player()->set_gender("female"); }
	return 1;}
  if(a==70) {
    tell_object(this_player(),"You feel something has changed...\n You may wish to look at yourself\n");
    {this_player()->set_gender("male"); } 
    call_out("forcec",random(100)+30);
    return 1;}
  if(a > 20 && a< 31) {
    tell_object(this_player(),"Something whispers softly in your ear.\n");
    this_player()->lower_attrib();
     call_out("forcec",random(100)+50);
    return 1;}
   if(a > 30  && a <41) {
     tell_object(this_player(),"Something touches you...\n");
     if(this_player()->query_level() > 10) { 
     if(0==random(2)) {
       this_player()->heal_self(random(90));
       if(this_player()->query_money() > 75000)
       this_player()->add_money(random(50));
       }
     else {
       this_player()->heal_self(random(10));
       this_player()->add_exp(-random(10));
       }}
     call_out("forcec",random(100)+10);
    return 1;}
  if(a>20) {
  say(
 HIB+"Leonardo"+NORM+"'"+HIB+"s"+NORM+" katana rips through flesh spewing "+HIR+"blood"+NORM+" everywhere.\n");

  write(
YEL+"\n              .-.\n"+
YEL+"              | |"+NORM+HIK+"____________________________________________________\n"+NORM+
YEL+" _ _ _ _ _ _ _| |"+NORM+"                                                  "+HIR+".'`.\n"+NORM+
YEL+"|_|_|_|_|_|_|_| |"+NORM+HIK+"-mbfh-------------------------------------------"+HIR+".'****"+HIK+">\n"+NORM+
YEL+"              | |"+NORM+HIK+"_______________________________________________"+HIR+".'***.'\n"+NORM+
YEL+"              | |                                              "+HIR+" `**'\n"+NORM+
YEL+"              `-'                                             "+HIR+" .'*`.\n"+NORM+
"                                                              "+HIR+" `._.' .\n"+NORM+
"                                                             "+HIR+"  .   .'*`.\n"+NORM+
"                                                            "+HIR+" .'*`. `._.'\n"+NORM+
   "\n");
  return (1+ random(3));
    call_out("forcec",random(100));
    return 1;}
  return 1;}
