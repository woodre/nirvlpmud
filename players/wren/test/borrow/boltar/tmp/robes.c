/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
*/
int oldsp, oldhp, hp;
int oldcharge;
int teleport_ok;
int block;           /* Block cleric channel */
int shieldsumm;      /* Tell if shield has been summoned */
   int alignment;
int worn;
int spell_ok;
int death;
object owner;
object helper;
object mark;
int notyet;
int charge;


id(str) {
   return str == "ND" || str == "robes" || str == "GI" ||
   str == "robe" || str == "clericguild";
}

reset(arg) {
   if (arg) return;
   death = 0;
   worn = 0;
   shieldsumm = 0;
   teleport_ok=1;
   notyet = 0;
   owner = this_player();
   if (this_player()->query_guild_exp() == 1234) call_out("destroy_me",0);
}

destroy_me() {
destruct(this_object());
}
get() { return 1; }

drop() {
   if (query_verb() == "drop")
      write("You don't want to drop your robes!\n");
   return 1;
}

init() {
   add_action("cure","cure");
   add_action("crush","crush");
   add_action("leave","retire");
   add_action("helpercom","command");
   add_action("refresh","refresh");
   add_action("wear","wear");
   add_action("remove","remove");
   add_action("resurrect","resurrect");
   add_action("decorpse","decorpse");
   add_action("shield","shield");
   add_action("teleport","guild");
   add_action("death","death");
   add_action("revive","revive");
   add_action("alignment","alignment");
   add_action("harm","harm");
   add_action("light","createlight");
   add_action("blast","blast");
   add_action("ice","ice");
   add_action("helper","summon");
   add_action("info","info");
   add_action("send","send");
   add_action("send","cc");
   add_action("guildwho","cleric");
   add_action("minor","minor");
   add_action("major","major");
   add_action("fear","fear");
   add_action("peek","peek");
   add_action("bless","bless");
   add_action("list","list");
   add_action("fixtitle","fixtitle");
   add_action("block","block");
   add_action("I","I");
   add_action("sende","sende");
    if(this_player()==environment() && !this_player()->query_guild_name())
      this_player()->set_guild_name("clerics");
cat("/players/boltar/templar/info/news");
}

wear(str) {
   if (!id(str)) return 0;
   if (worn) {
      write("You are already wearing your robes.\n");
      return 1;
   }
   worn = 1;
   write("You feel a surge of power as you don your robes.\n");
   say(this_player()->query_name()+" wears "+
      this_player()->query_possessive()+" Cleric's Robes.\n");
   write("Ok.\n");
   return 1;
}

remove(str) {
   if (!id(str)) return 0;
   if (!worn) {
      write("You are not wearing your robes.\n");
      return 1;
   }
   worn = 0;
   write("You feel weakened.\n");
   say(this_player()->query_name()+" removes "+
      this_player()->query_possessive()+" Cleric's Robes.\n");
   write("Ok.\n");
   return 1;
}

short() {
   if (!owner) return "Someone's Cleric's Robes";
   if (worn) return owner->query_name()+"'s Cleric's Robes (worn)";
   return owner->query_name()+"'s Cleric's Robes";
}

long() {
   write("These robes are a sign of your membership to the Cleric's guild.\n");
   write("For a list of commands, type info.\n");
   write("For a list of cleric titles, type list titles.\n");
   write("Your robes now has the capacity to store upwards of 800 spell points.\n");
   write("Exceed this limit and you run the risk of getting hurt.\n");
   write("Current charge: "+charge+"\n");
}

test_piety(i) {
   if (this_player()->query_attrib("pie") >= i) return 1;
   return 0;
}

resurrect(str) {
   object victim;
   if (!test_piety(18)) return 0;
   if (!str) {
      write("Resurrect whom?\n");
      return 1;
   }
   victim = present("ghost of "+str, environment(this_player()));
   if (!victim) {
      write("Your person is not here.\n");
      return 1;
   }
   if (!living(victim) || victim->query_npc()) {
      write("You find you cannot cast your spell on that.\n");
      return 1;
   }
   if(victim->query_dead() > 1) {
     write(str+" is not really dead.\n");
     return 1;
    }
   if (!victim->query_ghost()) {
      write("You cannot cast a resurrection spell on something that is alive.\n");
      return 1;
   }
   spell_cost(225);
   if (!spell_ok) {
      write("You lack the spell points to cast that spell.\n");
      return 1;
   }
   write("You shudder as the mystical words of the resurrection spell\n"+
      "pass your lips. You feel a rush through you as the spell takes effect.\n");
   say(this_player()->query_name() + " focuses a resurrection spell on "+ str+".\n"+
      "You feel powerful forces at play here.\n");
   call_other(victim, "remove_ghost", 0);
   write("Ok.\n");
   return 1;
}

