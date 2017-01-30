inherit "obj/monster";
string name,name2,wiz,wiz2;
string alt_name;
reset(arg) {if (arg) return; ::reset(arg); name2=capitalize(name);
wiz2=capitalize(wiz); set_gender(2); set_level(14); set_name(name);
alias="playmate"; alt_name=name+" the playmate"; race="slave"; set_hp(125);
set_al(-666); set_wc(14); short_desc=name2+", "+wiz2+"'s evil playmate";
long_desc="This is the woman Known as "+name2+".  A genuine playmate and "+wiz2+
"'s private love\n"+
"slave.  She has long curly black hair that drapes down over her body down to\n"
+
"approximately the middle of her back.  Her eyes are a vivid green and her lush\
n"+
"red lips are curled in an evil smile that burns right through you.  Either\n"+
wiz2+" can't afford clothing or he doesn't like her to dress in much.  She\n"+
"is wearing a 3 piece purple lingerie set with black fishnet stackings.\n";}
play_tell(str1,str2,str3,victim) {object er,person; er=environment(this_object()
);
   person=first_inventory(er);
   while (person) {if (person!=victim) tell_object(person,str1+str3);
/* More: (line 17) */
   else tell_object(person,str1+str2); person=next_inventory(person);} }
heart_beat() {object mysty; ::heart_beat(); mysty=find_living(wiz);
   if (!present(wiz,environment(this_object()))) {
    if(!wiz) { write(name2+" breaks down into tears realizing that her master" +
       "has left her completely.\n"+
"She sulks away in tears.\n"); destruct(this_object()); return;}
   say (name2+" rushs off after her lord and master "+wiz2+".\n");
move_object(this_object(),environment(mysty));
say (name2+" rushs in and clings to her master, "+wiz2+".\n");}
}
match(str,mstr) {string t1;
if (sscanf(str,mstr+"%s",t1)==1) return 1;}
catch_tell(str) {call_out("catch2",0,str);}
catch2(str) {object wh; string who,rest;
  sscanf(str,"%s %s",who,rest);
  wh=present(lower_case(who),environment(this_object()));
  if (!wh) return;  /* An emote or echo_all with no name attached */
  if (match(rest,"gives you a deep and passionate")) {
   if (who!=wiz2) {
    play_tell(name2+" reels back in utter disgust./n"+
"She starts spitting and gagging./n"+
name2+" says: Do it again and i'll cut your fucking tongue out of your mouth.\n"
,"","",wh); return;}
 play_tell(name2+"  smiles happily.\n"+name2+" says: Oh baby, kiss me more.\n",
name2+" presses up against you, pressing her mouth firmly against yours.\n"+
"After about a minute she lets go, you are breathless.\n",
name2+" presses her sexy body firmly against "+wiz2+".\n"+
"She looks into his eyes, then presses her mouth firmly against his.\n"+
"A few minutes later, she seperates from him, similing.\n",wh); return 1;}
if (match(rest,"kisses yo")) {
 if (who!=wiz2) {play_tell(name2+" gets an evil look in her eyes.\n"+
name2+" says: You son of a bitch!\n",name2+" slugs you in the stomach... HARD!\n",
 name2+" slugs "+who+" in the stomach...  HARD!\n",wh); return;}
play_tell(name2+" blushs.\n"+name2+" says: Thank you master, kiss me more?\n",
"","",wh); return;}
  if (match(rest,"grapes yo")) {
if (who!=wiz2) {play_tell(name2+" gasps!\n"+name2+" says: Cap a feel of this,"+
"bastard!\n",name2+" spins and kicks you right in the mouth, knocking out one of"+
"your teeth.\n",
name2+" spins and kicks "+who+" in the mouth knocking out one of his teeth.\n"
,wh); return;}
play_tell(name2+" starts to moan.\n"+name2+" says: Oh baby, that feels so good!"
,"",wh); return;}
if (match(rest,"fondles yo")) {
if (who!=wiz2) {play_tell("Acting out of instinct, "+name2+" grabs your fingers"+
"and snaps them back.\nCRACK!\nShe just broke your hand.\n",
name2+
" grabs "+who+"'s fingers and snaps them back.\nCRACK!\nShe just broke his hand!\n"
,wh); return;}
play_tell(name2+" says: Oooh honey, you're getting me horny...\n",name2+" presses up against you, you feel her perfect body against your skin.\n"+
name2+" whispers: Do it some more, honey.\n",
name2+" presses up against "+wiz2+" and whispers something in his ear.\n",wh); return;}
if (match(rest,"slaps you")) {
if (who!=wiz2) {play_tell(name2+" screams: Woman basher!\n",name2+" socks you"+
"in the jaw!\n",
name2+" socks "+who+" in the jaw!\n",wh); return;}
 play_tell(name2+" says: Did I do something wrong, master?\n"+
 name2+" tries to look pitiful (and down she does a good job of it!).\n","","",wh
); return;}
 if (match(rest,"kicks you")) {
 if (who!=wiz2) {play_tell(name2+" rubs her skin.\n"+name2+" says: I can kick"+
"too.\n"+
name2+" spins lightning fast and catchs "," you in the side of the head!\n",
who+" in the side of the head!\n",wh); return;}
play_tell(name2+" says: Baby, what did I do wrong, I'll make it up to you.\n"+
name2+" tries to look sexy (Not hard to do for her).\n","","",wh); return;}
}
