/* Version 1.0 of the Druid score */

druid_score() {

string title, animal, touch_rank, element;
object ob;

ob = present("druid_ob",this_player());

if(ob->query_glvl() < 6) {title = "Initiate of Nature"; }
if((ob->query_glvl() > 5) && (ob->query_glvl() < 10)) {title = "Aspirant of Nature"; }
if((ob->query_glvl() > 9) && (ob->query_glvl() < 15)) {title = "Elemental Student"; }
if((ob->query_glvl() > 14) && (ob->query_glvl() < 20)) {title = "Worshiper of the Moon"; }
if((ob->query_glvl() > 19) && (ob->query_glvl() < 30)) {title = "Protector of the Grove"; }
if((ob->query_glvl() > 29) && (ob->query_glvl() < 40)) {title = "Elemental Master"; }
if(ob->query_glvl() > 39) {title = "ArchDruid"; }

if(ob->query_animal() == 0) {animal = "Fox"; }
if(ob->query_animal() == 1) {animal = "Hawk"; }
if(ob->query_animal() == 2) {animal = "Raven"; }
if(ob->query_animal() == 3) {animal = "Viper"; }
if(ob->query_animal() == 4) {animal = "Panther"; }
if(ob->query_animal() == 5) {animal = "Wolf"; }
if(ob->query_animal() == 6) {animal = "Black Bear"; }
if(ob->query_animal() == 7) {animal = "Dire Wolf"; }
if(ob->query_animal() == 8) {animal = "Elephant"; }
if(ob->query_animal() == 9) {animal = "Dire Bear"; }

element = (GRN+"None"+NORM);
if((ob->query_fire() > ob->query_earth()) && (ob->query_fire() > ob->query_air()) && (ob->query_fire() > ob->query_water())) {
element = (HIR+"Fire"+NORM);  }
if((ob->query_air() > ob->query_earth()) && (ob->query_air() > ob->query_fire()) && (ob->query_air() > ob->query_water())) {
element = (HIW+"Air"+NORM);  }
if((ob->query_earth() > ob->query_air()) && (ob->query_earth() > ob->query_fire()) && (ob->query_earth() > ob->query_water())) {
element = (YEL+"Earth"+NORM);  }
if((ob->query_water() > ob->query_air()) && (ob->query_water() > ob->query_fire()) && (ob->query_water() > ob->query_earth())) {
element = (HIC+"Water"+NORM);  }

if(ob->query_touch() == 0) {touch_rank = (HIR+"Empty"+NORM); }
if((ob->query_touch() > 0) && (ob->query_touch() < 50)) {touch_rank = (RED+"Low"+NORM); }
if((ob->query_touch() > 49) && (ob->query_touch() < 100)) {touch_rank = (YEL+"Weak"+NORM); }
if((ob->query_touch() > 99) && (ob->query_touch() < 250)) {touch_rank = (WHT+"Normal"+NORM); }
if((ob->query_touch() > 249) && (ob->query_touch() < 1000)) {touch_rank = (GRN+"Stong"+NORM); }
if(ob->query_touch() > 999) {touch_rank = (HIG+"Unbreakable"+NORM); }
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   "+HIG+capitalize(tp->query_real_name())+" the "+title+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   ");
if(tp->query_level() > 18) {
write("Level: "+tp->query_level()+" + "+tp->query_extra_level());
} else {
write("Level: "+tp->query_level());
}
write("     ");
  write("Experience: "+tp->query_exp()+"\n");
write("   ");
write("Hit Points: "+HIG+tp->query_hp()+NORM+WHT+"/"+
    HIG+tp->query_mhp()+NORM+"   ");
write("Spell Points: "+HIG+tp->query_sp()+NORM+WHT+"/"+
    HIG+tp->query_msp()+NORM+"\n");
write("   ");
write(HIR+"Stuff"+NORM+": "+HIW+tp->query_stuffed()*100/(tp->query_level()*8)+NORM+"%     ");
write(HIR+"Soak"+NORM+":  "+HIW+tp->query_soaked()*100/(tp->query_level()*8)+NORM+"%     ");
write(HIR+"Intox"+NORM+": "+HIW+tp->query_intoxination()*100/(tp->query_level()+3)+NORM+"%\n");
write("\n");
write("   ");
 write("Str: "+tp->query_attrib("str")+"   ");
 write("Sta: "+tp->query_attrib("sta")+"   ");
 write("Mag: "+tp->query_attrib("mag")+"   ");
 write("Ste: "+tp->query_attrib("ste")+"   ");
write("\n");
write("   ");
 write("Luc: "+tp->query_attrib("luc")+"   ");
  write("Int: "+tp->query_attrib("int")+"   ");
 write("Wil: "+tp->query_attrib("wil")+"   ");
 write("Pie: "+tp->query_attrib("pie")+"   ");
write("\n\n");
write("   ");
write("Gold Coins: "+tp->query_money()+"\n");
write("   ");
tp->show_age();
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   ");
write(HIG+"Druid Guild Level: "+NORM+ob->query_glvl()+"\n");
write("   Animal Companion: "+ob->query_animal_name()+" the "+animal+"\n");
write("\n   ");
write("Available Druid Skill Points: "+HIG+ob->query_skillpts()+NORM+"\n   ");
write("Animal Empathy: "+ob->query_empskill()+"   ");
write("Elemental Lore: "+ob->query_eleskill()+"   ");
write("Healing: "+ob->query_healskill()+"\n");
write("   Herbalism: "+ob->query_herbskill()+"   ");
write("     Plant Lore: "+ob->query_plantskill()+"\n");
write("\n   ");
write(HIG+"Touch of Nature:"+NORM+" "+touch_rank+"\n");
write("   ");
write(HIG+"Element Favored: "+NORM+element);
write("\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; 
}

