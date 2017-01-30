id(str) { return str =="statcheck"; }

checkstat(object ob) {
  if(!ob) return 1;
   if(ob->query_level() > 19 || ob->query_real_name() == "priest") return 1;
   if(ob->query_attrib("str") > 20) ob->set_attrib("str",20);
   if(ob->query_attrib("int") > 20) ob->set_attrib("int",20);
   if(ob->query_attrib("sta") > 20) ob->set_attrib("sta",20);
   if(ob->query_attrib("mag") > 30) ob->set_attrib("mag",30);
   if(ob->query_attrib("wil") > 20) ob->set_attrib("wil",20);
   if(ob->query_attrib("pie") > 20) ob->set_attrib("pie",20);
   if(ob->query_attrib("luc") > 20) ob->set_attrib("luc",20);
   if(ob->query_attrib("ste") > 25) ob->set_attrib("ste",25);
   if(ob->query_attrib("str") < 1) ob->set_attrib("str",1);
   if(ob->query_attrib("wil") < 1) ob->set_attrib("wil",1);
   if(ob->query_attrib("int") < 1) ob->set_attrib("int",1);
   if(ob->query_attrib("luc") < 1) ob->set_attrib("luc",1);
   if(ob->query_attrib("pie") < 1) ob->set_attrib("pie",1);
   if(ob->query_attrib("ste") < 1) ob->set_attrib("ste",1);
   if(ob->query_attrib("sta") < 1) ob->set_attrib("sta",1);
   if(ob->query_attrib("mag") < 1) ob->set_attrib("mag",1);
  if(ob->query_ac() < 0) ob->set_ac(0);
  if(ob->query_wc() < 0) ob->set_wc(0);
return 1; }
