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
     set_short(HIY+"YELLOW "+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
     set_long(""+HIR+"       Th"+NORM+YEL+"e "+HIY+"ka"+HIG+"le"+HIB+"id"+HIM+"os"+NORM+""+HIR+"co"+NORM+YEL+"pe"+HIY+" i"+HIG+"s "+HIB+"an"+HIM+" o"+NORM+""+HIR+"pt"+NORM+YEL+"ic"+HIY+"al"+HIG+" t"+HIB+"oy"+HIM+" w"+NORM+""+HIR+"hi"+NORM+YEL+"ch"+HIY+" s"+HIG+"ho"+HIB+"ws"+HIM+"  "+NORM+"\n"+
              ""+HIR+"    co"+NORM+YEL+"nt"+HIY+"in"+HIG+"uo"+HIB+"us"+HIM+"ly"+NORM+""+HIR+" c"+NORM+YEL+"ha"+HIY+"ng"+HIG+"in"+HIB+"g "+HIM+"sh"+NORM+""+HIR+"ap"+NORM+YEL+"e "+HIY+"an"+HIG+"d "+HIB+"co"+HIM+"lo"+NORM+""+HIR+"r."+NORM+YEL+" I"+HIY+"t "+HIG+"is"+HIB+"  "+HIM+"  "+NORM+"\n"+
              ""+HIR+" ma"+NORM+YEL+"de"+HIY+" b"+HIG+"y "+HIB+"a "+HIM+"tu"+NORM+""+HIR+"be"+NORM+YEL+" w"+HIY+"it"+HIG+"h "+HIB+"tw"+HIM+"o "+NORM+""+HIR+"mi"+NORM+YEL+"rr"+HIY+"or"+HIG+"s "+HIB+"at"+HIM+" t"+NORM+""+HIR+"he"+NORM+YEL+" e"+HIY+"nd"+HIG+"s."+HIB+" T"+HIM+"he"+NORM+"\n"+
              ""+HIR+" ro"+NORM+YEL+"ta"+HIY+"ti"+HIG+"on"+HIB+" a"+HIM+"nd"+NORM+""+HIR+" t"+NORM+YEL+"he"+HIY+" s"+HIG+"hi"+HIB+"ft"+HIM+" o"+NORM+""+HIR+"f "+NORM+YEL+"th"+HIY+"e "+HIG+"tw"+HIB+"o "+HIM+"mi"+NORM+""+HIR+"rr"+NORM+YEL+"or"+HIY+"s "+HIG+"on"+HIB+"e "+HIM+"  "+NORM+"\n"+
              ""+HIR+"    ag"+NORM+YEL+"ai"+HIY+"ns"+HIG+"t "+HIB+"th"+HIM+"e "+NORM+""+HIR+"ot"+NORM+YEL+"he"+HIY+"r "+HIG+"pr"+HIB+"od"+HIM+"uc"+NORM+""+HIR+"e "+NORM+YEL+"an"+HIY+" a"+HIG+"lm"+HIB+"os"+HIM+"t "+NORM+""+HIR+"en"+NORM+YEL+"dl"+HIY+"es"+HIG+"s "+HIB+"  "+HIM+"  "+NORM+"\n"+
              ""+HIR+"       co"+NORM+YEL+"mb"+HIY+"in"+HIG+"at"+HIB+"ti"+HIM+"on"+NORM+""+HIR+" o"+NORM+YEL+"f "+HIY+"sh"+HIG+"ap"+HIB+"es"+HIM+" a"+NORM+""+HIR+"nd"+NORM+YEL+" c"+HIY+"ol"+HIG+"or"+HIB+"s."+HIM+"  "+NORM+""+HIR+"  "+NORM+YEL+"  "+HIY+"  "+HIG+"  "+HIB+"  "+HIM+"  "+NORM+"\n");
   set_level(15);
   set_hp(260);
   set_wc(20);
   set_ac(12);
   set_chat_chance(10);
   set_heal(1,1);
   set_chance(15);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(10);
   kale = clone_object("/players/francesco/kale/items/kale3.c");
   move_object(kale,this_object());
}

id(str) {return str=="kaleidoscope" || str=="kale" || str=="kaleido" || str == "yellow kale" ;}

