#include "/players/reflex/guilds/harem/harem.h"

query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }

int block;

id(str){ return str == "harem_crown" || str == "crown"; }

query_auto_load(){ return "/players/reflex/guilds/harem/crown.c:"; }

extra_look() { write(ETPN+" is wearing a crown of "+BOLD+BLU+"blue roses"+NORM+".\n"); }

long(){
   write("You are a proud member of Reflex's Harem.\n"+BLU+BOLD+
	"---"+NORM+BOLD+"Commands"+BLU+"--------------------------------\n"+NORM+
      " Harem Channel                 ct\n"+
      " Harem Emote                   ce\n"+
      " Channel Block                 cblock\n"+
	" Online Members                harem\n"+
	" Private Tell to Reflex        rtell\n"+
	" Private Emote to Reflex       rtelle\n"+
	" Harem Emotes                  cemotes\n"+
	" Leave Harem                   leave_harem\n"+BLU+BOLD+
	"-------------------------------------------\n"+NORM);
   return 1;
}

init_arg(str)
{
	harem_news();
}

init(){
   if(environment() != this_player()) return;
 
 if(TP->query_level() > 19 && TP->query_real_name() != "reflex"
        && TP->query_real_name() != "boltar"){
   destruct(this_object());
   }
   if(TP->query_gender() != "female" && TP->query_real_name() != "reflex" 
        && TP->query_real_name() != "boltar"){
   destruct(this_object());
   }
   add_action("crown_tell", "ct");
   add_action("crown_emote", "ce");
   add_action("crown_block", "cblock");
   add_action("crown_who", "harem");
   add_action("tell_reflex", "rtell");
   add_action("telle_reflex", "rtelle");
   add_action("crown_emotes", "cemotes");
   add_action("get_rid_of", "leave_harem");
   add_action("new_quit", "quit");
   add_action("harem_grin", "hgrin");
   add_action("harem_sniffle", "hsniffle");
   add_action("harem_shudder", "hshudder");
   add_action("harem_smile", "hsmile");
   add_action("harem_suck", "hsuck");
   add_action("harem_grinz", "hgrinz");
   add_action("harem_tongue", "htongue");
   add_action("harem_pants", "hpants");
   add_action("harem_shoulder", "hshoulder");
   add_action("harem_skiss", "hskiss");
   add_action("harem_shorts", "hshorts");
   add_action("harem_skirt", "hskirt");
   add_action("harem_get", "hget");
   add_action("harem_chill", "hchill");
   add_action("harem_chair", "hchair");
   add_action("harem_lips", "hlips");
   add_action("harem_love", "hlove");
   if(this_player()->query_level() < 20 && !this_player()->is_npc())
      crown_emote("enters the game.");
   }

new_quit(){
 crown_emote("leaves the game.");
 return;
 }


get_rid_of(){
 write("You leave the Harem.\n");
 destruct(this_object());
 return 1;
 }

tell_reflex(str){
object reflex;
if(!str){ write("Tell him what?\n"); return 1; }
reflex = find_living("reflex");
if(!reflex){ write("He is not currently logged on.\n"); return 1; }
tell_object(reflex, 
BLU+BOLD+"{>H<}"+NORM+BOLD+TP->query_name()+" tells you: "+str+NORM+"\n");
write(BLU+BOLD+"{>H<}"+NORM+BOLD+"You tell Reflex: "+str+NORM+"\n");
return 1;
}

telle_reflex(str){
object reflex;
if(!str){ write("Emote what?\n"); return 1; }
reflex = find_living("reflex");
if(!reflex){ write("He is not currently logged on.\n"); return 1; }
tell_object(reflex, 
BLU+BOLD+"{>H<}"+NORM+BOLD+TP->query_name()+" "+str+NORM+"\n");
write(BLU+BOLD+"{>H<}"+NORM+BOLD+TP->query_name()+" "+str+NORM+"\n");
return 1;
}

crown_block(){
   if(!block){
      write("You block the Harem channel.\n");
      block = 1;
   }
   else{
      write("You turn the Harem channel on.\n");
      block = 0;
   }
   return 1;
}

