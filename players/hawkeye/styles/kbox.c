#define ME capitalize(this_player()->query_name())
#define IT capitalize(what->query_name())
inherit "players/hawkeye/closed/monk/styles/weapon.c";
object what;
int dmge;
reset(arg) {
    ::reset();
    if (arg) return;
 set_name("Monk's Staff");
 set_alias("staff");
 set_short("A Monk's Staff");
 set_long("This is a 6 foot long piece of Iron Wood.  The Staff is\n"+
       "a ornate walking stick, and in the right hands it is also\n"+
       "a deadly weapon.\n");
 set_class(12);
 set_save_flag(0);
 set_weight(1);
 set_value(100);
    set_hit_func(this_object());
 call_out("adjusts", 1);
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
xx = random(100);
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
write("You bash "+IT+" in the face.\n");
say(ME+" bashes "+IT+" in the face!\n");  }
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
   what->hit_player(random(dmge));
attacks++;
            }
}

init() {
 ::init();
add_action("choke","choke");
add_action("meditate","meditate");
add_action("view_commands","cmds");
}


view_commands() {
write(
"Akido commands: \n"+
" meditate      -- recover some of your energy faster.\n"+
"\n");
return 1;
}

meditate() {
 int pie;
pie = call_other(this_player(),"query_attrib","pie");
if(this_player()->query_attack()){
 write("You cannot meditate while you are fighting.\n");
 return 1;  }
write("You take deep breaths and empty your mind of thoughts.\n"+
  "You let your body flow and harmonize with nature.\n"+
  "The weariness and pain leave your body and you feel refreshed.\n");
this_player()->add_spell_point(-15);
this_player()->add_hit_point(random(pie)+5);
this_player()->add_intoxination(-10);
this_player()->add_stuffed(-25);
return 1;
}

adjusts(){
 object me, ob;
 string name;
me = environment(this_object());
ob = this_object();
if(!present("mrobe", me)) return 1;
if(me->query_guild_rank() > 0) ob->set_class(12);
if(me->query_guild_rank() > 2) ob->set_class(13);
if(me->query_guild_rank() > 3) ob->set_class(14);
if(me->query_guild_rank() > 5) ob->set_class(15);
if(me->query_guild_rank() > 7) ob->set_class(16);
if(me->query_guild_rank() > 10) ob->set_class(17);
name = me->query_real_name();
ob->set_short(capitalize(name)+"'s Monk Staff");
return 1;
}
