#include <esc.h>
#define myself this_player()
static string it;
reset(arg) {
        if(arg) return;
        /* Initialization code goes here */
}
   
long() {
        write( "A magic tool built by Francesco. Type 'com1' to see what\n"+
               "commands are currently available.\n" );
        return 1;
}

short() {
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name()) {
    tell_object(environment(this_object()),esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
    tell_object(environment(this_object()),capitalize(who)+" has just checked your inventory.");
    tell_object(environment(this_object()),esc+"[0m"+"\n");
   }
  return "Francesco's (wiz)tool (used)";
}

id(str) {
        if( str == "tool" ) return 1;
        return 0;
}

init() {
        add_action("com1","com1");
        add_action("bb","bb");
        add_action("ipquery","ipquery");
        add_action("nclone", "nclone" );
        add_action("dhl", "dhl" );
        add_action("go" , "go" );
        add_action("goin", "goin" );
        add_action("se","se");
        add_action("spaventa","spaventa");
        add_action("awho","awho");
        add_action("iwho","iwho");
        add_action("force", "force" );
        add_action("snop","snop");
        add_action("move", "move" );
return 1;}

com1() { 
     cat("/players/francesco/closed/helptool.c");
return 1;}
 
dhl(str){ 
    string stuff,rece;
    object stuff1,rece1;
    if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {notify_fail("You fail to send.\n");  return 0;}
    if(!present(stuff) || !find_living(rece))
      {notify_fail("Stuff or receiver not present.\n");return 1;}
    rece1=find_living(rece);
    stuff1=present(stuff);
    move_object(stuff1,rece1);
    tell_object(rece1,"A "+stuff+" is sent to you by Francesco.\n");
    write( "Ok, "+stuff1+" sent to "+rece1+".\n" );
return 1;}

go(arg) {
    object who,where;
    who= find_living(arg);
     if(!who) {notify_fail("No players with that name on.\n"); return 0;}
    where=environment(who);
    move_object(this_player(),where);
    write("Ok, moved to "+who+", in "+where+".\n");
return 1;}
  
force(str) {
  object who;
  string what;
  if(sscanf(str,"%s %s",who,what)==2) {
    if(!find_living(who)) {notify_fail("That is not on the MUD!\n"); return 0;}
    command(what,find_living(who));
    write("Done.  Forced "+who+" to "+what+".\n");
  return 1;}
  write("Usage: force <player> <action>\n");
return 1;}


get() {return 1;}

drop() {return 1;}

se(str) {
        if(!str) return 0;
        write("A Ghost "+str+"\n");
        say("Someone "+str+"\n");
return 1;}

iwho(str) {
  object us;
  string is_invis;
  int x, y;
  if(str) return;
  us=users();
  write("[-----*inv player*--------*location*-------------------------------------------]\n");
  for(x=0;x<sizeof(us);x++) {
        is_invis = us[x]->short();
        y = x+1;
        if(is_invis==0){
        write("["+y + "]\t" + capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())>7)
        write("\t"); else write("\t\t");
      write(environment(us[x])->short());
      write("\n");}}
return 1;}

awho(str){
  object us;
  int x;
  if(str) return;
  us = users();
  write("*-----------------------------------------------------------------------------*\n");
  write("*Name------Sex-Level---Guild---------Location---------------------------------*\n");
  write("*-----------------------------------------------------------------------------*\n");
  for(x=0;x<sizeof(us);x++){
  int invis;
  invis=us[x]->query_invis();
  if(invis<this_player()->query_level()){
  if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
        write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
        write("\t"); else write("\t\t");
  write(esc+"[0m");
  write("\b\b\b\b");
  if(us[x]->query_gender()=="male")
   write("M   ");
  else
   if(us[x]->query_gender()=="female")
   write("F   ");
  else 
    write("C   ");
  write(us[x]->query_level()+"\t\b");
  if(us[x]->query_guild_name())
   write(capitalize(us[x]->query_guild_name())+"\t");
  else 
   write("None\t");
   if(!us[x]->query_guild_name()||strlen(us[x]->query_guild_name())<=8) write("\t");
      write("\b\b\b\b");
        if(!environment(us[x])) write("Logging in");
                else write(environment(us[x])->short());
        write("\n");}
                }
  write("*-----------------------------------------------------------------------------*\n");
  write("*----------------------Players currently logged on: "+x);
  if(x<10) write("-");
  write("------------------------*\n");
  write("*-----------------------------------------------------------------------------*\n");
return 1;}

snop(str) {
  object who;
  who=find_living(str);
  if(!who){ write("No players with that name.\m"); return 1; }
  write("Ok :\n");
  call_other(this_player(),"snoop",who);
  return 1;
}

move(str)
{ if(!str) {write("Where do u want to go?\n"); return 1;}
  move_object(this_player(),"/players/"+str);
  write("Ok, moved to /players/"+str+".\n");
return 1;}

bb() {
shout("\n     ________________                           ______________\n");
shout("    \/                \\                         \/ \/            \\---_\n");
shout("   \/ \/          \\ \\   \\                       |     -    -         \\\n");
shout("   |                  |                       | \/         -   \\  _  |\n");
shout("  \/                  \/                        \\    \/  \/   \/\/    __   \\\n");
shout(" |      ___\\ \\| | \/ \/                          \\\/ \/\/ \/\/ \/ \/\/\/  \/      \\\n");
shout(" |      \/          \\                           |             \/\/\\ __   |\n");
shout(" |      |           \\                          \\              \/\/\/     \\\n");
shout("\/       |      _    |                           \\               \/\/  \\ |\n");
shout("|       |       \\   |    Hurtbrain               \\   \/--          \/\/  |\n");
shout("|       |       _\\ \/|     sucks!!!!               \/ (o-            \/ \\|\n");
shout("|      __\\     <_o)\\o-        \/                  \/            __   \/\\ |\n");
shout("|     |             \\        \/     Yeah,        \/              .)  \/  |\n");
shout(" \    ||             \\      \/      Heh Heh Heh \/   __          &\/ \/ \\ |\n");
shout("  |   |__          _  \\    \/       Heh Heh. \\ (____ *)         -  |   |\n");
shout("  |   |           (*___)  \/                  \\    \/               |  |\n");
shout("  |   |       _     |    \/                    \\  (____            |  |\n");
shout("  |   |    \/\/_______\/                             ####\\           |  |\n");
shout("  |  \/       | UUUUU__   \\                    \/   ____\/ )         |_\/\n");
shout("   \\|        \\_nnnnnn_\\~\\ \\                  \/   (___             \/\n");
shout("    |       ____________\/  \\                \/     \\____          |\n");
shout("    |      \/             Ya, ya,       Trix           \\          |\n");
shout("    |_____\/               YA!         is  Cool!        \\__________\\\n");
return 1;
}

spaventa(str) {
   object us;
   int x;
   if(!str) return;
   us=find_living(str);
 tell_object(us,"Hydra arrives.\n");
 tell_object(us,"Hydra smashes you with a bone crashing sound.\n");
 tell_object(us,"You missed.\n");
 tell_object(us,"Hydra hits you very hard.\n");
 tell_object(us,"\n");
 tell_object(us,"You feel very weak as your badly damaged body ");
 tell_object(us,"falls to the ground to die.\n\n");
 tell_object(us,"You die.\n");
 tell_object(us,"You have a strange feeling.\n");
 tell_object(us,"You can see your own dead body from above.\n");
 tell_object(us,"\n");
 tell_object(us,"setting hit points to 1/3 max....\n\n\n");
return 1;}