heart_beat() {
   ::heart_beat();
   if(attacker_ob){  
    a = random(5) ;
   if(a == 1) {
     say(""+HIR+"        @"+HIR+"@@"+HIR+"@        "+NORM+"\n"+
         ""+HIR+"      @@@"+HIB+"@@"+HIR+"@@@      "+NORM+"\n"+
         ""+HIR+"    @@@"+HIB+"@@"+HIR+"@@"+HIB+"@@"+HIR+"@@@ "+NORM+"\n"+
         ""+HIR+"  @@@"+HIB+"@@"+HIR+"@@@@@@"+HIB+"@@"+HIR+"@@@  "+NORM+"\n");
     say(""+HIR+"    @@@"+HIB+"@@"+HIR+"@@"+HIB+"@@"+HIR+"@@@    "+NORM+"\n"+
         ""+HIR+"      @@@"+HIB+"@@"+HIR+"@@@      "+NORM+"\n"+
         ""+HIR+"        @"+HIR+"@@"+HIR+"@        "+NORM+"\n");
   return 1;}
   if(a == 2) {
     say(""+HIB+"        @"+HIB+"@@"+HIB+"@        "+NORM+"\n"+
         ""+HIB+"      @@@"+HIR+"@@"+HIB+"@@@      "+NORM+"\n"+
         ""+HIB+"    @@@"+HIR+"@@"+HIB+"@@"+HIR+"@@"+HIB+"@@@    "+NORM+"\n"+
         ""+HIB+"  @@@"+HIR+"@@"+HIB+"@@@@@@"+HIR+"@@"+HIB+"@@@  "+NORM+"\n");
     say(""+HIB+"    @@@"+HIR+"@@"+HIB+"@@"+HIR+"@@"+HIB+"@@@    "+NORM+"\n"+
         ""+HIB+"      @@@"+HIR+"@@"+HIB+"@@@      "+NORM+"\n"+
         ""+HIB+"        @"+HIB+"@@"+HIB+"@        "+NORM+"\n");
   return 1;}
   if(a == 3) {
     say(""+HIY+"        @"+HIY+"@@"+HIY+"@        "+NORM+"\n"+
         ""+HIY+"      @@@"+HIM+"@@"+HIY+"@@@      "+NORM+"\n"+
         ""+HIY+"    @@@"+HIM+"@@"+HIY+"@@"+HIM+"@@"+HIY+"@@@    "+NORM+"\n"+
         ""+HIY+"  @@@"+HIM+"@@"+HIY+"@@@@@@"+HIM+"@@"+HIY+"@@@  "+NORM+"\n");
     say(""+HIY+"    @@@"+HIM+"@@"+HIY+"@@"+HIM+"@@"+HIY+"@@@    "+NORM+"\n"+
         ""+HIY+"      @@@"+HIM+"@@"+HIY+"@@@      "+NORM+"\n"+
         ""+HIY+"        @"+HIY+"@@"+HIY+"@        "+NORM+"\n");
   return 1;}
   if(a == 4) {
     say(""+HIC+"        @"+HIC+"@@"+HIC+"@        "+NORM+"\n"+
         ""+HIC+"      @@@"+HIR+"@@"+HIC+"@@@      "+NORM+"\n"+
         ""+HIC+"    @@@"+HIR+"@@"+HIC+"@@"+HIR+"@@"+HIC+"@@@    "+NORM+"\n"+
         ""+HIC+"  @@@"+HIR+"@@"+HIC+"@@@@@@"+HIR+"@@"+HIC+"@@@  "+NORM+"\n");
     say(""+HIC+"    @@@"+HIR+"@@"+HIC+"@@"+HIR+"@@"+HIC+"@@@    "+NORM+"\n"+
         ""+HIC+"      @@@"+HIR+"@@"+HIC+"@@@      "+NORM+"\n"+
         ""+HIC+"        @"+HIC+"@@"+HIC+"@        "+NORM+"\n");
   return 1;}
   if(a == 0) {
     say(""+HIM+"        @"+HIM+"@@"+HIM+"@        "+NORM+"\n"+
         ""+HIM+"      @@@"+HIC+"@@"+HIM+"@@@      "+NORM+"\n"+
         ""+HIM+"    @@@"+HIC+"@@"+HIM+"@@"+HIC+"@@"+HIM+"@@@    "+NORM+"\n"+
         ""+HIM+"  @@@"+HIC+"@@"+HIM+"@@@@@@"+HIC+"@@"+HIM+"@@@  "+NORM+"\n");
     say(""+HIM+"    @@@"+HIC+"@@"+HIM+"@@"+HIC+"@@"+HIM+"@@@    "+NORM+"\n"+
         ""+HIM+"      @@@"+HIC+"@@"+HIM+"@@@      "+NORM+"\n"+
         ""+HIM+"        @"+HIM+"@@"+HIM+"@        "+NORM+"\n");
   return 1;}
}
}



