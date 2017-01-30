#include "/players/pain/color.h"
#define tpg this_player()->query_gender()
#define tpn this_player()->query_name()
#define HOME "/players/pain/workroom"


int muf;
id(str) { return str == "penis" || str == "pains_penis"; }
reset(){
muf = 0;
move_object(this_object(),HOME);
}
query_muff(){ return muf;}
short() { return "A Whozitmawhatsis"; }
long(){
	write("nuff said\n");
}


laf(str) {
if(!str) { 
write("You laf.\n");
say(tpn+" lafs.\n");
return 1;
}
}
model(str) {
object ob;
if(!str){
   if(tpg == "female"){
      write("You model your sexy "+RED+"teddy"+END+" for all those in the room"+
            " to see!\n");
      say(tpn+" models her sexy "+RED+"teddy"+END+" for all those in the room"+
          " to see!\n");
      return 1;
   }
   if(tpg == "male"){
      write("You model you skimpy "+RED+"thong"+END+" for all of the women in"+
            " room to see!\n");
       say(tpn+" models a skimpy "+RED+"thong"+END+" for all the women in the"+
           " room to see!\n");
       return 1;
   }
}
   ob = present(str,environment(this_player()));
   if(!ob){
       write("Sorry that person is not here!\n");
       return 1;
   }
   if(tpg == "female"){
       write("You strip down to your "+RED+"teddy"+END+" and give "+
             ob->query_name()+" a nice show!\n");
       say(tpn+" strips down to her "+RED+"teddy"+END+" and puts on a nice"+
           " show for "+ob->query_name()+"!\n");
       tell_object(ob,"You smile in delight as "+tpn+" slides her clothes off"+
                   " and models her "+RED+"teddy"+END+" for you.\n");
       tell_object(ob,"You stare at her body and begin to drool!\n");
       write("You smile in delight as you see that "+ob->query_name()+
             " begins to drool over your scantily clad body.\n");
       say(ob->query_name()+" begins to drool as he watches "+tpn+
           "'s "+RED+"hot"+END+" body.\n");
       return 1;
    }
    if(tpg == "male"){
       write("You strip down to your "+RED+"thong"+END+" and model"+
             " it for "+ob->query_name()+"!\n");
       say(tpn+" strips down to his "+RED+"thong"+END+" and models"+
           " it for "+ob->query_name()+"!\n");
       tell_object(ob, tpn+" strips down to his "+RED+"thong"+END+
           " and dances sexily for you!\n");
       tell_object(ob, "You feel yourself begin to drool as you eye"+
           " the bulge in "+tpn+"'s thong!\n");
       write("You smile with delight as you notice "+ob->query_name()+
             " drooling at you.\n");
       say(ob->query_name()+" drools in lust eying the bulge in "+tpn+
           "'s "+RED+"thong"+END+"!\n");
       return 1;
    }
    return 1;
}

wedgie(str){
object ob;
string obg;
if(!str){
   write("You shouldn't give yourself a wedgie <sicko> \n");
   return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
   write("That player is not here!\n");
   return 1;
}
obg = ob->query_gender();

if(obg == "male"){
   write("You grab "+ob->query_name()+"'s underwear and pull them "+
         "up over his head!\n");
   tell_object(ob, tpn+" grabs your underwear and pulls the up over "+
         "your head!\n");
   tell_object(ob, "You scream out in pain and your underwear is lodged"+
         " up your ass.\n");
   say(tpn+" grabs "+ob->query_name()+"'s underwear and pulls them up "+
       "over his head.\n");
   say(ob->query_name()+" screams out in pain as his underwear is lodged "+
       "up his ass in the "+RED+"wedgie"+END+" from hell!\n");
   return 1;
}
if(obg == "female"){
   write("You playfully grab "+ob->query_name()+"'s underwear and give "+
         "her a sexy little wedgie.\n");
   tell_object(ob, tpn+" playfully grabs your underwear and gives you a "+
         RED+"sexy wedgie"+END+"!\n");
say(tpn+" grabs "+ob->query_name()+"'s underwear and gives her a "+RED+"sexy wedgie"+END+"!\n");
   write("You offer to help "+ob->query_name()+" get rid of the "+RED+
         "wedgie"+END+".\n");
   tell_object(ob, tpn+" offers to help take care of your "+RED+
         "wedgie"+END+".\n");
   say(tpn+" offers to help "+ob->query_name()+" take care of her "+RED+
         "wedgie"+END+".\n");
   return 1;
}
return 1;
}

