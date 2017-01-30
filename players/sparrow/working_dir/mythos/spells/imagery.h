#include "/players/mythos/closed/guild/def.h"
string whe, mess, trigger, mess2, chk, aner;
int delay, repe, sequence, t, sq;
object whob, send;
imagery(str) {
string tip;
  write("This power has been removed because of abuse\nYou have MonkeyDevil  to thank\n");
return 1;
if(!str || sscanf(str,"%s %s",tip,whe) != 2) { 
           write("Usage: image <type> <who>\n"+
                 "types: 1  straight messege\n"+
                 "       2  solid messege <delayable>\n"+
                 "who:   name of person or 'here' for the place\n");
           return 1;}
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 5) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 10) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(tip != "1" && tip != "2") { write("image cancelled.\n"); return 1;}
if(whe == "here") { whob = environment(tp); tip = "2";}
else { whob = find_player(whe); }
if(!whob) { write("That person is not on!\n"); return 1;}
if(whob->query_level() > 19 && whob->query_invis() > 0) {
write("That person is not on!\n"); return 1;}
if(tip == "1") { write("To: "+whe+"\nImage:  "); input_to("straight"); return 1;}
if(tip == "2") { write("Place: "+whe+"\nImage: "); input_to("solid"); return 1;}
return 1;}

straight(str) {
if(!str) { write("Image cancelled.\n"); return 1;}
mess = str;
if(in_editor(whob)) { write("That person is in edit.\n");}
mess = format(mess,60);
tell_object(whob,"\nAn image sent from "+capitalize(tpn)+
                 " appears before you:\n\n");
tell_object(whob,mess+"\n");
write("You send the image of :\n"+mess+"\nto "+whob->query_name()+"\n");
tp->add_spell_point(-1);
pp->add_sacrifice(-1);
return 1;}

solid(str) {
if(!str) { write("Image cancelled.\n"); return 1;}
send = clone_object("/players/mythos/closed/guild/spells/image.c");
mess = str; 
mess = format(mess,60);
send->set_first(mess);
if(whe == "here") { send->set_name("image"); send->set_where("here");
send->set_short(mess); send->set_long("An image.\n"); send->set_dest(6);
write("You may place a delay time and repeat time for the image.\n");
write("This would enable changing of the image to a second image and back.\n");
write("You may also have it trigger when someone enters the room or\n"+
      "when a specific person enters the room.\n");
write("You may also have the image broadcast the second image to a\n"+
      "specific trigger person when that person enters the room.\n");
write("To do these things: \n"+
      "when delay is asked type the number of heartbeats between images\n");
write("'0' if no change is needed <note with no delay there will\n"+
      "be no asking for repeat or new messege or person to trigger>\n"+
      "when repeat is asked type number of times of repeat\n"+
      "for no repeat type '0' for always repeat type '666'\n");
write("Note: for any repeat above 2 the trigger person will not be asked.\n");
write("when person is asked, type name of trigger person or 'any'\n"+
      "for anyone or 'none' to have a stable image\n"+
      "should you have a trigger person you will be asked if it is to\n"+
      "be broadcasted only to that person or not.\n");
write("\nDelay: ");
input_to("delayed");
return 1;}
send->set_name("star");
send->set_short("A small 'black' star.\n");
send->set_long("You may 'invoke star' to get the full image\n");
send->set_where(whe);
write("You may now have the whole room here the full image or just that person.\n"+
      "You may also have the image go through a set of different images...\n"+
      "making the image a series of events...\n"+
      "And you may choose from a varity of messege destruct systems....\n");
write("To choose the whole room to here when person is asked type 'all' if\n"+
      "only the holder type 'only'\n"+
      "To choose destruction methods type the number you wish <up to 5 extra -6 in all>\n"+
      "And for images, when asked type number of images including the one\n"+
      "just typed <i.e. you already have 1>\n"+
      "Then type the messeges.\n");
write("\nPerson : ");
input_to("person2");
return 1;}

delayed(str) {
if(!str || sscanf(str,"%d",delay) != 1) { write("Image cancelled.\n"); return 1;} 
send->set_delayed(delay);
if(delay == 0) { send->set_repeat(0);
write("You have created an image that is stable here.\n");
move_object(send,environment(tp));
tp->add_spell_point(-10);
pp->add_sacrifice(-10);
return 1;}
write("Repeat: ");
input_to("repeat");
return 1;}

repeat(str) {
if(!str || sscanf(str,"%d",repe) != 1) { write("Image cancelled.\n"); return 1;} 
send->set_repeat(repe);
write("Messege: ");
input_to("messege");
return 1;}

