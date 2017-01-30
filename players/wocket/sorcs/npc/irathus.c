#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

string *spell_name;
string *spell_path;
int *spell_xp;
int *spell_difficulty;


add_spell(string sname,string path,int xp,int diff) {
  spell_name+=sname;
  spell_path+=path;
  spell_xp+=xp;
  spell_difficulty+=diff;
}
list_spells() {
  int i;
  int xexp;
  string color;
  int level;
  int elevel;

  level=this_player()->query_level();
  if(level > 19) level=19;

  elevel=this_player()->query_extra_level();
  if(elevel > 21) elevel=21;

  for(i=0; i < sizeof(spell_name); i++) {

    if(elevel < 1)
      xexp = this_player()->query_exp() - "room/adv_guild"->get_next_exp(level-1);
    else
      xexp = this_player()->query_exp() - "room/exlv_guild"->get_next_exp(elevel-1);

    if(xexp < spell_xp[i])
      color=HIR;
    else
      color=HIG;
    write("\t\t"+color+capitalize(spell_name[i])+NORM+"\n");
  }
}
reset(){
  set_short(HIM+"iRathus the Necromancer"+NORM);
  set_name("irathus");
  set_long(
"Irathus sits in the center of the pentagram, his legs folded\n\
beneath him and his hands resting on his knees, palms facing\n\
up.  His eyes are coal black, with no white showing at all.\n\
His beard is long, neatly trimmed, and silver in shade.  He\n\
wears a long black vest over his purple robes.  You may 'ask'\n\
him for information about the Art of the Dead.\n");

  set_level(30);
  set_hp(500);
  set_wc(50);
  set_ac(30);
  spell_name=({ });
  spell_path=({ });
  spell_xp=({ });
  spell_difficulty=({ });
  add_spell("lifedrain","lifedrain",40000,30);
  add_spell("spiritwalk","spiritwalk",200000,40);
  add_spell("resurrect","resurrect",300000,40);
}

init(){
  if(present("mageguildob",this_player())){
    add_action("ask_mage","ask");
    add_action("study_spell","study");
    add_action("make_soulcatcher","make");
  }
}

ask_mage(){
  write("iRathus says, \"I can help you "+BOLD+"study"+NORM+" the art of necromancy.\n"+
        "               I can also help you "+BOLD+"make"+NORM+" a "+BOLD+"soulcatcher"+NORM+".\n"+
        "               What would you like help with?\"\n\n");
  write("\tSpells:\n");
  list_spells();
  say("iRathus speaks privately with "+this_player()->query_name()+".\n");
  return 1;
}

study_spell(str){
  int index;
  int xexp;

  if(!str){
    notify_fail("iRathus says, \"What would you like help studing?\"\n");
    return 0;
  }
  if(index=member_array(str,spell_name)==-1) {
    notify_fail("iRathus says, \"I'm sorry, but I can not help you with that.\"\n");
    return 0;
  }

  if(this_player()->query_level() < 21) { /* This is so it doesn't break on wizzes. */
    if(this_player()->query_extra_level() < 1)
      xexp = this_player()->query_exp() - "room/adv_guild"->get_next_exp(this_player()->query_level()-1);
    else
      xexp = this_player()->query_exp() - "room/exlv_guild"->get_next_exp(this_player()->query_extra_level()-1);
  }
  else
    xexp=spell_xp[index];

  if(xexp < spell_xp[index]){
    write("iRathus says, \"You don't have enought knowledge.  To train you would be \n"+
          "a waste of my time.\"\n");
    return 1;
  }
  write("iRathus shows and explain the spell to you then leaves you to study\n"+
        "in peace.  You begin to concentrate, seeping your knowledge into\n"+
        "the pen you scribe with.  ");
  say(this_player()->query_name()+" studies quietly.\n");
  this_player()->add_exp(-spell_xp[index]);
  if(random(100) < spell_difficulty[index] ) {
    write(HIR+"The ink glows red as the spell takes form.\n"+NORM);
    move_object(clone_object("/players/wocket/mages/spells/"+spell_path[index]+".c"),this_player());
    return 1;
  }
  else
    get_fail();
  return 1;
}

get_fail(){
  string msg;
  switch(random(7)){
    case 0:  msg = "The page ignites, destroying all of your work.\n"; break;
    case 1:  msg = "Your page tears, letting the magic seep out.\n"; break;
    case 2:  msg = "You faint, destroying your concentration.\n"; break;
    case 3:  msg = "You sneeze, destroying your concentration.\n"; break;
    case 4:  msg = "The ink fades leaving your page blank.\n"; break;
    case 5:  msg = "Jibberish fills your minDA LAsL iDL Tles.\n"; break;
    case 6:  msg = "iRathus tears up your paper and shakes his head at you.\n"; break;
    case 7:  msg = "The page fades from this reality leaving you\nbewildered.\n"; break;
  }
  write(msg);
}

make_soulcatcher(str) {
  object catcher;
  object gem;

  notify_fail("Make what?\n");
  if(!str || str!="soulcatcher") return 0;
  gem=present("bloodstone",this_player());
  if(!gem) {
    write("iRathus says: You must bring me a bloodgem before you can\n"+
          "              begin the ritual.\n");
    say(this_player()->query_name()+" and iRathus confer.\n");
    return 1;
  }
  if(this_player()->query_money() < 1000) {
    write("iRathus says: I do not manufacture all of the materials necessary\n"+
          "              to construct a soulcatcher myself.  You must pay me\n"+
          "              1000 coins before we can begin.\n");
    say(this_player()->query_name()+" and iRathus confer.\n");
    return 1;
  }
  write("You hand the bloodstone and 1000 coins to iRathus.\n");
  destruct(gem);
  this_player()->add_money(-1000);
  call_out("script1",3,this_player());
  return 1;
}
void script1(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,"iRathus says: Very good.  Let the ritual begin.\n");
  call_out("script2",3,me);
}
void script2(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"iRathus takes a jar of iron filings off of a shelf and gently\n"+
"taps them into a pattern in the middle of the pentagram.\n");
  call_out("script3",3,me);
}
void script3(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"iRathus places the bloodstone in the center of the pattern.\n");
  call_out("script4",3,me);
}
void script4(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"iRathus utters a few guttural words and the lines of the\n"+
"pentagram ignite with magical flame.\n");
  call_out("script5",3,me);
}
void script5(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"The flames slowly die.\n");
  call_out("script6",3,me);
}
void script6(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"The metal has cooled, leaving a glowing iron symbol with a red gem\n"+
"in the center.\n");
  call_out("script7",3,me);
}
void script7(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"iRathus gestures at you to pick it up.\n");
  call_out("script8",3,me);
}
void script8(object me) {
  if(!present(me,environment(this_object()))) return;
  tell_object(me,
"Wincing against the pain, you reach into the smoldering flames\n"+
"and take the soulcatcher.  You hold it in the palm of your hand\n"+
"while iRathus affixes a chain to it.  iRathus mutters a few last\n"+
"incantations to bind the magic, and then nods that the ritual is\n"+
"completed.\n");
  move_object(clone_object("/players/feldegast/mages/obj/soulcatcher"),me);
  me->add_weight(1);
}
