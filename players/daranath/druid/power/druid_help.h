/* Version 1.0 of the Druid Help system...  
   just a bunch of write commands showing powers, plus the ability to pull a small doc 
   file on each individual power (eventually)   */

druid_help(str) {
object ob;

ob = present("druid_ob",this_player());

if(!str) {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Guild Help"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("\n");
write(HIW+"   Druid help can be found on the following topics:"+NORM+"\n");
write("\n");
write("   basics, companion, components, inner, powers, powers2\n");
write("   powers3, powers4, quicklist, summoning, tending, touch\n");
write("   Usage:"+GRN+" druid <"+NORM+"help topic"+GRN+">\n"+NORM);
write("\n");
write("   Plus, help is available with "+GRN+"druid <"+NORM+"spellname"+GRN+">\n"+NORM);
write("\n");
write("   and finally: credits\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }
if(str == "components") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Components"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   Druids use spells components to help boost the power of certain\n");
write("   spells. \n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "quicklist") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Quicklist"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   druid, druids, dc, dce, dr_who, druid_update, leave_guild\n");
write("   dr_hush, dr_unhush, comps, tend, save_me\n");
write("   an_name, an_select\n");
write("\n");
write("   goodberry, cure_minor, dtouch, spark, mist, fang, rabbit\n");
write("   call, frost, arrow, entangle, shockwave, wolf_cry, dire_cry\n");
write("   barkskin, faerie, spike, cure_light, blade\n");
write("\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "tending") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Tending"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   Tending adds to a Druid's Touch of Nature score and components\n");
write("   can be gathered and harvested from the Grove a Druid tends to.\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "components") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Components"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "basics") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Basics"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write("   "+HIG+"dc"+NORM+": Chat on the guild line.\n");
write("   "+HIG+"dce"+NORM+": Emote on the guild line.\n");
write("   "+HIG+"dr_who"+NORM+": Druid world who listing.\n");
write("   "+HIG+"druids"+NORM+": Druid guild who listing.\n");
write("   "+HIG+"dr_hush"+NORM+": Muffles the guild chat line.\n");
write("   "+HIG+"dr_unhush"+NORM+": Unmuffles the guild chat line.\n");
write("   "+HIG+"comps"+NORM+": Lists the components that you have.\n");
write("   "+HIG+"an_select"+NORM+": Selects which animal companion you would like.\n");
write("   "+HIG+"an_name"+NORM+": Name you animal companion.\n");
write("\n");
write("   "+HIG+"leave_guild"+NORM+": Leave the Druid guild.\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "grove") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Groves"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "credits") {
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"                   Druid Guild Credits"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"   Guild Creator: "+HIW+"Daranath ColdsBlood"+NORM+"\n");
write("\n");
write(GRN+"   With help from:"+NORM+"\n");
write(WHT+"   Vertebraker, Forbin, Stark and Maledicta\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; 
}

if(str == "powers") {
write(GRN+"<< --- --- --- --- --- --- "+HIG+"Druid Powers"+NORM+GRN+" --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"   Power Name            Command      Type          Cost"+NORM);
write("\n");
write(GRN+"1"+NORM+": Cure Minor Wounds     cureminor    healing       7 sp\n");
write("   Death's Touch         dtouch       decorpse      none\n");
write("   Balance               balance      misc          10 sp\n");
write("   Goodberry             goodberry    misc          10 sp\n");
if(ob->query_glvl() > 1) {
write(GRN+"2"+NORM+": Spark                 spark        ele - "+HIW+"Air"+NORM+"     7 sp\n");
write("   Flame Arrow           arrow        ele - "+HIR+"Fire"+NORM+"    7 sp\n");
write("   Frost Strike          strike       ele - "+HIC+"Water"+NORM+"   7 sp\n");
write("   Shockwave             shockwave    ele - "+YEL+"Earth"+NORM+"   7 sp\n");
}
if(ob->query_glvl() > 2) {
write(GRN+"3"+NORM+": Obscuring Mist        mist         defensive     25 sp\n");
write("   Rabbit Feet           rabbit       defensive     25 sp\n");
}
if(ob->query_glvl() > 3) {
write(GRN+"4"+NORM+": Magic Fang            fang         summoning     40 sp\n");
write("   Call Nature's Ally    call         summoning     40 sp\n");
}
if(ob->query_glvl() > 4) {
write(GRN+"5"+NORM+": Entangle              entangle     unique        25+ sp\n");
write("   Purify Water          pure_water   misc          25 sp\n");
}
if(ob->query_glvl() > 5) {
write(GRN+"6"+NORM+": Wolf's Cry            wolf_cry     defensive     30 sp\n");
}
if(ob->query_glvl() > 6) {
write(GRN+"7"+NORM+": Barkskin              barkskin     defensive     40 sp\n");
}
if(ob->query_glvl() > 7) {
write(GRN+"8"+NORM+": Faerie Fire           faerie       offensive     35 sp\n");
}
if(ob->query_glvl() > 8) {
write(GRN+"9"+NORM+": Flame Blade           blade        ele - "+HIR+"Fire"+NORM+"    50 sp\n");
write("   Animal Messenger      messenger    misc          20 sp\n");
}
if(ob->query_glvl() > 9) {
write(GRN+"10"+NORM+":Cure Light Wounds     curelight    healing       17 sp\n");
write("   Spike Stone           spike        ele - "+YEL+"Earth"+NORM+"   35 sp\n");
}

if(ob->query_glvl() > 10) {
write("\n");
write("   Type: "+GRN+"<"+NORM+"druid powers2"+GRN+">"+NORM+" for more powers.\n");
}
if(ob->query_glvl() > 25) {
write("   Type: "+GRN+"<"+NORM+"druid powers3"+GRN+">"+NORM+" for more powers.\n");
}
if(ob->query_glvl() > 40) {
write("   Type: "+GRN+"<"+NORM+"druid circle"+GRN+">"+NORM+" for inner circle powers.\n");
}
write(GRN+"<< --- --- --- --- --- --- "+HIG+"Druid Powers"+NORM+GRN+" --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

if(str == "powers2") {
if(ob->query_glvl() < 11) {
write("   You have no powers for these levels yet.\n");   return 1; }
write(GRN+"<< --- --- --- --- --- --- "+HIG+"Druid Powers2"+NORM+GRN+" --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"   Power Name            Command      Type          Cost"+NORM);
write("\n");
write(GRN+"11"+NORM+":Cold Snap             csnap        ele - "+HIC+"Water"+NORM+"   40 sp\n");
if(ob->query_glvl() > 11) {
write(GRN+"12"+NORM+":Insect Swarm          iswarm       summoning     50 sp\n");
}
if(ob->query_glvl() > 12) {
write(GRN+"13"+NORM+":Summon Mephit         summon       summoning     65 sp\n");
write("   Purify Body           pure_body    misc          25 sp\n");
}
if(ob->query_glvl() > 13) {
write(GRN+"14"+NORM+":Nature's Silence      silence      defensive     40 sp\n");
write("   Touch of the Eel      eel_touch      ele - "+HIW+"Air"+NORM+"    35 sp\n");
}
if(ob->query_glvl() > 14) {
write(GRN+"15"+NORM+":Dire Wolf's Cry       dire_cry      defensive     40 sp\n");
}
write("\n");
write("   Type: "+GRN+"<"+NORM+"druid powers"+GRN+">"+NORM+" for more powers.\n");
if(ob->query_glvl() > 25) {
write("   Type: "+GRN+"<"+NORM+"druid powers3"+GRN+">"+NORM+" for more powers.\n");
}
if(ob->query_glvl() > 40) {
write("   Type: "+GRN+"<"+NORM+"druid circle"+GRN+">"+NORM+" for inner circle powers.\n");
}
write(GRN+"<< --- --- --- --- --- --- "+HIG+"Druid Powers2"+NORM+GRN+" --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

write(GRN+"<< "+HIG+"Druid Help"+NORM+GRN+" >> "+NORM+"That is not a valid topic.\n");
return 1; 
}
