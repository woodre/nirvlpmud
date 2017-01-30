inherit "room/room";
object jaunita, armor1;
object shenana, armor2;
object bruno, weapon;
object money;

reset(arg) {
  if (!arg) {
    set_light(1);
    move_object(clone_object("/players/blackadder/bed"),this_object());
  }
     if (!jaunita || !living(jaunita)) {
    jaunita = clone_object("obj/monster.talk");
    call_other(jaunita,"set_name","juanita");
    call_other(jaunita,"set_short","Juanita");
    call_other(jaunita,"set_long",
               "Juanita is a beautiful spanish full bread ho.  Today she is\n"+
               "wearing a lovely thong by Victoria Secret.  She is \n"+
               "pleased to meet you, and so are her breasts, apparently\n");
    call_other(jaunita,"set_level",10);
    call_other(jaunita,"set_hp",400);
    call_other(jaunita,"set_ac",10);
    move_object(jaunita,this_object());
    money = clone_object("obj/money");
    call_other(money,"set_money",random(2000));
    move_object(money,jaunita);
    call_other(jaunita,"set_chat_chance",20);
    call_other(jaunita,"set_a_chat_chance",33);
    call_other(jaunita,"load_chat","Juanita blows kisses at you...\n");
    call_other(jaunita,"load_chat","Juanita arches her back slightly, displaying her full breasts.\n");
    call_other(jaunita,"load_chat","Juanita makes a motion toward the bed.\n");
	armor1=clone_object("obj/armor");
	call_other(armor1,"set_name","Victoria Secret thong");
	call_other(armor1,"set_short","A skimpy Victoria Secret thong");
	call_other(armor1,"set_alias","thong");
	call_other(armor1,"set_long","Juanita's well-used thong.\n");
	call_other(armor1,"set_value",250);
	call_other(armor1,"set_ac",1);
	call_other(armor1,"set_type","armor");
	transfer(armor1,jaunita);
	call_other(jaunita,"init_command","wear thong");
  }
   if (!shenana || !living(shenana)) {
	shenana=clone_object("obj/monster.talk");
	call_other(shenana,"set_name","shenana");
	call_other(shenana,"set_short","She-na-na");
	call_other(shenana,"set_long",
		"She-na-na is a extrememly well used black woman.  She exemplifies\n"
		+ "today's modern day ho style.  Today, She-na-na is wearing a\n"
		+ "V-cut mesh body-suit, resembling Cher's.  She is glad to make\n"
		+ "your acquaintance.\n");
	call_other(shenana,"set_level",10);
	call_other(shenana,"set_hp",400);
	call_other(shenana,"set_ac",10);
	move_object(shenana,this_object());
	money=clone_object("obj/money");
	call_other(money,"set_money",random(2000));
	move_object(money,shenana);
	call_other(shenana,"set_chat_chance",20);
	call_other(shenana,"set_a_chat_chance",33);
	call_other(shenana,"load_chat","Shenana struts proudly around the bed.\n");
	call_other(shenana,"load_chat","Shenana gets down on all fours to show off her ebony ass.\n");
	call_other(shenana,"load_chat","Shenana makes a motion toward the bed.\n");
	call_other(shenana,"load_a_chat","Shenana screams: Bruno!!! Get in here!\n");
	armor2=clone_object("obj/armor");
	call_other(armor2,"set_name","Vcut body suit");
	call_other(armor2,"set_short","A V-cut mesh body suit");
	call_other(armor2,"set_alias","suit");
	call_other(armor2,"set_long","She-na-na's sensuous body suit.\n");
	call_other(armor2,"set_value",250);
	call_other(armor2,"set_ac",2);
	call_other(armor2,"set_type","misc");
	transfer(armor2,shenana);
	call_other(shenana,"init_command","wear suit");
	}
    if(!bruno || !living(bruno)) {
	bruno=clone_object("obj/monster.talk");
	call_other(bruno,"set_name","bruno");
	call_other(bruno,"set_short","Bruno");
	call_other(bruno,"set_long",
		"Bruno is just plain big!  The tattoo of Popeye on his shoulder\n"+
		"shows his feelings for his childhood hero.  Bruno is the man.\n");
	call_other(bruno,"set_level",18);
	call_other(bruno,"set_hp",450);
	call_other(bruno,"set_ac",15);
	call_other(bruno,"set_wc",26);
	move_object(bruno,this_object());
	call_other(bruno,"set_chat_chance",10);
	call_other(bruno,"set_a_chat_chance",33);
	call_other(bruno,"load_chat","Bruno says: you ladies allright in here?\n");
	call_other(bruno,"load_a_chat","Bruno gulps down some spinach, and growls.\n");
	weapon=clone_object("obj/weapon");
	call_other(weapon,"set_name","can of spinach");
	call_other(weapon,"set_short","A half empty can of spinach");
	call_other(weapon,"set_alias","can");
	call_other(weapon,"set_long","Bruno's half empty can... packs quite a punch.\n");
	call_other(weapon,"set_value",1000);
	call_other(weapon,"set_class",18);
	transfer(weapon,bruno);
	call_other(bruno,"init_command","wield can");
	}
  short_desc = "Da house";
  no_castle_flag = 0;
  long_desc = 
    "This is the best little whore house in Town Central.  Two ladies\n"
      + "stand next to a king-size waterbed, and a huge dark figure with\n"
        + "a tattoo of Popeye on his shoulder stands in the corner.\n";
  dest_dir = 
    ({
      "/players/rumplemintz/room/lounge/room2", "down",
    });
}
