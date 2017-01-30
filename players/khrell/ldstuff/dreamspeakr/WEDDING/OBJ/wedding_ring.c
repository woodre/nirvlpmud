#include "/players/dreamspeakr/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define eo environment(this_object())
#define fsp find_player(spouse)
#define PATH "players/dreamspeakr/WEDDING/SAVEFILES/"
#define MASTER "/players/dreamspeakr/WEDDING/OBJ/ring_master.c"
string own, spouse, spouse_name;
string mess,messout,inscript,messin;
int ring_color,tp_ok;
static int married;
static string *rcolor;

void ring_save();
int restore(string str);
int id ( string str ) { return str == "ring" || str == "wedding ring"; }
int query_tp_ok();
int find_a_player();
int check();
int fix_ring();

reset(arg) { if(arg) return;
} 
void long() { 
  if( (string)tp->query_gender() == "female" ) {
     write(format("You see a delicate golden band of love with a large," +
      " pear shapped white diamond.\n\n"));
  }
  else { write("You see a wide band of pure gold, simple and elegant.\n\n"); }
  write("Type \"help ring.\"\n");
}

short () { 
  return (HIG+"--`--}"+ MASTER->find_color(ring_color) +"@ "+NORM+ own + "'s "+HIY+"golden "+NORM+"wedding ring (" + spouse_name + ")");
}

/* changed to you : query_name() */
/* 11/05 verte */
string extra_look () {
  return (environment()==this_player() ? "You are" : (string)environment()->query_name()+" is")+" wearing a "+HIY+"golden"+NORM+" wedding band inscribed: "+inscript;
}

string query_auto_load() { return "/players/dreamspeakr/WEDDING/OBJ/wedding_ring:";
}

init () {
  if(!eo) return 1;
  if(eo->is_kid()) {
    destruct(this_object());
    return 1;
  }
     if(eo == tp){
        add_action("rquit","quit");
        add_action("help", "help");
        add_action("start_restore","restore");
        add_action("throw_ring", "i_want_a_divorce");
        add_action("ring_chat", "ring");
        add_action("bring", "bring");
        add_action("go", "go");
        add_action("ring_in","ring_in");
        add_action("ring_out","ring_out");
        add_action("ring_etch","ring_etch");
        add_action("read","read");
        add_action("sex","sex");
        add_action("tele","tele");
        add_action("forgive","forgive");
        if ( (string)tpn == "dreamspeakr" ) {
            add_action("renew_all_rings", "renew");
        }
        if ( !own ) {
            own = (string)tpn;
            own = capitalize(own);
        }
        if ( !spouse ) {
            spouse_name = "None";
            spouse = "none";
        }
        if ( !messin ) { messin = "Have your spouse set their entrance message."; }
        if ( !messout ) { messout = "Have your spouse set their exit message."; }
        if ( !inscript ) { inscript = "Devoted forever to "+spouse_name; }
        if ( !ring_color ) { ring_color = 0; }
        if ( ring_color > 4 ) { ring_color = 4; }
        if (married == 2) {
            ring_save();
            return 1;
        }
        if ( !married ) { married = 1; }
        if(fsp) {
           if(present("wedding ring", fsp) ){
              if( check() ) { 
                 tell_object(fsp, HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIG + own + " "+NORM + HIW + messin+ NORM + "\n");
                 return 1;        
              } else {
              tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is no longer married to you.\n"+NORM); 
              return 1;
              }
           } else {
           tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is no longer married to you, you should throw your ring!\n"+NORM); 
           return 1;
           }
        } else {
        tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is not logged in.\n"+NORM); 
        return 1;
        }
     } 
}

init_arg(){
	if(restore_object(PATH+tp->query_real_name())) {
		write("Restoring wedding ring info. . . \n");
	}
	else {
		write("Creating an info file . . .\n");
		save_object(PATH+tpn);
	}

}

read(str) {
     if(!str) return 0; 
     if(id(str)) {
        write("\n"+inscript+"\n\n");
        return 1;
     }
     return 0;
}

int help ( string str ) {
   if ( str == "ring" ){
       MASTER->help1();
       return 1;
   }
   if ( str == "ring2" ){
       MASTER->help2();
       return 1;
   } 
   return 0;
}

int query_tp_ok() { return tp_ok; }

int fix_ring(){
    if( restore_object(PATH+eo->query_real_name()) ) return 1;
    return 0;
}

int tele(string str) {
   if(str == "on") {
     tp_ok = 0;
     write("Your ring's teleport is now on!\n");
     ring_save();
     return 1;
   }
   if(str == "off") {
     tp_ok = 1;
     write("Your ring's teleport is now off!\n");
     ring_save();
     return 1;
   }
   write("Usage: Tele <on|off>.\n");
   return 1;
}

