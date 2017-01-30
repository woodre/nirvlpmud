#define SPOUSE find_living(spouse)
#define POSS query_possessive()
#define ME this_player()
#define cap(str) capitalize(str)
#define RN cap(ME->query_real_name())
#define owner cap(environment(this_object())->query_name())
int bring_flag;
object spouse;
id(str){ return str == "wedding ring" || str == "ring"; return 1;}
short() { return "Elaborate gold band"; }
drop() { return 1;}
get() { return 1;}
set_spouse(str) { spouse = str; }
query_spouse() { return spouse; }
query_auto_load(){ return "/players/mouzar/closed/ring:"+spouse;}
init_arg(arg) {
  spouse = arg;
  if(SPOUSE) {
    write("RING:  "+cap(spouse)+" is logged on.\n");
    tell_object(SPOUSE,"RING:  "+RN+" has just logged on.\n");
  }
}
init() {
  add_action("ring_talk","ring");
  add_action("ring_send","rsend");
  add_action("ring_bring","bring");
  add_action("ring_quit","quit");
  add_action("replace","replace");
}
ring_quit() {
  if(SPOUSE) {
    write("RING:  You leave your spouse all alone.\n");
    tell_object(SPOUSE,"RING:  "+RN+" leaves you alone.\n");
  }
return;
}
ring_send(str) { 
  string stuff,plr;
  object stuff1,plr1;
  if(!str) return;
  stuff = str;
  if(!SPOUSE) {   
    write("RING:  Your spouse isn't here.\n");
    return 1;
  }
  if(ME->query_sp()<20) {
    write("RING:  You do not have the spell points to do that.\n");
    return 1;
  }
  if(!present(stuff)) {   
    write("RING:  "+stuff+" not present.\n");
    return 1;
  }
  if(present(stuff)->query_auto_load() || present(stuff)->query_drop()){
    write("RING:  You can't send that.");
    return 1;
  }
  if(!call_other(SPOUSE, "add_weight",
    call_other(present(stuff), "query_weight"))) {
      write("RING:  Your spouse can't carry that much.\n");
      return;
    }
  plr1=SPOUSE;
  stuff1=present(stuff);
  move_object(stuff1,plr1);
  tell_object(plr1,"RING:  Your spouse sends you "+stuff+".\n");
  write("RING:  You send your spouse a "+stuff+"\n" );
  ME->add_spell_point(-20);  
  return 1;
}
ring_talk(str) {
  int x;
  object us, emote;
  if(!SPOUSE) {
    write("RING:  Your spouse isn't here.\n");
    return 1;
  }
  if(!str) {
    tell_object(SPOUSE,"RING: Your spouse sends "+ME->POSS+" love.\n");
    write("RING:  You send your love.\n");
    return 1;
  }
  if(sscanf(str,":%s", emote) == 1) {
    tell_object(SPOUSE,"{} "+RN+" "+emote+"\n");
    write("{}"+RN+" "+emote+"\n");
    return 1;
  } 
  tell_object(SPOUSE,"{}"+RN+"{} "+str+"\n");
  write("{}"+RN+"{} "+str+"\n");
  return 1;
}
ring_bring(str) {
  if(!str) return;
  if(str != spouse) {
    write("RING:  That isn't your spouse.\n");
    return 1;
  }
  if(bring_flag>time()) {
    write("RING:  You need to save up a little more love.\n");
    return 1;
  }
  if(!SPOUSE) {
    write("RING:  Your spouse isn't here.\n");
    return 1;
  }
  if(environment(SPOUSE)->query_realm() == "NT") {
    write("RING:  Your ring fails to bring your spouse to you.\n");
    return 1;
  }
  if(ME->query_sp() < 40) {
    write("RING:  You don't have the spell points to do this.\n");
    return 1;
  }
  tell_object(SPOUSE,"RING:  You are brought to your spouse.\n");
  move_object(SPOUSE,environment(this_player()));
  write("Your ring glows with the power of love and it brings your spouse to you.\n");
  say(RN+"'s rings glows with the power of love and "+cap(SPOUSE->query_name())+" appears.\n");
  ME->add_spell_point(-40);
  bring_flag = time()+600;
  return 1;
}
long() {
  write("This is a beautiful gold band with two diamonds set in the center.\n"+
        "It is a symbol to and a reminder of the love between you and your\n"+
        "spouse.  This ring has some power stored within it.  It's commands are:\n\n"+
        "       ring <mes>         Sends a message to your love.  Ring :<mes>\n"+
        "                          will send an emote to your love.\n"+
        "       bring <spouse>     Will bring your spouse to you.         40 sp\n"+
       "       rsend <item>       Send an item to your spouse.           20 sp\n"+
        "       replace <spouse>   Replace your spouse's ring.\n"+ 
        "\n\nMail Mouzar if there are any problems.\n");
        return 1;
}
replace(str) {
  object ob;
  if(str != spouse){
    write("RING:  That is not your spouse!  Should be shamed of yourself!\n");
    return 1;
  }
  if(!SPOUSE) { write("RING:  Your spouse isn't here is not here.\n"); return 1; }
  if(present("wedding ring",SPOUSE)) {write("RING:  Your spouse already has one.\n"); return 1; }
  ob=clone_object("/players/mouzar/closed/ring");
  ob->set_spouse(spouse);
  move_object(ob,SPOUSE);
  tell_object(SPOUSE,"RING:  You have just received a new wedding ring from your spouse.\n");
  write("RING:  You have just replaced "+cap(spouse)+"'s wedding ring.\n");
  return 1;
}
