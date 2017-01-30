#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define eo environment(this_object())
#define tpn tp->query_real_name()
#define fsp find_player(spouse)
#define PATH "players/mythos/closed/marry/"+tpn
#define MASTER "/players/mythos/closed/marry/master_ring.c"

string own, spouse;
string mess,messout,inscript;

id(str) { return str == "ring" || str == "mring"; }

short() { return "An intricate celtic wedding band ("+spouse+")"; }

long() { 
  write("  A band of intricately wrought fine gold with a highly detailed \n"+
  "etching worked deep into the surface of two stylized Ravens amid \n"+
  "a complex knotwork pattern cleverly interwoven about them and \n"+
  "detailed with white gold.  Crossed within the branches in the up \n"+
  "ward point of victory are a broad headed spear and an angelsword. \n"+
  "Also hidden among the branches are what appear to be two wolves \n"+
  "and an eight legged horse as well as the subtle sillouette of a \n"+
  "warrior angel on a horse, or perhaps the wings are on the horse.  \n"+
  "On the underside are etched a series of ancient Viking Runes that \n"+
  "form an inscription of some power.\n"); }

spouse_set(str) { if(sec()) { spouse = str; saves(); }
                  else destruct(this_object());}
own_set(str) { if(sec()) { own = str; saves(); }
                  else destruct(this_object());}

reset(arg) { if(arg) return;
             own = spouse = "mythos";
             mess = "MOO"; messout = "mooer";
             inscript = "Vous";
      call_out("mooed",3);
  }

init() {
if(!eo) return 1;
  if(eo == tp) {
    if(!restore_object(PATH)) { destruct(this_object()); return 1; }
    add_action("rquit","quit");
    add_action("help","ring_help");
    add_action("teleg","rgoto");
    add_action("teles","rsummon");
    add_action("ringline");add_xverb("rt");
    add_action("ring_in","ring_in");
    add_action("ring_out","ring_out");
    add_action("ring_title","ring_title");
    add_action("ring_etch","ring_etch");
    add_action("scry","scry");
    add_action("read","read");
    add_action("trns","trns"); }
  else  { destruct(this_object()); return 1; }
}

rquit() { if(check()) MASTER->ringline("e "+capitalize(own)+
          " "+messout+"\n",fsp);   }

mooed() {
  if(!eo) return 1;
  if(check()) {
   MASTER->ringline("e "+capitalize(own)+" "+mess+"\n",fsp);
  } else {
    tell_object(eo,"Your spouse is not in the game.\n"); }
return 1; }

read(str) { if(!str) return 0; 
            if(id(str)) {
            write("\n"+inscript+"\n\n");
            return 1; }}

static help() { cat("/players/mythos/closed/marry/rhelp"); write("\n");
                return 1;}
static teleg() { if(check()) MASTER->teleg(fsp); 
                 else write("Your spouse is not in.\n"); 
                 return 1;}
static teles() { if(check()) MASTER->teles(fsp); 
                 else write("Your spouse is not in.\n");
                 return 1;}
static ringline(str) { if(check()) MASTER->ringline(str,fsp); 
                   else write("Your spouse is not in.\n"); 
                   return 1;}
static ring_in(str) { if(str) { mess = str; saves(); 
                        ring_in();}
                      else write("Ring Login:\n"+mess+"\n");    
                      return 1;}
static ring_out(str) { if(str) { messout = str; saves();
                         ring_out();}
                 else write("Ring Logout:\n"+messout+"\n");
                      return 1;}
static ring_etch(str) { if(str) { 
write("You take off the ring and etch into the ring:\n"+
       str+"\n"); inscript = str;  saves(); } 
               else write("Ring Inscript:\n"+inscript+"\n"); 
                       return 1; }
static scry(str) { if(!str) str = "X"; 
                   if(check()) MASTER->scry(str,fsp); 
                   else write("Your spouse is not in.\n"); 
                   return 1;}
static trns(str) { if(!str) str = "X"; 
             if(check()) MASTER->trns(str,fsp); 
               else write("Your spouse is not in.\n"); 
                    return 1;}
static ring_title(str) { 
     if(str) { tp->set_title(str); tp->save_me();
               write(tp->short()); }
               else write(tp->short()); return 1;}

saves() { save_object(PATH); return 1; }

static sec() {
  if(tp->query_level() > 99 && tp == find_player(tpn)) 
   return 1;
  else return 0; 
}

check() { if(fsp) return 1; return 0; }

query_auto_load() { return "/players/mythos/closed/marry/omring.c:"; }
drop() { return 1; }
get() { return 0; }