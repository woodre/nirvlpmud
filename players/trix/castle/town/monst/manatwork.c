inherit "obj/monster";
reset(arg){
   object gold,shovel,boots;
   ::reset(arg);
   if(arg) return;
   set_name("man");
   set_race("human");
   set_alias("man");
   set_short("A man at work");
   set_long(
"A man at work.  He's sweaty and tired.  Life in Trixtown isn't always\nfine.\n");
   set_level(20);
   set_hp(500);
   set_al(300);
   set_wc(30);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("The man wipes the sweat from his forehead.\n");
   load_chat("Man says: You know there is something strange under Trixtown!!!\n");
   load_chat("Man says: I would never go down in the Sewer!\n");
   load_chat("The man wipes the sweat from his forehead.\n");
   set_a_chat_chance(15);
   load_a_chat("The man at work says: Hey!  Get away!  I can't waste my time!\n");
   load_a_chat("The man at work hits you with his shovel.\n");
   gold=clone_object("obj/money");
   gold->set_money(3450+random(51));
   move_object(gold,this_object());
   shovel=clone_object("/players/trix/castle/town/monst/shovel");
   move_object(shovel,this_object());
   boots=clone_object("/players/trix/castle/town/monst/boots");
   move_object(boots,this_object());
}
catch_tell(str)
{
    string a;
    string b;
    if(str) {
    if (sscanf(str, "%squest%s", a, b)) call_out("quest",1);
    else if(sscanf(str, "%ssewer%s", a, b)) call_out("quest",1);
    else if(sscanf(str, "%sring%s", a, b)) call_out("quest",1);
   }
}
quest()
{
  say(
"\nMan says: Oh, I can't tell you anything about the quest!  And I can't\n"+
"          even give you my shovel!\n");
  return 1;
}