messege(str) {
if(!str) { write("Image cancelled.\n"); return 1;} 
mess2 = str;
mess2 = format(mess2,60);
send->set_xmes1(mess2);
send->set_extra(1);
if(repe < 3) {
write("Person: ");
input_to("person"); }
write("You have created an image that has a delay of "+delay+" hb \n"+
       "and repeats "+repe+" times then it destructs <note 666 means always repeat>\n");
move_object(send,environment(tp));
tp->add_spell_point(-10);
pp->add_sacrifice(-10);
return 1;} 

person(str) {
if(!str) { write("Image cancelled.\n"); return 1;} 
chk = str;
send->set_trigger(chk);
if(chk != "none" || chk != "any") {
write("Broadcast only to person? y/n  :");
input_to("only"); return 1;}
write("You have created an image that has a delay of "+delay+" hb \n"+
       "and repeats "+repe+" times and is triggered by "+chk+".\n");
move_object(send,environment(tp));
tp->add_spell_point(-10);
pp->add_sacrifice(-10);
return 1;} 

only(str) {
string anwer, un;
if(!str) { write("Image cancelled.\n"); return 1;}
anwer = str;
if(anwer == "n") { send->set_bcast(0);  un = "broadcast to all";}
if(anwer == "y") { send->set_bcast(1); un = "broadcast only";}
if(anwer != "n" && anwer != "y") { 
write("Broadcast only to person? y/n  :");
input_to("only"); return 1;} 
write("You have created an image that has a delay of "+delay+" hb \n"+
       "and repeats "+repe+" times and is "+un+" which \nis triggered by "+chk+".\n");
move_object(send,environment(tp));
tp->add_spell_point(-10);
pp->add_sacrifice(-10);
return 1;}

person2(str) { 
if(!str) { write("Image cancelled.\n"); return 1;}
aner = str;
if(aner != "only" && aner != "all") { 
write("\nPerson : ");
input_to("person2");
return 1;}
send->set_answ(aner);
write("Destruction Methods:  "+
      "\n1 = shatter, 2 = vanish, 3 = mist, 4 = delay explode,\n"+
      "5 = no destruct, 6 = random\n"+
      "Type : ");
input_to("destr");
return 1;}

destr(str) {
if(!str || sscanf(str,"%d",t) != 1) { write("Image cancelled.\n"); return 1;}
if(t != 1 && t != 2 && t != 3 && t != 4 && t!= 5 && t != 6) {
write("Destruction Methods:  "+
      "\n1 = shatter, 2 = vanish, 3 = mist, 4 = delay explode,\n"+
      "5 = no destruct, 6 = random\n"+
      "Type : ");
input_to("destr"); return 1;}
send->set_dest(t);
write("Number of messeges: ");
input_to("num_mes");
return 1;}

num_mes(str) {
int t, jn;
if(!str || sscanf(str,"%d",t) != 1) { write("Image cancelled.\n"); return 1;} 
if(t > 1) {
sequence = t -1; sq = sequence; send->set_extra(sq); jn = (sequence + 1 - sq); 
write("Messege #"+jn+" : ");
input_to("messs");
return 1;}
send->set_extra(0);
write("You have created an image that has a broadcasts "+aner+" when\n"+
       whe+" triggers it.  It will destruct using method "+t+"\n");
move_object(send,whob);
tp->add_spell_point(-10);
pp->add_sacrifice(-10);
return 1;} 

messs(str) {
string mesl;
if(!str) { write("Image cancelled.\n"); return 1;} 
mesl = str;
mesl = format(mesl,60);
switch(sq) {
  case 1: send->set_xmes1(mesl); break;
  case 2: send->set_xmes2(mesl); break;
  case 3: send->set_xmes3(mesl); break;
  case 4: send->set_xmes4(mesl); break;
  case 5: send->set_xmes5(mesl); break;
}
sq = sq-1;
if(sq > 0) {
write("Messege #"+sq+1+" : ");
input_to("messs");
return 1;}
write("You have created an image that has a broadcasts "+aner+" when\n"+
       whe+" triggers it.  It will destruct using method "+t+" and has\n"+
       sequence+" extra messeges.\n");
tell_object(whob,"A small demon hands you a black 'star'.\n"+
                 "The demon whispers: An image from "+capitalize(tpn)+".\n");
move_object(send,whob);
tp->add_spell_point(-10);
pp->add_sacrifice(-10);
return 1;}

