inherit "/obj/monster";
 int skincount;
 int fabriccount;
 int platecount;
 int helmcount;
 int dresscount;
reset(arg) {
 skincount = 0;
 fabriccount= 0;
 platecount = 0;
 helmcount = 0;
 dresscount = 0;
   ::reset(arg);
   if (!arg) {

set_name("drand claclah");
set_alias("drand");
set_short("Drand ClaClah");
set_long(
"   Drand is a CtarlCtarl tradesman.  Soft gray matted fur covers nearly \n"+
"the entirety of his body.  The only spot being a under controlled puff of \n"+
"blond hair.  His hair is cut short surrounding his three inch pointed \n"+
"ears that poke out the side of his head.  A green tunic and shorts have \n"+
"seen much wear and dirt in their day.  Outside of the two pieces of worn \n"+
"down cloth, his body is bare but for a backpack.\n");

set_level(16);
set_hp(600);
set_al(200);
set_wc(24);
set_ac(17);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(10);
  load_chat("Drand says:  If you'd like to barter, please 'inquire.'\n");
  load_chat("Drand rummages through his backpack.\n");
  load_chat("Drand smiles and looks up at the skyline.\n");
} }

init(){
add_action("inquire","inquire");
add_action("inquire","ask");
}

cmd_barter(str) {
 if(!str) {
  notify_fail("Barter what?\n");
 return 0; }
 notify_fail("I can't take that.\n"); 
return 0; }

inquire(){
write(
"   Drand looks up at the trees and then searches though his backpack.  \n"+
"He then turns to you and says, 'I have most of the things I need here \n"+
"in my backpack.  But there are a few things here and there I could use.  \n"+
"You could just try to 'barter' whatever you have.'\n");
return 1; }


skincheck(){ return skincount; }
skinbarter(){ skincount = skincount + 1; }

fabriccheck(){ return fabriccount; }
fabricbarter(){ fabriccount = fabriccount + 1; }

platecheck(){ return platecount; }
platebarter(){ platecount = platecount + 1; }

helmcheck(){ return helmcount; }
helmbarter(){ helmcount = helmcount + 1; }

dresscheck(){ return dresscount; }
dressbarter(){ dresscount = dresscount + 1; }