kinky(){
   write("You say: Oh my! how "+GREEN+"K I N K Y"+END+"! ! !\n");
   say(tpn+" says: Oh my! how "+GREEN+"K I N K Y"+END+"! ! !\n");
   return 1;
}

grok(){
   write("You "+LIGHT_BLUE+"grok"+END+" solemnly.\n");
   say(tpn+" "+LIGHT_BLUE+"groks"+END+" solemnly.\n");
   return 1;
}

whip(str){
object ob;

if(!str) {
   write("You whip the room up into a "+RED+"frenzy"+END+"!\n");
   say(tpn+" whips everyone in the room into a "+RED+"frenzy"+
       END+"!\n");
   return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
   write("That person is not here!\n");
   return 1;
}
write("You whip "+ob->query_name()+" into a "+RED+"frenzy"+
      END+"!\n");
tell_object(ob, tpn+" whips you into a "+RED+"frenzy"+END+"!\n");
say(tpn+" whips "+ob->query_name()+" into a "+RED+"frenzy"+END+"!\n");
return 1;
}
cuff(str){
object ob;
string obg;
string pronoun;

if(!str){
	write("You take out a pair of shiny "+YELLOW+"hand cuffs"+END+
              " and twirl them around your finger.\n");
	say(tpn+" takes out a pair of "+YELLOW+"hand cuffs"+END+" and"+
              " twirls them around, eyeing you evilly.\n");
	return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
	write("Sorry that player is not present!\n");
	return 1;
}
obg = ob->query_gender();
if(obg == "male") { pronoun = "his"; }
if(obg == "female") { pronoun = "her"; }
if(tpg == "male"){
	write("You take out your "+YELLOW+"hand cuffs"+END+" and "+
	      "stroll over to "+ob->query_name()+" seductively.\n");
	tell_object(ob, tpn+" takes some "+YELLOW+"hand cuffs"+END+
	      " out of his pocket and seductively walks over to you.\n");
	say(tpn+" takes some "+YELLOW+"hand cuffs"+END+" out of his pocket "+
	      "and walks seductively over to "+ob->query_name()+".\n");
	write("You offer to take "+pronoun+" to your hotel room and "+
	      "to show "+pronoun+" how you like to use your "+YELLOW+
	      "cuffs"+END+".\n");
	tell_object(ob, tpn+" offers to take you to his hotel room and show "+
	      "you how to use his "+YELLOW+"cuffs"+END+".\n");
	say(tpn+" offers to take "+ob->query_name()+" to his hotel room "+
	      "and show "+pronoun+" how to use his "+YELLOW+"cuffs"+END+
	      ".\n");
	return 1;
}
if(tpg == "female"){
	write("You take your "+YELLOW+"hand cuffs"+END+" out and sexily "+
 	      "walk over to "+ob->query_name()+".\n");
	tell_object(ob, tpn+" takes some "+YELLOW+"hand cuffs"+END+" out of "+
	      "her pocket and sexily walks over to "+ob->query_name()+".\n");
	say(tpn+" takes some "+YELLOW+"hand cuffs"+END+" out of her pocket "+
	      "and walks sexily over to "+ob->query_name()+".\n");
	write("You offer to take "+ob->query_name()+" to your hotel "+
	      "to show "+pronoun+" how you like to use your "+YELLOW+
	      "cuffs"+END+".\n");
	tell_object(ob, tpn+"offers to take you to her hotel room to "+
	      "show you how she likes to use her "+YELLOW+"cuffs"+END+
	      ".\n");
	say(tpn+" offers to take "+ob->query_name()+" to her hotel room "+
	      "so she can show "+pronoun+" how she likes to use her "+YELLOW+
	      "cuffs"+END+".\n");
	return 1;
}
}
suck(str){
object ob;
string obg, pronoun;
if(!str){
	write(RED+"That is DISGUSTING... you should NOT do that to "+
              "yourself! ! !"+END+"\n");
	return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
	write("That player is not present.\n");
	return 1;
}
obg = ob->query_gender();
if(obg == "male") { pronoun = "his"; }
if(obg == "female") { pronoun = "her"; }
if(tpg == "male" && obg == "male"){
	write("Ummm... I think I would prefer if you NOT do that "+
	      "to another guy... thanks.\n");
	return 1;
}
if(tpg == "female" && obg == "female"){
	write("Ummm... I think I would prefer if you NOT do that "+
	      "to another girl... thanks.\n");
	return 1;
}
if(tpg == "male" && obg == "female"){
	write("You suck on "+ob->query_name()+"'s "+YELLOW+"golden "+
	      "mounds of heavenly joy"+END+"!\n");
	tell_object(ob, tpn+" sucks on your "+YELLOW+"golden mounds of "+
	      "heavenly joy"+END+"!\n");
	say(tpn+" sucks on "+ob->query_name()+"'s "+YELLOW+"golden mounds "+
            "of heavenly joy"+END+"!\n");
	return 1;
}
if(tpg == "female" && obg == "male"){
	write("You get down on your knees and suck "+ob->query_name()+
	      "'s "+RED+"rod of loving joy"+END+"!\n");
	tell_object(ob, tpn+" gets down on her knees and sucks your "+
	      RED+"rod of loving joy"+END+" thouroughly!\n");
	say(tpn+" sucks "+ob->query_name()+"'s "+RED+"rod of loving joy "+
	    END+"thouroughly!\n");
	return 1;
}
}

