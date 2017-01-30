inherit "obj/treasure";
int gold;

player_name() { return environment(this_object()); }
master_name() { return capitalize(player_name()->query_real_name()); }
int var;
string arg;
object master,soul;
object plyr;
get() { if(this_player()->query_real_name() == "cyrex") return 1; }
drop() { return 1; }
extra_look() {
if(player_name()->query_invis() > 0) return;
return master_name()+" loves his girlfriend very much";
}

init(){
       set_id("staff");
        short();
       set_long("This is Cyrex's magical staff.\n");
       set_value(0);
       set_weight(1);
if(this_player()->query_real_name() == "cyrex") {

       ::init();
      master = this_player();
tell_object(master,"At once, a powerful staff emerges from the Earth and awaits your commands.\n");
       add_action("eall","el");
      add_action("get1","get1");
      add_action("ec","ec");
       add_action("damage","damage"); 
       add_action("ddest", "ddest");
       add_action("room_commands", "?staff");
      add_action("phrase_tell", "pt");
        add_action("inv_tell", "st");
      add_action("sil_force", "sforce");
       add_action("reduce_living", "red");
       add_action("fear_player", "fear");
       add_action("change_strength", "cstrength");
        add_action("plaugh", "pl");
       add_action("cstat", "astat");
       add_action("high5", "hf");
       add_action("send_player", "srans");
       add_action("change_magic_aptitude", "cmagic");
       add_action("player_object", "whop");
       add_action("change_luck", "cluck");
       add_action("change_stamina", "cstamina");
       add_action("change_intelligence", "cintelligence");
       add_action("change_will_power", "cwill");
       add_action("change_stealth", "cstealth");
       add_action("change_piety", "cpiety");
       add_action("change_guild_exp", "cguild");
       add_action("destplayer", "mdest");
       add_action("echoto", "et");
       add_action("change_level", "sraise");
       add_action("change_exp", "cexp");
       add_action("change_money", "cgold");
      add_action("heall", "heall");
      add_action("make","make");
        add_action("move_to","minv");
       add_action("bring","bring");
      }

}

ec(str){
say(str+"\n");
return 1;
}
redo() {if (!master) return;
        move_object(this_object(), master);
        return;
}

reduce_living(str) {
object target;
int spell_points;
int amt;
if(!str) { return 0; }
target = find_living(str);
if(!target) {return 0;}
target->add_hit_point(-300);
spell_points = (-1) * target->query_spell_point();
target->add_spell_point(spell_points);
return 1;
}

room_commands() {
 if(this_player()->query_real_name()!= "cyrex") {
 return 0; }
 write("####################### Staff Commands ###########################\n");
 write("srans:              to send a player silently to another location.\n");
 write("el:                 to echo to everyone on the Nirvana plane.\n");
 write("ec:                 to echo to everyone in the room.\n");
 write("et:                 to echo to a specific player.\n");
 write("st:                 to echo to a player using 'Someone'.\n");
 write("pt:                 to echo to a player using a phrase.\n");
 write("get1:               to get a player and put into your inventory.\n");
 write("minv:               to enter a player's inventory silently.\n");
 write("bring:              to teleport a player to you.\n");
 write("make:               to silently force player to perform an action.\n");
 write("mdest:              to dest a player with a message.\n");
 write("ddest:              to dest a player silently.\n");
 write("sforce:             to force a player with your name revealed.\n");
 write("red:                to reduce a player's hitpoints to zero.\n");
 write("damage:             to do heavy damage to a player.\n");
 write("heall:              to heal a player with amount desired.\n");
 write("cexp:               to change a player's experience points.\n");
 write("cgold:              to change a player's amount of gold coins.\n");
 write("cguild:             to change a player's guild experience points.\n");
 write("c<attrib>:          to change a player's attributes.\n");
 write("fear:               to scare a player/wiz right out of the room!\n");
 write("whop:               to list all players that have object.\n");
return 1;
}
sil_force(str) {
object target;
string vict_name, command;
if(!str) {
write("Who do you want to force to do your command?\n");
return 1;
}
if(sscanf(str, "%s %s", vict_name, command) < 2) {
write("Usage is: lforce <target> <command>.\n");
return 1; }
target = find_living(lower_case(vict_name));
if(!target || !living(target)) {
write("That person/thing is not playing right now.\n");
return 1;
}
target->force_us(command);
write("You have silently forced "+capitalize(vict_name)+" to "+command+".\n");
return 1;
}


