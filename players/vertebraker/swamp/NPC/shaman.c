/* chg'd 3-12-01: potion giving rewritten */

#include "../define.h"
#define MLOG "/players/vertebraker/log/Monster"
#define POTION "/players/vertebraker/swamp/OBJ/potion"

inherit NPC;

int y;
string remembered;
object potion;

void reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("denis");
   set_alias("shaman");
   set_short("A shaman");
   set_long(
      "  Coloured beads wrap themselves around the neck of this\n"+
      "tall, dark man.  His dreadlocked hair pushes over top of\n"+
      "a simple green bandanna.  He is shirtless, and wears a \n"+
      "pair of denim shorts for clothes, and a low-cut pair of\n"+
      "sneakers.  A thin white scar rests atop of his left eyelid.\n"+
      "You could \"ask\" him any magical questions, or perhaps\n"+
      "\"list\" what he has available.\n");
   set_level(20);
   MO(CO(OBJ_DIR+"denim_shorts"),TO);
   command("wear shorts",TO);
   GUIDE->calc_stats(20);
   set_hp((int)GUIDE_HP);
   set_wc((int)GUIDE_WC + 12);
   set_ac((int)GUIDE_AC - 4);
   set_a_chat_chance(7);
   set_chat_chance(7);
   load_chat("Denis says, \"Eh mon.. Ask me a question, I tell you da ansuh...\n"+
      "              'buh ah' onlee know 'boud dah Mageek mon...\"\n");
   load_chat("Denis says, \"I needa acid slime from da changeleeng....\n" + 
      "              uh'll pay ya hansomely..\"\n");
   load_chat("Denis asks, \"Who are yuh that be comin' in to da house of Denis?\"\n");
   load_chat("Denis asks, \"Have yuh spoken with da ol' Juribel?\"\n");
   load_chat("Denis says, \"I sell charms mon!\"\n");
   load_a_chat("Denis' eyes roll back in his head.\n"+
      "He points at you.\n"+
      "WHOA!  A bolt of lightning strikes the floor next to you.\n");
   load_a_chat("denis lays his hands upon himself.\n"+
      "Denis smiles.\n");
   load_a_chat("Denis throws a vial of "+HIG+"green goo"+NORM+" at you!\n"+
      "He barely missed the mark!\n");
   set_message_hit(({
            HIW+"blasted"+NORM," with a shamanic spell",
            "got a second wind.\nDenis massacred"," to small fragments",
            "cast fireball upon","",
            "punched"," in the face",
            "cast a shock spell upon","",
            "cast a magic missile upon","",
            "nicked","", }));
    set_dead_ob(this_object());
}

init() {
   ::init();
   add_action("list","list");
   add_action("ask","ask"); 
   add_action("purchase","purchase");
   add_action("purchase","buy"); 
   if(remembered)
      if(this_player() && (string)this_player()->query_real_name() == remembered)
      {
        tell_object(this_player(), "Denis hands you a potion.\n\"Danks again, mon.\"\n");
        tell_room(environment(), "Denis hands " + capitalize(remembered) + " a potion.\n", ({ this_player() }));
        if(!potion) potion = clone_object(POTION);
        move_object(potion, this_player());
        remembered = 0;
        potion = 0;
      }
}

ask(str) {
   string ms,ms2;
   if(!str) return 0;
   if(sscanf(str,"%schangeling%s",ms,ms2) ||
sscanf(str,"%schangeleeng%s",ms,ms2)) {
      call_out("changeling",4);
      return 1; }
   if(sscanf(str,"%sslime%s",ms,ms2) || sscanf(str,"%sacid%s",ms,ms2)) {
      call_out("slime",4);
      return 1; }
   if(sscanf(str,"%sbottle%s",ms,ms2)) {
      call_out("bottle",4);
      return 1; }
   if(sscanf(str,"%sgelatin%s",ms,ms2)) {
      call_out("gelatin",4);
      return 1; }
   call_out("nothing",4);
   return 1; }