query_block(){ return block; }


crown_emote(str) {
   object list;
   object crown;
   int i;
   string myname;
   if(block) {
      write("You are blocking the Harem Channel.\n");
      return 1;
   }
   if (!str) { write("Use: he <what>\n"); return 1; }
   list = users();
   if(str == "block") {
      for(i=0;i<sizeof(list);i++) {
         crown = present("harem_crown",list[i]);
         if(crown && crown->query_block()) {
            write(list[i]->query_name()+" is blocking the Harem channel.\n");
          }
      }
      return 1;
   }
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      crown = present("harem_crown",list[i]);
      if (crown && !crown->query_block()) {
         tell_object(list[i], 
            BOLD+BLU+"{>Harem<}"+NORM+BOLD+myname+" "+str+NORM+"\n");
       }
   }
 return 1;
 }

crown_who(){
   int i, z;
   object *list;
  
   list = users();
   write(HIB);
   write(pad("",41,'-')+"\n");
   write("|"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+HIB+" |\n");
   write(NORM+HIB);
   write("|"+pad("",39,'-')+"|\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(list); i++) {
  
      if(!environment(list[i])) continue;
      if(present("harem_crown", list[i])){
         write(HIB+"|  "+HIW+pad(list[i]->query_name(),14)+NORM);
         z++;
         
         write(list[i]->query_level() + "\t");
         
         if (!list[i]->query_guild_name())
            write(pad("None",16));
         else
            write(pad(capitalize(list[i]->query_guild_name()),16));
         write(NORM+HIB+"|\n");
       }
   }
   if(!z) write(HIB+"@  "+NORM+pad("No Harem members logged on.",37)+NORM+HIB+"|\n");
   write(HIB);
   write("-"+pad("",39,'-')+"-\n");
   write(NORM);
   return 1;
}
 
crown_emotes() {

   write("These are special emotes only for Harem members.\n"+BLU+BOLD+
	"---"+NORM+BOLD+"Emotes"+BLU+"----------------------------------\n"+NORM+
      " hsniffle  hshudder  hgrin     hskirt   \n"+
      " hgrinz    hsuck     hsmile    hpants   \n"+
      " hshoulder hskiss    htongue   hshorts  \n"+
	" hget      hchair    hlips     hchill   \n"+
	" hlove     *hpantsk  *hshortsk *hskirtk \n"+
	" *Please mail me suggestions for more*  \n"+BLU+BOLD+
	"-------------------------------------------\n"+NORM);
   return 1;
}

harem_grin(string str)
{
  object target;
  
if(!str){
    write("You grin mischievously.\n");
    tell_room(ENVTP,TPN+" grins mischievously.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You grin mischievously at "+CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" grins mischievously at "+
	CAP((string)target->query_name())+".\n", ({ TP, target }));
    tell_object(target,TPN+" grins mischievously at you.\n");
    return 1;
  }
  else
  {
    write("From afar, you grin mischievously at "+
      CAP((string)target->query_name())+".\n");
    tell_object(target,"From afar, "+TPN+" grins mischievously at you.\n");
    return 1;
  }
}

harem_sniffle(string str)
{
  object target;
  
if(!str){
    write("You look up and sniffle, blinking back tears.\n");
    tell_room(ENVTP,TPN+" looks up and sniffles, blinking back tears.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You look up at "+CAP((string)target->query_name())+" and sniffle,"+
	  " blinking back tears.\n");
    tell_room(ENVTP, TPN+" looks up at "+CAP((string)target->query_name())+
	"and sniffles, blinking back tears.\n", ({ TP, target }));
    tell_object(target,TPN+" looks up at you and sniffles, blinking back tears.\n");
    return 1;
  }
  else
  {
    write("From afar, you look up at "+
      CAP((string)target->query_name())+" and sniffle, blinking back tears.\n");
    tell_object(target,"From afar, "+TPN+" looks up at you and sniffles,"+
	       " blinking back tears.\n");
    return 1;
  }
}