shield() {
   if (!test_piety(9)) return 0;
   if (shieldsumm) {
      write("You have already summoned a shield.\n");
      return 1;
   }
   if(this_player()->query_money() < 320) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
   spell_cost(40);
   
   if (!spell_ok) {
      write("You lack the spell points to cast that spell.\n");
      return 1;
   }
   write("You summon the shield preferred by more clerics around the world...\n");
   say(this_player()->query_name()+ " tosses coins into their and creates a shield.\n");
/*
   say(this_player()->query_name()+ " creates a shield out of thin air.\n");
*/
   shieldsumm = 1;
   call_out("unshield",600);
   move_object(clone_object("/players/boltar/templar/shield"), this_player());
   command("wear shield", this_player());
   this_player()->add_money(-320);
   return 1;
}

unshield() {
   shieldsumm = 0;
}


teleport() {
   object env;
   spell_cost(60);
   if (!spell_ok) {
      write("You find yourself too weak for that spell.\n");
      return 1;
   }
   /* Patched by Maniac to prevent certain teleports */
   env = environment(this_player());
   if(env->realm()=="NT") {
      write("You cannot teleport from this locus...\n");
      return 1;
   }
   if(!teleport_ok) {
      write("You can't quite remember how to do that.\n");
      write("Maybe it'll come back to you later.\n");
      return 1;
   }
   write("You fly through the air and land in the cleric's guild.\n");
   this_player()->move_player("to the cleric's guild#/players/boltar/templar/adv_guild");
   teleport_ok=0;
   call_out("tele_ok",300);
   return 1;
}

tele_ok() { teleport_ok=1; }

alignment(str) {
   object victim;
   string tmpaln;
   int tmpal;
   spell_cost(3);
   if (!spell_ok) {
      write("You lack the spell points to cast that spell.\n");
      return 1;
   }
   tmpal = this_player()->query_alignment();
   if (!str) {
      write("Your alignment: "+ aln(tmpal) + "\n");
      return 1;
   }
   victim = present(str, environment(this_player()));
   if (!victim) {
      write("That is not here.\n");
      return 1;
   }
   if (!living(victim)) {
      write("You can't do that!\n");
      return 1;
   }
   tmpal = victim->query_alignment();
   write(capitalize(str) + "'s alignment: " + aln(tmpal) + "\n");
   return 1;
}

aln(arg) {
if (arg > 10 * 64) {
        return "white lord";
    }
    if (arg > 10 * 32) {
        return "paladin";
    }
    if (arg > 10 * 16) {
        return "crusader";
    }
    if (arg > 10 * 8) {
        return "good";
    }
    if (arg > 10 * 4) {
        return "honorable";
    }
    if (arg > - 10 * 4) {
        return "neutral";
    }
    if (arg > - 10 * 8) {
        return "malicious";
    }
    if (arg > - 10 * 16) {
        return "evil";
    }
    if (arg > - 10 * 32) {
        return "infamous";
    }
    if (arg > - 10 * 64) {
        return "black knight";
    }
    return "lord of evil";
}

death() {
   object corpse;
   if (death) {
      write("You are already feigning death.\n");
      return 1;
   }
   if(this_player()->query_attack()) {
      write("You can't concentrate while being attacked.\nYou fail.\n");
      return 1;
   }
   corpse = clone_object("players/boltar/templar/corpse");
   corpse->set_name(this_player()->query_name());
   move_object(corpse, environment(this_player()));
   move_object(this_player(), corpse);
   write("You die.\n");
   tell_room(environment(corpse), this_player()->query_name()+ " dies.\n");
   death = 1;
   return 1;
}

revive() {
   object corpse;
   if (!death) {
      write("You are not feigning death.\n");
      return 1;
   }
   corpse = environment(this_player());
   if (!corpse->id("corpse")) {
      death = 0;
      write("You are not feigning death.\n");
      return 1;
   }
   move_object(this_player(), environment(corpse));
   write("You revive.\n");
   say(this_player()->query_name()+" revives from death.\n");
   destruct(corpse);
   death = 0;
   return 1;
}

