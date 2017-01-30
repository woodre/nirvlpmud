/*******************************************
*      ok this is a wc 19 savable but its 
*      its curse isnt that fun....  player
*      on a random basis can lose or gain or
*      have changed, alignment, money, gender,
*      xp, hp/sp....  also special attack
*      querie vs hp...(above random 700)
*      so as battle wears on... random occurs
*      less and less  (a small heal_self is
*      included but not enough to help)
*      also this is found after killing orochi.c
*
*       approved by saber
********************************************/
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("tsurugi");
    set_alt_name("blade");
    set_alias("katana");
    set_short("Tsurugi");
    set_long("This is the fabled blade which Susano-wo\n"+
             "pulled out of the Yamato-no-Oorochi.  It is\n"+
             "weapon of great power.  It is made of a red \n"+
             "substance, not metal, but something altogether\n"+
             "different.  As soon as you touch it, you feel the\n"+
             "healing powers within the sword and you understand\n"+
             "that all gifts have prices.....\n");
    set_read(RED+"There is always a price.....\n"+
    "\t\t\t\-Hunter\n"+NORM);
    set_class(19);
    set_weight(3);
    set_type("sword");
    set_value(8000);
    set_hit_func(this_object());
    call_out("forcec",random(150));
}
weapon_hit(attacker){
int trade, trader;
if(this_player())
if(this_player()->query_hp() > random(700))
 {
 trade=random(8);
 write("The Blade brightens and something shoots out and hits your foe!\n");
 write(CYN+"\n\tzzzzzzzz   ZAP  zzzzzzzz\n\n"+NORM+
     "Your enemy falls back in pain!\n"+BLU+"You feel healed!\n"+NORM);
 say("The Blade brightens and something shoots out and hits "+
  capitalize(tp)+"'s foe!\n");
 say(CYN+"\n\tzzzzzzzz   ZAP  zzzzzzzz\n\n"+NORM+
     "The enemy falls back in pain!\n"+BLU+capitalize(tp)+
     " looks healed!\n"+NORM);  
  attacker->heal_self(-trade);
  trader= trade-random(4);
  if(trader>0 ||trader==0) {
 this_player()->heal_self(trader);}
 if(trader<0) {
 this_player()->heal_self(-trader);}
  return 2;}
}

query_save_flag()  { return 0; }


init() {
  ::init();
  add_action("check","pricey");
}

forcec() {
if(environment(this_object())) {
	if(living(environment(this_object()))) {
	if( environment(this_object())->is_player()) {
	command("pricey", environment(this_object()));
	return 1;} 
	call_out("forcec",random(2000));
    return 1;
	} }
	call_out("forcec",random(2000));
	return 1;}
	
check() {
  int a,b;
  a=random(120);
  if(a>0 &&  a<11 ) {
    tell_object(this_player(),"Something checks your soul.....\n");
      call_other(this_player(),"add_alignment",random(700));
      if(this_player()->query_alignment() > 2000) {
      call_other(this_player(),"add_alignment",2000-(this_player()->query_alignment()));}
      this_player()->clear_crime();
      call_out("forcec",random(1000)+300);
    return 1;}
  if(a>10 && a<21) {
    tell_object(this_player(),"Something checks your soul.....\n");
    call_other(this_player(),"add_alignment",-random(700));
      if(this_player()->query_alignment() < -2000) {
      call_other(this_player(),"add_alignment",-2000-(this_player()->query_alignment()));}
    this_player()->set_crime();
    call_out("forcec",random(1000)+300);
    return 1;}
  if(a==0) {
    b=random(2);
    tell_object(this_player(),"You feel something has changed...\n You may wish to look at yourself\n");
    if(b==0) {this_player()->set_gender("female"); }
    if(b==1) {this_player()->set_gender("male"); } 
    call_out("forcec",random(1300)+600);
    return 1;}
  if(a > 20 && a< 31) {
    tell_object(this_player(),"Something whispers softly in your ear.\n");
    this_player()->lower_attrib();
     call_out("forcec",random(2000)+500);
    return 1;}
   if(a > 30  && a <41) {
     tell_object(this_player(),"Something touches you...\n");
     if(this_player()->query_level() > 10) { 
     if(0==random(2)) {
       this_player()->heal_self(-random(10));
       if(this_player()->query_money() > 500)
       this_player()->add_money(-random(500));
       }
     else {
       this_player()->heal_self(random(10));
       this_player()->add_exp(-random(1000));
       }}
     call_out("forcec",random(2000)+600);
    return 1;}
  if(a>40) {
  tell_object(this_player(),"You get the feeling something is watching you.\n");
    call_out("forcec",random(1000));
    return 1;}
  return 1;}
