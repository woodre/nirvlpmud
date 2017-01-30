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
   set_name(""+BLINK+HIR+"Ka"+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
   set_race("kaleidoscope");
   set_name("kaleidoscope");
   set_alias("kale");
   set_gender("neuter");
     set_short(HIW+BLINK+HIR+"Ka"+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pic  "+NORM+""+HIR+"Ka"+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
     set_long(""+HIR+"      Th"+NORM+YEL+"e "+HIY+"ka"+HIG+"le"+HIB+"id"+HIM+"os"+NORM+""+HIR+"co"+NORM+YEL+"pe"+HIY+" i"+HIG+"s "+HIB+"an"+HIM+" o"+NORM+""+HIR+"pt"+NORM+YEL+"ic"+HIY+"al"+HIG+" t"+HIB+"oy"+HIM+" w"+NORM+""+HIR+"hi"+NORM+YEL+"ch"+HIY+" s"+HIG+"ho"+HIB+"ws"+HIM+"  "+NORM+"\n"+
              ""+HIR+"    co"+NORM+YEL+"nt"+HIY+"in"+HIG+"uo"+HIB+"us"+HIM+"ly"+NORM+""+HIR+" c"+NORM+YEL+"ha"+HIY+"ng"+HIG+"in"+HIB+"g "+HIM+"sh"+NORM+""+HIR+"ap"+NORM+YEL+"e "+HIY+"an"+HIG+"d "+HIB+"co"+HIM+"lo"+NORM+""+HIR+"r."+NORM+YEL+" I"+HIY+"t "+HIG+"is"+HIB+"  "+HIM+"  "+NORM+"\n"+
              ""+HIR+"  ma"+NORM+YEL+"de"+HIY+" b"+HIG+"y "+HIB+"a "+HIM+"tu"+NORM+""+HIR+"be"+NORM+YEL+" w"+HIY+"it"+HIG+"h "+HIB+"tw"+HIM+"o "+NORM+""+HIR+"mi"+NORM+YEL+"rr"+HIY+"or"+HIG+"s "+HIB+"at"+HIM+" t"+NORM+""+HIR+"he"+NORM+YEL+" e"+HIY+"nd"+HIG+"s."+HIB+" T"+HIM+"he"+NORM+"\n"+
              ""+HIR+"  ro"+NORM+YEL+"ta"+HIY+"ti"+HIG+"on"+HIB+" a"+HIM+"nd"+NORM+""+HIR+" t"+NORM+YEL+"he"+HIY+" s"+HIG+"hi"+HIB+"ft"+HIM+" o"+NORM+""+HIR+"f "+NORM+YEL+"th"+HIY+"e "+HIG+"tw"+HIB+"o "+HIM+"mi"+NORM+""+HIR+"rr"+NORM+YEL+"or"+HIY+"s "+HIG+"on"+HIB+"e "+HIM+"  "+NORM+"\n"+
              ""+HIR+"    ag"+NORM+YEL+"ai"+HIY+"ns"+HIG+"t "+HIB+"th"+HIM+"e "+NORM+""+HIR+"ot"+NORM+YEL+"he"+HIY+"r "+HIG+"pr"+HIB+"od"+HIM+"uc"+NORM+""+HIR+"e "+NORM+YEL+"an"+HIY+" a"+HIG+"lm"+HIB+"os"+HIM+"t "+NORM+""+HIR+"en"+NORM+YEL+"dl"+HIY+"es"+HIG+"s "+HIB+"  "+HIM+"  "+NORM+"\n"+
              ""+HIR+"      co"+NORM+YEL+"mb"+HIY+"in"+HIG+"at"+HIB+"ti"+HIM+"on"+NORM+""+HIR+" o"+NORM+YEL+"f "+HIY+"sh"+HIG+"ap"+HIB+"es"+HIM+" a"+NORM+""+HIR+"nd"+NORM+YEL+" c"+HIY+"ol"+HIG+"or"+HIB+"s."+HIM+"  "+NORM+""+HIR+"  "+NORM+YEL+"  "+HIY+"  "+HIG+"  "+HIB+"  "+HIM+"  "+NORM+"\n");
   set_level(24);
   set_hp(1600);
   set_wc(44);
   set_ac(23);
   set_chat_chance(10);
   set_heal(5,2);
   set_chance(25);
   set_wc_bonus(33);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(35);
   kale = clone_object("/players/francesco/kale/items/kale5.c");
   move_object(kale,this_object());
}

id(str) {return str=="kaleidoscope" || str=="kale" || str=="kaleido" || str == "white kale" ;}

heart_beat() {
   ::heart_beat();
   if(attacker_ob){  

     say(""+YEL+"   @@@         @@@"+NORM+"\n"+
         ""+YEL+"     @@@     @@@"+NORM+"\n"+
         ""+YEL+"       @@@ @@@"+NORM+"\n"+
         ""+HIC+"         @@@"+NORM+"\n");
     say(""+MAG+"       @@@ @@@"+NORM+"\n"+
         ""+MAG+"     @@@     @@@"+NORM+"\n"+
         ""+MAG+"   @@@         @@@"+NORM+"\n"+
         ""+HIR+"   @@@         @@@"+NORM+"\n"+
         ""+HIR+"     @@@     @@@"+NORM+"\n"+
         ""+HIR+"       @@@ @@@"+NORM+"\n"+
         ""+HIG+"         @@@"+NORM+"\n");
     say(""+WHT+"       @@@ @@@"+NORM+"\n"+
         ""+WHT+"     @@@     @@@"+NORM+"\n"+
         ""+WHT+"   @@@         @@@"+NORM+"\n"+
         ""+HIY+"        @"+HIY+"@@"+HIY+"@        "+NORM+"\n"+
         ""+HIY+"      @@@"+HIM+"@@"+HIY+"@@@      "+NORM+"\n"+
         ""+HIY+"    @@@"+HIM+"@@"+HIY+"@@"+HIM+"@@"+HIY+"@@@    "+NORM+"\n"+
         ""+HIY+"  @@@"+HIM+"@@"+HIY+"@@@@@@"+HIM+"@@"+HIY+"@@@  "+NORM+"\n"+
         ""+HIY+"    @@@"+HIM+"@@"+HIY+"@@"+HIM+"@@"+HIY+"@@@    "+NORM+"\n"+
         ""+HIY+"      @@@"+HIM+"@@"+HIY+"@@@      "+NORM+"\n"+
         ""+HIY+"        @"+HIY+"@@"+HIY+"@        "+NORM+"\n"+
         ""+HIM+"        @"+HIM+"@@"+HIM+"@        "+NORM+"\n"+
         ""+HIM+"      @@@"+HIC+"@@"+HIM+"@@@      "+NORM+"\n"+
         ""+HIM+"    @@@"+HIC+"@@"+HIM+"@@"+HIC+"@@"+HIM+"@@@    "+NORM+"\n"+
         ""+HIM+"  @@@"+HIC+"@@"+HIM+"@@@@@@"+HIC+"@@"+HIM+"@@@  "+NORM+"\n");
     say(""+HIM+"    @@@"+HIC+"@@"+HIM+"@@"+HIC+"@@"+HIM+"@@@    "+NORM+"\n"+
         ""+HIM+"      @@@"+HIC+"@@"+HIM+"@@@      "+NORM+"\n"+
         ""+HIM+"        @"+HIM+"@@"+HIM+"@        "+NORM+"\n");
      say(""+HIC+"  @@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIC+"  @@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIC+"  @@@            @@@"+NORM+"\n"+
         ""+HIC+"  @@@            @@@"+NORM+"\n");
     say(""+HIC+"  @@@            @@@"+NORM+"\n"+
         ""+HIC+"  @@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIC+"  @@@@@@@@@@@@@@@@@@"+NORM+"\n");
     say(""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@               @@@"+NORM+"\n"+
         ""+HIY+"  @@@               @@@"+NORM+"\n");
     say(""+HIY+"  @@@               @@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
     say(""+HIB+"         @@"+NORM+"\n"+
         ""+HIB+"         @@"+NORM+"\n"+
         ""+HIB+"         @@"+NORM+"\n"+
         ""+HIW+"   @@@@@@@@@@@@@@"+NORM+"\n");
     say(""+HIC+"         @@"+NORM+"\n"+
         ""+HIC+"         @@"+NORM+"\n"+
         ""+HIC+"         @@"+NORM+"\n");
     say(""+HIC+"         @@ "+NORM+"\n"+
         ""+HIC+"         @@"+NORM+"\n"+
         ""+HIC+"         @@ "+NORM+"\n"+
         ""+HIW+"   @@@@@@@@@@@@@@"+NORM+"\n");
     say(""+HIB+"         @@"+NORM+"\n"+
         ""+HIB+"         @@"+NORM+"\n"+
         ""+HIB+"         @@"+NORM+"\n");
     say(""+HIR+"          @"+NORM+"\n"+
         ""+HIR+"         @@@"+NORM+"\n"+
         ""+HIR+"        @@@@@"+NORM+"\n"+
         ""+HIR+"       @@@@@@@"+NORM+"\n");
     say(""+HIR+"      @@@@@@@@@"+NORM+"\n"+
         ""+HIR+"     @@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"    @@@@@@@@@@@@@"+NORM+"\n");
     say(""+HIM+"          @@"+NORM+"\n"+
         ""+HIM+"          @@"+NORM+"\n"+
         ""+HIM+"          @@"+NORM+"\n"+
         ""+HIW+"   @@@@@@@@@@@@@@@"+NORM+"\n");
     say(""+HIM+"          @@"+NORM+"\n"+
         ""+HIM+"          @@"+NORM+"\n"+
         ""+HIM+"          @@"+NORM+"\n");
     say(""+HIY+"  @@@@@@@@   @@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@   @@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@             @@@"+NORM+"\n"+
         ""+HIY+"  @@@             @@@"+NORM+"\n");
     say(""+HIY+"  @@@             @@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@   @@@@@@@@"+NORM+"\n"+
         ""+HIY+"  @@@@@@@@   @@@@@@@@"+NORM+"\n");
if(attacker_ob) {
   if(!random(9)) attacker_ob->heal_self(-30);         /* 10% 30 damage x 2    -> wc_bonus 6*/ 
   if(!random(6)) attacker_ob->hit_player(40);         /* 15% 40 damage x 1    -> wc_bonus 6*/
   if(!random(6)) attacker_ob->add_hit_point(-40);     /* 15% 40 damage x 1.5  -> wc_bonus 9*/
   if(!random(6)) attacker_ob->add_spell_point(-54);   /* 15% 54 damage x 1.5  -> wc_bonus 12*/
  }    
}
}



