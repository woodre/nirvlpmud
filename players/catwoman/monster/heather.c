

inherit "obj/monster";
string z;
reset() {
   set_hp(180);
   set_name("Heather");
   set_alias("heather");
   set_short("Heather");
   set_wc(16);
   set_ac(9);
   set_al(142);
   set_long("The most beautiful woman you have ever seen\npoised with elegance and charm\nher movement is pure poetry\nyou would be willing to die for one night with her\n");
   set_level(12);
   set_chat_chance(13);
   load_chat("Heather says: Hi, I'm glad you stopped by to keep me from getting lonely.\n");
   load_chat("Heather smiles with delight.\n");
   load_chat("Heather softly says: could you massage my shoulders?\n");
   load_chat("Heather whispers: How may I please you?\n");
   ::reset(0);
}

/*break*/
init(){
add_action("heather","heather");
add_action("kill","kill");
add_action("love","love");
add_action("sex","sex");
add_action("hug","hug");
add_action("sex","fuck");
add_action("sex","screw");
add_action("suck","suck");
add_action("kiss","kiss");
add_action("kiss","french");
add_action("eat","eat");
add_action("eat","lick");
add_action("eat","tongue");
add_action("touch","touch");
add_action("finger","finger");
add_action("touch","grope");
add_action("kill","hit");
add_action("kill","punch");
add_action("touch","fondle");
add_action("rape","rape");
add_action("dog","dog");
add_action("handcuff","handcuff");
}

heather(z) {
if (z!=""){
say("Heather "+z+".\n");
write("you made Heather "+z+".\n");
return 1;}
return 0;
}

kill(z) {
if (z=="heather"){
say("Heather softly says: "+this_player()->query_real_name()+ " I'm not into S&M.\n");
write("Heather softly says: Please don't hurt me.\n");
return 1;}
return 0;
}

love(z) {
if (z=="heather"){
say("Heather smiles at "+this_player()->query_real_name()+" \nHeather softly says: now thats more like it.\n");
write("Heather smiles at you\nHeather softly says: now thats more like it.\n");
return 1;}
return 0;
}

hug(z) {
if (z=="heather"){
say("Heather smiles at "+this_player()->query_real_name()+" as "+this_player()->query_real_name()+" hugs her.\nHeather softly says: Make love to me.\n");
write("You give Heather a warm embrace.\nHeather smiles at you\nHeather softly says: my pussy yearns for you.\n");
return 1;}
return 0;
}

handcuff(z) {
if (z=="heather"){
say("Heather struggles as "+this_player()->query_real_name()+" handcuffs her.\nHeather struggles against the cuffs.\nHeather asks "+this_player()->query_real_name()+": what are you going to do to me.\n");
write("You handcuff Heather.\nHeather struggles against the cuffs\nHeather softly says: what are you goin to do to me.\n");
return 1;}
return 0;
}

sex(z) {
if (z=="heather"){ 
	if(this_player()->query_gender()!="female"){
		say("Heather gently pushes "+this_player()->query_real_name()+" back and strokes him.\nHe is imediately aroused.\nHeather stradles "+this_player()->query_real_name()+"'s throbing member and rides him into ecstasy\n");
		write("Heather gently pushes you back and strokes you.\nYou are imediately aroused.\nHeather stradles your throbing member and rides you into ecstasy\n");
		return 1;}
	else {
	say("Heather gently pushes "+this_player()->query_real_name()+" back and strokes her.\nShe is imediately aroused.\nHeather tongues "+this_player()->query_real_name()+"'s juicy clit and rides her tongue into ecstasy\n");
	write("Heather gently pushes you back fingers your cunt.\nYou start dripping.\nHeather tongues your juicy clit and rides your tongue into ecstasy\n");
	return 1;}
}
return 0;
}

dog(z) {
if (z=="heather"){ 
	if(this_player()->query_gender()!="female"){
		say("Heather gets down on her hands and knees backing up to "+this_player()->query_real_name()+".\n he sticks his cock in her awaiting cunt and rides her doggie style.\nHeather says: Oh do me "+this_player()->query_real_name()+".\nHeather says: Do me like you allways do.\n");
		write("Heather gently pushes you back and strokes you.\nYou are imediately aroused.\nHeather stradles your throbing member and rides you into ecstasy\n");
		return 1;}
	else {
	say("Heather gently pushes "+this_player()->query_real_name()+" back and strokes her.\nShe is imediately aroused.\nHeather tongues "+this_player()->query_real_name()+"'s juicy clit and rides her tongue into ecstasy\n");
	write("Heather says I would if you had a cock or a didlo.\n Heather softly says: Fuck me instead.\nHeather gently pushes you back fingers your cunt.\nYou start dripping.\nHeather tongues your juicy clit and rides your tongue into ecstasy\n");
	return 1;}
}
return 0;
}

suck(z) {
if (z=="heather"){
	if(this_player()->query_gender()!="female"){
		say("Heather gets down and begins to suck "+this_player()->query_real_name()+"'s cock.\n");
		write("Heather drops to her knees and begins sucking on your lovin rod of joy.\n");
		return 1;}
	else{
	say("Heather begins to suck "+this_player()->query_real_name()+"'s tits.\n");
	write("Heather licks your nipples gently biting them.\nHeather sucks your golden mounds.\n");
	return 1;}
}
return 0;
}

kiss(z) {
if (z=="heather"){
say("Heather gives "+this_player()->query_real_name()+" a deep pasionate kiss that seems to last forever.\n");
write("You kiss Heather deeply. \nHeather passionately probes your mouth with her tongue.\n");
return 1;}
return 0;
}


eat(z) {
if (z=="heather"){
	if(this_player()->query_gender()!="female"){
		say("Heather climbs on to "+this_player()->query_real_name()+"'s face and fucks his tongue.\n");
		write("As you start licking Heather..\n Heather climbs on to your face, spreads her juicy clit and fucks your tongue.\n");
		return 1;}
	else{
		say("Heather climbs on to "+this_player()->query_real_name()+"'s face and fucks her tongue.\n");
		write("As you start licking Heather..\n Heather climbs on to your face, spreads her juicy clit and fucks your tongue.\n");
		return 1;}
}
return 0;
}

finger(z) {
if (z=="heather"){
	if(this_player()->query_gender()!="female"){
		say("Heather spreads her legs as "+this_player()->query_real_name()+" probes her pussy with his finger.\nHeather moans with pleasure\n");
		write("Heather slowley spreads her legs as your fingers go deeper inside her juicy cunt\n Heather whispers to you: please don't just tease me.\n");
		return 1;}
	else{
		say("Heather spreads her legs as "+this_player()->query_real_name()+" probes her pussy with her finger.\nHeather moans with pleasure\n");
		write("Heather slowley spreads her legs as your fingers go deeper inside her juicy cunt\n Heather whispers to you: please don't just tease me.\n");
		return 1;}
}
return 0;
}

touch(z) {
if (z=="heather"){
say("Heather seems to enjoy "+this_player()->query_real_name()+"'s touch.\n");
write("Heather trembles at your touch.\nHeather lovingly looks into your eyes.\n");
return 1;}
return 0;
}


rape(z) {
if (z=="heather"){
say("Heather screams: Don't!\nHeather screams: Stop!\nHeather screams: Don't Stop!\nHeather smiles wickedly. \n");
write("Heather screams: Don't!\nHeather screams: Stop!\nHeather screams: Don't Stop!\n");
return 1;}
return 0;
}