nothing() {
   tell_room(USER,
      "Denis says, \"I know nuttin' boud dat mon.\"\n");
   return 1; }

bottle() {
   tell_room(USER,
      "Denis says, \"Da bottle is in-chan-ded mon.  Eet kun hold da acid\n"+
      "              slime from da changeleeng, but you mus' bee cayful.\"\n");
   tell_room(USER,
      " \" Eet costs 1,500 gold pieces mon.\"\n");
   return 1; }

scale() {
   tell_room(USER,
      "Denis says, \"Da alixa's scale is a vury pow'ful totem in-deeed.  Eet\n"+
      "              con be yewsed do rayze or lowuh ones awlunmunt.\"\n");
   tell_room(USER,
      " \" Eet costs 2,500 gold pieces mon.\"\n");
   return 1; }

gelatin() {
   tell_room(USER,
      "Denis says, \"Da jel-uh-teen be helps fuh one to naveegayte da swamp\n"+
      "              mon.  Yuh jus rub it on ya boots.\"\n");
   tell_room(USER,
      "  \" Eet costs 5,000 gold pieces mon.\"\n");
   return 1; }

changeling() {
   tell_room(USER,
      "Denis says, \"Da changeleeng is a pow-ful Mageek caster.  Eet is very\n"+
      "              dayn-ger-ous and can change eets form at weeel.  We\n"+
      "              theenk it still leeves in da swamp.\"\n");
   tell_room(USER,
      "Denis continues, \"Da changeleeng spits out a powerful acid when it\n"+
      "                   dies.  I needs da acid to complete a pow'ful po-shun.\"\n");
   return 1; }

list() {
   write(
      "Denis tells you,\n"+
      "\"I sell "+BOLD+"bottles"+NORM+" and "+BOLD+"gelatins"+NORM+"\"\n");
   return 1; }

purchase(str) {
   int cost;
   if(str == "bottle" || str == "gelatin" || str == "scale") {
      if(str == "bottle") cost = 1500;
      if(str == "gelatin") cost = 5000;
      if(TP->query_money() < cost) {
         write("Denis says, \"You don't have enuff mohney mon.\"\n");
         return 1; }
      if(!TP->add_weight(1)) {
         write("You cannot carry that!\n");
         return 1; }
      write("You purchase a "+BOLD+str+NORM+" from Denis.\n");
      say(TPN+" purchases a "+str+" from Denis.\n");
      tell_room(USER,
         "Denis says, \"Thank you mon.\"\n");
      TP->add_money(-cost);
      MO(CO(OBJ_DIR+"d_"+str),TP);
      return 1; }
   write("Denis says, \"I don't sell dat mon.\n"+
      "              Type 'list' for what I do.\"\n"); 
   return 1; }


catch_tell(string str) {
   string msg;

   if(sscanf(str,"%s gives",msg)) {
      potion = present("full_v_bottle",TO);
      if(potion && !y) {
         write(
            "Denis says, \"Dank you fo' da acid mon!  Come bawk in 'boud five\n"+
            "              minnids.  Uh'll have somethin fo' you den.\"\n");
         tell_room(USER,
            "Denis takes the acid and dumps a few mushrooms in it.\n"+
            "Denis smiles and begins working on his potion.\n");
         destruct(potion);
         potion = 0;
         y = 1;
         call_out("setup_potion", 150, this_player());
      }
   }
   return 1; }


setup_potion(object ob)
{
   if(!ob || !environment()) return;
   potion = clone_object(POTION);
   remembered = (string)ob->query_real_name();
   y = 0;
}

monster_died() {
    tell_room(environment(), "\tDenis collapses against the ground with a hard *thunk*.\n");
/*
    if(attacker_ob) write_file(MLOG, HIB + "[" + NORM + ctime()[4..15] + HIB
+ "] " + NORM + (string)capitalize(attacker_ob->query_real_name()) + " [" +
(int)attacker_ob->query_level() + "+" +
(int)attacker_ob->query_extra_level() + "] - Denis.\n");
*/
    return 0;
}
