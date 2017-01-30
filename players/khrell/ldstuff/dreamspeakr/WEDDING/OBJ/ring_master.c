#include "/players/dreamspeakr/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define fsp find_player(spouse)

int help1 () {
   write("\n\n" +
    HIG+"("+HIR+"@"+HIG+")~~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~~("+HIR+"@"+HIG+")~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"                                                            "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   ring <mess>      Talk to your spouse                     "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   ring :<emote>    Emote through the ring                  "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   ring @<echo>     Echo through the ring                   "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+ 
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   bring <spouse>   Transport your spouse (75 sp's)         "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   go <spouse>      Go to your spouse (75 sp's)             "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   i_want_a_divorce Divorce your spouse                     "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   restore ring     Restore your spouse's ring              "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   ring_in <msg>    Set the message your spouse gets        "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                    when you enter the game.                "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   ring_out <msg>   Set the message your spouse gets        "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                    when you leave the game.                "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   ring_etch <msg>  Etch an inscription on your ring.       "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+    
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   read ring        Shows the inscription on your ring.     "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   tele on          Your spouse may bring/go to you.        "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+    
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   tele off         Your spouse can not bring/go to you.    "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"                                                            "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"   help ring        See this message                        "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"   see also help ring2                                      "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+")~~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~~("+HIR+"@"+HIG+")~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~("+HIR+"@"+HIG+")\n"+NORM);
}

help2() {
   write("\n\n"+
    HIG+"("+HIR+"@"+HIG+")~~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~~~("+HIR+"@"+HIG+")~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                  What your rose color means.                "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+ 
    HIG+"("+HIR+"@"+HIG+") "+NORM+HIG+" --`--}"+HIR+"@ "+NORM+" A true and faithful spouse.                       "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"          Red rose divorce cost:  0 coins/0 xp               "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+HIG+" --`--}"+HIY+"@ "+NORM+" Loving but slightly untrue to your beloved.        "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"          Yellow rose divorce cost:  5k coins/15k xp         "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+HIG+" --`--}"+HIM+"@ "+NORM+" Quite friendly with others.                        "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"          Purple rose divorce cost: 10k coins/20k xp         "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+HIG+" --`--}"+NORM+HIB+"@ "+NORM+" Boy oh boy is your spouse gonna be blue            "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"          when they see this!                                "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"          Blue rose divorce cost: 20k coins/30k xp           "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+HIG+" --`--}"+NORM+BOLD+BLK+"@"+NORM+"  You been bad bad bad...your spouse is gonna        "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"          KILL you!                                          "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+    
    HIG+"("+HIW+"@"+HIG+") "+NORM+"          Black rose divorce cost: 30k coins/40k xp          "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"Infidelity can be costly! But not if your spouse is present! "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"Your spouse can '"+HIR+"forgive"+NORM+"' you of these sins.   ***BUT*** be  "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+ 
    HIG+"("+HIR+"@"+HIG+") "+NORM+"warned, you can only have a red rose once.                   "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"help ring2  See this message                                 "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+ 
    HIG+"("+HIW+"@"+HIG+") "+NORM+"see also help ring                                           "+HIG+"("+HIW+"@"+HIG+")\n"+NORM+
    HIG+"("+HIR+"@"+HIG+") "+NORM+"                                                             "+HIG+"("+HIR+"@"+HIG+")\n"+NORM+
    HIG+"("+HIW+"@"+HIG+")~~~~~~~~~~~~~~("+HIR+"@"+HIG+")~~~~~~~~~~~~~~("+HIW+"@"+HIG+")~~~~~~~~~~~~~("+HIR+"@"+HIG+")~~~~~~~~~~~~("+HIW+"@"+HIG+")\n"+NORM+
    "\n"+NORM);
}

