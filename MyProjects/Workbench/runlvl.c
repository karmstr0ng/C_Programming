#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <utmp.h>

void dump_entry(struct utmp* ut) {
    char s0[9], s1[5], s2[13];

    bzero(s0, 9);
    bzero(s1, 5);
    bzero(s2, 13);

    strncpy(s0, ut->ut_user, 8);
    strncpy(s1, ut->ut_id, 4);
    strncpy(s2, ut->ut_line, 12);

    fprintf(stderr, "user: %s, id: %s, line: %s\npid=%d, type=%d, exit=%d:%d\n",
        s0, s1, s2, ut->ut_pid, ut->ut_type, ut->ut_exit.e_termination,
        ut->ut_exit.e_exit);
}

int main() {
    struct utmp* ut;
    struct utmp filter;

    setutent();
    filter.ut_type = RUN_LVL;

    ut = getutid(&filter);

    if (!ut) {
        perror("getutent");
        fprintf(stderr, "Can't find RUN_LVL entry in utmp");
        exit(1);
    }

    dump_entry(ut);

    if (!strncmp(ut->ut_line, "run-level ", 9)) {
        fprintf(stdout, "%c\n", ut->ut_line[10]);
    }

    endutent();

    return (0);
}

