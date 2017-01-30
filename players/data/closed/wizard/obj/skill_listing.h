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