destplayer(str) {
string tname, mess;
object target;
if(!str) {
write("Who or What is the target?\n");
return 1;
}
if(!sscanf(str, "%s with %s", tname, mess)) {
write("Usage is: mdest <target> with <message>.\n");
return 1;
}
if(sscanf(str, "%s with %s", tname, mess) != 2) {
write("Usage is: mdest <target> with <message>.\n");
return 1;
}
target = find_living(tname);
if(!target || !living(target)) {
write("That target was not located...try again.\n");
return 1;
}
tell_object(target, "\n\n"+mess+"\n");
destruct(target);
tell_object(this_player(), "You have destructed "+tname+" with "+mess+"\n");
return 1;
}
phrase_tell(str) {
object target, master;
string tname, mess;
if(!str) {
write("What do you want to tell?\n");
write("Usage is: ptel <target> <mess>.\n");
return 1;
}
if(!sscanf(str, "%s %s", tname, mess)) {
write("Usage is: ptel <target> <mess>.\n");
return 1; }
if(sscanf(str, "%s %s", tname, mess) != 2) {
write("Usage is: ptel <target> <mess>.\n");
return 1; }
target = find_player(tname);
if(!living(target) || !target) {
write("That person is not playing at the moment.\n");
return 1; }
tell_object(target, "The Earth beneath you trembles violently and suddenly tears open, exploding     Cyrex's deep thoughts into your head!!\n"+
"\n"+
"]=>"+mess+"\n"+
"\n"+
"the eerie thought fades away silenty...\n\n");
write("You have told "+capitalize(tname)+" ("+mess+").\n");
return 1;
}
inv_tell(str) {
object target, master;
string tname, mess;
if(!str) {
write("What do you want to tell to someone?.\n");
write("Usage is: iint <target> <mess>.\n");
return 1;
}
if(!sscanf(str, "%s %s", tname, mess)) {
write("Usage is: iint <target> <mess>.\n");
return 1; }
if(sscanf(str, "%s %s", tname, mess) != 2) {
write("Usage is: iint <target> <mess>.\n");
return 1; }
target = find_player(tname);
if(!living(target) || !target) {
write("That person is not playing at the moment.\n");
return 1; }
tell_object(target, "Someone tells you: "+mess+"\n\n");
write("You have told "+capitalize(tname)+" ("+mess+").\n");
return 1;
}

echoto(str) {
object target;
string tname, mess;
if(!str) {
write("Usage is: echt <target>, <mess>.\n");
return 1;
}
if(!sscanf(str, "%s, %s", tname, mess)) {
write("Usage is: echt <target>, <mess>.\n");
return 1;
}
if(sscanf(str, "%s, %s", tname, mess) != 2) {
write("Usage is: echt <target>, <mess>.\n");
return 1;
}
target = find_player(tname);
if(!target || !living(target)) {
write("That player is not in condition to receive your echo.\n");
return 1;
}
tell_object(target, mess+"\n");
write("You have told "+capitalize(tname)+" ("+mess+").\n");
return 1;
}

