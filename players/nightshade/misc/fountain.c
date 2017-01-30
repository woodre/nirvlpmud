inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short ("Magnificent Fountain");
set_long
 ("This is a beautiful fountain mad out of polished black\n"+
"onyx. The water spills from the mouth of a statue of a gold dragon\n"+
"on top of the fountain. The water glows a soft blue color and is\n"+
"very clear. Perhaps you should take a swim in it.\n");
set_weight(10000);
set_alias("fountain");
}
