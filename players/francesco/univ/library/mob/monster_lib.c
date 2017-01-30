inherit "obj/monster";
int level1;
int level;
string subject;
string argomento;
set_argomento(subject){argomento=subject;}
int aaa;
int coins;

set_level1(level){

if(level >= 20)
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
   set_hp(90);
   set_al(0);
   set_wc(10);
   set_ac(5);
   coins=150;
} 

if(level >= 5 && level <=8)
{
   set_level(7);
   set_hp(105);
   set_al(0);
   set_wc(9);
   set_ac(9);
   coins=300;
}

if(level >= 9 && level <=12)
{
   set_level(11);
   set_hp(165);
   set_al(0);
   set_wc(13);
   set_ac(12);
   coins=500;
}
if(level >= 13 && level <=16)
{
   set_level(15);
   set_hp(225);
   set_al(0);
   set_wc(17);
   set_ac(17);
   coins=875;
}

if(level == 17 || level ==18)
{
   set_level(18);
   set_hp(450);
   set_al(0);
   set_wc(22);
   set_ac(22);
   coins=950;
}
if(level == 19)
{
  aaa=random(3);

if(aaa==0)
 { 
  set_level(18);
   set_hp(450);
   set_al(0);
   set_wc(22);
   set_ac(23);
   coins=1000;
 }

if(aaa==1)
 { 
  set_level(19);
   set_hp(47);
   set_al(0);
   set_wc(22);
   set_ac(27);
   coins=1000;
 }

if(aaa==2)
 { 
  set_level(20);
   set_hp(500);
   set_al(0);
   set_wc(24);
   set_ac(30);
   coins=5000;
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
            "is almost useless.\n");

  set_dead_ob(this_object());
}

monster_died() {
   object ob;
/*  write_file("/players/francesco/closed/library", ctime(time())+" "+
    attacker_ob->query_real_name()+", level "+attacker_ob->query_level()", killed the termite.\n");
*/  

write("After killing this annoying bookworm, you can now grab the\n"+
      "book you were looking for from the shelf.\n");
  ob=(clone_object("/players/francesco/univ/library/mob/grabber.c"));
  move_object(ob,environment(attacker_ob));
  present("grabber",environment())->set_coinage(coins); 
  present("grabber",environment())->set_subject(argomento);
  return 0; }
 