harem_shudder(string str)
{
  object target;
  
if(!str){
    write("You shudder in disgust.\n");
    tell_room(ENVTP,TPN+" shudders in disgust.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You shudder in disgust at "+CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" shudders in disgust at "+
	CAP((string)target->query_name())+".\n", ({ TP, target }));
    tell_object(target,TPN+" shudders in disgust at you.\n");
    return 1;
  }
  else
  {
    write("From afar, you shudder in disgust at "+
      CAP((string)target->query_name())+".\n");
    tell_object(target,"From afar, "+TPN+" shudders in disgust at you.\n");
    return 1;
  }
}

harem_smile(string str)
{
  object target;
  
if(!str){
    write("You smile wickedly.\n");
    tell_room(ENVTP,TPN+" smiles wickedly.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You smile wickedly at "+CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" smiles wickedly at "+
	CAP((string)target->query_name())+".\n", ({ TP, target }));
    tell_object(target,TPN+" smiles wickedly at you.\n");
    return 1;
  }
  else
  {
    write("From afar, you smile wickedly at "+CAP((string)target->query_name())+".\n");
    tell_object(target,"From afar, "+TPN+" smiles wickedly at you.\n");
    return 1;
  }
}

harem_suck(string str)
{
  object target;
  
if(!str){
    write("You suck on your lower lip.\n");
    tell_room(ENVTP,TPN+" sucks on her lower lip.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You gently suck on "+CAP((string)target->query_name())+"'s lower lip.\n");
    tell_room(ENVTP, TPN+" gently sucks on "+
	CAP((string)target->query_name())+"'s lower lip.\n", ({ TP, target }));
    tell_object(target,TPN+" gently sucks on your lower lip.\n");
    return 1;
  }
  else
  {
    write("From afar, you gently suck on "+CAP((string)target->query_name())+
	 "'s lower lip.\n");
    tell_object(target,"From afar, "+TPN+" gently sucks on your lower lip.\n");
    return 1;
  }
}

harem_grinz(string str)
{
  object target;
  
if(!str){
    write("You grin wit da z, baby!\n");
    tell_room(ENVTP,TPN+" grinz, baby!\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You grin wit da z at "+CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" grinz at "+
	CAP((string)target->query_name())+"!\n", ({ TP, target }));
    tell_object(target,TPN+" grinz at you!\n");
    return 1;
  }
  else
  {
    write("From afar, you grin wit da z at "+
      CAP((string)target->query_name())+"!\n");
    tell_object(target,"From afar, "+TPN+" grinz at you!\n");
    return 1;
  }
}

harem_tongue(string str)
{
  object target;
  
if(!str){
    write("You run your moist tongue across your lips as you look around seductively.\n");
    tell_room(ENVTP,TPN+" runs her moist tongue across her lips as she looks around"+
	" the room \nseductively.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You run your moist tongue across your lips as you gaze seductively at "+
	CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" runs her moist tongue across her lips as she gazes seductively at "+
	CAP((string)target->query_name())+".\n", ({ TP, target }));
    tell_object(target,TPN+" runs her moist tongue across her lips as she gazes seductively"+
	" at you.\n");
    return 1;
  }
  else
  {
    write("From afar, you run your moist tongue across your lips as you gaze seductively at "+
      CAP((string)target->query_name())+".\n");
    tell_object(target,"From afar, "+TPN+" runs her moist tongue across her lips as she "+
	"gazes\nseductively at you.\n");
    return 1;
  }
}

harem_pants(string str)
{
  object target;
  
if(!str){
    write("You play with your pants.\n");
    tell_room(ENVTP,TPN+" plays with her pants.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You play with "+CAP((string)target->query_name())+"'s pants.\n");
    tell_room(ENVTP, TPN+" plays with "+
	CAP((string)target->query_name())+"'s pants.\n", ({ TP, target }));
    tell_object(target,TPN+" plays with your pants.\n");
    return 1;
  }
  else
  {
    write("From afar, you play with "+
      CAP((string)target->query_name())+"'s pants.\n");
    tell_object(target,"From afar, "+TPN+" plays with your pants.\n");
    return 1;
  }
}