int ring_chat( string str ) {
   if(!eo) { return 1; }
   if ( !str ) {
      write("You should type a message.\n"+NORM);
      return 1;
   }
   if( !fsp ) {
     write(HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is not logged on now!\n"+NORM); 
     return 1;
   }
   if( !check() ) { 
     tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is no longer married to you, you should throw your ring!\n"+NORM); 
     return 1;
  }
   MASTER->ring_chat( str, spouse );
   return 1;
}

static ring_out(str) {
   if(str) {
      messout = str; 
      ring_save();
      ring_out();
   }
   else write(HIG+"--,--"+NORM+GRN+"}"+(string)MASTER->find_color(ring_color)+"@ " + NORM + HIG + own + NORM + HIW + " "+messout+"\n"+NORM);
   return 1;
}

static ring_in(str) {
   if(str) {
      messin = str;  
      ring_save();
      ring_in();
   }
   else write(HIG+"--,--"+NORM+GRN+"}"+(string)MASTER->find_color(ring_color)+"@ " + NORM + HIG + own + NORM + HIW + " "+messin+"\n"+NORM);    
   return 1;
}

static ring_etch(str) { if(str) { 
   write("You take off the ring and etch into the ring:\n"+
   str+"\n"); inscript = str;    
   ring_save();
   }
   else write("Ring Inscript:\n"+inscript+"\n"); 
   return 1; 
}

int bring (string str){
   if ( !str ){
      write("Bring <spouse>.\n");
      return 1;
   }
   if ( lower_case(str) != spouse ) {
      write("That person is not your spouse.\n");
      return 1;
   }
   if( !fsp ) {
     write(HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is not logged on now!\n"+NORM); 
     return 1;
   }
   if( !check() ) { 
     tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is married to another, you should throw your ring!\n"+NORM); 
     return 1;
  }
   MASTER->bring(str);
   return 1;
}

int go(string str){
   if ( !str ){
      write("Go <spouse>.\n");
      return 1;
   }
   if ( lower_case(str) != spouse ) {
      write("That person is not your spouse.\n");
      return 1;
   }
   if( !fsp ) {
     write(HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is not logged on now!\n"+NORM); 
     return 1;
   }
   if( !check() ) { 
     tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is married to another, you should throw your ring!\n"+NORM); 
     return 1;
  }
   MASTER->go(str);
   return 1;
}

void set_spouse ( string str ) {
  spouse_name = capitalize(str);
  spouse = lower_case(str);
}

void set_owner ( string str ) {
  own = capitalize(str);
  ring_save();
}

void set_married ( int i ) { married = i; }

int query_married() { return married; }

string query_spouse() { return spouse; }

int throw_ring() {
/*
   log_file("dreamspeakr.divorce", own + " divorced " + spouse_name + " " + ctime() + "\n");
*/
   MASTER->throw(spouse, ring_color);
   return 1;
}

int renew_my_ring() {
   object ob;
   ob = clone_object("/players/dreamspeakr/WEDDING/OBJ/wedding_ring.c");
   move_object(ob, eo);
   if( (int)ob->fix_ring() ) {
      tell_object(eo, tp->query_name() + 
      " replaced your wedding ring.\n");
      destruct(this_object());
   }
   destruct(ob);
   return 1;
}

int renew_all_rings( string str ) {
   if ( !str || str != "rings" ) {
      notify_fail("Renew what?\n");
      return 0;
   }
   MASTER->renew_all_rings();
   return 1;
}

int start_restore( string str ) {
   if ( !str || str != "ring" ) return 0;
   if ( !spouse_name || !fsp ) {
      notify_fail(spouse_name +" is not on.\n");
      return 1;
   }
   MASTER->start_restore(spouse);
   return 1;
}

int forgive(string str) {
    if( !str || str != spouse){
       write("You can only forgive your spouse!\n");
       return 1;
    }
    MASTER->forgive(spouse);
    return 1;
}

int forgive_me(){
    --ring_color;
    return 1;
}

int query_wedding_ring_color(){ return ring_color; }

sex( str ){  
   if(!str || str == spouse || str == tp->query_real_name()) return 0;
   if( fsp ) {
      if( environment(tp) == environment(fsp) ) { return 0; } 
   }
   if( str != "yes" && !find_player(str) ) { return 0; }
   if( str == "yes" && find_a_player()  ||  present(str, environment(tp)) ){
     ++ring_color;
     if( ring_color > 4 ){ ring_color = 4; }
     ring_save();
   }
   return 0;
}

find_a_player(){
   int i;
   object *obs;
   obs = all_inventory(environment(tp)); 
   i = sizeof(obs);
   while( i ){
         --i; 
         if( interactive(obs[i]) && obs[i] != tp ){ return 1; }
   }
   return 0;
}

rquit() { 
  married = 1;
  if(fsp) {
     if(present("wedding ring", fsp) ){
        if( check() ) { 
           tell_object(fsp, HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIG + own + " "+NORM + HIW + messout+ NORM + "\n"); 
           return 0;        
        }
        tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is no longer married to you.\n"+NORM); 
        return 0;
     }
     tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is married to another, you should throw your ring!\n"+NORM); 
     return 0;
  }
  tell_object(eo,HIG+"--,--"+NORM+GRN+"}"+MASTER->find_color(ring_color)+"@ " + NORM + HIW + spouse_name + " is not logged in.\n"+NORM); 
  return 0;
}

ring_save(){
  save_object(PATH+tp->query_real_name());
}

check() { 
   if( !present("wedding ring", fsp) ) { return 0; }
   if( present("wedding ring", fsp)->query_spouse() == tp->query_real_name() ) {
      return 1; 
   } else { return 0; }
}

drop() { return 1; }
get() { return 0; }
