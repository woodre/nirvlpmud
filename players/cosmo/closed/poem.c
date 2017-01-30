#include "/players/cosmo/closed/ansi.h"
#define SYM MAG+"-"+HIB+"><"+MAG+"-"+NORM
id(str) {
    return str == "poem" || str == "note";
}


long() {
    say(call_other(this_player(), "query_name") +
        " reads the poem and oogles.\n");
    write("\n\n"
+"\t"+SYM+CYN+"  Shall I compare thee to a summer's day?        "+SYM+"\n"
+"\t"+SYM+CYN+"  Thou art more lovely and more temperate.       "+SYM+"\n"
+"\t"+SYM+CYN+"  Rough winds do shake the darling buds of May.  "+SYM+"\n"
+"\t"+SYM+CYN+"  And summer's lease hath all too short a date.  "+SYM+"\n"
+"\t"+SYM+CYN+"  Sometime too hot the eye of heaven shines,     "+SYM+"\n"
+"\t"+SYM+CYN+"  And often is his gold complexion dimmed.       "+SYM+"\n"
+"\t"+SYM+CYN+"  And every fair from fair sometimes declines,   "+SYM+"\n"
+"\t"+SYM+CYN+"  By chance or nature's changing course          "+SYM+"\n"
+"\t"+SYM+CYN+"          untrimmed.                             "+SYM+"\n"
+"\t"+SYM+CYN+"  But thy eternal summer shall not fade,         "+SYM+"\n"
+"\t"+SYM+CYN+"  Nor lose possession of that fair thou owest,   "+SYM+"\n"
+"\t"+SYM+CYN+"  Nor shall Death brag thou wander'st in his     "+SYM+"\n"
+"\t"+SYM+CYN+"          shade,                                 "+SYM+"\n"
+"\t"+SYM+CYN+"  When in eternal lines to time thou growest.    "+SYM+"\n"
+"\t"+SYM+CYN+"    So long as men can breathe, or eyes can see, "+SYM+"\n"
+"\t"+SYM+CYN+"    So long lives, and this gives life to thee.  "+SYM+"\n"
+CYN+"\t\t\t -- William Shakespeare"+NORM+"\n");
}

short() {
    return (SYM+" A poem "+SYM);
}

init() {
    add_action("read","read");
}

read(str) {
    if (str == 0 || str != "poem") {
       notify_fail("Try <read poem>\n");
       return 0;
    }
    say(call_other(this_player(), "query_name") +
        " reads the poem and oogles.\n");
    write("\n\n"
+"\t"+SYM+CYN+"  Shall I compare thee to a summer's day?        "+SYM+"\n"
+"\t"+SYM+CYN+"  Thou art more lovely and more temperate.       "+SYM+"\n"
+"\t"+SYM+CYN+"  Rough winds do shake the darling buds of May.  "+SYM+"\n"
+"\t"+SYM+CYN+"  And summer's lease hath all too short a date.  "+SYM+"\n"
+"\t"+SYM+CYN+"  Sometime too hot the eye of heaven shines,     "+SYM+"\n"
+"\t"+SYM+CYN+"  And often is his gold complexion dimmed.       "+SYM+"\n"
+"\t"+SYM+CYN+"  And every fair from fair sometimes declines,   "+SYM+"\n"
+"\t"+SYM+CYN+"  By chance or nature's changing course          "+SYM+"\n"
+"\t"+SYM+CYN+"          untrimmed.                             "+SYM+"\n"
+"\t"+SYM+CYN+"  But thy eternal summer shall not fade,         "+SYM+"\n"
+"\t"+SYM+CYN+"  Nor lose possession of that fair thou owest,   "+SYM+"\n"
+"\t"+SYM+CYN+"  Nor shall Death brag thou wander'st in his     "+SYM+"\n"
+"\t"+SYM+CYN+"          shade,                                 "+SYM+"\n"
+"\t"+SYM+CYN+"  When in eternal lines to time thou growest.    "+SYM+"\n"
+"\t"+SYM+CYN+"    So long as men can breathe, or eyes can see, "+SYM+"\n"
+"\t"+SYM+CYN+"    So long lives, and this gives life to thee.  "+SYM+"\n"
+CYN+"\t\t\t -- William Shakespeare"+NORM+"\n");
    return 1;
}
