#include "/players/maledicta/ansi.h"
#define TP this_player()

query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }

int block;

id(str){
   return str == "lute" || str == "mals_bard_winner"; 
}

query_auto_load(){ return "/players/maledicta/closed/lute.c:"; }


short(){
   return HIW+"Silver Lute of the "+HIR+"B"+HIB+"a"+HIM+"r"+HIY+"d"+NORM+"";
}

long(){
   write(
      "This is a small silver lute. It is shaped like a pear sliced\n"+
      "lengthwise and has a bent neck that ends in a fretted finger-\n"+
      "board with numerous strings attached to it. It is always in\n"+
      "perfect tune and has the magical property of being able to\n"+
      "bring harmony to those who listen.  For a full list of its\n"+
      "magical powers type, 'lute_help'.\n"); 
   return 1;
}

init(){
   add_action("lute_info", "lute_help");
   add_action("play_it", "strum");
   add_action("btitle", "btitle");
   add_action("bsay", "bsay", 2);
   add_action("bhelp", "colorhelp");
   }

bhelp(){
 cat("/players/maledicta/closed/color.nfo");
 return 1;
 }

lute_info(){
  write(
BOLD+"<<><><><><><><><><><>> "+HIM+"Nirvana Bard"+NORM+BOLD+" <<><><><><><><><><><>>"+NORM+"\n"+
"    bsay <msg>     - A special say.\n"+
"    btitle <title> - Set your title, with color!\n"+
"    colorhelp      - Get help with using color in your title.\n"+
"    strum lute     - Play the lute and calm those around you. (15 sps)\n"+
BOLD+"<<><><><><><><><><><>>   "+HIM+"(*(*)*)"+NORM+BOLD+"    <<><><><><><><><><><>>"+NORM+"\n");
return 1;
 }

bsay(str){
int numero;
int a;
int b;
int c;
int d;
int x;
int y;
int z;
int e;
a = random(7);
b = random(7);
c = random(7);
d = random(2);
if(d == 0) { e = NORM; }
if(d == 1) { e = BOLD; }
if(a == 0) { x = BLU;}
if(a == 1) { x = RED;}
if(a == 2) { x = GRN;}
if(a == 3) { x = YEL;}
if(a == 4) { x = WHT;}
if(a == 5) { x = CYN;}
if(a == 6) { x = MAG;}
if(b == 0) { y = BLU;}
if(b == 1) { y = RED;}
if(b == 2) { y = GRN;}
if(b == 3) { y = YEL;}
if(b == 4) { y = WHT;}
if(b == 5) { y = CYN;}
if(b == 6) { y = MAG;}
if(c == 0) { z = HIB;}
if(c == 1) { z = HIR;}
if(c == 2) { z = HIG;}
if(c == 3) { z = HIY;}
if(c == 4) { z = HIW;}
if(c == 5) { z = HIC;}
if(c == 6) { z = HIM;}

if(TP->query_ghost()){ write("You are a ghost!\n"); return 1; }
if(!str){ write("bsay what?\n"); return 1; }
tell_room(environment(TP),
z+TP->query_name()+" "+e+x+"sings"+NORM+e+y+","+NORM+"\""+str+"\"\n", ({TP}));
tell_object(TP,
z+"You "+e+x+"sing"+NORM+e+y+","+NORM+"\""+str+"\"\n");
return 1;
}

btitle(str){
if(!str){ write("btitle <title>\n"); return 1; }
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
str = str+NORM;
TP->set_title(str);
write("done.\n");
return 1;
}

play_it(str){
   object ob;
   if(!str || str != "lute"){ write("strum what?\n"); return 1; }
   if(TP->query_sp() < 15){ write("You lack the energy to do that!\n"); return 1; }   
   tell_object(TP,
   "You strum the lute slowly and feel a calming effect radiate from its vibrating\n"+
   "cords.  It surrounds everyone in the room and causes them to calm their anger.\n");
   tell_room(environment(TP),
   TP->query_name()+" strums "+TP->query_possessive()+" lute slowly...\n"+
   "Waves of music calm your nerves and your anger ceases.\n", ({ TP }));
   ob = first_inventory(environment(TP));
   while(ob) {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      oc->attack_object();
      oc->attack_object();
      oc->stop_fight();
      oc->stop_fight();
      oc->stop_hunter();
      oc->stop_hunter();
      }
   TP->add_spell_point(-15);
   tell_room(environment(TP), "The fighting ends.\n");
   return 1;
   }


