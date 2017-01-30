inherit "obj/monster";
int level1;
/*
int level;  - Redeclaration of variable from obj/monster - Rumplemintz
*/
string subject;
string argomento;
set_argomento(subject){argomento=subject;}
int aaa;
int coins;

set_level1(level){

   set_chat_chance(8);
   load_chat("The bookworm mumbles:  They think they are intelligent, but they are empty.\n");
   load_chat("The bookworm hides behind a shelf.\n");
   load_chat("The bookworm puts about 10 books into his backpack.\n");
   load_chat("The bookworm says:  Hey, you student! You won't get your degree,  Haw Haw Haw\n");

if(level > 20)
{
   set_level(20);
   set_hp(800);
   set_al(0);
   set_wc(30);
   set_ac(24);
   coins=950;
}
if(level <=4)
{
   set_level(4);     
   set_hp(115);      /**** was 90 ****/
   set_al(0);        
   set_wc(12);       /**** was 10 ****/
   set_ac(8);        /**** was  5 ****/
   coins=150;
} 

if(level >= 5 && level <=8)
{
   set_level(7);
   set_hp(130);       /**** was 105 ****/
   set_al(0);
   set_wc(15);       /**** was 13 ****/
   set_ac(8);       /**** was 5 ****/
   coins=300;
}

if(level >= 9 && level <=12)
{
   set_level(11);
   set_hp(200);       /**** was 165 ****/
   set_al(0);
   set_wc(20);       /**** was 17 ****/
   set_ac(11);       /**** was 8 ****/
   coins=500;
}
if(level >= 13 && level <=16)
{
   set_level(15);
   set_hp(260);       /**** was 225 ****/
   set_al(0);
   set_wc(26);       /**** was 22 ****/
   set_ac(13);       /**** was 11 ****/
   coins=1000;
}

if(level == 17 || level ==18)
{
   set_level(18);
   set_hp(500);       /**** was 450 ****/
   set_al(0);
   set_wc(32);       /**** was 29 ****/
   set_ac(18);       /**** was 14 ****/
   coins=3500;
   set_chance(16);       /**** was 10 ****/
   set_spell_mess1("The bookworm laughs hard: Dodged!");
   set_spell_dam(15);       /**** was 10 ****/

}
if(level == 19)
{
  aaa=random(3);

if(aaa==0)
 { 
  set_level(18);
   set_hp(650);       /**** was 550 ****/
   set_al(0);
   set_wc(33);       /**** was 4 ****/
   set_ac(15);       /**** was 29 ****/
   coins=3400+random(200);
   set_chance(20);       /**** was 15 ****/
   set_spell_mess1("The bookworm laughs hard: Missed!");
   set_spell_dam(20);       /**** was 15 ****/
 }

if(aaa==1)
 { 
  set_level(19);
   set_hp(700);       /**** was 600 ****/
   set_al(0);
   set_wc(34);       /**** was 31 ****/
   set_ac(15);
   coins=3900+random(300);
   set_chance(25);       /**** was 20 ****/
   set_spell_mess1("The bookworm laughs hard: Untouched!");
   set_spell_dam(25);       /**** was 20 ****/
 }

if(aaa==2)
 { 
  set_level(20);
   set_hp(850);       /**** was 750 ****/
   set_al(0);
   set_wc(35);       /**** was 31 ****/
   set_ac(19);
   coins=4800+random(400);
   set_chance(35);       /**** was 25 ****/
   set_spell_mess1("The bookworm laughs hard: Avoided!");
   set_spell_dam(35);       /**** was 25 ****/
 }
}
}
reset(arg){
   ::reset(arg);
   set_name("bookworm");
   set_alias("bookworm");
   set_short("A bookworm");
   set_long("He appears to be in his early twenties.  He has a very pale\n"+
            "complexion from spending many hours reading books.  He is\n"+
            "wearing brown pants that don't even come close to his shoes.\n"+
            "His thick glasses have a severe wad of tape holding them\n"+
            "together.  A nice yellow pocket protector that holds his\n"+
            "large assortment of pens sits in his shirt pocket.  Definately,\n"+
            "he must have obtained a great deal of knowledge, most of which\n"+
            "is almost useless, though.\n");

  set_dead_ob(this_object());
}

monster_died() {
   object ob;
  write_file("/players/francesco/log/bookworm", ctime(time())+" "+
    attacker_ob->query_real_name()+"  "+argomento+"\n");
  write("After killing this annoying bookworm, you can now 'grab' the\n"+
      "'book' you were looking for 'from shelf'.\n");
  ob=(clone_object("/players/francesco/quest/mobs/grabber.c"));
  move_object(ob,environment(attacker_ob));
  present("grabber",environment())->set_coinage(coins); 
  present("grabber",environment())->set_subject(argomento);
  return 0; }
 