string find_color(int color){
      string *r_color;
      r_color = ({ HIR, HIY, HIM, HIB, NORM+BOLD+BLK });
      return r_color[color];
}
int ring_chat( string str, string spouse ) {
   string mess;
   int color;

   color = (int)present("wedding ring", tp)->query_wedding_ring_color();
   mess = str;
   if ( mess[0] == 58 ) {
      mess = HIG+"--,--"+NORM+GRN+"}"+find_color(color)+"@ " + NORM + HIG + this_player()->query_name() + " " +NORM+HIW+ mess[1..strlen(mess)] + "\n"+NORM;
   }
   else if ( mess[0] == '@' ) { 
      mess = HIG+"--,--"+NORM+GRN+"}"+find_color(color)+"@ " + NORM + HIW + mess[1..strlen(mess)] + "\n"+NORM;
   }
   else {
      mess = HIG+"--,--"+NORM+GRN+"}"+find_color(color)+"@ " + NORM + HIG + this_player()->query_name() + NORM + HIW + ": " + mess + "\n"+NORM;
   }
   if ( !find_player(spouse) ) {
      write(HIG+"--,--"+NORM+GRN+"}"+find_color(color)+"@ " + NORM + HIG + this_player()->query_name() + NORM + HIW + ": " + capitalize(spouse) + " is not logged in.\n"+NORM);
      return 1;
   }
   if(!present("wedding ring", fsp)){ 
   write("\n");
   write(HIG+"--,--"+NORM+GRN+"}"+find_color(color)+"@ " + NORM + HIG + this_player()->query_name() + NORM + HIW + ": " + capitalize(spouse) + " is no longer your spouse.\n"+NORM);
   return 1;
   }
   if( spouse && find_player(spouse) )
      tell_object(find_player(spouse), (mess));
   write(mess);
   return 1;
}

int bring ( string spouse ) {
   string here, there, where;

   if( !present("wedding ring", fsp) ){ 
      write("\n");
      write("You cannot do that, " + capitalize(spouse) + " is no longer your spouse. \n"+NORM);
      return 0;
   }
   if( this_player()->query_sp() < 75 ) {
      write("You need at least 75 spell points.\n");
      return 0;
   }
   if( present("wedding ring", fsp)->query_tp_ok() ) {
      write("Your beloved has teleport turned off.\n");
      return 0;
   }
   here = (string)environment(this_player())->realm();
   there = (string)environment(fsp)->realm();
   where = (string) call_other("obj/base_tele.c","teleport");
   if( here == "NT" || there == "NT" ) {
      write("A warping of space prevents you.\n");
      return 0;
   }
   this_player()->add_spell_point(-75);
   if(where) {
      move_object(find_player(spouse), where);
      tell_object(find_player(spouse), "Something is amiss!\n");
      return 1;
   } else {
        tell_object(fsp, "You appear beside your beloved.\n");
        write("You summon your beloved.\n");
        tell_room(environment(this_player()),capitalize(spouse) + " materializes.\n");
        move_object(fsp, environment(this_player()));
        return 1;
   }
}

int go ( string spouse ) {
   string here, there, where;

   if(!present("wedding ring", fsp)){ 
      write("\n");
      write("You cannot do that, " + capitalize(spouse) + " is no longer your spouse. \n"+NORM);
      return 0;
   }
   if( this_player()->query_sp() < 75 ) {
      write("You need at least 75 spell points.\n");
      return 0;
   }
   if( present("wedding ring", fsp)->query_tp_ok() ) {
      write("Your beloved has teleport turned off.\n");
      return 0;
   }
   here = (string)environment(this_player())->realm();
   there = (string)environment(fsp)->realm();
   if( here == "NT" || there == "NT" ) {
      write("A warping of space prevents you.\n");
      return 0;
   }
   this_player()->add_spell_point(-75);
   if(where = (string)call_other("obj/base_tele.c","teleport"))
               this_player()->move_player("with an astonished look#"+where);
   else { tell_object(fsp, "Your beloved appears at your side.\n");
      tell_room(environment(fsp), this_player()->query_name() + " materializes.\n");
      write("You go to your beloveds side!");
      move_object(this_player(), environment(fsp));
      return 1;
  }
}