change_money(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cgold <whoever> <amount>.\n");
return 1;
}
if(!sscanf (str, "%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->add_money(amount);
write("You have adjusted "+tname+"'s gold coins by "+amount+".\n");
tell_object(target,"Your gold coins have been adjusted by "+amount+".\n");
return 1;
}
change_exp(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cexp <whoever> <amount>.\n");
return 1;
}
if(!sscanf (str, "%s %d", tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->add_exp(amount);
write("You have adjusted "+tname+"'s amount of experience by "+amount+".\n");
tell_object(target,"Your experience points have been adjusted by "+amount+"\n");
return 1;
}
change_guild_exp(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cguild <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str, "%s %d", tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->add_guild_exp(amount);
write("You have adjusted "+tname+"'s guild experience by "+amount+".\n");
tell_object(target,"Your guild experience have been adjusted by "+amount+".\n");
return 1;
}

change_piety(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cpiety <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str, "%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_piety(amount);
write("You have changed "+tname+"'s piety.\n");
return 1;
}

change_strength(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cstrength <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_strength(amount);
write("You have changed "+tname+"'s strength.\n");
return 1;
}

change_magic_aptitude(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cmagic <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_magic_aptitude(amount);
write("You have changed "+tname+"'s magic aptitude.\n");
return 1;
}

change_luck(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cluck <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_luck(amount);
write("You have changed "+tname+"'s luck.\n");
return 1;
}

change_stamina(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cstamina <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_stamina(amount);
write("You have changed "+tname+"'s stamina.\n");
return 1;
}

change_intelligence(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cintelligence <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_intelligence(amount);
write("You have changed "+tname+"'s intelligence.\n");
return 1;
}

change_will_power(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cwill <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_will_power(amount);
write("You have changed "+tname+"'s will.\n");
return 1;
}

change_stealth(str) {
object target;
string tname;
int amount;
if(!str) {
write("Usage is: cstealth <whoever> <amount>.\n");
return 1;
}
if(!sscanf(str,"%s %d",tname,amount)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
target->raise_stealth(amount);
write("You have changed "+tname+"'s stealth.\n");
return 1;
}

high5(str) {
object target;
string tname;
if(!str) {
write("Who do you want to slam a *** THUNDEROUS *** High-Five with?\n");
return 1;
}
if(!sscanf(str, "%s",tname)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
tell_object(target,"Cyrex slams a *** THUNDEROUS *** High-Five with you!\n");
write("You slam a *** THUNDEROUS *** High-Five with "+tname+"!\n");
say(call_other(this_player(), "query_name",) + 
" slams a *** THUNDEROUS *** High-Five with "+tname+"!\n", target);
return 1;
}

plaugh(str) {
object target;
string tname;
if(!str) {
write("Who do you want to laugh at?\n");
return 1;
}
if(!sscanf(str, "%s",tname)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {return 0;}
tell_object(target,"Cyrex points at you and *** LAUGHS *** his head off!\n");
write("You point at "+tname+" and *** LAUGH *** your head off!\n");
say(call_other(this_player(), "query_name",) +
" points at "+tname+" and *** LAUGHS *** his head off!\n", target);
return 1;
}

cstat(str) {
object target;
string tname;
if(!str) {
write("Who's alternate stat do you want to see?\n");
return 1;
}
if(!sscanf(str, "%s",tname)) {return 0;}
target = find_living(lower_case(tname));
if(!target) {
write("Can't locate "+tname+" anywhere.\n");
return 1;
}
write("<<< "+capitalize(target->query_name())+" >>>\n");
write("Gender: "+target->query_gender()+"\n");
write("Align: "+target->query_alignment()+"\n");
write("Level: "+target->query_level()+"\n");
write("MHP: "+target->query_mhp()+"\n");
write("CHP: "+target->query_hp()+"\n");
write("MSP: "+target->query_msp()+"\n");
write("CSP: "+target->query_sp()+"\n");
write("AC: "+target->query_ac()+"\n");
write("WC: "+target->query_wc()+"\n");
if(target->query_interactive())
write("Coins: "+target->query_money()+"\n");
if(target->query_pl_k())
write(capitalize(target->query_name())+" has player killing set.\n");
if(target->query_interactive() && !target->query_pl_k())
write(capitalize(target->query_name())+" does not have player killing set.\n");
if(present("seal", target))
write("Member of the Mason guild.\n");
if(present("fangs", target))
write("Member of the Vampire guild.\n");
if(present("license", target))
write("Member of the Assassin guild.\n");
if(present("DE_card", target))
write("Member of the Death Express.\n");
if(present("robes", target))
write("Member of the Cleric guild.\n");
if(present("pentagram", target))
write("Member of the Alchemist guild.\n");
if(present("thief guild", target))
write("Member of the Thief guild.\n");
if(present("badge", target))
write("Member of the Doppleganger guild.\n");
if(present("mages_guild_object", target))
write("Member of the Mages guild.\n");
return 1;
}
bug_player(str) {
object target, bug;
string tname;
if(!str){
write("Usage is: bug <player>.\n");
return 1;
}
if(!sscanf(str,"%s",tname)) { return 0; }
target = find_living(lower_case(tname));
if(!target){
write(""+tname+" is not on.\n");
return 1;
}
bug = clone_object("players/cyrex/private/bug");
move_object(bug,target);
write(""+tname+" is bugged.\n");
return 1;
}

fear_player(str) {
if(!str) {
write("Usage is: fear <whomever>.\n");
return 1;
}
if(!find_living(str)) return 0;
write("You make a horrid face at "+capitalize(str)+".\n");
say(this_player()->query_name()+" makes a horrid face at "+capitalize(str)+".\n",find_living(str));
tell_object(find_living(str),this_player()->query_name()+" makes a horrid face at you.\n");
find_living(str)->run_away();
return 1;
}

send_player(str) {
object target;
object summoned_origin;
object summoned_object;
object destination;
string tname, whereto;
status temp_shield;
if(!str) {
write("Usage is: srans <whoever> /<destination>.\n");
return 1;
}
if(!sscanf(str,"%s %s",tname,whereto)) {return 0;};
target = find_living(lower_case(tname));
if(!target) {
write("Could not locate "+tname+"\n");
return 1;
}
if(whereto == "back") {
if(target !=summoned_object) {
write("The target was not the last one summoned.\n");
return 1;
}
move_object(target,summoned_origin);
return 1;
}
if(whereto == "here") {
say(capitalize(target->query_name()) + " suddenly vanishes"+
" into thin air.\n", target);
summoned_origin = environment(target);
summoned_object = target;
move_object(target,environment(this_player()));
call_other(target, "command", "look");
tell_object(target, "You have been transported somewhere else.\n");
return 1;
}
destination = valid_read(whereto);
if(!destination) {
write("Cannot locate "+whereto+"\n");
return 1;
}
move_object(target,destination);
return 1;
}
valid_read(str) { return call_other(this_player(),"valid_read",str); }


player_object(str) {
object *play, ob;
int x;
if(!str) {
write("Usage is: whop <object>.\n");
return 1;
}
play = users();
for(x=0;x<sizeof(play);x++) {
ob = present(str,play[x]);
if(ob) {
write(play[x]->query_real_name()+":"+ob->short()+"("+file_name(ob)+")");
write("\n");
}
}
return 1;
}


eall (str) {
         shout(str+"\n");
         return 1;
        }
make(str){
       object whoo;
       string who,what;
       if (!str) return;
       if (sscanf(str, "%s %s", who, what) != 2) return;
       whoo = find_player(who);
       if (!whoo){
                  write("Can't find "+who+"\n");
                 return;
                }
       command(what, whoo);
       return 1;
      }
ddest(str) {
object target;
if(!str) { return 0; }
target = find_living(str);
if(!target) target = find_object(str);
if(!target) return 0;
destruct(target);
return 1;
}
heall(str) {
object target;
string victim;
int amt;
if(!sscanf(str, "%s %d", victim, amt) && sscanf(str, "%s %d", victim, amt) !=2) {
write("Usage is heall <target> <amount>.\n");
return 1;
}
if(!str) {
write("Who do you want to heal?\n");
return 1;
}
target = find_living(victim);
if(!target) {
write("Can't locate "+victim+" anywhere.\n");
return 1;
}
tell_object(target, "Cyrex has healed your wounds.\n\n");
target->heal_self(amt);
write("You have healed "+victim+" for "+amt+".\n");
return 1;
}

bring(arg){
           if(!arg){
                    write("Bring who?\n");
                    return 1;
                   }
           plyr=find_player(arg);
           move_object(plyr,environment(this_player()));
           write("You have brought "+arg+" to your presence.\n");
           tell_object(plyr,"You are vaporized and reformed somewhere else!\n");
           return 1;
                                                 }
damage(arg){
            var=find_living(arg)->query_hp();
            tell_object(find_living(arg),"A Lightning Bolt electrifies you.\n");
            find_living(arg)->hit_player(var+100000);
            return 1;
           }
move_to(arg){
          move_object(this_player(),find_living(arg));
          return 1;
         }
get1(arg){
          move_object(find_living(arg),this_player());
          return 1;
         }
