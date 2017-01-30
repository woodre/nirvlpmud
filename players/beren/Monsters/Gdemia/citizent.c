/* Changed from lev16,ac10,wc25,hp250 -Snow 3/00 */
inherit "/obj/monster";
reset (arg) {
:: reset (arg);
if (!arg) {
        set_name ("gdemia");
	set_alias ("citizen");
        set_short ("A Gdemia citizen is wandering around");
        set_race ("gdemia");
        set_long ("Just a citizen. Just a Gdemia. Nothing special about him\n"+
	"You get a strange feeling that all Gdemias are alike, you can't\n"+
	"even tell which gender this guy is! No difference between male\n"+
	"and female (at least, you can't see one). Very strange guys they\n"+
	"are, you are quite puzzled why THEY were choosed as a partners\n"+
	"by a Star League and not the honourable Angya or merry Fiia.\n");
        set_level (10);
	set_ac (random(5)+4);
	set_wc (random(8)+10);
	set_hp (random(80)+100);
        set_al (0);
        set_aggressive (0);
        set_chat_chance (20);
        set_a_chat_chance (20);
/* Some value... -Snow 3/00 */
money = random(200)+250;
        load_chat ("A citizen looks at you.\n");
        load_a_chat ("A citizen tries to run away, but fails.\n");
}
}
