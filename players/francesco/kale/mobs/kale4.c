#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

int a;

reset(arg){
  object kale;
  ::reset();
  if(arg) return;
   set_name(""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
   set_race("kaleidoscope");
   set_alias("kale");
   set_gender("neuter");
     set_short(HIB+"BLUE "+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
     set_long(""+HIB+"Th"+NORM+YEL+"e "+HIY+"ka"+HIG+"le"+HIR+"id"+HIM+"os    "+NORM+""+HIR+"co"+NORM+YEL+"pe"+HIY+" i"+HIW+"s "+HIB+"an"+HIM+" o    "+NORM+""+HIR+"pt"+NORM+YEL+"ic"+HIY+"al"+HIG+" t"+HIW+"oy"+HIM+" w    "+NORM+""+HIR+"hi"+NORM+YEL+"ch"+HIY+" s"+HIG+"ho"+HIB+"ws"+HIW+"  "+NORM+"\n"+
              ""+HIB+"co"+NORM+YEL+"nt"+HIY+"in"+HIG+"uo"+HIR+"us"+HIM+"ly    "+NORM+""+HIR+" c"+NORM+YEL+"ha"+HIY+"ng"+HIW+"in"+HIB+"g "+HIM+"sh    "+NORM+""+HIR+"ap"+NORM+YEL+"e "+HIY+"an"+HIG+"d "+HIW+"co"+HIM+"lo    "+NORM+""+HIR+"r."+NORM+YEL+" I"+HIY+"t "+HIG+"is"+HIB+"  "+HIW+"  "+NORM+"\n"+
              ""+HIB+"ma"+NORM+YEL+"de"+HIY+" b"+HIG+"y "+HIR+"a "+HIM+"tu    "+NORM+""+HIR+"be"+NORM+YEL+" w"+HIY+"it"+HIW+"h "+HIB+"tw"+HIM+"o     "+NORM+""+HIR+"mi"+NORM+YEL+"rr"+HIY+"or"+HIG+"s "+HIW+"at"+HIM+" t    "+NORM+""+HIR+"he"+NORM+YEL+" e"+HIY+"nd"+HIG+"s."+HIB+" T"+HIW+"he"+NORM+"\n"+
              ""+HIB+"ro"+NORM+YEL+"ta"+HIY+"ti"+HIG+"on"+HIR+" a"+HIM+"nd    "+NORM+""+HIR+" t"+NORM+YEL+"he"+HIY+" s"+HIW+"hi"+HIB+"ft"+HIM+" o    "+NORM+""+HIR+"f "+NORM+YEL+"th"+HIY+"e "+HIG+"tw"+HIW+"o "+HIM+"mi    "+NORM+""+HIR+"rr"+NORM+YEL+"or"+HIY+"s "+HIG+"on"+HIB+"e "+HIW+"  "+NORM+"\n"+
              ""+HIB+"ag"+NORM+YEL+"ai"+HIY+"ns"+HIG+"t "+HIR+"th"+HIM+"e     "+NORM+""+HIR+"ot"+NORM+YEL+"he"+HIY+"r "+HIW+"pr"+HIB+"od"+HIM+"uc    "+NORM+""+HIR+"e "+NORM+YEL+"an"+HIY+" a"+HIG+"lm"+HIW+"os"+HIM+"t     "+NORM+""+HIR+"en"+NORM+YEL+"dl"+HIY+"es"+HIG+"s "+HIB+"  "+HIW+"  "+NORM+"\n"+
              ""+HIB+"co"+NORM+YEL+"mb"+HIY+"in"+HIG+"at"+HIR+"ti"+HIM+"on    "+NORM+""+HIR+" o"+NORM+YEL+"f "+HIY+"sh"+HIW+"ap"+HIB+"es"+HIM+" a    "+NORM+""+HIR+"nd"+NORM+YEL+" c"+HIY+"ol"+HIG+"or"+HIW+"s."+HIM+"      "+NORM+""+HIR+"  "+NORM+YEL+"  "+HIY+"  "+HIG+"  "+HIB+"  "+HIW+"  "+NORM+"\n");
   set_level(18);
   set_hp(430);
   set_wc(27);
   set_ac(17);
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(20);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(20);
   kale = clone_object("/players/francesco/kale/items/kale2.c");
   move_object(kale,this_object());
}

id(str) {return str=="kaleidoscope" || str=="kale" || str=="kaleido" || str == "blue kale"  ;}

heart_beat() {
   ::heart_beat();
   if(attacker_ob){  
    a = random(9) ;
   if(a == 1) {
     say(""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@               @@@"+NORM+"\n"+
         ""+HIR+"  @@@               @@@"+NORM+"\n");
     say(""+HIR+"  @@@               @@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 2) {
     say(""+HIB+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIB+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIB+"  @@@               @@@"+NORM+"\n"+
         ""+HIB+"  @@@               @@@"+NORM+"\n");
     say(""+HIB+"  @@@               @@@"+NORM+"\n"+
         ""+HIB+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIB+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 3) {
     say(""+HIM+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIM+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIM+"  @@@               @@@"+NORM+"\n"+
         ""+HIM+"  @@@               @@@"+NORM+"\n");
     say(""+HIM+"  @@@               @@@"+NORM+"\n"+
         ""+HIM+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIM+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 4) {
     say(""+HIC+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIC+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIC+"  @@@               @@@"+NORM+"\n"+
         ""+HIC+"  @@@               @@@"+NORM+"\n");
     say(""+HIC+"  @@@               @@@"+NORM+"\n"+
         ""+HIC+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIC+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 0) {
     say(""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@               @@@"+NORM+"\n"+
         ""+HIY+"  @@@               @@@"+NORM+"\n");
     say(""+HIY+"  @@@               @@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 5) {
     say(""+HIG+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIG+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIG+"  @@@               @@@"+NORM+"\n"+
         ""+HIG+"  @@@               @@@"+NORM+"\n");
     say(""+HIG+"  @@@               @@@"+NORM+"\n"+
         ""+HIG+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIG+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 6) {
     say(""+HIW+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIW+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIW+"  @@@               @@@"+NORM+"\n"+
         ""+HIW+"  @@@               @@@"+NORM+"\n");
     say(""+HIW+"  @@@               @@@"+NORM+"\n"+
         ""+HIW+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIW+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 7) {
     say(""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@               @@@"+NORM+"\n"+
         ""+HIR+"  @@@               @@@"+NORM+"\n");
     say(""+HIR+"  @@@               @@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 8) {
     say(""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@               @@@"+NORM+"\n"+
         ""+HIR+"  @@@               @@@"+NORM+"\n");
     say(""+HIR+"  @@@               @@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
}
}