horny(){
write("You appear to be very horny!\n");
say(tpn+" appears to be very "+GREEN+"horny"+END+"!\n");
return 1;
}
tongue(str){
object ob;
if(!str){
write("You stick out your tongue as an offering to the room.\n");
say(tpn+" sticks out his tongue as an offering to the room.\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("The player must be present!\n");
return 1;
}
write("You offer to show "+ob->query_name()+" all the interesting things that you can do with your tongue!\n");
tell_object(ob, tpn+" offers to show you all the interesting things that can be done with the human tongue!\n");
say(tpn+" offers to show "+ob->query_name()+" all the interesting things that can be done with the human tongue!\n");
return 1;
}
agree(str){
object ob;
if(!str){
write("You nod your head in agreement.\n");
say(tpn+" nods in agreement.\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present in order to agree.\n");
return 1;
}
write("You nod in agreement with "+ob->query_name()+".\n");
say(tpn+" nods in agreement with "+ob->query_name()+".\n");
return 1;
}
foff(str){
object ob;
if(!str){
write("You tell everyone in the room to "+RED+"fuck off"+END+"!\n");
say(tpn+" tells everyone to "+RED+"fuck off"+END+"!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("How can you tell the asshole to fuk off when he ain't here?\n");
return 1;
}
write("You tell "+ob->query_name()+" to fuck off!\n");
tell_object(ob, tpn+" tells you to fuck off!\n");
say(tpn+" tells "+ob->query_name()+" to fuck off!\n");
return 1;
}
swiggle(str){
object ob;
if(!str){
write("You wiggle sexily around the room!\n");
say(tpn+" wiggles sexily around the room!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!\n");
return 1;
}
write("You wiggle sexily all over "+ob->query_name()+"'s body!\n");
tell_object(ob, tpn+" wiggles sexily all over your body!\n");
say(tpn+" wiggles sexily all over "+ob->query_name()+"'s body!\n");
return 1;
}
toss(){
write("You toss your cookies!\n");
say(tpn+" "+GREEN+"t"+END+BLUE+"o"+END+WHITE+"s"+END+YELLOW+"s"+END+RED+
    "e"+END+LIGHT_BLUE+"s"+END+" their cookies!\n");
return 1;
}
wibble(){
write("You wibble about the room!\n");
say(tpn+" wibbles about the room!\n");
return 1;
}
lake(str){
object ob;
if(!str){
write("You throw yourself into a nearby "+BLUE+"lake"+END+"!\n");
say(tpn+" throws himself into a nearby "+BLUE+"lake"+END+"!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!\n");
return 1;
}
write("You throw "+ob->query_name()+" into a nearby "+BLUE+"lake"+END+"!\n");
tell_object(ob, tpn+" throws you into a nearby "+BLUE+"lake"+END+"!\n");
say(tpn+" throws "+ob->query_name()+" into a nearby "+BLUE+"lake"+END+"!\n");
return 1;
}
snort(){
write("You snort loudly and feel much better!\n");
say(tpn+" snorts loudly and feels better!\n");
return 1;
}
face(str){
object ob;
if(!str){
write("You shout: 'In Your Face' to the entire room!\n");
say(tpn+" shouts: 'In Your Face' to the entire room!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!\n");
return 1;
}
write("You shout: 'In Your Face' to "+ob->query_name()+".\n");
tell_object(ob, tpn+" shouts: 'In Your Face' to you.\n");
say(tpn+" shouts: 'In Your Face' to "+ob->query_name()+".\n");
return 1;
}
boot(str){
object ob;
if(!str){
write("Usage: boot <playername>.\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!");
return 1;
}
write("You boot "+ob->query_name()+" in the head.... it hurts!\n");
tell_object(ob, tpn+" boots you in the head... OUCH it hurts!\n");
say(tpn+" boots "+ob->query_name()+" in the head... it looks painful!\n");
return 1;
}
lambada(str){
object ob;
if(!str){
write("You do the lambada all by yourself... how sad!\n");
say(tpn+" does the lambada alone.... how sad!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!\n");
return 1;
}
write("You "+RED+"lambada"+END+" sexily with "+ob->query_name()+"!\n");
tell_object(ob, tpn+RED+" lambadas"+END+" sexily with you!\n");
say(tpn+RED+" lambadas"+END+" sexily with "+ob->query_name()+"!\n");
return 1;
}
roll(){
write("You roll your eyes!\n");
if(tpg == "male"){
say(tpn+" rolls his eyes!\n");
return 1;
}
if(tpg == "female") {
say(tpn+" rolls her eyes!\n");
return 1;
}
}
mood(){
write("You proclaim to the world that: You are in the mood!\n");
say(tpn+" appears to be in the mood for romance!\n");
return 1;
}
kissme(str){
object ob;
if(!str){
write("You say: Kiss Me I'm "+GREEN+"Irish"+END+"!\n");
say(tpn+" says: Kiss me I'm "+GREEN+"Irish"+END+"!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!\n");
return 1;
}
write("You say: Kiss Me I'm "+GREEN+"Irish"+END+" to "+ob->query_name()+"\n");
tell_object(ob, tpn+"says: Kiss Me I'm "+GREEN+"Irish"+END+" to you sexily!\n");
say(tpn+" sexily says: Kiss Me I'm "+GREEN+"Irish"+END+" to "+ob->query_name()+".\n");
return 1;
}
nasty(){
write("You go: '"+RED+"N*A*S*T*Y"+END+" !'\n");
say(tpn+" goes: '"+RED+"N*A*S*T*Y"+END+" !\n");
return 1;
}
mosh(){
write("You mosh wildly to the sounds of the underground!\n");
say(tpn+" moshes wildly to the sounds of the underground!\n");
return 1;
}
rave(){
write("You dance wildly to the rave music in your head!\n");
say(tpn+" dances wildly to the rave music you cannot hear!\n");
return 1;
}
bummer(){
write("You go: Bummer!\n");
say(tpn+" goes: Bummer!\n");
return 1;
}
sucks(){
write("You go: Sucks to be you!\n");
say(tpn+" goes: Sucks to be You!\n");
return 1;
}
boring(){
write("You go: 'B-O-R-I-N-G!'\n");
say(tpn+" goes: B-O-R-I-N-G!'\n");
return 1;
}
wonder(){
write("You wonder if it is at all possible to ever be as kewl as Pain!\n");
say(tpn+" wonders if it is at all possible to ever be as kewl as Pain!\n");
return 1;
}
sdance(str){
object ob;
if(!str){
write("You do a "+RED+"sexy dance"+END+" to entertain those in the room!\n");
say(tpn+" does a "+RED+"sexy dance"+END+" to keep you entertained!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("The player must be present!\n");
return 1;
}
write("You do a "+RED+"sexy dance"+END+" for "+ob->query_name()+"!\n");
tell_object(ob, tpn+" does a "+RED+"sexy dance"+END+" just for you!\n");
say(tpn+" does a "+RED+"sexy dance"+END+" just for "+ob->query_name()+"!\n");
return 1;
}
tstick(str){
object ob;
if(!str){
write("You stick out your tongue!\n");
say(tpn+" sticks out their tongue!\n");
return 1;
}
ob = present(str, environment(this_player()));
if(!ob){
write("That player must be present!\n");
return 1;
}
write("You stick you tongue out at "+ob->query_name()+"!\n");
tell_object(ob, tpn+" sticks his tongue out at you!\n");
say(tpn+" sticks its tongue out at "+ob->query_name()+"!\n");
return 1;
}
replace(){
object new_patch;
new_patch = clone_object("players/pain/closed/items/piercing");
move_object(new_patch, this_player());
write(RED+"You tear out your old piercing and put in a new one.\n"+END);
destruct(this_object());
return 1;
}
replace_all(){
object ob, piercing;
int i;
if(this_player()->query_real_name() == "pain"){
write("The piercings are being replaced!\n");
ob = users();
for(i = 0; i < sizeof(ob); i++){
piercing = present("pains_piercing", ob[i]);
if(piercing) {
tell_object(ob[i], "Your piercing is being replaced!\n");
command("replace", ob[i]);
}
}
}
return 1;
}
pierce_news(){
cat("/players/pain/closed/items/pierce_news");
return 1;
}
get_rid_of_pierce(){
destruct(this_object());
return 1;
}
tell(str){
string who,msg;
object ob;
if(!str || sscanf(str,"%s %s",who,msg) != 2){
	write("Use: tell <who> <what>\n");
	return 1;
	}
ob = find_living(lower_case(who));
/* fixed by mizan.. i hate getting tells while invis */
  if(ob->query_invis() > 38) {
	write("No player with that name.\n");
	return 1;
	}
if(in_editor(ob))
{
	write("That player is in editor... try again later!\n");
return 1;
}
tell_object(ob, tpn+" tells you: "+msg+"\n");
write("You tell "+capitalize(who)+": "+msg+"\n");
return 1;
}
hpierce(){
cat("/players/pain/closed/items/pierce_help");
return 1;
}
ick(){
write("You stick out your tongue and go '"+YELLOW+"Ick"+END+"!'\n");
say(tpn+" goes '"+YELLOW+"Ick"+END+"!'\n");
return 1;
}
yuck(){
write("You are totally disgusted and make a Mr. Yuck face   '"+GREEN+"YUCK"+END+"!'\n");
say(tpn+" makes a Mr. Yuck face and goes '"+GREEN+"YUCK"+END+"!'\n");
return 1;
}
quiver(str){
object ob;
if(!str){
write("You quiver like a bowl of jelly from your own touch\n");
say(tpn+" pleases himself and quivers like a bowl of jello\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
write("Why are you quivering?... that person is not even around?\n");
return 1;
}
write("You quiver shamelessly like a bowl of jello at "+ob->query_name()+"'s touch!\n");
say(tpn+" quivers shamelessly from "+ob->query_name()+"'s touch.\n");
return 1;
}
jump(){
write("You shout: '"+GREEN+"Jump Around"+END+"' and begin to dance!\n");
say(tpn+" shouts: '"+GREEN+"Jump Around"+END+"' and begins to dance wildly!\n");
return 1;
}
jazz(){
write("You go '"+LIGHT_BLUE+"JaZzY"+END+"' and know that you are kewl!\n");
say(tpn+" goes: '"+LIGHT_BLUE+"JaZzY"+END+"'... you think to yourself: 'Wow that is kewl!\n");
return 1;
}
thigh(str){
object ob;
if(!str){
write("Ummm.... you cannot lick your own thigh... just thought you should know!\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
write("Sorry... your tongue ain't long enough to reach someone who is not here!\n");
return 1;
}
write("You lick a figure-8 onto the shapely inner thigh of "+ob->query_name()+".\n");
write("MmmmMMmmmm.... that is nice!\n");
tell_object(ob,tpn+" licks a figure-8 on your shapely inner thigh!\n");
tell_object(ob,"You feel slightly aroused..... \n");
say(tpn+" licks a figure-8 on "+ob->query_name()+"'s shapely inner thigh.\n");
say("You gasp!\n");
return 1;
}
toe(str){
object ob;
if(!str){
write("You suck your own big toe!\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
write("That player is not here...\n");
}
write("You suck on "+ob->query_name()+"'s big toe erotically!\n");
tell_object(ob,tpn+" sucks on your big toe.... you feel turned on!\n");
say(tpn+" sucks on "+ob->query_name()+"'s big toe!\n");
return 1;
}
howl(){
write("You howl loudly at the moon!  H O W L!\n");
say(tpn+" howls loudly at the moon!\n");
return 1;
}
sleep(){
write("You pass out from boredom and go to sleep\n");
say(tpn+" passes out from boredom and goes to sleep\n");
return 1;
}
chortle(){
write("You chortle demonically!\n");
say(tpn+" chortles demonically!\n");
return 1;
}
thwak(str){
object ob;
if(!str){
write("Who do you wish to thwak?\n");
return 1;
}
ob = present(str,environment(this_player()));
write("You thwak "+ob->query_name()+" for being "+BLUE+"stupid."+END+"\n");
tell_object(ob,tpn+" thwaks you for being stupid.\n");
say(tpn+" thwaks "+ob->query_name()+" for being stupid.\n");
return 1;
}
phair(str){
object ob;
if(!str){
write("Who's hair are you going to pull??\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
write("That person must be around for you to abuse them!\n");
return 1;
}
write("You pull "+ob->query_name()+"'s hair!\n");
tell_object(ob,tpn+" pulls your hair!  O U C H!\n");
say(tpn+" pulls "+ob->query_name()+"'s hair!\n");
return 1;
}
noogie(str){
object ob;
if(!str){
write("You give yourself a noogie... Duh!\n");
say(tpn+" gives himself a noogie!\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
write("This player must be around to receive a noogie!\n");
return 1;
}
write("You give "+ob->query_name()+" a noogie.... IT HURTS!\n");
say(tpn+" gives "+ob->query_name()+" a noogie.... it looks painful!\n");
tell_object(ob,tpn+" gives you a noogie.... ouch IT HURTS!\n");
return 1;
}
cower(){
write("You cower in absolute fear and terror!\n");
say(tpn+" cowers in absolute fear and terror!\n");
return 1;
}
romance(str){
object ob;
if(!str){
write("You desire some romance in your pitiful existance!\n");
say(tpn+" desires to have some romance once in awhile!... how sad!\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){
write("You gotta catch 'em before you can romance 'em!\n");
return 1;
}
write("You romance "+ob->query_name()+" hoping to get lucky!\n");
tell_object(ob, tpn+" tries to romance you!\n");
say(tpn+" tries to romance "+ob->query_name()+" in hopes of getting lucky!\n");
return 1;
}
roar(){
write("You throw back your head and R O A R!\n");
say(tpn+" roars... you shrink back in FEAR!\n");
return 1;
}
woo(){
write("You go 'Woo Woo'.\n");
say(tpn+" goes 'Woo Woo'\n");
return 1;
}
wish(){
write("You wish you were as cool as Pain.\n");
say(tpn+" wishes to be as cool as Pain.\n");
return 1;
}
boggle(){
write("You boggle at the concept.\n");
say(tpn+" boggles at the concept.\n");
return 1;
}
flex(){
write("You flex your muscles impressing those around you.\n");
say(tpn+ " tries to impress you by flexing.\n");
return 1;
}
fear(str){
if(!str){
write("You say 'Fear IT!'\n");
say(tpn+" says 'Fear IT!'\n");
return 1;
}
str = capitalize(str);
write("You fear "+str+".\n");
say(tpn+" fears "+str+".\n");
return 1;
}




kiss(str){
object ob;
string gender;
string gender2;
if(!str){
write("Kiss who?\n");
return 1;
}
ob = present( str, environment(this_player()));
if(!ob){
write("You pucker up, but then realize that this person isn't around.\n");
return 1;
}
if(ob == this_player()){
write("You want to kiss yourself?\n");
return 1;
}
write("You pull "+ob->query_name()+" closer.\n");
tell_object(ob,tpn+" pulls you closer.\n");
say(tpn+" pulls "+ ob->query_name()+" closer.\n");
gender = "its";
gender2 = "its";
if(this_player()->query_gender() == "male"){ gender = "his";}
if(this_player()->query_gender() == "female"){ gender = "her";}
if(ob->query_gender() == "female"){ gender2 = "hers";}
if(ob->query_gender() == "male"){ gender2 = "his";}
write("You feel your heart flutter as you softly press your lips\n");
write("against "+gender2+".\n");
say(tpn+" softly kisses "+ob->query_name()+".\n");
tell_object(ob,"You feel your heart flutter as "+tpn+" softly presses\n"+gender+" lips against yours.\n");
return 1;
}
cheer(str){
object ob;
if(!str){
write("You cheer enthusiastically!\n");
say(tpn+" cheers enthusiastically.\n");
return 1;
}
ob = present( str, environment(this_player()));
if(!ob){
write("Hmm... Just where is this "+str+"?\n");
return 1;
}
write("You cheer "+ob->query_name()+" enthusiastically.\n");
say(tpn+" cheers "+ob->query_name()+" enthusiastically.\n");
return 1;
}
lag(){
write("You raise your fist high in the air and curses the Gods for creating\n");
write("this LAG!!\n");
say(tpn+" curses the Gods for creating this LAG!!\n");
return 1;
}
raise(){
write("You raise your eyebrow in disbelief.\n");
say(tpn+" raises an eyebrow in disbelief.\n");
return 1;
}
alive(){
int count;
int bat;
string who,guild;
int x;
object ob;
object mas,monk,as,dopp;
ob = users();
write("\n");
write(RED+"~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~"+END+"\n");
write("   Name:          Lvl:    Pk     Guild    Location:\n");
write(RED+"~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~"+END+"\n");
for(x=0;x<sizeof(ob);x+=1){
if(random(100) < 3 && !bat && find_living("batarsis")){
bat = 1;
if(environment(find_living("batarsis")))
write("   Batarsis        19     "+RED+"Yes"+END+"    None     "+environment(find_living("batarsis"))->short()+"\n");
}
if(ob[x]->query_level() < 1000000){
if(ob[x]->query_invis() == 0){
who = ob[x]->query_name();
 count = strlen(who);
count = 16 - count;
if(present("pains_piercing",ob[x]))
write(BLUE+"~`~"+END);
else
write("   ");
write(who);
while(count>0){
write(" ");
count = count - 1;
}
if(ob[x]->query_level() < 20) {
write(ob[x]->query_level()+"\t");
}
else write(ob[x]->query_level()+"\n");
if(ob[x]->query_level() < 20) {
if(ob[x]->query_pl_k() == 1){write("  "+RED+"Yes"+END+"    ");}
if(ob[x]->query_pl_k() == 0){write("  "+YELLOW+"No"+END+"     ");}
guild = ob[x]->query_guild_name();
if(!guild) {write( "None     ");}
if(guild == "vampire") {write("Vampire  ");}
if(ob[x]->query_real_name() == "guest") {write("Guest    ");}
if(guild == "monk") {write("Monk     ");}
if(guild == "polymorph") {write("Poly     ");}
if(guild == "Knights Templar") {write("Knight   ");}
if(guild == "bard") {write("Bard     ");}
if(guild == "undead") {write("Undead   ");}
if(guild == "shardak") {write("Shardak  ");}
if(guild == "cyberninja") {write("Cyber    ");}
if(guild == "rangers") {write("Ranger   ");}
if(guild == "mage") {write ("Mage     ");}
if(!environment(ob[x])){
write("Location Unknown\n");
}
if(environment(ob[x])){
write(environment(ob[x])->short()+"\n");
}
}
}
}
}
write(RED+"~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~"+END+"\n");
write("Total Number of Players: "+x+"\n");
write(RED+"~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~"+END+"\n");
return 1;
}
pt(str){
int x;
object patch;
object ob;
ob = users();
for(x=0; x<sizeof(ob);x+=1){
if(present("pains_piercing", ob[x])){
patch = present( "pains_piercing", ob[x]);
if(patch->query_muff() == 0 && patch->query_color() == 0){
tell_object(ob[x],RED+"'~ "+END+BOLD+this_player()->query_name()+
            END+RED+" ~`:"+END+" "+str+"\n");
}
if(patch->query_muff() == 0 && patch->query_color() == 1){
tell_object(ob[x], "`~ "+this_player()->query_name()+" ~`: "+str+"\n");
}
}
}
return 1;
}
pe(str){
int x;
object ob;
object patch;
ob = users();
for( x = 0; x < sizeof(ob); x += 1) {
if(present("pains_piercing", ob[x])){
patch = present("pains_piercing", ob[x]);
if(patch->query_muff() == 0 && patch->query_color() == 0){
tell_object(ob[x], RED+"`~"+END+BOLD+"-P-"+END+RED+"~`"+END+" "+this_player()->query_name()+" "+str+"\n");
}
if(patch->query_muff() == 0 && patch->query_color() == 1){
tell_object(ob[x], "`~-P-~` "+this_player()->query_name()+" "+str+"\n");
}
}
}
return 1;
}
hush(){
if(muf == 0){
write("`~ You decide to no longer listen to the other fans ~`\n");
 muf = 1;
return 1;
}
if(muf == 1){
write("`~ You will again be able to listen to the other fans ~`\n");
 muf = 0;
return 1;
}
}
share(str){
object ob;
object patch;
if(!str){
 write("Usage: share <playername>\n");
 return 1;
 }
ob = present( str, environment(this_player()));
if(!ob){
 write("The player has to be present!\n");
 return 1;
 }
if(!living(ob)){
 write("You can only give a piercing to players!");
write("\n");
 return 1;
}
if( present("pains_piercing", ob)){
 write("This player already has a piercing.\n");
 return 1;
}
if( ob->query_real_name() == "guest" ){
 write("Only real players get a piercing!\n");
 return 1;
}
patch = clone_object("players/pain/closed/items/piercing");
move_object(patch,ob);
write("You give a piercing to "+ob->query_name()+"\n");
tell_object(ob, tpn+" grabs some flesh and jams a ring through it!\n");
tell_object(ob, tpn+" give you a "+RED+"piercing"+END+"!\n");
tell_object(ob, "Pain nods in approval.\n");
return 1;
}
