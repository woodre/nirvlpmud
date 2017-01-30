
string make_long(object ob,string descriptor) {
  string pron,poss,obje,adje,ret;
  pron=(string)ob->query_pronoun();
  poss=(string)ob->query_possessive();
  obje=(string)ob->query_objective();
  adje=(pron=="he"?"man":"woman");
  ret="This "+descriptor+" patron of the bar appears to be a "+
  ({"tourist","punk","player","typical citizen"})[random(4)]+
  ".  "+capitalize(pron)+" "+
  ({"ignores you, like a prudent resident of New York",
    "eyes you nervously, as if worried about something",
    "stares back at you boldly, ignoring prudence",
    "turns away from you, almost as if trying to hide"})[random(4)]+
  ".  "+capitalize(pron)+" is dressed in ";
  if(pron=="he")
    ret+= ({"jeans and a t-shirt","a fancy suit and tie",
            "slacks and a polo shirt",
            "strangely-cut, unfamiliar clothing"})[random(4)];
  else
    ret+= ({"jeans amd a t-shirt","strangely-cut, unfamiliar clothing",
            "slacks and a blouse","a skirt and a blouse",
            "a skirt and suit coat"})[random(5)];
  ret += ".";
  return format(ret,75);
}
object patron_generator(object ob) {
  int lev;
  string descriptor;
  lev=random(5)+15;
  ob->set_level(lev);
    /* wc from monster.guide with +2 variation */
  ob->set_wc(lev+10+random(3));
    /* ac from monster.guide with +1 variation */
  ob->set_ac(lev-3+random(2));
  ob->set_al(-200+random(401));
  if(lev==15) ob->set_hp(225);
  else ob->set_hp(lev*25);
  ob->add_money(lev*57);
  ob->set_gender(({"male","female"})[random(2)]);
  ob->set_name("patron");
  descriptor=({"tired","tipsy","large","small","bored"})[random(5)];
  ob->set_short("A "+descriptor+" patron of the bar");
  ob->set_long(make_long(ob,descriptor));
  return ob;
}
