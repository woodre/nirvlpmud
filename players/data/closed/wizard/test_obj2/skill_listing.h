skill_listing(){
	write(
		"\n\n\n                         -[  "+HIB+"Weapon Skills"+NORM+" ]-\n"+
		"  Blunt Weapon    "+skills[1]+"/10("+gtp(1)+"%)\t\t"+
		"Edged Weapon    "+skills[2]+"/10("+gtp(2)+"%)\n"+
		"  Polearm Weapon  "+skills[3]+"/10("+gtp(3)+"%)\t\t"+
		"Archery Weapon  "+skills[4]+"/10("+gtp(4)+"%)\n"+
		"  Exotic Weapon   "+skills[5]+"/10("+gtp(5)+"%)\t\t"+
		"Small Weapon    "+skills[6]+"/10("+gtp(6)+"%)\n"+
		"                          -[ "+HIR+"Attack Moves"+NORM+" ]-\n"+
		"  Throw           "+skills[15]+"/5("+gtp(15)+"%)\t\t"+
		"Strike          "+skills[16]+"/5("+gtp(16)+"%)\n"+
		"  Punch           "+skills[17]+"/5("+gtp(17)+"%)\t\t"+
		"Kick            "+skills[18]+"/5("+gtp(18)+"%)\n"+
		"  Charge          "+skills[19]+"/5("+gtp(19)+"%)\t\t"+
		"Bash            "+skills[20]+"/5("+gtp(20)+"%)\n"+
		"  Finish          "+skills[41]+"/3("+gtp(41)+"%)\t\t"+
	"Blindfight      "+skills[70]+"/2(");
	if(skills[70]) write("100%)\n");
	else write("0%)\n");
	write(
		"                         -[ "+HIG+"Defensive Moves"+NORM+" ]-\n"+
		"  Dodge           "+skills[30]+"/5("+gtp(30)+"%)\t\t"+
		"Parry           "+skills[31]+"/5("+gtp(31)+"%)\n"+
		"  Offhand Parry   "+skills[32]+"/5("+gtp(32)+"%)\t\t"+
		"Block           "+skills[33]+"/5("+gtp(33)+"%)\n"+
		"                          -[ "+HIM+"Miscellaneous"+NORM+" ]-\n"+
		"  Pummel          "+skills[40]+"/5("+gtp(40)+"%)\t\t"+
		"First Aid       "+skills[50]+"/5("+gtp(50)+"%)\n"+
	"  Run             "+skills[60]+"/3("+gtp(60)+"%)\n\n\n");
	return 1;
}

skill_list2(){
if(monk){
write(
      HIW+"                         -[ "+HIB+"Monk Skills"+HIW+" ]-\n"+
      "  Hand-to-Hand      "+HIB+skills[80]+"/5  "+HIW);

if(skills[30] > 5) write("  Advanced Dodge    "+HIB+(skills[30] - 5)+"/5\n"+HIW);
else write("  Advanced Dodge    "+HIB+"0/5\n"+HIW);

write(
      "  Touch             "+HIB+skills[81]+"/5"+HIW+"  "+
      "  Advanced Punch    "+HIB+skills[21]+"/5"+HIW+"\n"+
      "  Advanced Kick     "+HIB+skills[22]+"/5"+HIW+"  "+
      "  Meditate          "+HIB+skills[85]+"/5"+HIW+"\n\n"+
      "                         -[ "+HIB+"Disciplines"+HIW+" ]-\n");

if(blood) write("  Discipline of Blood    "+HIB+"YES\n"+HIW);
else      write("  Discipline of Blood    "+HIB+"NO\n"+HIW);
if(time) write("  Discipline of Time     "+HIB+"YES\n"+HIW);
else     write("  Discipline of Time     "+HIB+"NO\n"+HIW);
if(mind) write("  Discipline of Mind     "+HIB+"YES\n\n"+NORM);
else     write("  Discipline of Mind     "+HIB+"NO\n\n"+NORM);
}
if(paladin){
write(
      BLU+"                         -[ "+HIB+"Paladin Skills"+NORM+BLU+" ]-\n"+
      HIY+" AURA POWERS"+HIW+"\n"+
      "  Regeneration          "+HIB+skills[92]+"/5"+HIW+"  "+
      "  Protection from Good  "+HIB+skills[90]+"/5"+HIW+"\n"+
      "  Protection from Evil  "+HIB+skills[91]+"/5"+HIW+"\n"+
      HIY+" HOLY POWERS"+HIW+"\n"+         
      "  Holy Bolt (good)      "+HIB+skills[93]+"/5"+HIW+"  "+
      "  Release               "+HIB+skills[94]+"/1"+HIW+"\n"+
      "  Redeem    (good)      "+HIB+skills[96]+"/5"+HIW+"  "+
      "  Corrupt   (evil)      "+HIB+skills[98]+"/5"+HIW+"\n"+
      "  Plague    (evil)      "+HIB+skills[99]+"/5"+HIW+"  "+
      "  Cleanse               "+HIB+skills[95]+"/1"+HIW+"\n"+
      "  Detect                "+HIB+skills[89]+"/1"+HIW+"  "+
      "  Sacrifice             "+HIB+skills[97]+"/5"+HIW+"\n\n"+NORM);
}
return 1;
}


prof_check(){ 
if(monk || paladin || knight || assassin || berserker) return 1;
else return 0;
}