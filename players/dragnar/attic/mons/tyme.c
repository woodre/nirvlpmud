inherit "obj/monster";

string text;	/*  For catch_tell string */
object receiver;	/* Player receving the text */
reset(arg){
	object gold, weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Tyme");
   set_race("human");
   set_alias("tyme");
   set_short("Tyme, the grand master of the mortals");
	set_long("As you take a step closer to Tyme, you look into his eyes\n" +
	"and notice the emptyness that fills his soul.  He looks as if he\n" +
	"is in superior shape, and well schooled in assassination. His\n" +
	"presence makes you tremble with fear.  As he continues to stare you down\n" +
	"you decide it wouldn't be a wise choice to attack him.\n");
   set_level(20);
   set_hp(1000);
	set_al(1000);
   set_wc(40);
   set_ac(17);
   set_chance(40);
   set_spell_dam(100);
	set_spell_mess1("Tyme casts a sonic blast.\n");
	set_spell_mess2("Tyme smashes you with a sonic blast.\n");
   set_chat_chance(4);
	set_a_chat_chance(2);
	load_chat("Tyme says: Beware, the evil in this place is powerful.\n");
	load_chat("Tyme says: Adventure on if you believe you are powerful enough.\n");
  load_chat("Tyme says: If you've lost your MK scar, just ask for my help.\n");
   load_chat("Tyme says: If you want to save this world, ask me about the quest.\n");
	load_a_chat("Tyme screams: I am the only good in this place and you dare to attack me?\n");
   gold=clone_object("obj/money");
   gold->set_money(random(3000)+500);
   move_object(gold,this_object());
	weapon=clone_object("players/dragnar/weapons/death.c");
	move_object(weapon, this_object ());
}
void long(string id)
{
    ::long(id);
    if (!text) {
	receiver = this_player();
   text = " If you want to save this land, ask me about the quest.\n";
	call_out("DoTalk", 3);
    }
}
void catch_tell(string str)
{
    string      who, what;

    if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
	sscanf(str, "%s asks: %s\n", who, what) == 2 ||
	sscanf(str, "%s tells you: %s\n", who, what) == 2) {

	what = lower_case(what);
	if (sscanf(what, "%squest", who))
     text = read_file("/players/dragnar/mons/tyme/quest");
   else if(sscanf(what, "%sscar", who)) {
     receiver = this_player();
     call_out("ResetScar", 2);
   }
   else return;
   receiver = this_player();
   call_out("DoTalk", 3 );
   }
}

void DoTalk() {

 if (!text || !receiver) { text = 0; return;}
   tell_object(receiver, "\nTyme whispers to you:");
    tell_object(receiver, text);
    text = receiver = 0;
}
ResetScar() {

  if( !receiver ) {
    return 1;
  }
   tell_object(receiver, "Tyme says: Sorry, I can't do that right now.\n");
  return 1;
  command("reset_scar_obj", receiver);
  return 1;
}
