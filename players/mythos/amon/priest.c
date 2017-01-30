#include "/players/mythos/closed/ansi.h"
int mn;
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("priest");
  set_race("priest");
  set_gender("male");
  set_alias("priest");
  set_short("Priest");
  set_long("The Priest is a quiet man.  He lives to uphold the purpose of\n"+
      "his order- to help and purify life.  He will grant you life\n"+
      "if you need.  Just 'pray' and he will come to your aid.\n"+
      "If you need your wounds healed, just ask him to 'heal' you.\n"+
      "For diseases- ask him to 'cure' you and all will be well.\n"+
      "And anything you need to get rid of- curses or Yokai..have\n"+
      "him 'erase' them for you.\n");
  set_hp(1000);
  set_level(25);
  set_al(1000);
  set_wc(40);
  set_ac(17);
  set_heal(5,18);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The Priest chants softly....\n");
  load_a_chat("The Priest steps back and chants loudly!\n");
  load_a_chat("You feel as if something is slowing you down...\n");
  load_a_chat("The priest glares at you and FEAR fills you!\n");
  set_chance(40);
  set_spell_dam(random(70));
  set_spell_mess1("The Priest laughs and gestures...\n\n\t"+
  "The Ground rumbles.....\n\t\tEarth herself is against you!\n\n");
  set_spell_mess2("The Priest laughs and gestures...\n\n\t"+
  "The Ground Rumbles....\n\t\tEarth herself is against you!\n\n");
  call_out("spec",1);
}

spec() {
  if(this_object()->query_attack()) {
    int a;
    object ob, ob2, ob3;
    a=random(100);
    if(a>50 && a<80) {
      say("The Priest gestures quickly and you feel great FEAR!\n"+
         "\n\n\n"+BOLD+"\t\t>>>>>>  <<>>  <<<<<<\n\n"+NORM+
        "\n"+
        "\nThe room darkens and something hits you, causing great pain!\n"+
        "\n");
    ob=all_inventory(environment(this_object()));
    for(mn=0; mn<sizeof(ob); mn++){
      if(ob[mn] != this_object()) {
        call_other(ob[mn],"add_hit_point",-25);
        if(ob[mn]->query_spell_point() > -150) {
        call_other(ob[mn],"add_spell_point",-25);}
        } }
  call_out("spec",3);
      return 1;}
    if(a>79 && a<91) {
      say("The Priest calls down the heavens!\n\n"+
        RED+"\tF    I    R    E\n\n"+"\t\tF    I    R    E\n\n"+
        "\t\t\tF    I    R    E\n\n"+NORM+
        "You see flames and all is pain and death!\n");
      ob=all_inventory(environment(this_object()));
      for(mn=0; mn<sizeof(ob); mn++) {
      if(ob[mn] != this_object()) {
          call_other(ob[mn],"add_hit_point",-75);
          if(call_other(ob[mn],"query_attrib","pie") >1) {
          call_other(ob[mn],"raise_piety",-1);}
        } }
  call_out("spec",3);
        return 1;}
    if(a<100 && a>90) {
    string title;
      say("The Priest mumbles.....\n"+
HIB+"\n\tRin\n\n\tByo\n\n\tTo\n\n\tSha\n\n\tKai\n\n\tChin\n\n\tRetsu\n\n\tZai\n\n\tZen\n\n"+
    NORM+"He gestures and shouts: "+HIR+"HA!"+NORM+"\n\n");
        ob=all_inventory(environment(this_object()));
        for(mn=0; mn<sizeof(ob); mn++) {
          if(ob[mn] != this_object()) {
          int mm;
        ob2=all_inventory(ob[mn]);
        for(mm=0; mm<sizeof(ob2); mm++) {
          if(ob2[mm]->armor_class() > 0) {
            ob2[mm]->set_ac(0);
            ob2[mm]->set_value(0);
            title=ob2[mm]->query_name();
            ob2[mm]->set_short(capitalize(title)+" <broken>");
            tell_object(ob[mn],"Your armor is shattered by the Priest's command!\n");
          }
          if(ob2[mm]->query_broke() != 1){
          if(ob2[mm]->weapon_class() > 0) {
            ob2[mm]->weapon_breaks(); 
        tell_object(ob[mn],"Your weapon shatters from the Priest's command!\n");
          } }
      }
      } }
  call_out("spec",5);
    return 1;}
  call_out("spec",2);
  return 1;}
call_out("spec",1);
return 1;}

monster_died() {
  move_object(clone_object("/players/mythos/awep/pie.c"),this_object());
/*
   write_file("/players/mythos/prac/ob",ctime(time())+"\t"+
      (this_object()->query_attack())->query_real_name()+"\t\t"+
      (this_object()->query_attack())->query_level()+"\tpriest\n");
*/
return 0; }

