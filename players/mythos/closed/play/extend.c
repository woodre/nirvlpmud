#define LIL find_living("lilith")
#define ELL present("lilith",environment(tp))
#define LLL "/players/mythos/closed/guild/task/hills/dragon.c"
#include "/players/mythos/closed/guild/def.h"

id(str) { return str == "lx"; }

get() { return 0; }
drop() { return 1; }

init() {
  if(tp->query_real_name() != "mythos" &&
     tp->query_real_name() != "meshitsukai" &&
     tp->query_real_name() != "priest") {
     destruct(tp);
     return 1;}
     else {
       add_action("ddd","drag");
       add_action("dgg","dsp");
      add_action("did","din");
       add_action("dmd","dmv");
       add_action("sic","sic");
       add_action("dfd","dfo");
       add_action("dw","wander");
       add_action("dm","spys");
       add_action("go","seek");
       add_action("shape","morph");
       add_action("llisten","ears");
       add_action("sd","s&d");
       add_action("ddt","track");
       add_action("lhelp","lhelp");
       add_action("lil","lc");
       add_action("dsds","dldl");
       add_action("whereas","whl");
     }
}

lhelp() { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->lhelp();
return 1; }
ddd(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->ddd(str); }
return 1;}
dgg(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->dgg(str); }
return 1;}
did(arg) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->did(arg); }
return 1;}
dmd(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->dmd(str); }
return 1;}
sic(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->sic(str); }
return 1;}
dfd() { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->dfd(); }
return 1;}
dw(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->dw(str); }
return 1;}
dm() { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->dm(); }
return 1;}
go(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->go(str); }
return 1;}
shape(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->shape(str); } 
return 1;}
llisten() { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->llisten(); } 
return 1;}
sd(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->sd(str); }
return 1;}
ddt(str) { if(!ELL) { if(!LIL) { write("Lilith is not in.\n"); return 1;}
           LIL->ddt(str); }
return 1;}
lil() {
  if(LIL) {
    move_object(LIL,environment(this_player()));
    write("Lilith comes to your call.\n");
  return 1;}
  move_object(clone_object("/players/mythos/closed/guild/task/hills/dragon.c"),
              environment(this_player()));
  write("Lilith is now here.\n");
return 1;}

dsds() { if(LIL) { destruct(LIL); write("Lilith gone.\n"); return 1;}
         write("Not in play.\n");
return 1;}

whereas() {  
object surround;
int h;
if(LIL) { write(environment(LIL)); 
                       write("\n"+environment(LIL)->short()+".\n");
                       surround = all_inventory(environment(LIL));
                       for(h=0;h<sizeof(surround);h++) {
                         if(surround[h] != this_object() &&
                            living(surround[h])) {
                            if(surround[h]->query_npc()) {
                               write(surround[h]); write("  "); }
                            write(BLU+surround[h]->query_real_name()+"\n"+NORM);
                            }
                        }
                       return 1;}
             write("Not in play.\n");
return 1;}