harem_shoulder(string str)
{
  object target;
  
if(!str){
    write("You give everyone in the room the cold shoulder.\n");
    tell_room(ENVTP,TPN+" gives everyone the cold shoulder.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You give "+CAP((string)target->query_name())+" the cold shoulder.\n");
    tell_room(ENVTP, TPN+" gives "+
	CAP((string)target->query_name())+" the cold shoulder.\n", ({ TP, target }));
    tell_object(target,TPN+" gives you the cold shoulder.\n");
    return 1;
  }
  else
  {
    write("From afar, you give "+
      CAP((string)target->query_name())+" the cold shoulder.\n");
    tell_object(target,"From afar, "+TPN+" gives you the cold shoulder.\n");
    return 1;
  }
}

harem_skiss(string str)
{
  object target;
  
if(!str){
    write("Who's shoulder are you going to kiss?\n");
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You put your arms around "+CAP((string)target->query_name())+
	" and kiss their shoulder lovingly.\n");
    tell_room(ENVTP, TPN+" puts her arms around "+
	CAP((string)target->query_name())+
	" and kisses their shoulder lovingly.\n", ({ TP, target }));
    tell_object(target,TPN+
	" puts her arms around you and kisses your shoulder lovingly.\n");
    return 1;
  }
  else
  {
    write("From afar, you put your arms around "+
      CAP((string)target->query_name())+" and kiss their shoulder lovingly.\n");
    tell_object(target,"From afar, "+TPN+
	" puts her arms around you and kisses your shoulder lovingly.\n");
    return 1;
  }
}

harem_shorts(string str)
{
  object target;
  
if(!str){
    write("You play with your shorts.\n");
    tell_room(ENVTP,TPN+" plays with her shorts.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You play with "+CAP((string)target->query_name())+"'s shorts.\n");
    tell_room(ENVTP, TPN+" plays with "+
	CAP((string)target->query_name())+"'s shorts.\n", ({ TP, target }));
    tell_object(target,TPN+" plays with your shorts.\n");
    return 1;
  }
  else
  {
    write("From afar, you play with "+
      CAP((string)target->query_name())+"'s shorts.\n");
    tell_object(target,"From afar, "+TPN+" plays with your shorts.\n");
    return 1;
  }
}

harem_skirt(string str)
{
  object target;
  
if(!str){
    write("You play with your skirt.\n");
    tell_room(ENVTP,TPN+" plays with her skirt.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You play with "+CAP((string)target->query_name())+"'s skirt.\n");
    tell_room(ENVTP, TPN+" plays with "+
	CAP((string)target->query_name())+"'s skirt.\n", ({ TP, target }));
    tell_object(target,TPN+" plays with your skirt.\n");
    return 1;
  }
  else
  {
    write("From afar, you play with "+
      CAP((string)target->query_name())+"'s skirt.\n");
    tell_object(target,"From afar, "+TPN+" plays with your skirt.\n");
    return 1;
  }
}

harem_get(string str)
{
  object target;
  
if(!str){
    write("You ain't gettin any.\n");
    tell_room(ENVTP,TPN+" ain't gettin any.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You let "+CAP((string)target->query_name())+" know he ain't gettin any.\n");
    tell_room(ENVTP, TPN+" lets the world know that "+
	CAP((string)target->query_name())+" ain't gettin any.\n", ({ TP, target }));
    tell_object(target,TPN+" lets you know you ain't gettin any.\n");
    return 1;
  }
  else
  {
    write("From afar, you let "+
      CAP((string)target->query_name())+" know he ain't gettin any.\n");
    tell_object(target,"From afar, "+TPN+" lets you know you ain't gettin any.\n");
    return 1;
  }
}

