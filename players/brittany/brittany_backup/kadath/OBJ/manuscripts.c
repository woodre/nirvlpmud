inherit "/obj/treasure";
short() { return "A manual"; }
long() {
write("     A manual of the Pnakotic manuscripts, used to decipher\n"+
      "hieroglyphic symbols.\n");
}
id(str) { return str == "manual" || str == "manuscripts"; }
