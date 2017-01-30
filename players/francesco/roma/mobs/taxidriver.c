#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "obj/monster";
   object gold;
object ob;
reset(arg){
   object tunic;
   ::reset(arg);
   if (arg) return;
   set_name("driver");
   set_race("human");
   set_alias("taxi driver");
   set_short("The taxi driver");
   set_long("The taxi driver is a poor dressed man, in his mid age.  He has a \n"+
            "well built body,  even though somehow fat.  Most likely, due to\n"+
            "his job, he cant workout enough.  Yet, through his t-shirt, you can\n"+
            "see strong muscles.\n");
   set_dead_ob(this_object());
   set_level(20);
   set_hp(600);
   set_al(-100);
   set_wc(38);
   set_ac(17);
   set_heal(4,4);
   set_ac_bonus(2);   /* cuz the room is turned NT after the fight starts */
   set_wc_bonus(6);   /* because of the damage inflicted by the carcrash  */
   set_chance(20);
   set_spell_mess1("The taxidriver screams:  I am already used to get attacked!!!\n"+
                   "I know how to defend myself!!!  You will pay for it!!!");
   set_spell_dam(60);
 gold = clone_object("obj/money");
 gold->set_money(40+random(700));
 move_object(gold,this_object());
/* tunic = clone_object("/players/francesco/roma/items/tunic.c");
 move_object(tunic,this_object());
*/
}

monster_died() {
   int flag;
   if(!flag){ flag++; call_out("monster_died",2);}
   ob=(clone_object("/players/francesco/roma/mobs/carcrash.c"));
   move_object(ob,environment(attacker_ob));
   present("carcrash",environment())->attaccante(attacker_ob);
   say("The taxi loses control and crashes against a side wall.\n"+
       "You hit severely on the dashboard and almost lose consciousness.\n");
   write_file("/players/francesco/roma/log/kill_taxidriver",
             ctime(time())+"  "+tpn+
             "    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");    
return 0; }
 