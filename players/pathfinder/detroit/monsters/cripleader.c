inherit "obj/monster";
 
object obj1;
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("jameel");
   set_race("human");
   set_alias("gang");
   set_alias("leader");
   set_ep(1300000);
   set_short("Jameel, leader of the Crips");
   set_long("\n"+
"  You set your eyes upon Jameel, the main nigga of the Crips gang.  He\n"+
"knows everything that goes on in and his turf, which you are now standing\n"+
"on.  He doesn't look to happy with your intrusion into his business.\n"+
"You get the sinking feeling that something is definitely wrong here.\n");
   set_level(20);
   set_hp(350+ random(400));
   set_al(-500);
   set_wc(25+random(15));
   set_ac(19+random(9));
   set_chance(10);
   set_spell_dam(15+random(10));
   set_spell_mess1("Jameel puts a bullet right through your heart.\n");
   set_chat_chance(2);
   load_chat("Jameel tells you: Whatcha doin' here punk beeatch?\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000)+700);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/shotgun"), this_object());
   call_out("more_gang",5);
}
 
more_gang() {
  if((this_player()->query_attack()) && (random(10) < 4)) {
    obj1 = clone_object("players/pathfinder/detroit/monsters/newcrip");
    move_object(obj1, environment(this_object()));
    say("You see more Crips entering from all over as you assault their leader.\n");
   }
/* excessive cloning. removed. -Bp
   call_out("more_gang",5);
*/
}