harem_chill(string str)
{
  object target;
  
if(!str){
    write("You are chillin like a villian!\n");
    tell_room(ENVTP,TPN+" is chillin like a villian!\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You think "+CAP((string)target->query_name())+" is chillin like a villian!\n");
    tell_room(ENVTP, TPN+" thinks "+
	CAP((string)target->query_name())+" is chillin like a villian!\n", ({ TP, target }));
    tell_object(target,TPN+" thinks your chillin like a villian!\n");
    return 1;
  }
  else
  {
    write("From afar, you think "+
      CAP((string)target->query_name())+" is chillin like a villian!\n");
    tell_object(target,"From afar, "+TPN+" thinks your chillin like a villian!\n");
    return 1;
  }
}

harem_chair(string str)
{
  object target;
  
if(!str){
    write("You pull up a chair and straddle it seductively.\n");
    tell_room(ENVTP,TPN+" pulls up a chair and straddles it seductively.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You pull up a chair and straddle it, facing "+
	CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" pulls up a chair and straddles it, facing "+
	CAP((string)target->query_name())+".\n", ({ TP, target }));
    tell_object(target,TPN+" pulls up a chair and straddles it, facing you.\n");
    return 1;
  }
  else
  {
    write("From afar, you pull up a chair and straddle it, facing "+
      CAP((string)target->query_name())+".\n");
    tell_object(target,"From afar, "+TPN+" pulls up a chair and straddles it, facing you.\n");
    return 1;
  }
}

harem_lips(string str)
{
  object target;
  
if(!str){
    write("You look around at everyone and lick your lips seductively.\n");
    tell_room(ENVTP,TPN+
	" looks around at everyone and licks her lips seductively\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You look at "+CAP((string)target->query_name())+
	" and lick your lips seductively.\n");
    tell_room(ENVTP, TPN+" looks at "+
	CAP((string)target->query_name())+
	" and licks her lips seductively.\n", ({ TP, target }));
    tell_object(target,TPN+" looks at you and licks her lips seductively.\n");
    return 1;
  }
  else
  {
    write("From afar, you look at "+
      CAP((string)target->query_name())+" and lick your lips seductively.\n");
    tell_object(target,"From afar, "+TPN+
	" looks at you and licks her lips seductively.\n");
    return 1;
  }
}

harem_love(string str)
{
  object target;
  
if(!str){
    write("You demonstrate your love for everyone.\n");
    tell_room(ENVTP,TPN+" demonstrates her love for everyone.\n", ({ TP }));
    return 1;
  }
  if(!(target=find_player(str)) || TP == target) return 0;
  if(ENV(target) == ENV(TP))
  {
    write("You demonstrate your love for "+CAP((string)target->query_name())+".\n");
    tell_room(ENVTP, TPN+" demonstrates her love for "+
	CAP((string)target->query_name())+".\n", ({ TP, target }));
    tell_object(target,TPN+" demonstrates her love for you.\n");
    return 1;
  }
  else
  {
    write("From afar, demonstrate your love for "+
      CAP((string)target->query_name())+".\n");
    tell_object(target,"From afar, "+TPN+" demonstrates her love for you.\n");
    return 1;
  }
}

crown_tell(str) {
   object list;
   object crown;
   int i;
   string myname;
   string history;
   if(block) {
      write("You are blocking the Harem Channel.\n");
      return 1;
   }
   if (!str) { write("Use: ct <what>\n"); return 1; }
   list = users();
   if(str == "block") {
      for(i=0;i<sizeof(list);i++) {
         crown = present("harem_crown",list[i]);
         if(crown && crown->query_block()) {
            write(list[i]->query_name()+" is blocking the Harem channel.\n");
          }
      }
      return 1;
   }
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      crown = present("harem_crown",list[i]);
      if (crown && !crown->query_block()) {
         tell_object(list[i], 
            BOLD+BLU+"{>Harem<}"+NORM+BOLD+myname+NORM+": "+str+"\n");
       }
   }
   return 1;
   }

harem_news()
{
	write(HIB +
		"{>HAREM<}"+NORM+BOLD+" Welcome back, sister.\n" +
		"Harem Master : Reflex (reflex@blarg.net)\n"+
		"Harem News:\n"+
		"Check out the new rtell and rtelle commands,\n"+
		"finally the much requested far emote ability!\n\n"+
	NORM);
	return 0;
}
