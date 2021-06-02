#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    struct pstat proc_stat;
    getpinfo(&proc_stat);
    for (int i = 0; i < NPROC; ++i) {
        if (proc_stat.inuse[i] == 1) {
            printf(1, "%d proc stat: pid %d, tickets %d, ticks %d\n", i,
                   proc_stat.pid[i], proc_stat.tickets[i], proc_stat.ticks[i]);
        }
    }

    exit();
}