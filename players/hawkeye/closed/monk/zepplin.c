#define ME capitalize(this_player()->query_name())
#define IT capitalize(what->query_name())
inherit "players/hawkeye/closed/monk/weapon.c";
object what;
int dmge;
reset(arg) {
    ::reset();
    if (arg) return;
set_name("A Long Iron Staff Named 'Zepplin'");
 set_alias("staff");
set_short("A Long Iron Staff Named 'Zepplin'");
set_long("This iron staff is surrounded by a blue aura of electricity.\n" +
"You feel a slight evilness as you hold it, but you know it has powers you\n" +
"shall never harness.\n");
 set_class(22);
 set_save_flag(1);
 set_weight(1);
 set_value(5000);
    set_hit_func(this_object());
 call_out("adjusts", 1);
}
id(str){
   return str == "staff" || str == "monk staff" || str == "monk_obj" 
   || str == "weapon" || str == "zepplin";
}

weapon_hit(attacker){
 int pie, str, x, xx;
what = attacker;
str = call_other(this_player(), "query_attrib", "str");
pie = call_other(this_player(), "query_attrib", "pie");
if(!present("mrobe", this_player())){
 write("This is a Monk's Staff!  This weapon is only for Monks.\n"+
       "The Staff disintegrates in your unworthy hands.\n");
 this_player()->hit_player(10);
 destruct(this_object());
 return;  }
dmge = this_player()->query_guild_rank();
if(dmge > 15) dmge = 15;
xx = random(50);
if( (pie + str) > xx)
  do_attack();
return 4;
}

do_attack(){
 int x, y, attacks;
attacks = 0;
x = random(2)+1;
while(attacks < x){
 y = random(5)+1;
if(y == 1){
write("Blue Sparks fly out of Zepplin and shock "+IT+"\n");
say(ME+"'s staff Zepplin fires Blue Sparks at "+IT+"\n"); }
if(y == 2){
write("You slam your staff down on "+IT+"'s foot!\n");
say(ME+" slams his staff down on "+IT+"'s foot!\n");  }
if(y == 3){
write("You reverse your swing and smack "+IT+" in the stomach!\n");
say(ME+" reverses his swing and smacks "+IT+" in the stomach!\n");  }
if(y == 4){
write("You use your staff to knock your enemy to the ground!\n");
say(ME+" knocks "+IT+" to the ground!\n");  }
if(y == 5){
write("You bring your staff up and slam "+IT+" in the crotch!\n"+
      IT+" crumples to the ground in pain!\n");
say(ME+" brings his staff up and slams "+IT+" in the crotch!\n"+
     IT+" crumples to the ground in pain!\n");  }
if(y == 6){
write("You cripple your enemy with a smashing blow to the knee!\n");
say(ME+" cripples his enemy with a smashing blow to the knee!\n");  }
 if(what->query_hp() > dmge)
what->hit_player(dmge-2);
return dmge;
attacks++;
            }
}

adjusts(){
 object me, ob;
 string name;
me = environment(this_object());
ob = this_object();
if(!present("glass", me)){
 tell_object(me, "This weapon is for Monks Only!\n"+
 "The staff disintegrates in your unworthy hands.\n");
 me->hit_player(random(10));
 destruct(this_object());
 return 1;   }
name = me->query_real_name();
return 1;
}