int throw(string spouse, int color) {
   switch(color){
     case 0: tell_object(this_player(), "You are lucky, your divorce cost you NOTHING!\n");break;
     case 1: tell_object(this_player(), "You feel as though you lost a small amount of experience and money!\n");
        if(this_player()->query_money() < 5000) {
        tell_object(this_player(), "Im afraid you dont have 5,000 coins needed to pay the lawyers!\n");
        return 1;
        }
        if(this_player()->query_exp() < 15000){
        tell_object(this_player(), "Im afraid you don't have 15,000 experience to divorce your spouse.\n");
        return 1;
        }
        this_player()->add_money(-5000);
        this_player()->add_exp(-15000);
        break;
     case 2: tell_object(this_player(), "You feel as though you lost some experience and money! \n");
        if(this_player()->query_money() < 10000) {
        tell_object(this_player(), "Im afraid you don't have 10,000 coins needed to pay the lawyers!\n");
        return 1;
        }
        if(this_player()->query_exp() < 20000){
        tell_object(this_player(), "Im afraid you don't have 20,000 experience to divorce your spouse.\n");
        return 1;
        }
        this_player()->add_money(-10000);
        this_player()->add_exp(-20000);
        break;
     case 3: tell_object(this_player(), "That sure cost you a pretty penny! \n");
        if(this_player()->query_money() < 20000) {
        tell_object(this_player(), "Im afraid you don't have 20,000 coins needed to pay the lawyers!\n");
        return 1;
        }
        if(this_player()->query_exp() < 30000){
        tell_object(this_player(), "Im afraid you don't have 30,000 experience to divorce your spouse.\n");
        return 1;
        }
        this_player()->add_money(-20000);
        this_player()->add_exp(-30000);
        break;
     case 4: tell_object(this_player(), "That divorce cost you an arm and a leg!\n");
        if(this_player()->query_money() < 30000) {
        tell_object(this_player(), "Im afraid you don't have 30,000 coins needed to pay the lawyers!\n");
        return 1;
        }
        if(this_player()->query_exp() < 40000){
        tell_object(this_player(), "Im afraid you don't have 40,000 experience to divorce your spouse.\n");
        return 1;
        }
        this_player()->add_money(-30000);
        this_player()->add_exp(-40000);
        break;
   }
   write("Your request for divorce is granted!  Free at last!  Free at last!\n");
   say(this_player()->query_name() + " sings Free at last, free at last!  DIVORCE granted!\n");
   rm("/players/dreamspeakr/WEDDING/SAVEFILES/"+this_player()->query_real_name()+".o");
   destruct( present("wedding ring",this_player()) );
   if ( find_player(spouse) ) {
     tell_object(find_player(spouse), HIG+"--,--"+NORM+GRN+"}"+find_color(color)+"@ " + NORM + HIG + this_player()->query_name() + NORM + HIW + ": "+NORM+HIW+"Your spouse has divorced you.\n"+NORM);
   }
   return 1;
}

int renew_all_rings() {
   object *all;
   int i;

   all = users();
   for ( i = 0; i < sizeof(all); i++ ) {
        if( present("wedding ring",all[i]) ) present("wedding ring", all[i])->renew_my_ring();
   }
   present("wedding ring",tp)->renew_my_ring();
   write("Done.\n");
   return 1;
}

int start_restore ( string spouse ) {
   object new;

   if(present("wedding ring", find_player(spouse))){ 
   write("\n");
   write("That player already has a wedding ring.\n");
    return 1;
   }
   if(present("restore_ob", find_player(spouse))){
   write("\n");
   write("That player has already been asked, please wait for a response.\n");
    return 1;
   }
   new = clone_object("/players/dreamspeakr/WEDDING/OBJ/restore.c");
   new->set_asker(tpn);
   move_object(new, find_player(spouse));
   tell_object(find_player(spouse), "\n");
   tell_object(find_player(spouse), "Would you like to allow your wedding ring to be restored?\n");
   tell_object(find_player(spouse), "Answer: <accept or deny>\n");
   write("You ask " + fsp->query_name() + " to allow the restoriation.\n");
   return 1;
}

int forgive(string spouse) {
    if( !present(spouse, environment(this_player())) ){
       write("Your spouse must be here with you to be forgiven.\n");
       return 1;
    }
    if( !present("wedding ring", find_player(spouse)) ){
       write("You can not forgive somone who has divorced you. Try restoring it first.\n");
       return 1;
    }
    if( !present("wedding ring", find_player(spouse))->query_wedding_ring_color() ){
       write("Your spouse has done nothing wrong!\n");
       return 1;
    }
    if( (int)present("wedding ring", find_player(spouse))->query_wedding_ring_color() == 1 ){
       write("You can forgive, but you'll never forget.\n");
       tell_object(find_player(spouse), "Your spouse has forgiven you but will never forget.\n");
       return 1;
    }
    if( (int)present("wedding ring", find_player(spouse))->forgive_me() ){
       write("You forgive your spouse.\n");
       tell_object(find_player(spouse), "Your spouse has forgiven your transgressions!\n");
       return 1;
    }
    write("For some unknown reason you couldn't forgive your beloved.\nPlease do not bother other wizards, mail Dreamspeakr about it.\n");
    return 1;
}