light() {
object light;
   if (!test_piety(9)) return 0;
   spell_cost(25);
   if (!spell_ok) {
      write("You lack the spell points for the light spell.\n");
      return 1;
   }
/*
   move_object(clone_object("players/boltar/templar/light"), this_player());
   call_out("dark",600);
*/
light = clone_object("obj/torch");
        call_other(light, "set_name", "light");
        call_other(light, "set_short", "A blazing ball of light");
        call_other(light, "set_fuel",600);
        call_other(light, "set_weight", 0);
        call_other(light, "set_value",0);
        call_other(light, "set_out_desc", "Your globe of light winks out.\n");
        move_object(light,this_player());
        command("light light",this_player());
   write("You clap your hands and a ball of light forms!\n");
   say(this_player()->query_name()+" summons light!\n");
   return 1;
}

dark() {
   write("Your globe of light winks out.\n");
   say("It grows darker.\n");
}

harm(str) {
   object victim;
   if (!test_piety(12)) return 0;
   if (!str) victim = this_player()->query_attack();
   else
      victim = present(str, environment(this_player()));
   if (!living(victim) || (!victim->query_npc() && victim->query_pl_k())) {
      write("You cannot attack that!\n");
      say(this_player()->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(14);
   if (!spell_ok) {
      write("You lack the spell points for that spell.\n");
      return 1;
   }
   this_player()->spell_object(victim, "harm spell", random(26), 0);
   write(this_player()->query_name()+" casts a harm spell at " + victim->short()+"\n");
   say(this_player()->query_name()+" casts a harm spell at " + victim->short()+"\n");
   return 1;
}

blast(str) {
   object victim;
   if (!test_piety(15)) return 0;
   if (!str) victim = this_player()->query_attack();
   else
      victim = present(str, environment(this_player()));
   if (!living(victim) || (!victim->query_npc() && victim->query_pl_k())) {
      write("You cannot attack that!");
      say(this_player()->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(24);
   if (!spell_ok) {
      write("You lack the spell points for that spell.\n");
      return 1;
   }
   this_player()->spell_object(victim, "BLAST spell", random(25)+10, 0);
   write(this_player()->query_name()+" BLASTS " + victim->short()+"\n");
   say(this_player()->query_name()+" BLASTS " + victim->short()+"\n");
   return 1;
}

ice(str) {
   object victim;
   if (!test_piety(17)) return 0;
   if (!str) victim = this_player()->query_attack();
   else
      victim = present(str, environment(this_player()));
   if (!living(victim) || (!victim->query_npc() && victim->query_pl_k())) {
      write("You cannot attack that!\n");
      say(this_player()->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(30);
   if (!spell_ok) {
      write("You lack the spell points for that spell.\n");
      return 1;
   }
   this_player()->spell_object(victim, "ice arrows", random(26)+15, 0);
   write(this_player()->query_name()+" fires ice arrows at " + victim->short()+"\n");
   say(this_player()->query_name()+" fires ice arrows at " + victim->short()+"\n");
   return 1;
}

helper(i) {
   if (i != "helper") return 0;
   if (!test_piety(9)) return 0;
   spell_cost(2);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      say(this_player()->query_name()+" tries to cast a spell, but fails.\n");
      return 1;
   }
   if (helper) {
      write("You already have a helper.\n");
      return 1;
   }
   write("You summon a helper.\n");
   write("Use 'info helper' for commands.\n");
   helper = clone_object("players/boltar/templar/helper");
   helper->set_owner(capitalize(this_player()->query_real_name()));
   move_object(helper, environment(this_player()));
   return 1;
}

send(str) {
   object list;
   object robe;
   int i;
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
robe = present("clericguild",list[i]);
if(robe && robe->query_block()) {
write(list[i]->query_name()+" is blocking the Cleric channel.\n");
}
}
return 1;
}
   for(i=0; i<sizeof(list); i++) {
      robe = present("clericguild",list[i]);
      if (robe && !robe->query_block()) {
         tell_object(list[i], this_player()->query_name()+" (cleric channel): "+
            str+"\n");
       }
   }
   for (i=0; i<sizeof(list); i++) {
      robe = present("clericguild",list[i]);
      if (robe && robe->query_block() && !list[i]->query_invis())
         write(list[i]->query_name() +" is blocking the cleric channel.\n");
   }
   return 1;
}

block() {
   block = !block;
   write("Cleric block: ");
   if (block) write("on\n");
   else write("off\n");
   return 1;
}

guildwho() {
call_other("/players/asmithrune/objects/magicitems/feelings","guildlist");
   return 1;
}

minor(str) {
   object victim;
   if (!test_piety(11)) return 0;
   if (!str) victim = this_player();
   if (!victim) victim = present(str, environment(this_player()));
   if (!victim && !living(victim)) {
      write("You cannot heal that!\n");
      return 1;
   }
   if(this_player()->query_money() < 400) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
   spell_cost(50);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a heal spell on "+victim->query_name()+"\n");
   say(this_player()->query_name() +" casts a heal spell on "+ victim->query_name() + "\n");
   victim->add_spell_point(-25);
   this_player()->add_money(-400);
   victim->add_hit_point(20);
   /* extra so that the player spends the spell points */
   return 1;
}

major(str) {
   object victim;
   if (!test_piety(14)) return 0;
   if (!str) victim = this_player();
   if (!victim) victim = present(str, environment(this_player()));
   if (!victim && !living(victim)) {
      write("You cannot heal that!\n");
      return 1;
   }
    if(this_player()->query_money() < 900) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
   spell_cost(100);
   if(!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a major heal spell on "+victim->query_name()+"\n");
   say(this_player()->query_name() +
      " casts a major heal spell on "+ victim->query_name() + "\n");
   victim->add_spell_point(-50);
   victim->add_hit_point(40);
   return 1;
}

spell_cost(i) {
   if (this_player()->query_alignment() < -5) {
      write("You find that the deities have forsaken you, your magical\n");
      write("power is crippled. You are without any special powers.\n");
      write("Prehaps if you changed your evil ways the deities will allow you to tap there source of magic agian.\n");
      spell_ok = 0;
      this_player()->add_spell_point(-this_player()->query_sp());
      return 1;
   }
   if (this_player()->query_sp() < i) spell_ok = 0;
   else {
   this_player()->add_spell_point(-i);
   spell_ok = 1;
   }
   return 1;
/*
   if (this_player()->query_sp()+charge < i)
      spell_ok = 0;
   else {
      if (charge <= i) {
         i -= charge;
         charge = 0;
         this_player()->add_spell_point(-i);
         spell_ok = 1;
         return 1;
      }
      if (charge > i) charge -= i;
      spell_ok = 1;
   }
*/
}

decorpse() {
  object blah;
   object corpse;
   string i;
   corpse = present("corpse", environment(this_player()));
   if (!corpse) {
      write("No corpse present.\n");
      return 1;
   }
   write("With a churning noise, "+corpse->short()+" is processed.\n");
   say(this_player()->query_name() + " processes "+ corpse->short()+"\n");
   if (sscanf(file_name(corpse),"obj/corpse%s",i)!=1) return 1;
   if (sscanf(corpse->short(),"%sjr",i) != 1)
      blah=clone_object("players/bern/magic/steak");
      blah->set_healval(corpse->heal_value());
       move_object(blah, environment(corpse));
   destruct(corpse);
   return 1;
}


fear(str) {
   object victim;
   if (!test_piety(14)) return 0;
   victim = present(str, environment(this_player()));
   if (!victim || !living(victim)) {
      write("You fail.\n");
      return 1;
   }
   spell_cost(30);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      say(this_player()->query_name()+" tries to cast a spell but fails.\n");
      return 1;
   }
   if(!victim->query_wimpy()) {
      write("Your victim withstands your fear.\n");
      return 1;
   }
   if (random(100) > 70) {
      write("You fail.\n");
      return 1;
   }
   write(capitalize(str)+" suddenly looks frightened.\n");
   victim->run_away();
   return 1;
}

peek(i) {
   object ob;
   int perc;
   if (!test_piety(10)) return 0;
   spell_cost(5);
   if (!spell_ok) {
      write("You lack the strength for that spell.\n");
      return 1;
   }
   if (!i) ob = this_player()->query_attack();
   else
      ob = present(i, environment(this_player()));
   if (!ob) return 0;
   if (!living(ob)) {
      write("You cannot 'peek' that.\n");
      return 1;
   }
   perc = ob->query_hp()*10 / ob->query_mhp();
   if (!i) i = ob->short();
   write("A sprite comes to you and whispers in your ear:\n"+
      capitalize(i) + " has " + perc + "/10 of its hitpoints left.\n");
   say(this_player()->query_name()+ " scrutinizes "+capitalize(i) +
      " carefully.\n");
   return 1;
}

bless(str) {
   object weapon;
   int old_class;
   int old_value;
   string a, b;
   if (!test_piety(16)) return 0;
   weapon = present(str, this_player());
   if (!weapon) {
      write("You don't have "+str+" with you.\n");
      return 1;
   }
  if (this_player()->query_money() < 777) {
     write("You don't have enough money to sacrifice.\n");
     return 1;
   }
   spell_cost(80);
   if (living(weapon)) {
      write("Your spell balks.\n");
      return 1;
   }
   this_player()->add_money(-777);
   old_class = weapon->weapon_class();
   old_value = weapon->query_value();
   if (!old_class) {
      write("Wild magicks destroy "+weapon->short()+".\n");
      say(weapon->short()+" goes up in a puff of smoke.\n");
      destruct(weapon);
      return 1;
   }
   if (present("blessing",weapon)) {
      write(weapon->short()+ " has already been blessed.\n");
      return 1;
   }
   if (sscanf(weapon->short(),"%swield%s",a,b) == 2)
      command("unwield "+weapon->query_name(), this_player());
   if (random(50)>10) {
      weapon->set_class(old_class + 1);
      move_object(clone_object("players/boltar/templar/blessing"), weapon);
      write("You cast your blessing on "+weapon->short()+".\n");
      say(this_player()->query_name()+" casts "+
         this_player()->query_possessive()+" blessing on "+
         weapon->short()+".\n");
      if (old_class > 18 && random(12)>8) {
         write("CRACK! Your weapon broke in two!\n");
         destruct(weapon);
       }
      return 1;
   }
   write("Wild magicks destroy "+weapon->short()+".\n");
   say(weapon->short()+" goes up in a puff of smoke.\n");
   destruct(weapon);
   return 1;
}

info(str) {
   if (!str) {
      cat("/players/boltar/templar/info/general");
      return 1;
   }
   if (file_size("players/boltar/templar/info/"+str)) {
      cat("/players/boltar/templar/info/"+str);
      return 1;
   }
   write("There is no information on that.\n");
   return 1;
}

fixtitle() {
   string title;
   title = "players/boltar/templar/adv_guild"->query_title(this_player());
   this_player()->set_title(title);
   write("Title fixed.\n");
   return 1;
}

list(i) {
   if (i!= "titles") return 0;
   cat("/players/boltar/templar/info/titles");
   return 1;
}

helpercom(i) {
   string a,b;
   object ob;
   if (!helper) { write("You don't have a helper.\n");
      return 1;
   }
   if (sscanf(i,"describe %s",b) == 1) {
      helper->describe(b);
      return 1;
   }
   if (sscanf(i,"emote %s",b) == 1) {
      write(helper->short()+" "+b+"\n");
      say(helper->short()+" "+b+"\n");
      return 1;
   }
   if (sscanf(i,"get %s",b) == 1) {
      if (b == "all") {
         helper->get_all();
         return 1;
       }
      if (sscanf(b,"all from %s",a) == 1) {
         helper->get_all(a);
         return 1;
       }
      ob = present(b, environment(helper));
      if (!ob) return 1;
      helper->pick_up(ob);
      return 1;
   }
   if (sscanf(i,"drop %s",b) == 1) {
      if (b == "all") {
         helper->drop_all();
         return 1;
       }
      if (b == "money" || b == "all money") {
         helper->drop_money();
         return 1;
       }
      ob = present(b, helper);
      if (!ob) return 1;
      helper->drop_thing(ob);
      return 1;
   }
   command(i, helper);
   return 1;
}

set_owner(i) { owner = i; }

refresh() {
   owner = this_player();
   write("Ok.\n");
   return 1;
}

mark(i) {
   object monster;
   if (mark) {
      write("You have already sigilized a monster with your mark.\n");
      return 1;
   }
   monster = present(i, environment(this_player()));
   if (!monster) {
      write("That is not here.\n");
      return 1;
   }
   if (!monster->query_npc() || !living(monster)) {
      write("You can't sigilize that!\n");
      return 1;
   }
   mark = clone_object("players/boltar/templar/mark");
   mark->set_owner(this_player());
   mark->set_target(monster);
   move_object(mark, environment(monster));
   write("You have set your mark upon "+monster->short()+"\n");
   say(this_player()->query_name()+" puts his mark on "+monster->short()+"\n");
   return 1;
}

query_block() { return block; }

query_guild_obj() { return 1; }

cure(str) {
   object victim;
   object poison, next;
   string a,b;
   if (!test_piety(16)) return 0;
   if (!str) victim = this_player();
   else victim = present(str, environment(this_player()));
   spell_cost(40);
   if (!spell_ok) {
      write("You find yourself too weak for this spell.\n");
      return 1;
   }
   poison = first_inventory(victim);
   while (poison) {
      next = next_inventory(poison);
      if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
            poison->id("poison")) {
         destruct(poison);
         }
      poison = next;
   }
   write("You cast a cure spell on "+victim->query_name()+".\n");
   tell_object(victim,
      "You feel a soothing light bathe over you,\n"+
      "removing all traces of poison from your person.\n");
   tell_room(environment(this_player()),this_player()->query_name()+
      " casts a purifying light upon ");
   if (victim == this_player())
      tell_room(environment(this_player()),
      this_player()->query_objective()+"self.\n");
   else tell_room(environment(this_player()),victim->query_name()+".\n");
   return 1;
}

rain() {
   object victim, next;
   if (!test_piety(14)) return 0;
   if (notyet) return 1;
   spell_cost(60);
   if (!spell_ok) {
      write("You find yourself too weak for this spell.\n");
      return 1;
   }
   victim = first_inventory(environment(this_player()));
   while (victim) {
      next = next_inventory(victim);
      if (victim->query_npc() && living(victim)) {
         victim->hit_player(35);
         victim->attacked_by(this_player());
         }
      victim = next;
   }
   write("Your prayers summon holy rain down upon your enemies!\n");
   say("Holy rain comes crashing down in a fury!\n");
   notyet = 1;
   call_out("resetyet",3);
   return 1;
}

resetyet() { notyet = 0; }

charge(o) {
   int i;
   if (sscanf(o,"%d",i) != 1) {
      write("Charge up how many spell points?\n");
      return 1;
   }
   if (i<0) i=0;
   if (this_player()->query_sp() < i) {
      write("You don't have that many spell points.\n");
      return 1;
   }
   charge += i/2;
   this_player()->add_spell_point(-i);
   write("You charge up "+i/2+" spell points.\n");
   write("Your total charge is: "+charge+"\n");
   if (random(charge-400)+400 > 800) {
      write("Your robes gleam from so much charge...\n");
      write("They explode, unable to contain such a charge!\n");
      write("You are hurt.\n");
      this_player()->add_hit_point(-50);
   }
   return 1;
}
heart_beat() {
   int newhp, newsp, maxhp, maxsp;
   maxhp = owner->query_mhp();
   maxsp = owner->query_msp();
   newhp = owner->query_hp();
   newsp = owner->query_sp();
   if (hp && (newhp != oldhp || newsp != oldsp || oldcharge != charge)) {
      tell_object(owner,"HP: "+newhp+" ("+maxhp+")   SP: "+newsp+" ("+maxsp+")"+
         "   CHARGE: "+charge+" (800)\n");
      oldhp = newhp;
      oldcharge = charge;
      oldsp = newsp;
   }
   
}
hp() {
   write("You toggle your hp monitor ");
   hp = !hp;
   set_heart_beat(hp);
   if (hp) write("on\n");
   else write("off\n");
   return 1;
}

leave() {
   int exp,minus;
   
   exp = this_player()->query_exp();
   minus = exp/6;
   this_player()->add_exp(-minus);
   this_player()->set_guild_file();
   this_player()->add_guild_exp(-this_player()->query_guild_exp());
   write("The Cleric guild feels sorry at your departure.\n");
   destruct(this_object());
   return 1;
}

crush() {
   object duh;
   duh = present(lower_case(this_player()->query_name())+" jr", environment(this_player()));
   if (!duh) {
      write("You don't have a helper to crush!\n");
      return 1;
   }
   destruct(duh);
   write("You have crushed your helper to smithereens!\n");
   say(this_player()->query_name()+" has crushed his helper to smithereens!\n");
   return 1;
}
sco() {
   call_other("players/asmithrune/objects/magicitems/scoreobj","sco");
   return 1;
}

I() {
   call_other("/players/asmithrune/objects/magicitems/invent","I");
   return 1;
}
sende(string str) {
   call_other("/players/asmithrune/objects/magicitems/feelings","sende",str);
   return 1;
}
